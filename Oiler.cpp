#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
int main()
{
    string menu;
    float Deposit_amount;
    int Withdraw_amount;
    float balance = 1000.00;
    //float Total_balance;

    cout << " \n your account balance is $1000";
    menu = "B";
    // while (menu == "D" || menu == "W" || menu == "B")
    while (1)
    {
        cout << "\n *** Oiler Banking ***";
        cout << "\n [D] Deposit";
        cout << "\n [W] Withdraw";
        cout << "\n [B] Balance";
        cout << "\n [X] Done";
        cout << "\n *********************";
        cout << "\n choose an option: ";
        cin >> menu;

        if (menu == "D")
        {
            cout << "please enter an amount between $0.01 and $5000.00";
            cin >> Deposit_amount;
            if (Deposit_amount >= 0.01 && Deposit_amount <= 5000)
            {
                // cout << setprecision(2);
                balance = Deposit_amount + balance;
                cout << "Your cureent balance is $" << balance << endl;


            }
            else {
                cout << "Youn have entered an invalid amount " << endl;
            }

        }
        else if (menu == "W")
        {
            cout << "please enter an withdrawls amount";
            cin >> Withdraw_amount;
            if (Withdraw_amount < 0)
            {
                cout << "You have entered an negative amount" << endl;

            }
            else if (Withdraw_amount % 10 != 0)
            {
                cout << "Your withdrawl amount is not a multiple of 10" << endl;

            }
            else if (Withdraw_amount > balance)
            {
                cout << "You're having insufficient funds" << endl;
            }
            else
            {
                // cout << setprecision(2);
                balance = balance - Withdraw_amount;
                cout << "Your current account balance is $" << balance << endl;
            }


        }
        else if (menu == "B")
        {
            // cout << setprecision(2);
            balance += 0.1089;
            cout << "your current balance is $" << balance << endl;
        }
        else if (menu == "X")
        {
            cout << "Thank you for visiting oiler atm" << endl;
            return 0;
        }
        else
        {
            cout << "you have entered an invalid option" << endl;
            
        }
    }
    return 0;
}