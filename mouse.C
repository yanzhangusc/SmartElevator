#include<graphics.h>
#include<dos.h>
void cursor(int x,int y)					//�����ʽ������������ͷ
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



void read(int*mx,int*my,int*mbutt)    /*   ������λ�úͰ�ť״̬����*/
{
	union REGS regs;

	int x0=*mx,y0=*my;			//����λ��
	int xnew,ynew;

	regs.x.ax=7;               //ax=7,����ˮƽ���λ�á�CX��С��DX������ꡣ
	regs.x.cx=0;
	regs.x.dx=639;
	int86(51,&regs,&regs);
	regs.x.ax=8;              //���ô�ֱ���λ�ã�CX��С��DX�������
	regs.x.cx=0;
	regs.x.dx=479;
	int86(51,&regs,&regs);


	do
	{
		regs.x.ax=3;					//3�Ź��ܣ���ȡ���λ��
		int86(51,&regs,&regs);
		xnew=regs.x.cx;
		ynew=regs.x.dx;
		*mbutt=regs.x.bx;

	}while(xnew==x0 &&ynew==y0&&*mbutt==0);


	*mx=xnew;					//���ؼ�¼����λ��
	*my=ynew;

}

void mouse(int *mx,int *my,int *mbutt)   
					/*   �Ƿ��а�ť���£������£�����λ�û�ʮ��  */
{
	int x0=*mx,y0=*my;
	int xnow,ynow;

	read(&xnow,&ynow,mbutt);		//��ȡ�����λ��
	cursor(x0,y0);						//���ǣ��ٻ���
	cursor(xnow,ynow);

	*mx=xnow;
	*my=ynow;
}
