# The_tower
The tower is a RPG game writen by C Plus Plus.

# 游戏说明
用C++编写的魔塔类RPG游戏,使用简单的控制台(Linux tty)界面.<br/>
##操作:<br/> 
按'w'向上,'s'向下,'a'向左,'d'向右,'h'帮助,'q'退出.<br/> 
按'm'使用地图,按'c'使用查看怪物属性工具,按'f'使用飞行工具.<br/>
 
##命名规则: <br/>
'字母+数字'为普通怪物,'JK'和'DF'是护卫,'BS'是BOSS;<br> 
'HH'为墙壁,'XX'为栅栏,'[]'为门,'><'是入口,'<>'是出口;<br/>
'ky','kb','kr','kg','ki'分别是黄,蓝,红,绿,铁钥匙;<br/>
'#'为加life,'$'为加money,'!'为加attack,'&'为加defence;'S'是小瓶,'M'是大瓶,'L'是特大奖励;<br/> 
'SS','SM','SL','OM','OL','OB'是商店.'AN','TE'是天使和小偷(帮助者),提供道具和游戏信息.<br/>
'FY','KN'是道具,具体使用请看操作.

#游戏编译环境
1.Linux;<br/>
2.gcc或其他C++编译器.<br/>

#游戏编译
1.$ cd game_path/The_tower
2.$ g++ -o game game.cpp

#游戏原理说明
##编号分配
###0～19分配给地图上可以显示的项目:
	0分配给道路,1分配给墙壁,2分配给herobrine;<br/>
	3,4,5分配给普通门(普通钥匙),6分配给绿门(特殊钥匙),7分配给铁门(4把钥匙开门);<br/>
	8分配给栅栏;9分配给253特殊陷阱出口;<br/>
	10分配给小商店(加life,attack,defence),11分配给中商店,12分配给大商店,13分配给老头(加life,attack&defence,exp),14分配给太婆(加key),15分配给小偷(得到绿钥匙,打通24层),16分配给仙子,得到0层钥匙;17分配给old big(加更多经验);<br/>
	18分配给入口,19分配给出口.<br/>

###100~199分配给各个monster figures:
	100(monsters[0])为boss;<br/>
	101,102(monsters[1],monsters[2])为特殊兵种,减血一半,101为boss护卫.<br/>

###200~249分配给道具:
	200～209分配给加life;<br/>
	210～219分配给加money;<br/>
	220~229分配给加attack;<br/>
	230~239分配给加defence;<br/>
	240,241,242,243,244加key,247得到fly(到任意一层),249得到小刀(小偷).<br/>

###250～299分配给陷阱:
	250为四周出现102,251为上方栅栏,252为井字陷阱,253为26(半层)入口,254为出口.


##文件列表:
./draft:场景布局的草稿文件,包括draft_source,draft两个文件,最终生成graphinit.h;<br/>
./tools:工具类,包括tools.h,traps.h两个文件,分别为道具定义和陷阱定义;<br/>
./tools/def:定义类,包括game_define.h,figuredef.h,figure.h,graphdef.h,graph.h五个文件,定义了游戏全局变量,人物类,场景类;<br/>
./tools/def/init:初始化类,包括graphinit.h,monsterinit.h两个文件,初始化了场景和怪物数据使其可以直接被游戏程序读取;<br/>
./tools/def/lib:库文件,包括mygetch.h,提供Linux下的getch()函数;<br/>
./UI:界面类,包括welcome.h,win.h,lost.h,提供欢迎界面,胜利界面,失败界面;<br/>
judgement.cpp:商店,帮助者提供购买项目和特殊道具;<br/>
judge.cpp:判断越界,输赢等;<br/>
move.cpp:人物移动;<br/>
game.cpp:游戏主程序.

#作者
Lavotap(liujiapple@hotmail.com)


