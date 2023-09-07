#include "FileManager.h"

FileManager::FileManager()
{
    nameOfFileWithUsers = "Users.txt";
}

void FileManager::writeUserToFile(User user)
{

    string lineWithUserData = "";
    nameOfFileWithUsers = "Users.txt";
    textFile.open(nameOfFileWithUsers.c_str(), ios::app);

    if (textFile.good() == true)
    {
        lineWithUserData = changeFormatOfLineToFormatOfAddressBook(user);

        if (doFileIsEmpty() == true)
        {
            textFile << lineWithUserData;
        }
        else
        {
            textFile << endl << lineWithUserData ;
        }
    }
    else
        cout << "Nie udalo sie otworzyc pliku " << nameOfFileWithUsers << " i zapisac w nim danych." << endl;
    textFile.close();
}

bool FileManager::doFileIsEmpty()
{
    textFile.seekg(0, ios::end);
    if (textFile.tellg() == 0)
        return true;
    else
        return false;
}

string FileManager::changeFormatOfLineToFormatOfAddressBook(User user)
{
    string lineWithUserData = "";

    lineWithUserData += AdditionalMethods::convertIntToString(user.getId())+ '|';
    lineWithUserData += user.getLogin() + '|';
    lineWithUserData += user.getPassword() + '|';

    return lineWithUserData;
}
