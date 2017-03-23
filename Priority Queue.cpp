#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
using namespace std;

#define MAX 100
struct PQ
{
    long int prio;
};
struct PQ ARR[MAX];

void insert(long int low, long int count) {
        long int pos = (2 * low) + 1, current = ARR[low].prio;
        while (pos <= count) {
                if (pos < count && ARR[pos].prio > ARR[pos + 1].prio)
                        pos++;
                if (current <= ARR[pos].prio)
                        break;
                else {
                        ARR[low].prio = ARR[pos].prio;
                        low = pos;
                        pos = (2 * low) + 1;
                }
        }
        ARR[low].prio = current;
        return;
  }

  void BuildHeap(long int n)
  {
        long int low;
        for (low = n/2 - 1; low >= 0; low--) {
                insert(low, n-1);
        }
        return;
  }
//////////////////////////////////////////////////////////////////////////////////////////////////////H4K3R!
void build(long int index)
{
    long int val = ARR[index].prio;
        while (ARR[(index - 1) / 2].prio >= val) {
                ARR[index].prio = ARR[(index - 1) / 2].prio;
                if (!index)
                        break;
                index = (index - 1) / 2;
        }
        ARR[index].prio = val;
        return;
}

void addnode(long int val, long int n)
{
    ARR[n].prio = val;
    build(n);
    return;
}
long int deletenode(long int n)
{
    if(n==0)
    {
        cout<<"\n\n\n\n\n\n          EMPTY QUEUE.........!";
        getch();
        return 1;
    }
    long int val = ARR[0].prio;
    ARR[0].prio = ARR[n].prio;
    insert(0, n - 1);
    printf("\n\n\n\n      %d IS DELETED\n", val);
    getch();
    return val;
}
void replacenode(long int val,long int n)
{
    long int i;
    ARR[0].prio =  val;
    for (i = n/2 - 1; i >= 0; i--)
    insert(i, n - 1);
    return;
}
int ndig(int n)
{
    int m=0;
    while(n)
    {
        n=n/10;
        m++;
    }
    return m;
}
void show(int TOP)
{
    if(TOP==0)
    {
        cout<<"\n\n\n\n\n\              EMPTY QUEUE................!";
        getch();
        return;
    }
    long int m=1,Height=(log(TOP+0.1)/log(2)),k,tp;
    cout<<"\n";
    for(k=0;k<pow(2,Height+2);k++)
        cout<<" ";
    for(long int i=0;i<TOP;i++)
    {
        for( int o=0;o<(ndig(ARR[i].prio))/2;o++ )
            cout<<"\b";
       cout<<ARR[i].prio;
       for( int o=0;o<(ndig(ARR[i].prio)-1)/2;o++ )
            cout<<"\b";
       for(k=0;k<pow(2,Height+3)-1;k++)
                cout<<" ";
       if(i==pow(2,m)-2)
       {
           cout<<"\n";
          /* for(k=0;k<pow(2,Height+2)-2;k++)
            cout<<" ";
            cout<<"/  \\\n";*/
       // pppppppppppppppppppppppppp
            //for( int o=0;o<(ndig(ARR[i].prio))/2;o++ )
           // cout<<"\b";
           for(int mmm=0;mmm<Height;mmm++)
           {
               tp=1;
                for(k=0;k<pow(2,Height+2)-2-mmm*3;k++)
                    cout<<" ";
                    if(i+(tp++)<TOP)
                    cout<<"/";
                    for(k=0;k<mmm*6;k++)
                        cout<<" ";
                    if(i+(tp++)<TOP)
                    cout<<"   \\";
                for(long int ii=1;ii<pow(2,m-1);ii++)
                {

                    for(k=0;k<pow(2,Height+3)-5-mmm*6;k++)
                        cout<<" ";
                        if(i+(tp++)<TOP)
                        cout<<"/";
                        for(k=0;k<mmm*6;k++)
                            cout<<" ";
                            if(i+(tp++)<TOP)
                        cout<<"   \\";
                }
                cout<<endl;
           }
           Height--;
           for(k=0;k<pow(2,Height+2);k++)
                cout<<" ";
            m++;
       }
    }
    getch();
}
int main()
{
    long int TOP,n,val;
    cout<<"INITIALY NUMBER OF ELEMENTS IN QUEUE:";
    cin>>TOP;
    if(TOP<1 || TOP>100)
    cout<<"\n\n\n Sorry You Enter Wrong Value Please Try Again............!";
    cout<<"ENTER "<<TOP<<" ELEMENTS:";
    for(int i=0;i<TOP;i++)
        cin>>ARR[i].prio;
        BuildHeap(TOP);
    do
    {
        system("cls");
        cout<<"_____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________";
        cout<<"                                                                                                        PRIORITY QUEUE                                                                                                                       ";
        cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
        cout<<"\n1. INSERT NODE\n2. DELETE NODE\n3. REPLACE ROOT NODE\n4. SHOW BINARY HEAP\n5 .EXIT\n\nENTER YOUR CHOICE[1-5]:";
        n=int(getche())-48;
        switch(n)
        {
            case 1:

                cout<<"\n\nENTER VALUE OF NEW NODE:";
                cin>>val;
                addnode(val,TOP);
                TOP++;
                break;
            case 2:
                deletenode(TOP);
                if(TOP>0)
                TOP--;
                break;
            case 3:
                printf("\n\nENTER VALUE TO REPLACE:");
                cin>>val;
                replacenode(val,TOP);
                break;
            case 4:
                show(TOP);
                break;
            case 5:
                exit(0);
            default:
                cout<<"\n\n\nSORRY YOU ENTERD WRONG OPTION..................!\nTry Again...";
                getch();
        }
    }while(TOP<MAX);
}
