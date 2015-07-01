/* 人物设定 */

#include"game_define.h"

#ifndef _FIGUREDEF_
#define _FIGUREDEF_

/******************* hero *********************/

hero::hero()
{
strcpy(name,"Herobrine");
life=1000;
exp=0;
rank=1;
money=100;
attack=500;
defence=500;
short i;
for(i=0;i<5;i++)
	key[i]=0;


ifmap=iffly=0;ifthief=0;
ifcheck=0;
}

hero::~hero()
{

}

int hero::chkatt(char a)
{
switch(a)
	{
	case 'l':return life;break;
	case 'e':return exp;break;
	case 'r':return rank;break;
	case 'm':return money;break;
	case 'a':return attack;break;
	case 'd':return defence;break;

	default :break;
	}
return 1;
}

short hero::chgatt(char b,int c)
{
switch(b)
	{
	case 'l':life+=c;break;
	case 'e':exp+=c;break;
	case 'r':rank+=c;break;
	case 'm':money+=c;break;
	case 'a':attack+=c;break;
	case 'd':defence+=c;break;
	
	default :break;
	}
return 1;
}

short hero::chktool(char d)
{
switch(d)
	{
	case 'y':return key[0]; break;
	case 'b':return key[1]; break;
	case 'r':return key[2]; break;
	case 'g':return key[3]; break;
	case 'i':return key[4]; break;

	case 'm':return ifmap; break;
	case 'f':return iffly; break;
	case 'c':return ifcheck;break;
	case 't':return ifthief;break;

	default :break;
	}
return 1;
}

short hero::chgtool(char e,short f)
{
switch(e)
	{
	case 'y':key[0]+=f; break;
	case 'b':key[1]+=f; break;
	case 'r':key[2]+=f; break;
	case 'g':key[3]+=f; break;
	case 'i':key[4]+=f; break;

	case 'm':ifmap+=f; break;
	case 'f':iffly+=f; break;
	case 'c':ifcheck+=f;break;
	case 't':ifthief+=f;break;

	default :break;
	}
return 1;
}

hero herobrine;

/******************* monster *********************/

monster::monster()
{
attr=NULL;
}
monster::~monster()
{

}

short monster::chginit(int *a)
{
attr=a;
return 1;
}

int monster::chkatt(char f)
{
switch(f)
	{
	case 'l':return attr[0];break;//life
	case 'r':return attr[1];break;//rank
	case 'm':return attr[2];break;//addmoney
	case 'a':return attr[3];break;//attack
	case 'd':return attr[4];break;//defence

	default :break;
	}
return 1;
}
short monster::chgatt(char g,int h)
{
switch(g)
	{
	case 'l':attr[0]+=h;break;
	case 'r':attr[1]+=h;break;
	case 'm':attr[2]+=h;break;
	case 'a':attr[3]+=h;break;
	case 'd':attr[4]+=h;break;
	
	default :break;
	}
return 1;
}

monster monsters[100];// 注意monster分配的是100～199,要减100

#endif
