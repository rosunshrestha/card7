#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <allegro.h>
#include <string>
#include <stdio.h>
using namespace std;
class Deck{
      public:
            const char* imagename;
            BITMAP *image;
            void assignname(const char* name){ // assigns name to a card . passed from main fucntion 3
                        imagename=name;                                           
                  }
                              
};

   
