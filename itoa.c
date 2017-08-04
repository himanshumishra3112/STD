#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* fun()
{
	int aInt = 368;
	int temp = aInt;
	int size=0;
	while(temp)
	{
		temp=temp/10;
		size++;
	}
	char *ret = (char*)malloc(size);
	sprintf(ret, "%d", aInt);
	return ret;
}

int main()
{
	char* ret=fun();
	printf("%s\n",ret);
}
