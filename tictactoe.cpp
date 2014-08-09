/* Purpose was to make it simple to understand.
Rasmus C. :) very la.te.
*/

#include <iostream>
#include <string>

using namespace std;

bool checkrange(int x, int y) // Check if numbers are in range.
{
    if (y<=3 && y>=0 && x<=3 && x>=0)
    {
        return true;
    }
    cout << "Coordinate not in range." << endl;
    return false;
}
// clear screen
void cls()
{
    for(int i=0;i<30;i++)
    {
        cout << endl;
    }
}

// Check if someone has won
string checkwin(string boardstate[][3])
{
    string p="X"; // run all this in a loop twice(make), first checking if x has won, then y.
    for (int e=0;e<2;e++)
    {

        //check x horisontally
        for(int i=0;i<3;i++)
        {
            if (boardstate[i][0] == p && boardstate[i][1] == p && boardstate[i][2]==p)
            {
                return p;
            }
        }

        // check vertically
        for(int j=0;j<3;j++)
        {
            if (boardstate[0][j] == p && boardstate[1][j] == p && boardstate[2][j]==p)
            {
                return p;
            }
        }

        //check left to right and reverse.
        if (boardstate[0][0] == p && boardstate[1][1] == p && boardstate[2][2]==p)
            {
                return p;
            }
        if (boardstate[0][2] == p && boardstate[1][1] == p && boardstate[2][0]==p)
            {
                return p;
            }
        // Check y's
        p="Y";
    }
    return "O"; // No one has won.
}

// Print the board
int printboard(string boardstate[][3])
{
    cout << "-------------------\n";
    cout << "|  " << boardstate[0][0] << "  |  " << boardstate[0][1] << "  |  " << boardstate[0][2] << "  |\n";
    cout << "-------------------\n";
    cout << "|  " << boardstate[1][0] << "  |  " << boardstate[1][1] << "  |  " << boardstate[1][2] << "  |\n";
    cout << "-------------------\n";
    cout << "|  " << boardstate[2][0] << "  |  " << boardstate[2][1] << "  |  " << boardstate[2][2] << "  |\n";
    cout << "-------------------\n";

    return 0;
}

int main()
{
    // New type with our possibilities. E=empty.
    //enum state{X,O,E};

    // New type tell who's turn it is
    enum players{p1, p2};
    // variable to store whose turn
    players turn =p1;

    string player1="Player1";
    string player2="Player2";

    // Menu
    cout << "Welcome to tictactoe!" << endl;
    cout << "Enter the name of player one: ";
    cin >> player1;
    cout << "Enter the name of player two: ";
    cin >> player2;
    cout << "Press enter to start the game!";
    cls();

    // Will hold the state of the boxes.
    string boardstate[3][3];

    // Fill the array with zero's.
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            boardstate[i][j]="0";
        }
    }

    int i=0; // Game loop
    while (i==0)
    {

        cls(); // clear the screen

        // Print the board with the data from boardstate
        printboard(boardstate);

        //Show the board
        if (checkwin(boardstate)== "X")
        {
            cls();
            cout << player1 << " HAS WON!\n";
            break;
        }

        if (checkwin(boardstate)== "Y")
        {
            cls();
            cout << player2 << " HAS WON!\n";
            break;
        }
        //Check whose turn it is and get next strike
        if (turn==p1)
        {

            int x=0;
            int y=0;

            int inrange=0;
            while(inrange==false)
            {
            cout << "It is your turn " << player1 << "\nPlease enter X coordinate: ";
            cin >> x;
            x--;
            cout << "Enter Y coordinate: ";
            cin >> y;
            y--;
            if (checkrange(x,y)==true)
                {
                    inrange=1;
                }
            }

            // check if taken
            if (boardstate[x][y]!="Y")
            {
                boardstate[y][x]="X";
            }
        }

        if (turn==p2)
        {
            int x=0;
            int y=0;

            int inrange=0;
            while(inrange==false)
            {
            cout << "It is your turn " << player2 << "\nPlease enter X coordinate: ";
            cin >> x;
            x--; // arrays starts from 0
            cout << "Enter Y coordinate: ";
            cin >> y;
            y--; // arrays starts from 0
            if (checkrange(x,y)==true)
                {
                    inrange=1;
                }
            }

            // check if taken
            if (boardstate[x][y]!="X")
            {
                boardstate[y][x]="Y";
            }

        }
    // give the turn over
    if (turn==p1)
    {
        turn=p2;
    }
    else
    {
        turn=p1;
    }

    }
}
