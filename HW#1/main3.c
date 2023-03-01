#include <stdio.h>

void left_shift(char *str, int n) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    char temp[n+1];
    for (int i = 0; i < n; i++) {
        temp[i] = str[i];
    }
    temp[n] = '\0';
    for (int i = 0; i < len-n; i++) {
        str[i] = str[i+n];
    }
    for (int i = 0; i < n; i++) {
        str[len-n+i] = temp[i];
    }
}

int main() {
    char str[] = "ABC123";
    int n = 3;
    left_shift(str, n);
    printf("%s", str);
}
