#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class user
{
    string userName, email, password;
    string searchUserName, searchEmail, searchPw;
    fstream file;

public:
    void signUp();
    void logIn();
    void forgotPw();
};

int main()
{
    class user me;
    char choice;
    cout << "\n1- Login";
    cout << "\n2- Sign Up";
    cout << "\n3- Forgot Password";
    cout << "\n4- Exit";
    cout << "\n\nEnter your Choice :\t";
    cin >> choice;

    // to ignore the new line buffer created by cin
    cin.ignore();

    switch (choice)
    {
    case '1':
        cout << "Login page Loading...." << endl;
        me.logIn();
        break;
    case '2':
        cout << "Sign-Up page Loading...." << endl;
        me.signUp();
        break;
    case '3':
        cout << "Password page Loading...." << endl;
        me.forgotPw();
        break;
    case '4':
        cout << "Exiting...." << endl;
        break;
    default:
        cout << "Please enter appropriate choice.";
    }
    return 0;
}

// function definitions section
void user ::signUp()
{
    cout << "Enter your username : " << endl;
    // To read a line of input
    getline(cin, userName);
    cout << "Enter your email Id : " << endl;
    getline(cin, email);
    cout << "Enter your password : " << endl;
    getline(cin, password);

    /*Opens the file "loginData.txt" for writing (appending if it exists)
    ios :: out --> file is opened for reading
    ios :: app --> file is opened for appending
    */

    file.open("loginData.txt", ios ::out | ios ::app);
    // writing data to a line in a file
    file << userName << "*" << email << "*" << password << endl;
    file.close();
}

void user ::logIn()
{
    int flag = 0; // to ensure availability of username
    cout << "------LOGIN------" << endl;
    cout << "Enter your username :\t";
    getline(cin, searchUserName);

    // opening file for input opeartion, for reading file
    file.open("loginData.txt", ios ::in);

    // reading characters from the file stream 'file' into the userName variable until it encounters the '*' character
    getline(file, userName, '*');  // reading username from file
    getline(file, email, '*');     // reading emial form file
    getline(file, password, '\n'); // reading password from file

    while (!file.eof())
    {
        // cout << "check start" << endl;
        // cout << " " << userName << endl;
        // cout << " " << email << endl;
        // cout << " " << password << endl;
        // cout << "check end" << endl;

        if (userName == searchUserName)
        {
            cout << "Username found" << endl;
            cout << "Enter your password : " << endl;
            getline(cin, searchPw); // reading password from user
            if (password == searchPw)
            {
                cout << "Login Successful" << endl;
                flag = 1;
            }
            else
            {
                cout << "Incorrect Password." << endl;
            }
            break;
        }
        //reading username, email and password for next user
        getline(file, userName, '*');
        getline(file, email, '*');
        getline(file, password, '\n');
    }
    if (flag == 0)
    {
        cout << "Error searching account..." << endl;
    }
}
void user ::forgotPw()
{
    int flag = 0;
    cout << "\nEnter your Username : ";
    getline(cin, searchUserName);
    cout << "\nEnter your email : ";
    getline(cin, searchEmail);

    file.open("loginData.txt", ios ::in);
    getline(file, userName, '*');
    getline(file, email, '*');
    getline(file, password, '\n');

    while (!file.eof())
    {
        if (searchUserName == userName)
        {
            if (searchEmail == email)
            {
                cout << "Account found" << endl;
                cout << "Your password is : " << password << endl;
                flag = 1;
            }
            else
            {
                cout << "Invalid email...!" << endl;
            }
            break;
        }
        getline(file, userName, '*');
        getline(file, email, '*');
        getline(file, password, '\n');
    }
    if (flag == 0)
    {
        cout << "Error searching account..." << endl;
    }
}