#include"graphics.h"
#include"stdlib.h"
void startend(int se)
{
	int i;
	int color;


	cleardevice();

	setbkcolor(6);
	setwritemode(COPY_PUT);
	setlinestyle(SOLID_LINE,0,1);/////lllll细实线
   
	randomize();// 随机数初始化
       
        
        
	while(bioskey(1)==0)	//任意键结束
	{
                
		for(i=1;i<50;i++) 						//两个循环，改变 字符串由小变大，闪动效果
		{
                        color=random(16);
                        setcolor(color);
                        
			if(se==0)			///////判断左右
				outtextxy(215,300,"press anykey to S T A R T !");
			else if(se==1)
				outtextxy(215,300,"pess any key to Q U I T !");

			rectangle(160,75,480,135);
                        rectangle(150,65,490,145);
setfillstyle(8,color);
floodfill(152,70,color);
//floodfill();					////退出提示，作者信息
			 hzxysc(160+i*10,210,1,hzstr("zuozhe",2),14);
	                hzxysc(450-i*10,210,1,hzstr("zuozhe",3),14);
                        delay(40);
			hzxysc(230,260,2,hzstr("back",se),11);
                        hzxysc(180,90,2,hzstr("title",0),11);
			setfillstyle(1,6);
                        bar(159+i*10,209,209+i*10,229);
                        bar(449-i*10,209,519-i*10,229);
                        

			delay(50);

		}

		
	}
	
}



