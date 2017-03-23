#include <iostream>
#include <string.h>
#include <ctime>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX 100
using namespace std;
/*start of queue................................................*/
struct node {
    int info;
    node *next;
};

class Queue {
    private:
        node *front;
        node *rear;
    public:
        Queue();
        ~Queue();
        bool isEmpty();
        void enqueue(int);
        int dequeue();
        void display();

};

void Queue::display(){
    node *p = new node;
    p = front;
    if(front == NULL){
        cout<<"\nNothing to Display\n";
    }else{
        while(p!=NULL){
            cout<<endl<<p->info;
            p = p->next;
        }
    }
}

Queue::Queue() {
    front = NULL;
    rear = NULL;
}

Queue::~Queue() {
    delete front;
}

void Queue::enqueue(int data) {
    node *temp = new node();
    temp->info = data;
    temp->next = NULL;
    if(front == NULL){
        front = temp;
    }else{
        rear->next = temp;
    }
    rear = temp;
}

int Queue::dequeue() {
    node *temp = new node();
    int value;
    if(front == NULL){
        cout<<"\nQueue is Emtpty\n";
    }else{
        temp = front;
        value = temp->info;
        front = front->next;
        delete temp;
    }
    return value;
}

bool Queue::isEmpty() {
    return (front == NULL);
}
/*end of queue..................................................*/

/*function to find number of digit for desired outout in table*/
int digit(int n)
{
    int k=0;
    while(n)
    {
        n=n/10;
        k++;
    }
    return k;
}
/*function to display table.....................................*/
void DisplayTable(int vertex,char Hr[50][50],char Vr[50][50])
{
    int dig;
    cout<<endl;
   for(int i=1;i<=vertex;i++)
    {
        if(i==1)
            cout<<char(201);
        else
            cout<<char(204);
        for(int n=0;n<vertex;n++)
        {
            for(int m=0;m<8;m++)
            {
                if(Hr[i-1][n])
                    cout<<char(205);
                else
                    cout<<" ";
                    //cout<<char(196);
            }
            if(n==vertex-1)
            {
                if(i==1)
                    cout<<char(187);
                else
                    cout<<char(185);
            }
            else
            {
                if(i==1)
                    cout<<char(203);
                else
                    cout<<char(206);
            }
        }

        cout<<endl<<char(186)<<"  ";
        for(int k=1;k<=vertex;k++)
        {
            cout<<k+vertex*(i-1)<<"   ";
            dig=digit(k+vertex*(i-1));
            while(5-dig)
            {
                cout<<" ";
                dig++;
            }
            if(Vr[i-1][k-1])
                cout<<"\b\b"<<char(186)<<"  ";
            else
                cout<<" ";
                //cout<<"\b\b"<<char(179)<<"  ";
        }
        cout<<endl;
        if(i==vertex)
            cout<<char(200);

    }
    for(int n=0;n<vertex;n++)
    {
            for(int m=0;m<8;m++)
                    cout<<char(205);
            if(n==vertex-1)
            {
                cout<<char(188);
            }
            else
            {
                cout<<char(202);
            }
    }
}
/*end of function to display table.............................................................*/

class Graph {
    private:
        int n; ///vertices
        int **A; ///edges between two vertices
    public:
        Graph(int size = 2);
        ~Graph();
        bool isConnected(int, int);
        void addEdge(int u, int v);
        void BFS(int );
};

Graph::Graph(int size) {
    int i, j;
    if (size < 2) n = 2;
    else n = size;
    A = new int*[n];
    for (i = 0; i < n; ++i)
        A[i] = new int[n];
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            A[i][j] = 0;
}

Graph::~Graph() {
    for (int i = 0; i < n; ++i)
    delete [] A[i];
    delete [] A;
}

bool Graph::isConnected(int u, int v) {
    return (A[u-1][v-1] == 1);
}

void Graph::addEdge(int u, int v) {
    A[u-1][v-1] = A[v-1][u-1] = 1;
}

void Graph::BFS(int s) {
    char hr[50][50],vr[50][50],*path,Key[]="yynnynnyyynyyyyynyyynnynnyynnynyynyyynyyynnyyyynnynyyyyyynny";
    for(int i=0;i<50;i++)
        for(int k=0;k<50;k++)
    {
        hr[i][k]=vr[i][k]=1;
    }
    Queue Q;
    bool *explored = new bool[n+1];
    for (int i = 1; i <= n; ++i)
    explored[i] = false;

    Q.enqueue(s);
    explored[s] = true;
    cout << "Breadth first Search starting from vertex ";
    cout << s << " : " << endl;
    DisplayTable(n,hr,vr);
    while (!Q.isEmpty())
    {
        int v = Q.dequeue();
        cout << v << " ";
        for (int w = 1; w <= n; ++w)

            if (isConnected(v, w) && !explored[w]) {
                Q.enqueue(w);
                explored[w] = true;
            }
    }
    cout << endl;
    delete [] explored;
}
bool validE(int a,int b,int nv,int VERT[])
{
    int m=0,n=0;
    for(int i=0;i<nv;i++)
    {
        if(VERT[i]==a)
            m=1;
        if(VERT[i]==b)
            n=1;
    }
    if(a==b)
        m=0;
    if(n&m)
        return true;
    else
        return false;
}

void wrt(char name[])
{
    for(long int i=0;i<strlen(name);i++)
    {
        cout<<name[i];
        _sleep(15);
    }
}
int rd()
{
    int ch,m=0;
    do
    {
        ch=getch()-48;
       // cout<<getch();
        if(ch<=9 && ch>=0)
            {cout<<ch;m=m*10+ch;}
        else if(ch==-40 && m>0)
        {
            m=m/10;
            cout<<"\b \b";
        }
    }while((ch!=-35 && ch!=-16) || m==0);
    return m;
}

int main()
{
    int nv,a,b,VERT[MAX],ne;
    char name[MAX+100];
    clock_t t1;

    wrt("ENTER NUMBER OF VERTICES IN ROW: ");
    do{
        nv=rd();
        if(!(nv>1 && nv <MAX))
        {
            while(nv)
            {
                cout<<"\b \b";
                nv=nv/10;
            }
        }
    }while(!(nv>1 && nv <MAX));
    Graph g(nv);
    wrt("\n Matrix of"); cout<<nv<<"x"<<nv; wrt(" VERTICES SUCCESSFULLY CREATED....... ");
    for(int i=0;i<nv*nv;i++)
    {
        VERT[i]=i;
      /*  if(!validV(VERT[i],i,VERT))
        {
            cout<<"\b\b\b\b    \b\b\b\b";
            i--;
            while(VERT[i]!=0)
            {
                cout<<"\b \b";
                VERT[i]=VERT[i]/10;
            }
        }*/
    }
    wrt("\nENTER NUMBER OF EDGES : ");
    do{
        ne=rd();
        if(!(ne<=(nv*(nv-1)/2) && ne>=nv-1))
        {
            while(ne)
            {
                cout<<"\b \b";
                ne=ne/10;
            }
        }
    }while(!(ne<=(nv*(nv-1)/2) && ne>=nv-1));

    wrt("\nENTER ");cout<<ne;wrt(" EDGES(E) : { ");
    for(int i=0;i<ne;i++)
    {
        cout<<"("; a=rd(); cout<<","; b=rd(); cout<<")";
        if(i!=ne-1)
            cout<<" , ";
        else cout<<" }";
        if(validE(a,b,nv,VERT))
            g.addEdge(a,b);
        else
        {
            cout<<"\b\b\b\b\b\b      \b\b\b\b\b\b";
            i--;
            while(a!=0)
            {
                cout<<"\b \b";
                a=a/10;
            }
            while(b!=0)
            {
                cout<<"\b \b";
                b=b/10;
            }
        }
    }
    if(!validE(VERT[0],1/*start vertex*/,nv,VERT))
        wrt("\nSORRY THIS VERTEX NOT FOUND IN GRAPH ....!");
    else
    {
        t1 = clock();
    }
    g.BFS(ne);
    float diff = (double)(clock() - t1)/CLOCKS_PER_SEC ;
    cout <<endl<< "The time taken for Breadth first search: "<< diff << endl;
}
