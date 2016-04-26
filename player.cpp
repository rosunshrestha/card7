#include "card.cpp"
class Player{
      private:
                //char thrown[3];
                //int convert_no;
                //char check_suit;
                int horizontal,vertical;
                int bot[13];
                int j1[13];
                int inside;
                int l1;

      public: 
              char Playername[10];
      /*To initialize the variables for newgame*/
      void reinitialize_values(){
           int i;
           for(i=0;i<13;i++){
                             bot[i]=20;
                             j1[i]=20;
                             }
           inside=730;
           l1=12;
           }
      /*To create player and pass the cards*/
      
             Card P[13];
             Card table;
             void distribute(int i,Card a){ //shuffled objects of Deck go inside Cards of player. Also images are loaded of the cards the player has
                  P[i]=a; //void operator=(Deck a)                     //passing deck attributes to card.
                  }
      /*To create other player*/
                  BITMAP *P2;
                  BITMAP *P3;
                  BITMAP *P4;
      /*To display it on the screen*/
             void display(){
                  /*display using network only in one computer for respective player*/
                  int i;
                  horizontal=100;
                  vertical=550;
                  for(i=0;i<13;i++){
                                    P[i].display(horizontal,vertical);
                                    horizontal+=45;
                                    }
                  P2=load_bitmap("P2.bmp",NULL);
                  P3=load_bitmap("P3.bmp",NULL);
                  P4=load_bitmap("P4.bmp",NULL);
                  text_mode(-1);
                  rectfill(screen,405,690,505,715,makecol(172,13,32));//Player one rectangle
                  textprintf(screen,font,425,700,makecol(255,255,255), Playername);
                  horizontal=750;
                  vertical=250;
                  blit(P2, screen, 0, 0, horizontal, vertical, SCREEN_W, SCREEN_H);
                  rectfill(screen,770,430,870,455,makecol(172,13,32));//Player two rectangle
                  textprintf(screen,font,790,440,makecol(255,255,255),"Player 2");
                  horizontal=380;
                  vertical=10;
                  blit(P3, screen, 0, 0, horizontal, vertical, SCREEN_W, SCREEN_H);
                  rectfill(screen,405,190,505,215,makecol(172,13,32));//Player three rectangle                                                    
                  textprintf(screen,font,425,200,makecol(255,255,255),"Player 3");
                  horizontal=10;
                  vertical=250;
                  blit(P4, screen, 0, 0, horizontal, vertical, SCREEN_W, SCREEN_H);
                  rectfill(screen,25,430,125,455,makecol(172,13,32));//Player four rectangle
                  textprintf(screen,font,45,440,makecol(255,255,255),"Player 4");
                  }
   //   friend const char* getName(string number,string suit);
      /*To get the player name*/
void playername()
{
                BITMAP *askname;
                askname=load_bitmap("name.bmp",NULL);
                blit(askname,screen,0,0,400,260,SCREEN_W,SCREEN_H);
                int index = 0;
                Playername[0]=char(0);
                text_mode(-1);
                while(1)
                {
                        if(keypressed())
                        {
                                 int newkey = readkey();
                                 char ascii = newkey &0xff;
                                 
                                 char scancode = newkey >> 8;
                                 
                                 if(ascii >= 32 && ascii <= 126)
                                 {
                                             if(index <10)
                                             {
                                                           Playername[index] = ascii;
                                                           index ++;
                                                           Playername[index] = '\0';
                                              }
                                  }
                                 else if(scancode == KEY_BACKSPACE)
                                 {
                                      ascii= char(32);
                                                  if(index > 0)
                                                  {
                                                             index--;
                                                             Playername[index] = ascii;
                                                                                     
                                                   }
                                 //textout(screen, font, , 460, 325, makecol(165, 165,165));
                                  }
                        
                        }
                        
                        textout(screen, font, Playername, 500, 330, makecol(165, 165,165));
                                 
                        if(key[KEY_ENTER])
                        {
                                 destroy_bitmap(askname);
                                 clear(screen);
                                 break;
                               
                        }                                                
 
                         
                }
                
}
      /*To check the card for Spade of 7 and start the game*/
           int spade_7(){
               int i;
               string t;
               for(i=0;i<13;i++){
                                 t=P[i].imagename;
                                 if(t=="S7.bmp"){
                                          break;
                                          }
                                 }
               if(i==13){  
                         return 0;
                         }
               else{
                    return 1;
                    }
               }       
             
      /*To show active player*/
      void activeplayer(int x1,int y1, int x2, int y2, int col,char* n){
                          rectfill(screen,x1,y1,x2,y2,col);//Player one rectangle
                  textprintf(screen,font,x1+20,y1+10,makecol(255,255,255),n);
           }
      /*To check the rule of the game*/
          int condition(int j){
              string t;
              string array1[52]={"S1.bmp","S2.bmp","S3.bmp","S4.bmp","S5.bmp","S6.bmp","*","S8.bmp","S9.bmp","S10.bmp","S11.bmp","S12.bmp","S13.bmp","D1.bmp","D2.bmp","D3.bmp","D4.bmp","D5.bmp","D6.bmp","D7.bmp","D8.bmp","D9.bmp","D10.bmp","D11.bmp","D12.bmp","D13.bmp","C1.bmp","C2.bmp","C3.bmp","C4.bmp","C5.bmp","C6.bmp","C7.bmp","C8.bmp","C9.bmp","C10.bmp","C11.bmp","C12.bmp","C13.bmp","H1.bmp","H2.bmp","H3.bmp","H4.bmp","H5.bmp","H6.bmp","H7.bmp","H8.bmp","H9.bmp","H10.bmp","H11.bmp","H12.bmp","H13.bmp"};
              string static array[52]={"S1.bmp","S2.bmp","S3.bmp","S4.bmp","S5.bmp","S6.bmp","*","S8.bmp","S9.bmp","S10.bmp","S11.bmp","S12.bmp","S13.bmp","D1.bmp","D2.bmp","D3.bmp","D4.bmp","D5.bmp","D6.bmp","D7.bmp","D8.bmp","D9.bmp","D10.bmp","D11.bmp","D12.bmp","D13.bmp","C1.bmp","C2.bmp","C3.bmp","C4.bmp","C5.bmp","C6.bmp","C7.bmp","C8.bmp","C9.bmp","C10.bmp","C11.bmp","C12.bmp","C13.bmp","H1.bmp","H2.bmp","H3.bmp","H4.bmp","H5.bmp","H6.bmp","H7.bmp","H8.bmp","H9.bmp","H10.bmp","H11.bmp","H12.bmp","H13.bmp"};
              if(j==500){
                         int i;
                         for(i=0;i<52;i++){
                                          array[i]=array1[i];                                           
                                           }
                         return 1;
                         }
              t=P[j].imagename; //get the required cardname
              if(t=="D7.bmp"||t=="H7.bmp"||t=="C7.bmp"){
                                            ss:
                                            int j;
                                            for(j=0;j<52;j++){
                                                              if(array[j]==t){
                                                                              array[j]="*";
                                                                              }
                                                              }
                                            clear_keybuf();
                                            return 1;
                                            }
              else{
                   int i;
                   for(i=44;i>=0;i--){
                                      if(array[i]==t){
                                                      if(array[i+1]=="*"){
                                                                         goto ss;
                                                                          }
                                                      else{
                                                           clear_keybuf();
                                                           return 0;
                                                           }
                                                      }
                                      if(i==39||i==26||i==13){
                                                              i=i-6;
                                                              }
                                      }
                   for(i=7;i<52;i++){
                                     if(array[i]==t){
                                                     if(array[i-1]=="*"){
                                                                        goto ss;
                                                                         }
                                                     else{
                                                          clear_keybuf();
                                                          return 0;
                                                          }
                                                     }             
                                     if(i==12||i==25||i==38){
                                                             i=i+6;
                                                             }
                                     }
                   }
          }
          /*For the bot to throw spade of 7*/
      void botS7(){
           int i;
           string t;
           for (i=0;i<13;i++){
               t=P[i].imagename;
               if(t=="S7.bmp"){
                               P[i].Table();
                               }
               }
           
           }
      
      /*For the bot mode*/
       int getcard(){
           
           int i;
           int k=0;
           string t;
           int answer;
           for(i=0;i<13;i++){
                             t=P[i].imagename;
                             if (t!="S7.bmp"){
                                              if (bot[i]==20){
                                                            answer=condition(i);
                                                            if (answer==1){
                                                                           P[i].Table();
                                                                           bot[i]=0;
                                                                           k++;
                                                                           destroy_bitmap(P[i].image);
                                                                           break;
                                                                           }
                                                            }
                                              }
                             }
           if(k==0){clear_keybuf();return 0;}
           if(k!=0){clear_keybuf();return 1;}           
           }          
           void destroyimage(){
                int i;
                for (i=0;i<13;i++){
                    destroy_bitmap (P[i].image);
                    }
                destroy_bitmap(P2);
                destroy_bitmap(P3);
                destroy_bitmap(P4);
                
                    
                }                        
          int mouseGetcard(){
               int k;
               int answer;
               //static int l1=12;
               //static int j1[13]={20,20,20,20,20,20,20,20,20,20,20,20,20};
               //static int inside=730;
               horizontal=100;
               vertical=550;
               int cp=0;//to determine card position
               BITMAP *illegal;
               illegal=load_bitmap("illegal.bmp",NULL);
               if(l1==12){
                          if(P[11].imagename==P[12].imagename){
                                           j1[12]=0;
                                           l1--;
                                           inside=685;
                                           }
                          }
               int mx,my;
               int quit=0;
               extern volatile int mouse_b;
               mouse_b=0;
               while(!mouse_b & 1){
                              goto other;
                              other:
                              mx=mouse_x;
                              my=mouse_y;
                              if(mouse_x>=100 && mouse_x<=(inside-90) && my>=550 && my<=670){ // || click position for pass
                                            if(mx>=100 && mx<=145){
                                                       cp=0;
                                                                                                         
                                                       }
                                            else if(mx>145 && mx<=190){
                                                       cp=1;                                               
                                                       }
                                            else if(mx>190 && mx<=235){
                                                       cp=2;                                                       
                                                       }
                                            else if(mx>235 && mx<=280){
                                                       cp=3;                                                       
                                                       }
                                            else if(mx>280 && mx<=325){
                                                       cp=4;                                                       
                                                       }
                                            else if(mx>325 && mx<=370){
                                                       cp=5;                                                       
                                                       }
                                            else if(mx>370 && mx<=415){
                                                       cp=6;                                                       
                                                       }
                                            else if(mx>415 && mx<=460){
                                                       cp=7;                                                       
                                                       }
                                            else if(mx>460 && mx<=505){
                                                       cp=8;                                                       
                                                       }
                                            else if(mx>505 && mx<=550){
                                                       cp=9;                                                       
                                                       }
                                            else if(mx>550 && mx<=595){
                                                       cp=10;                                                       
                                                       }
                                            else if(mx>595 && mx<=640){
                                                       cp=11;                                                       
                                                       }
                                            else if(mx>640 && mx<=730){
                                                       cp=12;                                                       
                                                       }
                                            }
                              else if(mouse_x>(inside-90) && mouse_x<inside){
                                   cp=l1;                                   
                                   }
                              else if(mouse_x>=770 && mouse_x<=870 && mouse_y>=630 && mouse_y<=655 && mouse_b & 1){//for passing to next player
                                   return 0;
                                   }
                                   
                              else if((mouse_x>=0 && mouse_x<=200 && mouse_y>=0 && mouse_y<=67 && mouse_b & 1)|| key[KEY_ESC]){
                                   return 2;
                                   }
                              else{
                                   goto other;
                                   }
                              }     
                    answer=condition(cp); // goes to condition , 2nd funtion of player
                    if(answer==0){    
                                   msg_sound();                              
                                  blit(illegal,screen,0,0,570,30,SCREEN_W,SCREEN_H);
                                   msg_sound();                              
                                  rest(1000);
                                  //press key??
                                  rectfill(screen,570,30,870,130,makecol(34,177,76));                                  
                                  mouseGetcard();
                                  }
                    else if(answer==1){
                         table=P[cp]; //The thrown card all attributes will be applied to object table
                         j1[l1]=0;
                         for (k=cp;k<l1;k++){
                             P[k]=P[k+1];                   
                             }
                         if(l1==0){
                                   rectfill(screen,100,550,145,670,makecol(34,177,76));
                                   }
                         P[l1].removecard();
                         inside-=45;
                         P[l1].display(inside,vertical);
                         l1--;
                         for(k=0;k<13;k++){
                                           if(j1[k]==20){
                                                        P[k].display(horizontal,vertical);
                                                        horizontal+=45;
                                                        }
                                           }
                         table.Table();
                         if(l1==-1) {return 3;}
                         return 1;
                         }
               } 
               void mouse7Spade(){
                    int cp=0;
                    int k;
                    string t;
                    horizontal=100;
                    vertical=550;
                    int mx,my;
                    extern volatile int mouse_b;
                    BITMAP *illegal1;
                    illegal1=load_bitmap("illegal.bmp",NULL);
                    mouse_b=0;
                    while(!mouse_b & 1){
                              goto other7;
                              other7:
                              mx=mouse_x;
                              my=mouse_y;
                              if(mouse_x>=100 && mouse_x<=730 && my>=550 && my<=670){ // || click position for pass
                                            if(mx>=100 && mx<=145){
                                                       cp=0;                                                   
                                                       }
                                            else if(mx>145 && mx<=190){
                                                       cp=1;                                                       
                                                       }
                                            else if(mx>190 && mx<=235){
                                                       cp=2;                                                       
                                                       }
                                            else if(mx>235 && mx<=280){
                                                       cp=3;                                                       
                                                       }
                                            else if(mx>280 && mx<=325){
                                                       cp=4;                                                       
                                                       }
                                            else if(mx>325 && mx<=370){
                                                       cp=5;                                                       
                                                       }
                                            else if(mx>370 && mx<=415){
                                                       cp=6;                                                       
                                                       }
                                            else if(mx>415 && mx<=460){
                                                       cp=7;                                                       
                                                       }
                                            else if(mx>460 && mx<=505){
                                                       cp=8;                                                       
                                                       }
                                            else if(mx>505 && mx<=550){
                                                       cp=9;                                                       
                                                       }
                                            else if(mx>550 && mx<=595){
                                                       cp=10;                                                       
                                                       }
                                            else if(mx>595 && mx<=640){
                                                       cp=11;                                                       
                                                       }
                                            else if(mx>640 && mx<=730){
                                                       cp=12;                                                       
                                                       }
                                            }
                              else{
                                   goto other7;
                                   }
                              }
                    t=P[cp].imagename;
                    if(t=="S7.bmp"){
                                                 table=P[cp];
                                                 horizontal=100;
                                                 for(k=cp;k<12;k++){
                                                                   P[k]=P[k+1];                                                                   
                                                                   }
                                                 P[12].removecard();
                                                 P[12].display(685,550);
                                                 for(k=0;k<12;k++){
                                                                   P[k].display(horizontal,vertical);
                                                                   horizontal+=45;
                                                                   }
                                                 table.Table();              
                                                 }
                    else if(t!="S7.bmp"){
                         msg_sound();
                         blit(illegal1,screen,0,0,570,30,SCREEN_W,SCREEN_H);
                         rest(1000);
                         //press key??
                         rectfill(screen,570,30,870,130,makecol(34,177,76));                                  
                         mouse7Spade();
                         }                             
                    }
};
