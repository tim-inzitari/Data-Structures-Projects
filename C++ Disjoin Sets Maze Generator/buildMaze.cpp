// Tim Inzitari
#include <iostream>
#include <cstdlib>
#include <ctime>
/*

buildMaze.cpp contains the main() driver code. You will write this code; it is NOT available on
our website. It should include the following.
a. void twoRandom(int & n1, int & n2, int maxN ); -- a function prototype that
generates two distinct random integers in the range of [0, row * col); i.e. the random
numbers should not be greater than maxN. These numbers represent random cells. Your
code will need to determine if the cells are neighbors by invoking the method from maze.h
that has the prototype of
bool maze::neighbors(int cell, int neigh) const;
b. bool isConnected(int n1, int n2); -- a function prototype used to determine
if two cells are connected. This function will invoke the DisjSets::find( )method.
c. Implement logic in this code file that keeps generating two distinct random integers and
connecting the cells that these integers represent if the cells are neighbors. Your code
should stop and display the final maze when there is a path from the starting cell to the exit
cell. How do you know when this occurs? You will be using the DisjSet unionSet and
find methods to help with this functionality. Make certain you use the DisjSets code
for full credit.
d. Make certain that your code always prints the starting and final maze. If the user enters ‘y’
to the prompt to print intermediate mazes, please make certain that your code does this.
*/

#include "maze.h"
#include "disjSets.h"
using std::cin;
using std::cout;
using std:: endl;


void twoRandom(int & n1, int & n2, int maxN);


int main()
{
     srand(time(0));
    int rows,cols = 0;
    bool eachIterOfMaze = true;
    char in;
    cout << "Please enter hte number of rows greater than 1: ";
    while(!(cin>>rows) || (rows <= 1)) // get int values while errorchecking
    {
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        cout << "Error: not a Valid Integer, Try Again: ";
    }
    cout << "Please enter hte number of cols greater than 1: ";
    while(!(cin>>cols) || (cols <= 1)) // get int values while errorchecking
    {
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        cout << "Error: not a Valid Integer, Try Again: ";
    }

    cout << "Would you like to see each iteration of the maze: ";
    while (!(cin>>in)|| !(in == 'n' || in == 'N' || in == 'Y' || in == 'y'))
    {
        cin.clear();
        cin.ignore();
        cout << "Error, please enter 'n' or 'y' Try Again: ";
    }
    if (in == 'n' || in == 'N')
        eachIterOfMaze = false;

    int rowsCols = rows * cols;
    maze theMaze(rows,cols);
    DisjSets disSet(rowsCols);

    theMaze.printMaze();

    // do until end = start
    while ((disSet.find(0) != disSet.find(rowsCols -1)))
    {
        int cell, neighbor = -1000;
        bool continueLoop = true;
        // find two cells that are nieghbors
        while (continueLoop)
        {
          twoRandom(cell,neighbor, rowsCols);
            if (theMaze.neighbors(cell,neighbor)) // If Neighbors continue
                continueLoop = disSet.isConnected(cell,neighbor); // if not connected End Loop
        } // generate randum until you get nieghbors that aren't connected
        if (eachIterOfMaze)
        cout << "\nNeighbors " << cell << ", " << neighbor << " wall smashed below" << endl;
                int fCell = disSet.find(cell);
        int fNeighbor = disSet.find(neighbor);
        theMaze.smashWall(cell,neighbor); // smash walls
        theMaze.smashWall(neighbor,cell); // smash walls
        disSet.unionSets(fCell,fNeighbor);
        if (eachIterOfMaze)
        theMaze.printMaze();

    }
    if (!eachIterOfMaze) // Display result if you are not showing every iteration
    theMaze.printMaze();
    return 0;
}

void twoRandom(int & n1, int & n2, int maxN)
{

   do
   {
    n1 = rand() % maxN;
    n2 = rand() % maxN;
   } while (n1 == n2);

}


