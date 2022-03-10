#include <iostream>
#include <fstream>
#include <time.h>
#include <conio.h>
#include <windows.h>
using namespace std;
char option = ' ';
int lives = 10;
int lvl = 1;
bool NextLevel = 0;
int enemyfinal = 0;
int enemy1 = 0;
int enemy2 = 0;
int enemy3 = 0;
int color_final_enemy = 1;
int count = 0;
int stage = 1;
int enemy3lives = 5;
int enemy1lives = 5;
int enemy2lives = 5;
bool ENEMY1TRUE = 1;
bool ENEMY2TRUE = 1;
bool fenemy = 1;
bool ENEMY3TRUE = 1;
bool ENEMY4TRUE = 1;
int ship_uper_part_x = 20;
int ship_uper_part_y = 27;
int ship_inner_part_x = 21;
int ship_inner_part_y = 27;
int ship_right_part_y = 28;
int ship_right_part_x = 21;
int ship_left_part_x = 21;
int ship_left_part_y = 26;
char previousitem = ' ';
// __________________final enemy _________________
int bala_1x_upper = 2;
int bala_1y_upper = 38;
int bala_2x_upper = 2;
int bala_2y_upper = 39;
int bala_3x_upper = 2;
int bala_3y_upper = 40;
int shooter1x = 3;
int shooter1y = 38;
int shooter2x = 3;
int shooter2y = 39;

int shooter3x = 3;
int shooter3y = 40;
int shooter4x = 3;
int shooter4y = 37;
int shooter5x = 3;
int shooter5y = 41;
int down_bala1x = 4;
int down_bala1y = 38;
int down_bala2x = 4;
int down_bala2y= 39;

int down_bala3x = 4;
int down_bala3y = 40;
// ___________________________ eniemies level 1 _______________________

int first_enemy_1x = 2;
int first_enemy_2x = 38;
int first_location_x = 3;
int first_location_y = 38;
int last_enemy_lives = 8;
int first_right_loc_x = 39;
int first_right_loc_y = 3;
int first_left_loc_x = 3;
int first_left_loc_y = 36;
int first_end_x = 4;
int first_end_y = 38;
// enemy 3
int third_enemy_1x = 1;
int third_enemy_1y = 30;
int third_location_x = 2;
int third_location_y = 30;

int third_right_loc_x = 31;
int third_right_loc_y = 2;
int third_left_loc_x = 2; // 
int third_left_loc_y = 29;
int third_end_x = 3;
int third_end_y = 30;
// enemy 2nd
int second_enemy_1x = 2;
int second_enemy_1y = 4;
int second_location_x = 3;
int second_location_y = 4;
int second_right_loc_x = 5;
int second_right_loc_y = 3;
int second_left_loc_x = 3;
int second_left_loc_y = 2;
int second_end_x = 4;
int second_end_y = 4;

char upperitem = ' ';
char inneritem = ' ';
char leftitem = ' ';
char rightitem = ' ';
int a = 0;
//---------------------------------------------------------------------------------
//_______________________________________________function prototypes____________________________
void moveleft();
void moveright();
void moveup();
void movedown(); 
//----------------------motion of ship---------------------------------
//________________________________firing functios of ship___________________________
void movingshoot();
void shoot();
//___________________________________end of firing function______________________

//------------------------------------others function of game---------------------
char level_of_menu();
void liveschecker();
void gotoxy(int x_axis, int y_axis);
void printmaze();
int finalenemydirection(); 
void level();
void setcolor( unsigned char color );
void header();
void instruction();
void loadMaze();
//---------------------------------motion of enemy----------------------------
void thirdenemymotion(); 
void firstenemymotion();
void bossenemy();
void secondenemymotion();
//_______________________________________________end of motion of nemy____________________
//-------------------------------fiing of enem-----------------------------
void bossenemyshoot();
void enemy_2nd_shoots();
void enemy_one_shoots();
void enemy_3rd_shoots();
void endshootsof_firstenemy();
void endshoot_of_boss_enemy();
void endshoots_of_3rd_enemy();
void endshoots_of_2nd_enemy();
//______________________________________end of funciton prototypes_______________________________
char plane[2][3] = {{' ', '^', ' '},
                    {'<', '=', '>'}};
char maze[24][71] = {{"#####################################################################"},
                     {"|                                                                   |"},
                     {"|                                                                   |"},
                     {"|                                                                   |"},
                     {"|                                                                   |"},
                     {"|                                                                   |"},
                     {"|                                                                   |"},
                     {"|                                                                   |"},
                     {"|                                                                   |"},
                     {"|                                                                   |"},
                     {"|                                                                   |"},
                     {"|                                                                   |"},
                     {"|                                                                   |"},
                     {"|                                                                   |"},
                     {"|                                                                   |"},
                     {"|                                                                   |"},
                     {"|                                                                   |"},
                     {"|                                                                   |"},
                     {"|                                                                   |"},
                     {"|                                                                   |"},
                     {"|                                                                   |"},
                     {"|                                                                   |"},
                     {"|                                                                   |"},
                     {"#####################################################################"}};
//____________________________________________________start of main() function____________________________________________
main()
{
    loadMaze();
    header();
    instruction();
    getch();
    while (true)
    {
        char select_option = level_of_menu();
        system("Color 04");
        system("cls");
        printmaze();
    
        gotoxy(ship_uper_part_y, ship_uper_part_x);
        cout << "^";
        gotoxy(ship_inner_part_y, ship_inner_part_x);
        cout << "=";
        gotoxy(ship_left_part_y, ship_left_part_x);
        cout << "<";
        gotoxy(ship_right_part_y, ship_right_part_x);
        cout << ">";
        if (select_option == '1')
        {
            for(int i=1;i<23;i++)
            {
                for(int y=1;y<69;y++)
                {
                    if(maze[i][y] != '|' )
                    {
                        maze[i][y] =' ';
                    }
                }
            }
            lives=3;
            while (true)
            {
                Sleep(100);

                if (GetAsyncKeyState(VK_LEFT))
                {
                    moveleft(); // Function call to move Pacman towards left
                }

                if (GetAsyncKeyState(VK_RIGHT))
                {
                    moveright(); // Function call to move Pacman towards right
                }
                if (GetAsyncKeyState(VK_UP))
                {
                    moveup(); // Function call to move Pacman towards up
                }
                if (GetAsyncKeyState(VK_DOWN))
                {
                    movedown(); // Function call to move Pacman towards down
                }
                if (GetAsyncKeyState(VK_ESCAPE))
                {

                    break;
                }
                if (GetAsyncKeyState(VK_SPACE))
                {
                    shoot(); // Function call to move Pacman towards down
                }

                movingshoot();
                if (ENEMY1TRUE)
                {
                    firstenemymotion();
                }
                else
                {
                    endshootsof_firstenemy();
                }
                enemy_one_shoots();
                if (ENEMY3TRUE)
                {

                    thirdenemymotion();
                }
                else
                {
                    endshoots_of_3rd_enemy();
                }
                enemy_3rd_shoots();
                if (ENEMY2TRUE)
                {
                    secondenemymotion();
                }
                else
                {
                    endshoots_of_2nd_enemy();
                }
                enemy_2nd_shoots();
                if (ENEMY1TRUE == 0 && ENEMY2TRUE == 0 && ENEMY3TRUE == 0)
                {
                    system("cls");
                    count++;
                    lvl = 2;
                    stage = 2;
                    select_option = '2';
                    enemy1lives = 5;
                    enemy2lives = 5;
                    enemy3lives = 5;
                    ENEMY2TRUE = 1;
                    ENEMY1TRUE = 1;
                    ENEMY3TRUE = 1;
                    NextLevel = 1;
                    getch();
                    break;
                }
                // enemy_2nd_shoots();
                gotoxy(0, 26);
                liveschecker();

                gotoxy(20, 28);
                level();
                if (lives <= 0)
                {
                    break;
                }
            }
        }
        else if (select_option == '2')
        {
            for(int i=1;i<23;i++)
            {
                for(int y=1;y<69;y++)
                {
                    if(maze[i][y] != '|' )
                    {
                        maze[i][y] =' ';
                    }
                }
            }
            system("cls");
            printmaze();
            lives=3;
            gotoxy(ship_uper_part_y, ship_uper_part_x);
            cout << "^";
            gotoxy(ship_inner_part_y, ship_inner_part_x);
            cout << "=";
            gotoxy(ship_left_part_y, ship_left_part_x);
            cout << "<";
            gotoxy(ship_right_part_y, ship_right_part_x);
            cout << ">";
          
            ENEMY1TRUE = 1;
            ENEMY2TRUE = 1;
            ENEMY3TRUE = 1;
            lvl = 2;
            stage = 2;
            first_enemy_1x = 2;
            first_enemy_2x = 38;
            first_location_x = 3;
            first_location_y = 38;

            first_right_loc_x = 39;
            first_right_loc_y = 3;
            first_left_loc_x = 3;
            first_left_loc_y = 36;
            first_end_x = 4;
            first_end_y = 38;
            //
            second_enemy_1x = 2;
            second_enemy_1y = 4;
            second_location_x = 3;
            second_location_y = 4;
            second_right_loc_x = 5;
            second_right_loc_y = 3;
            second_left_loc_x = 3;
            second_left_loc_y = 2;
            second_end_x = 4;
            second_end_y = 4;
            //
            third_enemy_1x = 1;
            third_enemy_1y = 30;
            third_location_x = 2;
            third_location_y = 30;

            third_right_loc_x = 31;
            third_right_loc_y = 2;
            third_left_loc_y = 29;
            third_left_loc_x = 2;
            third_end_y = 30;
            third_end_x = 3;
            while (1)
            {
                Sleep(100);

                if (GetAsyncKeyState(VK_LEFT))
                {
                    moveleft(); // Function call to move Pacman towards left
                }

                if (GetAsyncKeyState(VK_RIGHT))
                {
                    moveright(); // Function call to move Pacman towards right
                }
                if (GetAsyncKeyState(VK_UP))
                {
                    moveup(); // Function call to move Pacman towards up
                }
                if (GetAsyncKeyState(VK_DOWN))
                {
                    movedown(); // Function call to move Pacman towards down
                }
                if (GetAsyncKeyState(VK_ESCAPE))
                {

                    break;
                }
                if (GetAsyncKeyState(VK_SPACE))
                {
                    shoot(); // Function call to move Pacman towards down
                }
                movingshoot();
                if (ENEMY1TRUE)
                {
                    firstenemymotion();
                }
                else
                {
                    endshootsof_firstenemy();
                }
                enemy_one_shoots();
                //
                if (ENEMY3TRUE)
                {
                    thirdenemymotion();
                }
                else
                {
                    endshoots_of_3rd_enemy();
                }
                enemy_3rd_shoots();
                if (ENEMY2TRUE)
                {
                    secondenemymotion();
                }
                else
                {
                    endshoots_of_2nd_enemy();
                }
                enemy_2nd_shoots();
                if (ENEMY1TRUE == 0 && ENEMY2TRUE == 0 && ENEMY3TRUE == 0)
                {
                    // level_of_menu();
                    cout << "level  2   completed" << endl;
                    break;
                }
                // enemy_2nd_shoots();
                gotoxy(0, 26);
                liveschecker();
                gotoxy(0, 27);
                cout << "enemy one lifes  " << enemy1lives << endl;
                gotoxy(0, 28);
                cout << "enemy two lifes " << enemy2lives << endl;
                gotoxy(0, 29);
                cout << "enemy three lifes " << enemy3lives << endl;
                gotoxy(0, 32);
                cout << "stage number  " << stage << endl;
                gotoxy(20, 35);
                level();
                if (lives <= 0)
                {
                    break;
                }
            }
        }
        else if (select_option == '3')
        {
            for(int i=1;i<23;i++)
            {
                for(int y=1;y<69;y++)
                {
                    if(maze[i][y] != '|' )
                    {
                        maze[i][y] =' ';
                    }
                }
            }
            fenemy=1;
            system("cls");
            printmaze();
            lives=3;
            gotoxy(ship_uper_part_y, ship_uper_part_x);
            cout << "^";
            gotoxy(ship_inner_part_y, ship_inner_part_x);
            cout << "=";
            gotoxy(ship_left_part_y, ship_left_part_x);
            cout << "<";
            gotoxy(ship_right_part_y, ship_right_part_x);
            cout << ">";
         
            ENEMY1TRUE = 1;
            ENEMY2TRUE = 1;
            ENEMY3TRUE = 1;
            lvl = 2;
            stage = 2;
            //upper
            bala_1x_upper = 2;
            bala_1y_upper = 38;
            bala_2x_upper = 2;
            bala_2y_upper = 39;
            bala_3x_upper = 2;
            bala_3y_upper = 40;
            shooter1x = 3;
            shooter1y = 38;
            shooter2x = 3;
            shooter2y = 39;

            shooter3x = 3;
            shooter3y = 40;
            shooter4x = 3;
            shooter4y = 37;
            shooter5x = 3;
            shooter5y = 41;
            down_bala1x = 4;
            down_bala1y = 38;
            down_bala2x = 4;
            down_bala2y = 39;

            down_bala3x = 4;
            down_bala3y = 40;

            first_enemy_1x = 2;
            first_enemy_2x = 38;
            first_location_x = 3;
            first_location_y = 38;

            first_right_loc_x = 39;
            first_right_loc_y = 3;
            first_left_loc_x = 3;
            first_left_loc_y = 36;
            first_end_x = 4;
            first_end_y = 38;
            //
            second_enemy_1x = 2;
            second_enemy_1y = 4;
            second_location_x = 3;
            second_location_y = 4;
            second_right_loc_x = 5;
            second_right_loc_y = 3;
            second_left_loc_x = 3;
            second_left_loc_y = 2;
            second_end_x = 4;
            second_end_y = 4;
            //
            third_enemy_1x = 1;
            third_enemy_1y = 30;
            third_location_x = 2;
            third_location_y = 30;

            third_right_loc_x = 31;
            third_right_loc_y = 2;
            third_left_loc_y = 29;
            third_left_loc_x = 2;
            third_end_y = 30;
            third_end_x = 3;
            while (1)
            {
                Sleep(100);

                if (GetAsyncKeyState(VK_LEFT))
                {
                    moveleft(); // Function call to move Pacman towards left
                }

                if (GetAsyncKeyState(VK_RIGHT))
                {
                    moveright(); // Function call to move Pacman towards right
                }
                if (GetAsyncKeyState(VK_UP))
                {
                    moveup(); // Function call to move Pacman towards up
                }
                if (GetAsyncKeyState(VK_DOWN))
                {
                    movedown(); // Function call to move Pacman towards down
                }
                if (GetAsyncKeyState(VK_ESCAPE))
                {

                    break;
                }
                if (GetAsyncKeyState(VK_SPACE))
                {
                    shoot(); // Function call to move Pacman towards down
                }
                movingshoot();
                if (fenemy)
                {
                    bossenemy();
                }
                else
                {
                    endshoot_of_boss_enemy();
                }
                bossenemyshoot();
                liveschecker();
                gotoxy(20, 26);
                cout << "boss enemy lifes:";
                cout << last_enemy_lives << endl;
                if (lives <= 0)
                {
                    break;
                }
            }
        }
        else if (select_option == '4')
        {
            break;
        }
        else
        {
            continue;
        }
    }
}
//__________________________________end of main() function____________________________

//------------------------------------------------------------------------------------------
void header()
{
    system("Color 80");
    cout<<"--------------------------------------------------------------------------------------------------------------------------------------------------- :"<<endl;
    cout<<"                                                                                                                                                    :"<<endl;
    cout<<"---------------           /\\             _____________     ____________      __________  @      _______________                 __________________  :"<<endl;
    cout<<"|                        /  \\           |                 |                 |            |     |                |            |          |           :"<<endl;
    cout<<"|                       /    \\          |                 |                 |            |     |                |            |          |           :"<<endl;
    cout<<"|                      /      \\         |                 |                 |            |     |                |            |          |           :"<<endl;
    cout<<"|                     /        \\        |                 |                 |            |     |                |            |          |           :"<<endl;
    cout<<":--------------      /          \\       |                 |____________     |__________  |     |   ___________  |------------|          |           :"<<endl;
    cout<<"              |     /____________\\      |                 |                 |            |     |  :           | |            |          |           :"<<endl;
    cout<<"              |    /              \\     |                 |                 |            |     |  :           | |            |          |           :"<<endl;
    cout<<"              |   /                \\    |                 |                 |            |     |  :           | |            |          |           :"<<endl;
    cout<<"              |  /                  \\   |                 |                 |            |     |              | |            |          |           :"<<endl;
    cout<<"--------------: /                    \\  |_____________    |____________     |            |     |______________| |            |          |           :"<<endl;
    cout<<"                                                                                                                                                    :"<<endl;
    cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------:"<<endl;
}
void instruction()
{
    setcolor(0x0C);
    cout<<"game instriuctions for player:"<<endl;
    cout<<"left arrow key for left move:"<<endl;
    cout<<"right  arrow key for right move:"<<endl;
    cout<<"upper arrow key for upper move:"<<endl;
    cout<<"down arrow key for down move:"<<endl;
    cout<<"space key for fire:"<<endl;
    cout<<"---------------------------"<<endl;
    cout<<"press any key to continue:"<<endl;
}
void printmaze()
{
  
    for (int row = 0; row < 24; row++)
    {
        for (int col = 0; col < 71; col++)
        {
            cout << maze[row][col];
        }
        cout << "\n";
    }
   
}
void gotoxy(int x_axis, int y_axis)
{
    COORD coordinates;
    coordinates.X = x_axis;
    coordinates.Y = y_axis;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void moveleft()
{
    if (maze[ship_left_part_x][ship_left_part_y - 1] != '|')
    {
        setcolor( 0x0A );
        maze[ship_uper_part_x][ship_uper_part_y] = ' ';
        maze[ship_inner_part_x][ship_inner_part_y] = ' ';
        maze[ship_left_part_x][ship_left_part_y] = ' ';
        maze[ship_right_part_x][ship_right_part_y] = ' ';
        gotoxy(ship_uper_part_y, ship_uper_part_x);
        cout << " ";
        gotoxy(ship_inner_part_y, ship_inner_part_x);
        cout << " ";
        gotoxy(ship_left_part_y, ship_left_part_x);
        cout << " ";
        gotoxy(ship_right_part_y, ship_right_part_x);
        cout << " ";

        ship_uper_part_y = ship_uper_part_y - 1;
        ship_inner_part_y = ship_inner_part_y - 1;
        ship_left_part_y = ship_left_part_y - 1;
        ship_right_part_y = ship_right_part_y - 1;

        maze[ship_uper_part_x][ship_uper_part_y] = '^';

        maze[ship_inner_part_x][ship_inner_part_y] = '=';
        maze[ship_left_part_x][ship_left_part_y] = '<';
        maze[ship_right_part_x][ship_right_part_y] = '>';
       
        gotoxy(ship_uper_part_y, ship_uper_part_x);
        cout << "^";
        gotoxy(ship_inner_part_y, ship_inner_part_x);
        cout << "=";
        gotoxy(ship_left_part_y, ship_left_part_x);
        cout << "<";
        gotoxy(ship_right_part_y, ship_right_part_x);
        cout << ">";
      
    }
}
void moveright()
{
    if (maze[ship_right_part_x][ship_right_part_y + 1] != '|')
    {
        setcolor( 0x0A );
        maze[ship_uper_part_x][ship_uper_part_y] = ' ';
        maze[ship_inner_part_x][ship_inner_part_y] = ' ';
        maze[ship_left_part_x][ship_left_part_y] = ' ';
        maze[ship_right_part_x][ship_right_part_y] = ' ';
        gotoxy(ship_uper_part_y, ship_uper_part_x);
        cout << " ";
        gotoxy(ship_inner_part_y, ship_inner_part_x);
        cout << " ";
        gotoxy(ship_left_part_y, ship_left_part_x);
        cout << " ";
        gotoxy(ship_right_part_y, ship_right_part_x);
        cout << " ";

        ship_uper_part_y = ship_uper_part_y + 1;
        ship_inner_part_y = ship_inner_part_y + 1;
        ship_left_part_y = ship_left_part_y + 1;
        ship_right_part_y = ship_right_part_y + 1;

        maze[ship_uper_part_x][ship_uper_part_y] = '^';
        maze[ship_inner_part_x][ship_inner_part_y] = '=';
        maze[ship_left_part_x][ship_left_part_y] = '<';
        maze[ship_right_part_x][ship_right_part_y] = '>';
       
        gotoxy(ship_uper_part_y, ship_uper_part_x);
        cout << "^";
        gotoxy(ship_inner_part_y, ship_inner_part_x);
        cout << "=";
        gotoxy(ship_left_part_y, ship_left_part_x);
        cout << "<";
        gotoxy(ship_right_part_y, ship_right_part_x);
        cout << ">";
      
    }
}
void moveup()
{
    if (maze[ship_uper_part_x - 1][ship_uper_part_y] != '#')
    {
        setcolor( 0x0A );
        maze[ship_uper_part_x][ship_uper_part_y] = ' ';
        maze[ship_inner_part_x][ship_inner_part_y] = ' ';
        maze[ship_left_part_x][ship_left_part_y] = ' ';
        maze[ship_right_part_x][ship_right_part_y] = ' ';
        gotoxy(ship_uper_part_y, ship_uper_part_x);
        cout << " ";
        gotoxy(ship_inner_part_y, ship_inner_part_x);
        cout << " ";
        gotoxy(ship_left_part_y, ship_left_part_x);
        cout << " ";
        gotoxy(ship_right_part_y, ship_right_part_x);
        cout << " ";

        ship_uper_part_x = ship_uper_part_x - 1;
        ship_inner_part_x = ship_inner_part_x - 1;
        ship_left_part_x = ship_left_part_x - 1;
        ship_right_part_x = ship_right_part_x - 1;
        maze[ship_uper_part_x][ship_uper_part_y] = '^';
        maze[ship_inner_part_x][ship_inner_part_y] = '=';
        maze[ship_left_part_x][ship_left_part_y] = '<';
        maze[ship_right_part_x][ship_right_part_y] = '>';
    
        gotoxy(ship_uper_part_y, ship_uper_part_x);
        cout << "^";
        gotoxy(ship_inner_part_y, ship_inner_part_x);
        cout << "=";
        gotoxy(ship_left_part_y, ship_left_part_x);
        cout << "<";
        gotoxy(ship_right_part_y, ship_right_part_x);
        cout << ">";
       
    }
}
void movedown()
{

    if (maze[ship_inner_part_x + 1][ship_inner_part_y] != '#')
    {
        setcolor( 0x0A );
        maze[ship_uper_part_x][ship_uper_part_y] = ' ';
        maze[ship_inner_part_x][ship_inner_part_y] = ' ';
        maze[ship_left_part_x][ship_left_part_y] = ' ';
        maze[ship_right_part_x][ship_right_part_y] = ' ';
        gotoxy(ship_uper_part_y, ship_uper_part_x);
        cout << " ";
        gotoxy(ship_inner_part_y, ship_inner_part_x);
        cout << " ";
        gotoxy(ship_left_part_y, ship_left_part_x);
        cout << " ";
        gotoxy(ship_right_part_y, ship_right_part_x);
        cout << " ";

        ship_uper_part_x = ship_uper_part_x + 1;
        ship_inner_part_x = ship_inner_part_x + 1;
        ship_left_part_x = ship_left_part_x + 1;
        ship_right_part_x = ship_right_part_x + 1;
        maze[ship_uper_part_x][ship_uper_part_y] = '^';
        maze[ship_inner_part_x][ship_inner_part_y] = '=';
        maze[ship_left_part_x][ship_left_part_y] = '<';
        maze[ship_right_part_x][ship_right_part_y] = '>';
      
        gotoxy(ship_uper_part_y, ship_uper_part_x);
        cout << "^";
        gotoxy(ship_inner_part_y, ship_inner_part_x);
        cout << "=";
        gotoxy(ship_left_part_y, ship_left_part_x);
        cout << "<";
        gotoxy(ship_right_part_y, ship_right_part_x);
        cout << ">";
        
    }
}
//-------------------changing colour----------------------
void setcolor( unsigned char color )
{
  SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), color );
}
//----------------------------------------------------
void level()
{
    setcolor( 0x0A );
    cout << "level is " << count + 1;
}
void shoot()
{

    gotoxy(ship_uper_part_y, ship_uper_part_x - 1);
    cout << "!";
    maze[ship_uper_part_x - 1][ship_uper_part_y] = '!';
}
void movingshoot()
{
    for (int row = 0; row < 24; row++)
    {
        for (int col = 0; col < 71; col++)
        {

            if (maze[row][col] == '!')
            {
                gotoxy(col, row);
                cout << " ";
                maze[row][col] = ' ';
                if (maze[row - 1][col] != '#')
                {
                    setcolor(0x0C);
                    if (ENEMY2TRUE)
                    {
                        if (((row - 1) == second_end_x && col == second_end_y) || ((row - 1) == second_left_loc_x && col == second_left_loc_y) || (second_right_loc_y == (row - 1) && second_right_loc_x == col))
                        {
                            maze[second_location_x][second_location_y] = ' ';
                            gotoxy(second_location_y, second_location_x);
                            cout << " ";
                            maze[second_left_loc_x][second_left_loc_y] = ' ';
                            gotoxy(second_left_loc_y, second_left_loc_x);
                            cout << " ";
                            maze[second_right_loc_y][second_right_loc_x] = ' ';
                            gotoxy(second_right_loc_x, second_right_loc_y);
                            cout << " ";
                            maze[second_end_x][second_end_y] = ' ';
                            gotoxy(second_end_y, second_end_x);
                            cout << " ";
                            maze[second_enemy_1x][second_enemy_1y] = ' ';
                            gotoxy(second_enemy_1y, second_enemy_1x);
                            cout << " ";
                            if (lvl == 1 && stage == 1)
                            {
                                ENEMY2TRUE = 0;
                            }
                            if (lvl == 2 && enemy2lives == 0 && stage == 2)
                            {
                                ENEMY2TRUE = 0;
                            }
                            else
                            {
                                enemy2lives--;
                            }
                        }
                    }
                    // final enemy lives
                    if (fenemy)
                    {
                        if (((row - 1) == down_bala1x && col == down_bala1y) || ((row - 1) == down_bala2x && col == down_bala2y))
                        {
                            maze[down_bala1x][down_bala1y] = ' ';
                            gotoxy(down_bala1y, down_bala1x);
                            cout << " ";
                            maze[down_bala2x][down_bala2y] = ' ';
                            gotoxy(down_bala2y, down_bala2x);
                            cout << " ";
                            maze[down_bala3x][down_bala3y] = ' ';
                            gotoxy(down_bala3y, down_bala3x);
                            cout << " ";
                            maze[bala_1x_upper][bala_1y_upper] = ' ';
                            gotoxy(bala_1y_upper, bala_1x_upper);
                            cout << " ";
                            maze[bala_2x_upper][bala_2y_upper] = ' ';
                            gotoxy(bala_2y_upper, bala_2x_upper);
                            cout << " ";
                            maze[bala_3x_upper][bala_3y_upper] = ' ';
                            gotoxy(bala_3y_upper, bala_3x_upper);
                            cout << " ";
                            maze[shooter1x][shooter1y] = ' ';
                            gotoxy(shooter1y, shooter1x);
                            cout << " ";
                            maze[shooter2x][shooter2y] = ' ';
                            gotoxy(shooter2y, shooter2x);
                            cout << " ";
                            maze[shooter3x][shooter3y] = ' ';
                            gotoxy(shooter3y, shooter3x);
                            cout << " ";
                            maze[shooter4x][shooter4y] = ' ';
                            gotoxy(shooter4y, shooter4x);
                            cout << " ";
                            maze[shooter5x][shooter5y] = ' ';
                            gotoxy(shooter5y, shooter5x);
                            cout << " ";
                            last_enemy_lives--;
                            if (last_enemy_lives == 0)
                            {
                                fenemy = 0;
                            }
                        }
                    }

                    if (ENEMY1TRUE)
                    {
                        if (((row - 1) == first_end_x && col == first_end_y) || ((row - 1) == first_left_loc_x && col == first_left_loc_y) || (first_right_loc_y == (row - 1) && first_right_loc_x == col))
                        {
                            maze[first_location_x][first_location_y] = ' ';
                            gotoxy(first_location_y, first_location_x);
                            cout << " ";
                            maze[first_left_loc_x][first_left_loc_y] = ' ';
                            gotoxy(first_left_loc_y, first_left_loc_x);
                            cout << " ";
                            maze[first_right_loc_y][first_right_loc_x] = ' ';
                            gotoxy(first_right_loc_x, first_right_loc_y);
                            cout << " ";
                            maze[first_end_x][first_end_y] = ' ';
                            gotoxy(first_end_y, first_end_x);
                            cout << " ";
                            maze[first_enemy_1x][first_enemy_2x] = ' ';
                            gotoxy(first_enemy_2x, first_enemy_1x);
                            cout << " ";

                            if (lvl == 1 && stage == 1)
                            {
                                ENEMY1TRUE = 0;
                            }
                            if (lvl == 2 && enemy1lives == 0 && stage == 2)
                            {
                                ENEMY1TRUE = 0;
                            }
                            else
                            {
                                enemy1lives--;
                            }
                            
                        }
                    }
                    if (ENEMY3TRUE)
                    {
                        if (((row - 1) == third_end_x && col == third_end_y) || ((row - 1) == third_left_loc_x && col == third_left_loc_y) || (third_right_loc_y == (row - 1) && third_right_loc_x == col))
                        {
                            maze[third_location_x][third_location_y] = ' ';
                            gotoxy(third_location_y, third_location_x);
                            cout << " ";
                            maze[third_left_loc_x][third_left_loc_y] = ' ';
                            gotoxy(third_left_loc_y, third_left_loc_x);
                            cout << " ";
                            maze[third_right_loc_y][third_right_loc_x] = ' ';
                            gotoxy(third_right_loc_x, third_right_loc_y);
                            cout << " ";
                            maze[third_end_x][third_end_y] = ' ';
                            gotoxy(third_end_y, third_end_x);
                            cout << " ";
                            maze[third_enemy_1x][third_enemy_1y] = ' ';
                            gotoxy(third_enemy_1y, third_enemy_1x);
                            cout << " ";

                            if (lvl == 1 && stage == 1)
                            {
                                ENEMY3TRUE = 0;
                            }
                            if (lvl == 2 && enemy3lives == 0 && stage == 2)
                            {
                                ENEMY3TRUE = 0;
                            }
                            else
                            {
                                enemy3lives--;
                            }
                        }
                    }
                    gotoxy(col, row - 1);
                    cout << "!";
                    maze[row - 1][col] = '!';
                }
            }
        }
    }
}
char level_of_menu()
{
    cout<<endl;
    cout << "1_first level" << endl;
    cout << "2_2nd level" << endl;
    cout << "3_3rd level" << endl;
    cout << "4_exit" << endl;
    cin >> option;
    return option;
}

void thirdenemymotion()
{
    if (enemy3 == 0)
    {
        if (maze[third_right_loc_y][third_right_loc_x + 1] != '|')
        {
            setcolor(0x0A);
            // right part of enemy
            previousitem = maze[third_right_loc_y][third_right_loc_x + 1];
            gotoxy(third_right_loc_x, third_right_loc_y);
            cout << previousitem;
            maze[third_right_loc_y][third_right_loc_x] = previousitem;
            third_right_loc_x = third_right_loc_x + 1;
            maze[third_right_loc_y][third_right_loc_x] = '$';
            gotoxy(third_right_loc_x, third_right_loc_y);
            cout << "$";
            previousitem = maze[third_left_loc_x][third_left_loc_y + 1];
            gotoxy(third_left_loc_y, third_left_loc_x);
            cout << previousitem;
            maze[third_left_loc_x][third_left_loc_y] = previousitem;
            third_left_loc_y = third_left_loc_y + 1;
            maze[third_left_loc_x][third_left_loc_y] = '$';
            gotoxy(third_left_loc_y, third_left_loc_x);
            cout << "$";

            // upper part of enemy
            previousitem = maze[third_enemy_1x][third_enemy_1y + 1];
            gotoxy(third_enemy_1y, third_enemy_1x);
            cout << previousitem;
            maze[third_enemy_1x][third_enemy_1y] = previousitem;
            third_enemy_1y = third_enemy_1y + 1;
            gotoxy(third_enemy_1y, third_enemy_1x);
            cout << "$";
            maze[third_enemy_1x][third_enemy_1y] = '$';
            //  iner part of enemy
            previousitem = maze[third_location_x][third_location_y + 1];
            gotoxy(third_location_y, third_location_x);
            cout << previousitem;
            third_location_y = third_location_y + 1;
            gotoxy(third_location_y, third_location_x);
            cout << "$";
            maze[third_location_x][third_location_y];
            // lower part of enemy
            previousitem = maze[third_end_x][third_end_y + 1];
            gotoxy(third_end_y, third_end_x);
            cout << previousitem;
            maze[third_end_x][third_end_y] = previousitem;
            third_end_y = third_end_y + 1;
            gotoxy(third_end_y, third_end_x);
            cout << "*";
            maze[third_end_x][third_end_y] = '*';
        }
        if (maze[third_right_loc_y][third_right_loc_x + 1] == '|')
        {
            enemy3 = 1;
        }
    }
    if (enemy3 == 1)
    {

        if (maze[third_right_loc_y][third_right_loc_x - 1] != '|')
        {
            setcolor(0x0A);
            // right part of enemy
            previousitem = maze[third_right_loc_y][third_right_loc_x - 1];
            gotoxy(third_right_loc_x, third_right_loc_y);
            cout << previousitem;
            maze[third_right_loc_y][third_right_loc_x] = previousitem;
            third_right_loc_x = third_right_loc_x - 1;
            maze[third_right_loc_y][third_right_loc_x] = '$';
            gotoxy(third_right_loc_x, third_right_loc_y);
            cout << "$";
            // left part of enemy
            previousitem = maze[third_left_loc_x][third_left_loc_y - 1];
            gotoxy(third_left_loc_y, third_left_loc_x);
            cout << previousitem;
            maze[third_left_loc_x][third_left_loc_y] = previousitem;
            third_left_loc_y = third_left_loc_y - 1;
            maze[third_left_loc_x][third_left_loc_y] = '$';
            gotoxy(third_left_loc_y, third_left_loc_x);
            cout << "$";

            // upper part of enemy
            previousitem = maze[third_enemy_1x][third_enemy_1y - 1];
            gotoxy(third_enemy_1y, third_enemy_1x);
            cout << previousitem;
            maze[third_enemy_1x][third_enemy_1y] = previousitem;
            third_enemy_1y = third_enemy_1y - 1;
            gotoxy(third_enemy_1y, third_enemy_1x);
            cout << "$";
            maze[third_enemy_1x][third_enemy_1y] = '$';
            //  iner part of enemy
            previousitem = maze[third_location_x][third_location_y - 1];
            gotoxy(third_location_y, third_location_x);
            cout << previousitem;
            third_location_y = third_location_y - 1;
            gotoxy(third_location_y, third_location_x);
            cout << "$";
            maze[third_location_x][third_location_y];
            // lower part of enemy
            previousitem = maze[third_end_x][third_end_y - 1];
            gotoxy(third_end_y, third_end_x);
            cout << previousitem;
            maze[third_end_x][third_end_y] = previousitem;
            third_end_y = third_end_y - 1;
            gotoxy(third_end_y, third_end_x);
            cout << "*";
            maze[third_end_x][third_end_y] = '*';
        }
        if (maze[third_right_loc_y][third_right_loc_x - 1] == '|')
        {
            enemy3 = 0;
        }
    }
    
}
void firstenemymotion()
{
    if (enemy1 == 0)
    {
        if (maze[first_right_loc_y][first_right_loc_x + 1] != '|')
        {
            setcolor( 0x0B );
            // right part of enemy
            previousitem = maze[first_right_loc_y][first_right_loc_x + 1];
            gotoxy(first_right_loc_x, first_right_loc_y);
            cout << previousitem;
            maze[first_right_loc_y][first_right_loc_x] = previousitem;
            first_right_loc_x = first_right_loc_x + 1;
            maze[first_right_loc_y][first_right_loc_x] = 's';
            gotoxy(first_right_loc_x, first_right_loc_y);
            cout << "s";
            previousitem = maze[first_left_loc_x][first_left_loc_y + 1];
            gotoxy(first_left_loc_y, first_left_loc_x);
            cout << previousitem;
            maze[first_left_loc_x][first_left_loc_y] = previousitem;
            first_left_loc_y = first_left_loc_y + 1;
            maze[first_left_loc_x][first_left_loc_y] = 's';
            gotoxy(first_left_loc_y, first_left_loc_x);
            cout << "s";

            // upper part of enemy
            previousitem = maze[first_enemy_1x][first_enemy_2x + 1];
            gotoxy(first_enemy_2x, first_enemy_1x);
            cout << previousitem;
            maze[first_enemy_1x][first_enemy_2x] = previousitem;
            first_enemy_2x = first_enemy_2x + 1;
            gotoxy(first_enemy_2x, first_enemy_1x);
            cout << "s";
            maze[first_enemy_1x][first_enemy_2x] = 's';
            //  iner part of enemy
            previousitem = maze[first_location_x][first_location_y + 1];
            gotoxy(first_location_y, first_location_x);
            cout << previousitem;
            first_location_y = first_location_y + 1;
            gotoxy(first_location_y, first_location_x);
            cout << "s";
            maze[first_location_x][first_location_y];
            // lower part of enemy
            previousitem = maze[first_end_x][first_end_y + 1];
            gotoxy(first_end_y, first_end_x);
            cout << previousitem;
            maze[first_end_x][first_end_y] = previousitem;
            first_end_y = first_end_y + 1;
            gotoxy(first_end_y, first_end_x);
            cout << "?";
            maze[first_end_x][first_end_y] = '?';
        }
        if (maze[first_right_loc_y][first_right_loc_x + 1] == '|')
        {
            enemy1 = 1;
        }
    }
    if (enemy1 == 1)
    {

        if (maze[first_right_loc_y][first_right_loc_x - 1] != '|')
        {
            setcolor( 0x0B );
            // right part of enemy
            previousitem = maze[first_right_loc_y][first_right_loc_x - 1];
            gotoxy(first_right_loc_x, first_right_loc_y);
            cout << previousitem;
            maze[first_right_loc_y][first_right_loc_x] = previousitem;
            first_right_loc_x = first_right_loc_x - 1;
            maze[first_right_loc_y][first_right_loc_x] = 's';
            gotoxy(first_right_loc_x, first_right_loc_y);
            cout << "s";
            // left part of enemy
            previousitem = maze[first_left_loc_x][first_left_loc_y - 1];
            gotoxy(first_left_loc_y, first_left_loc_x);
            cout << previousitem;
            maze[first_left_loc_x][first_left_loc_y] = previousitem;
            first_left_loc_y = first_left_loc_y - 1;
            maze[first_left_loc_x][first_left_loc_y] = 's';
            gotoxy(first_left_loc_y, first_left_loc_x);
            cout << "s";

            // upper part
            previousitem = maze[first_enemy_1x][first_enemy_2x - 1];
            gotoxy(first_enemy_2x, first_enemy_1x);
            cout << previousitem;
            maze[first_enemy_1x][first_enemy_2x] = previousitem;
            first_enemy_2x = first_enemy_2x - 1;
            gotoxy(first_enemy_2x, first_enemy_1x);
            cout << "s";
            maze[first_enemy_1x][first_enemy_2x] = 's';
            //  iner part
            previousitem = maze[first_location_x][first_location_y - 1];
            gotoxy(first_location_y, first_location_x);
            cout << previousitem;
            first_location_y = first_location_y - 1;
            gotoxy(first_location_y, first_location_x);
            cout << "s";
            maze[first_location_x][first_location_y];
            // lower part
            previousitem = maze[first_end_x][first_end_y - 1];
            gotoxy(first_end_y, first_end_x);
            cout << previousitem;
            maze[first_end_x][first_end_y] = previousitem;
            first_end_y = first_end_y - 1;
            gotoxy(first_end_y, first_end_x);
            cout << "?";
            maze[first_end_x][first_end_y] = '?';
        }
        if (maze[first_right_loc_y][first_right_loc_x - 1] == '|')
        {
            enemy1 = 0;
        }
    }
   
}
// bossenemy
void bossenemy()
{
    if (enemyfinal == 0)
    {
        if (maze[shooter5x][shooter5y + 1] != '|')
        {
            setcolor( 0x0C);
            // UPPER PORTION
            // UPPER 3
            previousitem = maze[bala_3x_upper][bala_3y_upper + 1];
            gotoxy(bala_3y_upper, bala_3x_upper);
            cout << previousitem;
            maze[bala_3x_upper][bala_3y_upper] = previousitem;
            bala_3y_upper = bala_3y_upper + 1;
            maze[bala_3x_upper][bala_3y_upper] = '=';
            gotoxy(bala_3y_upper, bala_3x_upper);
            cout << "=";
            previousitem = ' ';
            // UPPER 2
            previousitem = maze[bala_2x_upper][bala_2y_upper + 1];
            gotoxy(bala_2y_upper, bala_2x_upper);
            cout << previousitem;
            maze[bala_2x_upper][bala_2y_upper] = previousitem;
            bala_2y_upper = bala_2y_upper + 1;
            maze[bala_2x_upper][bala_2y_upper] = '=';
            gotoxy(bala_2y_upper, bala_2x_upper);
            cout << "=";
            // UPPER 1
            previousitem = maze[bala_1x_upper][bala_1y_upper + 1];
            gotoxy(bala_1y_upper, bala_1x_upper);
            cout << previousitem;
            maze[bala_1x_upper][bala_1y_upper] = previousitem;
            bala_1y_upper = bala_1y_upper + 1;
            maze[bala_1x_upper][bala_1y_upper] = '=';
            gotoxy(bala_1y_upper, bala_1x_upper);
            cout << "=";

            // middle portion right
            previousitem = maze[shooter5x][shooter5y + 1];
            gotoxy(shooter5y, shooter5x);
            cout << previousitem;
            maze[shooter5x][shooter5y] = previousitem;
            shooter5y = shooter5y + 1;
            maze[shooter5x][shooter5y] = '>';
            gotoxy(shooter5y, shooter5x);
            cout << ">";
            ///------------------testing method----------------
            char pervious1 = ' ';
            char pervious2 = ' ';
            // middle 3
            previousitem = maze[shooter3x][shooter3y + 1];
            gotoxy(shooter3y, shooter3x);
            cout << previousitem;
            maze[shooter3x][shooter3y] = previousitem;
            shooter3y = shooter3y + 1;
            maze[shooter3x][shooter3y] = ' ';
            gotoxy(shooter3y, shooter3x);
            cout << " ";
            // middle 2
            pervious2 = maze[shooter2x][shooter2y + 1];
            gotoxy(shooter2y, shooter2x);
            cout << pervious2;
            maze[shooter2x][shooter2y] = pervious2;
            shooter2y = shooter2y + 1;
            maze[shooter2x][shooter2y] = 'b';
            gotoxy(shooter2y, shooter2x);
            cout << "b";
            // middle 1
            pervious1 = maze[shooter1x][shooter1y + 1];
            gotoxy(shooter1y, shooter1x);
            cout << pervious1;
            maze[shooter1x][shooter1y] = pervious1;
            shooter1y = shooter1y + 1;
            maze[shooter1x][shooter1y] = ' ';
            gotoxy(shooter1y, shooter1x);
            cout << " ";
            // middle portion left
            previousitem = maze[shooter4x][shooter4y + 1];
            gotoxy(shooter4y, shooter4x);
            cout << previousitem;
            maze[shooter4x][shooter4y] = previousitem;
            shooter4y = shooter4y + 1;
            maze[shooter4x][shooter4y] = '<';
            gotoxy(shooter4y, shooter4x);
            cout << "<";

            // down PORTION
            // down 3
            previousitem = maze[down_bala3x][down_bala3y + 1];
            gotoxy(down_bala3y, down_bala3x);
            cout << previousitem;
            maze[down_bala3x][down_bala3y] = previousitem;
            down_bala3y = down_bala3y + 1;
            maze[down_bala3x][down_bala3y] = '+';
            gotoxy(down_bala3y, down_bala3x);
            cout << "+";
            // down 2
            previousitem = maze[down_bala2x][down_bala2y + 1];
            gotoxy(down_bala2y, down_bala2x);
            cout << previousitem;
            maze[down_bala2x][down_bala2y] = previousitem;
            down_bala2y = down_bala2y + 1;
            maze[down_bala2x][down_bala2y] = '+';
            gotoxy(down_bala2y, down_bala2x);
            cout << "+";
            // down 1
            previousitem = maze[down_bala1x][down_bala1y + 1];
            gotoxy(down_bala1y, down_bala1x);
            cout << previousitem;
            maze[down_bala1x][down_bala1y] = previousitem;
            down_bala1y = down_bala1y + 1;
            maze[down_bala1x][down_bala1y] = '+';
            gotoxy(down_bala1y, down_bala1x);
            cout << "+";
        }
        else
        {
            enemyfinal = 1;
            color_final_enemy++;
        }
    }

    if (enemyfinal == 1)
    {
        if (maze[shooter4x][shooter4y - 1] != '|')
        {
            setcolor( 0x0C);
            previousitem = ' ';
            // middle portion left
            previousitem = maze[shooter4x][shooter4y - 1];
            gotoxy(shooter4y, shooter4x);
            cout << previousitem;
            maze[shooter4x][shooter4y] = previousitem;
            shooter4y = shooter4y - 1;
            maze[shooter4x][shooter4y] = '<';
            gotoxy(shooter4y, shooter4x);
            cout << "<";
            // middle 1

            previousitem = maze[shooter1x][shooter1y - 1];
            gotoxy(shooter1y, shooter1x);
            cout << previousitem;
            maze[shooter1x][shooter1y] = previousitem;
            shooter1y = shooter1y - 1;
            maze[shooter1x][shooter1y] = ' ';
            gotoxy(shooter1y, shooter1x);
            cout << " ";
            // middle 2
            previousitem = maze[shooter2x][shooter2y - 1];
            gotoxy(shooter2y, shooter2x);
            cout << previousitem;
            maze[shooter2x][shooter2y] = previousitem;
            shooter2y = shooter2y - 1;
            maze[shooter2x][shooter2y] = 'b';
            gotoxy(shooter2y, shooter2x);
            cout << "b";
            // middle 3
            previousitem = maze[shooter3x][shooter3y - 1];
            gotoxy(shooter3y, shooter3x);
            cout << previousitem;
            maze[shooter3x][shooter3y] = previousitem;
            shooter3y = shooter3y - 1;
            maze[shooter3x][shooter3y] = ' ';
            gotoxy(shooter3y, shooter3x);
            cout << " ";
            // middle portion right
            previousitem = maze[shooter5x][shooter5y - 1];
            gotoxy(shooter5y, shooter5x);
            cout << previousitem;
            maze[shooter5x][shooter5y] = previousitem;
            shooter5y = shooter5y - 1;
            maze[shooter5x][shooter5y] = '>';
            gotoxy(shooter5y, shooter5x);
            cout << ">";
            // UPPER PORTION
            // UPPER 1
            previousitem = maze[bala_1x_upper][bala_1y_upper - 1];
            gotoxy(bala_1y_upper, bala_1x_upper);
            cout << previousitem;
            maze[bala_1x_upper][bala_1y_upper] = previousitem;
            bala_1y_upper = bala_1y_upper - 1;
            maze[bala_1x_upper][bala_1y_upper] = '=';
            gotoxy(bala_1y_upper, bala_1x_upper);
            cout << "=";
            // UPPER 2
            previousitem = maze[bala_2x_upper][bala_2y_upper - 1];
            gotoxy(bala_2y_upper, bala_2x_upper);
            cout << previousitem;
            maze[bala_2x_upper][bala_2y_upper] = previousitem;
            bala_2y_upper = bala_2y_upper - 1;
            maze[bala_2x_upper][bala_2y_upper] = '=';
            gotoxy(bala_2y_upper, bala_2x_upper);
            cout << "=";
            // UPPER 3
            previousitem = maze[bala_3x_upper][bala_3y_upper - 1];
            gotoxy(bala_3y_upper, bala_3x_upper);
            cout << previousitem;
            maze[bala_3x_upper][bala_3y_upper] = previousitem;
            bala_3y_upper = bala_3y_upper - 1;
            maze[bala_3x_upper][bala_3y_upper] = '=';
            gotoxy(bala_3y_upper, bala_3x_upper);
            cout << "_";
            // down PORTION
            // down 1
            previousitem = maze[down_bala1x][down_bala1y - 1];
            gotoxy(down_bala1y, down_bala1x);
            cout << previousitem;
            maze[down_bala1x][down_bala1y] = previousitem;
            down_bala1y = down_bala1y - 1;
            maze[down_bala1x][down_bala1y] = '+';
            gotoxy(down_bala1y, down_bala1x);
            cout << "+";
            // down 2
            previousitem = ' ';
            previousitem = maze[down_bala2x][down_bala2y - 1];
            gotoxy(down_bala2y, down_bala2x);
            cout << previousitem;
            maze[down_bala2x][down_bala2y] = previousitem;
            down_bala2y = down_bala2y - 1;
            maze[down_bala2x][down_bala2y] = '+';
            gotoxy(down_bala2y, down_bala2x);
            cout << "+";
            // down 3

            previousitem = maze[down_bala3x][down_bala3y - 1];
            gotoxy(down_bala3y, down_bala3x);
            cout << previousitem;
            maze[down_bala3x][down_bala3y] = previousitem;
            down_bala3y = down_bala3y - 1;
            maze[down_bala3x][down_bala3y] = '+';
            gotoxy(down_bala3y, down_bala3x);
            cout << "+";
        }
        if (maze[shooter4x][shooter4y - 1] == '|')
        {
            color_final_enemy++;
            enemyfinal = 0;
        }
    }

}
void secondenemymotion()
{
    
    if (enemy2 == 0)
    {
        if (maze[second_right_loc_y][second_right_loc_x + 1] != '|')
        {
            setcolor( 0x0A );
            // right
            previousitem = maze[second_right_loc_y][second_right_loc_x + 1];
            gotoxy(second_right_loc_x, second_right_loc_y);
            cout << previousitem;
            maze[second_right_loc_y][second_right_loc_x] = previousitem;
            second_right_loc_x = second_right_loc_x + 1;
            maze[second_right_loc_y][second_right_loc_x] = '~';
            gotoxy(second_right_loc_x, second_right_loc_y);
            cout << "~";

            // left
            previousitem = maze[second_left_loc_x][second_left_loc_y + 1];
            gotoxy(second_left_loc_y, second_left_loc_x);
            cout << previousitem;
            maze[second_left_loc_x][second_left_loc_y] = previousitem;
            second_left_loc_y = second_left_loc_y + 1;
            maze[second_left_loc_x][second_left_loc_y] = '~';
            gotoxy(second_left_loc_y, second_left_loc_x);
            cout << "~";

            // upper
            previousitem = maze[second_enemy_1x][second_enemy_1y + 1];
            gotoxy(second_enemy_1y, second_enemy_1x);
            cout << previousitem;
            maze[second_enemy_1x][second_enemy_1y] = previousitem;
            second_enemy_1y = second_enemy_1y + 1;
            gotoxy(second_enemy_1y, second_enemy_1x);
            cout << "_";
            maze[second_enemy_1x][second_enemy_1y] = '_';
            //  iner
            previousitem = maze[second_location_x][second_location_y + 1];
            gotoxy(second_location_y, second_location_x);
            cout << previousitem;
            second_location_y = second_location_y + 1;
            gotoxy(second_location_y, second_location_x);
            cout << "_";
            maze[second_location_x][second_location_y];
            // lower
            previousitem = maze[second_end_x][second_end_y + 1];
            gotoxy(second_end_y, second_end_x);
            cout << previousitem;
            maze[second_end_x][second_end_y] = previousitem;
            second_end_y = second_end_y + 1;
            gotoxy(second_end_y, second_end_x);
            cout << "+";
            maze[second_end_x][second_end_y] = '+';
        }
        if (maze[second_right_loc_y][second_right_loc_x + 1] == '|')
        {
            enemy2 = 1;
        }
    }
    if (enemy2 == 1)
    {
        if (maze[second_right_loc_y][second_right_loc_x - 1] != '|')
        {
            setcolor( 0x0A );
            // right
            previousitem = maze[second_right_loc_y][second_right_loc_x - 1];
            second_right_loc_x = second_right_loc_x - 1;
            maze[second_right_loc_y][second_right_loc_x] = '>';
            gotoxy(second_right_loc_x, second_right_loc_y);
            cout << ">";
            gotoxy(second_right_loc_x + 1, second_right_loc_y);
            cout << previousitem;
            maze[second_right_loc_y][second_right_loc_x + 1] = previousitem;

            // left
            previousitem = maze[second_left_loc_x][second_left_loc_y - 1];
            second_left_loc_y = second_left_loc_y - 1;
            maze[second_left_loc_x][second_left_loc_y] = '<';
            gotoxy(second_left_loc_y, second_left_loc_x);
            cout << "<";
            gotoxy(second_left_loc_y + 1, second_left_loc_x);
            cout << previousitem;
            maze[second_left_loc_x][second_left_loc_y + 1] = previousitem;

            // upper
            previousitem = maze[second_enemy_1x][second_enemy_1y - 1];
            second_enemy_1y = second_enemy_1y - 1;
            gotoxy(second_enemy_1y, second_enemy_1x);
            cout << "_";
            maze[second_enemy_1x][second_enemy_1y] = '_';
            gotoxy(second_enemy_1y + 1, second_enemy_1x);
            cout << previousitem;
            maze[second_enemy_1x][second_enemy_1y + 1] = previousitem;

            //  iner
            previousitem = maze[second_location_x][second_location_y - 1];
            second_location_y = second_location_y - 1;
            gotoxy(second_location_y, second_location_x);
            cout << "_";
            gotoxy(second_location_y + 1, second_location_x);
            cout << previousitem;

            maze[second_location_x][second_location_y + 1] = previousitem;
            // lower
            previousitem = maze[second_end_x][second_end_y - 1];
            second_end_y = second_end_y - 1;
            gotoxy(second_end_y, second_end_x);
            cout << "*";
            maze[second_end_x][second_end_y] = '*';
            gotoxy(second_end_y + 1, second_end_x);
            cout << previousitem;
            maze[second_end_x][second_end_y + 1] = previousitem;
        }
        if (maze[second_right_loc_y][second_right_loc_x - 1] == '|')
        {
            enemy2 = 0;
        }
    }
  
}
void liveschecker()
{   
    gotoxy(45,30);
    cout << "lives is "; 
    cout << lives;   
}

// final enemy shoot
// final enemy shoot
int finalenemydirection()
{
    srand(time(0));
    int result = 0;
    result = 1 + (rand() % 3);
    return result;
}
void bossenemyshoot()
{
    int value = finalenemydirection();
    Sleep(100);
    if (value == 1)
    {
        setcolor(0x0C);
        if (ENEMY2TRUE)
        {
            if (maze[down_bala1x + 1][down_bala1y] != '#')
            {
                maze[down_bala1x + 1][down_bala1y] = 'o';
                gotoxy(down_bala1y,down_bala1x + 1);
                cout << "o";
            }

            for (int row = 24; row > 0; row--)
            {
                for (int col = 0; col < 71; col++)
                {
                    if (maze[row][col] == 'o')
                    {
                        maze[row][col] = ' ';
                        gotoxy(col, row);
                        cout << " ";

                        if (maze[row + 1][col] != '#')
                        {
                            if ((ship_uper_part_x == row + 1 && ship_uper_part_y == col) || (ship_left_part_x == row + 1 && ship_left_part_y == col) || (ship_right_part_x == row + 1 && ship_right_part_y == col))
                            {
                                lives--;
                            }
                            else
                            {
                                maze[row + 1][col] = 'o';
                                gotoxy(col, row + 1);
                                cout << "o";
                            }
                        }
                    }
                }
            }
        }
    }
    //   down part 2
    if (value == 2)
    {
        setcolor(0x0C);
        if (ENEMY2TRUE)
        {
            if (maze[down_bala2x + 1][down_bala2y] != '#')
            {
                maze[down_bala2x + 1][down_bala2y] = 'o';
                gotoxy(down_bala2y,
                       down_bala2x + 1);
                cout << "o";
            }

            for (int row = 24; row > 0; row--)
            {
                for (int col = 0; col < 71; col++)
                {
                    if (maze[row][col] == 'o')
                    {
                        maze[row][col] = ' ';
                        gotoxy(col, row);
                        cout << " ";

                        if (maze[row + 1][col] != '#')
                        {
                            if ((ship_uper_part_x == row + 1 && ship_uper_part_y == col) || (ship_left_part_x == row + 1 && ship_left_part_y == col) || (ship_right_part_x == row + 1 && ship_right_part_y == col))
                            {
                                lives--;
                            }
                            else
                            {
                                maze[row + 1][col] = 'o';
                                gotoxy(col, row + 1);
                                cout << "o";
                            }
                        }
                    }
                }
            }
        }
    }
    // down part 3
    if (value == 3)
    {
        if (ENEMY2TRUE)
        {
            setcolor(0x0C);
            if (maze[down_bala3x + 1][down_bala3y] != '#')
            {
                maze[down_bala3x + 1][down_bala3y] = 'o';
                gotoxy(down_bala3y,
                       down_bala3x + 1);
                cout << "o";
            }

            for (int row = 24; row > 0; row--)
            {
                for (int col = 0; col < 71; col++)
                {
                    if (maze[row][col] == 'o')
                    {
                        maze[row][col] = ' ';
                        gotoxy(col, row);
                        cout << " ";

                        if (maze[row + 1][col] != '#')
                        {
                            if ((ship_uper_part_x == row + 1 && ship_uper_part_y == col) || (ship_left_part_x == row + 1 && ship_left_part_y == col) || (ship_right_part_x == row + 1 && ship_right_part_y == col))
                            {
                                lives--;
                            }
                            else
                            {
                                maze[row + 1][col] = 'o';
                                gotoxy(col, row + 1);
                                cout << "o";
                            }
                        }
                    }
                }
            }
        }
    }
}
void enemy_2nd_shoots()
{
    if (ENEMY2TRUE)
    {
        if (maze[second_end_x + 1][second_end_y] != '#')
        {
            maze[second_end_x + 1][second_end_y] = '%';
            gotoxy(second_end_y,
                   second_end_x + 1);
            cout << "%";
        }

        for (int row = 24; row > 0; row--)
        {
            for (int col = 0; col < 71; col++)
            {
                if (maze[row][col] == '%')
                {
                    maze[row][col] = ' ';
                    gotoxy(col, row);
                    cout << " ";

                    if (maze[row + 1][col] != '#')
                    {
                        setcolor(0x0D);
                        if ((ship_uper_part_x == row + 1 && ship_uper_part_y == col) || (ship_left_part_x == row + 1 && ship_left_part_y == col) || (ship_right_part_x == row + 1 && ship_right_part_y == col))
                        {
                            lives--;
                        }
                        else
                        {
                            maze[row + 1][col] = '%';
                            gotoxy(col, row + 1);
                            cout << "%";
                        }
                    }
                }
            }
        }
    }
}
void endshootsof_firstenemy()
{
    for (int row = 24; row > 0; row--)
    {
        for (int col = 0; col < 71; col++)
        {
            if (maze[row][col] == '@')
            {
                maze[row][col] = ' ';
                gotoxy(col, row);
                cout << " ";
            }
        }
    }
}
void endshoot_of_boss_enemy()
{
    for (int row = 24; row > 0; row--)
    {
        for (int col = 0; col < 71; col++)
        {
            if (maze[row][col] == 'o')
            {
                setcolor(0x0E);
                maze[row][col] = ' ';
                gotoxy(col, row);
                cout << " ";
            }
        }
    }
}
void endshoots_of_3rd_enemy()
{
    for (int row = 24; row > 0; row--)
    {
        for (int col = 0; col < 71; col++)
        {
            if (maze[row][col] == '&')
            {
                maze[row][col] = ' ';
                gotoxy(col, row);
                cout << " ";
            }
        }
    }
}
void endshoots_of_2nd_enemy()
{
    for (int row = 24; row > 0; row--)
    {
        for (int col = 0; col < 71; col++)
        {
            if (maze[row][col] == '%')
            {
                maze[row][col] = ' ';
                gotoxy(col, row);
                cout << " ";
            }
        }
    }
}
// 2 shoots
void enemy_one_shoots()
{
    if (ENEMY1TRUE)
    {
        if (maze[first_end_x + 1][first_end_y] != '#')
        {
            maze[first_end_x + 1][first_end_y] = '@';
            gotoxy(first_end_y, first_end_x + 1);
            cout << "@";
        }
        for (int row = 24; row > 0; row--)
        {
            for (int col = 0; col < 71; col++)
            {
                if (maze[row][col] == '@')
                {
                    maze[row][col] = ' ';
                    gotoxy(col, row);
                    cout << " ";

                    if (maze[row + 1][col] != '#')
                    {

                        setcolor(0x0D);
                        if ((ship_uper_part_x == row + 1 && ship_uper_part_y == col) || (ship_left_part_x == row + 1 && ship_left_part_y == col) || (ship_right_part_x == row + 1 && ship_right_part_y == col))

                        {
                            lives--;
                        }
                        else
                        {
                            maze[row + 1][col] = '@';
                            gotoxy(col, row + 1);
                            cout << "@";
                        }
                    }
                }
            }
        }
    }
}
void enemy_3rd_shoots()
{
    if (ENEMY3TRUE)
    {
        if (maze[third_end_x + 1][third_end_y] != '#')
        {
            maze[third_end_x + 1][third_end_y] = '&';
            gotoxy(third_end_y, third_end_x + 1);
            cout << "&";
        }
        for (int row = 24; row > 0; row--)
        {
            for (int col = 0; col < 71; col++)
            {
                if (maze[row][col] == '&')
                {
                    maze[row][col] = ' ';
                    gotoxy(col, row);
                    cout << " ";

                    if (maze[row + 1][col] != '#')
                    {
                        setcolor(0x0D);
                        if ((ship_uper_part_x == row + 1 && ship_uper_part_y == col) || (ship_left_part_x == row + 1 && ship_left_part_y == col) || (ship_right_part_x == row + 1 && ship_right_part_y == col))
                        {
                            lives--;
                        }
                        else
                        {
                            maze[row + 1][col] = '&';
                            gotoxy(col, row + 1);
                            cout << "&";
                        }
                    }
                }
            }
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