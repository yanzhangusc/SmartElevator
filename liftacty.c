#include"graphics.h"
void liftacty(char lr,int tofloor,int *cfloor,int *action,int *n)
{
	int x0,xt,y0;//ÿѭ��һ�λ�һ����	
	if(tofloor!=0)
	{
		setcolor(2);
		setlinestyle(SOLID_LINE,0,1);
		if(lr=='l')		/////�ж�����Ϊ��
		{
			x0=181;
			xt=239;
		}
		else if(lr=='r')		/////�ж�����Ϊ��
		{
			x0=375;
			xt=433;
		}
		y0=95+(9-*cfloor)*22;		//ȷ������ʱYλ��
			
		if(*cfloor<tofloor)			//�ж�Ϊ��¥
		{
			if(*n>=y0-22)			//����ֹͣ
			{
				setwritemode(XOR_PUT);
				line(x0,*n-1,xt,*n-1);
				setwritemode(XOR_PUT);
				line(x0,22+*n,xt,22+*n);
				delay(30);
			}
			if(*n==y0-23)
			{

				(*cfloor)++;	//���µ�ǰ¥��


				y0=95+(9-*cfloor)*22;
				*n=95+(9-*cfloor)*22;
			}
			*action=1;		//���ݶ�����1Ϊ����
                        (*n)--;
		}
                        
		if(*cfloor>tofloor)	//�ж�Ϊ��¥
		{
			if(*n<=y0+22)			//����ֹͣ
			{
				setwritemode(XOR_PUT);
				line(x0,*n,xt,*n);
				setwritemode(XOR_PUT);
				line(x0,23+*n,xt,23+*n);
				delay(30);
			}
			if(*n==y0+23)
			{
				(*cfloor)--;		//���µ�ǰ¥��
				y0=95+(9-*cfloor)*22;
				*n=95+(9-*cfloor)*22;
			}
			*action=2; //���ݶ�����2Ϊ����
                        (*n)++;	
		}
	}
}