#include "account.h"
#include <string>
using namespace std;

account::account(string firstName, string lastName, string userName, string email, string password)
: firstName(firstName),lastName(lastName),userName(userName),email(email),password(password) {}

string account::getFirstName() const
{
    return firstName;
}

void account::setFirstName(string firstName)
{
    this->firstName=firstName;
}

string account::getLastName() const
{
    return lastName;
}

void account::setLastName(string lastName)
{
    this->lastName=lastName;
}

string account::getUserName() const
{
    return userName;
}

void account::setUserName(string userName)
{
    this->userName=userName;
}

string account::getEmail() const
{
    return email;
}

void account::setEmail(string email)
{
   this->email=email;
}

string account::getPassword() const
{
    return password;
}

void account::setPassword(string password)
{
    this->password=password;
}
