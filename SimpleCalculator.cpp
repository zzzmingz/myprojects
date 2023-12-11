#include<iostream>

using namespace std;

int main()
{
    char op;
    float num1, num2;
    int num3, num4;

    cin >> op;

    switch (op) {

    case '+':
    cin >> num1 >> num2;
    cout << num1 + num2;
    break;

    case '-':
    cin >> num1 >> num2;
    cout << num1 - num2;
    break;

    case '*':
    cin >> num1 >> num2;
    cout << num1 * num2;
    break;

    case '/':
    cin >> num1 >> num2;
    cout << num1 / num2;
    break;

    case '%':
    cin >> num3 >> num4;
    cout << num3 % num4;
    break;

    default:
        cout << "Error! Operator is not correct";
        break;
    }

    return 0;
}
