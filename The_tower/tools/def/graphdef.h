/* 场景设定 */

#include"game_define.h"

#ifndef _GRAPHDEF_
#define _GRAPHDEF_


graph::graph()
{
gr=NULL;
}

graph::~graph()
{

}

/******************* 读取对应坐标值 ***********************/

short graph::read(short x,short y)
{
return gr[x][y];
}

/******************* 初始化 ********************/

short graph::initgraph(short a[][N])
{
gr=a;
return 1;
}

/******************* 绘制场景 *********************/

short graph::drawgraph()
{
CLEAR;
if(curlevel==25)
	cout<<BLUE<<"Level: "<<trapdlevel+1<<" 1/2"<<COLEND<<endl;
else
	cout<<BLUE<<"Level: "<<curlevel+1<<COLEND<<endl;

cout<<RED"Life: "<<herobrine.chkatt('l')<<"     ";
cout<<"Money: "<<herobrine.chkatt('m')<<"     ";
cout<<"Exp: "<<herobrine.chkatt('e')<<"     ";
cout<<"Rank: "<<herobrine.chkatt('r')<<"     ";
cout<<"Attack: "<<herobrine.chkatt('a')<<"     ";
cout<<"Defence: "<<herobrine.chkatt('d')<<COLEND<<endl;

cout<<GREEN<<"Yellowkey: "<<herobrine.chktool('y')<<"/1"<<"     ";
cout<<"Bluekey: "<<herobrine.chktool('b')<<"/1"<<"     ";
cout<<"Redkey: "<<herobrine.chktool('r')<<"/1"<<"     ";
cout<<"Greenkey: "<<herobrine.chktool('g')<<"/1"<<"     ";
cout<<"Ironkey: "<<herobrine.chktool('i')<<"/4"<<COLEND<<endl;


short i,j;
for(i=0;i<M;i++)
	{
	cout<<"			";
	for(j=0;j<N;j++)
		{
		if(i==x_pot&&j==y_pot)
			{
			cout<<BLUE" *"RED"!"COLEND;
			}
		else
			{
			if(gr[i][j]>=0&&gr[i][j]<100)
				{
				switch(gr[i][j])
					{
					case 0:cout<<"   ";break;
					case 1:cout<<" HH";break;
					case 3:cout<<YELLOW" []"COLEND;break;
					case 4:cout<<BLUE" []"COLEND;break;
					case 5:cout<<RED" []"COLEND;break;
					case 6:cout<<GREEN" []"COLEND;break;
					case 7:cout<<" []";break;
					case 8:cout<<" XX";break;
					case 9:cout<<BLUE" <>"COLEND;break;
					case 18:cout<<BLUE" ><"COLEND;break;
					case 19:cout<<BLUE" <>"COLEND;break;
					case 10:cout<<RED" SS"COLEND;break;
					case 11:cout<<RED" SM"COLEND;break;
					case 12:cout<<RED" SL"COLEND;break;
					case 13:cout<<RED" OM"COLEND;break;
					case 14:cout<<RED" OL"COLEND;break;
					case 15:cout<<RED" AN"COLEND;break;
					case 16:cout<<RED" TE"COLEND;break;
					case 17:cout<<RED" OB"COLEND;break;

					default:break;
					}
				}
			else if(gr[i][j]>=100&&gr[i][j]<200)
				{
				if(gr[i][j]==100) cout<<BLUE" BS"COLEND;
				else if(gr[i][j]==101) cout<<GREEN" DF"COLEND;
				else if(gr[i][j]==102) cout<<YELLOW" JK"COLEND;
				else
					{
					switch((gr[i][j]-100)/10)
						{
						case 0:cout<<RED" A"COLEND;break;
						case 1:cout<<RED" B"COLEND;break;
						case 2:cout<<RED" C"COLEND;break;
						case 3:cout<<RED" D"COLEND;break;
						case 4:cout<<RED" E"COLEND;break;
						case 5:cout<<RED" F"COLEND;break;
						case 6:cout<<RED" G"COLEND;break;
						case 7:cout<<RED" H"COLEND;break;
						case 8:cout<<RED" I"COLEND;break;
						case 9:cout<<RED" J"COLEND;break;
						default:break;
						}
					switch((gr[i][j]-100)%10)
						{
						case 0:cout<<GREEN"0"COLEND;break;
						case 1:cout<<GREEN"1"COLEND;break;
						case 2:cout<<GREEN"2"COLEND;break;
						case 3:cout<<GREEN"3"COLEND;break;
						case 4:cout<<GREEN"4"COLEND;break;
						case 5:cout<<GREEN"5"COLEND;break;
						case 6:cout<<GREEN"6"COLEND;break;
						case 7:cout<<GREEN"7"COLEND;break;
						case 8:cout<<GREEN"8"COLEND;break;
						case 9:cout<<GREEN"9"COLEND;break;
						default:break;
						}
					}
				}
			else if(gr[i][j]>=200&&gr[i][j]<250)
				{
				switch(gr[i][j])
					{
					case 200:cout<<GREEN" #S"COLEND;break;
					case 201:cout<<GREEN" #M"COLEND;break;
					case 202:cout<<GREEN" #L"COLEND;break;
					case 210:cout<<YELLOW" $S"COLEND;break;
					case 211:cout<<YELLOW" $L"COLEND;break;
					case 220:cout<<RED" !S"COLEND;break;
					case 221:cout<<RED" !M"COLEND;break;
					case 222:cout<<RED" !L"COLEND;break;
					case 230:cout<<BLUE" &S"COLEND;break;
					case 231:cout<<BLUE" &M"COLEND;break;
					case 232:cout<<BLUE" &L"COLEND;break;
					case 240:cout<<YELLOW" ky"COLEND;break;
					case 241:cout<<BLUE" kb"COLEND;break;
					case 242:cout<<RED" kr"COLEND;break;
					case 243:cout<<GREEN" kg"COLEND;break;
					case 244:cout<<" ki";break;
					case 247:cout<<RED" F"GREEN"Y"COLEND;break;
					case 249:cout<<BLUE" K"GREEN"N"COLEND;break;
					default:break;
					}
				}
			else
				cout<<"   ";

			}
		}
	cout<<endl;
	}

cout<<endl<<" 控制台信息(按 h 显示帮助信息): "<<endl;
cout<<"     "<<control;
return 1;
}

/******************** 仅绘制编号20以下的物体 **************************/

short graph::drawonly(short lev)
{
CLEAR;

cout<<GREEN<<"***** W 为墙壁,D 为门,E 为入口,O 为出口,S 为商店,H 为帮助者,K为钥匙 *****"<<endl<<COLEND;
cout<<BLUE<<endl<<"			"<<"Level- "<<lev+1<<endl<<COLEND;

short i,j;
for(i=0;i<M;i++)
	{
	cout<<"			";
	for(j=0;j<N;j++)
		{
		
		if(lev==curlevel&&i==x_pot&&j==y_pot)
				cout<<" *";// *显示heribrine位置
		else
			{
			if(gr[i][j]>=0&&gr[i][j]<20)
				{
				switch(gr[i][j])
					{
					case 0:cout<<"  ";break;
					case 1:cout<<" W";break;
					case 3:cout<<YELLOW" D"COLEND;break;
					case 4:cout<<BLUE" D"COLEND;break;
					case 5:cout<<RED" D"COLEND;break;
					case 6:cout<<GREEN" D"COLEND;break;
					case 7:cout<<" D";break;
					case 9:cout<<BLUE" O"COLEND;break;
					case 18:cout<<BLUE" E"COLEND;break;
					case 19:cout<<BLUE" O"COLEND;break;
					case 10:cout<<RED" S"COLEND;break;
					case 11:cout<<RED" S"COLEND;break;
					case 12:cout<<RED" S"COLEND;break;
					case 13:cout<<RED" S"COLEND;break;
					case 14:cout<<RED" S"COLEND;break;
					case 15:cout<<RED" H"COLEND;break;
					case 16:cout<<RED" H"COLEND;break;
					case 17:cout<<RED" S"COLEND;break;

					default:break;
					}
				}
			else
				{
				if(gr[i][j]>=240&&gr[i][j]<=244)
					{
					switch(gr[i][j])
						{
						case 240:cout<<YELLOW" K"COLEND;break;
						case 241:cout<<BLUE" K"COLEND;break;
						case 242:cout<<RED" K"COLEND;break;
						case 243:cout<<GREEN" K"COLEND;break;
						case 244:cout<<" K";break;
						default:break;
						}
					}
				else
					cout<<"  ";
				}
			}
		}
	cout<<endl;
	}


return 1;
}

/******************** 更改坐标x,y的值为b **********************/

short graph::changepot(short x,short y,short b=0)
{
gr[x][y]=b;
}

/******************** 找到对应点 ***********************/

short graph::findpot(short pot)
{
short i,j;
for(i=0;i<M;i++)
	for(j=0;j<N;j++)
		{
		if(gr[i][j]==pot)
		{xp=i;yp=j;}
		}
return 1;
}

/******************* 清除本层场景中所有为pot的值为0 *********************/

short graph::clearpot(short pot)
{
short i,j;
for(i=0;i<M;i++)
	for(j=0;j<N;j++)
		{
		if(gr[i][j]==pot)
		gr[i][j]=0;
		}
return 1;
}

/******************* 找出本层场景中所有不同的值，并记录在numing[]中 *********************/

short graph::sortpot()// 找出graph中100~199(monster类型)不同类型的数,即找出所有种类的monster
{
short i,j,m;
for(i=0;i<M;i++)
	for(j=0;j<N;j++)
		{
		if(gr[i][j]>=100&&gr[i][j]<200)
			{
			short n=0;
			for(m=0;m<20;m++)
				if(numing[m]==gr[i][j]) n++;// 判断numing[]中是否已经存有这个种类了
			if(n==0)
				{
				short k=0,chk=0;
				do
					{
					if(numing[k]==0)
						{
						numing[k]=gr[i][j];
						chk++;
						}
					k++;
					}while(chk==0);
				}
			}
		}
return 1;
}

short clearnuming()// 使用sortpot函数后一定要将numing[]清零!!
{
short i;
for(i=0;i<20;i++)
numing[i]=0;
}

graph graphs[26];

#endif
