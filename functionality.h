/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You need to define the required function in the part instructed here below.
 * Avoid making any unnecessary changes, particularly the ones you don't understand.
 * The different pieces should be defined using an array - uncomment the following code once you are done creating the array.
 * TIP: Understand thoroughly before getting started with coding.
 * */
//---Piece Starts to Fall When Game Starts---//




void fall( float& timer, float& delay, int& colorNum, bool& rotate ){                           ///(1).....
               
     		if (timer>delay){ 
     		
     		bombdetector=0;                                         // Variable detetctsBomb fall position
     		
     		
     		for (int i=0;i<4;i++){
     	        point_2[i][0]=point_1[i][0] ;    
            	point_2[i][1]=point_1[i][1] ;
            	point_1[i][1]+=1; 
		bombdetector =point_1[i][1];}
		
		
        	
               if (!anamoly()){     
               for(int i =0; i<4; i++)
               gameGrid[point_2[i][1]][point_2[i][0]] = colorNum;
               colorNum = 1+rand()%7;
               
               if(beginner ==true){ n =rand()%4;}    					///Checking Complexity......
               else if (beginner==false) { n =rand()%6; }
              
              ::BOMBER++; if(::BOMBER==20){::BOMBER =0; ::n=7; ::r =rand()%9; }                //Bomb falls after 20 blocks.....
              ::gridcounter=::gridcounter+1;                                                    //After 30 falls grid size will decrease.....
                       
                       
                  for (int i=0;i<4;i++){
                    point_1[i][0] = BLOCKS[n][i] % 4+r;
                    point_1[i][1] = BLOCKS[n][i] / 4;
                    
  			}
                
            }
            
        timer=0; 
        
    }
    
}

void movealong_x_axis(int& delta_x)                                                   //(2)......
{ 
    if(n!=7){                                                                        //Bomb should not be moved..............
    int i=0;
    
    do
    {
      point_1[i][0]+=delta_x;                                                            // coordinates changing
      i++;
    } 
    while(i<4);
    
    delta_x =0;                                                                       //turning back to normal
    
    if(!anamoly()) { 
    int i =0;                                                           // This is the check That Prevent Overlapping During MOvement
    do{
    
      point_1[i][0] = point_2[i][0];
      i++;
      }
    while(i<4);    }
    
    }
}


void deleter()                                                                        //(3)...
{											// THIS DELETE ROWS AND MOVE EVERY PIECE DOWNWARD !
             		 int k =M-1;   // Starting With BOttom
             		 int i =(M-1);
                         do
                         {
                            int v=N; // Acts as a Counter.
                            int j =0;
                            do
                            {
                               if(gameGrid[i][j] != 0) {v=v-1;}                  // Checking Empty or FULL then we increse counter.
                                gameGrid[k][j] = gameGrid[i][j];
                                j++;
                            }
                            while(j<N);
                           if(v>0) {k--; } else if(v<=0) ::score=score+1;    //counts total no. of lines deleted one time...
                                
                                i--;
                         }
                         while(i>0);
                         
}

void verticalchecker()                                                               //(4).........
{											// Checks Vertical line test...
   int i =0;
   do
   {
     if(gameGrid[0][i] !=0)                                                        //If first row is filled it stop all
     gameover = false;
     i++;
   }
   while(i<N);  
}
     
void Bomber()                                                //(5).....
{                                                                           //Bomb..........
  if (n==7){
  		vv =vv+1;
  }
  else if(vv!=0){
   
   if (gameGrid[bombdetector][::r] == gameGrid[bombdetector-1][::r]){                 //If bomb color match with the lowest block color grid =0
   bigsound=1;
   int i =0;
   do {
   int j =0;
   do
   {                                                           // IF bomb fall on same colour
   gameGrid[i][j] =0;
   j++;
   }
   while(j<N);
   i++;
   }
   while(i<M); 
                                                               
   bombpoints++;}                                                                  //Increasing points............
   
   
   
   else if (gameGrid[bombdetector][::r] != gameGrid[bombdetector-1][::r]){
   slosound=1;
    gameGrid[bombdetector][::r] =0;
    gameGrid[bombdetector][::r-1]=0;                                    //IF bomb fall on another colour......
    gameGrid[bombdetector-1][::r]=0;
    gameGrid[bombdetector-1][::r-1]=0;
    gameGrid[bombdetector+1][::r+1]=0;
    bomblesspoints++;                                                        //Increasing points.........................
    }
    ::r=0;  vv=0;                                                     //Counters resets..................
   }
}

void gridshotner()                                            //(6)....
{
  switch(::gridcounter==30)
  {
  case 1 :                                      //Shortens the grid after 30 blocks fall......
  {
     int i =0;
     do 
     {
       gameGrid[(M-1)-hhr][i]=0;
        i++;
     }
     while(i<N);
     ::gridcounter=0;
       hhr = hhr+1;
  }
  break;
  }
}

void downwardkey(float& delay)                                      //(7).... 
{
   switch(Downwarder ==1)
   { 
      case 1:
      (beginner == true)  ?  delay=0.05  :   delay = 0.02;
      break;
   }
   Downwarder =0;
   
}
void harddrop(float& delay)                                             //(8)........
{
  switch(harddroper ==1)                                      
   { 
      case 1:
      delay =0.002;
      break;
   }
   harddroper =0;
  

}
void scorecounter()                                           //(9)...............
{                                                            //Score counter.....
                 linedeletes=linedeletes+score;
                 if(score ==1) ::points=::points+10;
                 if(score==2)  ::points=::points+30;
		  if(score==3)  ::points=::points+60;
                 if(score>=4)  ::points=::points+100;
                 score=0;
}
void rotation(bool & rotate)
{
 /*if(rotate ==true){
    
     int x =point_1[1][0];
     int y =point_1[1][1];
     int i =0;  //decl int
     do  //do loop
     {
      int nx=point_1[i][1] -y; //dec new
      int ny=point_1[i][0] -x;  //dec new
      point_1[i][0]=x-nx;     //x -nx
      point_1[i][1]=y-ny;   //y -ny
      i++;
     }
     while(i<4);
     rotate =0; //rot =o;
  }
  
  if(!anamoly()) { 
    int i =0;                                                           // This is the check That Prevent Overlapping During MOvement
    do{
    
      point_1[i][0] = point_2[i][0];
      i++;
      }
    while(i<4);    }*/
}



  ///*** YOUR FUNCTIONS END HERE ***///
/////////////////////////////////////
