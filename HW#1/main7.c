#include <stdio.h>

int main() {
    char binary_string[]="10001111";
    int decimal_number = 0;
    char hexadecimal_string[100];
    int i, j;
    for(i=0; binary_string[i]!='\0'; i++)
        decimal_number=decimal_number*2+(binary_string[i]-'0');
    i=0;
    while(decimal_number!=0){
        int remainder = decimal_number % 16;
        hexadecimal_string[i++] = (remainder < 10)?remainder + '0':remainder - 10 + 'A';
        decimal_number /= 16;
    }
    if(i==0) {hexadecimal_string[i++] = '0';}
    hexadecimal_string[i] = '\0';
    int len = i;
    for(i=0, j=len-1; i<j; i++, j--){
        char temp = hexadecimal_string[i];
        hexadecimal_string[i] = hexadecimal_string[j];
        hexadecimal_string[j] = temp;
    }
    printf("%s\n", hexadecimal_string);
    return 0;
}
