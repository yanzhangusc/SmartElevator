#include<graphics.h>
#include<stdio.h>
void disys(int x,int y,int z,char code[],int color,FILE* hzkp);
void hzxysc(int x,int y,int z,char*s,int color)
{

	FILE *hzkp;						//打开汉字文件
	int head=x;

	hzkp=fopen("e:\\ss\\hzk16","r");
	if (!hzkp)
	{
		printf(" file hzk16 not exist! anykey to quit.\n");
		getch();
		closegraph();
		exit(1);
	}


	while (*s!=NULL)					//循环传入单个汉字
	{
		while (x<head+350 && *s!=NULL)		//转行或结束
		{
			disys(x,y,z,s,color,hzkp);			//逐个汉字打点显示
			x+=z*20;
			s+=2;
		}
		x=head;				//转行，输出位置置头
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
		/*屏蔽字模每行各位的数组*/


	//gethz(code,mat);
	char qh,wh;
	long offset;

	qh=code[0]-160; /*得到区号*/
	wh=code[1]-160; /*得到位号*/
	offset=(94*(qh-1)+(wh-1))*32L; /*得到偏移位置*/

	fseek(hzkp,offset,SEEK_SET); /*移文件指针到要读取的汉字字模处*/
	fread(mat,32,1,hzkp); /*读取32 个汉字的汉字字模*/

	//dishz
	for (i=0;i<16;++i)
	{
		x=head;			//置头
		pos=2*i;

		for(j=0;j<16;++j)
		{
			/*屏蔽出汉字字模的一个位，即一个点是1 则显示，否则不显示该点*/
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
        startend[][30]={"欢迎光临","谢谢光临"},
        back[][30]={"任意键进入","任意键退出","任意键返回"},
        
        title[][30]={"智能双电梯系统"},
        zuozhe[][40]={"控制","零九零一","张琰","皮仕强","智能电梯"},
	menu[][20]={"帮助关于","退出"},
	people[][20]={"进人数","出人数","现有人数"},

        about[][200]={
			"智能电梯系统，作者：张琰，皮仕强",

			"智能电梯系统模拟九层双电梯的运行情况，提供优化的运行方案。",

			"本系统运用动画直观地显示电梯的运行过程，使用户能够清楚的了解其运行状态。",

			"系统结构：主界面：（采用鼠标选定目标）菜单项，提供“关于”“帮助”菜单；",
"电梯开关项，选择打开，关闭电梯；人数项，选择进入或走出电梯的人数；",
                        
			"电梯楼层项，选择表示从该楼层进入；",

			"楼层号项，选择到达目的楼层。",

			"操作流程：选择进入楼层，选择进入人数，（选择开，关电梯门属于非限制项），选择目的楼层，运行，循环。"

		};

	
 
        if(!strcmp(item,"menu"))	
		return (menu[i]);
	else if(!strcmp(item,"people"))
	        return(people[i]);
        else if(!strcmp(item,"title"))	
		return (title[i]);
        else if(!strcmp(item,"back"))		//返回，0为进入，1为退出，3为返回
		return (back[i]);
        else if(!strcmp(item,"startend"))		//返回开始结束，0为开始，1为结束
		return (startend[i]);

        else if(!strcmp(item,"zuozhe"))
	        return(zuozhe[i]);
        else if(!strcmp(item,"about"))
	        return(about[i]);
	else								//其他情况返回0
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