#include <iostream>
using namespace std;
int main(){
    int num;
    cout << "Enter a number: \n";cin>>num;
    int temp = num;
    int rev=0;
    while(temp > 0)
    {
        int digit=temp%10;
        rev=rev*10+digit;
        temp/=10;
    }

    if(num==rev)
        cout << num <<" is Palindrom" << endl;
    else
        cout << num <<" is not Palindrom" << endl;
}
