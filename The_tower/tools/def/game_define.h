#ifndef _GAME_DEFINE_
#define _GAME_DEFINE_

#define CLEAR system("clear")

#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<iomanip>
#include<time.h>
#include"./lib/mygetch.h"

#define BACK "\033[8m"
#define BLUE "\033[34m"
#define RED  "\033[31m"
#define GREEN  "\033[32m"
#define YELLOW  "\033[33m"
#define WHITE  "\033[37m"
#define COLEND  "\033[0m"


using namespace std;

const short L=25;// level
const short M=15,N=15;

short x_pot=1,y_pot=7;// herobrine point
short xp=0,yp=0;// 临时point 

short curlevel=0;// current level 0~24
short maxlevel=0;//the hightest level reached 0~24
short trapdlevel=0;//trap D 的所在层

#include"./init/monsterinit.h"// inmo[100][5]
#include"./init/graphinit.h"//ingr[26][15][15]

short numing[20]={0};// graphdef.h 记录每一层的monster种类

int  ww=1,ss=1,aa=1,dd=1;// 随机数种子

short ifend=0;//判断游戏结束,1正常结束，2生命值少：

short nangel=0,nthief=0;//见到helper的次数

char control[100]=" 欢迎来到魔塔!按w向上;s向下;a向左;d向右;q退出.具体帮助请按h... ";

#endif
