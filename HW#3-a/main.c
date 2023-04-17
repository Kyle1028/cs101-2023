#include <stdio.h>
#include <time.h>

void hanoi(int n, char from, char to, char aux, FILE *fp) {
    static int move_num = 1;
    if (n == 1) {
        time_t now = time(NULL);
        fprintf(fp, "%d (%s) : 1P from %c to %c\n", move_num, ctime(&now), from, to);
        move_num++;
        return;
    }
    hanoi(n - 1, from, aux, to, fp);
    time_t now = time(NULL);
    fprintf(fp, "%d (%s) : %dP from %c to %c\n", move_num, ctime(&now), n, from, to);
    move_num++;
    hanoi(n - 1, aux, to, from, fp);
}

int main() {
    int n = 20;
    FILE *fp = fopen("hanoi.txt", "w");
    time_t start_time = time(NULL);
    fprintf(fp, "開始搬動時間 (%s)\n", ctime(&start_time));
    hanoi(n, 'A', 'C', 'B', fp);
    time_t end_time = time(NULL);
    fprintf(fp, "完成搬動時間 (%s)\n", ctime(&end_time));
    fclose(fp);
    return 0;
}
