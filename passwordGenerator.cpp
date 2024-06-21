#include <iostream> //to use cout & cin
#include <cstdlib>  //to use rand()
#include <ctime>    //accessing time
#include <string>   //to handle strings

using namespace std;

string genPas(int l)
{
    string pw;
    string characterSet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int charSize = characterSet.size();

    // used to seed the random number generator (rand() function) with the current time.
    srand(time(0));
    int randIdx;
    for (int i = 0; i < l; i++)
    {
        // generates a random index within the range [0, charSize-1], where charSize is the size of the character set.
        randIdx = rand() % charSize;
        pw = pw + characterSet[randIdx];
    }
    return pw;
}

int main()
{
    int length;
    string password;
    cout << "Enter the length of the password: ";
    if (!(cin >> length) || length <= 0)
    {
        cerr << "Error: Please enter a valid positive integer for the password length." << endl;
        return 1; // Return a non-zero exit code to indicate an error
    }
    password = genPas(length);
    cout << "Your Password is : " << password << endl;
    return 0;
}