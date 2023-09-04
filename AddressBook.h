#include <iostream>
#include <vector>
#include<windows.h>

#include "User.h"

using namespace std;

class AddressBook
{
    int idOfLoggedUser;
    int idOfLastUser;
    int idOfDeletedUser;

    vector <User> users;

    User enterDataOfNewUser();
    int getIdofNewUser();
    bool doUserExist(string login);

public:
    void registerUser();
    void displayAllUsers();

};
