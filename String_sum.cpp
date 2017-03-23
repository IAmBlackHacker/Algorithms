#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAX 10000
using namespace std;
//name1>name2
int sadd(char name1[],char name2[],char name3[],int n1,int n2,int d,int rem=0)
{
    int n=(n1+n2)/2;
    if(n1 != n2)
        rem=sadd(name1,name2,name3,n+1,n2,d,rem);
    if(n1==n)
    {
        rem=(((int)name1[n+d]+(int)name2[n])%48)+rem;
        name3[n+d+1]=(char)(rem%10+48);
        rem=rem/10;
        return rem;
    }
    if(n1 != n2)
        sadd(name1,name2,name3,n1,n,d,rem);

}
char *add(char name1[],char name2[],char name3[])
{
    int len1=strlen(name1),len2=strlen(name2),rem,i;
    if(len1>len2)
    {
        rem=sadd(name1,name2,name3,0,strlen(name2)-1,len1-len2);
        for(i=len1-len2;i>0;i--)
        {
            rem=((int)name1[i-1])%48+rem;
            name3[i]=(char)(rem%10+48);
            rem=rem/10;
        }
        name3[0]=char(rem+48);
        name3[len1+1]='\0';
    }
    else
    {
        rem=sadd(name2,name1,name3,0,strlen(name1)-1,len2-len1);
        for(i=len2-len1;i>0;i--)
        {
            rem=((int)name2[i-1])%48+rem;
            name3[i]=(char)(rem%10+48);
            rem=rem/10;
        }
        name3[0]=char(rem+48);
        name3[len2+1]='\0';
    }
    char *p=name3;
    for(i=0;i<strlen(name3)-1;i++)
    {
        if(name3[i]=='0')
            p++;
        else
            break;
    }
    return p;
}
int ssub(char name1[],char name2[],char name3[],int n1,int n2,int d,int rem=0)
{
    int n=(n1+n2)/2;
    if(n1 != n2)
        rem=ssub(name1,name2,name3,n+1,n2,d,rem);
    if(n1==n)
    {
        rem=((int)name1[n+d]-(int)name2[n])-rem;
        name3[n+d]=(char)( ((rem<0)?(-rem):rem)%10+48 );
        if(rem<0)
            rem=1;
        else
            rem=0;
        return rem;
    }
    if(n1 != n2)
        ssub(name1,name2,name3,n1,n,d,rem);

}
char *sub(char name1[],char name2[],char name3[])
{
    int len1=strlen(name1),len2=strlen(name2),rem,i;
    if(len1>=len2)
    {
        rem=ssub(name1,name2,name3,0,strlen(name2)-1,len1-len2);
        for(i=len1-len2;i>0;i--)
        {
            rem=((int)name1[i-1])%48-rem;
            name3[i-1]=(char)( ((rem<0)?(-rem):rem)%10+48);
            if(rem<0)
                rem=-1;
            else
                rem=0;
        }
        name3[len1]='\0';
    }
    else
    {
        rem=ssub(name2,name1,name3,0,strlen(name1)-1,len2-len1);
        for(i=len2-len1;i>0;i--)
        {
            rem=((int)name2[i-1])%48-rem;
            name3[i-1]=(char)( ((rem<0)?(-rem):rem)%10+48);
            if(rem<0)
                rem=-1;
            else
                rem=0;
        }
        name3[len2]='\0';
    }
    char *p=name3;
    for(i=0;i<strlen(name3)-1;i++)
    {
        if(name3[i]=='0')
            p++;
        else
            break;
    }
    return p;
}

int main()
{
    char name1[MAX],name2[MAX],name3[MAX],name4[MAX];
    cout<<"Enter1 : ";
    cin>>name1;
    cout<<"Enter2 : ";
    cin>>name2;
    strcpy(name3,sub(name1,name2,name3));
    strcpy(name4,add(name1,name2,name4));
    cout<<"sub = "<<name3;
    cout<<"\nadd = "<<name4;
    return 1;
}
