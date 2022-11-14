#include <iostream>
#include <ctime>
#include <conio.h>
#include <fstream>
#include <windows.h>
using namespace std;

char maze[24][71] =
    {
        {"#####################################################################"},
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
        {"||..|%|  %%%%%%%%%%%%%%        ...|%|%%%%%%%%%%     |%| ..|%|%%%%%  ||"},
        {"||...............................................   |%| ..........  ||"},
        {"||   ............................................          .......  ||"},
        {"||..|%|  |%|   |%|..    %%%%%%%%%%%%%  ......|%|    |%| ..|%|.      ||"},
        {"||..|%|  |%|   |%|..           ...|%|     %%%%%%    |%| ..|%|.      ||"},
        {"||..|%|            .     G     ...|%|               |%| ..|%|.      ||"},
        {"||..|%|  %%%%%%%%%%%%%%        ...|%|%%%%%%%%%%     |%| ..|%|%%%%%  ||"},
        {"||...............................................   |%| ..........  ||"},
        {"||  .............................................          .......  ||"},
        {"#####################################################################"}};

int score = 0;
int lives = 0;
bool gameRunning = 1;
int ghostX = 19; // X Coordinate of Random Ghost
int ghostY = 25; // Y Coordinate of Random Ghost
char previousItem = ' ';

int pacmanX = 9;  // X Coordinate of Pacman
int pacmanY = 31; // Y Coordinate of Pacman
int pacmanDX = 9;
int pacmanDY = 31;

int ghostHX = 22; // X coordinate of Horizontal Ghost
int ghostHY = 55; // Y- Coordinate of Horizontal ghost
char previousItem1 = ' ';
string value2 = "LEFT";
int ghostVX = 13; // X Coordinate of Vertical Ghost
int ghostVY = 56; // Y Coordinate of Vertical Ghost
char previousItem2 = ' ';
string value3 = "UP";
int IntGhostX = 1; // X Coordinate of Intelligent Ghost
int IntGhostY = 3; // Y Coordinate of Intelligent Ghost
char previousItem3 = ' ';

void printMaze();
void calculateScore();
void printScore();
void movePacmanLeft();
void movePacmanRight();
void movePacmanUp();
void movePacmanDown();
int ghostDirection();
bool ghostMovement();
void ghostH();
void ghostV();
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void IntelligentGhost();

int main()
{

    system("CLS");
    printMaze();

    // gotoxy(pacmanY, pacmanX);
    // cout << "P";
    while (lives < 3)
    {
        gameRunning = 1;
        gotoxy(pacmanDY, pacmanDX);
        cout << "P";
        pacmanX = pacmanDX;
        pacmanY = pacmanDY;
        while (gameRunning)
        {
            Sleep(200);
            ghostV();
            gameRunning = ghostMovement();
            ghostH();
            IntelligentGhost();

            printScore();
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
                movePacmanUp();
            }
            if (GetAsyncKeyState(VK_DOWN))
            {
                movePacmanDown();
            }
            if (GetAsyncKeyState(VK_ESCAPE))
            {
                gameRunning = 0;
            }
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
    gotoxy(100, 20);
    cout << "Score: " << score << endl;
}
void movePacmanLeft()
{
    if (maze[pacmanX][pacmanY - 1] == ' ' || maze[pacmanX][pacmanY - 1] == '.')
    {

        maze[pacmanX][pacmanY] = ' ';
        gotoxy(pacmanY, pacmanX);
        cout << " ";
        pacmanY = pacmanY - 1;
        if (maze[pacmanX][pacmanY] == '.')
        {
            calculateScore();
        }
        gotoxy(pacmanY, pacmanX);
        cout << "P";
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
        if (maze[pacmanX][pacmanY] == '.')
        {
            calculateScore();
        }

        gotoxy(pacmanY, pacmanX);
        cout << "P";
    }
}
void movePacmanUp()
{
    if (maze[pacmanX - 1][pacmanY] == ' ' || maze[pacmanX - 1][pacmanY] == '.')
    {
        maze[pacmanX][pacmanY] = ' ';
        gotoxy(pacmanY, pacmanX);
        cout << " ";
        pacmanX = pacmanX - 1;
        if (maze[pacmanX][pacmanY] == '.')
        {
            calculateScore();
        }

        gotoxy(pacmanY, pacmanX);
        cout << "P";
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
        if (maze[pacmanX][pacmanY] == '.')
        {
            calculateScore();
        }

        gotoxy(pacmanY, pacmanX);
        cout << "P";
    }
}
int ghostDirection()
{
    srand(time(NULL));
    int result = 1 + (rand() % 4);
    return result;
}
bool ghostMovement()
{
    int value = ghostDirection();
    if (value == 1) // move ghost left
    {
        // previousItem = ' ';
        if (maze[ghostX][ghostY - 1] == ' ' || maze[ghostX][ghostY - 1] == '.' || maze[ghostX][ghostY - 1] == 'P')
        {
            maze[ghostX][ghostY] = previousItem;

            gotoxy(ghostY, ghostX);
            cout << previousItem;

            ghostY = ghostY - 1;
            previousItem = maze[ghostX][ghostY];
            if (ghostX == pacmanX && ghostY == pacmanY)
            {
                lives++;
                return 0;
            }

            gotoxy(ghostY, ghostX);
            cout << "G";
        }
    }
    if (value == 2) // move ghost right
    {
        // previousItem = ' ';
        if (maze[ghostX][ghostY + 1] == ' ' || maze[ghostX][ghostY + 1] == '.' || maze[ghostX][ghostY + 1] == 'P')
        {
            maze[ghostX][ghostY] = previousItem;

            gotoxy(ghostY, ghostX);
            cout << previousItem;

            ghostY = ghostY + 1;
            previousItem = maze[ghostX][ghostY];

            if (ghostX == pacmanX && ghostY == pacmanY)
            {
                lives++;
                return 0;
            }

            gotoxy(ghostY, ghostX);
            cout << "G";
        }
    }
    if (value == 3) // move ghost up
    {

        if (maze[ghostX - 1][ghostY] == ' ' || maze[ghostX - 1][ghostY] == '.' || maze[ghostX - 1][ghostY] == 'P')
        {
            maze[ghostX][ghostY] = previousItem;
            // (ghostX - 1 != ' ')

            gotoxy(ghostY, ghostX);
            cout << previousItem;

            ghostX = ghostX - 1;
            previousItem = maze[ghostX][ghostY];
            if (ghostX == pacmanX && ghostY == pacmanY)
            {
                lives++;
                return 0;
            }
            gotoxy(ghostY, ghostX);
            cout << "G";
        }
    }
    if (value == 4) // move ghost down
    {

        if (maze[ghostX + 1][ghostY] == ' ' || maze[ghostX + 1][ghostY] == '.' || maze[ghostX + 1][ghostY] == 'P')
        {
            maze[ghostX][ghostY] = previousItem;

            gotoxy(ghostY, ghostX);
            cout << previousItem;

            ghostX = ghostX + 1;
            previousItem = maze[ghostX][ghostY];

            if (ghostX == pacmanX && ghostY == pacmanY)
            {
                lives++;
                return 0;
            }
            gotoxy(ghostY, ghostX);
            cout << "G";
        }
    }
    return 1;
}
void ghostH()
{
    if (value2 == "LEFT") // move ghost left
    {                     // string flag variable

        if (maze[ghostHX][ghostHY - 1] == ' ' || maze[ghostHX][ghostHY - 1] == '.' || maze[ghostHX][ghostHY - 1] == 'P')
        {
            maze[ghostHX][ghostHY] = previousItem1;

            gotoxy(ghostHY, ghostHX);
            cout << previousItem1;

            ghostHY = ghostHY - 1;
            previousItem1 = maze[ghostHX][ghostHY];
            if (ghostHX == pacmanX && ghostHY == pacmanY)
            {
                lives++;
                gameRunning = 0;
            }

            gotoxy(ghostHY, ghostHX);
            cout << "G";
            if (maze[ghostHX][ghostHY - 1] == '|') // updation of flag at boundary
                value2 = "RIGHT";
        }
    }
    if (value2 == "RIGHT") // move ghost right
    {                      // string flag variable
        if (maze[ghostHX][ghostHY + 1] == ' ' || maze[ghostHX][ghostHY + 1] == '.' || maze[ghostHX][ghostHY + 1] == 'P')
        {
            maze[ghostHX][ghostHY] = previousItem1;

            gotoxy(ghostHY, ghostHX);
            cout << previousItem1;

            ghostHY = ghostHY + 1;
            previousItem1 = maze[ghostHX][ghostHY];

            if (ghostHX == pacmanX && ghostHY == pacmanY)
            {
                lives++;
                gameRunning = 0;
            }

            gotoxy(ghostHY, ghostHX);
            cout << "G";
            if (maze[ghostHX][ghostHY + 1] == '|') // updation of flag at boundary
                value2 = "LEFT";
        }
    }
}
void ghostV()
{
    if (value3 == "UP") // move ghost up
    {
        if (maze[ghostVX - 1][ghostVY] == ' ' || maze[ghostVX - 1][ghostVY] == '.' || maze[ghostVX - 1][ghostVY] == 'P')
        {
            maze[ghostVX][ghostVY] = previousItem2;

            gotoxy(ghostVY, ghostVX);
            cout << previousItem2;

            ghostVX = ghostVX - 1;
            previousItem2 = maze[ghostVX][ghostVY];

            gotoxy(ghostVY, ghostVX);
            cout << previousItem2;

            if (ghostVX == pacmanX && ghostVY == pacmanY)
            {
                lives++;
                gameRunning = 0;
            }
            gotoxy(ghostVY, ghostVX);
            cout << "G";
            if (maze[ghostVX - 1][ghostVY] == '#') // updation of flag
                value3 = "DOWN";                   // at boundary
        }
        // if (maze[ghostVX - 1][ghostVY] == '#') // updation of flag
        //     value3 = "DOWN";                   // at boundary
    }
    if (value3 == "DOWN")
    {
        if (maze[ghostVX + 1][ghostVY] == ' ' || maze[ghostVX + 1][ghostVY] == '.' || maze[ghostVX + 1][ghostVY] == 'P')
        {
            maze[ghostVX][ghostVY] = previousItem2;

            gotoxy(ghostVY, ghostVX);
            cout << previousItem2;

            ghostVX = ghostVX + 1;
            previousItem2 = maze[ghostVX][ghostVY];

            if (ghostVX == pacmanX && ghostVY == pacmanY)
            {
                lives++;
                gameRunning = 0;
            }
            gotoxy(ghostVY, ghostVX);
            cout << "G";
            if (maze[ghostVX + 1][ghostVY] == '#') // updation of flag at boundary
                value3 = "UP";                     // of maze
        }
        // if (maze[ghostVX + 1][ghostVY] == '#') // updation of flag at boundary
        //     value3 = "UP";                     // of maze
    }
}
void IntelligentGhost()
{
    char pre;
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
            if ((IntGhostX == pacmanX) && (IntGhostY == pacmanY))
            {
                lives++;
                gameRunning = 0;
            }

            gotoxy(IntGhostY, IntGhostX);
            cout << "G";
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
            if ((IntGhostX == pacmanX) && (IntGhostY == pacmanY))
            {
                lives++;
                gameRunning = 0;
            }

            gotoxy(IntGhostY, IntGhostX);
            cout << "G";
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
            if ((IntGhostX == pacmanX) && (IntGhostY == pacmanY))
            {
                lives++;
                gameRunning = 0;
            }
            gotoxy(IntGhostY, IntGhostX);
            cout << "G";
        }
    }
    if (pacmanY < IntGhostY)
    {
        if (maze[IntGhostX][IntGhostY - 1] == ' ' || maze[IntGhostX][IntGhostY - 1] == '.')
        {
            pre = maze[IntGhostX][IntGhostY];
            maze[IntGhostX][IntGhostY] = pre;

            gotoxy(IntGhostY, IntGhostX);
            cout << pre;

            IntGhostY = IntGhostY - 1;
            if ((IntGhostX == pacmanX) && (IntGhostY == pacmanY))
            {
                lives++;
                gameRunning = 0;
            }
            gotoxy(IntGhostY, IntGhostX);
            cout << "G";
        }
    }
}