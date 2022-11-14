#include <iostream>
#include <fstream>
#include <conio.h>

int GetWinner(int symbol);
int CheckRows(int symbol);
int CheckColumns(int symbol);
int CheckDiagonals(int symbol);

int a[3] = {11, 12, 13};
int b[3] = {21, 22, 23};
int c[3] = {31, 32, 33};

using namespace std;
int main()
{
    int i = 1, count = 0;
    int first, second;
    int symbol;

    int taken;

    while (true)
    {
        for (int z = 0; z < 3; z++)
        {
            if (taken == a[z])
            {
                a[z] = symbol;
            }
            if (taken == b[z])
            {
                b[z] = symbol;
            }
            if (taken == c[z])
            {
                c[z] = symbol;
            }
        }
        system("cls");
        cout << "                  ----------------------------------------------------------------------" << endl;
        cout << "                  -                               Tic Tak Toe                          -" << endl;
        cout << "                  ----------------------------------------------------------------------" << endl;
        cout << "                  " << endl
             << endl;
        if (count > 0)
        {
            cout << "      Note :-" << endl
                 << "               Taken Boxes By Player 1 Are Shown By 10" << endl
                 << "               Taken Boxes By Player 2 Are Shown By 20" << endl
                 << endl;
        }

        cout << "                                 _____________________" << endl;
        cout << "                                  " << a[0] << "  |  " << a[1] << "  |  " << a[2] << "  | " << endl;
        cout << "                                ______|______|______|" << endl;
        cout << "                                  " << b[0] << "  |  " << b[1] << "  |  " << b[2] << "  | " << endl;
        cout << "                                ______|______|______| " << endl;
        cout << "                                  " << c[0] << "  |  " << c[1] << "  |  " << c[2] << "  | " << endl;
        cout << "                                ______|______|______|" << endl;
        if (count % 2 == 0)
        {
            i = 1;
            symbol = 10;
        }
        else
        {
            symbol = 20;
        }
        cout << "                   player " << i << " Turn: " << endl;
        while (true)
        {
            cout << "                         Enter 1st Digit: ";
            cin >> first;
            cout << "                         Enter 2nd Digit: ";
            cin >> second;
            taken = first * 10;
            taken = taken + second;
            if (count > 0)
            {
                int cont = 0;
                for (int i = 0; i < 3; i++)
                {
                    if (taken == a[i])
                    {
                        cont = 1;
                        break;
                    }
                    if (taken == b[i])
                    {
                        cont = 1;
                        break;
                    }
                    if (taken == c[i])
                    {
                        cont = 1;
                        break;
                    }
                }
                if (cont == 0)
                {
                    cout << "                           Already Taken  :) ";
                    cout << "                       Press Any Key: ";
                    getch();
                }
            }

            if (first <= 3 && second <= 3)
            {
                break;
            }
            else
            {
                cout << "                           InCorrect Input!!!  TRY AGAIN  :) " << endl
                     << endl;
                cout << "                       Press Any Key: ";
                getch();
            }
        }

        if (count > 3)
        {
            // check who wins.
            for (int y = 0; y < 2; y++)
            {
                int value = 10;
                int player = GetWinner(value);
                if (player == 1)
                {
                    cout << "                         ---------Congratulation-------------";
                    cout << "                            Player " << player << " Wins...";
                    exit(0);
                }
                value = 10 + 10;
            }
        }

        count++;
        i++;
    }

    return 0;
}
int GetWinner(int symbol)
{
    if ((CheckRows(symbol) == 1) || (CheckColumns(symbol) == 1) || (CheckDiagonals(symbol) == 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int CheckColumns(int symbol)
{
    if (a[0] == symbol && b[0] == symbol && c[0] == symbol)
    {
        return 1;
    }
    else if (a[1] == symbol && b[1] == symbol && c[1] == symbol)
    {
        return 1;
    }
    else if (a[2] == symbol && b[2] == symbol && c[2] == symbol)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int CheckRows(int symbol)
{
    if (a[0] == symbol && a[1] == symbol && a[2] == symbol)
    {
        return 1;
    }
    else if (b[0] == symbol && b[1] == symbol && b[2] == symbol)
    {
        return 1;
    }
    else if (c[0] == symbol && c[1] == symbol && c[2] == symbol)
    {
        return 1;
    }
    else
        return 0;
}
int CheckDiagonals(int symbol)
{
    if (a[0] == symbol && b[1] == symbol && c[2] == symbol)
    {
        return 1;
    }
    else if (a[2] == symbol && b[1] == symbol && c[0] == symbol)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}