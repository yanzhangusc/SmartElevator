#include"graphics.h"
void lrcfloor(int*llc,int*rlc)
{
        char *ls,*rs;
        setcolor(0);
        setfillstyle(1,6);
	circle(210,80,9);
	floodfill(210,80,0);
        circle(404,80,9);
	floodfill(404,80,0);
        delay(10); 
        setcolor(YELLOW);       
        sprintf(ls,"%d",*llc);
        sprintf(rs,"%d",*rlc);
        outtextxy(208,79,ls);
        outtextxy(402,79,rs);
}




void  alarm(char lr)
{
	int i;
	int x0,y0;
	char str[20]="超载";
	
	setfillstyle(1,YELLOW);
	if(lr=='l')
		x0=96;
	else if(lr=='r')
		x0=441;
	y0=281;
	
	for(i=0;i<5;i++)	/////报警五次
	{
	
		//////////			输出“超载”提醒语句
		bar(x0,y0,x0+80,y0+35);
		hzxysc(x0+5,y0+4,2,str,1);
		delay(200);
		bar(x0,y0,x0+80,y0+35);
	}
		
}


void menus(char *item)
{

	int i,y0;
	int x,y,butt;

	cleardevice();

	setcolor(1);
	
	if(!strcmp(item,"about"))			//判断为“关于”项
	{
                setfillstyle(1,12);
		bar(18,10,97,35);					//标题栏
		hzxysc(20,15,1,hzstr("menu",0),RED);

		for(i=0,y0=0;i<7;i++,y0+=50)			//循环输出各项
		{
			hzxysc(80,50+y0,1,hzstr("about",i),RED);
			
		}

	}

	

			//任意键返回

	 while(1)
	 {
		mouse(&x,&y,&butt);
		if(butt)
			break;
	 }



}