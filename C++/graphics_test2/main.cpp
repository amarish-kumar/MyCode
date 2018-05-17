#include <iostream>
#include <graphics.h>
#include <stdio.h>

using namespace std;

int main()
{
    int n;
    cout<<"\nThis is a Countdown Program";
    cout<<"\n----------------------------";
    cout<<"\n\nCountdown from: ";
    cin>>n;

    int gd = DETECT, gm;
    initgraph(&gd,&gm,"c:/tc/bgi");
    char a[100];

    settextjustify(CENTER_TEXT,CENTER_TEXT);
    settextstyle(GOTHIC_FONT,HORIZ_DIR,6);

    for(int i = n; i >= 0; i--)
    {
        cleardevice();
        sprintf(a, "%d", i);
        outtextxy(getmaxx()/2,getmaxy()/2,a);
        delay(1000);
    }

    closegraph();
    restorecrtmode();
    return 0;
}

