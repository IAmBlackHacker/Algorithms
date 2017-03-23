#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include <graphics.h>
#define  TABLE_SIZE 10
using namespace std;

namespace Chaining
{
    int calK(char *name)
    {
        int K=0;
        for(int i=0;i<strlen(name);i++)
        {
            K+=(int)name[i];
        }
        return K;
    }
    class HashNode
    {
        public:
            int key;
            char data[200];
            HashNode(char data[])
            {
                strcpy(this->data,data);
                key=calK(data);
                next=NULL;
            }
            HashNode *next;
    };

    int enqueue(HashNode *(&start),char data[])
    {
        HashNode *temp=new HashNode(data);
        if(start == NULL)
        {
            start = temp;
        }
        else
        {
            HashNode *tmp=start;
            while(tmp->next)
            {
                if(!strcmp(data,tmp->data))
                    return 0;
                tmp=tmp->next;
            }
            if(!strcmp(data,tmp->data))
                    return 0;
            tmp->next=temp;
        }
        return 1;
    }

    void displayA(HashNode **table)
    {
        char name[100];
        rectangle(100,350,1800,350+40*TABLE_SIZE);
        int m;
        for(int i=0;i<TABLE_SIZE;i++)
        {
            if(table[i]!=NULL)
            {
                   setcolor(5);
                   HashNode *tmp=table[i];
                   m=0;
                   do
                   {
                       outtextxy(120+m*200,360+40*i,tmp->data);
                       m++;
                       tmp=tmp->next;
                   }while(tmp);
            }
            setcolor(BLUE);
            sprintf(name,"%d",i);
            outtextxy(60,360+40*i,name);
            setcolor(RED);
            line(100,390+40*i,1800,390+40*i);
        }
        getch();
    }

    class HashMap
    {
        private:
            HashNode **htable;
        public:
            HashMap()
            {
                htable = new HashNode* [TABLE_SIZE];
                for (int i = 0; i < TABLE_SIZE; i++)
                {
                    htable[i] = NULL;
                }
            }

            ~HashMap()
            {
                for (int i = 0; i < TABLE_SIZE; i++)
                {
                    if (htable[i] != NULL)
                        delete htable[i];
                }
                delete[] htable;
            }
            /*
             * Hash Function
             */
            int HashFunc(int key)
            {
                return key % TABLE_SIZE;
            }
            /*
             * Insert Element at a key
             */
            void Insert(char data[])
            {
                int key=calK(data);
                int hash_val = HashFunc(key);
                if(!enqueue(htable[hash_val],data))
                    outtextxy(200,900,"DATA ALREADY FOUND........!");
                displayA(htable);
            }
            /*
             * Search Element at a key
             */
            int Search(int key,char data[])
            {
                int hash_val = HashFunc(key);
                int init =1;
                HashNode *tmp=htable[hash_val];
                if(tmp)
                    do
                    {
                        if(!strcmp(data,tmp->data))
                        {
                            init=0;
                            break;
                        }
                        tmp=tmp->next;
                    }while(tmp);
                if (init)
                    return -1;
                else
                    return  hash_val;
            }
            /*
             * Remove Element at a key
             */
            int Remove(int key,char data[])
            {
                int hash_val = HashFunc(key);
                int init =1;
                HashNode *tmp=htable[hash_val],*tmpp=NULL;
                if(tmp)
                    do
                    {
                        if(!strcmp(data,tmp->data))
                        {
                            init=0;
                            if(tmpp==NULL)
                            {
                                htable[hash_val]=tmp->next;
                            }
                            else
                            {
                               tmpp->next=tmp->next;
                            }
                            delete tmp;
                            break;
                        }
                        tmpp=tmp;
                        tmp=tmp->next;
                    }while(tmp);
                if (init)
                    return -1;
                else
                    return  hash_val;

            }
    };

    /*
     * Main Contains Menu
     */
     char *input_chr(int x,int y)
     {
        outtextxy(x,y,"                                                                           ");
        char ch;
        int s=0;
        char name[500]="";
        do
        {
            ch=getch();
            if((int)ch<=122 && (int)ch>=48)
            {
                    name[s++]=ch;
                    outtextxy(x,y,"                                                                           ");
                    outtextxy(x,y,name);
            }
            else if((int)ch==8 && s>0)
            {
                name[--s]='\n';
                outtextxy(x,y,"                                                                           ");
                outtextxy(x,y,name);
            }
        }while(((int)ch!=13 && (int)ch!=32));
        return name;
     }

     int input_int(int x,int y)
    {
        outtextxy(x,y,"                         ");
        int ch,m=0;
        char name[100];
        do
        {
            ch=getch()-48;
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
    void Chaining()
    //int main()
    {
        //initwindow(6000,6000);
        cleardevice();
        char tmp[100],ch,data[200];
        HashMap hash;
        int choice=1,m,key;
        while(1)
        {
           /* for(int i=0;i<30;i++)
            {
                setcolor(i);
                outtextxy(200,100+30*i,"sdfsdfdsfdsf dfsfASD SFS");
            }
            getch();*/
            cleardevice();
            setcolor(RED);
            rectangle(320,90,1550,190);
            rectangle(325,95,1545,185);
            settextstyle(6,0,4);
            setcolor(BLUE);
            outtextxy(350,120," OPERATIONS ON HASH TABLE ( CHAINING ) ");
            do
            {
                    setcolor(BLACK);
                    setfillstyle(1,0);
                    bar(400,250,1500,500);
                    if(choice==1)
                    {
                        setcolor(10);
                        settextstyle(6,0,4);
                        m=80;
                    }
                    else
                    {
                         setcolor(2);
                         settextstyle(6,0,3);
                         m=0;
                    }

                    outtextxy(710-m,280,"INSERT DATA INTO TABLE");
                    if(choice==2)
                    {
                        setcolor(10);
                        settextstyle(6,0,4);
                        m=100;
                    }
                    else
                    {
                         setcolor(2);
                         settextstyle(6,0,3);
                         m=0;
                    }
                    outtextxy(680-m,320,"SEARCH ELEMENT USING DATA");
                    if(choice==3)
                    {
                        setcolor(10);
                        settextstyle(6,0,4);
                        m=80;
                    }
                    else
                    {
                         setcolor(2);
                         settextstyle(6,0,3);
                         m=0;
                    }
                    outtextxy(685-m,360,"DELETE ELEMENT USING DATA");
                    if(choice==4)
                    {
                        setcolor(10);
                        settextstyle(6,0,4);
                        m=15;
                    }
                    else
                    {
                         setcolor(2);
                         settextstyle(6,0,3);
                         m=0;
                    }
                    outtextxy(885-m,400,"EXIT");
                    ch=getch();
                    if((int)ch==72 && choice>1)
                        choice--;
                    if((int)ch==80 && choice <4)
                        choice++;

            }while((int)ch!=13);
            setfillstyle(10,2);
            bar(0,0,10000,10000);
            setcolor(BLUE);
            switch(choice)
            {
            case 1:
                setcolor(RED);
                rectangle(320,90,1550,190);
                rectangle(325,95,1545,185);
                settextstyle(6,0,4);
                setcolor(BLUE);
                outtextxy(740,120,"INSERT DATA");
                settextstyle(6,0,3);
                outtextxy(100,250,"ENTER DATA TO BE INSERTED( ANY TYPE ) : ");
                outtextxy(940,290,"                                                                           ");
                outtextxy(100,290,"CALCULATED KEY IS : ");
                setcolor(RED);
                strcpy(data,input_chr(940,250));
                key=calK(data);
                sprintf(tmp,"%d",key);
                outtextxy(940,290,tmp);
                hash.Insert(data);
                break;
            case 2:
                setcolor(RED);
                rectangle(320,90,1550,190);
                rectangle(325,95,1545,185);
                settextstyle(6,0,4);
                setcolor(BLUE);
                outtextxy(740,120,"SEARCH DATA");
                settextstyle(6,0,3);
                outtextxy(100,250,"ENTER DATA TO BE SEARCHED : ");
                outtextxy(940,290,"                                                                           ");
                outtextxy(100,290,"CALCULATED KEY IS : ");
                setcolor(RED);
                strcpy(data,input_chr(940,250));
                key=calK(data);
                sprintf(tmp,"%d",key);
                outtextxy(940,290,tmp);
                if(hash.Search(key,data) == -1)
                {

                    sprintf(tmp,"NO DATA FOUND AT KEY %d.",key);
                    outtextxy(500,450,tmp);
                    getch();
                    continue;
                }
                else
                {
                    sprintf(tmp,"DATA FOUND AT KEY %d IS : %s",key,data);
                    outtextxy(500,450,tmp);
                    getch();
                }
                break;
            case 3:
                setcolor(RED);
                rectangle(320,90,1550,190);
                rectangle(325,95,1545,185);
                settextstyle(6,0,4);
                setcolor(BLUE);
                outtextxy(740,120,"DELETE DATA");
                settextstyle(6,0,3);
                outtextxy(100,250,"ENTER DATA TO BE DELETED : ");
                outtextxy(940,290,"                                                                           ");
                outtextxy(100,290,"CALCULATED KEY IS : ");
                setcolor(RED);
                strcpy(data,input_chr(940,250));
                key=calK(data);
                sprintf(tmp,"%d",key);
                outtextxy(940,290,tmp);
                if(hash.Remove(key,data) == -1)
                {

                    sprintf(tmp,"NO DATA FOUND AT KEY %d. TRY AGAIN.......!",key);
                    outtextxy(500,450,tmp);
                    getch();
                    continue;
                }
                else
                {
                    sprintf(tmp,"DATA FOUND AT KEY %d IS : %s",key,data);
                    outtextxy(500,450,tmp);
                    sprintf(tmp,"DATA DELETED SUCESSFULLY.....!",key,data);
                    outtextxy(510,490,tmp);
                    getch();
                }
                break;
            case 4:
                return ;
           }
        }
    }
}
