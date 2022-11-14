#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <time.h>
using namespace std;
// car in 2D array
char car[6][7] =
    {
        {' ', ' ', ' ', '#', ' ', ' ', ' '},
        {' ', ' ', '#', '#', '#', ' ', ' '},
        {'#', '#', '#', '#', '#', '#', '#'},
        {' ', '#', '#', '#', '#', '#', ' '},
        {'#', '#', '#', '#', '#', '#', '#'},
        {' ', ' ', '#', '#', '#', ' ', ' '}};
int car_x = 27;   // X-axis
int car_y = 50;   // Y-axis
int enemyX[7];    // enemy cars X-axis
int enemyY[7];    // enemy cars Y-axis
int enemyFlag[7]; // enemy flags in program
int const row = 209, col = 61;
int lifeline = 3;       // for lifeline
int score = 0;          // for score
void resetEverything(); // reseting all necessary varaibles before starting the game
char track[row][col];   // array for game
char mainMenu();        // main menu
void playGame();        // playing game
// void playingGameBox();                      // printing the game box 
void items();                               // displaying valuse of score 
void instruct();                        // printing instruct 
void gameOverMessage(int x, int y);         //  its all three lifeline 
void readTrack();                           // reading track from file
bool gameover();                            // checking the collisions of my car anf enemy cars
void printing(int m, int x, int y, int c);  // printing space behind the car
void move_car(int car_x, int car_y, int m); // moving my car
void gotoxy(int x, int y);                  // displaying some thing on specific location
void movingTrack(int x);                    // moving track on screen
void drawEnemy(int ind);                    // displayong enemy car
void erase(int x, int y);
int GenRandomNu();    // generating random numbers
void GenerateEnemy(); // generating randomly enemy cars
void increaseIndex(); // changing the index of enemy car for moving
void resetingIndex(); // specific height  than reset the enemy car index
// main
main()
{
    readTrack();
    char option;
    while (true)
    {
        system("cls");
        option = mainMenu();
        if (option == '1')
        {
            playGame();
        }
        else if (option == '2')
        {
            instruct();
            cout << "\n Press any key to continue.. ";
            getch();
        }
        else if (option == '3')
        {
            break;
        }
    }
}
char mainMenu()
{
    char option;
    gotoxy(30, 10);
    cout << "*********************************\n";
    gotoxy(30, 11);
    cout << "********** F9 Car Game **********\n";
    gotoxy(30, 12);
    cout << "*********************************\n";
    gotoxy(30, 15);
    cout << " select any one option >>>";
    gotoxy(30, 17);
    cout << " 1. play game : ";
    gotoxy(30, 19);
    cout << " 2. instructions ";
    gotoxy(30, 21);
    cout << " 3. exit ";
    gotoxy(30, 23);
    cout << " your option...: ";
    option = getche();
    return option;
}
// start playing game
void playGame()
{
    Sleep(50);
    system("cls");
    char m = 0;
    int x;
    int a = row - 61;
    int loop = 0, killStop = 0, b = 0;
    resetEverything();
    // playingGameBox();

    instruct();
    while (true)
    {
        gotoxy(70, 50);
        items();
        if (lifeline == 0)
        {
            gameOverMessage(1, 30);
            break;
        }
        x = a;
        movingTrack(x);
        a = a - 1;
        if (a == 0)
        {
            a = row - 61;
        }
        if (GetAsyncKeyState(VK_LEFT))
        {
            if (car_x > 1)
            {
                car_x--;
                m = 1;
            }
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            if (car_x < 52)
            {
                car_x++;
                m = 2;
            }
        }
        if (GetAsyncKeyState(VK_UP))
        {
            if (car_y > 0)
            {
                car_y--;
                m = 3;
            }
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            if (car_y < 53)
            {
                car_y++;
                m = 4;
            }
        }
        move_car(car_x, car_y, m);
        if (GetAsyncKeyState(VK_ESCAPE))
        {
            break;
        }
        if (loop == 5)
        {
            GenerateEnemy();
            loop = 0;
        }
        loop++;
        drawEnemy(0);
        drawEnemy(1);
        drawEnemy(2);
        drawEnemy(3);
        drawEnemy(4);
        drawEnemy(5);
        drawEnemy(6);
        if (killStop == 0)
        {
            b = 0;
            if (gameover())
            {
                killStop = 25;
                b = 1;
            }
        }
        if (b == 1)
        {
            killStop--;
        }
        increaseIndex();
        resetingIndex();
        Sleep(50);
    }
    cin.ignore();
}
// reseting all necessary varaibles before starting the game
void resetEverything()
{
    lifeline = 3;
    score = 0;
    car_x = 27;
    car_y = 50;
    enemyFlag[0] = enemyFlag[1] = enemyFlag[2] = enemyFlag[3] = enemyFlag[4] = enemyFlag[5] = enemyFlag[6] = 0;
}
// read track
void readTrack()
{
    string line;
    fstream file;
    file.open("Game.txt", ios::in);
    for (int x = 0; x < row; x++)
    {
        getline(file, line);
        for (int y = 0; y < col; y++)
        {
            track[x][y] = line[y];
        }
    }
    file.close();
}
// moving track
void movingTrack(int x)
{
    for (int n = 0; n < 59; n++)
    {
        gotoxy(0, n);
        cout << track[x];
        x = x + 1;
    }
}
// moveing car
void move_car(int car_x, int car_y, int m)
{
    int n = car_y;
    printing(m, car_x, car_y, 1);

    for (int i = 0; i < 6; i++)
    {

        gotoxy(car_x, n);
        for (int y = 0; y < 7; y++)
        {
            cout << car[i][y];
        }
        n++;
    }
    printing(m, car_x, car_y, 0);
}

void printing(int m, int x, int y, int c)
{
    if (m == 1)
    {
        x = x + 7;
        for (int t = 0; t < 6; t++)
        {
            gotoxy(x, y + t);
            cout << " ";
        }
    }
    else if (m == 2 && c == 1)
    {
        x--;
        for (int t = 0; t < 6; t++)
        {
            gotoxy(x, y + t);
            cout << " ";
        }
    }
    else if (m == 3)
    {
        y = y + 6;
        gotoxy(x, y);
        cout << "      ";
    }
    else if (m == 4)
    {
        y--;
        gotoxy(x, y);
        cout << "      ";
    }
}
// gotoxy
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
// genrendomnum
int GenRandomNu()
{
    return rand() % (7);
}
// game over
bool gameover()
{
    bool flag = false;
    for (int i = 0; i < 7; i++)
    {
        for (int x = 0; x < 7; x++)
        {
            if ((car_x + x >= enemyX[i] && car_x + x <= enemyX[i] + 6) && (car_y >= enemyY[i] && car_y <= enemyY[i] + 3))
            {
                flag = true;
            }
        }
        for (int j = 0; j < 3; j++)
        {
            if (car_x == enemyX[i] + 6 && car_y + 2 == enemyY[i] + j)
            {
                flag = true;
            }
        }
        for (int j = 0; j < 3; j++)
        {
            if (car_x == enemyX[i] + 6 && car_y + 4 == enemyY[i] + j)
            {
                flag = true;
            }
        }
        for (int j = 0; j < 3; j++)
        {
            if (car_x + 6 == enemyX[i] && car_y + 2 == enemyY[i] + j)
            {
                flag = true;
            }
        }
        for (int j = 0; j < 3; j++)
        {
            if (car_x + 6 == enemyX[i] && car_y + 4 == enemyY[i] + j)
            {
                flag = true;
            }
        }
    }
    if (flag)
    {
        lifeline--;
        car_x = 27;
        car_y = 50;
        return true;
    }
    return false;
}
// generateenemy
void GenerateEnemy()
{
    int random;
    random = GenRandomNu();
    if (random == 0 && enemyFlag[0] == 0)
    {
        enemyX[0] = 4;
        enemyY[0] = 0;
        enemyFlag[0] = 1;
    }
    else if (random == 1 && enemyFlag[1] == 0)
    {
        enemyX[1] = 19;
        enemyY[1] = 0;
        enemyFlag[1] = 1;
    }
    else if (random == 2 && enemyFlag[2] == 0)
    {
        enemyX[2] = 34;
        enemyY[2] = 0;
        enemyFlag[2] = 1;
    }
    else if (random == 3 && enemyFlag[3] == 0)
    {
        enemyX[3] = 49;
        enemyY[3] = 0;
        enemyFlag[3] = 1;
    }
    else if (random == 4 && enemyFlag[4] == 0)
    {
        enemyX[4] = 12;
        enemyY[4] = 0;
        enemyFlag[4] = 1;
    }
    else if (random == 5 && enemyFlag[5] == 0)
    {
        enemyX[5] = 27;
        enemyY[5] = 0;
        enemyFlag[5] = 1;
    }
    else if (random == 6 && enemyFlag[6] == 0)
    {
        enemyX[6] = 42;
        enemyY[6] = 0;
        enemyFlag[6] = 1;
    }
}
// drawenemy
void drawEnemy(int ind)
{
    if (enemyFlag[ind] == 1)
    {
        if (enemyY[ind] != 0)
        {
            gotoxy(enemyX[ind], enemyY[ind] - 1);
            cout << "       ";
        }
        gotoxy(enemyX[ind], enemyY[ind]);
        cout << "*******";
        gotoxy(enemyX[ind], enemyY[ind] + 1);
        cout << "*******";
        gotoxy(enemyX[ind], enemyY[ind] + 2);
        cout << "*******";
        gotoxy(enemyX[ind], enemyY[ind] + 3);
        cout << "  ***  ";
        gotoxy(enemyX[ind], enemyY[ind] + 4);
        cout << "   *   ";
    }
}
// increase index
void increaseIndex()
{
    for (int idx = 0; idx < 7; idx++)
    {
        if (enemyFlag[idx] == 1)
        {
            enemyY[idx] = enemyY[idx] + 1;
        }
    }
}
// reseting index
void resetingIndex()
{
    for (int idx = 0; idx < 7; idx++)
    {
        if (enemyY[idx] == 54)
        {
            erase(enemyX[idx], enemyY[idx]);
            enemyY[idx] = 0;
            enemyFlag[idx] = 0;
            score++;
        }
    }
}

void erase(int x, int y)
{
    gotoxy(x, y - 1);
    cout << "       ";
    gotoxy(x, y);
    cout << "       ";
    gotoxy(x, y + 1);
    cout << "       ";
    gotoxy(x, y + 2);
    cout << "       ";
    gotoxy(x, y + 3);
    cout << "       ";
    gotoxy(x, y + 4);
    cout << "       ";
}

void items()
{
    gotoxy(70, 20);
    cout << " score : " << score;
    gotoxy(70, 22);
    cout << " lifeline : " << lifeline;
}

void instruct()
{
    gotoxy(82, 35);
    cout << " controls for car ";
    gotoxy(77, 37);
    cout << " for moving left  : left arrow key ";
    gotoxy(77, 39);
    cout << " for moving right : right arrow key ";
    gotoxy(77, 41);
    cout << " for moving up    : up arrow key ";
    gotoxy(77, 43);
    cout << " for moving down  : down arrow key ";
}

// void playingGameBox()
// {

//     for (int x = 0; x < 126 - 61; x++)
//     {

//         if (x < (126 - 61) / 2)
//         {
//             gotoxy(61 + x, 0);
//             cout << "[";
//             gotoxy(61 + x, 16);
//             cout << "[";
//             gotoxy(61 + x, 48);
//             cout << "[";
//             gotoxy(61 + x, 58);
//             cout << "[";
//         }
//         else
//         {
//             gotoxy(61 + x, 0);
//             cout << "]";
//             gotoxy(61 + x, 16);
//             cout << "]";
//             gotoxy(61 + x, 48);
//             cout << "]";
//             gotoxy(61 + x, 58);
//             cout << "]";
//         }
//     }
//     for (int i = 0; i < 59; i++)
//     {
//         gotoxy(61, i);
//         cout << "[[[";
//         gotoxy(126, i);
//         cout << "]]]";
//     }
// }

void gameOverMessage(int x, int y)
{
    gotoxy(x, y - 1);
    cout << "                                                                                                                                          " << endl;
    gotoxy(x, y);
    cout << "           ########     ############    ##         ##    ############        ############    #             #    ############    ########  " << endl;
    gotoxy(x, y + 1);
    cout << "         #         #    #          #    # #       # #    #                   #          #    #             #    #               #       # " << endl;
    gotoxy(x, y + 2);
    cout << "        #          #    #          #    #  #     #  #    #                   #          #    #             #    #               #        #" << endl;
    gotoxy(x, y + 3);
    cout << "       #                #          #    #   #   #   #    #                   #          #    #             #    #               #        #" << endl;
    gotoxy(x, y + 4);
    cout << "      #                 #          #    #    # #    #    #                   #          #     #           #     #               #       # " << endl;
    gotoxy(x, y + 5);
    cout << "      #                 ############    #     #     #    ############        #          #      #         #      ############    ########  " << endl;
    gotoxy(x, y + 6);
    cout << "      #                 #          #    #           #    #                   #          #       #       #       #               ##        " << endl;
    gotoxy(x, y + 7);
    cout << "       #                #          #    #           #    #                   #          #        #     #        #               #  #      " << endl;
    gotoxy(x, y + 8);
    cout << "        #      ####     #          #    #           #    #                   #          #         #   #         #               #    #    " << endl;
    gotoxy(x, y + 9);
    cout << "         #     #  #     #          #    #           #    #                   #          #          # #          #               #      #  " << endl;
    gotoxy(x, y + 10);
    cout << "          ######  #     #          #    #           #    ############        ############           #           ############    #       # " << endl;
    gotoxy(x, y + 11);
    cout << "                                                                                                                                          " << endl;
}