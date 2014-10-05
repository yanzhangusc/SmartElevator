void lUprUp(int*floorup,			/*����������˶����ҵ��������˶�*/	
		
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
			if(lcfloor<rcfloor)		//��������ҵ�������ʱ
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
		//����ݵ�i+1�����˳�
								{
									*lt=i+1;
								}
							if(rmust[i]==i+1)		
//�ҵ��ݵ�i+1�����˳�
								{
									*rt=i+1;
								}
							break;
						}
					}
				}
	
			if(lcfloor>=rcfloor)				//��������ҵ��������ͬ��ʱ����=��������
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
	//����ݵ�i+1�����˳�
								{
									*lt=i+1;
								}
							if(rmust[i]==i+1)		
	//	�ҵ��ݵ�i+1�����˳�
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
			if(*ltofloor==0)			//����ߵ��ݵ����
				{
					floorup[lcfloor-1]=0;
					
					lmust[lcfloor-1]=0;

				}
			if(*rtofloor==0)		//���ұߵ��ݵ���󣬶�����
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
			for(i=rcfloor-2;i>=0;i--)		//��-2����ǰ����һ
				{
					if((floordown[i]==i+1)||(rmust[i]==i+1))
						{
							*rt=i+1;
							break;
						}
				}
		}
}

void lDownrUp(int*floorup,int*floordown,			/*����������˶���
                                                                                   �ҵ��������˶�*/
		
		int*lmust,int*rmust,
		int lcfloor,int rcfloor,
		int*laction,int*raction,
		int*ltofloor,int*rtofloor,
		int *lt,int *rt)
{

	int i;
	if((*laction==2)&&(*raction==1))
		{
			if(*ltofloor==0)				//����ߵ�
				{
					floordown[lcfloor-1]=0;
					
					lmust[lcfloor-1]=0;

				}
			if(*rtofloor==0)		//���ұ� ���ݵ���󣬶�
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

void lDownrDown(int*floordown,			/*����������˶����ҵ��������˶�*/
		int*lmust,int*rmust,
		int lcfloor,int rcfloor,
		int*laction,int*raction,
		int*ltofloor,int*rtofloor,
		int *lt,int *rt)
{
	int i;
	if((*laction==2)&&(*raction==2))
		{
			if(*ltofloor==0)		//����ߵ��ݵ���󣬶���?
				{
					floordown[lcfloor-1]=0;
					
					lmust[lcfloor-1]=0;

				}
			if(*rtofloor==0)			//���ұߵ��ݵ���
				{
					floordown[rcfloor-1]=0;
					
					rmust[rcfloor-1]=0;

				}
			if(lcfloor>=rcfloor)			//��������ҵ���?
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
	//����ݵ�i+1�����˳�
								{
									*lt=i+1;
								}
							if(rmust[i]==i+1)		
	//�ҵ��ݵ�i+1�����˳�
								{
									*rt=i+1;
								}
							break;
						}

					}
				}

			if(lcfloor<rcfloor)		//��������ҵ�������ʱ
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
	//����ݵ�i+1�����˳�
								{
									*lt=i+1;
								}
							if(rmust[i]==i+1)		
	//�ҵ��ݵ�i+1�����˳�
								{
									*rt=i+1;
								}
							break;
						}
					}
				}
		}
}
void lStoprUp(int*floorup,int*floordown,			/*����ݿ��У��ҵ�
�������˶�*/
		int*lmust,int*rmust,
		int lcfloor,int rcfloor,
		int*laction,int*raction,
		int*ltofloor,int*rtofloor,
		int *lt,int *rt)
{
	int i;
	if((*laction==0)&&(*raction==1))
		{
			if(*rtofloor==0)			//���ұߵ��ݵ���?
				{
					
					floorup[rcfloor-1]=0;
					rmust[rcfloor-1]=0;

				}
                        if(*ltofloor==0)				//����ߵ�
		
				{							
//���������ڵ�ǰλ�ÿ��ŵ����
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
//���������ڵ�ǰλ�ÿ��ŵ����
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

void lUprStop(int*floorup,int*floordown,			/*����������˶���
�ҵ��ݿ���*/
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
//����ߵ��ݵ���󣬶����ϴ�ֵ�����ӦԪ������
				{
					floorup[lcfloor-1]=0;
					
					lmust[lcfloor-1]=0;
				}
                        if(*rtofloor==0)				//���ұ�?
				{							
//���������ڵ�ǰλ�ÿ��ŵ����
					floorup[rcfloor-1]=0;
					
					rmust[rcfloor-1]=0;
					floordown[rcfloor-1]=0;
					
				}
			for(i=0;i<9;i++)
				{
					if(rmust[i]==i+1)				
//�ҵ��ݵ�i+1�����˳�
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
void lDownrStop(int*floorup,int*floordown,		/*����������˶����ҵ��ݿ�
��*/
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
//����ߵ��ݵ���󣬶����´�ֵ�����ӦԪ������
				{
					floordown[lcfloor-1]=0;
					
					lmust[lcfloor-1]=0;

				}
                        if(*rtofloor==0)				//���ұߵ�
				{							
//���������ڵ�ǰλ�ÿ��ŵ����
					floorup[rcfloor-1]=0;
					rmust[rcfloor-1]=0;
					floordown[rcfloor-1]=0;
				}
			
			for(i=0;i<8;i++)
				{
					if(rmust[i]==i+1)				
//�ҵ��ݵ�i+1�����˳�
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


void lStoprStop(int*floorup,int*floordown,		/*����ݿ��У��ҵ��ݿ���*/
		int*lmust,int*rmust,
		int lcfloor,int rcfloor,
		int*laction,int*raction,
		int*ltofloor,int*rtofloor,
		int *lt,int *rt)
{
	int i;
	if((*laction==0)&&(*raction==0))
		{
                       if(*ltofloor==0)				//����ߵ�
		
				{							
//���������ڵ�ǰλ�ÿ��ŵ����
					floorup[lcfloor-1]=0;
					
					lmust[lcfloor-1]=0;
					floordown[lcfloor-1]=0;
					
				}
			if(*rtofloor==0)				//���ұߵ�
				{							
//���������ڵ�ǰλ�ÿ��ŵ����
					floorup[rcfloor-1]=0;
					
					rmust[rcfloor-1]=0;
					floordown[rcfloor-1]=0;
					
				}
			if(lcfloor<rcfloor)			//�����
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
		//����ݵ�i+1�����˳�                                   break;
								}
					for(i=0;i<=8;i++)
							if(rmust[i]==i+1)		
	////�ҵ��ݵ�i+1�����˳�
								{
									*rt=i+1;
									break;
								}
				}
			if(lcfloor>=rcfloor)		//��������ҵ��������ͬ��
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
		//����ݵ�i+1�����˳�
								{
								       *lt=i+1;
									break;
								}
					for(i=0;i<=8;i++)
							if(rmust[i]==i+1)		
		//�ҵ��ݵ�i+1�����˳�
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
	if((*liftin)!=0)		//���ݵ��������ѡ�е�¥����
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
	if((*liftout)!=0)		//���ݵ������ڵ�ѡ�е�¥����
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
	