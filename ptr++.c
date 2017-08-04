#include <stdio.h>
int main(){
    int a=7;
    int* p = &a;
    int x = *p++;
    printf("val: %d\n",x);
}
