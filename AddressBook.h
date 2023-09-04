#include <iostream>
#include <vector>
#include<windows.h>
#include<fstream>
#include<sstream>

#include "User.h"

using namespace std;

class AddressBook
{
    int idOfLoggedUser;
    int idOfLastUser;
    int idOfDeletedUser;

    string nameOfFileWithUsers;

    vector <User> users;

    User enterDataOfNewUser();
    int getIdOfNewUser();
    bool doUserExist(string login);
    void writeUserToFile(User user);
    string changeFormatOfLineToFormatOdAddressBook(User user);
    string convertIntToString(int number);
    bool doFileIsEmpty(fstream &textFile);

public:
    AddressBook();
    void registerUser();
    void displayAllUsers();

};
