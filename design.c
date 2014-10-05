void lUprUp(int*floorup,			/*左电梯向上运动，右电梯向上运动*/	
		
		int*lmust,int*rmust,
		int lcfloor,int rcfloor,
		int*laction,int*raction,
		int*ltofloor,int*rtofloor,
		int *lt,int *rt)
{
	int i;
	if((*laction==1)&&(*raction==1))
		{
			if(*ltofloor==0)
				{
					floorup[lcfloor-1]=0;

					lmust[lcfloor-1]=0;

				}
			if(*rtofloor==0)
				{
					floorup[rcfloor-1]=0;

					rmust[rcfloor-1]=0;

				}
			if(lcfloor<rcfloor)		//左电梯在右电梯下面时
				{
					for(i=lcfloor;i<9;i++)
					{
						if((floorup[i]==i+1)||(lmust[i]
==i+1)||(rmust[i]==i+1))
						{
							if(floorup[i]==i+1)
							{
								if(rcfloor>=i+1)
									{
										
*lt=i+1;
									}
								if(rcfloor<i+1)
									{
										
*rt=i+1;
									}
							}
							if(lmust[i]==i+1)		
		//左电梯第i+1层有人出
								{
									*lt=i+1;
								}
							if(rmust[i]==i+1)		
//右电梯第i+1层有人出
								{
									*rt=i+1;
								}
							break;
						}
					}
				}
	
			if(lcfloor>=rcfloor)				//左电梯在右电梯上面或同层时，“=”左优先
				{
					for(i=rcfloor;i<9;i++)
					{
						if((floorup[i]==i+1)||(lmust[i]
==i+1)||(rmust[i]==i+1))
						{
							if(floorup[i]==i+1)
							{
								if(lcfloor>i+1)
									{
										
*rt=i+1;
									}
								if(lcfloor<=i+1)
									{
										
*lt=i+1;
									}
							}
							if(lmust[i]==i+1)		
	//左电梯第i+1层有人出
								{
									*lt=i+1;
								}
							if(rmust[i]==i+1)		
	//	右电梯第i+1层有人出
								{
									*rt=i+1;
								}
							break;
						}
					}
				}
		}
}

void lUprDown(int*floorup,int*floordown,
		int*lmust,int*rmust,
		int lcfloor,int rcfloor,
		int*laction,int*raction,
		int*ltofloor,int*rtofloor,
		int *lt,int *rt)
{
	int i;
	if((*laction==1)&&(*raction==2))
		{
			if(*ltofloor==0)			//当左边电梯到达后
				{
					floorup[lcfloor-1]=0;
					
					lmust[lcfloor-1]=0;

				}
			if(*rtofloor==0)		//当右边电梯到达后，对向下
				{
					floordown[rcfloor-1]=0;
					rmust[rcfloor-1]=0;

				}
			for(i=lcfloor;i<9;i++)
				{
					if((floorup[i]==i+1)||(lmust[i]==i+1))
						{
							*lt=i+1;
							break;
						}
				}
			for(i=rcfloor-2;i>=0;i--)		//“-2”当前层下一
				{
					if((floordown[i]==i+1)||(rmust[i]==i+1))
						{
							*rt=i+1;
							break;
						}
				}
		}
}

void lDownrUp(int*floorup,int*floordown,			/*左电梯向下运动，
                                                                                   右电梯向上运动*/
		
		int*lmust,int*rmust,
		int lcfloor,int rcfloor,
		int*laction,int*raction,
		int*ltofloor,int*rtofloor,
		int *lt,int *rt)
{

	int i;
	if((*laction==2)&&(*raction==1))
		{
			if(*ltofloor==0)				//当左边电
				{
					floordown[lcfloor-1]=0;
					
					lmust[lcfloor-1]=0;

				}
			if(*rtofloor==0)		//当右边 电梯到达后，对
				{
					
					floorup[rcfloor-1]=0;
					rmust[rcfloor-1]=0;
				}
			for(i=lcfloor-2;i>=0;i--)
				{
					if((floordown[i]==i+1)||(lmust[i]==i+1))
						{
							*lt=i+1;
							break;
						}
				}
			for(i=rcfloor;i<9;i++)
				{
					if((floorup[i]==i+1)||(rmust[i]==i+1))
						{
							*rt=i+1;
							break;
						}
				}
		}
}

void lDownrDown(int*floordown,			/*左电梯向下运动，右电梯向下运动*/
		int*lmust,int*rmust,
		int lcfloor,int rcfloor,
		int*laction,int*raction,
		int*ltofloor,int*rtofloor,
		int *lt,int *rt)
{
	int i;
	if((*laction==2)&&(*raction==2))
		{
			if(*ltofloor==0)		//当左边电梯到达后，对向?
				{
					floordown[lcfloor-1]=0;
					
					lmust[lcfloor-1]=0;

				}
			if(*rtofloor==0)			//当右边电梯到达
				{
					floordown[rcfloor-1]=0;
					
					rmust[rcfloor-1]=0;

				}
			if(lcfloor>=rcfloor)			//左电梯在右电梯?
				{
					for(i=lcfloor-2;i>=0;i--)
					{
						if((floordown[i]==i+1)||(lmust[i]
==i+1)||(rmust[i]==i+1))
						{
							if(floordown[i]==i+1)
							{
								if(rcfloor<=i+1)
									{
										
*lt=i+1;

									}
								if(rcfloor>i+1)
									{
										
*rt=i+1;

									}
							}
							if(lmust[i]==i+1)		
	//左电梯第i+1层有人出
								{
									*lt=i+1;
								}
							if(rmust[i]==i+1)		
	//右电梯第i+1层有人出
								{
									*rt=i+1;
								}
							break;
						}

					}
				}

			if(lcfloor<rcfloor)		//左电梯在右电梯下面时
				{
					for(i=rcfloor-2;i>=0;i--)
					{
						if((floordown[i]==i+1)||(lmust[i]
==i+1)||(rmust[i]==i+1))
						{
							if(floordown[i]==i+1)
							{
								if(lcfloor>=i+1)
									{
										
*lt=i+1;
									}
								if(lcfloor<i+1)
									{
										
*rt=i+1;
									}
							}
							if(lmust[i]==i+1)		
	//左电梯第i+1层有人出
								{
									*lt=i+1;
								}
							if(rmust[i]==i+1)		
	//右电梯第i+1层有人出
								{
									*rt=i+1;
								}
							break;
						}
					}
				}
		}
}
void lStoprUp(int*floorup,int*floordown,			/*左电梯空闲，右电
梯向上运动*/
		int*lmust,int*rmust,
		int lcfloor,int rcfloor,
		int*laction,int*raction,
		int*ltofloor,int*rtofloor,
		int *lt,int *rt)
{
	int i;
	if((*laction==0)&&(*raction==1))
		{
			if(*rtofloor==0)			//当右边电梯到达?
				{
					
					floorup[rcfloor-1]=0;
					rmust[rcfloor-1]=0;

				}
                        if(*ltofloor==0)				//当左边电
		
				{							
//用来处理在当前位置开门的情况
					floorup[lcfloor-1]=0;
					
					lmust[lcfloor-1]=0;
					
					floordown[lcfloor-1]=0;
				}
			for(i=0;i<8;i++)
				{
					if(lmust[i]==i+1)
						{
							*lt=i+1;
							break;
						}
				}
			for(i=8;i>=0;i--)
				{
					if((floordown[i]==i+1)&&(*rtofloor)!=i+1)
						{
							*lt=i+1;
							break;
						}
				}
			for(i=0;i<rcfloor;i++)
				{
					if(floorup[i]==i+1)
						{
							*lt=i+1;
							break;
						}
				}
			for(i=0;i<rcfloor;i++)
				{
					if(rmust[i]==i+1)
						{
							*rt=i+1;
							break;
						}
				}
			for(i=rcfloor;i<9;i++)
				{
					if((floorup[i]==i+1)||(rmust[i]==i+1))
						{
							*rt=i+1;
							break;
						}
				}
			
	}
}

void lStoprDown(int*floorup,int*floordown,
		int*lmust,int*rmust,
		int lcfloor,int rcfloor,
		int*laction,int*raction,
		int*ltofloor,int*rtofloor,
		int *lt,int *rt)
{
	int i;
	if((*laction==0)&&(*raction==2))
		{
			if(*rtofloor==0)
				{
					floordown[rcfloor-1]=0;
					
					rmust[rcfloor-1]=0;

				}
                        if(*ltofloor==0)
		
				{							
//用来处理在当前位置开门的情况
					floorup[lcfloor-1]=0;
					lmust[lcfloor-1]=0;
					floordown[lcfloor-1]=0;
					
				}

			for(i=0;i<8;i++)
				{
					if(lmust[i]==i+1)
						{
							*lt=i+1;
							break;
						}
				}
			for(i=8;i>=rcfloor-1;i--)
				{
					if(floordown[i]==i+1)
						{
							*lt=i+1;
							break;
						}
				}
			for(i=0;i<9;i++)
				{
					if((floorup[i]==i+1)&&(*rtofloor!=i+1))
						{
							*lt=i+1;
							break;
						}
				}
			for(i=rcfloor-1;i<9;i++)
				{
					if(rmust[i]==i+1)
						{
							*rt=i+1;
							break;
						}
				}
			for(i=rcfloor-2;i>=0;i--)
				{
					if((floordown[i]==i+1)||(rmust[i]==i+1))
						{
							*rt=i+1;
							break;
						}
				}
			
		}

}

void lUprStop(int*floorup,int*floordown,			/*左电梯向上运动，
右电梯空闲*/
		int*lmust,int*rmust,
		int lcfloor,int rcfloor,
		int*laction,int*raction,
		int*ltofloor,int*rtofloor,
		int *lt,int *rt)
{
	int i;
	if((*laction==1)&&(*raction==0))
		{
			if(*ltofloor==0)						
//当左边电梯到达后，对向上传值数组对应元素清零
				{
					floorup[lcfloor-1]=0;
					
					lmust[lcfloor-1]=0;
				}
                        if(*rtofloor==0)				//当右边?
				{							
//用来处理在当前位置开门的情况
					floorup[rcfloor-1]=0;
					
					rmust[rcfloor-1]=0;
					floordown[rcfloor-1]=0;
					
				}
			for(i=0;i<9;i++)
				{
					if(rmust[i]==i+1)				
//右电梯第i+1层有人出
						{
							*rt=i+1;
							break;
						}
				}
			for(i=8;i>=0;i--)
				{
					if((floordown[i]==i+1)&&((*ltofloor)!=i+1))
						{
							*rt=i+1;
							break;
						}
				}			
			for(i=0;i<lcfloor;i++)
				{
					if(floorup[i]==i+1)
						{
							*rt=i+1;
							break;
						}
				}

			for(i=0;i<lcfloor;i++)
				{
					if(lmust[i]==i+1)
						{
							*lt=i+1;
							break;
						}
				}
			for(i=lcfloor;i<9;i++)
				{
					if((floorup[i]==i+1)||(lmust[i]==i+1))
						{
							*lt=i+1;
							break;
						}
				}	
			
		}
}
void lDownrStop(int*floorup,int*floordown,		/*左电梯向下运动，右电梯空
闲*/
		int*lmust,int*rmust,
		int lcfloor,int rcfloor,
		int*laction,int*raction,
		int*ltofloor,int*rtofloor,
		int *lt,int *rt)
{
	int i;
	if((*laction==2)&&(*raction==0))
		{
			if(*ltofloor==0)						
//当左边电梯到达后，对向下传值数组对应元素清零
				{
					floordown[lcfloor-1]=0;
					
					lmust[lcfloor-1]=0;

				}
                        if(*rtofloor==0)				//当右边电
				{							
//用来处理在当前位置开门的情况
					floorup[rcfloor-1]=0;
					rmust[rcfloor-1]=0;
					floordown[rcfloor-1]=0;
				}
			
			for(i=0;i<8;i++)
				{
					if(rmust[i]==i+1)				
//右电梯第i+1层有人出
						{
							*rt=i+1;
							break;
						}
				}
			for(i=8;i>=lcfloor-1;i--)
				{
					if(floordown[i]==i+1)
						{
							*rt=i+1;
							break;
						}
				}
			for(i=0;i<9;i++)
				{
					if((floorup[i]==i+1)&&(*ltofloor!=i+1))
						{
							*rt=i+1;
							break;
						}
				}
			for(i=lcfloor-1;i<9;i++)
				{
					if(lmust[i]==i+1)			
						{
							*lt=i+1;
							break;
						}
				}
			for(i=lcfloor-2;i>=0;i--)
				{
					if((floordown[i]==i+1)||(lmust[i]==i+1))
						{
							*lt=i+1;
							break;

						}
				}
			
		}
}


void lStoprStop(int*floorup,int*floordown,		/*左电梯空闲，右电梯空闲*/
		int*lmust,int*rmust,
		int lcfloor,int rcfloor,
		int*laction,int*raction,
		int*ltofloor,int*rtofloor,
		int *lt,int *rt)
{
	int i;
	if((*laction==0)&&(*raction==0))
		{
                       if(*ltofloor==0)				//当左边电
		
				{							
//用来处理在当前位置开门的情况
					floorup[lcfloor-1]=0;
					
					lmust[lcfloor-1]=0;
					floordown[lcfloor-1]=0;
					
				}
			if(*rtofloor==0)				//当右边电
				{							
//用来处理在当前位置开门的情况
					floorup[rcfloor-1]=0;
					
					rmust[rcfloor-1]=0;
					floordown[rcfloor-1]=0;
					
				}
			if(lcfloor<rcfloor)			//左电梯
				{
					for(i=(lcfloor+rcfloor)/2;i<=8;i++)
							if((floordown[i]==i+1)||
(floorup[i]==i+1))
								{
									*rt=i+1;
									break;
								}
					for(i=(lcfloor+rcfloor)/2-1;i>=0;i--)
							if((floordown[i]==i+1)||
(floorup[i]==i+1))
								{
								       *lt=i+1;
									break;
								}
					for(i=0;i<=8;i++)
							if(lmust[i]==i+1)
								{
								      *lt=i+1;	
		//左电梯第i+1层有人出                                   break;
								}
					for(i=0;i<=8;i++)
							if(rmust[i]==i+1)		
	////右电梯第i+1层有人出
								{
									*rt=i+1;
									break;
								}
				}
			if(lcfloor>=rcfloor)		//左电梯在右电梯上面或同层
				{
					for(i=(lcfloor+rcfloor)/2;i<=8;i++)
							if((floordown[i]==i+1)||
(floorup[i]==i+1))
								{
								      *lt=i+1;
									break;
								}
					for(i=(lcfloor+rcfloor)/2-1;i>=0;i--)
							if((floordown[i]==i+1)||
(floorup[i]==i+1))
								{
									*rt=i+1;
									break;
								}
					for(i=0;i<=8;i++)
							if(lmust[i]==i+1)		
		//左电梯第i+1层有人出
								{
								       *lt=i+1;
									break;
								}
					for(i=0;i<=8;i++)
							if(rmust[i]==i+1)		
		//右电梯第i+1层有人出
								{
									*rt=i+1;
									break;
								}
				}
			
               
        }
}

void transferfloor(int*liftin,int*liftout,
		int ltotalpeople, int rtotalpeople,
		int*floorup,int*floordown,
		int*lmust,int*rmust,enum direct direction[])
{
	int i;
	if((*liftin)!=0)		//传递电梯门外的选中的楼层数
	{
		if(direction[1]==1)
		{
		    floorup[*liftin-1]=*liftin;
                }
		if(direction[1]==2)
		{		
		    floordown[*liftin-1]=*liftin;
						
		}
		*liftin=0;
	}
	if((*liftout)!=0)		//传递电梯门内的选中的楼层数
	{
		if(direction[0]==7)
		{
			lmust[*liftout-1]=*liftout;

		}
		if(direction[0]==8)
		{
			rmust[*liftout-1]=*liftout;

		}
		*liftout=0;
	} 
        if(ltotalpeople==0)
	{
		 for(i=0;i<9;i++)
			lmust[i]=0;
	}
	if(rtotalpeople==0)
		{
		 for(i=0;i<9;i++)
			rmust[i]=0;
		}
       
          
        
	
}
void design(int*floorup,int*floordown,
		
		int*lmust,int*rmust,
		int lcfloor,int rcfloor,
		int*laction,int*raction,
		int*ltofloor,int*rtofloor,int*lltofloor,int*rrtofloor)
{
	static int	lt=0,rt=0;
		if((lt==0)&&((*ltofloor)==0))
		{
			*laction=0;
		}
	        if((rt==0)&&((*rtofloor)==0))
		{
			*raction=0;
		}

		
	lUprUp(floorup,
								lmust,rmust,
								lcfloor,rcfloor,
								laction,raction,
								
ltofloor,rtofloor,&lt,&rt);
	lUprDown(floorup, floordown,
								lmust,rmust,
								lcfloor,rcfloor,
								laction,raction,
								
ltofloor,rtofloor,&lt,&rt);
	 lDownrUp(floorup, floordown,
								lmust,rmust,
								lcfloor,rcfloor,
								laction,raction,ltofloor,rtofloor,&lt,&rt);
	lDownrDown(floordown,
								lmust,rmust,
								lcfloor,rcfloor,
								laction,raction,ltofloor,rtofloor,&lt,&rt);
	 lStoprUp(floorup, floordown,
								lmust,rmust,
								lcfloor,rcfloor,
								laction,raction,ltofloor,rtofloor,&lt,&rt);
	 lStoprDown(floorup, floordown,
								lmust,rmust,
								lcfloor,rcfloor,
								laction,raction,ltofloor,rtofloor,&lt,&rt);
	 lUprStop(floorup, floordown,
								lmust,rmust,
								lcfloor,rcfloor,
								laction,raction,ltofloor,rtofloor,&lt,&rt);
	 lDownrStop(floorup, floordown,
								lmust,rmust,
								lcfloor,rcfloor,
								laction,raction,ltofloor,rtofloor,&lt,&rt);
	 lStoprStop(floorup, floordown,
								lmust,rmust,
								lcfloor,rcfloor,
								laction,raction,ltofloor,rtofloor,&lt,&rt);
	
	
		
	if(lt!=0&&lt!=lcfloor)
		{
			*ltofloor=lt;
                        *lltofloor=lt; 
			
		}
	if(rt!=0&&rt!=rcfloor)
		{
			*rtofloor=rt;
                        *rrtofloor=rt;
			
		}
lt=0;
rt=0;
}
	