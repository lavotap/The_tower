/* 胜利界面 */

#ifndef _WIN_
#define _WIN_

short win()
{
CLEAR;
cout
<<BLUE<<" The MONSTER -- "<<endl
<<"     Oh,no----"<<endl
<<"     It is impossible!!! "<<endl
<<"     PRINCESS is here,please let me go!!! "<<endl
<<RED" Herobrine -- "<<endl
<<COLEND<<endl
<<"You have win the game, "<<endl
<<"Press anykey to continue... "<<endl;
mygetch();
return 1;
}

#endif
