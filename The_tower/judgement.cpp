/* 商店及帮助者，提供购买项目和工具 */

#include"./tools/tools.h"
#include"./tools/traps.h"

/********************** 小商店10 **********************/

short asksmashop()
{
short chkend=0;
do{
	CLEAR;
	cout<<BLUE<<"Small shop--Welcome to my shop!"<<endl;
	cout<<"Enter the number you want..."<<endl;
	cout<<endl<<"1.Pay 100 coin to add 200 life;"<<endl<<"2.Pay 100 coin to add 50 attack;"<<endl<<"3.Pay 100 coin to add 50 defence;"<<endl<<"4.quit"<<COLEND<<endl;
	short ans;
	cin>>ans;mygetch();//抵消回车
	
	if(ans>=1&&ans<=3)
		{
		int money=herobrine.chkatt('m');
		if(money>=100)
			{
			herobrine.chgatt('m',-100);
			switch(ans)
				{
				case 1:herobrine.chgatt('l',200);break;
				case 2:herobrine.chgatt('a',50);break;
				case 3:herobrine.chgatt('d',50);break;
				}
			cout<<"Successed!Press anykey to continue..."<<endl;
			mygetch();
			}
		else
			{
			chkend=1;
			cout<<"You dont have enough money!"<<endl<<"Press anykey to continue..."<<endl;
			mygetch();
			}
		}
	else
		{
		switch(ans)
			{
			case 4:chkend=1;break;
			default:break;
			}
		}
	}while(chkend==0);
return 1;
}

/********************* 中商店11 *********************/

short askmidshop()
{
short chkend=0;
do{
	CLEAR;
	cout<<BLUE<<"Middle shop--Welcome to my shop!"<<endl;
	cout<<"Enter the number you want..."<<endl;
	cout<<endl<<"1.Pay 500 coin to add 2000 life;"<<endl<<"2.Pay 500 coin to add 300 attack;"<<endl<<"3.Pay 500 coin to add 300 defence;"<<endl<<"4.quit"<<COLEND<<endl;
	short ans;
	cin>>ans;mygetch();
	
	if(ans>=1&&ans<=3)
		{
		int money=herobrine.chkatt('m');
		if(money>=500)
			{
			herobrine.chgatt('m',-500);
			switch(ans)
				{
				case 1:herobrine.chgatt('l',2000);break;
				case 2:herobrine.chgatt('a',300);break;
				case 3:herobrine.chgatt('d',300);break;
				}
			cout<<"Successed!Press anykey to continue..."<<endl;
			mygetch();
			}
		else
			{
			chkend=1;
			cout<<"You dont have enough money!"<<endl<<"Press anykey to continue..."<<endl;
			mygetch();
			}
		}
	else
		{
		switch(ans)
			{
			case 4:chkend=1;break;
			default:break;
			}
		}
	}while(chkend==0);
return 1;
}

/******************* 大商店12 *********************/

short asklarshop()
{
short chkend=0;

	CLEAR;
	cout<<BLUE<<"Large shop--Welcome to my shop!"<<endl;
	cout<<"Enter the number you want..."<<endl;

	cout<<"1.Get somthing... "<<endl<<"Sale my keys... "<<endl;
	short cho;cin>>cho;mygetch();
	if(cho==1)
		do{
		CLEAR;
		cout<<"1.Pay 800 coin to add 4000 life;"<<endl<<"2.Pay 800 coin to add 600 attack;"<<endl<<"3.Pay 800 coin to add 600 defence;"<<endl<<"4.quit"<<COLEND<<endl;
		short ans;
		cin>>ans;mygetch();
		
		if(ans>=1&&ans<=3)
			{
			int money=herobrine.chkatt('m');
			if(money>=800)
				{
				herobrine.chgatt('m',-800);
				switch(ans)
					{
					case 1:herobrine.chgatt('l',4000);break;
					case 2:herobrine.chgatt('a',600);break;
					case 3:herobrine.chgatt('d',600);break;
					}
				cout<<"Successed!Press anykey to continue..."<<endl;
				mygetch();
				}
			else
				{
				chkend=1;
				cout<<"You dont have enough money!"<<endl<<"Press anykey to continue..."<<endl;
				mygetch();
				}
			}
		else
			{
			switch(ans)
				{
				case 4:chkend=1;break;
				default:break;
				}
			}
		}while(chkend==0);


	else
		do{
		CLEAR;
		cout<<"1.Sale a yellow key for 10 coins;"<<endl<<"2.Sale a blue key for 20 coins;"<<"3.Sale a red key for 50 coins;"<<endl<<"4.quit."<<COLEND<<endl;
		short ans;
		cin>>ans;mygetch();
		switch(ans)
			{
			case 1:if(herobrine.chktool('y')>0)
					{
					herobrine.chgtool('y',-1);
					herobrine.chgatt('m',10);
					cout<<"Successed! Press anykey to continue..."<<endl;
					mygetch();
					break;
					}
				else
					{
					cout<<"You dont have any yellow keys!"<<endl<<"Press anykey to continue... "<<endl;
					mygetch();
					return 0;
					}

			case 2:if(herobrine.chktool('b')>0)
					{
					herobrine.chgtool('b',-1);
					herobrine.chgatt('m',10);
					cout<<"Successed! Press anykey to continue..."<<endl;
					mygetch();
					break;
					}
				else
					{
					cout<<"You dont have any blue keys!"<<endl<<"Press anykey to continue... "<<endl;
					mygetch();
					return 0;
					}

			case 3:if(herobrine.chktool('r')>0)
					{
					herobrine.chgtool('r',-1);
					herobrine.chgatt('m',50);
					cout<<"Successed! Press anykey to continue..."<<endl;
					mygetch();
					break;
					}
				else
					{
					cout<<"You dont have any red keys!"<<endl<<"Press anykey to continue... "<<endl;
					mygetch();
					return 0;
					}
				
			case 4:chkend=1;break;
			default:break;
			}
		
		}while(chkend==0);		
return 1;
}

/******************** 老头（加经验）13 *********************/

short askoldman()
{
short chkend=0;
do{
	CLEAR;
	cout<<BLUE<<"Old mam--What can I do for you ?"<<endl;
	cout<<"Enter the number you want..."<<endl;
	cout<<endl<<"1.Pay 200 exp to add 1500 life;"<<endl<<"2.Pay 200 exp to add 200 attack&defence;"<<endl<<"3.Pay 500 exp to add a rank;"<<endl<<"4.quit"<<COLEND<<endl;
	short ans;
	cin>>ans;mygetch();
	
	if(ans==1||ans==2)
		{
		int exp=herobrine.chkatt('e');
		if(exp>=200)
			{
			herobrine.chgatt('e',-200);
			switch(ans)
				{
				case 1:herobrine.chgatt('l',1500);break;
				case 2:herobrine.chgatt('a',200);herobrine.chgatt('d',200);break;
				}
			cout<<"Successed! Press anykey to continue..."<<endl;
			mygetch();
			}
		else
			{
			chkend=1;
			cout<<"You dont have enough experience!"<<endl<<"Press anykey to continue..."<<endl;
			mygetch();
			}
		}
	else
		{
		if(ans==3)
			{
			int exp=herobrine.chkatt('e');
			if(exp>=500)
				{
				herobrine.chgatt('e',-500);
				herobrine.chgatt('r',1);
				cout<<"Successed! Press anykey to continue..."<<endl;
				mygetch();
				}
			else
				{
				chkend=1;
				cout<<"You dont have enough experience!"<<endl<<"Press anykey to continue..."<<endl;
				mygetch();
				}
			}
		else chkend=1;
		}
	
	}while(chkend==0);
return 1;
}

/*********************** 太婆（加钥匙） ***********************/

short askoldlady()
{
short chkend=0;
do{
	CLEAR;
	cout<<BLUE<<"Old lady--What can I do for you ?"<<endl;
	cout<<"Enter the number you want..."<<endl;
	cout<<endl<<"1.Pay 100 coin to add a yellow key;"<<endl<<"2.Pay 400 coin to add a blue key;"<<endl<<"3.Pay 800 coin to add a red key;"<<endl<<"4.quit"<<COLEND<<endl;
	short ans;
	cin>>ans;mygetch();
	short money=herobrine.chkatt('m');
	switch(ans)
		{
		case 1:if(money>100)
			{
			herobrine.chgatt('m',-100);
			herobrine.chgtool('y',1);
			cout<<"Successed! Press anykey to continue..."<<endl;
			mygetch();
			}
			else
			{
			cout<<"You dont have enough money!"<<endl<<"Press anykey to continue..."<<endl;
			chkend=1;
			}
			break;
		case 2:if(money>400)
			{
			herobrine.chgatt('m',-400);
			herobrine.chgtool('b',1);
			cout<<"Successed! Press anykey to continue..."<<endl;
			mygetch();
			}
			else
			{
			cout<<"You dont have enough money!"<<endl<<"Press anykey to continue..."<<endl;
			chkend=1;
			}
			break;
		case 3:if(money>800)
			{
			herobrine.chgatt('m',-800);
			herobrine.chgtool('r',1);
			cout<<"Successed! Press anykey to continue..."<<endl;
			mygetch();
			}
			else
			{
			cout<<"You dont have enough money!"<<endl<<"Press anykey to continue..."<<endl;
			chkend=1;
			}
			break;
		case 4:
			chkend=1;break;
		}
	}while(chkend==0);

return 1;
}

/**************** 小偷 15 ******************/

short askthief()
{
if(nthief==0)
	{
	CLEAR;
	cout<<BLUE<<" Thief -- "<<endl;
	cout<<"     I have been traped here by the MONSTER, thanks for you saving me out! "<<endl<<"     I have a MONSTER HNAD BOOK, it can show monsters' attribute. Now it is yours. "<<endl<<endl<<"     Oh, yes, I have lost my knife in any level of the tower, if you find my knife and give it back to me, I can find the way fo level 24th for you. "<<endl<<"     Thank you! See you next time. "<<endl;
	cout<<RED<<" Herobrine -- "<<endl;
	cout<<"     OK. "<<endl<<COLEND;
	cout<<endl<<" Get the MONSTER HAND BOOK. "<<endl<<" Press 'c' to use it. "<<endl;
	cout<<endl<<"Press anykey to continue...";
	mygetch();
	herobrine.chgtool('c',1);
	nthief++;
	return 1;
	}
else
	{
	CLEAR;
	if(herobrine.chktool('t')==1)
		{
		cout<<BLUE<<" Thief -- "<<endl;
		cout<<"     Thanks for giving my knife back! "<<endl<<"     I will show you the way to level 24th. "<<endl;
		cout<<RED<<"Herobrine -- "<<endl<<"     Thank you! "<<endl<<COLEND;
		graphs[23].changepot(7,7,19);//23层正中间
		cout<<endl<<"Press anykey to continue...";
		mygetch();
		return 2;
		}
	else
		{
		cout<<BLUE<<"Thief -- "<<endl;
		cout<<"     Please find my knife, it is important for me. I will find the way to level 24th if I have my knife back. "<<endl<<COLEND;
		cout<<endl<<"Press anykey to continue...";
		mygetch();
		return 0;
		}
	}
}

/****************** angel 16 ********************/

short askangel()
{
CLEAR;
if(nangel==0)
	{
	cout<<BLUE<<"Angel -- "<<endl;
	cout<<"     I have been traped here for a long time and I can't escape. "<<endl<<"     But I have a MAP here, you can use it before you save out the PRINCESS. "<<endl<<"     Good luck! "<<endl;
	cout<<RED<<"Herobrine -- "<<endl<<"     Thanks for your blessing! "<<endl<<COLEND;
	cout<<endl<<" Get the MAP. "<<endl<<" Press 'm' to use it. "<<endl;
	cout<<endl<<"Press anykey to continue..."<<endl;
	mygetch();
	herobrine.chgtool('m',1);
	nangel++;
	return 1;
	}
else
	return 0;
}

/****************** old big 17 **********************/

short askoldbig()
{
short chkend=0;
do{
	CLEAR;
	cout<<BLUE<<"Old mam--What can I do for you ?"<<endl;
	cout<<"Enter the number you want..."<<endl;
	cout<<endl<<"1.Pay 400 exp to add 4000 life;"<<endl<<"2.Pay 400 exp to add 500 attack&defence;"<<endl<<"3.Pay 2000 exp to add 5 rank;"<<endl<<"4.quit"<<COLEND<<endl;
	short ans;
	cin>>ans;mygetch();
	
	if(ans==1||ans==2)
		{
		int exp=herobrine.chkatt('e');
		if(exp>=400)
			{
			herobrine.chgatt('e',-400);
			switch(ans)
				{
				case 1:herobrine.chgatt('l',4000);break;
				case 2:herobrine.chgatt('a',500);herobrine.chgatt('d',500);break;
				}
			cout<<"Successed!Press anykey to continue..."<<endl;
			mygetch();
			}
		else
			{
			chkend=1;
			cout<<"You dont have enough experience!"<<endl<<"Press anykey to continue..."<<endl;
			mygetch();
			}
		}
	else
		{
		if(ans==3)
			{
			int exp=herobrine.chkatt('e');
			if(exp>=2000)
				{
				herobrine.chgatt('e',-2000);
				herobrine.chgatt('r',5);
				cout<<"Successed!Press anykey to continue..."<<endl;
				mygetch();
				}
			else
				{
				chkend=1;
				cout<<"You dont have enough experience!"<<endl<<"Press anykey to continue..."<<endl;
				mygetch();
				}
			}
		else chkend=1;
		}
	
	}while(chkend==0);
return 1;
}

