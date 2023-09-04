#include <iostream>
#include <vector>

#include "User.h"

using namespace std;

class AddressBook
{
    int idOfLoggedUser;
    int idOfLastUser;
    int idOfDeletedUser;

    vector <User> Users;

public:
    void registerUser();

};
