#include <iostream>
#include <fstream>
#include <conio.h>
#include <ctime>
#include <string>
#include <sstream>
#include <windows.h>
using namespace std;
// /////////////////////////////////////////////////
// //////////////  Global Variables  //////////////
// ///////////////////////////////////////////////
char Grid[23][96];
int livesCount = 0;
bool gameRunning = 1;
struct Cars
{
    int X;
    int Y;
};
Cars Position[16] = {
    {18, 35},
    {18, 36},
    {18, 37},
    {18, 38},
    {18, 39},
    {18, 40},
    {19, 37},
    {19, 38},
    {20, 37},
    {20, 38},
    {21, 35},
    {21, 36},
    {21, 37},
    {21, 38},
    {21, 39},
    {21, 40},
};
Cars lane1[12] = {
    {1, 12},
    {1, 13},
    {1, 14},
    {1, 15},
    {2, 13},
    {2, 14},
    {3, 13},
    {3, 14},
    {4, 12},
    {4, 13},
    {4, 14},
    {4, 15},
};
Cars lane2[12] = {
    {1, 23},
    {1, 24},
    {1, 25},
    {1, 26},
    {2, 24},
    {2, 25},
    {3, 24},
    {3, 25},
    {4, 23},
    {4, 24},
    {4, 25},
    {4, 26},
};
Cars lane3[12] = {
    {1, 33},
    {1, 34},
    {1, 35},
    {1, 36},
    {2, 34},
    {2, 35},
    {3, 34},
    {3, 35},
    {4, 33},
    {4, 34},
    {4, 35},
    {4, 36},
};
Cars lane4[12] = {
    {1, 43},
    {1, 44},
    {1, 45},
    {1, 46},
    {2, 44},
    {2, 45},
    {3, 44},
    {3, 45},
    {4, 43},
    {4, 44},
    {4, 45},
    {4, 46},
};
// /////////////////////////////////////////////////
// /////////// Functions Prototypes  //////////////
// ///////////////////////////////////////////////
void loadGrid();
void printGrid();
void load_Print_Logo();
int MainMenu();
void instruction();
void GameControls();
bool CarsRunning();
int CarsLane();
bool car1();
bool car2();
bool car3();
bool car4();
void MoveLeft();
void MoveRight();
void MoveUp();
void MoveDown();
void gotoxy(int x, int y);
// /////////////////////////////////////////////////
// //////////////   Main Funtion     //////////////
// ///////////////////////////////////////////////
int main()
{
    int condition = 0;
    loadGrid();
    load_Print_Logo();
    getch();
    while (true)
    {
        system("cls");
        int option = MainMenu();
        if (option == 1)
        {
            system("cls");
            printGrid();
            while (livesCount < 3)
            {
                do
                {
                    Sleep(200);
                    gameRunning = CarsRunning();
                    GameControls();
                    if (GetAsyncKeyState(VK_ESCAPE))
                    {
                        condition = 1;
                        break;
                    }
                } while (gameRunning);
                if (condition == 1)
                {
                    break;
                }
                loadGrid();
                printGrid();
                livesCount += 1;
            }
        }
        if (option == 2)
        {
            instruction();
        }
        if (option == 3)
        {
            exit(0);
        }
    }

    return 0;
}
// User-Defined Functions...
// ////////////////////////
void gotoxy(int y, int x)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void loadGrid()
{
    string line;
    fstream file;
    file.open("grid.txt", ios::in);
    for (int row = 0; row < 23; row++)
    {
        getline(file, line);
        for (int col = 0; col < 96; col++)
        {
            Grid[row][col] = line[col];
        }
    }
    file.close();
}
void printGrid()
{
    for (int row = 0; row < 23; row++)
    {
        for (int col = 0; col < 96; col++)
        {
            cout << Grid[row][col];
        }
        cout << endl;
    }
}
void load_Print_Logo()
{
    string line;
    fstream file;
    file.open("logo.txt", ios::in);
    while (!file.eof())
    {
        getline(file, line);
        cout << line << endl;
    }
    file.close();
}
int MainMenu()
{
    int option;
    cout << "\n\n\n\n\n\n\n\t\t\t\t\t   ///////////////////\n";
    cout << "\t\t\t\t\t   /////// F9 ////////\n";
    cout << "\t\t\t\t\t   /////////////////// \n\n\n";
    cout << "\t\t\t\t\t 1:- Play Game.\n";
    cout << "\t\t\t\t\t 2:- Instructions.\n";
    cout << "\t\t\t\t\t 3:- Exit.\n";
    cin >> option;
    return option;
}
void instruction()
{
    cout << endl;
}
void GameControls()
{
    if (GetAsyncKeyState(VK_LEFT))
    {
        MoveLeft();
    }
    if (GetAsyncKeyState(VK_RIGHT))
    {
        MoveRight();
    }
    if (GetAsyncKeyState(VK_UP))
    {
        MoveUp();
    }
    if (GetAsyncKeyState(VK_DOWN))
    {
        MoveDown();
    }
}
int CarsLane()
{
    srand(time(NULL));
    int result = 1 + (rand() % 4);
    return result;
}
bool CarsRunning()
{
    bool a1, a2, a3, a4;
    int value = CarsLane();
    if (value == 1) // Move Car In 1st Lane (Down_Ward)..
    {
        a1 = car1();
    }
    if (value == 2)
    {
        a2 = car2();
    }
    if (value == 3)
    {
        a3 = car3();
    }
    if (value == 4)
    {
        a4 = car4();
    }
    // if (a1 == false || a2 == false || a3 == false || a4 == false)
    // {
    //     return false;
    // }
}
void MoveLeft()
{
    if (Position[0].Y - 1 != 11)
    {
        for (int i = 0; i < 16; i++)
        {
            gotoxy(Position[i].X, Position[i].Y);
            cout << " ";
            Position[i].Y = Position[i].Y - 1;
            gotoxy(Position[i].X, Position[i].Y);
            cout << "#";
        }
    }
}
void MoveRight()
{
    if (Position[0].Y - 1 != 46)
    {
        for (int i = 15; i >= 0; i--)
        {
            gotoxy(Position[i].X, Position[i].Y);
            cout << " ";
            Position[i].Y = Position[i].Y + 1;
            gotoxy(Position[i].X, Position[i].Y);
            cout << "#";
        }
    }
}
void MoveUp()
{
    if (Position[0].X - 1 != 0)
    {
        for (int i = 0; i < 16; i++)
        {
            gotoxy(Position[i].X, Position[i].Y);
            cout << " ";
            Position[i].X = Position[i].X - 1;
            gotoxy(Position[i].X, Position[i].Y);
            cout << "#";
        }
    }
}
void MoveDown()
{
    if (Position[0].X + 1 != 19)
    {
        for (int i = 15; i >= 0; i--)
        {
            gotoxy(Position[i].X, Position[i].Y);
            cout << " ";
            Position[i].X = Position[i].X + 1;
            gotoxy(Position[i].X, Position[i].Y);
            cout << "#";
        }
    }
}
bool car1()
{
    for (int i = 0; i < 12; i++)
    {
        gotoxy(lane1[i].X, lane1[i].Y);
        cout << "%";
    }
    for (int i = 11; i >= 0; i--)
    {
        gotoxy(lane1[i].X, lane1[i].Y);
        cout << " ";
        lane1[i].X += 1;
        gotoxy(lane1[i].X, lane1[i].Y);
        cout << "%";
    }

    return true;
}
bool car2()
{
    for (int i = 0; i < 12; i++)
    {
        gotoxy(lane2[i].X, lane2[i].Y);
        cout << "%";
    }
    for (int i = 11; i >= 0; i--)
    {
        gotoxy(lane2[i].X, lane2[i].Y);
        cout << " ";
        lane2[i].X += 1;
        gotoxy(lane2[i].X, lane2[i].Y);
        cout << "%";
    }
    return true;
}
bool car3()
{
    for (int i = 0; i < 12; i++)
    {
        gotoxy(lane3[i].X, lane3[i].Y);
        cout << "%";
    }
    for (int i = 11; i >= 0; i--)
    {
        gotoxy(lane3[i].X, lane3[i].Y);
        cout << " ";
        lane3[i].X += 1;
        gotoxy(lane3[i].X, lane3[i].Y);
        cout << "%";
    }
    return true;
}
bool car4()
{
    for (int i = 0; i < 12; i++)
    {
        gotoxy(lane4[i].X, lane4[i].Y);
        cout << "%";
    }
    for (int i = 11; i >= 0; i--)
    {
        gotoxy(lane4[i].X, lane4[i].Y);
        cout << " ";
        lane4[i].X += 1;
        gotoxy(lane4[i].X, lane4[i].Y);
        cout << "%";
    }
    return true;
}