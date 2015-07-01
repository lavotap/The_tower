#include"game_define.h"

#ifndef _GRAPH_
#define _GRAPH_

class graph
{
private:
short (*gr)[N];

public:
graph();
~graph();

short initgraph(short a[][N]);

short read(short x,short y);
short drawgraph();
short drawonly(short lev);
short changepot(short x,short y,short b);
short findpot(short pot);
short clearpot(short pot);
short sortpot();
};

#include"graphdef.h"

#endif
