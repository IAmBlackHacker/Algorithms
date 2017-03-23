#include <iostream>
#include <ctime>
#define MAX 100
using namespace std;
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
    Queue Q;
    bool *explored = new bool[n+1];
    for (int i = 1; i <= n; ++i)
    explored[i] = false;

    Q.enqueue(s);
    explored[s] = true;
    cout << "Breadth first Search starting from vertex ";
    cout << s << " : " << endl;
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
    if(n&m)
        return true;
    else
        return false;
}
int main()
{
    int nv,a,b,VERT[MAX],ne;
    Graph g(MAX);
    clock_t t1;
    cout<<"ENTER NUMBER OF VERTICES : ";
    cin>>nv;
    cout<<"\nENTER ";cout<<nv;cout<<" VERTICES : ";
    for(int i=0;i<nv;i++)
    {
        cin>>VERT[i];
    }
    cout<<"\nENTER NUMBER OF EDGES : ";
    cin>>ne;
    cout<<"\nENTER";cout<<ne;cout<<"EDGES : ";
    for(int i=0;i<ne;i++)
    {
        cin>>a>>b;
        if(validE(a,b,nv,VERT))
            g.addEdge(a,b);
        else
        {
            cout<<"\nYOU ENTERED WRONG EDGES (TRY AGAIN...) .";
            i--;
        }
    }
    cout<<"\nENTER STARTING VERTEX IN BFS : ";
    cin>>ne;
    if(!validE(VERT[0],ne,nv,VERT))
        cout<<"\nSORRY THIS VERTEX NOT FOUND IN GRAPH ....!";
    else
    {
        t1 = clock();
    }
    g.BFS(ne);
    float diff = (double)(clock() - t1)/CLOCKS_PER_SEC ;
    cout <<endl<< "The time taken for Breadth first search: "<< diff << endl;
}

