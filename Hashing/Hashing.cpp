#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include <graphics.h>
#include "Liniar Probing.cpp"
#include "QuadreticProbing.cpp"
#include "Chaining.cpp"
using namespace std;
void Welcome()
{
    arccoordstype a,b,c,d,e,f;
     int n=0;
     int m;
    int i=0;
    int ii=0,iii=0;
     settextstyle(6,HORIZ_DIR,12);
     setcolor(BLUE);
     outtextxy(500,450,"WELCOME");
    while(i<300)
    {
        setcolor(BLACK);
        if(kbhit())
            break;
        for(int n=0;n<360;n++,m++)
        {
            arc(300,300,n,n,i);
            getarccoords(&a);
            putpixel(a.xstart,a.ystart,m%getmaxcolor());

            arc(800,200,n,n,i);
            getarccoords(&b);
            putpixel(b.xstart,b.ystart,m%getmaxcolor());

            arc(600,400,n,n,i);
            getarccoords(&c);
            putpixel(c.xstart,c.ystart,m%getmaxcolor());

            arc(50,900,n,n,i);
            getarccoords(&c);
            putpixel(c.xstart,c.ystart,m%getmaxcolor());
        }
        i+=6;
    }
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
    while(!kbhit())
    {
        setcolor(BLACK);
        for(int n=0;n<360;n++,m++)
        {
            /*arc(300,300,n,n,i);
            getarccoords(&a);
            putpixel(a.xstart,a.ystart,m%getmaxcolor());

            arc(800,200,n,n,i);
            getarccoords(&b);
            putpixel(b.xstart,b.ystart,m%getmaxcolor());

            arc(600,400,n,n,i);
            getarccoords(&c);
            putpixel(c.xstart,c.ystart,m%getmaxcolor());

            arc(50,900,n,n,i);
            getarccoords(&c);
            putpixel(c.xstart,c.ystart,m%getmaxcolor());*/
            setcolor(RED);
            arc(1500-ii,470-ii*2,n,n,ii*2);
            getarccoords(&d);
            putpixel(d.xstart,d.ystart,n%getmaxcolor());
            setcolor(BLACK);

            arc(1200,-250,-24+n%90+iii,0,1200);
            getarccoords(&d);
            setcolor(n%getmaxcolor());
            circle(d.xstart,d.ystart,50);
            setcolor(BLACK);

            arc(720,-250,360+n%90-iii,0,1200);
            getarccoords(&d);
            setcolor(n%getmaxcolor());
            circle(d.xstart,d.ystart,50);
            setcolor(BLACK);
        }
        for(int n=270-iii;n<360-iii;n++)
        {
            arc(720,-250,360+n%90-iii,0,1200);
            getarccoords(&d);
            circle(d.xstart,d.ystart,50);
            arc(1200,-250,-24+n%90+iii,0,1200);
            getarccoords(&d);
            circle(d.xstart,d.ystart,50);
        }
        iii+=2;
        if(iii>270)
            iii=0;
        ii+=2;
       // i+=8;
      /*  if(i>500)
        {
            setcolor(BLACK);
            setfillstyle(1,BLACK);
            fillellipse(300,300,500,520);
            fillellipse(800,200,500,520);
            fillellipse(600,400,500,520);
            i=0;
        }*/
    }
}
int main()
{
     initwindow(6000,6000);
     PlaySound(TEXT("start.wav"),NULL,SND_ASYNC);
     Welcome();
     getch();
     fflush(stdin);
     int choice=1,m;
     char ch;
     do
     {
        cleardevice();
        setcolor(RED);
        rectangle(320,90,1550,190);
        rectangle(325,95,1545,185);
        settextstyle(6,0,4);
        setcolor(BLUE);
        outtextxy(350,120,"                   HASHING IN DATA STRUCTURE");
        do
        {
                setcolor(BLACK);
                setfillstyle(1,0);
                bar(400,250,1500,500);
                setcolor(GREEN);
                setcolor(8);
                fillellipse(920,500,600,250);
                ellipse(920,500,0,360,605,255);
                line(918,210,918,800);
                line(922,210,922,800);
                line(200,498,1800,498);
                line(200,502,1800,502);
                if(choice==1)
                {
                    setcolor(10);
                    settextstyle(6,0,5);
                    m=40;
                    setfillstyle(1,8);
                    floodfill(700,400,8);
                }
                else
                {
                     setcolor(2);
                     settextstyle(6,0,3);
                     m=0;
                }

                outtextxy(680-m,380,"LINIAR");
                if(choice==2)
                {
                    setcolor(10);
                    settextstyle(6,0,5);
                    m=20;
                    setfillstyle(1,8);
                    floodfill(1000,400,8);
                }
                else
                {
                     setcolor(2);
                     settextstyle(6,0,3);
                     m=0;
                }
                outtextxy(1000-m,380,"QUADRETIC");
                if(choice==3)
                {
                    setcolor(10);
                    settextstyle(6,0,5);
                    m=70;
                    setfillstyle(1,8);
                    floodfill(700,700,8);
                }
                else
                {
                     setcolor(2);
                     settextstyle(6,0,3);
                     m=0;
                }
                outtextxy(650-m,600,"CHAINING");
                if(choice==4)
                {
                    setcolor(10);
                    settextstyle(6,0,5);
                    m=15;
                    setfillstyle(1,8);
                    floodfill(1000,700,8);
                }
                else
                {
                     setcolor(2);
                     settextstyle(6,0,3);
                     m=0;
                }
                outtextxy(1000-m,600,"DOUBLE");
                if(choice==5)
                {
                    settextstyle(6,0,4);
                    m=15;
                    setcolor(GREEN);
                    rectangle(850,840,1000,890);
                    setcolor(10);
                }
                else
                {
                     setcolor(BLACK);
                     setfillstyle(1,0);
                     bar(850,840,1010,900);
                     setcolor(2);
                     settextstyle(6,0,3);
                     m=0;
                }
                outtextxy(885-m,850,"EXIT");
                setcolor(6);
                ellipse(920,500,0,360,600,250);
                ellipse(920,500,0,360,605,255);
                setcolor(3);
                line(918,210,918,800);
                line(922,210,922,800);
                line(200,498,1800,498);
                line(200,502,1800,502);
                ch=getch();
                PlaySound(TEXT("Button1.wav"),NULL,SND_ASYNC);
                if((int)ch==72 && choice>2)
                    choice-=2;
                if((int)ch==80 && choice <5)
                {
                    choice+=2;
                    if(choice>5)
                        choice=5;
                }
                if((int)ch==75)
                {
                    if((choice==2 || choice==4))
                     choice--;
                     else
                        if(choice==5)
                        choice-=2;
                }

                if((int)ch==77)
                {
                    if((choice==1 || choice==3))
                        choice++;
                    else
                        if(choice==5)
                        choice--;
                }

        }while((int)ch!=13);

        switch(choice)
        {
            case 1:
                 Liniar::Liniar();
                break;
            case 2:
                Quadretic::Quadretic();
                break;
            case 3:
                Chaining::Chaining();
                break;
            case 4:

                break;
            case 5:
                closegraph();
        }
    }while(choice!=5);
    PlaySound(TEXT("end.wav"),NULL,SND_SYNC);

}
