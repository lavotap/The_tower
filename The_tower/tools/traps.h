/* 陷阱布置 */

#include"./def/game_define.h"
#include"./def/figure.h"
#include"./def/graph.h"

#ifndef _TRAPS_
#define _TRAPS_

/******************* trapA num.250 ********************/

short trapa()// 使用102特殊兵种
{
(graphs+curlevel)->changepot(x_pot,y_pot+1,102);
(graphs+curlevel)->changepot(x_pot,y_pot-1,102);
(graphs+curlevel)->changepot(x_pot+1,y_pot,102);
(graphs+curlevel)->changepot(x_pot-1,y_pot,102);

(graphs+curlevel)->clearpot(250);// 使用一次后失效

return 1;
}


/****************** trapB num.251 ********************/

short trapb()// 使用8栅栏
{
short i;
for(i=1;i<N-1;i++)
	(graphs+curlevel)->changepot(x_pot-2,i,8);//将herobrine 前面变成栅栏
(graphs+curlevel)->changepot(x_pot-2,7,0);
(graphs+curlevel)->changepot(x_pot-2,6,102);//在陷阱两旁设置102兵种
(graphs+curlevel)->changepot(x_pot-2,8,102);

(graphs+curlevel)->clearpot(251);

return 1;
}

/***************** trapC num.252 ********************/

short trapc()
{
(graphs+curlevel)->changepot(x_pot-2,y_pot-2,8);
(graphs+curlevel)->changepot(x_pot-1,y_pot-2,8);
(graphs+curlevel)->changepot(x_pot-2,y_pot-1,8);
(graphs+curlevel)->changepot(x_pot-1,y_pot-3,8);
(graphs+curlevel)->changepot(x_pot-1,y_pot-4,8);
(graphs+curlevel)->changepot(x_pot-3,y_pot-1,8);
(graphs+curlevel)->changepot(x_pot-4,y_pot-1,8);

(graphs+curlevel)->changepot(x_pot+2,y_pot-2,8);
(graphs+curlevel)->changepot(x_pot+1,y_pot-2,8);
(graphs+curlevel)->changepot(x_pot+2,y_pot-1,8);
(graphs+curlevel)->changepot(x_pot+1,y_pot-3,8);
(graphs+curlevel)->changepot(x_pot+1,y_pot-4,8);
(graphs+curlevel)->changepot(x_pot+3,y_pot-1,8);
(graphs+curlevel)->changepot(x_pot+4,y_pot-1,8);

(graphs+curlevel)->changepot(x_pot-2,y_pot+2,8);
(graphs+curlevel)->changepot(x_pot-1,y_pot+2,8);
(graphs+curlevel)->changepot(x_pot-2,y_pot+1,8);
(graphs+curlevel)->changepot(x_pot-1,y_pot+3,8);
(graphs+curlevel)->changepot(x_pot-1,y_pot+4,8);
(graphs+curlevel)->changepot(x_pot-3,y_pot+1,8);
(graphs+curlevel)->changepot(x_pot-4,y_pot+1,8);

(graphs+curlevel)->changepot(x_pot+2,y_pot+2,8);
(graphs+curlevel)->changepot(x_pot+1,y_pot+2,8);
(graphs+curlevel)->changepot(x_pot+2,y_pot+1,8);
(graphs+curlevel)->changepot(x_pot+1,y_pot+3,8);
(graphs+curlevel)->changepot(x_pot+1,y_pot+4,8);
(graphs+curlevel)->changepot(x_pot+3,y_pot+1,8);
(graphs+curlevel)->changepot(x_pot+4,y_pot+1,8);


(graphs+curlevel)->changepot(x_pot,y_pot+2,102);
(graphs+curlevel)->changepot(x_pot,y_pot-2,102);
(graphs+curlevel)->changepot(x_pot+2,y_pot,102);
(graphs+curlevel)->changepot(x_pot-2,y_pot,102);

(graphs+curlevel)->changepot(x_pot,y_pot+3,244);
(graphs+curlevel)->changepot(x_pot,y_pot-3,244);
(graphs+curlevel)->changepot(x_pot+3,y_pot,244);
(graphs+curlevel)->changepot(x_pot-3,y_pot,244);

(graphs+curlevel)->changepot(x_pot,y_pot+4,7);
(graphs+curlevel)->changepot(x_pot,y_pot-4,7);
(graphs+curlevel)->changepot(x_pot+4,y_pot,7);
(graphs+curlevel)->changepot(x_pot-4,y_pot,7);

(graphs+curlevel)->clearpot(252);

return 1;
}


/******************** trapD num.253 *********************/

short trapd()
{
trapdlevel=curlevel;
curlevel=25;x_pot=7,y_pot=7;
return 1;
}

/******************* trapD' num.9 *********************/
short trapdout()
{
curlevel=trapdlevel;
trapdlevel=0;
(graphs+curlevel)->findpot(253);
x_pot=xp;y_pot=yp;
return 1;
}



/******************** 18入口(本层入口，进入上一层出口) **********************/

short enter()
{
curlevel--;
(graphs+curlevel)->findpot(19);
x_pot=xp,y_pot=yp;

return 1;
}

/******************** 19出口（本层出口，进入下一层入口） **********************/

short exit()
{
curlevel++;
if(maxlevel<curlevel) maxlevel=curlevel;

graphs[curlevel].findpot(18);
x_pot=xp,y_pot=yp;

return 1;
}

#endif
