#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;
int score = 0;
void printscore();
char tempghost = ' ';
char tempghost2 = ' ';

// ghost  hit pacman
bool checkghost(int x, int y, int x1, int y1);

char maze[24][71] = {{"#####################################################################"},
                     {"||..A.....................................................  ......  ||"},
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
                     {"||..|%|  %%%%%%%%%%%%%%  H    ...|%|%%%%%%%%%%     |%| ..|%|%%%%%  ||"},
                     {"||...............................................   |%| ..........  ||"},
                     {"||G   ............................................         .......  ||"},
                     {"||..|%|  |%|   |%|..    %%%%%%%%%%%%%  ......|%|    |%| ..|%|.      ||"},
                     {"||..|%|  |%|   |%|..           ...|%|     %%%%%%    |%| ..|%|.      ||"},
                     {"||..|%|            .     G     ...|%|               |%| ..|%|.      ||"},
                     {"||..|%|  %%%%%%%%%%%%%%        ...|%|%%%%%%%%%%     |%| ..|%|%%%%%  ||"},
                     {"||...............................................   |%| ..........  ||"},
                     {"||  .............................................          .......  ||"},
                     {"##################################################################### "}};

int pacmanX = 9;  // X Coordinate of Pacman int pacmanY = 4; // Y Coordinate of Pacman
int pacmanY = 31; // X Coordinate of Pacman int pacmanY = 4; // Y Coordinate of Pacman
int IntGhostX = 15;
int IntGhostY = 25;
int ghostx = 19;
int ghosty = 25;
int ghostx2 = 16;
int ghosty2 = 2;
int ghostx3 = 1;
int ghosty3 = 4;
// Function Prototype void printMaze();
void gotoxy(int x, int y);
void printMaze();
// pacman movement
void movePacmanLeft();
void movePacmanRight();
void movePacmanUP();
void movePacmanDown();
// ghost movement
void ghostmovement();
void moveGhostLeft();
void moveGhostRight();
void moveGhostUP();
void moveGhostDown();
// ghost2mvement
bool g2move = 1;
bool g3move = 1;
void ghost2movement();
void moveGhost2Left();
void moveGhost2Right();

// ghost3movement
void ghost3movement();
void moveGhost3UP();
void moveGhost3Down();
// ghost4movement
int livesCount = 0;
int gameRunning = 0;
int pre;
void IntelligentGhost();
void ghost4movement();
void moveGhost4Left();
void moveGhost4Right();
void moveGhost4UP();
void moveGhost4Down();
// Main Function
main()
{

    bool gameRunning = true;
    system("CLS");
    printMaze();
    gotoxy(pacmanY, pacmanX);
    cout << "P";
    while (gameRunning)
    {
        ghostmovement();
        ghost2movement();
        moveGhost2Right();

        Sleep(50);
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
        // Checking score to see if game is over
        if (score == 4660)
        {
            gameRunning = false;
            system("CLS");
            cout << "You Win!";
        }
        // checking clash with ghost
        if (checkghost(pacmanX, pacmanY, ghostx, ghosty) == false)
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
        if (maze[pacmanX][pacmanY - 1] == '.')
        {
            score = score + 10;
        }
        maze[pacmanX][pacmanY] = ' ';
        gotoxy(pacmanY, pacmanX);
        cout << " ";
        pacmanY = pacmanY - 1;
        gotoxy(pacmanY, pacmanX);
        cout << "P";
    }
}

void movePacmanRight()
{
    if (maze[pacmanX][pacmanY + 1] == ' ' || maze[pacmanX][pacmanY + 1] == '.')
    {
        if (maze[pacmanX][pacmanY + 1] == '.')
        {
            score = score + 10;
        }
        maze[pacmanX][pacmanY] = ' ';
        gotoxy(pacmanY, pacmanX);
        cout << " ";
        pacmanY = pacmanY + 1;
        gotoxy(pacmanY, pacmanX);
        cout << "P";
    }
}
void movePacmanUP()
{
    if (maze[pacmanX - 1][pacmanY] == ' ' || maze[pacmanX - 1][pacmanY] == '.')
    {
        if (maze[pacmanX - 1][pacmanY] == '.')
        {
            score = score + 10;
        }
        maze[pacmanX][pacmanY] = ' ';
        gotoxy(pacmanY, pacmanX);
        cout << " ";
        pacmanX = pacmanX - 1;
        gotoxy(pacmanY, pacmanX);
        cout << "P";
    }
}
void movePacmanDown()
{
    if (maze[pacmanX + 1][pacmanY] == ' ' || maze[pacmanX + 1][pacmanY] == '.')
    {
        if (maze[pacmanX + 1][pacmanY] == '.')
        {
            score = score + 10;
        }
        maze[pacmanX][pacmanY] = ' ';
        gotoxy(pacmanY, pacmanX);
        cout << " ";
        pacmanX = pacmanX + 1;
        gotoxy(pacmanY, pacmanX);
        cout << "P";
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
void printscore()
{
    gotoxy(100, 20);
    cout << "Score: " << score << endl;
}
void moveGhostLeft()
{
    if (maze[ghostx][ghosty - 1] == ' ' || maze[ghostx][ghosty - 1] == '.')
    {

        maze[ghostx][ghosty] = tempghost;
        gotoxy(ghosty, ghostx);
        cout << tempghost;
        tempghost = maze[ghostx][ghosty - 1];
        ghosty = ghosty - 1;
        gotoxy(ghosty, ghostx);
        cout << "Z";
    }
}
void moveGhost3UP()
{
    if (maze[ghostx2][ghosty2 + 1] == ' ' || maze[ghostx2][ghosty2 + 1] == '.')
    {
        maze[ghostx2][ghosty2] = tempghost2;
        gotoxy(ghosty2, ghostx2);
        cout << tempghost2;
        tempghost2 = maze[ghostx2][ghosty2 + 1];
        ghosty2 = ghosty2 + 1;
        gotoxy(ghosty2, ghostx2);
        cout << "A";
    }
}
void moveGhost3DOWN()
{
    if (maze[ghostx3 - 1][ghosty3] == ' ' || maze[ghostx3 - 1][ghosty3] == '.')
    {
        maze[ghostx2][ghosty2] = tempghost2;
        gotoxy(ghosty2, ghostx2);
        cout << tempghost2;
        tempghost2 = maze[ghostx2][ghosty2 - 1];
        ghosty2 = ghosty2 - 1;
        gotoxy(ghosty2, ghostx2);
        cout << "s";
    }
}
void moveGhost2Right()
{
    if (maze[ghostx2][ghosty2 + 1] == ' ' || maze[ghostx2][ghosty2 + 1] == '.')
    {
        maze[ghostx2][ghosty2] = tempghost2;
        gotoxy(ghosty2, ghostx2);
        cout << tempghost2;
        tempghost2 = maze[ghostx2][ghosty2 + 1];
        ghosty2 = ghosty2 + 1;
        gotoxy(ghosty2, ghostx2);
        cout << "A";
    }
}
void moveGhost2Left()
{
    if (maze[ghostx2][ghosty2 - 1] == ' ' || maze[ghostx2][ghosty2 - 1] == '.')
    {
        maze[ghostx2][ghosty2] = tempghost2;
        gotoxy(ghosty2, ghostx2);
        cout << tempghost2;
        tempghost2 = maze[ghostx2][ghosty2 - 1];
        ghosty2 = ghosty2 - 1;
        gotoxy(ghosty2, ghostx2);
        cout << "s";
    }
}
void moveGhostRight()
{
    if (maze[ghostx][ghosty + 1] == ' ' || maze[ghostx][ghosty + 1] == '.')
    {
        maze[ghostx][ghosty] = tempghost;
        gotoxy(ghosty, ghostx);
        cout << tempghost;
        tempghost = maze[ghostx][ghosty + 1];
        ghosty = ghosty + 1;
        gotoxy(ghosty, ghostx);
        cout << "G";
    }
}
void moveGhostUP()
{
    if (maze[ghostx - 1][ghosty] == ' ' || maze[ghostx - 1][ghosty] == '.')
    {
        maze[ghostx][ghosty] = tempghost;
        gotoxy(ghosty, ghostx);
        cout << tempghost;
        tempghost = maze[ghostx - 1][ghosty];
        ghostx = ghostx - 1;
        gotoxy(ghosty, ghostx);
        cout << "G";
    }
}
void moveGhostDown()
{
    if (maze[ghostx + 1][ghosty] == ' ' || maze[ghostx + 1][ghosty] == '.')
    {
        maze[ghostx][ghosty] = tempghost;
        gotoxy(ghosty, ghostx);
        cout << tempghost;
        tempghost = maze[ghostx + 1][ghosty];
        ghostx = ghostx + 1;
        gotoxy(ghosty, ghostx);
        cout << "G";
    }
}
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
void ghost2movement()
{
    if (g2move == 1)
    {
        moveGhost2Right();
    }
    else if (g2move == 2)
    {
        moveGhost2Left();
    }
    if (maze[ghostx2][ghosty2 + 1] == '|' || maze[ghostx2][ghosty2 - 1] == '|')
    {
        if (g2move == 1)
        {
            g2move = 2;
        }
        else if (g2move == 2)
        {
            g2move = 1;
        }
    }
}
void ghost3movement()
{
    if (g3move == 1)
    {
        moveGhost2Right();
    }
    else if (g3move == 2)
    {
        moveGhost2Left();
    }
    if (maze[ghostx2][ghosty2 + 1] == '|' || maze[ghostx2][ghosty2 - 1] == '|')
    {
        if (g3move == 1)
        {
            g3move = 2;
        }
        else if (g2move == 2)
        {
            g2move = 1;
        }
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
