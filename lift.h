void lUprUp(int*floorup,			/*����������˶����ҵ��������˶�*/	
		
		int*lmust,int*rmust,
		int lcfloor,int rcfloor,
		int*laction,int*raction,
		int*ltofloor,int*rtofloor,
		int *lt,int *rt);
void lUprDown(int*floorup,int*floordown,
		int*lmust,int*rmust,
		int lcfloor,int rcfloor,
		int*laction,int*raction,
		int*ltofloor,int*rtofloor,
		int *lt,int *rt);
void lDownrUp(int*floorup,int*floordown,			/*����������˶���
                                                                                   �ҵ��������˶�*/
		
		int*lmust,int*rmust,
		int lcfloor,int rcfloor,
		int*laction,int*raction,
		int*ltofloor,int*rtofloor,
		int *lt,int *rt);
void lDownrDown(int*floordown,			/*����������˶����ҵ��������˶�*/
		int*lmust,int*rmust,
		int lcfloor,int rcfloor,
		int*laction,int*raction,
		int*ltofloor,int*rtofloor,
		int *lt,int *rt);
void lStoprUp(int*floorup,int*floordown,			/*����ݿ��У��ҵ�
�������˶�*/
		int*lmust,int*rmust,
		int lcfloor,int rcfloor,
		int*laction,int*raction,
		int*ltofloor,int*rtofloor,
		int *lt,int *rt);
void lStoprDown(int*floorup,int*floordown,
		int*lmust,int*rmust,
		int lcfloor,int rcfloor,
		int*laction,int*raction,
		int*ltofloor,int*rtofloor,
		int *lt,int *rt);
void lUprStop(int*floorup,int*floordown,			/*����������˶���
�ҵ��ݿ���*/
		int*lmust,int*rmust,
		int lcfloor,int rcfloor,
		int*laction,int*raction,
		int*ltofloor,int*rtofloor,
		int *lt,int *rt);
void lDownrStop(int*floorup,int*floordown,		/*����������˶����ҵ��ݿ�
��*/
		int*lmust,int*rmust,
		int lcfloor,int rcfloor,
		int*laction,int*raction,
		int*ltofloor,int*rtofloor,
		int *lt,int *rt);
void lStoprStop(int*floorup,int*floordown,		/*����ݿ��У��ҵ��ݿ���*/
		int*lmust,int*rmust,
		int lcfloor,int rcfloor,
		int*laction,int*raction,
		int*ltofloor,int*rtofloor,
		int *lt,int *rt);

void transferfloor(int*liftin,int*liftout,
		int ltotalpeople, int rtotalpeople,
		int*floorup,int*floordown,
		int*lmust,int*rmust,enum direct direction[]);

void design(int*floorup,int*floordown,
		
		int*lmust,int*rmust,
		int lcfloor,int rcfloor,
		int*laction,int*raction,
		int*ltofloor,int*rtofloor,int*lltofloor,int*rrtofloor);
void ldooron_off(int *li,int *lj,int *lopen,int *lclose,int lt,int *lti);
void rdooron_off(int *ri,int *rj,int *ropen,int *rclose,int rt,int *rti);