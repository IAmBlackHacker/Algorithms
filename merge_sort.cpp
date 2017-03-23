#include<iostream>
#include<conio.h>
#define MAX 50
using namespace std;
void merge(long int Arr[],long int low,long int mid,long int high)
{
    long int Arrt[MAX];
    long int p=low,q=low,r=mid+1;
    while(p<=mid && r<=high)
    {
        if(Arr[p]<Arr[r])
        {
            Arrt[q++]=Arr[p++];
        }
        else
        {
            Arrt[q++]=Arr[r++];
        }
    }
    while(p<=mid)
    {
        Arrt[q++]=Arr[p++];
    }
    while(r<=mid)
    {
        Arrt[q++]=Arr[r++];
    }
    for(;low<q;low++)
    {
        Arr[low]=Arrt[low];
    }
}
void msort(long int Arr[],long int p,long int r)
{
    long int q;
    if(p<r)
    {
        q=(p+r)/2;
        msort(Arr,p,q);
        msort(Arr,q+1,r);
        merge(Arr,p,q,r);
    }
    return;
}
int main()
{
    long int n,Arr[MAX];
    cout<<"Enter number of elements you want:";
    cin>>n;
    cout<<"Enter integer Arry:";
    for (int i=0;i<n;i++)
    {
        cin>>Arr[i];
    }
    msort(Arr,0,n-1);
    for (int i=0;i<n;i++)
    {
        cout<<Arr[i]<< " ";
    }
    return 1;
}
