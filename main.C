#include<graphics.h>
#include<dos.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum direct {up=1,down,leftin,leftout,rightin,rightout,left,right};
void main()
{
  
  int gd=EGA,gm=EGAHI;
  initgraph(&gd,&gm,"F:\\TCPP30E\\BGI");
  
  cleardevice();
  startend(0);
  cleardevice();
setbkcolor(YELLOW);
  lpeople();
  rpeople();
	kuang();
	putscreen1();
	putscreen2();
	fenge();
	lanjian();
	ranjian();
	updn();
        hanzi();
	
	control();
   startend(0);
   getch();
   closegraph();
}