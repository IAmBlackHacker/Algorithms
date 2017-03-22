#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<vector>
#include<queue>
#include<stdio.h>
#include<math.h>
#define MAX 100
#include<windows.h>
using namespace std;
int inputg_int(int x,int y,char s[]="integer"){
    char ch;
    char name[100];
    int i=0;
    int sign=1;
    do{
        ch=getch();
        if(int(ch)==8){
                if(i>0)
            name[--i]='\0';
        else
            sign=1;
        }
        if(int(ch)>=48 && int(ch)<=57){
                name[i++]=ch;
                name[i]='\0';
                if(name[0]=='0')i--;
        }
        outtextxy(x,y,"                                                   ");
        if(((ch=='-' && i==0) || sign==-1) && s!="whole"){
            outtextxy(x,y,"-");
            sign=-1;
        }
        outtextxy(x+20,y,name);
    }while(int(ch)!=13 && int(ch)!=32);
    if(s=="whole")
        sign=1;
    return atoi(name)*sign;
}
/*int inputg2_int(int x,int y)
{
    int ch,m=0;
    char name[100];
    do
    {
        ch=getch()-48;
       // cout<<getch();
        if(ch<=9 && ch>=0)
            {
                m=m*10+ch;
                sprintf(name,"%d",m);
                outtextxy(x,y,"                         ");
                outtextxy(x,y,name);
            }
        else if(ch==-40 && m>0)
        {
            m=m/10;
            sprintf(name,"%d",m);
            outtextxy(x,y,"                         ");
            outtextxy(x,y,name);
        }
    }while((ch!=-35 && ch!=-16) || m==0);
    return m;
}
*/
template <typename T>
struct xy{
    long int x;
    T y;
};
double scaleit(double x,double minx,double maxx,double ratio=600){
    //return (x-minx)*ratio/(maxx-minx)+100;
    return x;
}
template <typename T>
void merge(vector < xy<T> > &A,int s,int m,int e,char o){
    int t=m+1,r=s,j=0;
    vector< xy<T> > B;
    while(s<=m && t<=e){
        if(o=='a'){
            if(A[s].x<A[t].x){
                B.push_back(A[s++]);
            }
            else{
                B.push_back(A[t++]);
            }
        }
        else{
            if(A[s].x>A[t].x){
                B.push_back(A[s++]);
            }
            else{
                B.push_back(A[t++]);
            }
        }
    }
    while(s<=m){
        B.push_back(A[s++]);
    }
    while(t<=e){
        B.push_back(A[t++]);
    }
    for(int i=r;i<=e;i++){
        A[i]=B[j++];
    }
}
template <typename T>
void merge_sort(vector < xy<T> > &A,int s,int e,char o='a'){
    if(s<e){
        int m=(s+e)/2;
        merge_sort(A,s,m,o);
        merge_sort(A,m+1,e,o);
        merge(A,s,m,e,o);
    }
}
int orientation(struct xy<long int> p,struct xy<long int> q,struct xy<long int> r){
    float val=(q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);
    if(val == 0) return 0;
    return (val>0)?1:2;
}
double pdist(xy<long int> p,xy<long int> q,xy<long int> r){
    double area=p.x*(q.y-r.y)+q.x*(r.y-p.y)+r.x*(p.y-q.y);
    double base=sqrt(pow(p.x-r.x,2)+pow(p.y-r.y,2));
    return 2*area/base;
}
bool search_point(int s,int e,vector < xy< pair<int,int> > > points){
    for(int i=0;i<points.size();i++){
        if(s==points[i].y.first && e==points[i].y.second){
            return true;
        }
    }
    return false;
}
 vector<int> line_at_min_dist(xy<long int> mouse,vector < xy<long int> > point,vector < xy< pair<int,int> > > selpoint,int color){
     setcolor(color);
     vector<int> si;
     si.push_back(point.size()-2); si.push_back(point.size()-1);
     double min_d=abs(pdist(point[point.size()-2],mouse,point[point.size()-1]));
     for(int i=0;i<point.size()-1;i++){
        for(int j=i+1;j<point.size();j++){
            double temp_d=abs(pdist(point[i],mouse,point[j]));
            if(!(search_point(i,j,selpoint)))
            line(point[i].x,point[i].y,point[j].x,point[j].y);
            if(temp_d<min_d){
                min_d=temp_d;
                si[0]=i; si[1]=j;
            }
        }
     }
     return si;
}
int mdist_i(xy<long int> p,xy<long int> q,vector < xy<long int> > point){
    double m_dist=pdist(p,point[0],q);
    int si=0;
    for(int i=1;i<point.size();i++){
        double tdist=pdist(p,point[i],q);
        if(tdist>m_dist && (point[i].x!=p.x || point[i].y!=p.y) && (point[i].x!=q.x || point[i].y!=q.y)){
            m_dist=tdist;
            si=i;
        }
    }
    if(m_dist<0 || (point[si].x==p.x && point[si].y==p.y) || (point[si].x==q.x && point[si].y==q.y)){
        return -1;
    }
    return si;
}
void hull_dc(vector < xy<long int> > point,int s,int e,vector < xy<long int> > &hull){
    int si=mdist_i(point[s],point[e],point);
    //cout<<si;
    if(si<0){return;}
    hull.push_back(point[si]);
    hull_dc(point,s,si,hull);
    hull_dc(point,si,e,hull);
}
double minx,maxx,miny,maxy;
void print(vector < xy<long int> > point){
    setcolor(RED);
    minx=point[0].x;
    maxx=point[0].x;
    miny=point[0].y;
    maxy=point[0].y;
    for(int i=1;i<point.size();i++){
        if(point[i].x<minx){
            minx=point[i].x;
        }
        else if(point[i].x>maxx){
            maxx=point[i].x;
        }
        if(point[i].y<miny){
            miny=point[i].y;
        }
        else if(point[i].y>maxy){
            maxy=point[i].y;
        }

    }
    char name[100];
    for(int i=0;i<point.size();i++){
        circle(scaleit(point[i].x,minx,maxx,1000),scaleit(point[i].y,miny,maxy),5);
        /*sprintf(name,"(%d,%d)",point[i].x,point[i].y);
        outtextxy(scaleit(point[i].x,minx,maxx)+20,scaleit(point[i].y,miny,maxy),name);*/
    }
}
vector < xy<long int> > Convex_DAC(vector < xy<long int> > points){
    vector < xy<long int> > hull;
    merge_sort(points,0,points.size()-1);
    hull.push_back(points[0]); hull.push_back(points[points.size()-1]);
    hull_dc(points,0,points.size()-1,hull);
    int m=hull.size();
    merge_sort(hull,0,m-1);
    hull_dc(points,points.size()-1,0,hull);
    merge_sort(hull,m,hull.size()-1,'d');
    return hull;
}

vector < xy<long int> > Convex_Jarvis(vector < xy<long int> > points){
    xy<long int> min_x=points[0];
    int j=0,n=points.size();
    vector < xy<long int> > hull;
    for(long int i=1;i<points.size();i++){
        if(points[i].x<min_x.x){
            min_x=points[i];
            j=i;
        }
    }
    int p=j,r;
    do{
        hull.push_back(points[p]);
        //cout<<"\n     "<<points[p].x<<"  "<<points[p].y;
        r=(p+1)%n;
        for(int q=0;q<n;q++){
            if(orientation(points[p],points[q],points[r])==2){
                r=q;
            }
        }
        p=r;
    }while(p!=j);
    return hull;
}
int main1(){
    initwindow(6000,5000,"Convex Hull ...");
    settextstyle(6,0,2);
    setfillstyle(10,4);
    bar(0,0,10000,10000);
    vector < xy<long int> > points;
    long int n,m;
    char name[100];
    xy<long int> point;
    do{
        setcolor(GREEN);
        outtextxy(100,100,"ENTER NUMBER OF POINTS :            ");
        try{
            setcolor(BLUE);
            n=inputg_int(550,100);
            throw n;
        }
        catch (long int x){
            if(x<3){
                setcolor(RED);
                outtextxy(100,150,"VALUE MUST BE GREATER THAN EQUAL TO 3 AND INTEGER");
                outtextxy(100,180,"TRY AGAIN ...");
            }
            else{
                break;
            }
            /*cin.clear();
            cin.ignore(100, '\n');*/
        }
    }while(true);
    setfillstyle(10,4);
    bar(0,0,10000,10000);
    setcolor(GREEN);
    sprintf(name,"ENTER %d POINTS",n);
    outtextxy(100,100,name);
    m=n;
    while(n &&true){
        setcolor(1);
        sprintf(name,"ENTER POINT %d",m-n);
        outtextxy(100,150,name);
        setcolor(RED);
        //outtextxy(100,200,"ENTER COR X :                                ");
        //setcolor(BLUE);
        //point.x=inputg_int(350,200);
        //setcolor(RED);
        //outtextxy(100,200,"ENTER COR Y :                                ");
        //setcolor(BLUE);
        //point.y=inputg_int(350,200);
        //getmouseclick(2,x,y);
        POINT p;
        GetCursorPos(&p);
        int x=p.x;
        int y=p.y;
        if(GetAsyncKeyState(VK_LBUTTON) && true){
            circle(x-8,y-28,4);
            n--;
            point.x=p.x;
            point.y=p.y;
            delay(300);
            points.push_back(point);
        }
        //delay(20);
        //cout<<", ";
        if(n>1000){break;}
    }
    setfillstyle(1,0);
    bar(0,0,10000,10000);
    print(points);
    //Convex_Jarvis(points);
    vector< xy<long int> > hull=Convex_DAC(points);
    n=hull.size();
    setcolor(BLUE);
    outtextxy(400,20,"CONVEX HULL FORM");
    outtextxy(1250,40,"CON HULL POINTS");
    for(int i=0;i<n;i++){
            setcolor(GREEN);
            sprintf(name,"[ %d,%d ]",hull[i].x,hull[i].y);
            outtextxy(1250,25*i+65,name);
            circle(scaleit(hull[i].x,minx,maxx,1000),scaleit(hull[i].y,miny,maxy),10);
            setcolor(YELLOW);
            line(scaleit(hull[i].x,minx,maxx,1000),scaleit(hull[i].y,miny,maxy),scaleit(hull[(i+1)%n].x,minx,maxx,1000),scaleit(hull[(i+1)%n].y,miny,maxy));
            //line(hull[i].x*40,hull[i].y*40,hull[i+2].x*40,hull[i+2].y*40);
    }
    getch();
    closegraph();
}
bool valid_span(pair<int,int> E,vector<int> &notvisit){
    if(notvisit[E.first]==notvisit[E.second] && notvisit[E.first]!=-1)
        return false;

    int first=notvisit[E.first],temp2;
    vector <int> ch; ch.push_back(E.first); ch.push_back(E.second);
    while(first!=-1){
        ch.push_back(first);
        first=notvisit[first];
    }

    first=notvisit[E.second];
    temp2=E.second;
    cout<<E.first<<E.second<<notvisit[E.second]<<endl;
    while(first!=-1){
            temp2=first;
            ch.push_back(first);
            first=notvisit[first];
    }
    for(int i=0;i<ch.size()-1;i++){
        for(int j=i+1;j<ch.size();j++){
            if(ch[i]==ch[j]){
                return false;
            }
        }
    }
    notvisit[temp2]=E.first;
    return true;

}
vector< xy< pair<int,int> > > kruskal_algo(vector< xy<long int> > V,vector< xy< pair<int,int> > > E,vector < xy<long int> > points){
    merge_sort(E,0,E.size()-1);
    char name[100];
    vector< xy< pair<int,int> > > Result;
    vector<int> notvisit(V.size(),-1);
    outtextxy(200,20,"GREEN GRAPH IS SPANNING TREE");
    setcolor(BLUE);
    for(int i=0;i<E.size();i++){
            line(points[E[i].y.first].x,points[E[i].y.first].y,points[E[i].y.second].x,points[E[i].y.second].y);
            setcolor(YELLOW);
            sprintf(name,"[%d,%d]",points[E[i].y.first].x,points[E[i].y.first].y);
            //outtextxy(points[E[i].y.first].x,points[E[i].y.first].y,name);
            sprintf(name,"[%d,%d]",points[E[i].y.second].x,points[E[i].y.second].y);
            //outtextxy(points[E[i].y.second].x,points[E[i].y.second].y,name);
            circle(points[E[i].y.first].x,points[E[i].y.first].y,5);
            circle(points[E[i].y.second].x,points[E[i].y.second].y,5);
            setcolor(BLUE);
            sprintf(name,"[%d]",E[i].x);
            outtextxy((points[E[i].y.first].x+points[E[i].y.second].x)/2,(points[E[i].y.first].y+points[E[i].y.second].y)/2,name);

    }
    for(int i=0;i<E.size();i++){
        if(valid_span(E[i].y,notvisit)){
            xy< pair<int,int> > temp;
            temp=E[i];
            setfillstyle(0,0);
            bar(0,0,10000,10000);
            Result.push_back(temp);
            setcolor(GREEN);
            for(int i=0;i<Result.size();i++){
                line(points[Result[i].y.first].x,points[Result[i].y.first].y,points[Result[i].y.second].x,points[Result[i].y.second].y);
                sprintf(name,"[%d]",Result[i].x);
                outtextxy((points[Result[i].y.first].x+points[Result[i].y.second].x)/2,(points[Result[i].y.first].y+points[Result[i].y.second].y)/2,name);
            }
            getch();
            //notvisit[E[i].y.first]=notvisit[E[i].y.second]=0;
        }
    }
    cout<<Result.size();
    return Result;
}
int main2(){
    initwindow(6000,5000,"Spanning");
    settextstyle(6,0,2);
    setfillstyle(10,4);
    bar(0,0,10000,10000);
    vector < xy<long int> > points;
    char name[100];
    xy<long int> point;
    long int m,n;
    do{
        setcolor(GREEN);
        outtextxy(100,100,"ENTER NUMBER OF POINTS :            ");
        try{
            setcolor(BLUE);
            n=inputg_int(550,100);
            throw n;
        }
        catch (long int x){
            if(x<3){
                setcolor(RED);
                outtextxy(100,150,"VALUE MUST BE GREATER THAN EQUAL TO 3 AND INTEGER");
                outtextxy(100,180,"TRY AGAIN ...");
            }
            else{
                break;
            }
            /*cin.clear();
            cin.ignore(100, '\n');*/
        }
    }while(true);
    setfillstyle(10,4);
    bar(0,0,10000,10000);
    setcolor(GREEN);
    sprintf(name,"ENTER %d POINTS",n);
    outtextxy(100,100,name);
    m=n;
    while(n){
        setcolor(1);
        sprintf(name,"ENTER POINT %d",m-n+1);
        outtextxy(100,150,name);
        setcolor(RED);
        POINT P;
        GetCursorPos(&P);
        int x=P.x;
        int y=P.y;
        if(GetAsyncKeyState(VK_LBUTTON)){
            n--;
            point.x=x;
            point.y=y;
            points.push_back(point);
            circle(x,y,4);
            delay(300);
        }
    }
    n=m*(m+1)/2;
    vector < xy< pair<int,int> > > E;
    setfillstyle(1,0);
    bar(0,0,10000,10000);
    print(points);
    while(n){
        if(point.x>1300 && point.y>700){setcolor(BLUE);}
        else
        setcolor(RED);
        rectangle(1300,700,1500,750);
        outtextxy(1340,715,"SUBMIT");
        setcolor(1);
        sprintf(name,"CREATE GRAPH");
        outtextxy(200,80,name);
        setcolor(RED);
        POINT P;
        GetCursorPos(&P);
        point.x=P.x;
        point.y=P.y;
        vector <int> si=line_at_min_dist(point,points,E,BLACK);
        setcolor(RED);
        line(points[si[0]].x,points[si[0]].y,points[si[1]].x,points[si[1]].y);
        if(GetAsyncKeyState(VK_LBUTTON)){
            if(point.x>1300 && point.y>700){
                int f=true,j;
                for(int i=0;i<points.size();i++){
                    for(j=0;j<E.size();j++){
                        if(i==E[j].y.first || i==E[j].y.second)
                            break;
                    }
                    if(j==E.size()){
                        f=false;
                        setcolor(RED);
                        outtextxy(600,80,"(ALL POINTS MUST CONNECTED TO GRAPH)");
                        break;
                    }
                }
                if(f)
                break;
            }
            else{
                    n--;
                    xy< pair<int,int> > temp;
                    temp.y=std::make_pair(si[0],si[1]);
                    temp.x=0;
                    E.push_back(temp);
            }
            delay(300);
        }
        setcolor(GREEN);
        for(int i=0;i<E.size();i++){
            line(points[E[i].y.first].x,points[E[i].y.first].y,points[E[i].y.second].x,points[E[i].y.second].y);
        }
    }

    setfillstyle(1,0);
    bar(0,0,10000,10000);
    print(points);

    n=E.size();
    //vector<int> W(E.size(),0);
    delay(300);
    while(n){
        setcolor(GREEN);
        sprintf(name,"ENTER WEIGHTS OF LINES(%d)",n);
        outtextxy(100,100,name);
        setcolor(0);
        outtextxy(100,150,"                                            ");
        setcolor(RED);
        POINT P;
        GetCursorPos(&P);
        point.x=P.x;
        point.y=P.y;
        vector <int> si=line_at_min_dist(point,points,E,BLACK);
        setcolor(BLUE);
        line(points[si[0]].x,points[si[0]].y,points[si[1]].x,points[si[1]].y);
        if(GetAsyncKeyState(VK_LBUTTON)){
            for(int i=0;i<E.size();i++){
                if(E[i].y.first==si[0] && E[i].y.second==si[1]){
                    setcolor(1);
                    sprintf(name,"ENTER WEIGHT :                           ");
                    outtextxy(100,150,name);
                    E[i].x=inputg_int(350,150);
                    sprintf(name,"[%d]      ",E[i].x);
                    outtextxy((points[si[0]].x+points[si[1]].x)/2,(points[si[0]].y+points[si[1]].y)/2,name);
                    n=0;
                    for(int k=0;k<E.size();k++){
                        if(E[k].x==0){
                            n++;
                        }
                    }
                    break;
                }
            }
            delay(300);
        }
        setcolor(GREEN);
        for(int i=0;i<E.size();i++){
            line(points[E[i].y.first].x,points[E[i].y.first].y,points[E[i].y.second].x,points[E[i].y.second].y);
        }
    }
    setfillstyle(1,0);
    bar(0,0,10000,10000);
    print(points);
    setcolor(1);
    sprintf(name,"SPANNING GRAPH");
    outtextxy(200,80,name);
    vector< xy< pair<int,int> > > Result=kruskal_algo(points,E,points);
    setcolor(GREEN);
    for(int i=0;i<Result.size();i++){
        line(points[Result[i].y.first].x,points[Result[i].y.first].y,points[Result[i].y.second].x,points[Result[i].y.second].y);
    }
    getch();
    closegraph();
}
int main(){
    char n;
    while(true){
        system("cls");
        cout<<"\n\n     1. Convex Hull\n     2. Minimum Spanning Tree\n     3. Exit\n\n   Enter Your Choice : ";
        n=getche();
        switch(n){
            case '1':
                main1();
                break;
            case '2':
                main2();
                break;
            case '3':
                exit(1);
            default:
            cout<<"\n\n     Enter Right Choice ...";
            getche();
                continue;
        }
        cout<<"Want To Contine[y/n] : ";
        n=getche();
        if(n=='y' || n=='Y')
            break;
    }
}
