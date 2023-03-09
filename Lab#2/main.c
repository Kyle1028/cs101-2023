#include <stdio.h>
#include <string.h>

typedef struct employee{
    int em_id;
    char em_name[10];
    int em_age;
    char em_phone[12];
    float em_slary;
}employee_t;

void employee_info (employee_t employee_1){
    printf("%d\n",employee_1.em_id);
    printf("%s\n",employee_1.em_name);
    printf("%d\n",employee_1.em_age);
    printf("%s\n",employee_1.em_phone);
    printf("%f\n",employee_1.em_slary);
}
int main()
{
    employee_t employee_1;
    int a = sizeof(employee_t);
    printf("employee_t's size %d\n",a);
    strcpy(employee_1.em_name, "IU Lee");
    strcpy(employee_1.em_phone, "0937123456");
    employee_1.em_id = 1;
    employee_1.em_age = 18;
    employee_1.em_slary = 1000.30;
    employee_info(employee_1);
    return 0;
}
