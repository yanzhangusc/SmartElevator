#define dt_xa1 180
#define dt_ya1 95
#define dt_xb1 240
#define dt_yb1 117
#define dt_xa2 374
#define dt_ya2 95
#define dt_xb2 434
#define dt_yb2 117
#include<graphics.h>
void kuang()
{
	setcolor(8);
	setfillstyle(4,8);
	rectangle(72,36,309,51);
	floodfill(73,37,8);
	setfillstyle(5,8);
	rectangle(309,36,546,51);
	floodfill(310,37,8);
	setfillstyle(5,8);
	rectangle(72,51,92,346);
	floodfill(73,52,8);
	setfillstyle(4,8);
	rectangle(526,51,546,346);
	floodfill(527,52,8);
	setcolor(11);
	setfillstyle(1,11);
	rectangle(92,331,526,346);
	floodfill(93,332,11);
	setcolor(1);
	setfillstyle(1,1);
	rectangle(150,331,240,346);
	floodfill(151,332,1);
	rectangle(390,331,450,346);
	floodfill(391,332,1);
	
}
void putscreen1()
{
	int i,xa=dt_xa1,ya=dt_ya1,xb=dt_xb1,yb=dt_yb1,xab,xabc;
	char *s;
        char *ls="1";
	setcolor(1);
	circle(210,80,9);
	setfillstyle(1,6);
	floodfill(210,80,1);
	for(i=1;i<=9;i++)
	{
	   setcolor(2);
	   setfillstyle(1,0);
	   rectangle(xa-1,ya,xb+1,yb);
	   floodfill(xa+2,ya+2,2);
           rectangle(xa+66,ya+6,xb+26,yb-1);
           setfillstyle(1,10);
           floodfill(xa+67,ya+7,2);
	   setcolor(4);
	   sprintf(s,"%df",10-i);
	   outtextxy(xa+70,ya+11,s);
	   ya+=22;
	   yb+=22;
	}
        setcolor(5);
        setfillstyle(1,2);
        rectangle(181,270,239,292);
        floodfill(182,271,5);
        setcolor(YELLOW);
        outtextxy(208,80,ls);
        
        
}
void putscreen2()
{
	int i,xa=dt_xa2,ya=dt_ya2,xb=dt_xb2,yb=dt_yb2;
	char *s;
        char *rs="1";
	setcolor(1);
	circle(404,80,9);
	setfillstyle(1,6);
	floodfill(404,80,1);
	for(i=1;i<=9;i++)
	{
	   setcolor(2);
	   setfillstyle(1,0);
	   rectangle(xa-1,ya,xb+1,yb);
	   floodfill(xa+1,ya+1,2);
           rectangle(xa-24,ya+6,xb-64,yb-1);
           setfillstyle(1,10);
           floodfill(xa-23,ya+7,2);
	   setcolor(4);
	   sprintf(s,"%df",10-i);
	   outtextxy(xa-20,ya+11,s);
	   ya+=22;
	   yb+=22;
	}
        setcolor(5);
        setfillstyle(1,2);
        rectangle(375,270,433,292);
        floodfill(376,271,5);
        setcolor(YELLOW);
        outtextxy(402,80,rs);
        setwritemode(XOR_PUT);
        setcolor(14);
        for(i=0;i<15;i++)
	{
		line(246,276+i,266,276+i);
                line(350,276+i,370,276+i);
	}
        setwritemode(COPY_PUT);

}
void fenge()
{
	int a=95,i;
	while(a<=295)
	{
	for(i=0;i<3;i++)
	{
		setcolor(9);
		line(180,a+i,240,a+i);
		line(374,a+i,434,a+i);
	}
	a=a+22;
	}
}
void lanjian()
{
	int i=1,x,y;
	char *floor;
	setcolor(4);
        setfillstyle(1,10);
	rectangle(112,88,172,133);
        floodfill(113,89,4);
	line(112,103,172,103);
	line(112,118,172,118);
	line(132,88,132,133);
	line(152,88,152,133);
	for(y=95;y<=125;y+=15)
	for(x=115;x<=155;x+=20,i++)
	{
		sprintf(floor,"%df",i);
		outtextxy(x,y,floor);
	}
}
void ranjian()
{
	int i=1,x,y;
	char *floor;
	setcolor(4);
        setfillstyle(1,10);
	rectangle(446,88,506,133);
        floodfill(447,89,4);
	line(446,103,506,103);
	line(446,118,506,118);
	line(466,88,466,133);
	line(486,88,486,133);
	for(y=95;y<=125;y+=15)
	for(x=449;x<=489;x+=20,i++)
	{
		sprintf(floor,"%df",i);
		outtextxy(x,y,floor);
	}
}
void updn()
{
	int i,xa=297,xb=327,ya=124,yb=109;
        setcolor(4);
	for(i=0;i<8;i++,ya+=22)
	{
		setfillstyle(1,6);
		pieslice(xa,ya,240,300,12);
	}
	for(i=0;i<8;i++,yb+=22)
	{
		setfillstyle(1,6);
		pieslice(xb,yb,60,120,12);
	}
}
void newkeyout(int *x,int *y,int ltotalpeople,int rtotalpeople,int *butt,int *liftout,enum direct *direction,int lan[],int ran[])//左按键
{
        int n,i;
        setwritemode(XOR_PUT);
        setcolor(11);
  
     if((*butt)&&(*y>=88&&*y<=133)&&((*x>=112&&*x<=172)||(*x>=446&&*x<=506)))
     {
                if(*y>=88&&*y<=103||*y>=446&&*y<=461 ) n=1;
                if(*y>=103&&*y<=118||*y>=461&&*y<=476)   n=4;
                if(*y>=118&&*y<=133||*y>=476&&*y<=491)   n=7;
               
               if(*x>=112&&*x<=172)
               *direction=7;
               else if(*x>=446&&*x<=506)
               *direction=8;
               if(*direction==7) 
               {
                *liftout=(*x-112)/20+n;
               lan[*liftout-1]=*liftout;
               if(ltotalpeople!=0)
               for(i=0;i<15;i++)
            {
              line(112+(*liftout-n)*20,88+(n-1)*5+i,112+(*liftout-n)*20+20,88+(n-1)*5+i);
            }
               } 
               if(*direction==8) 
               {
                *liftout=(*x-446)/20+n;
               ran[*liftout-1]=*liftout;                
               if(rtotalpeople!=0)   
               for(i=0;i<15;i++)
            {
              line(446+(*liftout-n)*20,88+(n-1)*5+i,446+(*liftout-n)*20+20,88+(n-1)*5+i);
            }
                 }
               delay(100);
     }   

      
}

void newkeyin(int *x,int *y,int *butt,int *liftin,enum direct *direction,int*lup,int*rdn,int *lcfloor,int*rcfloor)
{
        int xa=297,ya=124,xb=327,yb=110;
        setcolor(4);
        setfillstyle(1,4);
    /* if(((*x>=290&&*x<=310)||(*x>=314&&*x<=334))&&*y>=102&&*y<=293&&*butt==1)
       {
            *liftin=9-(*y-90)/15;
            if(*x>=290&&*x<=310&&*butt==1)
               {
                *direction=1;*lup=1;
                pieslice(xa,ya+(8-*liftin)*22,240,300,12);               
               }
            else if(*x>=314&&*x<=334&&*butt==1)
               {
                *direction=2;*rdn=2;
                 pieslice(xb,yb+(9-*liftin)*22,60,120,12);
                }
         
        }*/
       if(*x>=290&&*x<=310&&*y>=124&&*y<=139&&*butt==1)
	{
         *liftin=8;
         *lup=1;
         *direction=1;
if(*liftin!=*lcfloor)         
pieslice(xa,ya+(8-*liftin)*22,240,300,12);
        }
	else if(*x>=290&&*x<=310&&*y>=146&&*y<=161&&*butt==1)
	{
         *liftin=7;
         *lup=1;
         *direction=1;
if(*liftin!=*lcfloor) 
         pieslice(xa,ya+(8-*liftin)*22,240,300,12);
        }
	else if(*x>=290&&*x<=310&&*y>=168&&*y<=183&&*butt==1)
	{
         *liftin=6;
         *lup=1;
         *direction=1;if(*liftin!=*lcfloor) 
         pieslice(xa,ya+(8-*liftin)*22,240,300,12);
        }
	else if(*x>=290&&*x<=310&&*y>=190&&*y<=205&&*butt==1)
	{
         *liftin=5;
         *lup=1;
         *direction=1;if(*liftin!=*lcfloor) 
         pieslice(xa,ya+(8-*liftin)*22,240,300,12);
        }
	else if(*x>=290&&*x<=310&&*y>=212&&*y<=227&&*butt==1)
	{
         *liftin=4;
         *lup=1;
         *direction=1;if(*liftin!=*lcfloor) 
         pieslice(xa,ya+(8-*liftin)*22,240,300,12);
        }
	else if(*x>=290&&*x<=310&&*y>=234&&*y<=249&&*butt==1)
        {
         *liftin=3;
         *lup=1;
         *direction=1;if(*liftin!=*lcfloor) 
         pieslice(xa,ya+(8-*liftin)*22,240,300,12);
        }
	else if(*x>=290&&*x<=310&&*y>=256&&*y<=271&&*butt==1)
	{
         *liftin=2;
         *lup=1;
         *direction=1;if(*liftin!=*lcfloor) 
         pieslice(xa,ya+(8-*liftin)*22,240,300,12);
        }
	else if(*x>=290&&*x<=310&&*y>=278&&*y<=293&&*butt==1)
	{
         *liftin=1;
         *lup=1;
         *direction=1;if(*liftin!=*lcfloor) 
         pieslice(xa,ya+(8-*liftin)*22,240,300,12);
        }
        //中间下按键
        else if(*x>=314&&*x<=334&&*y>=102&&*y<=117&&*butt==1)
	{
         *liftin=9;
         *rdn=2;
         *direction=2;if(*liftin!=*rcfloor) 
         pieslice(xb,yb+(9-*liftin)*22,60,120,12);
        }
	else if(*x>=314&&*x<=334&&*y>=124&&*y<=139&&*butt==1)
	{
         *liftin=8;
         *rdn=2;
         *direction=2;if(*liftin!=*rcfloor) 
         pieslice(xb,yb+(9-*liftin)*22,60,120,12);
        }
	else if(*x>=314&&*x<=334&&*y>=146&&*y<=161&&*butt==1)
	{
         *liftin=7;
         *rdn=2;
         *direction=2;if(*liftin!=*rcfloor) 
         pieslice(xb,yb+(9-*liftin)*22,60,120,12);
        }
	else if(*x>=314&&*x<=334&&*y>=168&&*y<=183&&*butt==1)
	{
         *liftin=6;
         *rdn=2;
         *direction=2;if(*liftin!=*rcfloor) 
         pieslice(xb,yb+(9-*liftin)*22,60,120,12);
        }
	else if(*x>=314&&*x<=334&&*y>=190&&*y<=205&&*butt==1)
	{
         *liftin=5;
         *rdn=2;
         *direction=2;if(*liftin!=*rcfloor) 
         pieslice(xb,yb+(9-*liftin)*22,60,120,12);
        }
	else if(*x>=314&&*x<=334&&*y>=212&&*y<=227&&*butt==1)
        {
         *liftin=4;
         *rdn=2;
         *direction=2;if(*liftin!=*rcfloor) 
         pieslice(xb,yb+(9-*liftin)*22,60,120,12);
        }
	else if(*x>=314&&*x<=334&&*y>=234&&*y<=249&&*butt==1)
	{
         *liftin=3;
         *rdn=2;
         *direction=2;if(*liftin!=*rcfloor) 
         pieslice(xb,yb+(9-*liftin)*22,60,120,12);
        }
	else if(*x>=314&&*x<=334&&*y>=256&&*y<=271&&*butt==1)
	{
         *liftin=2;
         *rdn=2;
         *direction=2;if(*liftin!=*rcfloor) 
         pieslice(xb,yb+(9-*liftin)*22,60,120,12);
	}
        
	
}
void lpeokey(int *x,int *y,int *butt,int *people)
{
       int i;
       setcolor(11);
       setwritemode(XOR_PUT);
        if(*x>=96&&*x<=112&&*y>=183&&*y<=195&&*butt==1)
      {
        *people=1;
        for(i=0;i<=12;i++)
        {
           line(96,182+i,112,182+i);
        }
        delay(100);
        for(i=0;i<=12;i++)
        {
           line(96,182+i,112,182+i);  
        }
      }
        if(*x>=113&&*x<=128&&*y>=183&&*y<=195&&*butt==1)
      { 
        *people=2;
        for(i=0;i<=12;i++)
        {
           line(112,182+i,128,182+i);
        }
        delay(100);
        for(i=0;i<=12;i++)
        {
           line(112,182+i,128,182+i);  
        }          
      }
        if(*x>=129&&*x<=144&&*y>=183&&*y<=195&&*butt==1)
      {          *people=3;
        for(i=0;i<=12;i++)
        {
           line(128,182+i,144,182+i);
        }
        delay(100);
        for(i=0;i<=12;i++)
        {
           line(128,182+i,144,182+i);  
        }         
      }
        if(*x>=145&&*x<=160&&*y>=183&&*y<=195&&*butt==1)
      {          *people=4;
        for(i=0;i<=12;i++)
        {
           line(144,182+i,160,182+i);
        }
           delay(100);
        for(i=0;i<=12;i++)
        {
           line(144,182+i,160,182+i);  
        }          
      }
        if(*x>=161&&*x<=176&&*y>=183&&*y<=195&&*butt==1)
      {          *people=5;
         for(i=0;i<=12;i++)
        {
           line(160,182+i,176,182+i);
        }
           delay(100);
        for(i=0;i<=12;i++)
        {
           line(160,182+i,176,182+i);  
        }         
      }
        
        if(*x>=96&&*x<=112&&*y>=197&&*y<=209&&*butt==1)
      {
          *people=6;
         for(i=0;i<=12;i++)
        {
           line(96,197+i,112,197+i);
        }
           delay(100);
        for(i=0;i<=12;i++)
        {
           line(96,197+i,112,197+i);  
        }         
          
      }
        if(*x>=113&&*x<=128&&*y>=197&&*y<=209&&*butt==1)
      {          
        *people=7;
        for(i=0;i<=12;i++)
        {
           line(112,197+i,128,197+i);
        }
           delay(100);
        for(i=0;i<=12;i++)
        {
           line(112,197+i,128,197+i);  
        }     
      }
        if(*x>=129&&*x<=144&&*y>=197&&*y<=209&&*butt==1)
      {          
       *people=8;
       for(i=0;i<=12;i++)
        {
           line(128,197+i,144,197+i);
        }
           delay(100);
        for(i=0;i<=12;i++)
        {
           line(128,197+i,144,197+i);  
        }   
      }
        if(*x>=145&&*x<=160&&*y>=197&&*y<=209&&*butt==1)
      {          
        *people=9;
        for(i=0;i<=12;i++)
        {
           line(144,197+i,160,197+i);
        }
           delay(100);
        for(i=0;i<=12;i++)
        {
           line(144,197+i,160,197+i);  
        }     
      }
        if(*x>=161&&*x<=176&&*y>=197&&*y<=209&&*butt==1)
      {          
       *people=10;
       for(i=0;i<=12;i++)
        {
           line(160,197+i,176,197+i);
        }
           delay(100);
        for(i=0;i<=12;i++)
        {
           line(160,197+i,176,197+i);  
        }   
      }
        if(*x>=96&&*x<=112&&*y>=241&&*y<=253&&*butt==1)                        //out
      { 
        *people=-1;

        for(i=0;i<=12;i++)
        {
           line(96,241+i,112,241+i);
        }
           delay(100);
        for(i=0;i<=12;i++)
        {
           line(96,241+i,112,241+i);  
        }
      }
        if(*x>=113&&*x<=128&&*y>=241&&*y<=253&&*butt==1)
      {          *people=-2;
        for(i=0;i<=12;i++)
        {
           line(112,241+i,128,241+i);
        }
           delay(100);
        for(i=0;i<=12;i++)
        {
           line(112,241+i,128,241+i);  
        }
      }
        if(*x>=129&&*x<=144&&*y>=241&&*y<=253&&*butt==1)
      {          *people=-3;
        for(i=0;i<=12;i++)
        {
           line(128,241+i,144,241+i);
        }
           delay(100);
        for(i=0;i<=12;i++)
        {
           line(128,241+i,144,241+i);  
        }
      }
        if(*x>=145&&*x<=160&&*y>=241&&*y<=253&&*butt==1)
      {          *people=-4;
         for(i=0;i<=12;i++)
        {
           line(144,241+i,160,241+i);
        }
           delay(100);
        for(i=0;i<=12;i++)
        {
           line(144,241+i,160,241+i);  
        }
      }
        if(*x>=161&&*x<=176&&*y>=241&&*y<=253&&*butt==1)
      {          *people=-5;
         for(i=0;i<=12;i++)
        {
           line(160,241+i,176,241+i);
        }
           delay(100);
        for(i=0;i<=12;i++)
        {
           line(160,241+i,176,241+i);  
        }
      }
        
        if(*x>=96&&*x<=112&&*y>=255&&*y<=267&&*butt==1)
      {
          *people=-6;
          for(i=0;i<=12;i++)
        {
           line(96,256+i,112,256+i);
        }
           delay(100);
        for(i=0;i<=12;i++)
        {
           line(96,256+i,112,256+i);  
        }
      }
        if(*x>=113&&*x<=128&&*y>=255&&*y<=267&&*butt==1)
      {          *people=-7;
          for(i=0;i<=12;i++)
        {
           line(112,256+i,128,256+i);
        }
           delay(100);
        for(i=0;i<=12;i++)
        {
           line(112,256+i,128,256+i);  
        }
      }
        if(*x>=129&&*x<=144&&*y>=255&&*y<=267&&*butt==1)
      {          *people=-8;
         for(i=0;i<=12;i++)
        {
           line(128,256+i,144,256+i);
        }
           delay(100);
        for(i=0;i<=12;i++)
        {
           line(128,256+i,144,256+i);  
        }
      }
        if(*x>=145&&*x<=160&&*y>=255&&*y<=267&&*butt==1)
      {          *people=-9;
         for(i=0;i<=12;i++)
        {
           line(144,256+i,160,256+i);
        }
           delay(100);
        for(i=0;i<=12;i++)
        {
           line(144,256+i,160,256+i);  
        }
      }
        if(*x>=161&&*x<=176&&*y>=255&&*y<=267&&*butt==1)
      {          *people=-10;
         for(i=0;i<=12;i++)
        {
           line(160,256+i,176,256+i);
        }
           delay(100);
        for(i=0;i<=12;i++)
        {
           line(160,256+i,176,256+i);  
        }
      }
}
void rpeokey(int *x,int *y,int *butt,int *people)
{
       int i;
       setcolor(11);
       setwritemode(XOR_PUT);
        if(*x>=440&&*x<=456&&*y>=183&&*y<=195&&*butt==1)
      {
          *people=1;
        for(i=0;i<=12;i++)
        {
           line(440,182+i,456,182+i);
        }
        delay(100);
        for(i=0;i<=12;i++)
        {
           line(440,182+i,456,182+i);  
        }
          
      }
        if(*x>=457&&*x<=472&&*y>=183&&*y<=195&&*butt==1)
      {          *people=2;
          for(i=0;i<=12;i++)
        {
           line(456,182+i,472,182+i);
        }
        delay(100);
        for(i=0;i<=12;i++)
        {
           line(456,182+i,472,182+i);  
        }
      }
        if(*x>=473&&*x<=488&&*y>=183&&*y<=195&&*butt==1)
      {          *people=3;
          for(i=0;i<=12;i++)
        {
           line(472,182+i,488,182+i);
        }
        delay(100);
        for(i=0;i<=12;i++)
        {
           line(472,182+i,488,182+i);  
        }
      }
        if(*x>=489&&*x<=504&&*y>=183&&*y<=195&&*butt==1)
      {          *people=4;
          for(i=0;i<=12;i++)
        {
           line(488,182+i,504,182+i);
        }
        delay(100);
        for(i=0;i<=12;i++)
        {
           line(488,182+i,504,182+i);  
        }
      }
        if(*x>=505&&*x<=520&&*y>=183&&*y<=195&&*butt==1)
      {          *people=5;
          for(i=0;i<=12;i++)
        {
           line(504,182+i,520,182+i);
        }
        delay(100);
        for(i=0;i<=12;i++)
        {
           line(504,182+i,520,182+i);  
        }
      }
        
        if(*x>=440&&*x<=456&&*y>=197&&*y<=209&&*butt==1)
      {
          *people=6;
          for(i=0;i<=12;i++)
        {
           line(440,197+i,456,197+i);
        }
        delay(100);
        for(i=0;i<=12;i++)
        {
           line(440,197+i,456,197+i);  
        }
      }
        if(*x>=457&&*x<=472&&*y>=197&&*y<=209&&*butt==1)
      {          *people=7;
         for(i=0;i<=12;i++)
        {
           line(456,197+i,472,197+i);
        }
        delay(100);
        for(i=0;i<=12;i++)
        {
           line(456,197+i,472,197+i);  
        } 
      }
        if(*x>=473&&*x<=488&&*y>=197&&*y<=209&&*butt==1)
      {          *people=8;
         for(i=0;i<=12;i++)
        {
           line(472,197+i,488,197+i);
        }
        delay(100);
        for(i=0;i<=12;i++)
        {
           line(472,197+i,488,197+i);  
        } 
      }
        if(*x>=489&&*x<=504&&*y>=197&&*y<=209&&*butt==1)
      {          *people=9;
        for(i=0;i<=12;i++)
        {
           line(488,197+i,504,197+i);
        }
        delay(100);
        for(i=0;i<=12;i++)
        {
           line(488,197+i,504,197+i);  
        }  
      }
        if(*x>=505&&*x<=520&*y>=197&&*y<=209&&*butt==1)
      {          *people=10;
         for(i=0;i<=12;i++)
        {
           line(504,197+i,520,197+i);
        }
        delay(100);
        for(i=0;i<=12;i++)
        {
           line(504,197+i,520,197+i);  
        }
      }
        if(*x>=440&&*x<=456&&*y>=241&&*y<=253&&*butt==1)             //out
      {
          *people=-1;
         for(i=0;i<=12;i++)
        {
           line(440,241+i,456,241+i);
        }
        delay(100);
        for(i=0;i<=12;i++)
        {
           line(440,241+i,456,241+i);  
        } 
      }
        if(*x>=457&&*x<=472&&*y>=241&&*y<=253&&*butt==1)
      {          *people=-2;
         for(i=0;i<=12;i++)
        {
           line(456,241+i,472,241+i);
        }
        delay(100);
        for(i=0;i<=12;i++)
        {
           line(456,241+i,472,241+i);  
        } 
      }
        if(*x>=473&&*x<=488&&*y>=241&&*y<=253&&*butt==1)
      {          *people=-3;
         for(i=0;i<=12;i++)
        {
           line(472,241+i,488,241+i);
        }
        delay(100);
        for(i=0;i<=12;i++)
        {
           line(472,241+i,488,241+i);  
        }
      }
        if(*x>=489&&*x<=504&&*y>=241&&*y<=253&&*butt==1)
      {          *people=-4;
         for(i=0;i<=12;i++)
        {
           line(488,241+i,504,241+i);
        }
        delay(100);
        for(i=0;i<=12;i++)
        {
           line(488,241+i,504,241+i);  
        } 
      }
        if(*x>=505&&*x<=520&&*y>=241&&*y<=253&&*butt==1)
      {          *people=-5;
         for(i=0;i<=12;i++)
        {
           line(504,241+i,520,241+i);
        }
        delay(100);
        for(i=0;i<=12;i++)
        {
           line(504,241+i,520,241+i);  
        }
      }
        
        if(*x>=440&&*x<=456&&*y>=255&&*y<=267&&*butt==1)
      {
          *people=-6;
         for(i=0;i<=12;i++)
        {
           line(440,256+i,456,256+i);
        }
        delay(100);
        for(i=0;i<=12;i++)
        {
           line(440,256+i,456,256+i);  
        }
      }
        if(*x>=457&&*x<=472&&*y>=255&&*y<=267&&*butt==1)
      {          *people=-7;
         for(i=0;i<=12;i++)
        {
           line(456,256+i,472,256+i);
        }
        delay(100);
        for(i=0;i<=12;i++)
        {
           line(456,256+i,472,256+i);  
        }
      }
        if(*x>=473&&*x<=488&&*y>=255&&*y<=267&&*butt==1)
      {          *people=-8;
         for(i=0;i<=12;i++)
        {
           line(472,256+i,488,256+i);
        }
        delay(100);
        for(i=0;i<=12;i++)
        {
           line(472,256+i,488,256+i);  
        }
      }
        if(*x>=489&&*x<=504&&*y>=255&&*y<=267&&*butt==1)
      {          *people=-9;
         for(i=0;i<=12;i++)
        {
           line(488,256+i,504,256+i);
        }
        delay(100);
        for(i=0;i<=12;i++)
        {
           line(488,256+i,504,256+i);  
        }
      }
        if(*x>=505&&*x<=520&&*y>=255&&*y<=267&&*butt==1)
      {          *people=-10;
          for(i=0;i<=12;i++)
        {
           line(504,256+i,520,256+i);
        }
        delay(100);
        for(i=0;i<=12;i++)
        {
           line(504,256+i,520,256+i);  
        }
      }
}
