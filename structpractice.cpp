#include <iostream>
#include <conio.h>
using namespace std;
struct uni
{
    string adminname;
    int salary;
};
uni takeInput()
{
    uni data;
    cout << "enter the name of admin " << endl;
    cin >> data.adminname;
    cout << "enter the salary of admin" << endl;
    cin >> data.salary;
    return data;
}
void displayoutput(uni d)
{
    cout << "Admin = " << d.adminname << endl;
    cout << "Salary = " << d.salary << endl;
}
main()
{
    uni input;
    input = takeInput();
    displayoutput(input);

    return 0;
}
