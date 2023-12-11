#include <iostream>

using namespace std;

int main()
{
    string FirstName;
    string LastName;
    int age;
    string addr;
    int idNum;

    cout << "Please input your first name: ";
    cin >> FirstName;
    cout << "Your first name is " << FirstName << endl;

    cout << "Please input your last name: ";
    cin >> LastName;
    cout << "Your last name is " << LastName << endl;

    cout << "Please input your age: ";
    cin >> age;
    cout << "Your are " << age << endl;

    cout << "Please input your address: ";
    cin.ignore();
    getline (cin, addr);
    cout << "Your address is: " << addr << endl;

    cout << "Please input your ID number: ";
    cin >> idNum;
    cout << "Your ID number is " << idNum << endl;


    return 0;
}
