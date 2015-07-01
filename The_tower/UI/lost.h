/* 失败界面 */

#ifndef _LOST_
#define _LOST_

short lost()
{
CLEAR;
cout
<<BLUE<<" The MONSTER -- "<<endl
<<"     HAHAHAHA----"<<endl
<<"     You are loser!!! "<<endl
<<"     Never can you get your PRINCESS!!! "<<endl
<<RED" Herobrine -- "<<endl
<<COLEND<<endl
<<"You have win the game, "<<endl
<<"Press anykey to continue... "<<endl;
mygetch();
return 0;
}

#endif
