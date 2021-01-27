// Tim Inzitari
#include "maze.h"
#include "DisjSets.h"

using std::vector;
using std::cout;
using std::endl;

maze::maze(int r, int c)// constructor
{
    row = r;
    col = c;
   int rowsMultCols = row * col;
  int  endSet = rowsMultCols -1;
    // maze with all wall
   theMaze.clear();
   for (int i = 0; i < row; ++i)
   {
       for (int j = 0; j < col; ++j)
       {
           // base case for first cell
           if (i == 0 && j == 0)
            theMaze.push_back(mazeCell(0,1,0,1));
          else if (i == row-1 && j == col -1 ) // base last cell
            theMaze.push_back(mazeCell(1,0,1,0));
          else
            theMaze.push_back(mazeCell());
       }
   }





}
   // returns true if neigh is cell's neighbor
   //(i.e. in position left, right, top or bot
   // with respect to cell)
   bool maze::neighbors(int cell, int neigh) const
   {
       // make Cell always lower
       if (cell > neigh)
       {
           int tmp = cell;
           cell = neigh;
           neigh = tmp;
       }

       if (neigh - col == cell)
        return true; // top neighbor and bototm since we establish an order above
       if (cell + 1 == neigh && (cell % col ) != (col - 1))
            return true; // right
       if (cell - 1 == neigh && (cell % col != 0))
        return true; // left

       return false; // not a neighbor
   }


      // get rid of cell's wall between cell and neighbor
   // Note: this method should be invoked twice from the driver
   // code to smashWall(a,b) and to smashWall(b,a)
   void maze::smashWall (int cell, int neigh)
   {
        if (cell + col == neigh) // bot
        {
            theMaze[cell].setBot(false);
        }
       if (cell - col == neigh)
       {
        theMaze[cell].setTop(false); // top neighbor
       }
       if (cell + 1 == neigh)
       {
           theMaze[cell].setRight(false); // right
       }
       if (cell - 1 == neigh)
       {

        theMaze[cell].setLeft(false); // left
        }
   }


      //print the maze
   void maze::printMaze()
   {
       for (int i = 0; i < row; ++i)
       {
           // TOP ROW
           if (i == 0)
           {
               for (int j = 0; j < col; j++)
               {
                    if (theMaze[ i* col + j].getTop())
                cout << "_ "; // top space
                else
                    cout << "   ";
               }
               cout << endl; // next line

           }
           if (i==0)
            cout << " ";
           else
            cout <<"|";

           // EVERY ROW, DON'T NEED TO DO A TOP OR Left CHECK, SINCE FOR EVERY ROW THATS NOT FIRST BOT = TOP and Left = Right for first column
            for (int j = 0; j < col; ++j)
           {
               if (theMaze[ i* col + j].getBot())
                cout << "_"; // bot space
               else
                cout << " "; // bot space
                if (theMaze[ i* col + j].getRight())
                cout << "|"; // right space
               else
                cout << " "; // right space
           }
           cout << endl; // next line for Next Cell row
       }


       cout << endl << endl;
   }


