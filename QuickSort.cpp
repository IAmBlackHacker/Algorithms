#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<math.h>
using namespace std;
struct node
{
    int value;

};
class qsorts
{
        struct node *data;
        int sizeofa,index;
    public:
        qsorts(int nn)
        {
            data=new node [nn];
            sizeofa=nn;
        }
        void insertdata();
        void display();
        void Qsort(int,int,int);
        int partitions(int,int,int);
        ~qsorts()
        {
            delete data;
        }
};
int inputz(char bd='0')
{
    int ch,m=0,s=0;
    int sign=1;
    if(bd =='d' || bd=='D')
    {
            m=rand();
            sign=pow(-1,rand()%2);
            cout<<m*sign<<"   <-- Random value.";
            return m*sign;
    }
    m=(int)bd-48;
    if(m<0 || m>9)
        m=0;
    else if(m<=9 && m>0)
    {
        cout<<m;
        s++;
    }
    if(bd=='-')
    {
        sign=-1;
        cout<<"-";
    }
    do
    {
        ch=getch()-48;
        if(ch==-3 && sign==1)
        {
            sign=-1;
            cout<<"-";
        }
        if((ch==20 || ch ==52) && bd!='0')
        {
            while(m)
            {
                m=m/10;
                s--;
                cout<<"\b \b";
            }
            m=rand();
            sign=pow(-1,rand()%2);
            cout<<m*sign<<"   <-- This is Random value as you press 'D'.";
            return m*sign;
        }
        if(ch<=9 && ch>=0)
            {cout<<ch;m=m*10+ch;s++;}
        else if(ch==-40 && m>0 || (s && ch!=-35 && ch!=-16))
        {
            m=m/10;
            s--;
            cout<<"\b \b";
        }
        else if(ch==-40 && sign==-1)
        {
            cout<<"\b \b";
            sign=1;
        }
    }while((ch!=-35 && ch!=-16) || !s);
    return m*sign;
}
int input()
{
    int ch,m=0,s=0;
    do
    {
        ch=getch()-48;
        if((ch<=9 && ch>=0))
            {cout<<ch;m=m*10+ch;s++;}
        else if(ch==-40 && m>0 || (s && ch!=-35 && ch!=-16))
        {
            m=m/10;
            s--;
            cout<<"\b \b";
        }
    }while((ch!=-35 && ch!=-16) || !s);
    return m;
}
void qsorts::insertdata()
{
    char bd='n';
    cout<<"\n       ";
    for(long int i=0;i<100;i++)
        cout<<char(177);
    cout<<"\n       ";
    for(long int i=0;i<39;i++)
        cout<<char(177);
    cout<<"INSERT VALUES OF NODES";
    for(long int i=0;i<39;i++)
        cout<<char(177);
    cout<<"\n       ";
    for(long int i=0;i<100;i++)
        cout<<char(177);
        cout<<endl;
    cout<<"FOR BY DEFAULT VALUES PRESS 'D' AT ANY STEP ..........\n";
    for(long int i=0;i<sizeofa;i++)
    {
        cout<<"\n  Enter value of node "<<i+1;
        if((i+1)/10==0)
            cout<<" ";
        cout<<" : ";
        if(!(bd=='d' || bd=='D'))
            bd=getch();
        data[i].value=inputz(bd);
    }
    if(bd=='d' || bd=='D')
        getch();
}
void qsorts::display()
{
    cout<<"\n       ";
    for(long int i=0;i<100;i++)
        cout<<char(177);
    cout<<"\n       ";
    for(long int i=0;i<41;i++)
        cout<<char(177);
    cout<<"DISPLAY NODE VALUE";
    for(long int i=0;i<41;i++)
        cout<<char(177);
    cout<<"\n       ";
    for(long int i=0;i<100;i++)
        cout<<char(177);
        cout<<endl;
    for(long int i=0;i<sizeofa;i++)
    {
        cout<<"\n       NODE "<<i+1;
        if((i+1)/10==0)
            cout<<" ";
        cout<<" : "<<data[i].value;
    }
}
int qsorts::partitions(int start,int end,int pivot)
{
    int i,in=start;
    for(i=start;i<=end;i++)
    {
        if(i == index)
            continue;
        if(data[i].value<=pivot)
        {
            if(in == index)
                in++;
            swap(data[i],data[in]);
            in++;
        }
    }
    if(in == end +1)
        in--;
    swap(data[index],data[in]);
    return in;
}
void qsorts::Qsort(int start,int end,int deflt=0)
{
    int pivot;
    if(start<end)
    {
        cout<<"\n       ENTER INDEX OF PIVOT ["<<start<<"-"<<end<<"] (Else by default it take index "<<end<<" for wrong input or Enter negative value to take some pivot to be default) : ";
        if(!deflt && index >=0)
            index=inputz();
        else
        {
            index=end;
            cout<<index;
        }
        if(index<0)
            deflt=1;
        if(index>end || index <start)
        {
            pivot=data[end].value;
            index=end;
        }
        else
            pivot=data[index].value;
        index=partitions(start,end,pivot);
        Qsort(start,index-1,deflt);
        Qsort(index+1,end,deflt);
    }
}
int main()
{
    int n,i;
    char ch;
    do
    {
      system("cls");
      char name[]="\n\n\n\n\n\n                  ENTER NUMBER OF NODES IN ARRAY (size can't be 0 else it take 1) : ";
        i=0;
        while(name[i])
        {
            cout<<name[i++];
            if(i>24)
            Sleep(1);
        }
        n=input();
        if(n==0)
            n=1;
        system("cls");
        qsorts sorts(n);
        sorts.insertdata();
        system("cls");
        strcpy(name,"       INITIAL NODE ARRAY BEFORE SORTING......");
        i=0;
        while(name[i])
        {
            cout<<name[i++];
            Sleep(1);
        }
        sorts.display();
        cout<<"\n\n\n                                                                Enter To Continue.....";
        getch();
        system("cls");
        sorts.Qsort(0,n-1);
        system("cls");
        strcpy(name,"       NODE ARRAY AFTER SORTING......");
        i=0;
        while(name[i])
        {
            cout<<name[i++];
            Sleep(1);
        }
        sorts.display();
        cout<<"\n\n\n                                                                Want To Continue(y/n) : ";
        ch=getche();
    }while(ch=='y' || ch=='Y');
}
