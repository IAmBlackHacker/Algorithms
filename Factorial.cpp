#include<iostream>
#include<conio.h>
using namespace std;
long long int fact(int n)
{
    if(n==1 || n==0)
        return 1;
    return n*fact(n-1);
}
int main()
{
    int n;
    unsigned long long int res;
   // cin>>n;
    cout<<fact(18);
}
