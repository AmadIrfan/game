#include <iostream>
using namespace std;
int main()
{
    int num, num1;
    cout << "enter 2 numbers ";
    cin >> num;
    cin >> num1;
    int i;
    for (i = num; i < num1; i++)
    {
        int ij;
        for (ij = 2; ij < num; ij++)
        {
            if (num % ij == 0)
            {
                break;
            }
        }
        if (ij == num)
        {
            cout << num << endl;
        }
    }
    return 0;
}