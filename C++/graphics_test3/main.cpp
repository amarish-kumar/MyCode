#include <iostream>
#include <graphics.h>
#include <time.h>
#include <stdio.h>

using namespace std;

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd,&gm,"c:/tc/bgi");

    int i = 0;
    int midx = getmaxx()/2;
    int midy = getmaxy()/2;
    char str[100];
    int hr, min, sec;

    while(i == 0)
    {
        time_t t = time(NULL);
        tm *data = localtime(&t);

        hr = data->tm_hour % 12;
        min = data->tm_min % 60;
        sec = data->tm_sec % 60;

        if(sec < 10 && min < 10)
            sprintf(str,"%d : 0%d : 0%d",hr,min,sec);
        else if(min < 10)
            sprintf(str,"%d : 0%d : %d",hr,min,sec);
        else if(sec < 10)
            sprintf(str,"%d : %d : 0%d",hr,min,sec);
        else
            sprintf(str,"%d : %d : %d",hr,min,sec);

        settextjustify(CENTER_TEXT,CENTER_TEXT);
        settextstyle(GOTHIC_FONT,HORIZ_DIR,4);
        cleardevice();
        outtextxy(midx,midy,str);
        delay(100);
    }




    getch();
    closegraph();
    restorecrtmode();
    return 0;
}
