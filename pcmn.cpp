#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
#include <stdio.h>
#include <windows.h>
using namespace std;
// GLOBAL VARIABLES.....
// ////////////////////////////////////
char maze[24][71];
bool gamerunning = 1;
int score = 0;
int pacmanX = 9;          // X Coordinate of Pacman
int pacmanY = 31;         // Y Coordinate of Pacman
int ghostX = 19;          // X Coordinate of Ghost1
int ghostY = 25;          // Y Coordinate of Ghost1
int ghostX2 = 22;         // X Coordinate of Ghost2
int ghostY2 = 51;         // Y Coordinate of Ghost2
int ghostX3 = 15;         // X Coordinate of Ghost3
int ghostY3 = 51;         // Y Coordinate of Ghost3
int ghostX4 = 1;          // X Coordinate of Ghost4
int ghostY4 = 2;         // Y Coordinate of Ghost4
char previousItem1 = ' '; // For Ghost 1.
char previousItem2 = ' '; // For Ghost 2.
int gx = 0, gx2 = 0;
// FUNCTIONS.......
// ////////////////////////////
void loadmaze()
{
    string line;
    fstream file;
    file.open("maze.txt", ios::in);
    for (int i = 0; i < 24; i++)
    {
        getline(file, line);
        for (int j = 0; j < 71; j++)
        {
            maze[i][j] = line[j];
        }
    }
    file.close();
}
void printmaze()
{
    for (int i = 0; i < 24; i++)
    {
        for (int j = 0; j < 71; j++)
        {
            cout << maze[i][j];
        }
        cout << endl;
    }
}
void gotoxy(int y, int x)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void calculateScore()
{
    score = score + 1;
}
void movePacmanLeft()
{
    if (maze[pacmanX][pacmanY - 1] == ' ' || maze[pacmanX][pacmanY - 1] == '.')
    {
        gotoxy(pacmanX, pacmanY);
        cout << ' ';
        pacmanY = pacmanY - 1;
        if (maze[pacmanX][pacmanY] == '.')
        {
            calculateScore();
        }
        gotoxy(pacmanX, pacmanY);
        cout << 'P';
    }
}
void movePacmanRight()
{
    if (maze[pacmanX][pacmanY + 1] == ' ' || maze[pacmanX][pacmanY + 1] == '.')
    {
        gotoxy(pacmanX, pacmanY);
        cout << ' ';
        pacmanY = pacmanY + 1;
        if (maze[pacmanX][pacmanY] == '.')
        {
            calculateScore();
        }
        gotoxy(pacmanX, pacmanY);
        cout << 'P';
    }
}
void movePacmanUp()
{
    if (maze[pacmanX - 1][pacmanY] == ' ' || maze[pacmanX - 1][pacmanY] == '.')
    {
        gotoxy(pacmanX, pacmanY);
        cout << ' ';
        pacmanX = pacmanX - 1;
        if (maze[pacmanX][pacmanY] == '.')
        {
            calculateScore();
        }
        gotoxy(pacmanX, pacmanY);
        cout << 'P';
    }
}
void movePacmanDown()
{
    if (maze[pacmanX + 1][pacmanY] == ' ' || maze[pacmanX + 1][pacmanY] == '.')
    {
        gotoxy(pacmanX, pacmanY);
        cout << ' ';
        pacmanX = pacmanX + 1;
        if (maze[pacmanX][pacmanY] == '.')
        {
            calculateScore();
        }
        gotoxy(pacmanX, pacmanY);
        cout << 'P';
    }
}
int ghostDirection()
{
    srand(time(0));
    int result = 1 + (rand() % 4);
    return result;
}
bool moveGhostVerticle()
{
    if (maze[ghostX2 - 1][ghostY2] != ' ')
    {
        gx = 1;
    }
    if (gx == 0)
    {
        gotoxy(ghostX2, ghostY2);
        cout << ' ';
        ghostX2 = ghostX2 - 1;
        // if (maze[ghostX2][ghostY2] == 'P')
        // {
        //     return 0;
        // }
        gotoxy(ghostX2, ghostY2);
        cout << 'G';
        return 1;
    }
    if (maze[ghostX2 + 1][ghostY2] != ' ')
    {
        gx = 0;
    }
    if (gx == 1)
    {
        gotoxy(ghostX2, ghostY2);
        cout << ' ';
        ghostX2 = ghostX2 + 1;
        // if (maze[ghostX2][ghostY2] == 'P')
        // {
        //     return 0;
        // }
        gotoxy(ghostX2, ghostY2);
        cout << 'G';
        return 1;
    }
}
bool moveGhostHorizontal()
{
    if (maze[ghostX3][ghostY3 - 1] != ' ')
    {
        gx2 = 1;
    }
    if (gx2 == 0)
    {
        gotoxy(ghostX3, ghostY3);
        cout << ' ';
        ghostY3 = ghostY3 - 1;
        // if (maze[ghostX3][ghostY3] == 'P')
        // {
        //     return 0;
        // }
        gotoxy(ghostX3, ghostY3);
        cout << 'G';
        return 1;
    }
    if (maze[ghostX3][ghostY3 + 1] != ' ')
    {
        gx2 = 0;
    }
    if (gx2 == 1)
    {
        gotoxy(ghostX3, ghostY3);
        cout << ' ';
        ghostY3 = ghostY3 + 1;
        // if (maze[ghostX3][ghostY3] == 'P')
        // {
        //     return 0;
        // }
        gotoxy(ghostX3, ghostY3);
        cout << 'G';
        return 1;
    }
}
bool findpath()
{
	int a = ghostX4 - pacmanX;
	int b = ghostY4 - pacmanY;
	if (a < 0 && b < 0)
	{
		if (maze[ghostX4][ghostY4 + 1] == ' ')
		{
			gotoxy(ghostX4, ghostY4);
			cout << ' ';
			ghostY4 = ghostY4 + 1;
            // if(maze[ghostX3][ghostY3] == 'P')
            // {
            //     return 0;
            // }
			gotoxy(ghostX4, ghostY4);
			cout << 'G';
		}
		else
		{
			gotoxy(ghostX4, ghostY4);
			cout << ' ';
			ghostX4 = ghostX4 + 1;
            // if(maze[ghostX3][ghostY3] == 'P')
            // {
            //     return 0;
            // }
			gotoxy(ghostX4, ghostY4);
			cout << 'G';
		}
	}
	if (a > 0 && b > 0)
	{
		if (maze[ghostX4][ghostY4 + 1] == ' ')
		{
			gotoxy(ghostX4, ghostY4);
			cout << ' ';
			ghostX4 = ghostX4 - 1;
            // if(maze[ghostX3][ghostY3] == 'P')
            // {
            //     return 0;
            // }
			gotoxy(ghostX4, ghostY4);
			cout << 'G';
		}
		else
		{
			gotoxy(ghostX4, ghostY4);
			cout << ' ';
			ghostY4 = ghostY4 - 1;
            // if(maze[ghostX3][ghostY3] == 'P')
            // {
            //     return 0;
            // }
			gotoxy(ghostX4, ghostY4);
			cout << 'G';
		}
	}
	if (a == 0 && b < 0)
	{
		if (maze[ghostX4 + 1][ghostY4] == ' ')
		{
			gotoxy(ghostX4, ghostY4);
			cout << ' ';
			ghostX4 = ghostX4 + 1;
            // if(maze[ghostX3][ghostY3] == 'P')
            // {
            //     return 0;
            // }
			gotoxy(ghostX4, ghostY4);
			cout << 'G';
		}
	}
	else if (a == 0 && b > 0)
	{
		if (maze[ghostX4 - 1][ghostY4] == ' ')
		{
			gotoxy(ghostX4, ghostY4);
			cout << ' ';
			ghostX4 = ghostX4 - 1;
            // if(maze[ghostX3][ghostY3] == 'P')
            // {
            //     return 0;
            // }
			gotoxy(ghostX4, ghostY4);
			cout << 'G';
		}
	}
	if (b == 0 && a < 0)
	{
		if (maze[ghostX4][ghostY4 + 1] == ' ')
		{
			gotoxy(ghostX4, ghostY4);
			cout << ' ';
			ghostY4 = ghostY4 + 1;
            // if(maze[ghostX3][ghostY3] == 'P')
            // {
            //     return 0;
            // }
			gotoxy(ghostX4, ghostY4);
			cout << 'G';
		}
	}
	else if (b == 0 && a > 0)
	{
		if (maze[ghostX4][ghostY4 - 1] == ' ')
		{
			gotoxy(ghostX4, ghostY4);
			cout << ' ';
			ghostY4 = ghostY4 - 1;
            // if(maze[ghostX3][ghostY3] == 'P')
            // {
            //     return 0;
            // }
			gotoxy(ghostX4, ghostY4);
			cout << 'G';
		}
	}
}
bool ghostMovement()
{
    
    moveGhostVerticle();
    moveGhostHorizontal();
    findpath();
    // bool b = moveGhostVerticle();
    // bool c = moveGhostHorizontal();
    // bool d = findpath();
    // if (b == 0)
    // {
    //     return 0;
    // }
    // if (c == 0)
    // {
    //     return 0;
    // }
    // if (d == 0)
    // {
    //     return 0;
    // }
    int value = ghostDirection();
    if (value == 1)
    {
        if (maze[ghostX][ghostY - 1] == ' ' || maze[ghostX][ghostY - 1] == '.' || maze[ghostX][ghostY - 1] == 'P')
        {
            gotoxy(ghostX, ghostY);
            cout << previousItem1;
            ghostY = ghostY - 1;
            previousItem1 = maze[ghostX][ghostY];
            if (previousItem1 == 'P')
            {
                return 0;
            }
            gotoxy(ghostX, ghostY);
            cout << 'G';
        }
    }
    if (value == 2)
    {
        if (maze[ghostX][ghostY + 1] == ' ' || maze[ghostX][ghostY + 1] == '.' || maze[ghostX][ghostY + 1] == 'P')
        {
            gotoxy(ghostX, ghostY);
            cout << previousItem1;
            ghostY = ghostY + 1;
            previousItem1 = maze[ghostX][ghostY];
            if (previousItem1 == 'P')
            {
                return 0;
            }
            gotoxy(ghostX, ghostY);
            cout << 'G';
        }
    }
    if (value == 3)
    {
        if (maze[ghostX - 1][ghostY] == ' ' || maze[ghostX - 1][ghostY] == '.' || maze[ghostX - 1][ghostY] == 'P')
        {
            gotoxy(ghostX, ghostY);
            cout << previousItem1;
            ghostX = ghostX - 1;
            previousItem1 = maze[ghostX][ghostY];
            if (previousItem1 == 'P')
            {
                return 0;
            }
            gotoxy(ghostX, ghostY);
            cout << 'G';
        }
    }
    if (value == 4)
    {
        if (maze[ghostX + 1][ghostY] == ' ' || maze[ghostX + 1][ghostY] == '.' || maze[ghostX + 1][ghostY] == '.')
        {
            gotoxy(ghostX, ghostY);
            cout << previousItem1;
            ghostX = ghostX + 1;
            previousItem1 = maze[ghostX][ghostY];
            if (previousItem1 == 'P')
            {
                return 0;
            }
            gotoxy(ghostX, ghostY);
            cout << 'G';
        }
    }
    return 1;
}
// MAIN FUNCTION....
// //////////////////
int main()
{
    loadmaze();
    printmaze();
    while (gamerunning)
    {
        Sleep(200);
        gamerunning = ghostMovement();
        if (GetAsyncKeyState(VK_LEFT))
        {
            movePacmanLeft(); // Function call to move Pacman towards left
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
            gamerunning = false; // Stop the game
        }
        gotoxy(28, 80);
        cout << "scrore: " << score;
        if (score == 482)
        {
            cout<<"Congratulation! You Win :) "<<endl;
            cout<<"Press Any Key: ";
            getch();
            exit(0);
        }
        
    }
}
