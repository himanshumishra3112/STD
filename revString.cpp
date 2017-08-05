#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
#define SIZE 10

int main(){
    const char str[SIZE] = "himanshu";
    char temp[SIZE];
    temp[0] = '\0';

    for(int i=0; i<strlen(str); i++)
    {
        snprintf(temp+strlen(temp), SIZE - strlen(temp), "%c",str[(strlen(str)-1) -i]);
    }
    temp[strlen(temp)] = '\0';

    cout << temp << endl;
	return 0;
}
