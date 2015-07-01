#include"./tools/tools.h"
#include"./tools/traps.h"
#include"judgement.cpp"

short fightwith(monster *mons)
{
short ran=ww+2*ss+3*aa+4*dd;
srand(ran*(unsigned)time(NULL));
float rfight=(rand()%1000+9500)/10000.0;
float rmoney=(rand()%2000+9000)/10000.0;
float rexp=(rand()%3000+8500)/10000.0;
float ra=(rand()%2800+8600)/10000.0;
float rd=(rand()%3200+8400)/10000.0;

double multi;
multi=(3/4.0*((mons->chkatt('r'))/((herobrine.chkatt('r'))*1.0))+1/8.0*((mons->chkatt('a'))/((herobrine.chkatt('d'))*1.0))+1/8.0*((mons->chkatt('d'))/((herobrine.chkatt('a'))*1.0)))*rfight;

if(herobrine.chkatt('l')>mons->chkatt('l')*multi)
	{
	herobrine.chgatt('l',int(-(mons->chkatt('l')*0.55*multi)));
	herobrine.chgatt('a',int(mons->chkatt('r')*0.15*ra));
	herobrine.chgatt('d',int(mons->chkatt('r')*0.15*rd));
	herobrine.chgatt('m',int(mons->chkatt('m')*0.45*rmoney));
	herobrine.chgatt('e',int(mons->chkatt('m')*0.35*rexp));
	return 1;
	}
else
	return 0;

}

short judge(short a)
{
if(a>=0&&a<20)
	{
	switch(a)
		{
		case 0:return 0;break;//道路
		case 1:return 0;break;//墙壁
		case 8:return 0;break;//栅栏

		case 3:if(herobrine.chktool('y')>0)// yellow door
			{
			herobrine.chgtool('y',-1);
			graphs[curlevel].changepot(xp,yp,0);
			
			break;
			}
			else
			{
			strcpy(control," You need a yellow key. ");
			break;
			}

		case 4:if(herobrine.chktool('b')>0)// blue door
			{
			herobrine.chgtool('b',-1);
			graphs[curlevel].changepot(xp,yp,0);
			
			break;
			}
			else
			{
			strcpy(control," You need a blue key. ");
			break;
			}

		case 5:if(herobrine.chktool('r')>0)// red door
			{
			herobrine.chgtool('r',-1);
			graphs[curlevel].changepot(xp,yp,0);
			
			break;
			}
			else
			{
			strcpy(control," You need a red key. ");
			break;
			}

		case 6:if(herobrine.chktool('g')>0)// green door
			{
			herobrine.chgtool('g',-1);
			graphs[curlevel].changepot(xp,yp,0);
			
			break;
			}
			else
			{
			strcpy(control," You need a green key. ");
			break;
			}

		case 7:if(herobrine.chktool('i')>=4)// iron door (need 4keys)
			{
			herobrine.chgtool('i',-4);
			graphs[curlevel].changepot(xp,yp,0);
			
			break;
			}
			else
			{
			strcpy(control," You need four iron keys. ");
			break;
			}

		case 9:trapdout();break;// trapD 253
		case 10:asksmashop();break;// small shop
		case 11:askmidshop();break;// middle shop
		case 12:asklarshop();break;// large shop
		case 13:askoldman();break;// old man
		case 14:askoldlady();break;// old lady
		case 16:askthief();break;// thief
		case 15:askangel();break;// angel
		case 17:askoldbig();break;//oldbig
		case 18:enter();break;// 入口
		case 19:exit();break;// 出口

		default:break;
		}
	return 1;
	}

if(a==100)
	{
	short ans=fightwith(monsters);
	if(ans==1)
		ifend=1;
	else
		ifend=2;
	return 2;
	}

if(a>100&&a<200)
	{
	if(a==101||a==102)// 101 102特殊兵种减血1/3
		herobrine.chgatt('l',int(-(herobrine.chkatt('l'))*1/3));

	short ans=fightwith(monsters+(a-100));
	if(ans==1)
		{
		strcpy(control," Win! ");
		graphs[curlevel].changepot(xp,yp,0);
		
		}
	else
		{
		//graphs[curlevel].findpot(18);
		//x_pot=xp;y_pot=yp;

		herobrine.chgatt('l',-5*herobrine.chkatt('r'));
		herobrine.chgatt('m',5*herobrine.chkatt('r'));
		
		strcpy(control," Fail! ");
		}
	return 2;
	}

if(a>=200&&a<250)
	{
	switch(a)
		{
		case 200:herobrine.chgatt('l',100);
			
			strcpy(control," Life +100. ");
			graphs[curlevel].changepot(xp,yp,0);break;

		case 201:herobrine.chgatt('l',500);
			
			strcpy(control," Life +500. ");
			graphs[curlevel].changepot(xp,yp,0);break;

		case 202:herobrine.chgatt('l',herobrine.chkatt('l')*10);
			
			strcpy(control," Life ×10. ");
			graphs[curlevel].changepot(xp,yp,0);break;

		case 210:herobrine.chgatt('m',10);
			
			strcpy(control," Gold coin +10. ");
			graphs[curlevel].changepot(xp,yp,0);break;

		case 211:herobrine.chgatt('m',50);
			
			strcpy(control," Gold coin +50. ");
			graphs[curlevel].changepot(xp,yp,0);break;

		case 220:herobrine.chgatt('a',100);
			
			strcpy(control," Attack +100. ");
			graphs[curlevel].changepot(xp,yp,0);break;

		case 221:herobrine.chgatt('a',300);
			
			strcpy(control," Attack +300. ");
			graphs[curlevel].changepot(xp,yp,0);break;

		case 222:herobrine.chgatt('a',800);
			
			strcpy(control," Attack +800. ");
			graphs[curlevel].changepot(xp,yp,0);break;

		case 230:herobrine.chgatt('d',100);
			
			strcpy(control," Defence +100. ");
			graphs[curlevel].changepot(xp,yp,0);break;

		case 231:herobrine.chgatt('d',300);
			
			strcpy(control," Defence +300. ");
			graphs[curlevel].changepot(xp,yp,0);break;

		case 232:herobrine.chgatt('d',800);
			
			strcpy(control," Defence +800. ");
			graphs[curlevel].changepot(xp,yp,0);break;

		case 240:herobrine.chgtool('y',1);
			
			strcpy(control," Get a yellow key. ");
			graphs[curlevel].changepot(xp,yp,0);break;

		case 241:herobrine.chgtool('b',1);
			
			strcpy(control," Get a blue key. ");
			graphs[curlevel].changepot(xp,yp,0);break;

		case 242:herobrine.chgtool('r',1);
			
			strcpy(control," Get a red key. ");
			graphs[curlevel].changepot(xp,yp,0);break;

		case 243:herobrine.chgtool('g',1);
			
			strcpy(control," Get a green key. ");
			graphs[curlevel].changepot(xp,yp,0);break;

		case 244:herobrine.chgtool('i',1);
			
			strcpy(control,"  Get a iron key, you need 4 iron keys to open a iron door. ");
			graphs[curlevel].changepot(xp,yp,0);break;

		case 246:herobrine.chgtool('m',1);
			graphs[curlevel].changepot(xp,yp,0);break;

		case 247:herobrine.chgtool('f',1);
			CLEAR;
			cout<<" Using FLY tool to fly to any levels, press 'f' to use it. "<<endl<<"Press anykey to continue..."<<endl;
			mygetch();
			graphs[curlevel].changepot(xp,yp,0);break;

		case 248:herobrine.chgtool('c',1);
			graphs[curlevel].changepot(xp,yp,0);break;

		case 249:herobrine.chgtool('t',1);
			CLEAR;
			cout<<" It is the thief's knife, please give it back to him. "<<endl<<"Press anykey to continue..."<<endl;
			mygetch();
			graphs[curlevel].changepot(xp,yp,0);break;
		
		default:break;
		}
	return 3;
	}

if(a>=250)
	{
	switch(a)
		{
		case 250:trapa();break;
		case 251:trapb();break;
		case 252:trapc();break;
		case 253:trapd();break;

		default:break;
		}
	strcpy(control," Lost into the TRAP! ");
	
	return 4;
	}
else
	return 0;
}

