#include <iostream>
using namespace std;
void UI()
{
    float balance = 1000, amount;
    int op;
    do
    {
        cout << "Choose the required functionality you want to perform" << endl;
        cout << "1.Balance enquiry" << endl;
        cout << "2.Amount Withdrawal" << endl;
        cout << "3.Cash Deposit" << endl;
        cout << "4.Exit" << endl;

        cin >> op;
        switch (op)
        {
        case 1:
        {
            cout << "Your balance is Rs." << balance << endl;
            break;
        }
        case 2:
        {
            cout << "Enter the amount required" << endl;
            cin >> amount;
            if (amount < balance)
            {
                cout << "withdrawal of Rs." << amount << "has been successful "<<endl
             << "Please collect your card and cash simultaneously" << endl;
                balance -= amount;
            }
            else
            {
                cout << "Not enough money on your account" << endl
                     << "Sorry! for your inconvinience" << endl;
            }
            break;
        }
        case 3:
        {
            cout << "Enter the amount to be deposited" << endl;
            cin >> amount;
            balance += amount;
            cout << "Your new balance is " << balance << endl;
            break;
        }
        default:
        {
            cout << "Invalid option " << endl;
            break;
        }
        }
    } while (op != 4);
}

int main()
{
    cout << "Welcome to NABIL BANK LIMITED" << endl;
    UI();
    return 0;
}
