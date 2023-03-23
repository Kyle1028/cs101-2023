#include <stdio.h>

void replace_all(char *str, char oldChar, char newChar){
    int len=0;
    while(str[len]!= '\0'){len++;}
    for(int i=0;i<len;i++){str[i]=(str[i]==oldChar)?newChar:oldChar;}
}

int main()
{
    char str[100], oldChar = 'a', newChar ='A';
    printf("Enter any string: ");
    scanf("%s", str);
    printf("\nString before replacing: \n%s", str);
    replace_all(str, oldChar, newChar);
    printf("\n\n string after replacing %c with %c : \n%s", oldChar, newChar, str);
    return 0;
}
#include <stdio.h>

void replace_all(char *str, char oldChar, char newChar){
    int len=0;
    while(str[len]!= '\0'){len++;}
    for(int i=0;i<len;i++){str[i]=(str[i]==oldChar)?newChar:oldChar;}
}

int main()
{
    char str[100], oldChar = 'a', newChar ='A';
    printf("Enter any string: ");
    scanf("%s", str);
    printf("\nString before replacing: \n%s", str);
    replace_all(str, oldChar, newChar);
    printf("\n\n string after replacing %c with %c : \n%s", oldChar, newChar, str);
    return 0;
}
