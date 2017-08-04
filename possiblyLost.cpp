#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//char *str; //possibly lost
int main()
{
	//char *str;    //Directly lost
	static char* str;
	str = (char*)malloc(6);
	strcpy(str,"Hello");
	str=str+1;
	return 0;
}
