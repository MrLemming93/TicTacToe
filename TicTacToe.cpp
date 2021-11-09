#include <iostream>
#include <string>
using namespace std;

// NOTE(Lemming): GLobal variables for now, can we find a way to replace these?

char Cell[3][3];
int Row;
int Column;
char Token = 'x';
bool winCon = false;
bool Tie = false;
string n1;
string n2;
bool IsGameRunning = true;
bool userQuery = true;

// -----------------------------------------------------------------------------

void board()
{
    
    // Clearing the window
    system("cls");
    //--------------------
    
    cout << "    --------------------------\n";
    cout << "    #####  Tic Tac Toe   #####\n";
    cout << "    --------------------------\n\n";
    
    cout << "    Enter an X or O by typing in\n";
    cout << "    the  number that corresponds\n";
    cout << "    to a square.\n\n\n";
    
    cout << "             |     |   \n";
    cout << "          " << Cell[0][0]  << "  |  " << Cell[0][1] << "  |  " << Cell[0][2] << "  \n";
    cout << "             |     |     \n";
    cout << "        _____ _____ _____\n";
    cout << "             |     |     \n";
    cout << "          " << Cell[1][0] << "  |  " << Cell[1][1]<< "  |  " << Cell [1][2] << "  \n";
    cout << "             |     |     \n";
    cout << "        _____ _____ _____\n";
    cout << "             |     |     \n";
    cout << "          " << Cell[2][0] << "  |  " << Cell[2][1] << "  |  " << Cell [2][2] << "  \n";
    cout << "             |     |     \n\n\n";
}

void playerInput()
{
    int digit = 0;
    
    if(Token == 'x')
    {
        cout << n1 << ", please enter: ";
        cin >> digit;
    }
    if(Token == 'o')
    {
        cout << n2 << ", please enter: ";
        cin >> digit;
    }
    
    switch(digit)
    {
        case 1:
        {
            Row = 0;
            Column = 0;
        } break;
        
        case 2:
        {
            Row = 0;
            Column = 1;
        } break;
        
        case 3:
        {
            Row = 0;
            Column = 2;
        } break;
        
        case 4:
        {
            Row = 1;
            Column = 0;
        } break;
        
        case 5:
        {
            Row = 1;
            Column =1;
        } break;
        
        case 6:
        {
            Row = 1;
            Column = 2;
        } break;
        
        case 7:
        {
            Row = 2;
            Column = 0;
        } break;
        
        case 8:
        {
            Row = 2;
            Column = 1;
        } break;
        
        case 9:
        {
            Row = 2;
            Column = 2;
        } break;
        
        default:
        {
            cout << "Invalid number!!";
        } break;
    }
    
    if(Token == 'x' && Cell[Row][Column] != 'x' && Cell[Row][Column] != 'o')
    {
        Cell[Row][Column] = 'x';
        Token = 'o';
    }
    
    else if(Token == 'o' && Cell[Row][Column] != 'x' && Cell[Row][Column] != 'o')
    {
        Cell[Row][Column] = 'o';
        Token = 'x';
    }
    
    else
    {
        cout << "There isn't enough space!" << endl;
        playerInput();
    }
    board();
}

bool winCheck()
{
    for(int i = 0;i < 3;i++)
    {
        if(Cell[i][0] == Cell[i][1] && Cell[i][0] == Cell[i][2] || Cell[0][i] == Cell[1][i] && Cell[0][i] == Cell[2][i])
        {
            winCon = true;
            return(winCon);
        }
    }
    if(Cell[0][0] == Cell[1][1] && Cell[1][1] == Cell[2][2] || Cell[0][2] == Cell[1][1] && Cell[1][1] == Cell[2][0])
    {
        winCon = true;
        return(winCon);
    }
    
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(Cell[i][j] != 'x' && Cell[i][j] != 'o')
            {
                winCon = false;
                return(winCon);
            }
        }
    }
    Tie = true;
    winCon = false;
    return(winCon);
}

void gameLoop()
{
    system("cls");
    
    
    cout << "    --------------------------\n";
    cout << "    #####  Tic Tac Toe   #####\n";
    cout << "    --------------------------\n\n\n";
    
    // TODO(Lemming): This is being written too many times upon restarting. FIX IT!!!
    cout << "Enter the name of the first player: \n";
    cin >>  n1;
    cout << "Enter the name of the second player: \n";
    cin >>  n2;
    winCon = false;
    while(!winCon)
    {
        board();
        playerInput();
        winCheck();
    }
    
    if(Token == 'x' && Tie == false)
    {
        cout << "\n";
        cout << n2 << " wins!" << endl;
        cout << "\n";
    }
    
    else if(Token == 'o' && Tie == false)
    {
        cout << "\n";
        cout << n1 << " wins!" << endl;
        cout << "\n";
    }
    
    else if (Tie == true)
    {
        cout << "\n";
        cout << "Its a draw!" << endl;
        cout << "\n";
    }
    int userIntQuery = 0;
    cout << "would you like to play again?(1 = yes, 2 = no)\n";
    cin >> userIntQuery;
    if(userIntQuery == 1)
    {
        userQuery = true;
    }
    else if(userIntQuery == 2)
    {
        userQuery = false;
    }
}

int main()
{
    while(IsGameRunning)
    {
        if(userQuery == true)
        {
            Cell[0][0] = '1';
            Cell[0][1] = '2';
            Cell[0][2] = '3';
            Cell[1][0] = '4';
            Cell[1][1] = '5';
            Cell[1][2] = '6';
            Cell[2][0] = '7';
            Cell[2][1] = '8';
            Cell[2][2] = '9';
            gameLoop();
        }
        else
        {
            return 0;
        }
    }
}



