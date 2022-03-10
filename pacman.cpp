#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>
#include <cmath>
#include <time.h>
#include <conio.h>
#include <fstream>
using namespace std;
char maze[24][71] = {
    {"#####################################################################"},
    {"||.. .....................................................  ......  ||"},
    {"||.. %%%%%%%%%%%%%%%%        ...     %%%%%%%%%%%%%%  |%|..   %%%%   ||"},
    {"||..        |%|   |%|     |%|...     |%|        |%|  |%|..    |%|   ||"},
    {"||..   G    |%|   |%|     |%|...     |%|        |%|  |%|..    |%|   ||"},
    {"||..        %%%%%%%%  . . |%|...     %%%%%%%%%%%%%%     ..   %%%%.  ||"},
    {"||G.        |%|       . . |%|...    ............... |%| ..       .  ||"},
    {"||..        %%%%%%%%%%. . |%|...    %%%%%%%%%%%%    |%| ..   %%%%.  ||"},
    {"||..               |%|.             |%|......       |%| ..    |%|.  ||"},
    {"||..     ......... |%|.        P    |%|......|%|        ..    |%|.  ||"},
    {"||..|%|  |%|%%%|%|.|%|. |%|            ......|%|        ..|%| |%|.  ||"},
    {"||..|%|  |%|   |%|..    %%%%%%%%%%%%%  ......|%|         .|%|.      ||"},
    {"||..|%|  |%|   |%|..           ...|%|     %%%%%%        . |%|.      ||"},
    {"||..|%|            .           ...|%|               |%| ..|%|.      ||"},
    {"||..|%|  %%%%%%%%%%%%%%        ...|%|%%%%%%%%%%     |%| ..|%|%%%%%  ||"},
    {"||...............................................   |%| ..........  ||"},
    {"||   ............................................          .......  ||"},
    {"||..|%|  |%|   |%|..    %%%%%%%%%%%%%  ......|%|    |%| ..|%|.      ||"},
    {"||..|%|  |%|   |%|..           ...|%|     %%%%%%    |%| ..|%|.      ||"},
    {"||..|%|            .     G     ...|%|               |%| ..|%|.      ||"},
    {"||..|%|  %%%%%%%%%%%%%%        ...|%|%%%%%%%%%%     |%| ..|%|%%%%%  ||"},
    {"||...............................................   |%| ..........  ||"},
    {"||  ..G..........................................          .......  ||"},
    {"#####################################################################"}};
// Global Variable
int pacmanX = 9;  // X Coordinate of Pacman
int pacmanY = 31; // Y Coordinate of Pacman
int score = 0;
const int number = 4;
int ghostX = 19; // X Coordinate of Ghost
int ghostY = 25; // Y Coordinate of Ghost
int ghostX1 = 4;
int ghostY1 = 7;
int ghostX2 = 6;
int ghostY2 = 2;
int ghostX3 = 22;
int ghostY3 = 6;
char previousItem = ' ';
char previousItem1 = ' ';
char previousItem2 = ' ';
char previousitem = ' ';
char previousItem3 = ' ';
float distance1[number];
int idx;
int life = 3;
//----------------- prototype ----
void printMaze();
void movePacmanLeft();
void movePacmanRight();
void gotoxy(int x, int y);
void movePacmanUp();
void movePacmanDown();
void calculateScore();
bool ghostMovement();
bool ghostMovement1();
void printScore();
int ghostDirection();
bool ghostMovement2();
bool ghostMovement3();
void loadMaze();
float distancecalculater(int px, int py, int gx, int gy);
int shortdistance();

// Main Function
main()
{
    loadMaze();
    system("CLS");
    printMaze();
    maze[pacmanX][pacmanY] = 'p';
    gotoxy(pacmanX, pacmanY);
    cout << maze[pacmanX][pacmanY];
    bool gameRunning = true;
    bool gameRunning1 = true;
    bool gameRunning2 = true;
    bool gameRunning3 = true;
    while (gameRunning)
    {
        Sleep(100);
        printScore();
        gotoxy(31, 45);
        cout << "life:" << life << endl;
        if (life == 0)
            break;
        gameRunning = ghostMovement();
        gameRunning1 = ghostMovement1();
        gameRunning2 = ghostMovement2();
        gameRunning3 = ghostMovement3();
        if (GetAsyncKeyState(VK_LEFT))
        {
            movePacmanLeft(); // Function call to move Pacman towards left
        }
        if (GetAsyncKeyState(0x41))
        {
            movePacmanLeft();
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            movePacmanRight(); // Function call to move Pacman towards right
        }
        if (GetAsyncKeyState(VK_UP))
        {
            movePacmanUp(); // Function call to move Pacman towards up
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            movePacmanDown(); // Function call to move Pacman towards down
        }
        if (GetAsyncKeyState(VK_ESCAPE))
        {
            gameRunning = false;  // Stop the game
        }
        
    }
}
void printMaze()
{
    for (int row = 0; row < 24; row = row + 1)
    {
        for (int col = 0; col < 71; col = col + 1)
        {
            cout << maze[row][col];
        }
        cout << endl;
    }
}
void calculateScore()
{
    score = score + 1;
}
void printScore()
{
    gotoxy(30, 45);
    cout << endl<< "Score: " << score << endl;
}
void movePacmanRight()
{
    if (maze[pacmanX][pacmanY + 1] == ' ' || maze[pacmanX][pacmanY + 1] == '.')
    {
        maze[pacmanX][pacmanY] = ' ';
        gotoxy(pacmanX, pacmanY);
        cout << maze[pacmanX][pacmanY];
        pacmanY = pacmanY + 1;
        if (maze[pacmanX][pacmanY] == '.')
        {
            calculateScore();
        }
        maze[pacmanX][pacmanY] = 'P';
        gotoxy[pacmanX][pacmanY];
        cout << maze[pacmanX][pacmanY];
    }
}
void movePacmanLeft()
{
    if (maze[pacmanX][pacmanY - 1] == ' ' || maze[pacmanX][pacmanY - 1] == '.')
    {
        maze[pacmanX][pacmanY] = ' ';
        gotoxy(pacmanX, pacmanY);
        cout << " ";
        pacmanY--;
        if (maze[pacmanX][pacmanY] == '.')
        {
            calculateScore();
        }
        maze[pacmanX][pacmanY] = 'P';
        gotoxy(pacmanX, pacmanY);
        cout << "P";
    }
}

void movePacmanUp()
{
    if (maze[pacmanX - 1][pacmanY] == ' ' || maze[pacmanX - 1][pacmanY] == '.')
    {
        maze[pacmanX][pacmanY] = ' ';
        gotoxy(pacmanX, pacmanY);
        cout << maze[pacmanX][pacmanY];
        pacmanX = pacmanX - 1;
        if (maze[pacmanX][pacmanY] == '.')
        {
            calculateScore();
        }
        maze[pacmanX][pacmanY] = 'P';
        gotoxy(pacmanX, pacmanY);
        cout << maze[pacmanX][pacmanY];
    }
}
void movePacmanDown()
{
    if (maze[pacmanX + 1][pacmanY] == ' ' || maze[pacmanX + 1][pacmanY] == '.')
    {
        maze[pacmanX][pacmanY] = ' ';
        gotoxy(pacmanX, pacmanY);
        cout << " ";
        pacmanX ++;
        if (maze[pacmanX][pacmanY] == '.')
        {
            calculateScore();
        }
        maze[pacmanX][pacmanY] = 'P';
        gotoxy[pacmanX][pacmanY];
        cout << "P";
    }
}
int ghostDirection()
{
    srand(time(0));
    int result = 1 + (rand() % 4);
    return result;
}
int shortdistance()
{
    if(maze[ghostX][ghostY - 1] != '|' && maze[ghostX][ghostY - 1] != '%' && maze[ghostX][ghostY - 1] != '#')
    {distance1[0]=distancecalculater(pacmanX,pacmanY,ghostX,ghostY-1);}
    else 
    {distance1[0]=10000;}
    if(maze[ghostX][ghostY + 1] != '|' && maze[ghostX][ghostY + 1] != '%' && maze[ghostX][ghostY + 1] != '#')
    {distance1[1]=distancecalculater(pacmanX,pacmanY,ghostX,ghostY+1);}
    else 
   { distance1[1]=10000;}
    if(maze[ghostX-1][ghostY] != '|' && maze[ghostX-1][ghostY ] != '%' && maze[ghostX-1][ghostY] != '#')
    {distance1[2]=distancecalculater(pacmanX-1,pacmanY,ghostX,ghostY);}
    else 
   { distance1[2]=10000;}
    if(maze[ghostX+1][ghostY ] != '|' && maze[ghostX+1][ghostY] != '%' && maze[ghostX+1][ghostY] != '#')
    {distance1[3]=distancecalculater(pacmanX+1,pacmanY,ghostX,ghostY);}
    else 
   { distance1[3]=10000;}
    int index=1;
    float smallest=0;
    smallest=distance1[0];
    for(int i=0;i<4;i++)
    {
        if(smallest > distance1[i])
        {
            smallest=distance1[i];
            index=i;
        }
    }
    return index+1;

}
float distancecalculater(int px, int py, int gx, int gy)
{
    float x_axis=(px-gx);
    float y_axis=(py-gy);
    float square_x=pow(x_axis,2);
    float square_y=pow(y_axis,2);
    float add=square_x+square_y;
    float root=sqrt(add);
    return root;
}
bool ghostMovement()
{
    int value=shortdistance();
    
    if (value == 1)
    {
        if (maze[ghostX][ghostY - 1] == ' ' || maze[ghostX][ghostY - 1] == '.' || maze[ghostX][ghostY - 1] == 'P')
        {
            maze[ghostX][ghostY] = previousItem;
            gotoxy(ghostX, ghostY);
            cout << maze[ghostX][ghostY];
            ghostY = ghostY - 1;
            previousItem = maze[ghostX][ghostY];
            gotoxy(ghostX, ghostY);
            cout << previousItem;
            if (previousItem == 'P')
            {
                life--;
                gotoxy(pacmanX,pacmanY);
                cout<<" ";
            }
            maze[ghostX][ghostY] = 'G';
            gotoxy(ghostX, ghostY);
            cout << maze[ghostX][ghostY];
        }
    }
    if (value == 2)
    {
        if (maze[ghostX][ghostY + 1] == ' ' || maze[ghostX][ghostY + 1] == '.' || maze[ghostX][ghostY + 1] == 'P')
        {
            maze[ghostX][ghostY] = previousItem;
            gotoxy(ghostX, ghostY);
            cout << maze[ghostX][ghostY];
            ghostY = ghostY + 1;
            previousItem = maze[ghostX][ghostY];
            gotoxy(ghostX, ghostY);
            cout<<previousItem;
            if (previousItem == 'P')
            {
                life--;
                gotoxy(pacmanX,pacmanY);
                cout<<" ";
                return 1;
            }
            maze[ghostX][ghostY] = 'G';
            gotoxy(ghostX, ghostY);
            cout << maze[ghostX][ghostY];
        }
    }
    if (value == 3)
    {
        if (maze[ghostX - 1][ghostY] == ' ' || maze[ghostX - 1][ghostY] == '.' || maze[ghostX - 1][ghostY] == 'P')
        {
            maze[ghostX][ghostY] = previousItem;
            gotoxy(ghostX, ghostY);
            cout << maze[ghostX][ghostY];
            ghostX = ghostX - 1;
            previousItem = maze[ghostX][ghostY];
            gotoxy(ghostX, ghostY);
            cout<<previousItem;
            if (previousItem == 'P')
            {
                life--;
                gotoxy(pacmanX,pacmanY);
                cout<<" ";
                // 
                return 1;
            }
            maze[ghostX][ghostY] = 'G';
            gotoxy(ghostX, ghostY);
            cout << maze[ghostX][ghostY];
        }
    }
    if (value == 4)
    {
        if (maze[ghostX + 1][ghostY] == ' ' || maze[ghostX + 1][ghostY] == '.' || maze[ghostX + 1][ghostY] == 'P')
        {
            maze[ghostX][ghostY] = previousItem;
            gotoxy(ghostX, ghostY);
            cout << maze[ghostX][ghostY];
            ghostX = ghostX + 1;
            previousItem = maze[ghostX][ghostY];
            gotoxy(ghostX, ghostY);
            cout<<previousItem;
            if (previousItem == 'P')
            {
                life--;
                gotoxy(pacmanX,pacmanY);
                cout<<" ";
                return 1;
            }
            maze[ghostX][ghostY] = 'G';
            gotoxy(ghostX, ghostY);
            cout << maze[ghostX][ghostY];
        }
    }
    return 1;
}
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = y;
    coordinates.Y = x;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

//----------------------------for rendom motion--------------------
bool ghostMovement1()
{
    int value = ghostDirection();
    if (value == 1)
    {
        if (maze[ghostX1][ghostY1 - 1] == ' ' || maze[ghostX1][ghostY1 - 1] == '.' || maze[ghostX1][ghostY1 - 1] == 'P')
        {
            maze[ghostX1][ghostY1] = previousItem1;
            gotoxy(ghostX1, ghostY1);
            cout << maze[ghostX1][ghostY1];
            ghostY1 = ghostY1 - 1;
            previousItem1 = maze[ghostX1][ghostY1];
            gotoxy(ghostX1, ghostY1);
            cout << previousItem1;
            if (previousItem1 == 'P')
            {
                life--;
                gotoxy(pacmanX,pacmanY);
                cout<<" ";
                return 1;
            }
            maze[ghostX1][ghostY1] = 'G';
            gotoxy(ghostX1, ghostY1);
            cout << maze[ghostX1][ghostY1];
        }
    }
    if (value == 2)
    {
        if (maze[ghostX1][ghostY1 + 1] == ' ' || maze[ghostX1][ghostY1 + 1] == '.' || maze[ghostX1][ghostY1 + 1] == 'P')
        {
            maze[ghostX1][ghostY1] = previousItem1;
            gotoxy(ghostX1, ghostY1);
            cout << maze[ghostX1][ghostY1];
            ghostY1 = ghostY1 + 1;
            previousItem1 = maze[ghostX1][ghostY1];
            gotoxy(ghostX1, ghostY1);
            cout << previousItem1;
            if (previousItem1 == 'P')
            {
                life--;
                gotoxy(pacmanX,pacmanY);
                cout<<" ";
                return 1;
            }
            maze[ghostX1][ghostY1] = 'G';
            gotoxy(ghostX1, ghostY1);
            cout << maze[ghostX1][ghostY1];
        }
    }
    if (value == 3)
    {
        if (maze[ghostX1 - 1][ghostY1] == ' ' || maze[ghostX1 - 1][ghostY1] == '.' || maze[ghostX1 - 1][ghostY1] == 'P')
        {
            maze[ghostX1][ghostY1] = previousItem1;
            gotoxy(ghostX1, ghostY1);
            cout << maze[ghostX1][ghostY1];
            ghostX1 = ghostX1 - 1;
            previousItem1 = maze[ghostX1][ghostY1];
            gotoxy(ghostX1, ghostY1);
            cout << previousItem1;
            if (previousItem1 == 'P')
            {
                life--;
                gotoxy(pacmanX,pacmanY);
                cout<<" ";
                return 1;
            }
            maze[ghostX1][ghostY1] = 'G';
            gotoxy(ghostX1, ghostY1);
            cout << maze[ghostX1][ghostY1];
        }
    }
    if (value == 4)
    {
        if (maze[ghostX1 + 1][ghostY1] == ' ' || maze[ghostX1 + 1][ghostY1] == '.' || maze[ghostX1 + 1][ghostY1] == 'P')
        {
            maze[ghostX1][ghostY1] = previousItem1;
            gotoxy(ghostX1, ghostY1);
            cout << maze[ghostX1][ghostY1];
            ghostX1 = ghostX1 + 1;
            previousItem1 = maze[ghostX1][ghostY1];
            gotoxy(ghostX1, ghostY1);
            cout << previousItem1;
            if (previousItem1 == 'P')
            {
                life--;
                gotoxy(pacmanX,pacmanY);
                cout<<" ";
                return 1;
            }
            maze[ghostX1][ghostY1] = 'G';
            gotoxy(ghostX1, ghostY1);
            cout << maze[ghostX1][ghostY1];
        }
    }
    return 1;
}
//---------------------------------for vertical -----------------------
bool ghostMovement2()
{
    if (maze[ghostX2 - 1][ghostY2] == ' ' || maze[ghostX2 - 1][ghostY2] == '.' || maze[ghostX2 - 1][ghostY2] == 'P')
    {

        maze[ghostX2][ghostY2] = previousItem2;
        gotoxy(ghostX2, ghostY2);
        cout << maze[ghostX2][ghostY2];
        ghostX2 = ghostX2 - 1;
        previousItem2 = maze[ghostX2][ghostY2];
        gotoxy(ghostX2, ghostY2);
        cout << previousItem2;
        if (previousItem2 == 'P')
        {
            life--;
            gotoxy(pacmanX,pacmanY);
            cout<<" ";
            return 1;
            
        }
        maze[ghostX2][ghostY2] = 'G';
        gotoxy(ghostX2, ghostY2);
        cout << maze[ghostX2][ghostY2];
    }
    if (maze[ghostX2 - 1][ghostY2] == '#')
    {
        int i = 0;
        while (i < 21)
        {
            maze[ghostX2][ghostY2] = previousItem2;
            gotoxy(ghostX2, ghostY2);
            cout << maze[ghostX2][ghostY2];
            ghostX2 = ghostX2 + 1;
            previousItem2 = maze[ghostX2][ghostY2];
            gotoxy(ghostX2, ghostY2);
            cout<<previousItem2;
            if (previousItem2 == 'P')
            {
                life--;
                gotoxy(pacmanX,pacmanY);
                cout<<" ";
                return 1;
            }
            maze[ghostX2][ghostY2] = 'G';
            gotoxy(ghostX2, ghostY2);
            cout << maze[ghostX2][ghostY2];
            if (maze[ghostX2 + 1][ghostY2] == '#')
                break;
            i++;
        }
    }
}
//-------------------------for horizontal ------------------------
bool ghostMovement3()
{
    if (maze[ghostX3][ghostY3 - 1] == ' ' || maze[ghostX3][ghostY3 - 1] == '.' || maze[ghostX3][ghostY3 - 1] == 'P')
    {

        maze[ghostX3][ghostY3] = previousItem3;
        gotoxy(ghostX3, ghostY3);
        cout<<maze[ghostX3][ghostY3];
        ghostY3 = ghostY3 - 1;
        previousItem3 = maze[ghostX3][ghostY3];
        gotoxy(ghostX3, ghostY3);
        cout << previousItem3;
        if (previousItem3 == 'P')
        {
            life--;
            gotoxy(pacmanX,pacmanY);
            cout<<" ";
            return 1;
            
        }
        maze[ghostX3][ghostY3] = 'G';
        gotoxy(ghostX3, ghostY3);
        cout << maze[ghostX3][ghostY3];
    }
    if (maze[ghostX3][ghostY3 - 1] == '|')
    {
        int i = 0;
        while (i < 62)
        {
            maze[ghostX3][ghostY3] = previousItem3;
            gotoxy(ghostX3, ghostY3);
            cout<<maze[ghostX3][ghostY3];
            ghostY3 = ghostY3 + 1;
            previousItem3 = maze[ghostX3][ghostY3];
            gotoxy(ghostX3, ghostY3);
            cout << previousItem3;
            if (previousItem3 == 'P')
            {
                life--;
                gotoxy(pacmanX,pacmanY);
                cout<<" ";
                return 1;
                
            }
            maze[ghostX3][ghostY3] = 'G';
            gotoxy(ghostX3, ghostY3);
            cout << maze[ghostX3][ghostY3];
            i++;
        }
    }
}
void loadMaze()
{
    fstream Mazfile;
    string line;
    Mazfile.open("maze1.txt", ios::in);
    for (int i = 0; i < 24; i++)
    {
        getline(Mazfile, line);
        for (int j = 0; j < 71; j++)
        {
            maze[i][j] = line[j];
        }
    }
    Mazfile.close();
}
