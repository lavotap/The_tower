/* 欢迎界面 */

#ifndef _WELCONE_
#define _WELCOME_

short welcome()
{
CLEAR;
cout
<<BLUE
<<"                                                              "<<endl
<<"  ××××× ×   × ×××××                                           "<<endl
<<"    ×   ××××× ×××    ×                                        "<<endl
<<"    ×   ×   × ×××××  ×                                        "<<endl
<<"                                                              "<<endl
<<RED
<<"   *********      **      *       *   *********   *******     "<<endl
<<"       *        *    *    *       *   *           *       *   "<<endl
<<"       *       *      *   *   *   *   *           *       *   "<<endl
<<"       *       *      *   *   *   *   ******      * *****     "<<endl
<<"       *       *      *   *   *   *   *           *  *        "<<endl
<<"       *        *    *    *   *   *   *           *    *      "<<endl
<<"       *          **        *   *     *********   *      **   "<<endl
<<"                                                              "<<endl
<<"                                                              "<<endl
<<GREEN
<<"  THE TOWER    魔塔                                           "<<endl
<<"                                                  2015.01.29  "<<endl
<<"                                                              "<<endl
<<YELLOW
<<"  Press anykey to start game(Press h for help)...             "<<endl
<<COLEND;
mygetch();
return 1;
}


#endif
