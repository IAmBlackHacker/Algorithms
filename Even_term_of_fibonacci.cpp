#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/* fib series 1,2,3,5,8,13,21,34,55,89,⋯ */
long long int sum;
long long int esumf(long long int n)
{
    if(n==1)
        return 2;
    if(n==2)
        return 8;
    else
        return 4*esumf(n-1)+esumf(n-2);
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long long int n;
    cout<<"Enter Term:";
    cin>>n;
    cout<<endl<<esumf(n);
    return 1;
}
