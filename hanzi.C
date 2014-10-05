#include<graphics.h>
#include<stdio.h>
void disys(int x,int y,int z,char code[],int color,FILE* hzkp);
void hzxysc(int x,int y,int z,char*s,int color)
{

	FILE *hzkp;						//�򿪺����ļ�
	int head=x;

	hzkp=fopen("e:\\ss\\hzk16","r");
	if (!hzkp)
	{
		printf(" file hzk16 not exist! anykey to quit.\n");
		getch();
		closegraph();
		exit(1);
	}


	while (*s!=NULL)					//ѭ�����뵥������
	{
		while (x<head+350 && *s!=NULL)		//ת�л����
		{
			disys(x,y,z,s,color,hzkp);			//������ִ����ʾ
			x+=z*20;
			s+=2;
		}
		x=head;				//ת�У����λ����ͷ
		y+=20;
	}

      //	getch();
	fclose(hzkp);

}

void disys(int x,int y,int z,char code[],int color,FILE* hzkp)
{

	int i,j,m,n;
	int head=x,pos;
	char mat[32];
	char mask[]={0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
		////1000 0000  0100 0000 0010 0000 0001 0000
		////0000 1000  0000 0100 0000 0010 0000 0001
		/*������ģÿ�и�λ������*/


	//gethz(code,mat);
	char qh,wh;
	long offset;

	qh=code[0]-160; /*�õ�����*/
	wh=code[1]-160; /*�õ�λ��*/
	offset=(94*(qh-1)+(wh-1))*32L; /*�õ�ƫ��λ��*/

	fseek(hzkp,offset,SEEK_SET); /*���ļ�ָ�뵽Ҫ��ȡ�ĺ�����ģ��*/
	fread(mat,32,1,hzkp); /*��ȡ32 �����ֵĺ�����ģ*/

	//dishz
	for (i=0;i<16;++i)
	{
		x=head;			//��ͷ
		pos=2*i;

		for(j=0;j<16;++j)
		{
			/*���γ�������ģ��һ��λ����һ������1 ����ʾ��������ʾ�õ�*/
			if ((mask[j%8]&mat[pos+j/8])!=NULL)
				for(m=0;m<z;m++)
					for(n=0;n<z;n++)
						putpixel(x+m,y+n,color);

			x+=z;
		}

		y+=z;

	}

}


char* hzstr(char* item ,int i)
{
	static char
        startend[][30]={"��ӭ����","лл����"},
        back[][30]={"���������","������˳�","���������"},
        
        title[][30]={"����˫����ϵͳ"},
        zuozhe[][40]={"����","�����һ","����","Ƥ��ǿ","���ܵ���"},
	menu[][20]={"��������","�˳�"},
	people[][20]={"������","������","��������"},

        about[][200]={
			"���ܵ���ϵͳ�����ߣ�������Ƥ��ǿ",

			"���ܵ���ϵͳģ��Ų�˫���ݵ�����������ṩ�Ż������з�����",

			"��ϵͳ���ö���ֱ�۵���ʾ���ݵ����й��̣�ʹ�û��ܹ�������˽�������״̬��",

			"ϵͳ�ṹ�������棺���������ѡ��Ŀ�꣩�˵���ṩ�����ڡ����������˵���",
"���ݿ����ѡ��򿪣��رյ��ݣ������ѡ�������߳����ݵ�������",
                        
			"����¥���ѡ���ʾ�Ӹ�¥����룻",

			"¥����ѡ�񵽴�Ŀ��¥�㡣",

			"�������̣�ѡ�����¥�㣬ѡ�������������ѡ�񿪣��ص��������ڷ��������ѡ��Ŀ��¥�㣬���У�ѭ����"

		};

	
 
        if(!strcmp(item,"menu"))	
		return (menu[i]);
	else if(!strcmp(item,"people"))
	        return(people[i]);
        else if(!strcmp(item,"title"))	
		return (title[i]);
        else if(!strcmp(item,"back"))		//���أ�0Ϊ���룬1Ϊ�˳���3Ϊ����
		return (back[i]);
        else if(!strcmp(item,"startend"))		//���ؿ�ʼ������0Ϊ��ʼ��1Ϊ����
		return (startend[i]);

        else if(!strcmp(item,"zuozhe"))
	        return(zuozhe[i]);
        else if(!strcmp(item,"about"))
	        return(about[i]);
	else								//�����������0
	{
		printf("can not find string!\n");
		return 0;
	}

}
void hanzi()
{
        char*s1;
        s1=hzstr("zuozhe",4);
	hzxysc(224,9,2,s1,13);
	s1=hzstr("menu",0);
	hzxysc(158,335,1,s1,13);
	s1=hzstr("menu",1);
	hzxysc(398,335,1,s1,13);
	s1=hzstr("people",0);
	hzxysc(100,160,1,s1,13);
	hzxysc(445,160,1,s1,13);
	s1=hzstr("people",1);
	hzxysc(100,219,1,s1,13);
	hzxysc(445,219,1,s1,13);
        s1=hzstr("people",2);
        hzxysc(100,133,1,s1,13);
        hzxysc(445,133,1,s1,13);
	s1=hzstr("zuozhe",0);
	hzxysc(551,73,2,s1,13);
	s1=hzstr("zuozhe",1);
	hzxysc(551,109,1,s1,13);
	s1=hzstr("zuozhe",2);
	hzxysc(551,146,1,s1,13);
	s1=hzstr("zuozhe",3);
	hzxysc(551,183,1,s1,13);
}