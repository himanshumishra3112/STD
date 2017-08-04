#include <iostream>
#include <stdio.h>
using namespace std;
int power(int num, int size){
    int ret=1;
    for(int i = 1; i<=size; i++){
        ret=ret*num;
    }
    return ret;
}
int main(){
    int num;
    printf("Enter a num:\n");
    scanf("%d",&num);

    int temp = num;
    int size=0;
    while(temp > 0){
        temp/=10;
        size++;
    }
    temp = num;
    int sum=0;
    for(int i = 0; i<size; i++){
        sum+= power(temp%10, size);
        temp/=10;
    }

    if(sum == num)
        printf("%d is an Armstrong Number\n",num);
    else
        printf("%d is not not Armstrong Number\n",num);
}
