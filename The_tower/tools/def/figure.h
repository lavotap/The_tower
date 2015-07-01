#include"game_define.h"

#ifndef _FIGURE_
#define _FIGURE_

/********************* hero ************************/

class hero
{
private:

/********** attribute ************/

char name[10];
int life;
int exp;
int rank;
int money;
int attack;
int defence;

/********** tool ************/

short key[5];// yellow,blue,red,green,iron
short ifmap;
short iffly;
short ifcheck;
short ifthief;

public:
hero();
~hero();

int chkatt(char a);
short chgatt(char b,int c);

short chktool(char d);
short chgtool(char e,short f);
};

/****************** monster *******************/

class monster
{
private:
int *attr;//life,rank,addmoney,attack,defence(addexp=60%addmoney<define in judge.cpp>);

public:
monster();
~monster();

short chginit(int *a);

int chkatt(char f);
short chgatt(char g,int h);
};

#include"figuredef.h"

#endif
