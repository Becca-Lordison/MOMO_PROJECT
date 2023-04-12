#include <iostream>
#include <limits>

using namespace std;

int main()
{
    int balance = 1000; // Default balance
    string  pin = "0000"; // Default pin
    int attempts = 0; // Keeps track of the number of attempts
    bool authenticated = false;

    while (!authenticated) // Keep asking for authentication until it succeeds
    {
        cout << "Enter your PIN: ";
        cin >> pin;

        if (cin.fail()) // Check if the input is a number
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            attempts++;
            if (attempts >= 3)
            {
                cout << "You have exceeded the maximum number of attempts. Exiting program." << endl;
                return 0;
            }
            continue;
        }

        if (pin == "0000") // Replace 1234 with the correct pin
        {
            authenticated = true;
            cout << "Authentication successful" << endl;
        }
        else
        {
            attempts++;
            if (attempts >= 3)
            {
                cout << "You have exceeded the maximum number of attempts. Exiting program." << endl;
                return 0;
            }
            cout << "Invalid PIN. Please try again." << endl;
        }
    }

    // Display menu
   int choice = 0;

while (true)
{
    cout << "Welcome to Mobile Banking System. Please select an option:" << endl;
    cout << "1. Change PIN" << endl;
    cout << "2. Check balance" << endl;
    cout << "3. Send Money" << endl;
    cout << "4. Exit" << endl;

    cin >> choice;

    if (cin.fail()) // Check if the input is a number
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number." << endl;
        continue;
    }

    if (choice == 1)
    {
        string old_pin;
        string new_pin;
        cout << "Enter your old PIN: "<<endl;
        cin >> old_pin;

        if (cin.fail()) // Check if the input is a number
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        if (old_pin == pin || old_pin == "0000")
        {
            cout << "Enter your new PIN: "<<endl;
            cin >> new_pin;

            if (cin.fail()) // Check if the input is a number
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a number." << endl;
                continue;
            }

            pin = new_pin;
            cout << "PIN changed successfully" << endl;
        }
        else
        {
            cout << "Invalid old PIN. Please try again." << endl;
        }
    }
    else if (choice == 2)
    {
        string balance_pin;
        cout<<"enter your momo pin: "<<endl;
        cin>>balance_pin;
        if (cin.fail()) // Check if the input is a number
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }
        if (balance_pin != pin)
        {
            cout << "Invalid MoMo PIN. Please try again." << endl;
            continue;
        }

        cout << "Your balance is: " << balance << endl;
    }
    else if (choice == 3)
    {
        string momo_pin;
        int amount;
        string num;
        cout << "Enter a Valid Mobile number: ";
        cin >> num;
        cout<<"Enter the amount to send: ";
        cin >> amount;
        cout<<"enter your Pin:";
        cin>>momo_pin;

        if (cin.fail()) // Check if the input is a number
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }
        if (momo_pin != pin)
        {
            cout << "Invalid MoMo PIN. Please try again." << endl;
            continue;
        }

        if (amount <= balance)
        {
            balance -= amount;
            cout << "Transaction successful" << endl;
            cout << "New balance: " << balance << endl;
        }
        else
        {
            cout << "Insufficient funds" << endl;
        }
    }
    else if (choice == 4)
    {
        cout << "Exiting program." << endl;
        return 0;
    }
    else
    {
        cout << "Invalid choice" << endl;
    }
}


    return 0;
}
}
