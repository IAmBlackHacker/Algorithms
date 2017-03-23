#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

struct TH
{
    int data;
    struct TH *node;
};
struct TH *tower1,*tower2,*tower3,*tower;
void push(int ele,int tn)
{
    if(tn==1)
        tower=tower1;
    else if(tn==2)
        tower=tower2;
    else if(tn==3)
        tower=tower3;
    struct TH *newn=new struct TH;
    if(!newn)
    {
        printf("Overflow! Overflow! Overflow!");
    }
    else
    {
        newn->data=ele;
        newn->node=NULL;
        while(tower->node != NULL)
        {
            tower=tower->node;
        }
        tower->node=newn;
    }
}
int pop(int tn)
{
    if(tn==1)
        tower=tower1;
    else if(tn==2)
        tower=tower2;
    else if(tn==3)
        tower=tower3;
    if(tower->node=NULL)
    {
        cout<<"Underflow!";
        return -1;
    }
    while(tower->node->node != NULL)
    {
        tower=tower->node;
    }
    int k=tower->node->data;
    tower->node=NULL;
    return k;
}
void show()
{
    struct TH *tow1=tower1,*tow2=tower2,*tow3=tower3;
    while(tow1->node!=NULL || tow2->node!=NULL || tow3->node!=NULL)
    {
        if(tow1->node!=NULL)
        {
            tow1=tow1->node;
            cout<<tow1->data;
        }
        else
        {
            cout<<"       ";
        }
        if(tow2->node!=NULL)
        {
            tow2=tow2->node;
            cout<<tow2->data;
        }
        else
        {
            cout<<"       ";
        }
        if(tow3->node!=NULL)
        {
            tow3=tow3->node;
            cout<<tow3->data<<endl;
        }
        else
        {
            cout<<"\n";
        }
    }
    cout<<"____________________________________________________\n";
    cout<<"TOWER1                 TOWER2                 TOWER3\n";
    cout<<"----------------------------------------------------\n";
}
void ToH(int n,int from=1, int to=3, int other=2)
{
    if(n>0)
    {
        ToH(n-1,from,other,to);
        push(pop(from),to);
        show();
        ToH(n-1,other,to,from);
    }
}
int main()
{
    tower1=(struct TH *)malloc(sizeof(TH)); tower1->node=NULL;
    tower2=(struct TH *)malloc(sizeof(TH)); tower2->node=NULL;
    tower3=(struct TH *)malloc(sizeof(TH)); tower3->node=NULL;
    int n;
    cout<<"Enter the number of Element in Tower 1:";
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        push(i,1);
    }
    pop(1);
   // ToH(n);
}
