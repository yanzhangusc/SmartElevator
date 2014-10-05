#include"graphics.h"
void liftacty(char lr,int tofloor,int *cfloor,int *action,int *n)
{
	int x0,xt,y0;//每循环一次画一次线	
	if(tofloor!=0)
	{
		setcolor(2);
		setlinestyle(SOLID_LINE,0,1);
		if(lr=='l')		/////判断左右为左
		{
			x0=181;
			xt=239;
		}
		else if(lr=='r')		/////判断左右为右
		{
			x0=375;
			xt=433;
		}
		y0=95+(9-*cfloor)*22;		//确定出此时Y位置
			
		if(*cfloor<tofloor)			//判断为上楼
		{
			if(*n>=y0-22)			//设置停止
			{
				setwritemode(XOR_PUT);
				line(x0,*n-1,xt,*n-1);
				setwritemode(XOR_PUT);
				line(x0,22+*n,xt,22+*n);
				delay(30);
			}
			if(*n==y0-23)
			{

				(*cfloor)++;	//更新当前楼层


				y0=95+(9-*cfloor)*22;
				*n=95+(9-*cfloor)*22;
			}
			*action=1;		//电梯动作，1为向上
                        (*n)--;
		}
                        
		if(*cfloor>tofloor)	//判断为下楼
		{
			if(*n<=y0+22)			//设置停止
			{
				setwritemode(XOR_PUT);
				line(x0,*n,xt,*n);
				setwritemode(XOR_PUT);
				line(x0,23+*n,xt,23+*n);
				delay(30);
			}
			if(*n==y0+23)
			{
				(*cfloor)--;		//更新当前楼层
				y0=95+(9-*cfloor)*22;
				*n=95+(9-*cfloor)*22;
			}
			*action=2; //电梯动作，2为向下
                        (*n)++;	
		}
	}
}