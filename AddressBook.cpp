#include "AddressBook.h"

AddressBook::AddressBook()
{
    nameOfFileWithUsers = "Users.txt";
}

void AddressBook::registerUser()
{
    User user = enterDataOfNewUser();

    users.push_back(user);
    writeUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

User AddressBook::enterDataOfNewUser()
{
    User user;

    user.setId(getIdOfNewUser());

    string login;
    do
    {
        cout << "Podaj login: ";
        cin >> login;
        user.setLogin(login);
    } while (doUserExist(user.getLogin()) == true);

    string password;
    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password);

    return user;
}

int AddressBook::getIdOfNewUser()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool AddressBook::doUserExist(string login)
{
    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
        else
            itr++;
    }
    return false;
}

void AddressBook::displayAllUsers()
{
    for(int i = 0; i < users.size(); i++)
    {
        cout << users[i].getId() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;


    }
}

void AddressBook::writeUserToFile(User user)
{
    fstream textFile;
    string lineWithUserData = "";
    textFile.open(nameOfFileWithUsers.c_str(), ios::app);

    if (textFile.good() == true)
    {
        lineWithUserData = changeFormatOfLineToFormatOdAddressBook(user);

        if (doFileIsEmpty(textFile) == true)
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

string AddressBook::changeFormatOfLineToFormatOdAddressBook(User user)
{
    string lineWithUserData = "";

    lineWithUserData += convertIntToString(user.getId())+ '|';
    lineWithUserData += user.getLogin() + '|';
    lineWithUserData += user.getPassword() + '|';

    return lineWithUserData;
}

string AddressBook::convertIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

bool AddressBook::doFileIsEmpty(fstream &textFile)
{
    textFile.seekg(0, ios::end);
    if (textFile.tellg() == 0)
        return true;
    else
        return false;
}
