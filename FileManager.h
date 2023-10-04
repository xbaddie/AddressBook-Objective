#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "User.h"
#include "AdditionalMethods.h"

using namespace std;

class FileManager
{

    string nameOfFileWithUsers;
    fstream textFile;
    bool doFileIsEmpty();
    string changeFormatOfLineToFormatOfAddressBook(User user);
    User getUserData(string dataOfSingleUserSeparatedWithVerticalLines);

public:
    FileManager();
    void writeUserToFile(User user);
    vector <User> getUsersFromFile();

};

#endif
