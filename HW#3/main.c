#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define ARRAY_SIZE 7
typedef struct lottery {
    int receipt_id;
    int receipt_price;
    int lotto_set[5][7];
    char receipt_time[32];
} lotto_record_t;
lotto_record_t record = {0};
int generateRandomNumber(int previous) {
    int num = rand() % 69 + 1;
    while (num == previous) {num = rand() % 69 + 1;}
    return num;
}
void generateRandomArray(int arr[]) {
    int previous = 0;
    for (int i = 0; i < ARRAY_SIZE - 1; i++) {
        arr[i] = generateRandomNumber(previous);
        previous = arr[i];
    }
    arr[ARRAY_SIZE - 1] = rand() % 10 + 1;
}
char* date() {
    putenv("TZ=Asia/Taipei");
    tzset();
    time_t current_time = time(NULL);
    return asctime(localtime(&current_time));
}
int file_Count() {
    int count = 1;
    FILE* fp=fopen("record.bin", "rb+");
    if (!fp) {
        fp = fopen("record.bin", "wb+");
        if (!fp) {
            perror("Error opening file");
            exit(EXIT_FAILURE);
        }
        fwrite(&count, sizeof(count), 1, fp);
    } else {
        fread(&count, sizeof(count), 1, fp);
        ++count;
        fseek(fp, 0, SEEK_SET);
        fwrite(&count, sizeof(count), 1, fp);
    }
    fclose(fp);
    return count;
}
void generate_lotto(int x,int count){
    FILE* fp = fopen("lotto.txt", "w");
    FILE* wfp = fopen("record.bin", "ab+");
    srand(time(NULL));
    int arr[ARRAY_SIZE], j, k;
    char*time_str = date();
    record.receipt_id = count;
    strcpy(record.receipt_time, time_str);
    fprintf(fp, "=========lotto649=========\n=======+ NO.%05d +=======\n %s", record.receipt_id, record.receipt_time);
    for(j = 0; j < x; j++) {
        generateRandomArray(arr);
        fprintf(fp,"[%d]: ", j + 1);
        for(int i = 0; i < ARRAY_SIZE; i++) {
            fprintf(fp, "%02d ", arr[i]);
            record.lotto_set[j][i] = arr[i];
        }
        fprintf(fp,"\n");
    }
    for(k = j; k < 5; k++){
        fprintf(fp, "[%d]: -- -- -- -- -- -- --\n", k+1);
        memset(record.lotto_set[k], 0, sizeof(record.lotto_set[k]));
    }
    fprintf(fp, "=========csie@cgu=========");
    record.receipt_price=x*100;
    printf("id:%d\n",record.receipt_id);
    printf("price:%d\n",record.receipt_price);
    printf("time:%s",record.receipt_time);
    for(int x=0;x<5;x++){
        for(int y=0;y<ARRAY_SIZE;y++){
            printf("%02d ",record.lotto_set[x][y]);
        }
        printf("\n");
    }
    fwrite(&record, sizeof(record), 1, wfp);
    fclose(fp);
    fclose(wfp);
}
void print_record() {
    FILE* fp = fopen("record.bin", "rb");
    int count, price,lotto_set[5][7];
    char time_str[32];
    fread(&count, sizeof(count), 1, fp);
    printf("共有%d筆記錄\n", count);
    for (int i = 0; i < count; i++) {
        fread(&price, sizeof(price), 1, fp);
        fread(time_str, sizeof(time_str), 1, fp);
        printf("\n========== Record %d ==========\n", i+1);
        printf("Receipt ID: %05d\n", i+1);
        printf("Receipt Price: %d\n", price);
        printf("Receipt Time: %s", time_str);
        printf("Lotto Numbers:\n");
        for (int j = 0; j < 5; j++) {
            printf("[%d]: ", j+1);
            for (int k = 0; k < 7; k++) {
                fread(&lotto_set[j][k], sizeof(int), 1, fp);
                printf("%02d ", lotto_set[j][k]);
            }
            printf("\n");
        }
    }
    fclose(fp);
}

int main() {
    int x,winning_numbers[3];
    printf("請問你要買幾組樂透彩：");
    scanf("%d", &x);
    if (!x) {
        printf("請輸入中獎號碼（最多3個）：");
        for (int i = 0; i < 3; i++) scanf(" %d", &winning_numbers[i]);
        printf("輸入中獎號碼為：");
        for (int i = 0; i < 3; i++) printf("%02d ",winning_numbers[i]);
        printf("\n以下為中獎彩卷：\n");
        print_record();
    }else if(x<6) {
        printf("已為您購買的%d組樂透組合輸出至lotto.txt\n", x);
        generate_lotto(x,file_Count());
    }else{
        printf("最多只能買5組");
    }
    
    return 0;
}
