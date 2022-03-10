#include <iostream>
#include <windows.h>
using namespace std;

char maze[5][5] = {
    {'-', '#', '#', '-', '#'},
    {'#', '-', '-', '#', '-'},
    {'-', '#', '-', '-', '-'},
    {'#', '-', '#', '-', '#'},
    {'#', '-', '-', '-', '-'}};

void displaycharacter();
void timeTick();
void setcolor( unsigned char color );

main()
{
    while(true)
    {
        Sleep(500); 
        system("cls");
        // setcolor(0x0D);
        displaycharacter();
        timeTick();
        if(GetAsyncKeyState(VK_ESCAPE))
        {
            break;
        }
    }
}

void displaycharacter()
{
    setcolor(0x0C);
    cout<<endl<<endl;
    for(int x = 0; x < 5; x++)
    {
        for(int y = 0; y < 5; y++)
        {
            cout<<"\t"<<maze[x][y];
        }
        cout<<endl<<endl;
    }
}

void timeTick()
{
    char o[5];
    for(int r = 0; r < 5; r++)
    {
        setcolor(0x0D);
        o[r] = maze[4][r];
    }
    
    for(int x = 4; x >= 1; x--)
    {
        for(int y = 0; y < 5; y++)
        {
            setcolor(0x0D);
            maze[x][y] = maze[x-1][y];
        }
    }
    
    for(int r = 0; r < 5; r++)
    {
        setcolor(0x0D);
        maze[0][r] = o[r];
    }
}

void setcolor( unsigned char color )
{
  SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), color );
}