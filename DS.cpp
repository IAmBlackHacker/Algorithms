#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<string.h>
#include<windows.h>
using namespace std;
COORD coord={0,0};
 void gotoxy(int x,int y)
 {
   coord.X=x;
 coord.Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }
struct node
{
    //int subnode;
    int info;
    //int visit;
    int dist;
    char *path;
    node *right;
    node *left;
    node *up;
    node *down;
};

//start queue **************************************************************************
struct node2
{
    node *info;
    node2 *next;
};

class Queue {
    private:
        node2 *front;
        node2 *rear;
    public:
        Queue();
        ~Queue();
        bool isEmpty();
        void enqueue(node *);
        node *dequeue();
        void display();

};

/*void Queue::display(){
    node2 *p = new node2;
    p = front;
    if(front == NULL){
        cout<<"\nNothing to Display\n";
    }else{
        while(p!=NULL){
            cout<<endl<<p->info;
            p = p->next;
        }
    }
}*/

Queue::Queue() {
    front = NULL;
    rear = NULL;
}

Queue::~Queue() {
    delete front;
}

void Queue::enqueue(node *data) {
    node2 *temp = new node2();
    temp->info = data;
    temp->next = NULL;
    if(front == NULL){
        front = temp;
    }else{
        rear->next = temp;
    }
    rear = temp;
}

node* Queue::dequeue() {
    node2 *temp = new node2();
    node *value;
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
// end of queue**********************************************************************************************
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


class STE
{
    /*private:
        node *start;*/
    public:
        int vertex;
        STE();
        ~STE();
        int retv()
        {
            return vertex;
        }
        void Travel(int);
};
void STE::Travel(int bd=0)
{
    Queue Q;
    int kkk=0,dist=0,Matrix[50][50];
    char hr[50][50],vr[50][50],*path,Key[]="yynnynnyyynyyyyynyyynnynnyynnynyynyyynyyynnyyyynnynyyyyyynny";
    for(int i=0;i<50;i++)
        for(int k=0;k<50;k++)
    {
        hr[i][k]=vr[i][k]=1;
        Matrix[i][k]=0;
    }
    node *tmp=new node;
    node *tmpnode;
   /* node **Arr=new node *[vertex*vertex+1];
    for(int i=0;i<vertex*vertex+1;i++)
        {
            Arr[i]=NULL;
        }*/
    char ch;
    Q.enqueue(start);
    cout <<endl;
    system("cls");
    cout<<"Enter Edge Information.............\n";
    DisplayTable(vertex,hr,vr);
    while (!Q.isEmpty())
    {
        node *v = Q.dequeue();
/*        Arr[v->info]=v;*/
        if(v->info-vertex>0 && !(Matrix[v->info][v->info-vertex]))
        {
          /*  if(Arr[v->info-vertex])
            {
                tmpnode=Arr[v->info-vertex];
            }
            else*/
            {
               /* tmpnode=CreateNode();*/
                tmpnode->info=v->info-vertex;
            }
            cout<<"\n\n\nIs Node "<<v->info<<" connected to node "<<v->info-vertex<<" (Yes(y)/No(Other Key)) : ";
            cout<<"                    \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
            if(bd)
            {
                cout<<Key[kkk];
                ch=Key[kkk++];
            }
            else
                ch=getche();
            if(ch=='y'||ch=='Y')
            {
                v->up=tmpnode;
                Arr[v->info-vertex]=tmpnode;
                tmpnode->down=v;
                Q.enqueue(tmpnode);
                hr[int(v->info/(vertex+0.1))][(v->info-1)%vertex]=0;
                if(v->dist + 1 < tmpnode->dist || tmpnode->dist==0)
                {
                    tmpnode->dist=v->dist+1;
                    tmpnode->path=new char [tmpnode->dist*5];
                    sprintf(tmpnode->path,"%s%d:",v->path,v->info-vertex);
                }

            }
            else
            {
                Arr[v->info]->up=tmp;
            }
            //system("cls");
            gotoxy(0,0);
            cout<<"Enter Edge Information.............\n";
            DisplayTable(vertex,hr,vr);
        }

        if((v->info-1)%vertex>0 && v->left==NULL && ( !Arr[v->info-1] || !(Arr[v->info-1]->right) ))
        {
            if(Arr[v->info-1])
            {
                tmpnode=Arr[v->info-1];
            }
            else
            {
                tmpnode=CreateNode();
                tmpnode->info=v->info-1;
            }
            cout<<"\n\n\nIs Node "<<v->info<<" connected to node "<<v->info-1<<" (Yes(y)/No(Other Key)) : ";
            cout<<"                    \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
            if(bd)
            {
                cout<<Key[kkk];
                ch=Key[kkk++];
            }
            else
                ch=getche();

            if(ch=='y'||ch=='Y')
            {
                v->left=tmpnode;
                Arr[v->info-1]=tmpnode;
                tmpnode->right=v;
                Q.enqueue(tmpnode);
                vr[int(v->info/(vertex+0.1))][(v->info-2)%vertex]=0;
                if(v->dist + 1 < tmpnode->dist || tmpnode->dist==0)
                {
                    tmpnode->dist=v->dist+1;
                    tmpnode->path=new char [tmpnode->dist*5];
                    sprintf(tmpnode->path,"%s%d:",v->path,v->info-1);
                }
            }
            else
            {
                Arr[v->info]->left=tmp;
            }
            //system("cls");
            gotoxy(0,0);
            cout<<"Enter Edge Information.............\n";
            DisplayTable(vertex,hr,vr);
        }

        if((v->info+1)%vertex!=1 && v->right==NULL && ( !Arr[v->info+1] || !Arr[v->info+1]->left ))
        {
            if(Arr[v->info+1])
            {
                tmpnode=Arr[v->info+1];
            }
            else
            {
                tmpnode=CreateNode();
                tmpnode->info=v->info+1;
            }
            cout<<"\n\n\nIs Node "<<v->info<<" connected to node "<<v->info+1<<" ((Yes(y)/No(Other Key)) : ";
            cout<<"                    \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
            if(bd)
            {
                cout<<Key[kkk];
                ch=Key[kkk++];
            }
            else
                ch=getche();
            if(ch=='y'||ch=='Y')
            {
                v->right=tmpnode;
                Arr[v->info+1]=tmpnode;
                tmpnode->left=v;
                Q.enqueue(tmpnode);
                vr[int(v->info/(vertex+0.1))][(v->info-1)%vertex]=0;
                if(v->dist + 1 < tmpnode->dist || tmpnode->dist==0)
                {
                    tmpnode->dist=v->dist+1;
                    tmpnode->path=new char [tmpnode->dist*5];
                    sprintf(tmpnode->path,"%s%d:",v->path,v->info+1);
                }
            }
            else
            {
                Arr[v->info]->right=tmp;
            }
            //system("cls");
            gotoxy(0,0);
            cout<<"Enter Edge Information.............\n";
            DisplayTable(vertex,hr,vr);
        }

        if((v->info+vertex)<=vertex*vertex && v->down==NULL && ( !Arr[v->info+vertex] || !Arr[v->info+vertex]->up ))
        {
            if(Arr[v->info+vertex])
            {
                tmpnode=Arr[v->info+vertex];
            }
            else
            {
                tmpnode=CreateNode();
                tmpnode->info=v->info+vertex;
            }
            cout<<"\n\n\nIs Node "<<v->info<<" connected to node "<<v->info+vertex<<" (Yes(y)/No(Other Key)) : ";
            cout<<"                    \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
            if(bd)
            {
                cout<<Key[kkk];
                ch=Key[kkk++];
            }
            else
                ch=getche();
            if(ch=='y'||ch=='Y')
            {
                v->down=tmpnode;
                Arr[v->info+vertex]=tmpnode;
                tmpnode->up=v;
                Q.enqueue(tmpnode);
                hr[int((v->info+vertex)/(vertex+0.1))][(v->info-1)%vertex]=0;
                if(v->dist + 1 < tmpnode->dist || tmpnode->dist==0)
                {
                    tmpnode->dist=v->dist+1;
                    tmpnode->path=new char [tmpnode->dist*5];
                    sprintf(tmpnode->path,"%s%d:",v->path,v->info+vertex);
                }
            }
            else
            {
                Arr[v->info]->down=tmp;
            }
            //system("cls");
            gotoxy(0,0);
            cout<<"Enter Edge Information.............\n";
            DisplayTable(vertex,hr,vr);
        }
        if(v->info==vertex*vertex)
        {
            dist=v->dist;
            path=new char [v->dist*5];
            path=v->path;
        }
    }//end while
    if(dist!=0)
    {
        cout <<"\n\n\nShortest Distance is "<<dist<<" Unit.                                                                       \n And Shortest path is ";
        for(int i=0;i<strlen(path)-1;i++)
        {
            if(path[i]==':')
                cout<<" -> ";
            else
                cout<<path[i];
        }
    }
    else
        cout<<"\n\n\n          Sorry There is no path found......................!";
}
STE::STE()
{
   /*tart=new node[vertex]vertex];
    start->info=1;
    start->right=NULL;
    start->left=NULL;
    start->up=NULL;
    start->down=NULL;
    start->path=new char [5];
    start->path="1:";
  //    start->subnode=1;
  //  start->visit=0;
    start->dist=0;*/
}
STE::~STE()
{
        /*delete start;*/
}
int main()
{
    cout<<"\n\n\n\n\n\n\n";
    cout<<"    __                     __    _________    ___        ______   ________   ___     ___               _________ \n";
    cout<<"      \\                     /            /      /             /          /      \\       \\                      / \n";
    cout<<"       \\                   /      /            /         /   /     /    /    /   \\   /   \\              /        \n";
    cout<<"        \\                 /      /_____       /         /         /    /    /       /     \\            /_____    \n";
    cout<<"         \\      __       /            /      /         /         /    /    /               \\                /    \n";
    cout<<"          \\       \\     /      /            /____     /         /    /    /                 \\        /           \n";
    cout<<"           \\   /   \\   /      /                 /    /__ /     /__  /    /                   \\      /            \n";
    cout<<"              /       /    ________/           /        /   _______/    /                     \\ _________/       \n";
    getch();

    int i=0,bd;
    char ch,name[]="\nThis is the Program to Find Shortest Path To Reach form Source To Destination in Maze\nThis is a Wonderful Alogorithm based on (Dijkashtra's Algorithm)\n\nProject Made By\n   Lokesh Bhoyar\n   Lalit Mandloi\n   Raghuwendra Meena\n   Anuj Kumar\n\nSpecial Thanks To\nGuided By\n   A K Sukla Sir\n   Computer Science n Eng.\n   Data Structure\n\n\n\nPress Enter To Continue....";
    system("cls");
    while(name[i++]&&!kbhit())
    {
        cout<<name[i];
        _sleep(0);
    }
    getch();
    do{
            STE Dig;
            system("cls");
            bd=0;
            cout<<"\nWant default Maze(Yes(y)/No(Other)) : ";
            ch=getche();
        if(ch=='y'||ch=='Y')
        {
            bd=1;
            Dig.vertex=6;
        }
        else
        {
            cout<<"\n\nEnter Number of Vertices in Row : ";
            cin>>Dig.vertex;
        }
    char hr[50][50],vr[50][50];
    cout<<"\n\n\n                        You Have Successfully Created Matrix with "<<Dig.vertex<<"x"<<Dig.vertex<<" Vertices.";
    getch();
    Dig.Travel(bd);
    cout<<"\n\n\n                    Want to Continue(y/n).....";
    ch=getch();
    }while(tolower(ch)=='y');
}
