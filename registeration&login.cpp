#include <iostream>
#include <fstream>
#include <string>


using namespace std;

void login();
void registration();
void forgotpassword();

int main()
{
    int c;

    cout << "\t\t\t_________________________________________________________\n\n\n";
    cout << "\t\t\t                Welcome to the Login page                \n\n\n";
    cout << "\t\t\t______________________        MENU        _______________\n\n";

    cout << "                                                              " << endl;

    cout << "\t |   Press 1 to LOGIN                   |" << endl;
    cout << "\t |   Press 2 to REGISTER                |" << endl;
    cout << "\t |   Press 3 if forgot your PASSWORD    |" << endl;
    cout << "\t |   Press 4 to EXIT                    |" << endl;
    cout << "\n\t\t\t Please enter your choice: ";
    cin >> c;
    cout << endl;

    switch (c)
    {
    case 1:
        login();
        break;
    case 2:
        registration();
        break;
    case 3:
        forgotpassword();
        break;
    case 4:
        cout << "\t\t\t Thank you! \n\n";
        break;
    default:
        system("cls");
        cout << "\t\t\t Please select from the options given above.\n" << endl;
        main();
        break;
    }

    return 0;
}

void login()
{
    int count = 0;
    string userId, password, id, pass;
    system("cls");
    cout << "\t\t\t Please enter the username and password: " << endl;
    cout << "\t\t\t USERNAME: ";
    cin >> userId;
    cout << "\t\t\t PASSWORD: ";
    cin >> password;

    ifstream input("record.txt");

    while (input >> id >> pass)
    {
        if (id == userId && pass == password) {
            count = 1;
            break;
        }
    }

    input.close();

    if (count == 1) {
        cout << userId << "\n Your LOGIN was successful\n Thanks for logging in \n";
    }
    else {
        cout << "\n WRONG USERNAME or PASSWORD\n Please check your credentials.\n";
    }

    main();
}

void registration()
{
    string ruserId, rpassword, rId, rpass;
    system("cls");
    cout << "\n\t\t\t  Enter USERNAME: ";
    cin >> ruserId;
    cout << "\n\t\t\t  Enter PASSWORD: ";
    cin >> rpassword;

    ofstream f1("record.txt", ios::app);

    f1 << ruserId << ' ' << rpassword << endl;
    f1.close();
    system("cls");

    cout << "\n\t\t\t Registration is successful. \n";

    main();
}

void forgotpassword()
{
    int option;
    system("cls");
    cout << "\t\t\t You forgot your password? \n";
    cout << "Press 1 to search your ID by username " << endl;
    cout << "Press 2 to go back to the main menu " << endl;
    cout << "\t\t\t Enter your choice: ";
    cin >> option;

    switch (option) {
    case 1:
    {
        int count = 0;
        string suserId, sId, spass;
        cout << "\n\t\t\t Enter the USERNAME you used to sign in: ";
        cin >> suserId;

        ifstream f2("record.txt");
        while (f2 >> sId >> spass)
        {
            if (sId == suserId) {
                count = 1;
                break;
            }
        }

        f2.close();

        if (count == 1)
        {
            cout << "\n\n Your account has been found! \n";
            cout << "\n\n Password is: " << spass;
        }
        else {
            cout << "\n\t Sorry, your account hasn't been found";
        }

        break;
    }
    case 2:
        break;
    default:
        cout << "\t\t\t Wrong choice. Please try again.\n";
        break;
    }

    main();
}
