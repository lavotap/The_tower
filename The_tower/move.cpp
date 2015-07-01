#include"./tools/tools.h"
#include"./tools/traps.h"

short move()
{
char mv=mygetch();
if(mv=='w'||mv=='s'||mv=='a'||mv=='d')
	{
	switch(mv)
		{
		case 'w':xp=x_pot-1;yp=y_pot;ww++;break;
		case 's':xp=x_pot+1,yp=y_pot;ss++;break;
		case 'a':xp=x_pot;yp=y_pot-1;aa++;break;
		case 'd':xp=x_pot;yp=y_pot+1;dd++;break;
		}
	short num=graphs[curlevel].read(xp,yp);
	if(num==0||num>=250)
		{
		x_pot=xp;
		y_pot=yp;
		}
	return num;
	}
else 
	{
	if(mv=='m'||mv=='f'||mv=='c')
		{
		switch(mv)
			{
			case 'm':usemymap();break;
			case 'f':usemyfly();break;
			case 'c':usemycheck();break;
			}
		return 0;
		}
	else
		{
		if(mv=='q')
			{
			ifend=3;//结束标志
			return 0;
			}
		else if(mv=='h')
			{
			CLEAR;
			cout<<BLUE<<" 操作: "<<endl
			<<" 	按w向上,s向下,a向左,d向右,h帮助,q退出. "<<endl
			<<" 	m使用地图,c使用查看怪物属性工具,f使用飞行工具. "<<endl
			<<GREEN<<" 命名规则: "<<endl
			<<"	字母+数字为普通怪物,JK和DF是护卫,BS是boss. "<<endl
			<<"	HH为墙壁,XX为栅栏,[]为门,><是入口,<>是出口. "<<endl
			<<"	ky,kb,kr,kg,ki分别是黄、蓝、红、绿、铁钥匙. "<<endl
			<<"	#为加life,$为加money,!为加attack,&为加defence;S是小瓶,M是大瓶,L是特大奖励. "<<endl
			<<"	SS,SM,SL,OM,OL,OB是商店.AN,TE是帮助者,提供道具和游戏信息. "<<endl
			<<"	FY,KN是道具，具体使用请看操作. "<<COLEND<<endl;
			cout<<endl<<endl<<"Press anykey to continue... "<<endl;
			mygetch();
			return 1;
			}
		else return 0;
		}
	}
}


