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

vector <User> FileManager::getUsersFromFile()
{
    User user;
    vector <User> users;
    string dataOfSingleUserSeparatedWithVerticalLines = "";

    textFile.open(nameOfFileWithUsers.c_str(), ios::in);

    if (textFile.good() == true)
    {
        while (getline(textFile, dataOfSingleUserSeparatedWithVerticalLines))
        {
            user = getUserData(dataOfSingleUserSeparatedWithVerticalLines);
            users.push_back(user);
        }

    }
    textFile.close();
    return users;
}

User FileManager::getUserData(string dataOfSingleUserSeparatedWithVerticalLines)
{
    User user;
    string singleUserData = "";
    int countOfSingleUserData = 1;

    for (int characterPlace = 0; characterPlace < dataOfSingleUserSeparatedWithVerticalLines.length(); characterPlace++)
    {
        if (dataOfSingleUserSeparatedWithVerticalLines[characterPlace] != '|')
        {
            singleUserData += dataOfSingleUserSeparatedWithVerticalLines[characterPlace];
        }
        else
        {
            switch(countOfSingleUserData)
            {
            case 1:
                user.setId(atoi(singleUserData.c_str()));
                break;
            case 2:
                user.setLogin(singleUserData);
                break;
            case 3:
                user.setPassword(singleUserData);
                break;
            }
            singleUserData = "";
            countOfSingleUserData++;
        }
    }
    return user;
}
