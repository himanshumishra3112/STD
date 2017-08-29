/*
Storage qualifiers in C++:
==========================

As a practical example, think of touch sensor on mobile phones. The driver abstracting touch sensor will read the location of touch 
and send it to higher level applications. The driver itself should not modify (const-ness) the read location, and make sure it reads 
the touch input every time fresh (volatile-ness). Such driver must read the touch sensor input in const volatile manner.
*/


#include <stdio.h>

int main()
{
    volatile const int a = 10;
    printf("Value = %d\n", a);
    int* p = (int*) &a;
    *p = 1000;
    printf("Value = %d\n", a);
    return 0;
}

gcc -g -O3 volatile.c
