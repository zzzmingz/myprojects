#include <iostream>
using namespace std;

int bridgeaccountno = 7777;
int bridgepinno = 1111;
int balance = 1000;

bool login () {

	int givenbridgeaccountno = -1;
	int givenbridgepinno = -1;
	bool isAccountInvalid = true;
	bool isPinInvalid = true;

	cout << "WELCOME!\n" << endl;

	while (isAccountInvalid) {

		cout << "Please enter your account number: ";
		cin >> givenbridgeaccountno;

		if (givenbridgeaccountno == bridgeaccountno) {
			isAccountInvalid = false;
		} else {
			cout << "INVALID ACCOUNT NUMBER! Try again." << endl;
		}
	}

	while (isPinInvalid) {

		cout << "Enter your 4 digit PIN: ";
		cin >> givenbridgepinno;

		if (givenbridgepinno == bridgepinno) {
			isPinInvalid = false;
		} else {
			cout << "INVALID PIN NUMBER! Try again." << endl;
		}

	}

	return true;
}

int getUserOption () {

    int selectedoption = -1;

    cout << "\n--- MAIN MENU: \n" << endl;
    cout << "\t1 - View my balance" << endl;
    cout << "\t2 - Withdraw cash" << endl;
    cout << "\t3 - Deposit funds" << endl;
    cout << "\t4 - Exit\n" << endl;
    cout << " Enter a choice: ";
    cin >> selectedoption;

    return selectedoption;


}

void viewBalance (){

    cout << "\n\tYou have " << balance << " UwU." << endl;

}

void withdrawUwu (){

    int selectedoption = -1;
    int ValueToWithdraw = 0;
    bool isNotFinished = true;

    do {

        cout << "\n\tWITHDRAWAL OPTIONS: " << endl;
        cout << "\t1 - 100 UwU" << endl;
        cout << "\t2 - 200 UwU" << endl;
        cout << "\t3 - 500 UwU" << endl;
        cout << "\t4 - 1000 UwU" << endl;
        cout << "\t5 - 2000 UwU" << endl;
        cout << "\t6 - Cancel transaction" << endl;
        cout << "\tChoose a withdrawal options (1-6): ";
        cin >> selectedoption;


        switch (selectedoption) {
        case 1:
            ValueToWithdraw = 100;
            break;
        case 2:
            ValueToWithdraw = 200;
            break;
        case 3:
            ValueToWithdraw = 500;
            break;
        case 4:
            ValueToWithdraw = 1000;
            break;
        case 5:
            ValueToWithdraw = 2000;
            break;
        case 6:
            isNotFinished = false;
            break;
        default:
            cout << "\n\tINVALID OPTION! Try again." << endl;
            break;
        }

        if (ValueToWithdraw != -1) {
            if (ValueToWithdraw > balance) {
                cout << "\n\tINSUFFICIENT FUNDS!" << " You can't withdraw " << ValueToWithdraw << " UwU." << endl;
            } else {
                balance = balance - ValueToWithdraw;
                cout << "\n\tYou withdrew " << ValueToWithdraw << " UwU." << "Your balance now is " << balance << " UwU.\n" << endl;
                isNotFinished = false;
            }
            ValueToWithdraw = 0;
        }

    } while (isNotFinished);

}
void depositUwu() {

	int selectedoption = -1;
	bool isNotFinished = true;

	do {

        cout << "\n\tDEPOSIT OPTIONS: " << endl;
        cout << "\t1 - 100 UwU" << endl;
        cout << "\t2 - 200 UwU" << endl;
        cout << "\t3 - 500 UwU" << endl;
        cout << "\t4 - 1000 UwU" << endl;
        cout << "\t5 - 2000 UwU" << endl;
        cout << "\t6 - Cancel transaction" << endl;
        cout << "\tChoose a deposit options (1-6): ";
        cin >> selectedoption;

        switch (selectedoption) {
        case 1:
            balance = balance + 100;
            isNotFinished = false;
            break;
        case 2:
            balance = balance + 200;
            isNotFinished = false;
            break;
        case 3:
            balance = balance + 500;
            isNotFinished = false;
            break;
        case 4:
            balance = balance + 1000;
            isNotFinished = false;
            break;
        case 5:
            balance = balance + 2000;
            isNotFinished = false;
            break;
        case 6:
            isNotFinished = false;
            break;
        default:
            cout << "\n\tINVALID OPTION! Try again." << endl;
            break;
		}
            cout << "\n	Your balance now is " << balance << " UwU.\n" << endl;
	} while (isNotFinished);

}

int main (){
    if (login()) {

        int isNotFinished = true;

        do {

            switch (getUserOption()) {
            case 1:
                viewBalance();
                break;
            case 2:
                withdrawUwu();
                break;
            case 3:
                depositUwu();
                break;
            case 4:
                isNotFinished = false;
            default:
                cout << "INVALID OPTION! Try again." << endl;
                break;
            }
        } while (isNotFinished);

    }

    return 0;


}
