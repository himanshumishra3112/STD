#include <stdio.h>
#include <string.h>

int main()
{
    if (0)
    {
        char* ptr;
        strcpy(ptr, "hello"); //Segmentation fault
        //(gdb) p ptr
        //$1 = 0x0
    }

    {
        char arr[5] = {'\0'};
        printf("%d\n", strlen(arr));        // 0
        strcpy(arr, "helloworld");
        char arr1[] = "Helloworld";
        char *arr2 = "Helloworld";
        char * iptr;
        printf("%d\n", sizeof(arr));        // 5
        printf("%d\n", sizeof(arr1));       // 11
        printf("%d\n", strlen(arr1));       // 10
        printf("%d\n", sizeof(arr2));       // 4
        printf("%d\n", sizeof(iptr));       // 4
    }


    return 0;
}
