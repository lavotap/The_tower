/* 工具及使用 */

#include"./def/game_define.h"
#include"./def/figure.h"
#include"./def/graph.h"

#ifndef _TOOLS_
#define _TOOLS_

/********************** MAP ***********************/

short usemymap()// 不能查看特殊层26,作陷阱使用
{
CLEAR;

short chkif=herobrine.chktool('m');// 检查能否使用MAP
if(chkif==1)
	{
	short lev;
	cout<<" 请输入要在地图上查找的层数(1~24); "<<endl<<" 按 0 退出地图: ";
	cin>>lev;mygetch();// 输入楼层
	
	if(lev==0) return 0;
	else if(lev>=1&&lev<=24)
		{
		--lev;
		char chkend;

		do{
			if(lev>=0&&lev<24)// 检查越程
				{
				
				(graphs+lev)->drawonly(lev);// "graph.h"
				cout<<endl<<" 按 w 向上一级查看，按 s 向下一级查看; "<<endl<<" 按 q 退出地图: "<<endl;;
				chkend=mygetch();
				switch(chkend)
					{
					case 'w':lev++;break;
					case 's':lev--;break;
					case 'q':break;
	
					default:break;
					}
				}
			else
				{
				cout<<endl<<lev+1<<" 层不在地图上！ "<<endl<<"Press anykey to continue...";
				mygetch();
				return 0;
				}
		}while(chkend!='q');
		return 1;
		}
	}

else
	{
	cout<<" 地图不在你的工具箱中，现在无法使用! "<<endl<<"Press anykey to continue...";
	mygetch();
	return 0;
	}
}

/******************** FLY *********************/

short usemyfly()
{
CLEAR;

short chkif=herobrine.chktool('f');// 检查能否使用FLY
if(curlevel!=24&&chkif==1)
	{
	short lev;
	cout<<" 请输入你要去的层数(1~"<<maxlevel+1<<"); "<<endl<<" 按 0 退出飞行工具: ";
	cin>>lev;mygetch();
	if(lev==0) return 0;
	--lev;
	if(lev==0)
		{
		x_pot=1;y_pot=7;
		curlevel=0;
		return 1;
		}
	if(lev>0&&lev<=maxlevel)
		{
		(graphs+lev)->findpot(18);
		x_pot=xp;y_pot=yp;
		curlevel=lev;
		return 1;
		}
	else
		{
		cout<<" 你不能去 "<<lev+1<<"! 你还没达到这一层，或这一层不存在... "<<endl<<"Press anykey to continue...";
		mygetch();
		return 0;
		}
	}
else if(curlevel==24)
	{
	cout<<" 你现在已经到达第25层，不再需要飞行工具了. "<<endl<<"Pess anykey to continue...";
	mygetch();
	}

else
	{
	cout<<" 飞行工具不在你的工具箱中，现在无法使用! "<<endl<<"Press anykey to continue...";
	mygetch();
	return 0;
	}
}

/******************** CHECK **********************/

short usemycheck()
{
CLEAR;

short chkif=herobrine.chktool('c');
if(chkif==1)
	{
	cout<<"***** 怪物属性 *****"<<endl;
	cout<<setw(10)<<"Name"<<setw(10)<<"Life"<<setw(10)<<"Rank"<<setw(10)<<"Attack"<<setw(10)<<"Defence"<<endl;
	(graphs+curlevel)->sortpot();//将本楼层的monster类型记录在numing[]中
	short num=0;
	while(numing[num]!=0)//读取numing[]的记录
		{
		short n=numing[num]-100;
		char name[3];

		if(n==0) strcpy(name,"BS");
		else if(n==1) strcpy(name,"DF");
		else if(n==2) strcpy(name,"JK");
		else
			{
			switch(n/10)
				{
				case 0:name[0]='A';break;
				case 1:name[0]='B';break;
				case 2:name[0]='C';break;
				case 3:name[0]='D';break;
				case 4:name[0]='E';break;
				case 5:name[0]='F';break;
				case 6:name[0]='G';break;
				case 7:name[0]='H';break;
				case 8:name[0]='I';break;
				case 9:name[0]='J';break;
				default:break;
				}
			switch(n%10)
				{
				case 0:name[1]='0';break;
				case 1:name[1]='1';break;
				case 2:name[1]='2';break;
				case 3:name[1]='3';break;
				case 4:name[1]='4';break;
				case 5:name[1]='5';break;
				case 6:name[1]='6';break;
				case 7:name[1]='7';break;
				case 8:name[1]='8';break;
				case 9:name[1]='9';break;
				default:break;
				}
			name[2]='\0';
			}
					
					
					
					
		int life=(monsters+n)->chkatt('l');
		int rank=(monsters+n)->chkatt('r');
		int attack=(monsters+n)->chkatt('a');
		int defence=(monsters+n)->chkatt('d');
		cout<<setw(10)<<name<<setw(10)<<life<<setw(10)<<rank<<setw(10)<<attack<<setw(10)<<defence<<endl;
		num++;
		};

	cout<<"Press anykey to continue...";
	mygetch();

	clearnuming();//清零numing[]
	return 1;
	}
else
	{
	cout<<" 查看怪物属性工具不在你的工具箱中，现在无法使用! "<<endl<<"Press anykey to continue...";
	mygetch();
	return 0;
	}
}

#endif
