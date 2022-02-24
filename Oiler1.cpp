#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
    string menu;
    float depositamount;
    float withdrawamount;
    float Balance = 1000;

    cout<<"\n your current balance is $1000";
    menu = "B";
    while(menu== "D" || menu =="B" || menu == "W")
    {
      cout << "\n Oiler Bank";
      cout << "\n [D] Deposit";
      cout << "\n [B] Balance";
      cout << "\n [W] Withdraw";
      cout << "\n enter an option from the menu : ";
      cin  >> menu;
      if (menu == "D")
      {
       cout << "enter an amount between $0.01 && 5000.00";
       cin >> depositamopunt;
       if(depositamount >=0.01 && depositamount <=5000)
       {
           Balance = depositamount + Balance ;
           cout << "the balance is "<< Balance << "$" << endl;

       }
       else 
       {
           cout<< "You have entered a invalid amount" << endl;
       }

      }

    }
    else if (menu == "W")
    {
        cout << "Enter the amount to be withdrawn";
        cin >> withdrawamount ;
        if(withdrawamount < 0)
        {
            cout << "you have entered an negative value" << endl;
        }
        else if (withdrawamount %10 != 0)
        {
            cout << "your value should be a multiple of 10" << endl;
        
        }
        else if(withdrawamount > balance)
        {
            cout << "you are having insufficient funds " << endl;
        }
        else 
        {
            Balance = Balance - withdrawamount;
            cout << "your balance is " << Balance << "$" << endl ;
        }
    }
    else if(menu == "B")
    {
        cout << "Your balance is" << Balance << "$" << endl;
    }
    else if(menu =="X")
    {
        cout << "Thank you for using OILER ATM services"<< endl;
    }
    else
    {
        cout << "please enter a valid option" << endl;
    }
    return 0;
    

}