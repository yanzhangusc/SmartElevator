#include<graphics.h>
void ldooron_off(int *li,int *lj,int *lopen,int *lclose,int lt,int *lti)
{
	
        int x=210,xa=181,xb=239,y;
	y=95+(9-lt)*22;
	setcolor(2);
        setwritemode(XOR_PUT);
	if(*lopen==1)
        {
	  if((x+*li)<240)
	  {
		line(x+*li,y,x+*li,y+22);
		line(x-*li,y,x-*li,y+22);
                delay(20);
                if((x+*li)==xb)//门完全打开将open置零，将close置1
                {
                  *lclose=1;
                  *lopen=0;
                  *li=0;
                  *lj=0;
                  delay(200);
                } 
          }
	}
        if(*lclose==1)
        {        
	  if((xa+*lj)<=210)
	  {
                
		line(xa+*lj,y,xa+*lj,y+22);
		line(xb-*lj,y,xb-*lj,y+22);
                delay(20);
                if(xa+*lj==x)//门完全关闭将open置1，将close置0，lti置1
                {
                 *lti=1;
                 *lclose=0;
                 *lopen=1;
                 *li=0;
                 *lj=0;
                }
	  }
        }
}
void rdooron_off(int *ri,int *rj,int *ropen,int *rclose,int rt,int *rti)
{	
	int x=404,xa=375,xb=433,y;
	y=95+(9-rt)*22;
	setcolor(2);
        setwritemode(XOR_PUT);
	if(*ropen==1)
        {
          if((x+*ri)<444)
	  {
		line(x+*ri,y,x+*ri,y+22);
		line(x-*ri,y,x-*ri,y+22);
                delay(20);
                if((x+*ri)==xb)
                {
                  *rclose=1;
                  *ropen=0;
                  *ri=0;
                  *rj=0;
                  delay(200);
                } 
          }
	}
        if(*rclose==1)
        {    
	   if((xa+*rj)<=404)
	   {
                
		line(xa+*rj,y,xa+*rj,y+22);
		line(xb-*rj,y,xb-*rj,y+22);
                delay(20);
                if(xa+*rj==x)
                {
                  *rti=1;
                  *rclose=0;
                  *ropen=1;
                  *ri=0;
                  *rj=0;
                }
	   }
        }              
}
/*void ldoorcontrol(int nl,int*li,int*lflag,int*lti)
{
  switch(*lflag)
    {
    case 0:
    dooropen('l',nl,li,lflag);break;
    case 1:
    doorclose('l',nl,li,lflag,lti);break;
    default: break;
    }
    
}
void rdoorcontrol(int nr,int*ri,int*rflag,int*rti)
{
  
     switch(*rflag)
    {
    case 0:
    dooropen('r',nr,ri,rflag);break;
    case 1:
    doorclose('r',nr,ri,rflag,rti);break;
    default: break;
    }
}
void dooropen(char lr, int n,int*i,int*flag)
{
   int x;
   if(lr=='l')
   x=211;
   else if(lr=='r')
   x=405;
     
     
     line(x-*i,n,x-*i,n+30);
     line(x+*i,n,x+*i,n+30);
     delay(50);
     (*i)++;
   if((*i)==31) 
   {*flag=1;}
}

void doorclose(char lr, int n,int*i,int*flag,int*ti)
{
   int x;
   if(lr=='l')
   x=211;
   else if(lr=='r')
   x=405;
 
   (*i)--;
     line(x-*i,n,x-*i,n+30);
     line(x+*i,n,x+*i,n+30);
     delay(50);
     
   if((*i)==0)
   {*ti=100,*flag=0;}
   
}*/