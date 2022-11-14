#include <iostream>
#include <time.h>
#include <math.h>
#include <conio.h>
#include <windows.h>
using namespace std;
char maze[24][71] = {{"#####################################################################"},
                     {"||.. .....................................................  ......  ||"},
                     {"||.. %%%%%%%%%%%%%%%%        ...     %%%%%%%%%%%%%%  |%|..   %%%%   ||"},
                     {"||..        |%|   |%|     |%|...     |%|        |%|  |%|..    |%|   ||"},
                     {"||..        |%|   |%|     |%|...     |%|        |%|  |%|..    |%|   ||"},
                     {"||..        %%%%%%%%  . . |%|...     %%%%%%%%%%%%%%     ..   %%%%.  ||"},
                     {"||..        |%|       . . |%|...    ............... |%| ..       .  ||"},
                     {"||..        %%%%%%%%%%. . |%|...    %%%%%%%%%%%%    |%| ..   %%%%.  ||"},
                     {"||..               |%|.             |%|......       |%| ..    |%|.  ||"},
                     {"||..     ......... |%|.        P    |%|......|%|        ..    |%|.  ||"},
                     {"||..|%|  |%|%%%|%|.|%|. |%|            ......|%|        ..|%| |%|.  ||"},
                     {"||..|%|  |%|   |%|..    %%%%%%%%%%%%%  ......|%|         .|%|.      ||"},
                     {"||..|%|  |%|   |%|..           ...|%|     %%%%%%        . |%|.      ||"},
                     {"||..|%|            .           ...|%|               |%| ..|%|.      ||"},
                     {"||..|%|  %%%%%%%%%%%%%% G      ...|%|%%%%%%%%%%     |%| ..|%|%%%%%  ||"},
                     {"||...............................................   |%| ..........  ||"},
                     {"||G   ............................................         .......  ||"},
                     {"||..|%|  |%|   |%|..    %%%%%%%%%%%%%  ......|%|    |%| ..|%|.      ||"},
                     {"||..|%|  |%|   |%|..           ...|%|     %%%%%%    |%| ..|%|.      ||"},
                     {"||..|%|            .     G     ...|%|               |%| ..|%|.      ||"},
                     {"||..|%|  %%%%%%%%%%%%%%        ...|%|%%%%%%%%%%     |%| ..|%|%%%%%  ||"},
                     {"||...............................................   |%| ..........  ||"},
                     {"||  .............................................          .......  ||"},
                     {"##################################################################### "}};

int pacmanX = 9;  // X Coordinate of Pacman
int pacmanY = 31; // Y Coordinate of Pacman
int ghostX = 19;
int ghostY = 25;
int ghostX2 = 16;
int ghostY2 = 2;
int IntGhostX = 15;
int IntGhostY = 24;
int livesCount = 0;
int gameRunning = 0;
int score = 0;
char tempvalue = ' ';
char tempvalue2 = ' ';
// Function Prototype void printMaze();
void gotoxy(int x, int y);
void printMaze();
void printscore();
void calculatescore();
void movePacmanLeft();
void movePacmanRight();
void movePacmanUP();
void movePacmanDown();
void ghostmovement();
void moveGhostLeft();
void moveGhostRight();
void moveGhostUP();
void moveGhostDown();
bool g2move = 1;
void ghost2movement();
void moveGhost2Left();
void moveGhost2Right();

// ghost3movement
void ghost3movement();
void moveGhost3UP();
void moveGhost3Down();
// ghost4movement
void ghost4movement();
void moveGhost4Left();
void moveGhost4Right();
void moveGhost4UP();
void moveGhost4Down();
// Global Parameters char maze[10][10] = {
bool checkghost(int x, int y, int x1, int y1);
// Main Function
main()
{
    bool gameRunning = true;
    system("CLS");
    printMaze();
    gotoxy(pacmanY, pacmanX);
    cout << "T";
    while (gameRunning)
    {
        Sleep(100);
        if (GetAsyncKeyState(VK_LEFT))
        {
            movePacmanLeft();
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            movePacmanRight();
        }
        if (GetAsyncKeyState(VK_UP))
        {
            movePacmanUP();
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            movePacmanDown();
        }
        if (GetAsyncKeyState(VK_ESCAPE))
        {
            gameRunning = false;
        }
        printscore();
        if (checkghost(pacmanX, pacmanY, ghostX, ghostY) == false)
        {
            gameRunning = false;
            system("CLS");
            cout << "You Lose!";
        }
    }
}

void movePacmanLeft()
{
    if (maze[pacmanX][pacmanY - 1] == ' ' || maze[pacmanX][pacmanY - 1] == '.')
    {
        maze[pacmanX][pacmanY] = ' ';
        gotoxy(pacmanY, pacmanX);
        cout << " ";
        pacmanY = pacmanY - 1;
        if (maze[pacmanX][pacmanY - 1] == '.')
            calculatescore();
        gotoxy(pacmanY, pacmanX);
        cout << "T";
    }
}

void movePacmanRight()
{
    if (maze[pacmanX][pacmanY + 1] == ' ' || maze[pacmanX][pacmanY + 1] == '.')
    {
        maze[pacmanX][pacmanY] = ' ';
        gotoxy(pacmanY, pacmanX);
        cout << " ";
        pacmanY = pacmanY + 1;
        if (maze[pacmanX][pacmanY + 1] == '.')
            calculatescore();
        gotoxy(pacmanY, pacmanX);
        cout << "T";
    }
}
void movePacmanUP()
{
    if (maze[pacmanX - 1][pacmanY] == ' ' || maze[pacmanX - 1][pacmanY] == '.')
    {
        maze[pacmanX][pacmanY] = ' ';
        gotoxy(pacmanY, pacmanX);
        cout << " ";
        pacmanX = pacmanX - 1;
        if (maze[pacmanX - 1][pacmanY] == '.')
            calculatescore();
        gotoxy(pacmanY, pacmanX);
        cout << "T";
    }
}
void movePacmanDown()
{
    if (maze[pacmanX + 1][pacmanY] == ' ' || maze[pacmanX + 1][pacmanY] == '.')
    {
        maze[pacmanX][pacmanY] = ' ';
        gotoxy(pacmanY, pacmanX);
        cout << " ";
        pacmanX = pacmanX + 1;
        if (maze[pacmanX + 1][pacmanY] == '.')
            calculatescore();
        gotoxy(pacmanY, pacmanX);
        cout << "T";
    }
}
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void printMaze()
{
    for (int row = 0; row < 24; row++)
    {
        for (int col = 0; col < 71; col++)
        {
            cout << maze[row][col];
        }
        cout << endl;
    }
}
void calculatescore()
{
    score = score + 1;
}
void printscore()
{
    gotoxy(100, 20);
    cout << "Score : " << score << endl;
}
int ghostDirection()
{
    srand(time(0));
    int result = 1 + (rand() % 4);
    return result;
}
// bool ghostMovement()
// {
//     int value = ghostDirection();
//     if (value == 1)
//     {
//         if (maze[ghostX][ghostY - 1] == ' ' || maze[ghostX][ghostY - 1] == 'P' || maze[ghostX][ghostY - 1] == '.')
//         {
//             maze[ghostX][ghostY] = tempvalue;
//             gotoxy(ghostY, ghostX);
//             ghostY = ghostY - 1;
//             cout << tempvalue;
//             tempvalue = maze[ghostX][ghostY];
//             if (tempvalue == 'P')
//                 return 0;
//             maze[ghostX][ghostY] = 'G';
//             gotoxy(ghostY, ghostX);
//             cout << 'G';
//         }
//     }
//     if (value == 2)
//     {
//         if (maze[ghostX][ghostY + 1] == ' ' || maze[ghostX][ghostY + 1] == 'P' || maze[ghostX][ghostY + 1] == ' ' || maze[ghostX][ghostY] == ' ')
//         {
//             ghostY = ghostY + 1;
//             tempvalue = maze[ghostX][ghostY];
//             if (tempvalue == 'P')
//                 return 0;
//             maze[ghostX][ghostY] = 'G';
//         }
//     }
//     if (value == 3)
//     {
//         if (maze[ghostX - 1][ghostY] == ' ' || maze[ghostX - 1][ghostY] == 'P' || maze[ghostX - 1][ghostY] == ' ')
//         {
//             ghostX = ghostX - 1;
//             tempvalue = maze[ghostX][ghostY];
//             if (tempvalue == 'P')
//                 return 0;
//             maze[ghostX][ghostY] = 'G';
//         }
//     }
// }
void ghostmovement()
{
    srand(time(0));
    int ghostmove = rand() % 4 + 1;
    if (ghostmove == 1)
    {
        moveGhostLeft();
    }
    if (ghostmove == 2)
    {
        moveGhostRight();
    }
    if (ghostmove == 3)
    {
        moveGhostUP();
    }
    if (ghostmove == 4)
    {
        moveGhostDown();
    }
}
void moveGhostLeft()
{
    if (maze[ghostX][ghostY - 1] == ' ' || maze[ghostX][ghostY - 1] == '.')
    {

        maze[ghostX][ghostY] = tempvalue;
        gotoxy(ghostY, ghostX);
        cout << tempvalue;
        tempvalue = maze[ghostX][ghostY - 1];
        ghostY = ghostY - 1;
        gotoxy(ghostY, ghostX);
        cout << "G";
    }
}
void moveGhostRight()
{
    if (maze[ghostX][ghostY + 1] == ' ' || maze[ghostX][ghostY + 1] == '.')
    {
        maze[ghostX][ghostY] = tempvalue;
        gotoxy(ghostY, ghostX);
        cout << tempvalue;
        tempvalue = maze[ghostX][ghostY + 1];
        ghostY = ghostY + 1;
        gotoxy(ghostY, ghostX);
        cout << "G";
    }
}
void moveGhostUP()
{
    if (maze[ghostX - 1][ghostY] == ' ' || maze[ghostX - 1][ghostY] == '.')
    {
        maze[ghostX][ghostY] = tempvalue;
        gotoxy(ghostY, ghostX);
        cout << tempvalue;
        tempvalue = maze[ghostX - 1][ghostY];
        ghostX = ghostX - 1;
        gotoxy(ghostY, ghostX);
        cout << "G";
    }
}
void moveGhostDown()
{
    if (maze[ghostX + 1][ghostY] == ' ' || maze[ghostX + 1][ghostY] == '.')
    {
        maze[ghostX][ghostY] = tempvalue;
        gotoxy(ghostY, ghostX);
        cout << tempvalue;
        tempvalue = maze[ghostX + 1][ghostY];
        ghostX = ghostX + 1;
        gotoxy(ghostY, ghostX);
        cout << "G";
    }
}

void moveGhost2Right()
{
    if (maze[ghostX2][ghostY2 + 1] == ' ' || maze[ghostX2][ghostY2 + 1] == '.')
    {
        maze[ghostX2][ghostY2] = tempvalue2;
        gotoxy(ghostY2, ghostX2);
        cout << tempvalue2;
        tempvalue2 = maze[ghostX2][ghostY2 + 1];
        ghostY2 = ghostY2 + 1;
        gotoxy(ghostY2, ghostX2);
        cout << "G";
    }
}
void moveGhost2Left()
{
    if (maze[ghostX2][ghostY2 - 1] == ' ' || maze[ghostX2][ghostY2 - 1] == '.')
    {
        maze[ghostX2][ghostY2] = tempvalue2;
        gotoxy(ghostY2, ghostX2);
        cout << tempvalue2;
        tempvalue2 = maze[ghostX2][ghostY2 - 1];
        ghostY2 = ghostY2 - 1;
        gotoxy(ghostY2, ghostX2);
        cout << "G";
    }
}
void ghost2movement()
{
    if (g2move == 1)
    {
        moveGhost2Right();
    }
    else if (g2move == 0)
    {
        moveGhost2Left();
    }
    if (maze[ghostX2][ghostY2 + 1] == '|' || maze[ghostX2][ghostY2 - 1] == '|')
    {
        if (g2move == 1)
        {
            g2move = 0;
        }
        else if (g2move == 0)
        {
            g2move = 1;
        }
    }
}
bool checkghost(int x, int y, int x1, int y1)
{
    if (x == x1 && y == y1)
    {
        return false;
    }
    else
    {
        return true;
    }
}
void IntelligentGhost()
{

    Sleep(50);
    if (pacmanX > IntGhostX) // to move the intelligent ghost right
    {
        if (maze[IntGhostX + 1][IntGhostY] == ' ' || maze[IntGhostX + 1][IntGhostY] == '.')
        {
            pre = maze[IntGhostX][IntGhostY];
            maze[IntGhostX][IntGhostY] = pre;

            gotoxy(IntGhostY, IntGhostX);
            cout << pre;

            IntGhostX = IntGhostX + 1;
            if (maze[IntGhostX][IntGhostY] == '%' || maze[IntGhostX][IntGhostY] == '|')
            {
                if (maze[IntGhostX + 1][IntGhostY] == ' ' || maze[IntGhostX + 1][IntGhostY] == '.') // right
                {
                    pre = maze[IntGhostX][IntGhostY];
                    maze[IntGhostX][IntGhostY] = pre;

                    gotoxy(IntGhostY, IntGhostX);
                    cout << pre;

                    IntGhostX = IntGhostX + 1;
                    if ((IntGhostX == pacmanX) && (IntGhostY == pacmanY))
                    {
                        livesCount++;
                        gameRunning = 0;
                    }

                    gotoxy(IntGhostY, IntGhostX);
                    cout << "I";
                }
                else if (maze[IntGhostX - 1][IntGhostY] == ' ' || maze[IntGhostX - 1][IntGhostY] == '.') // left
                {
                    pre = maze[IntGhostX][IntGhostY];
                    maze[IntGhostX][IntGhostY] = pre;

                    gotoxy(IntGhostY, IntGhostX);
                    cout << pre;

                    IntGhostX = IntGhostX - 1;
                    if ((IntGhostX == pacmanX) && (IntGhostY == pacmanY))
                    {
                        livesCount++;
                        gameRunning = 0;
                    }

                    gotoxy(IntGhostY, IntGhostX);
                    cout << "I";
                }
                else if (maze[IntGhostX][IntGhostY + 1] == ' ' || maze[IntGhostX][IntGhostY + 1] == '.') // down
                {
                    pre = maze[IntGhostX][IntGhostY];
                    maze[IntGhostX][IntGhostY] = pre;

                    gotoxy(IntGhostY, IntGhostX);
                    cout << pre;

                    IntGhostY = IntGhostY + 1;
                    if ((IntGhostX == pacmanX) && (IntGhostY == pacmanY))
                    {
                        livesCount++;
                        gameRunning = 0;
                    }

                    gotoxy(IntGhostY, IntGhostX);
                    cout << "I";
                }
                else // up
                {

                    pre = maze[IntGhostX][IntGhostY];
                    maze[IntGhostX][IntGhostY] = pre;

                    gotoxy(IntGhostY, IntGhostX);
                    cout << pre;

                    IntGhostY = IntGhostY - 1;
                    if ((IntGhostX == pacmanX) && (IntGhostY == pacmanY))
                    {
                        livesCount++;
                        gameRunning = 0;
                    }

                    gotoxy(IntGhostY, IntGhostX);
                    cout << "I";
                }
            }
            else
            {
                if ((IntGhostX == pacmanX) && (IntGhostY == pacmanY))
                {
                    livesCount++;
                    gameRunning = 0;
                }

                gotoxy(IntGhostY, IntGhostX);
                cout << "I";
            }
        }
    }

    if (pacmanX < IntGhostX) // to move the intelligent ghost left
    {
        if (maze[IntGhostX - 1][IntGhostY] == ' ' || maze[IntGhostX - 1][IntGhostY] == '.')
        {
            pre = maze[IntGhostX][IntGhostY];
            maze[IntGhostX][IntGhostY] = pre;

            gotoxy(IntGhostY, IntGhostX);
            cout << pre;

            IntGhostX = IntGhostX - 1;
            if (maze[IntGhostX][IntGhostY] == '%' || maze[IntGhostX][IntGhostY] == '|')
            {
                if (maze[IntGhostX + 1][IntGhostY] == ' ' || maze[IntGhostX + 1][IntGhostY] == '.') // right
                {
                    pre = maze[IntGhostX][IntGhostY];
                    maze[IntGhostX][IntGhostY] = pre;

                    gotoxy(IntGhostY, IntGhostX);
                    cout << pre;

                    IntGhostX = IntGhostX + 1;
                    if ((IntGhostX == pacmanX) && (IntGhostY == pacmanY))
                    {
                        livesCount++;
                        gameRunning = 0;
                    }

                    gotoxy(IntGhostY, IntGhostX);
                    cout << "I";
                }
                else if (maze[IntGhostX - 1][IntGhostY] == ' ' || maze[IntGhostX - 1][IntGhostY] == '.') // left
                {
                    pre = maze[IntGhostX][IntGhostY];
                    maze[IntGhostX][IntGhostY] = pre;

                    gotoxy(IntGhostY, IntGhostX);
                    cout << pre;

                    IntGhostX = IntGhostX - 1;
                    if ((IntGhostX == pacmanX) && (IntGhostY == pacmanY))
                    {
                        livesCount++;
                        gameRunning = 0;
                    }

                    gotoxy(IntGhostY, IntGhostX);
                    cout << "I";
                }
                else if (maze[IntGhostX][IntGhostY + 1] == ' ' || maze[IntGhostX][IntGhostY + 1] == '.') // down
                {
                    pre = maze[IntGhostX][IntGhostY];
                    maze[IntGhostX][IntGhostY] = pre;

                    gotoxy(IntGhostY, IntGhostX);
                    cout << pre;

                    IntGhostY = IntGhostY + 1;
                    if ((IntGhostX == pacmanX) && (IntGhostY == pacmanY))
                    {
                        livesCount++;
                        gameRunning = 0;
                    }

                    gotoxy(IntGhostY, IntGhostX);
                    cout << "I";
                }
                else // up
                {

                    pre = maze[IntGhostX][IntGhostY];
                    maze[IntGhostX][IntGhostY] = pre;

                    gotoxy(IntGhostY, IntGhostX);
                    cout << pre;

                    IntGhostY = IntGhostY - 1;
                    if ((IntGhostX == pacmanX) && (IntGhostY == pacmanY))
                    {
                        livesCount++;
                        gameRunning = 0;
                    }

                    gotoxy(IntGhostY, IntGhostX);
                    cout << "I";
                }
            }
            else
            {
                if ((IntGhostX == pacmanX) && (IntGhostY == pacmanY))
                {
                    livesCount++;
                    gameRunning = 0;
                }

                gotoxy(IntGhostY, IntGhostX);
                cout << "I";
            }
        }
    }

    if (pacmanY > IntGhostY) // to move the intelligent ghost down
    {
        if (maze[IntGhostX][IntGhostY + 1] == ' ' || maze[IntGhostX][IntGhostY + 1] == '.')
        {
            pre = maze[IntGhostX][IntGhostY];
            maze[IntGhostX][IntGhostY] = pre;

            gotoxy(IntGhostY, IntGhostX);
            cout << pre;

            IntGhostY = IntGhostY + 1;
            if (maze[IntGhostX][IntGhostY] == '%' || maze[IntGhostX][IntGhostY] == '|')
            {
                if (maze[IntGhostX + 1][IntGhostY] == ' ' || maze[IntGhostX + 1][IntGhostY] == '.') // right
                {
                    pre = maze[IntGhostX][IntGhostY];
                    maze[IntGhostX][IntGhostY] = pre;

                    gotoxy(IntGhostY, IntGhostX);
                    cout << pre;

                    IntGhostX = IntGhostX + 1;
                    if ((IntGhostX == pacmanX) && (IntGhostY == pacmanY))
                    {
                        livesCount++;
                        gameRunning = 0;
                    }

                    gotoxy(IntGhostY, IntGhostX);
                    cout << "I";
                }
                else if (maze[IntGhostX - 1][IntGhostY] == ' ' || maze[IntGhostX - 1][IntGhostY] == '.') // left
                {
                    pre = maze[IntGhostX][IntGhostY];
                    maze[IntGhostX][IntGhostY] = pre;

                    gotoxy(IntGhostY, IntGhostX);
                    cout << pre;

                    IntGhostX = IntGhostX - 1;
                    if ((IntGhostX == pacmanX) && (IntGhostY == pacmanY))
                    {
                        livesCount++;
                        gameRunning = 0;
                    }

                    gotoxy(IntGhostY, IntGhostX);
                    cout << "I";
                }
                else if (maze[IntGhostX][IntGhostY + 1] == ' ' || maze[IntGhostX][IntGhostY + 1] == '.') // down
                {
                    pre = maze[IntGhostX][IntGhostY];
                    maze[IntGhostX][IntGhostY] = pre;

                    gotoxy(IntGhostY, IntGhostX);
                    cout << pre;

                    IntGhostY = IntGhostY + 1;
                    if ((IntGhostX == pacmanX) && (IntGhostY == pacmanY))
                    {
                        livesCount++;
                        gameRunning = 0;
                    }

                    gotoxy(IntGhostY, IntGhostX);
                    cout << "I";
                }
                else // up
                {

                    pre = maze[IntGhostX][IntGhostY];
                    maze[IntGhostX][IntGhostY] = pre;

                    gotoxy(IntGhostY, IntGhostX);
                    cout << pre;

                    IntGhostY = IntGhostY - 1;
                    if ((IntGhostX == pacmanX) && (IntGhostY == pacmanY))
                    {
                        livesCount++;
                        gameRunning = 0;
                    }

                    gotoxy(IntGhostY, IntGhostX);
                    cout << "I";
                }
            }
            else
            {
                if ((IntGhostX == pacmanX) && (IntGhostY == pacmanY))
                {
                    livesCount++;
                    gameRunning = 0;
                }

                gotoxy(IntGhostY, IntGhostX);
                cout << "I";
            }
        }
    }

    if (pacmanY < IntGhostY) // to move the intelligent ghost up
    {
        if (maze[IntGhostX][IntGhostY - 1] == ' ' || maze[IntGhostX][IntGhostY - 1] == '.')
        {
            pre = maze[IntGhostX][IntGhostY];
            maze[IntGhostX][IntGhostY] = pre;

            gotoxy(IntGhostY, IntGhostX);
            cout << pre;

            IntGhostY = IntGhostY - 1;
            if (maze[IntGhostX][IntGhostY] == '%' || maze[IntGhostX][IntGhostY] == '|')
            {
                if (maze[IntGhostX + 1][IntGhostY] == ' ' || maze[IntGhostX + 1][IntGhostY] == '.') // right
                {
                    pre = maze[IntGhostX][IntGhostY];
                    maze[IntGhostX][IntGhostY] = pre;

                    gotoxy(IntGhostY, IntGhostX);
                    cout << pre;

                    IntGhostX = IntGhostX + 1;
                    if ((IntGhostX == pacmanX) && (IntGhostY == pacmanY))
                    {
                        livesCount++;
                        gameRunning = 0;
                    }

                    gotoxy(IntGhostY, IntGhostX);
                    cout << "I";
                }
                else if (maze[IntGhostX - 1][IntGhostY] == ' ' || maze[IntGhostX - 1][IntGhostY] == '.') // left
                {
                    pre = maze[IntGhostX][IntGhostY];
                    maze[IntGhostX][IntGhostY] = pre;

                    gotoxy(IntGhostY, IntGhostX);
                    cout << pre;

                    IntGhostX = IntGhostX - 1;
                    if ((IntGhostX == pacmanX) && (IntGhostY == pacmanY))
                    {
                        livesCount++;
                        gameRunning = 0;
                    }

                    gotoxy(IntGhostY, IntGhostX);
                    cout << "I";
                }
                else if (maze[IntGhostX][IntGhostY + 1] == ' ' || maze[IntGhostX][IntGhostY + 1] == '.') // down
                {
                    pre = maze[IntGhostX][IntGhostY];
                    maze[IntGhostX][IntGhostY] = pre;

                    gotoxy(IntGhostY, IntGhostX);
                    cout << pre;

                    IntGhostY = IntGhostY + 1;
                    if ((IntGhostX == pacmanX) && (IntGhostY == pacmanY))
                    {
                        livesCount++;
                        gameRunning = 0;
                    }

                    gotoxy(IntGhostY, IntGhostX);
                    cout << "I";
                }
                else // up
                {

                    pre = maze[IntGhostX][IntGhostY];
                    maze[IntGhostX][IntGhostY] = pre;

                    gotoxy(IntGhostY, IntGhostX);
                    cout << pre;

                    IntGhostY = IntGhostY - 1;
                    if ((IntGhostX == pacmanX) && (IntGhostY == pacmanY))
                    {
                        livesCount++;
                        gameRunning = 0;
                    }

                    gotoxy(IntGhostY, IntGhostX);
                    cout << "I";
                }
            }
            else
            {
                if ((IntGhostX == pacmanX) && (IntGhostY == pacmanY))
                {
                    livesCount++;
                    gameRunning = 0;
                }

                gotoxy(IntGhostY, IntGhostX);
                cout << "I";
            }
        }
    }
}