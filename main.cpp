#include "player.cpp"     
#include <sstream>  
void init();
void deinit();
void game();
void menu();

int Exit();
    string convertint(int n){  //convert number of int type to string type 1->"1"
         string number;
         stringstream n1;
         n1<<n;
         number=n1.str();
         return number;
         }
 int mouseinside(int x1,int y1,int x2,int y2)
        {
                if (mouse_x > x1 && mouse_x < x2 && mouse_y > y1 && mouse_y < y2)
                     return 1;
                else
                    return 0;
        }     
void close_sound(){

      SAMPLE *sound1;
     install_sound(DIGI_AUTODETECT, MIDI_NONE, "");
     int panning = 128;
     int pitch = 1000;
     int volume = 300;
         sound1=load_sample("menu_sound.wav");
         destroy_sample(sound1);
         remove_sound();
     
     }        
     void msg_sound(){
     SAMPLE *sound3;
     install_sound(DIGI_AUTODETECT, MIDI_NONE, "");
     int panning = 128;
     int pitch = 1000;
     int volume = 300;
         sound3=load_sample("msg_sound.wav");
         play_sample(sound3, volume, panning, pitch,FALSE);
     }
     
      void player_sound(){
     SAMPLE *sound2;
     install_sound(DIGI_AUTODETECT, MIDI_NONE, "");
     int panning = 128;
     int pitch = 1000;
     int volume = 300;
         sound2=load_sample("player_sound.wav");
         play_sample(sound2, volume, panning, pitch,FALSE);
     }  
void sound(){
     SAMPLE *sound1;
     install_sound(DIGI_AUTODETECT, MIDI_NONE, "");
     int panning = 128;
     int pitch = 1000;
     int volume = 300;
         sound1=load_sample("menu_sound.wav");
         play_sample(sound1, volume, panning, pitch,FALSE);
     } 
void Rule(){
     BITMAP *rule;
	 rule=load_bitmap("rule.bmp",NULL);
	 blit(rule, screen, 0, 0, 0 , 0, SCREEN_W, SCREEN_H);
              rules:
              if(mouseinside(30,654,270,695) && mouse_b & 1) //for back key
                        {
                              close_sound();               
                              destroy_bitmap(rule);
                              menu();
                        }                     
     
               else goto rules;
     } 
     
 void instruction(){
     BITMAP *instruct;
     instruct=load_bitmap("instruct.bmp",NULL);
     blit(instruct, screen, 0, 0, 0, 0 ,SCREEN_W, SCREEN_H);  
        instructions:
        if(mouseinside(30,654,270,695) && mouse_b & 1)//for back key
                        {
                              close_sound();         
                              destroy_bitmap(instruct);
                              menu();
                        }                     
     
     else goto instructions;
        
        
        } 
              
void quit_game(){
     BITMAP *quit;
	quit=load_bitmap("quit.bmp",NULL);
	BITMAP *credit;
	credit=load_bitmap("credits.bmp",NULL);
	blit(quit, screen, 0, 0, 0 , 0, SCREEN_W, SCREEN_H);
                       exit:
                        if(mouseinside(123,346,518,416) && mouse_b & 1)
                        {
                             blit(credit,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                             while(!keypressed()){
                                                  
                                                  }
                             destroy_bitmap(quit);
                             exit(-1);
                        }
                        if(mouseinside(692,352,1085,419) && mouse_b & 1)
                        {
                            close_sound();
                             menu();
                        }
                        else goto exit;
     
     
     
     }         
void game(){
        /* to close sound*/
    close_sound();
     
     /*To create players*/
     Player P1, P2, P3, P4;
     P1.playername();//to ask the player his/her name
     /*To create the background*/
    BITMAP *background;
	background=load_bitmap("back.bmp",NULL);
	blit(background, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	/*To create the table*/
    BITMAP *table;
	table=load_bitmap("table.bmp",NULL);
	blit(table, screen, 0, 0, 280 , 210, SCREEN_W, SCREEN_H);
	
    BITMAP *quit;
    quit=load_bitmap("Esc.bmp",NULL);
    blit(quit, screen, 0, 0, 0,0 , SCREEN_W, SCREEN_H);
    
    BITMAP *pass;    
     pass=load_bitmap("pass.bmp",NULL);
    blit(pass, screen, 0, 0, 770,630 , SCREEN_W, SCREEN_H);
	/*To create image to show thrown cards on screen*/
	BITMAP *thrown;
	thrown=load_bitmap("table_1.bmp",NULL);
	blit(thrown,screen,0,0,910,10,SCREEN_W,SCREEN_H);
    /*declaration of messages bitmaps*/
     BITMAP *you_7; BITMAP *c1_7; BITMAP *c2_7; BITMAP *c3_7; BITMAP *youwon; BITMAP *c1won; BITMAP *c2won; BITMAP *c3won;
    /*To create cards and shuffle it*/        
    Card card[52];
    int i,j,count1=0,count2=13,num=0;
    string name1[52];
    const char* fname;   
    string suit="S";
    char s1='S';
    for(i=0;i<4;i++){
                     if(i==1){
                              suit="C";
                              s1='C';
                              }
                     else if(i==2){
                          suit="H";
                          s1='H';
                          }
                     else if(i==3){
                          suit="D";
                          s1='D';
                          }
                     for(j=count1;j<count2;j++){
                                                string number=convertint(num+1); //1st function of main
                                                string name =suit+number+".bmp"; // mathi 2nd function to get name s1.bmp 
                                                name1[j]=name;
                                                fname=name1[j].c_str();
                                                card[j].assignname(fname,s1,num+1); //assigns s1.bmp or similar to the card
                                                num++;
                                       }
                     
                     num=0;
                     count1=count1+13;
                     count2=count2+13;
                     }
    srand(time(0));
    for(i=0;i<52;i++){
                      Card shuffle;
                      int k=rand()%52;
                      shuffle=card[i];
                      card[i]=card[k];
                      card[k]=shuffle;     
                      }
     /* To distribute the cards to player*/
     int mem=0;
     for(i=0;i<13;i++){
                       P1.distribute(i,card[mem]);
                       P2.distribute(i,card[mem+1]);
                       P3.distribute(i,card[mem+2]);
                       P4.distribute(i,card[mem+3]);
                       mem=mem+4;
                       }
     P1.reinitialize_values();
     P2.reinitialize_values();
     P3.reinitialize_values();
     P4.reinitialize_values();
     P1.condition(500);
     P1.display();//display in COMPUTER 1 only using network
     int player1,player2,player3,player4;
      int c1,c2,c3,c4;
         c1=c2=c3=c4=13;
               if(P1.spade_7()==1){
                                    msg_sound();
                                    you_7=load_bitmap("U_7.bmp",NULL);
                                    blit(you_7,screen,0,0,570,30,SCREEN_W,SCREEN_H);
                                    rest(2500);
                                    destroy_bitmap(you_7);
                                    rectfill(screen,570,30,870,130,makecol(34,177,76));
                                    P1.activeplayer(405,690,505,715,makecol(14,9,77),P1.Playername);
                                    P1.mouse7Spade();
                                    --c1;
                                    goto player2;
                                    }
                if(P2.spade_7()==1){
                                    msg_sound();
                                    c1_7=load_bitmap("c1_7.bmp",NULL);
                                    blit(c1_7,screen,0,0,570,30,SCREEN_W,SCREEN_H);
                                    rest(1000);
                                    destroy_bitmap(c1_7);
                                    rectfill(screen,570,30,870,130,makecol(34,177,76));
                                    P2.activeplayer(770,430,870,455,makecol(14,9,77),"Player 2");
                                    P2.botS7();
                                    --c2;
                                    goto player3;
                                    }
                if(P3.spade_7()==1){
                                    msg_sound();
                                    
                                    c2_7=load_bitmap("c2_7.bmp",NULL);
                                    blit(c2_7,screen,0,0,570,30,SCREEN_W,SCREEN_H);
                                    rest(1000);
                                    destroy_bitmap(c2_7);
                                    rectfill(screen,570,30,870,130,makecol(34,177,76));
                                    P3.activeplayer(405,190,505,215,makecol(14,9,77),"Player 3");
                                    P3.botS7();
                                    --c3;
                                    goto player4;
                                    }
                if(P4.spade_7()==1){
                                    msg_sound();
                                    c3_7=load_bitmap("c3_7.bmp",NULL);
                                    blit(c3_7,screen,0,0,570,30,SCREEN_W,SCREEN_H);
                                    rest(1000);
                                    destroy_bitmap(c3_7);
                                    rectfill(screen,570,30,870,130,makecol(34,177,76));
                                    P4.activeplayer(25,430,125,455,makecol(14,9,77),"Player 4");
                                    P4.botS7();
                                    --c4;
                                    goto player1;
                                    }                   
    player1:{
           P4.activeplayer(25,430,125,455,makecol(172,13,32),"Player 4");
           player_sound();
           P1.activeplayer(405,690,505,715,makecol(14,9,77),P1.Playername);
           player1=P1.mouseGetcard();
           if(player1==0){
                          goto player2;
                          }
           else if(player1==2){
                goto finish;
                }

           else if(player1==3){
                 msg_sound();     
                     youwon=load_bitmap("Youwon.bmp",NULL);
                     blit(youwon,screen,0,0,450,300,SCREEN_W,SCREEN_H);
                     while(!keypressed()){
                                          }
                     destroy_bitmap(youwon);
                     goto finish; 
                     }
           }
     player2:{
           P1.activeplayer(405,690,505,715,makecol(172,13,32),P1.Playername);
           player_sound(); 
           P2.activeplayer(770,430,870,455,makecol(14,9,77),"Player 2");
           player2=P2.getcard();
           rest(2500);
           if(player2==1){
                          --c2;
                          }
           if(c2==0){
                     msg_sound();
                     c1won=load_bitmap("C1Won.bmp",NULL);
                     blit(c1won,screen,0,0,450,300,SCREEN_W,SCREEN_H);
                     while(!keypressed()){
                                          }
                     destroy_bitmap(c1won);
                     goto finish;
                     }
           goto player3;
           }
     player3:{
           P2.activeplayer(770,430,870,455,makecol(172,13,32),"Player 2");
           player_sound();
           P3.activeplayer(405,190,505,215,makecol(14,9,77),"Player 3");
           player3=P3.getcard(); //condition check/ return vale. 1 = ture throw card. 0 = don't throw next player.
           rest(2500);
           if(player3==1){
                          --c3;
                          }
           if(c3==0){
                     msg_sound();
                     c2won=load_bitmap("C2Won.bmp",NULL);
                     blit(c2won,screen,0,0,450,300,SCREEN_W,SCREEN_H);
                     while(!keypressed()){
                                          }
                     destroy_bitmap(c2won);
                     goto finish;
                     }
           goto player4;
           }   
     player4:{
           P3.activeplayer(405,190,505,215,makecol(172,13,32),"Player 3");
           player_sound();
           P4.activeplayer(25,430,125,455,makecol(14,9,77),"Player 4");
           player4=P4.getcard();
           rest(2500);
           if(player4==1){
                          --c4;
                          }
           if(c4==0){
                     msg_sound();
                     c3won==load_bitmap("C3Won.bmp",NULL);
                     blit(c3won,screen,0,0,450,300,SCREEN_W,SCREEN_H);
                     while(!keypressed()){
                                          }
                     destroy_bitmap(c3won);
                     goto finish;
                     }
           goto player1;
           }
     finish:
     /*Other players images destroyed*/
     P1.destroyimage();
     destroy_bitmap(pass);
     destroy_bitmap(quit);
     destroy_bitmap(table);
     destroy_bitmap(thrown);
     destroy_bitmap(background);
}


int Exit(){
     exit(-1);
     }
 void menu(){
      BITMAP *menu1;
	  menu1=load_bitmap("menu.bmp",NULL);
	  blit(menu1, screen, 0, 0, 0 , 0, SCREEN_W, SCREEN_H); 
	  sound(); 
      mouse_b = 0;        
      mainscreen:
      if(mouseinside(650, 226, 1115, 293) && mouse_b & 1){
                          clear(screen);
                          destroy_bitmap(menu1);
                          game();
                          clear(screen);
                          menu();
                }        
      else if(mouseinside(650, 345 ,1115 , 420) && mouse_b & 1){
                       clear(screen);
                       destroy_bitmap(menu1);
                       Rule();
            }
      else if(mouseinside(650,470, 1115, 540) && mouse_b & 1){
                       clear(screen);
                       destroy_bitmap(menu1);
                       instruction();
       }
       else if(mouseinside(650, 590, 1115, 669) && mouse_b & 1){
                       clear(screen);
                       destroy_bitmap(menu1);
                       quit_game();
            }
       else goto mainscreen;
}


int main(){
    init();
	deinit();
    
    /*To show the mouse button*/
    show_mouse(screen);
     menu();                                                                
     allegro_exit();
}
END_OF_MAIN()
void init() {
	int depth, res;
	allegro_init();
	depth = desktop_color_depth();
	if (depth == 0) depth = 32;
	set_color_depth(depth);
	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED,1200,720,0,0);
	if (res != 0) {
		allegro_message(allegro_error);
		exit(-1);
	}

	install_timer();
	install_keyboard();
	install_mouse();
	/* add other initializations here */
	
    install_sound(DIGI_AUTODETECT, MIDI_NONE, "");      
                                    

}

void deinit() {
	clear_keybuf();
	/* add other deinitializations here */
}
 
