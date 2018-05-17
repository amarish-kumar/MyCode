#include <iostream>
#include <graphics.h>
#include <dos.h>

using namespace std;

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd,&gm,"c:/tc/bgi");

    int i;

    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
    outtextxy(100,100,"Press any key to display the moving car...");
    getch();

    for(i = 0; i < 420; i = i + 1)
    {
        cleardevice();
        rectangle(50+i,275,150+i,400);
        rectangle(150+i,350,200+i,400);
        circle(75+i,410,10);
        circle(175+i,410,10);
        delay(10);
    }

    getch();
    closegraph();
    restorecrtmode();
    return 0;
}
