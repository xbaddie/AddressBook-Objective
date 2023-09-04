#include <iostream>

#include "AddressBook.h"
using namespace std;

int main()
{
    AddressBook addressBook;
    addressBook.registerUser();
    addressBook.displayAllUsers();

    return 0;
}
