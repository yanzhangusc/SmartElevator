#include"lift.h"
#include<graphics.h>

void control()
{
	int x=0,y=0,mbutt;//鼠标
        char *s;
	static int lti=1,rti=1;//电梯运行和开关门标志
	int nl,nr;//左右电梯位置
        int lt,rt;//储存电梯到达的楼层
        static int li=0,lj=0,ri=0,rj=0,lltofloor,rrtofloor;//开关门时x轴上的增量
        static int lopen=1,lclose=0,ropen=1,rclose=0;//开关门标志open=1开门，close=1关门
        int liftin=0,liftout=0, ltofloor=0,rtofloor=0,
		lpeople=0,rpeople=0,
		ltotalpeople=0,rtotalpeople=0;
	int lcfloor=1,rcfloor=1;//两电梯当前楼层
        int laction=0,raction=0;//两电梯当前状态0停1上2下
	int floorup[9]={0,0,0,0,0,0,0,0,0},	
	    floordown[9]={0,0,0,0,0,0,0,0,0},
	    lmust[9]={0,0,0,0,0,0,0,0,0},
	    rmust[9]={0,0,0,0,0,0,0,0,0};
        static int lan[9]={0,0,0,0,0,0,0,0,0,},ran[]={0,0,0,0,0,0,0,0,0,};
      
        static int lup=0,rdn=0;
        static int lc=1,rc=1;
	enum direct direction[2]={0,0};
	nl=95+(9-lcfloor)*22;//电梯位置初始化
	nr=95+(9-rcfloor)*22;
        cursor(x, y);
	while(1)
	{	
                mouse(&x,&y,&mbutt);delay(30);
                newkeyin(&x,&y,&mbutt,&liftin,&direction[1],&lup,&rdn,&lcfloor,&rcfloor);
		newkeyout(&x,&y,ltotalpeople,rtotalpeople,&mbutt,&liftout,&direction[0],lan,ran);
                transferfloor(&liftin,&liftout,
				ltotalpeople,rtotalpeople,
				floorup, floordown,
				lmust,rmust,direction);

		 if(lti!=0&&rti!=0)
                 design(floorup, floordown,
		       lmust,rmust,
		       lcfloor,rcfloor,
		       &laction,&raction,
		       &ltofloor,&rtofloor,&lltofloor,&rrtofloor);
             
          lltofloor=0;
          rrtofloor=0;                
                
         if(lcfloor!=lc||rcfloor!=rc)
         lrcfloor(&lcfloor,&rcfloor);
         lc=lcfloor;//记录当前楼层以便当前楼层显示用
         rc=rcfloor;
         
         if(lti==1)
                 {
                   liftacty('l', ltofloor, &lcfloor,&laction,&nl);
                 }
         if(rti==1)	
                 { 
                  liftacty('r', rtofloor, &rcfloor,&raction,&nr);
                 }
         
      
        if(lcfloor==ltofloor)////////当前楼层等于目的楼层，即到达后
		 {
                        lanjianliang(ltofloor,&lcfloor,lan);
                        lti=0;
                        lt=ltofloor;//把值赋给lt用于开关门计算坐标
                        ltofloor=0;             	
		 }
	if(rcfloor==rtofloor)
		 {
                        ranjianliang(rtofloor,&rcfloor,ran);
                        rti=0;
                        rt=rtofloor;
			rtofloor=0;      
		 }
         if(laction==0&&liftin==lcfloor)

            { 
              ldooron_off(&li,&lj,&lopen,&lclose,lt,&lti);
                  li++;
                  lj++; 
             }
         if(raction==0&&liftin==rcfloor)
           { 
               rdooron_off(&ri,&rj,&ropen,&rclose,rt,&rti);
                  ri++;
                  rj++;
            } 
          if(lti==0)
                 {
                  lmidshine(lcfloor);
                  ldooron_off(&li,&lj,&lopen,&lclose,lt,&lti);
                  li++;
                  lj++; 
                 
                  lpeokey(&x,&y,&mbutt,&lpeople);
                  ltotalpeople=lpeople+ltotalpeople;
                  lpeople=0;
                  setfillstyle(1,6);

                  if(ltotalpeople>10)
                    {
                        alarm('l');
                        ltotalpeople=10;
                    }
                  if(ltotalpeople<0)
                     ltotalpeople=0;
                  bar(120,149,145,158);
                  setcolor(1);
                  sprintf(s,"%d",ltotalpeople);
                  outtextxy(130,153,s);        
                 }
          if(rti==0)
                 {
                  rmidshine(rcfloor);
                  rdooron_off(&ri,&rj,&ropen,&rclose,rt,&rti);
                  ri++;
                  rj++;
                 
                  rpeokey(&x,&y,&mbutt,&rpeople);
                  rtotalpeople=rtotalpeople+rpeople;
                  rpeople=0;                    
                  if(rtotalpeople>10)
                    {
                       alarm('r');
                       rtotalpeople=10;
                    }
                  if(rtotalpeople<0)
                     rtotalpeople=0;
                  setfillstyle(1,6);
                  bar(458,149,483,158);
                  setcolor(1);
                  sprintf(s,"%d",rtotalpeople);
		  outtextxy(468,153,s);        
                 } 
          if(laction==1)          
              luplouliang(&nl,&lcfloor);
          if(laction==2)
              ldnlouliang(&nl,&lcfloor);
          if(raction==1)          
              ruplouliang(&nr,&rcfloor);
          if(raction==2)
              rdnlouliang(&nr,&rcfloor);
          
          if(x>160&&x<200&&y>=335&&y<=350&&mbutt==1)
		 {	
                        setactivepage(1);
                        cleardevice();
                        setvisualpage(1);
                        
			menus("about");
                        setactivepage(0);
                        setvisualpage(0);
                        
	 	 }
            if(x>=390&&x<450&&y>=335&&y<=350&&mbutt==1)
	  {    break;}
	}
}