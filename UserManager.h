#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include<windows.h>
#include<fstream>
#include<sstream>

#include "User.h"
#include "FileManager.h"

using namespace std;

class UserManager
{
    int idOfLoggedUser;

    vector <User> users;

    User enterDataOfNewUser();
    int getIdOfNewUser();
    bool doUserExist(string login);
    FileManager textFile;

public:
    void registerUser();
    void displayAllUsers();
    void getUsersFromFile();
};

#endif
