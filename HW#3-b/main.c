#include <stdio.h>

typedef struct my_mm {
    int size;
    char* start;
} my_mm_t;

int g_mem[10];
my_mm_t mms[10] = {{0}};

char* my_calloc(int n, int size) {
    for (int i = 0; i < 10; i++) {
        if (mms[i].start == NULL) { // 找到未被分配的内存块
            int mem_size = n * size;
            if (mem_size > (10 - i) * sizeof(int)) { // 检查是否有足够的内存
                printf("Insufficient memory\n");
                return NULL;
            }
            char* ptr = (char*)&g_mem[i]; // 计算指针地址
            mms[i].size = mem_size;
            mms[i].start = ptr;
            for (int j = 0; j < mem_size; j++) { // 初始化内存块
                *(ptr + j) = 0;
            }
            printf("1100000000\n"); // 打印信息
            return ptr;
        }
    }
    printf("Insufficient memory\n"); // 如果没有可用的内存块，则打印错误信息
    return NULL;
}

void my_free(char* p) {
    for (int i = 0; i < 10; i++) {
        if (p == mms[i].start) { // 找到要释放的内存块
            mms[i].start = NULL;
            printf("1100000000\n"); // 打印信息
            return;
        }
    }
    printf("Invalid pointer\n"); // 如果没有找到要释放的内存块，则打印错误信息
}

int main() {
    int* np1 = (int*)my_calloc(1, sizeof(int));
    int* np2 = (int*)my_calloc(1, sizeof(int)*2);
    int* np3 = (int*)my_calloc(1, sizeof(int)*3);
    int* np4 = (int*)my_calloc(1, sizeof(int)*4);
    my_free((char*)np1);
    my_free((char*)np4);
    int* np5 = (int*)my_calloc(1, sizeof(int)*3);
    return 0;
}
