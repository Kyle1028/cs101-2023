#include <stdio.h>
void filter(char *a){
    int len = 0;
    while (a[len] != '\0') {len++;}
    for(int i=0; i<len; i++){
        switch(a[i]){
            case '1':
                printf("I ");
                break;
            case '2':
                printf("II ");
                break;
            case '3':
                printf("III ");
                break;
            case '4':
                printf("IV ");
                break;
            case '5':
                printf("V ");
                break;
            case '6':
                printf("VI ");
                break;
            case '7':
                printf("VII ");
                break;
            case '8':
                printf("VIII ");
                break;
            case '9':
                printf("IX ");
                break;
            default:
                printf("%c ",a[i]);
                break;
        }
    }
}

int main()
{
    char a[]="81c8g8u168";
    filter(a);
}
