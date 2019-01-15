/*This project is made up by Sahil Sharma.
    It is all about an analog and digital clock display.
    It is made using C++ Graphics.
    
*/


#include<graphics.h>
#include<time.h>
#include<stdio.h>
int main()
{
    //initializing graphics driver

    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");


    initwindow(1200,700);
    //coordinates for hour hand

    int coordsforhourX[12]={50,87,100,87,50,0,-50,-87,-100,-87,-50,0};
    int coordsforhourY[12]={ -87,-50,0,50,87,100,87,50,0,-50,-87,-100};

    //coordinates for minute hand

    int coordsforminX[60]=
    {0,18,36,53,70,85,100,114,127,138,148,156,162,167,169,170,169,167,162,156,148,138,127,114,100,85,70,53,36,18,0,-18,-36,-53,
     -70,-85,-100,-114,-127,-138,-148,-156,-162,-167,-169,-170,-169,-167,-162,-156,-148,-138,-127,-114,-100,-85,-70,-53,-36,-18
    };


    int coordsforminY[60]=
    {
        -170,-169,-167,-162,-156,-148,-138,-127,-114,-100,-85,-70,-53,-36,-18,0,18,36,53,70,85,100,114,127,138,148,156,162,167,
        169,170,169,167,162,156,148,138,127,114,100,85,70,53,36,18,0,-18,-36,-53,-70,-85,-100,-114,-127,-138,-148,-156,-162,-167,-169
    };

    while(1)
    {
    //time variables
    struct tm *currenttime;
    time_t rawtime;
    rawtime=time(NULL);
    currenttime=localtime(&rawtime);



    // making circle for analog clock
    int xmax=getmaxx()/2;
    int ymax=getmaxy()/2;
    setcolor(BLUE);
    circle(xmax,ymax,200);


    //digital clock
    int ims;
    char a[100];
    settextstyle(3,HORIZ_DIR,2);
    setcolor(BLUE);
    strftime(a,100,"%I:%M:%S",currenttime);
    outtextxy(xmax-textwidth(a)/2,50,a);

    strftime(a,100,"%a %d %b,%y",currenttime);
    outtextxy(xmax-textwidth(a)/2,100,a);




    // making clock labels
    setcolor(WHITE);
    outtextxy(xmax+95-5,ymax-165-5,"1");
    outtextxy(xmax+165-5,ymax-95-5,"2");
    outtextxy(xmax+190-7,ymax+0-7,"3");
    outtextxy(xmax+165-10,ymax+95-10,"4");
    outtextxy(xmax+95-10,ymax+165-10,"5");
    outtextxy(xmax+0-10,ymax+190-10,"6");
    outtextxy(xmax-95-10,ymax+165-15,"7");
    outtextxy(xmax-165-10,ymax+95-15,"8");
    outtextxy(xmax-190-5,ymax-0-10,"9");
    outtextxy(xmax-165-5,ymax-95-5,"10");
    outtextxy(xmax-95-5,ymax-165-5,"11");
    outtextxy(xmax+0-5,ymax-190-5,"12");





    // displaying hour hand



    strftime(a,100,"%I",currenttime);
    sscanf(a,"%d",&ims);
    setcolor(RED);
    line(xmax,ymax,xmax+coordsforhourX[ims-1],ymax+coordsforhourY[ims-1]);


    //displaying minute hand

    strftime(a,100,"%M",currenttime);
    sscanf(a,"%d",&ims);
    setcolor(YELLOW);
    line(xmax,ymax,xmax+coordsforminX[ims],ymax+coordsforminY[ims]);

    //displaying seconds hand
    strftime(a,100,"%S",currenttime);
    sscanf(a,"%d",&ims);
    setcolor(GREEN);
    line(xmax,ymax,xmax+coordsforminX[ims],ymax+coordsforminY[ims]);

    delay(1000);
    cleardevice();
    }
    outtextxy(10,10,"PRESS ANY KEY TO CLOSE");
    getch();
    closegraph();
}
