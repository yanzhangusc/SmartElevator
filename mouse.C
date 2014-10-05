#include<graphics.h>
#include<dos.h>
void cursor(int x,int y)					//异或形式画线做出鼠标箭头
{

	setwritemode(XOR_PUT);
	setlinestyle(SOLID_LINE,0,1);
	setcolor(1);
	line(x,y,x,y+18);
	line(x,y,x+12,y+12);
	line(x,y+18,x+4,y+14);
	line(x+4,y+14,x+6,y+20);
	line(x+6,y+20,x+10,y+18);
	line(x+10,y+18,x+8,y+12);
	line(x+8,y+12,x+12,y+12);
}



void read(int*mx,int*my,int*mbutt)    /*   读鼠标的位置和按钮状态函数*/
{
	union REGS regs;

	int x0=*mx,y0=*my;			//留旧位置
	int xnew,ynew;

	regs.x.ax=7;               //ax=7,设置水平最大位置。CX最小，DX最大坐标。
	regs.x.cx=0;
	regs.x.dx=639;
	int86(51,&regs,&regs);
	regs.x.ax=8;              //设置垂直最大位置，CX最小，DX最大坐标
	regs.x.cx=0;
	regs.x.dx=479;
	int86(51,&regs,&regs);


	do
	{
		regs.x.ax=3;					//3号功能，读取鼠标位置
		int86(51,&regs,&regs);
		xnew=regs.x.cx;
		ynew=regs.x.dx;
		*mbutt=regs.x.bx;

	}while(xnew==x0 &&ynew==y0&&*mbutt==0);


	*mx=xnew;					//返回记录的新位置
	*my=ynew;

}

void mouse(int *mx,int *my,int *mbutt)   
					/*   是否有按钮按下，若按下，在新位置画十字  */
{
	int x0=*mx,y0=*my;
	int xnow,ynow;

	read(&xnow,&ynow,mbutt);		//读取鼠标新位置
	cursor(x0,y0);						//覆盖，再画出
	cursor(xnow,ynow);

	*mx=xnow;
	*my=ynow;
}

