#include"move.cpp"
#include"judge.cpp"
#include"./UI/welcome.h"
#include"./UI/win.h"
#include"./UI/lost.h"
int main()
{
short i;

for(i=0;i<26;i++)
	graphs[i].initgraph(ingr[i]);

for(i=0;i<100;i++)
	monsters[i].chginit(inmo[i]);

welcome();// 欢迎界面

short chk=0;
do
	{
	if(curlevel==24&&chk==0)
		{
		chk++;
		herobrine.chgtool('i',-herobrine.chktool('i'));
		}
	graphs[curlevel].drawgraph();
	short mvent=move();
	judge(mvent);
	if(herobrine.chkatt('l')<=0)
		ifend=2;
	}while(ifend==0);

if(ifend==1)
	win();
if(ifend==2)
	lost();

return 1;
}
