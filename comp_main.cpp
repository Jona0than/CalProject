 #include "maze.h"

// Edit the code here to change maze file.
#define MAZE_FILE "maze.txt"
#include<iostream>
#include <vector>

using namespace std;

int solve(Maze& M, int xi, int yi, char lastMove);
bool checkArraySame(int x, int y);

    vector<int> xS;
    vector<int> yS;

int main(){
	Maze M;
	M.ReadMaze(MAZE_FILE);
	cout<<"This is the maze."<<endl;
	cout << M;
	M.getStart();
	int x, y;
	M.getCurrentLocation(x,y);
	cout<<"Get started! Now you are @ ("<<x<<","<<y<<")"<<endl;
    cout << M;

    char lastMove;

    solve(M, 0, 0,'q');
}
bool checkArraySame(int x, int y){      //this method checks the potential location with
                                        //the locations already visited.

    for(int i = 0 ; i < xS.size(); i++){
        if(xS[i] == x && yS[i] == y)
            return true;

    }
            return false;
}

int solve(Maze& M, int xi, int yi, char lastMove)
	{

	    int x, y;
	    M.getCurrentLocation(x,y);
	    xS.push_back(x);
	    yS.push_back(y);


        cout<<"current loc (x , y): "<< x <<", " << y <<endl;
  //      for(int i = 0 ; i < xS.size(); i++){
  //          cout<<"vector (x,y): "<<xS[i]<<", "<<yS[i]<<endl;
  //      }

        if(M.isFinish())
        {
            cout<<"Maze is completed!"<<endl;
            return 0;
        }
        else
        {
            if(!checkArraySame(x,y-1) && M.north() )
            {
                    //xS.push_back(x);
                    //yS.push_back(y);



                    lastMove = 'n';
                    cout<<M;
                //int x, y;
                //M.getCurrentLocation(x,y);


               return solve(M, x, y, lastMove);
            }

            if(!checkArraySame(x-1,y) && M.west() )
            {
                    //xS.push_back(x);
                    //yS.push_back(y);
                    lastMove = 'w';
                //cout<<M;int x, y;
                //M.getCurrentLocation(x,y);

                cout<<M;


                return solve(M,x,y,lastMove);
            }

            if(!checkArraySame(x+1,y) && M.east() )
            {
                //xS.push_back(x);
                //yS.push_back(y);
                lastMove = 'e';

                cout<<M;
                //int x, y;
              //  M.getCurrentLocation(x,y);

                return solve(M, x, y, lastMove);
            }


            if(!checkArraySame(x,y+1) &&  M.south()  )
            {

                 //xS.push_back(x);
                  //yS.push_back(y);
                  lastMove = 's';

                //cout<<M;int x, y;
                cout<<M;
               // M.getCurrentLocation(x,y);


                return solve(M, x, y, lastMove);
            }


   //////////////////////////////////////////////////////////////////



            if( M.north() ){
                    while(checkArraySame(x, y-1) && M.north()){
             //           M.north();
             //           int x,y;
                        M.getCurrentLocation(x,y);
                    }

                cout<<M;
                return solve(M,x,y,lastMove);
            }

            if( M.west()  ){
                    while(checkArraySame(x-1,y) && M.west()){
              //          M.west();
              //          int x,y;
                        M.getCurrentLocation(x,y);
                    }

                cout<<M;
                return solve(M,x,y,lastMove);
            }

            if( M.east()){
                    while(checkArraySame(x+1,y) && M.east()){
             //           M.east();
             //           int x,y;
                        M.getCurrentLocation(x,y);
                    }

                cout<<M;
                return solve(M,x,y,lastMove);
            }

            if( M.south()){
                    while(checkArraySame(x,y+1) && M.south()){
             //           M.south();
             //           int x,y;
                        M.getCurrentLocation(x,y);
                    }

                cout<<M;
                return solve(M,x,y,lastMove);
            }


///////////////////////////////////////////////////////////////////



            if( lastMove == 's' ){
                    while(checkArraySame(x, y-1) && M.north()){
             //           M.north();
             //           int x,y;
                        M.getCurrentLocation(x,y);
                    }

                cout<<M;
                return solve(M,x,y,lastMove);
            }

            if( lastMove == 'e'  ){
                    while(checkArraySame(x-1,y) && M.west()){
              //          M.west();
              //          int x,y;
                        M.getCurrentLocation(x,y);
                    }

                cout<<M;
                return solve(M,x,y,lastMove);
            }

            if( lastMove == 'w'){
                    while(checkArraySame(x+1,y) && M.east()){
             //           M.east();
             //           int x,y;
                        M.getCurrentLocation(x,y);
                    }

                cout<<M;
                return solve(M,x,y,lastMove);
            }

            if( lastMove == 'n' ){
                    while(checkArraySame(x,y+1) && M.south()){
             //           M.south();
             //           int x,y;
                        M.getCurrentLocation(x,y);
                    }

                cout<<M;
                return solve(M,x,y,lastMove);
            }

            return 0;



        }
        return 0;
    }
