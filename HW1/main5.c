#include <stdio.h>

void bubble_sort(int *array) {
    int len = sizeof(array)/sizeof(int)-1;
    for (int i=0; i<len-1; i++) {
        for (int j=0; j<len-i-1; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int main() {
    int array[] = {-9,8,7,6,5,-4,3,-2,1};
    int n = 3;
    bubble_sort(array);
    printf("%d",array[n]);
    return 0;
}
