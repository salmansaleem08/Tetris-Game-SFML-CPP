/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You don't need to change anything in the driver code/main function except the part(s) where instructed.
 * You are expected to define your functionalities in the "functionality.h" header and call them here in the instructed part(s).
 * The game is started with a small box, you need to create other possible in "pieces.h" file in form of array.
    E.g., Syntax for 2 pieces, each having four coordinates -> int Pieces[2][4];
 * Load the images into the textures objects from img directory.
 * Don't make any changes to the "utils.h" header file except for changing the coordinate of screen or global variables of the game.
 * SUGGESTION: If you want to make changes in "utils.h", do it once you complete rest of the functionalities.
 * TIP: You can study SFML for drawing scenes, sprites and window.
 * */

#include <SFML/Graphics.hpp>  //Graphics Library
#include <SFML/Audio.hpp>     // Sound Library
#include <time.h>
#include "utils.h"
#include "pieces.h"
#include "functionality.h"
#include<iostream>


using namespace sf;
using namespace std;
int main(){

    //==================================START OF MENU =================================//
    
    cout<<"---------------Welcome to TETRIS--------------\n";
    cout<<"--------------Let the Chill Begin's-----------\n";
    cout<<"SELECT GAME TYPE...\n";
    cout<<"(1) Beginner \n";
    cout<<"(2) Advance  \n";
    cout<<"Press 1 for Beginner level or 2 for Advance level.. \n";
    int Enter;
    cout<<"Enter : ";
    cin>>Enter;
    if(Enter ==1)
    {
     beginner =true;
     cout<<"Beginner level selected So now you will experience 5 types of BLOCKS with slow fall Duration.\n";
    }
    else if(Enter ==2)
    {
      beginner =false;
      cout<<"Advance level selected So now you will experience 7 types of BLOCKS with fast fall Duration.\n";
    }
   else
   cout<<"OK!!";
   //==================================== MENU END ==================================//

    srand(time(0));
    
    RenderWindow window(VideoMode(320, 480), title);
    Texture obj1, obj2, obj3 ,obj4;
    obj1.loadFromFile("img/tiles.png");
    obj2.loadFromFile("img/background.png");
    obj3.loadFromFile("img/frame.png");
    obj4.loadFromFile("img/tiles1.jpg");
    Sprite sprite(obj1), background(obj2), frame(obj3),sprite1(obj4);
    
    
     
    
    //============= SOUNDS =================//
    sf::SoundBuffer buffer, buffer1 , buffer2, buffer3, buffer4;
    buffer.loadFromFile("img/music.wav");
    Sound sound;
    sound.setBuffer(buffer);
    sound.play();
    
    buffer1.loadFromFile("img/rotate.wav");
    Sound sound1;
    sound1.setBuffer(buffer1);
    
    buffer2.loadFromFile("img/move.wav");
    Sound sound2;
    sound2.setBuffer(buffer2);
    
    
    buffer3.loadFromFile("img/bbomb.wav");
    Sound sound3;
    sound3.setBuffer(buffer3);
    
    buffer4.loadFromFile("img/sbomb.wav");
    Sound sound4;
    sound4.setBuffer(buffer4);
   
   
    //================ SOUNDS END ==============//
    
    
    
   //================= VARIABLES =============//
   
    int delta_x=0, colorNum=1;
    float timer=0; 
     
    float  delay; 
    if (beginner == true )         /// BEGINNER CHECK 
    delay=0.5;          
    else  
    delay = 0.3;
    
    
    bool rotate=0;
    Clock clock;
    
    //===============VARIABLES END ===============//
    
    
    
    //========================  WINDOW OPEN ============================//
    
    while (window.isOpen()){ 
   
      if (beginner == true )   //====BEGINNER CHECK =======//
      delay=0.5; 
      else 
      delay = 0.3;
        
      float time = clock.getElapsedTime().asSeconds();
      clock.restart();
      timer+=time;
      
        
       //=============== Event Listening Part ==============//
        Event e;
        while (window.pollEvent(e)){    //delay =0.3;                    //Event is occurring - until the game is in running state
            if (e.type == Event::Closed)                   //If cross/close is clicked/pressed
                window.close();                            //Opened window disposes
            if (e.type == Event::KeyPressed) {             //If any other key (not cross) is pressed
                if (e.key.code == Keyboard::Up)            //Check if the other key pressed is UP key
                     {rotate = true; sound1.play();}                   //Rotation gets on
                else if (e.key.code == Keyboard::Left)     //Check if the other key pressed is LEFT key
                    {delta_x = -1; sound2.play();}                         //Change in X-Axis - Negative
                else if (e.key.code == Keyboard::Right)    //Check if the other key pressed is RIGHT key
                    {delta_x = 1;    sound2.play();}                       //Change in X-Axis - Positive
                    
            }
        }
        
       //===========  END OF EVENTS LISTINING PART ==========//
       
        
        if (beginner = true )   
        delay=0.5; 
        else 
        delay = 0.3;
        
        if(bigsound==1){
         sound3.play();
          bigsound=0;}
          
           if(slosound==1){
         sound4.play();
          slosound=0;}
        //========================= Down movement and hard drop ===============================//
        
        if (Keyboard::isKeyPressed(Keyboard::Down))             //Just another way to detect key presses without event listener
         Downwarder =1;                                        //A Variable detecting down movement.........
         else if (Keyboard::isKeyPressed(Keyboard::Space))  
         harddroper =1;                                        // A variable detecting hard drop....
         
         
       //=========================  End of Down Movement and hard drop ========================//  
       
       
       //-------------------------------------------------------------------------------------//
       //================================   My Functions =====================================//
       //-------------------------------------------------------------------------------------//  
        
        downwardkey(delay);                     //(1).Downward Movement......
        harddrop(delay);                        //(2).Hard Drop..............
        
        if(gameover==true){                     //Checking game over.........
               
        Bomber();                              //(3).Bomb falling............
        fall(timer, delay , colorNum, rotate); //(4).Peace faller............              
        movealong_x_axis(delta_x);             //(5).Mover...................
        deleter();                             //(6).Row deleter.............
        scorecounter();                        //(7).Score Counter...........
        verticalchecker();                     //(8).Helps in checking game over
        rotation(rotate);           //(9).Rotation................
        gridshotner();                         //(10).Shortens the grid......
        }                                      //Bracket close...............
        
        //-------------------------------------------------------------------------------------//
       //============================= End of My Functions ===================================//
       //-------------------------------------------------------------------------------------// 
       
       
       
       
       //===============================Points after game ===================================//
        
        else if(gameover==false){              //Condition after game over......
         
         for(int i =0; i<M; i++){
         for(int j =0; j<N; j++){
         if(gameGrid[i][j] !=0){
         gameGrid[i][j]=0;
         }}}
         
         cout<<"\nSo Total Numbers of Lines Deleted are :";
         cout<<linedeletes<<"\n\n";
         cout<<"Your Bomb delete whole Grid "<<bombpoints<<" times \n\n"; 
         cout<<"Your Bomb delete square no.blocks "<<bomblesspoints<<" times \n\n";
         cout<<"So Your Total Score is: ";
         cout<<points+bombpoints*100+bomblesspoints*10<<"\n";
         cout<<"------------OVER------------\n";
         
         break;
        
        }
        
        
        
        
        
        
        
        window.clear(Color::White);
        window.draw(background);
        for (int i=0; i<M; i++){
            for (int j=0; j<N; j++){
                if (gameGrid[i][j]==0)
                    continue;
                sprite.setTextureRect(IntRect(gameGrid[i][j]*18,0,18,18));
                sprite.setPosition(j*18,i*18);
                sprite.move(28,31); //offset
                window.draw(sprite);
            }
        }
        for (int i=0; i<4; i++){
            sprite.setTextureRect(IntRect(colorNum*18,0,18,18));
            sprite.setPosition(point_1[i][0]*18,point_1[i][1]*18);
            sprite.move(28,31);
            window.draw(sprite);
          }
          
          
        
       //---The Final on Which Everything is Drawn Over is Loaded---//
        window.draw(frame);
        //sound.play();
        //---The Window that now Contains the Frame is Displayed---//
        window.display();
        
    }
    return 0;
}

