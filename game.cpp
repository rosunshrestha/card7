#include "player.cpp"
#include <sstream>
void init();
void deinit();
string convertint(int n){
         string number;
         stringstream out;
         out<<n;
         number=out.str();
         return number;
         }
int main(){
    init();
    while(!key[KEY_ESC])
    { 
    }
	deinit();
    /*To create cards and shuffle it*/    
//cout <<"\n\n";
    Deck card[52];
    int i,j,count1=0,count2=13,num=0;
    string suit="S";
    for(i=0;i<4;i++){
                     for(j=count1;j<count2;j++){
                                                string number=convertint(num+1);
                                                card[j].assignname(number,suit);
                                                num++;
                                       }
                     if(i==1){
                              suit="C";
                              }
                     else if(i==2){
                          suit="H";
                          }
                     else if(i==3){
                          suit="D";
                          }
                     num=0;
                     count1=count1+13;
                     count2=count2+13;
                     }
     srand(time(0));
     for(i=0;i<52;i++){
                       Deck shuffle;
                       int k=rand()%52;
                       shuffle=card[i];
                       card[i]=card[k];
                       card[k]=shuffle;      
                       }

     /* To create player and distribute the card*/
     Player P1, P2, P3, P4;
     int mem=0;
     for(i=0;i<13;i++){
                       P1.distribute(i,card[mem]);
                       P2.distribute(i,card[mem+1]);
                       P3.distribute(i,card[mem+2]);
                       P4.distribute(i,card[mem+3]);
                       mem=mem+4;
                       }        
     P1.display(); //display in COMPUTER 1 only using network
  /*   cout<<"\n\n\n";
     P2.display();  //display in COMPUTER 2 only using network
     cout<<"\n\n\n";
     P3.display();  //display in COMPUTER 3 only using network
     cout<<"\n\n\n";
     P4.display();  //display in COMPUTER 4 only using network
     cout<<"\n\n\n";
     int c1,c2,c3,c4;
         c1=c2=c3=c4=13;
                if(P1.spade_7()==1){cout<<"player1 has spade of 7 so player1 should throw the card first\n";P1.Spade7();c1--;goto player2;}
                if(P2.spade_7()==1){cout<<"player2 has spade of 7 so player2 should throw the card first\n";P2.Spade7();c2--;goto player3;}
                if(P3.spade_7()==1){cout<<"player3 has spade of 7 so player3 should throw the card first\n";P3.Spade7();c3--;goto player4;}
                if(P4.spade_7()==1){cout<<"player4 has spade of 7 so player4 should throw the card first\n";P4.Spade7();c4--;goto player1;}            
     
     player1:
             
           cout<<"player1 turn\n";    
           char ch1;
           ch1=P1.getcard();
           if(ch1=='p'||ch1=='P'){
                                    goto player2;}
                                    else{c1--;}
           if(c1==0){
             cout<<"player1 is a winner\n";
             goto finish;}
           goto player2;
     player2:
           
           cout<<"player2 turn\n";
          
                   char ch2;
                   ch2=P2.getcard();
                  if(ch2!='p'||ch2!='P'){
                                    c2--;}
                   if(c2==0){
             cout<<"player2 is a winner\n";
             goto finish;}
                    goto player3;
     player3:
             
           cout<<"player3 turn\n";
                 char ch3;
                 ch3=P3.getcard();
                  if(ch3!='p'||ch3!='P'){
                  c3--;}
                  if(c3==0){
             cout<<"player3 is a winner\n";
             goto finish;}
                  goto player4;    
     player4:
             
           cout<<"player4 turn\n";
             char ch4;
             ch4=P4.getcard();
             if(ch4!='p'||ch4!='P'){
                                    c4--;}
             if(c4==0){
             cout<<"player4 is a winner\n";
             goto finish;}
             goto player1;
     finish:
            
     system("pause");
     return 0;*/
}
END_OF_MAIN()
void init() {
	int depth, res;
	allegro_init();
	depth = desktop_color_depth();
	if (depth == 0) depth = 32;
	set_color_depth(depth);
	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1200, 700, 0, 0);
	if (res != 0) {
		allegro_message(allegro_error);
		exit(-1);
	}

	install_timer();
	install_keyboard();
	/* add other initializations here */
		if (install_sound(DIGI_AUTODETECT, MIDI_NONE, "") != 0)
{
allegro_message("Error initializing sound system");
return;
}

}

void deinit() {
	clear_keybuf();
	/* add other deinitializations here */
}
