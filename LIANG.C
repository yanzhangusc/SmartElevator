#include"graphics.h"


void luplouliang(int*nl,int*lc)
{   
	int xa=246,xb=266,ya,i;
	ya=95+(9-*lc)*22;
	
	
	setwritemode(XOR_PUT);
	setcolor(14);
	if((*nl+22)==281||(*nl+22)==259||(*nl+22)==237||(*nl+22)==215||(*nl+22)==193||(*nl+22)==171||(*nl+22)==149||(*nl+22)==127)
	{
		for(i=0;i<15;i++)
		{
			line(xa,ya+6+i,xb,ya+6+i);
			line(xa,ya+6-22+i,xb,ya+6-22+i);
		}
	}
	
}

void ldnlouliang(int*nl,int*lc)
{   
	int xa=246,xb=266,ya,i;
	ya=95+(9-*lc)*22;
		
	setwritemode(XOR_PUT);
	setcolor(14);
	if((*nl+22)==281||(*nl+22)==259||(*nl+22)==237||(*nl+22)==215||(*nl+22)==193||(*nl+22)==171||(*nl+22)==149||(*nl+22)==127)
	{
		for(i=0;i<15;i++)
		{
			line(xa,ya+6+i,xb,ya+6+i);
			line(xa,ya+6+22+i,xb,ya+6+22+i);
		}
	}
	
}
void ruplouliang(int*nr,int*rc)
{   
	int xa=350,xb=370,ya,i;
	ya=95+(9-*rc)*22;
		
	setwritemode(XOR_PUT);
	setcolor(14);
	if((*nr+22)==281||(*nr+22)==259||(*nr+22)==237||(*nr+22)==215||(*nr+22)==193||(*nr+22)==171||(*nr+22)==149||(*nr+22)==127)
	{
		for(i=0;i<15;i++)
		{
			line(xa,ya+6+i,xb,ya+6+i);
			line(xa,ya+6-22+i,xb,ya+6-22+i);
		}
	}
	
}

void rdnlouliang(int*nr,int*rc)
{   
	int xa=350,xb=370,ya,i;
	ya=95+(9-*rc)*22;
		
	setwritemode(XOR_PUT);
	setcolor(14);
	if((*nr+22)==281||(*nr+22)==259||(*nr+22)==237||(*nr+22)==215||(*nr+22)==193||(*nr+22)==171||(*nr+22)==149||(*nr+22)==127)
	{
		for(i=0;i<15;i++)
		{
			line(xa,ya+6+i,xb,ya+6+i);
			line(xa,ya+6+22+i,xb,ya+6+22+i);
		}
	}
	
}


void updnliangbiao(int *lltofloor,int *rrtofloor,int upl[],int upr[],int dnl[],int dnr[],int*lup,int*rdn)
{
	if(*lup==1)
	{
	   if(*lltofloor!=0)
		{
                  upl[*lltofloor-1]=1;
                }
	   if(*rrtofloor!=0)
		{
                  upr[*rrtofloor-1]=1;
                }
	}
	if(*rdn==2)
	{
	   if(*lltofloor!=0)
		{
                  dnl[*lltofloor-1]=2;
                }
	   if(*rrtofloor!=0)
		{ 
                  dnr[*rrtofloor-1]=2;
                }
	}
      *lup=0;
      *rdn=0;

        

}
void updnliang(int ltofloor,int rtofloor,int *lcfloor,int *rcfloor,int upl[],int upr[],int dnl[],int dnr[])
{
	int xa=297,ya=124,xb=327,yb=110;
        setcolor(4);
		if((*lcfloor==ltofloor)&&upl[ltofloor-1]==1)
		{	
		   setfillstyle(1,9);
		   pieslice(xa,ya+(8-ltofloor)*22,240,300,12);
		   upl[ltofloor-1]=0;
		}	
		if((*rcfloor==rtofloor)&&upr[rtofloor-1]==1)
		{	
		   setfillstyle(1,9);
		   pieslice(xa,ya+(8-rtofloor)*22,240,300,12);
		   upr[rtofloor-1]=0;
		}
		if((*lcfloor==ltofloor)&&dnl[ltofloor-1]==2)
		{	
		   setfillstyle(1,9);
		   pieslice(xb,yb+(9-ltofloor)*22,60,120,12);
		   dnl[ltofloor-1]=0;
		}	
		if((*rcfloor==rtofloor)&&dnr[rtofloor-1]==2)
		{	
		   setfillstyle(1,9);
		   pieslice(xb,yb+(9-rtofloor)*22,60,120,12);
		   dnr[rtofloor-1]=0;
		}
        
}


void lanjianliang(int ltofloor,int*lcfloor,int lan[])
{
	int i,j,k;
    setwritemode(XOR_PUT);
    setcolor(11);
   
      for(j=1;j<10;j++)
     {
        if((*lcfloor==ltofloor)&&lan[ltofloor-1]==j)
			
	 { k=(j+2)/3;
         for(i=0;i<15;i++)     
        {
           line(112+(j-(k-1)*3-1)*20,88+(k-1)*15+i,132+(j-(k-1)*3-1)*20,88+(k-1)*15+i);
        }}
     }
	lan[ltofloor-1]=0;        
}
void ranjianliang(int rtofloor,int*rcfloor,int ran[])
{
	int i,j,k;
        setwritemode(XOR_PUT);
        setcolor(11);
    for(j=1;j<10;j++)
     {
        if((*rcfloor==rtofloor)&&ran[rtofloor-1]==j)
	{	k=(j+2)/3;	
	    for(i=0;i<15;i++)
         {
            line(446+(j-(k-1)*3-1)*20,88+(k-1)*15+i,466+(j-(k-1)*3-1)*20,88+(k-1)*15+i);
         }}
     }
	ran[rtofloor-1]=0;
}
 void lmidshine(int lc)
{
  int k1,k2;

//setcolor(4);

//setfillstyle(1,4);
//setwritemode(XOR_PUT);
   k1=getpixel(297,95+(9-lc)*22+11);
if(k1==4)
pieslice(297,124+(8-lc)*22,240,300,12);
   k2=getpixel(327,95+(9-lc)*22+11);
if(k2==4)
pieslice(327,110+(9-lc)*22,60,120,12);
}



void rmidshine(int rc)
{
   int k1,k2;

//setcolor(4);

//setfillstyle(1,4);
//setwritemode(XOR_PUT);

   k1=getpixel(297,95+(9-rc)*22+11);
if(k1==4)
pieslice(297,124+(8-rc)*22,240,300,12);
   k2=getpixel(327,95+(9-rc)*22+11);
if(k2==4)
pieslice(327,110+(9-rc)*22,60,120,12);
}