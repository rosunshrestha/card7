#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <allegro.h>
#include <string>
#include <stdio.h>
#include <sstream>
using namespace std;
void msg_sound();
class Card{
      public:
             const char* imagename;
             BITMAP *p1_image;
             BITMAP *selection;
             BITMAP *buffer;
             BITMAP *image;
             BITMAP *glow;
             char suit;
             int number;
             void assignname(const char* name,char s,int n){ // assigns name to a card . passed from main fucntion 3
                        suit=s;
                        imagename=name;
                        number=n;                                           
                  }
             void operator=(Card a){             //passing deck 13 objects to each player while distribution is done
                  imagename=a.imagename;
                  image=load_bitmap(imagename,NULL);
                  suit=a.suit;
                  number=a.number;
                  }             
             void display(int h,int v){
                  blit(image, screen, 0, 0, h, v, SCREEN_W, SCREEN_H); //blit library funtion allegro //blit- to tansfer block by block image to destination
                  }
             void Table(){
                  image=load_bitmap(imagename,NULL);
                  blit(image, screen, 0, 0, 410, 320, SCREEN_W, SCREEN_H);
                  if(suit=='S'){
                                if(number==7) blit(image,screen,0,0,1015,290,SCREEN_W,SCREEN_H);
                                if(number>7) blit(image,screen,0,0,920,90,SCREEN_W,SCREEN_H);
                                if(number<7) blit(image,screen,0,0,945,150,SCREEN_W,SCREEN_H); 
                              }
                  else if(suit=='C'){
                                     if(number==7) blit(image,screen,0,0,1060,290,SCREEN_W,SCREEN_H);
                                     if(number>7) blit(image,screen,0,0,1065,90,SCREEN_W,SCREEN_H);
                                     if (number<7) blit(image,screen,0,0,1100,150,SCREEN_W,SCREEN_H);
                                     }
                  else if(suit=='H'){
                                     if(number==7) blit(image,screen,0,0,1015,350,SCREEN_W,SCREEN_H);
                                     if(number>7) blit(image,screen,0,0,920,490,SCREEN_W,SCREEN_H);
                                     if(number<7) blit(image,screen,0,0,945,550,SCREEN_W,SCREEN_H);                                     
                                     }
                  else if(suit=='D'){
                                     if(number==7) blit(image,screen,0,0,1060,350,SCREEN_W,SCREEN_H);
                                     if(number>7) blit(image,screen,0,0,1065,490,SCREEN_W,SCREEN_H);
                                     if (number<7) blit(image,screen,0,0,1100,550,SCREEN_W,SCREEN_H);
                                     }           
                  }
             void removecard(){                                 
                  clear_to_color(image,makecol(34,177,76));
                  }
           void glow_card(int glow_where_x){
                              glow = load_bitmap("glow.bmp", NULL);
                              rectfill(screen, 80, 540, 740, 550, makecol(34, 177, 76));
                              rectfill(screen, 80, 670, 740, 690, makecol(34, 177, 76));
                              masked_blit(glow, screen, 0,0, glow_where_x -10 , 545, glow->w , glow->h);
                              } 
};


