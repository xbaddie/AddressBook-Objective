#include "AddressBook.h"

AddressBook::AddressBook()
{
    userManager.getUsersFromFile();
}

void AddressBook::displayAllUsers()
{
    userManager.displayAllUsers();
}

void AddressBook::registerUser()
{
    userManager.registerUser();
}

















