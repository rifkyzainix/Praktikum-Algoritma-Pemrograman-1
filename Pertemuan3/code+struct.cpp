#include <iostream>
#include <windows.h>
#include <conio.h>
 
using namespace std;

bool randomBool() {
    return 0 + (rand() % (1 - 0 + 1)) == 1;
}

char Map[30][30] = {"###########################",
                    "#       ##   R  ##        #",
                    "#               ##        #",
                    "########        ##        #",
                    "#                         #",
                    "#          ####    ###    #",
                    "# #        #R             #",
                    "# ######   #        #######",
                    "#          #          #R  #",
                    "#         ##########      #",
                    "#######      ##$   #  #####",
                    "#            ##    #      #",
                    "##########   ##    #      #",
                    "#$           ##   #########",
                    "#         #            #  #",
                    "#####     #########       #",
                    "#R        #R          #####",
                    "#         #        #      #",
                    "#     ##############      #",
                    "###        #       #      #",
                    "#          #   #####   ####",
                    "######     #       #      #",
                    "#               ####   #  #",
                    "#############      #   #  #",
                    "#     #$           #      #",
                    "#  #  #   ##############  #",
                    "#  #  #         #    #    #",
                    "#@ #                      #",
                    "###########################",
                    };
int Gamespeed = 100;
int Level = 0;
bool stopgame = false;

struct profile{
    int money;
    int mission;

    int R(int money){
    int random = 1 + (rand()%2);
    if(random==1){
        money--;
    }else if(random==2){
        money++;
    }
    return money;
    }

    int dollar(int money){
        money++;
     return money;
    }
};


int main () 
{
    profile level1;
    level1.money = 0;
    level1.mission=5+(rand()%10);
    while (stopgame == false && Level==0) 
    {
    if(level1.money>=level1.mission){
       Map[1][0]='!'; 
    }
          system("cls");
          for (int y= 0;y<30;y++)
          {
              cout << Map[y] << endl;
          }
          for (int y= 0;y<30;y++)
          {
              for (int x = 0; x<30; x++) 
              {
                  switch (Map[y][x]) 
                  { 
                      case '#':
                      {
                          Map[y][x] = 219;
                      }break;
                     case '@':
                     {
                           
                          if (GetAsyncKeyState(VK_UP) !=0)
                          {
                               int y2 = (y-1);
                              switch(Map[y2][x]) 
                              {
                                  case ' ' :
                                  {
                                        Map[y][x] = ' ';
                                        y-=1;
                                        Map[y2][x]='@';
                                  } break;
                                  case '!' :
                                  {
                                        if(level1.money>=level1.mission){
                                               Level = 1;
                                           }
                                  } break;
                                  case '$' :
                                  {
                                      Map[y][x] = ' ';
                                        y-=1;
                                        Map[y2][x]='@';
                                        level1.money=level1.dollar(level1.money);
                                  } break;
                                  case 'R' :
                                  {
                                      
                                        level1.money=level1.R(level1.money);
                                         
                                  } break;
                              }
                          }
                          if (GetAsyncKeyState(VK_DOWN) !=0)
                          {
                                   int y2 = (y+1);
                                  switch(Map[y2][x]) 
                                  {
                                      case ' ' :
                                      {
                                            Map[y][x] = ' ';
                                            y+=1;
                                            Map[y2][x]='@';
                                      } break; 
                                        case '!' :
                                  {
                                       if(level1.money>=level1.mission){
                                               Level = 1;
                                           }
                                  } break;
                                  case '$' :
                                  {Map[y][x] = ' ';
                                        y-=1;
                                        Map[y2][x]='@';
                                        level1.money=level1.dollar(level1.money);
                                  } break;
                                  case 'R' :
                                  {
                                     
                                        level1.money=level1.R(level1.money);
                                         
                                  } break;
                                  }
                          }
                           if (GetAsyncKeyState(VK_RIGHT) !=0)
                          {
                                   int x2 = (x+1);
                                  switch(Map[y][x2]) 
                                  {
                                      case ' ' :
                                      {
                                            Map[y][x] = ' ';
                                            x+=1;
                                            Map[y][x2]='@';
                                      } break; 
                                      case '!' :
                                      {
                                       if(level1.money>=level1.mission){
                                               Level = 1;
                                           }
                                      } break;
                                  case '$' :
                                  {Map[y][x] = ' ';
                                            x+=1;
                                            Map[y][x2]='@';
                                        level1.money=level1.dollar(level1.money);
                                  } break;
                                  case 'R' :
                                  {
                                        level1.money=level1.R(level1.money);
                                         
                                  } break;
                                  }
                          }
                          if (GetAsyncKeyState(VK_LEFT) !=0)
                          {
                                   int x2 = (x-1);
                                  switch(Map[y][x2]) 
                                  {
                                      case ' ' :
                                      {
                                            Map[y][x] = ' ';
                                            x-=1;
                                            Map[y][x2]='@';
                                      } break; 
                                        case '!' :
                                      {
                                           if(level1.money>=level1.mission){
                                               Level = 1;
                                           }
                                      } break;
                                  case '$' :
                                  {    Map[y][x] = ' ';
                                            x+=1;
                                            Map[y][x2]='@'; 
                                        level1.money=level1.dollar(level1.money);
                                  } break;
                                  case 'R' :
                                  {
                                        level1.money=level1.R(level1.money);
                                         
                                  } break;
                                  }
                          }
                           
                     }break;
                  }
              }
          }

              cout<<"Mission : Dapatkan uang sebanyak "<<level1.mission<<endl;
              cout<<"Money : "<<level1.money<<endl;
              Sleep(Gamespeed);
    }
    
    while  (stopgame == false && Level==1)
    {
      system ("cls");
      cout << "Level 2 Goes Here" << endl;
      system("pause");  
      return EXIT_SUCCESS;        
    }

    exit (1);
    getch ();
}
