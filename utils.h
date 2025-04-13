/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * This header contains the global/common variables of the project.
 * You don't really need to change anything.
 * TIP: After completing your project, you can make changes for aesthetics.
 * */

//---Title: PF-Project, Fall-2022 for BS(CS)---//
const char title[] = "PF-Project, Fall-2022";

//---Height and Width of the Actual Interactive Game---//
const int M = 20;   //Number of rows for a piece to cover on the screen (not the entire screen) = 20
const int N = 10;   //Number of columns for a piece to cover on the screen (not the entire screen) = 10

//---The Actual Interactive Game Grid - Built Over (MxN)---//
int gameGrid[M][N] = {{0}};

//---To Hold the Coordinates of the Piece---//
int point_1[4][4], point_2[4][4]; // given.......
bool gameover = true;
int n =0;//=rand()%7;
int BOMBER =0; // mainly used in faller 
//int temp[4][4]={{0}};
int r =0;  // Random POsition fall.......
int bombdetector =0;//lenght of fall

int gridcounter=0;  //Helps in shortining grid size....
int hhr=0;         //Grid shotner implementator

int Downwarder =0;  //Detects downward motion......
int harddroper =0;  //Check harddrop...............
bool beginner =true; //condiion of levels..........
int score =0;        // score checker............
int points=0;       // points storer.......
int linedeletes=0;  //Check how many lines are deleted in total one game play.....
int bombpoints=0;   //check if bomb destroy whole grid or not...................
int bomblesspoints=0; //check if bomb destroy 4 square bloacks
int vv=0;            // delay bomb...........
//---Check Uncertain Conditions---//
int bigsound=0;
int slosound=0;
bool anamoly(){
    for (int i=0;i<4;i++){
        if (point_1[i][0]<0 || point_1[i][0]>=N || point_1[i][1]>= (M-hhr) ) 
            return 0;
         else if (gameGrid[point_1[i][1]][point_1[i][0]] )
            return 0;
          
            
            
           }
        return 1;
};

