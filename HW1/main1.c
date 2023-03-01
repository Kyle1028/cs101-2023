#include <stdio.h>

int main() {
    char input[]="AAABBBBCCCCDD", output[100];
    int count = 1;
    int len = 0;
    while (input[len] != '\0') {
        len++;
    }
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (input[i] == input[i+1]) {
            count++;
        } else {
            output[j++] = input[i];
            output[j++] = count + '0';
            count = 1;
        }
    }
    output[j] = '\0';
    printf("%s\n", output);
    return 0;
}
