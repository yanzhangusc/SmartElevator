#include"graphics.h"
#include"stdlib.h"
void startend(int se)
{
	int i;
	int color;


	cleardevice();

	setbkcolor(6);
	setwritemode(COPY_PUT);
	setlinestyle(SOLID_LINE,0,1);/////lllllϸʵ��
   
	randomize();// �������ʼ��
       
        
        
	while(bioskey(1)==0)	//���������
	{
                
		for(i=1;i<50;i++) 						//����ѭ�����ı� �ַ�����С�������Ч��
		{
                        color=random(16);
                        setcolor(color);
                        
			if(se==0)			///////�ж�����
				outtextxy(215,300,"press anykey to S T A R T !");
			else if(se==1)
				outtextxy(215,300,"pess any key to Q U I T !");

			rectangle(160,75,480,135);
                        rectangle(150,65,490,145);
setfillstyle(8,color);
floodfill(152,70,color);
//floodfill();					////�˳���ʾ��������Ϣ
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



