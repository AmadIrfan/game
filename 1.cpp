#include <fstream>
#include <iostream>
#include <conio.h>
#include <cmath>
using namespace std;
int main()
{
    int num;
    cout << "enter a number";
    cin >> num;
    int i;
    for ( i= 2; i < num; i++)
    {
        if (num % i == 0)
        {
            cout << num << "non prime number ";
            break;
        }
    }
    if (num == i)
    {

        cout << num << "prime number ";
    }

    return 0;
}