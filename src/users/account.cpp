#include "account.h"
#include <regex>

Account::Account() : firstName(""), lastName(""), userName(""), email(""), password("")
{}

Account::Account(const string &firstName, const string &lastName, const string &userName, const string &email,
                 const string &password)
{
    this->firstName=firstName;
    this->lastName=lastName;
    this->userName=userName;
    this->email=email;
    this->password=password;
}

//Account::Account(const Account &account)
//{
//    this->firstName= account.getFirstName();
//    this->lastName= account.getFirstName();
//    this->userName= account.getUserName();
//    this->email= account.getEmail();
//    this->password= account.getPassword();
//}



string Account::getName() const
{
    return firstName+" "+lastName;
}

string Account::getFirstName() const
{
    return firstName;
}

void Account::setFirstName(string firstName)
{
    this->firstName=firstName;
}

string Account::getLastName() const
{
    return lastName;
}

void Account::setLastName(string lastName)
{
    this->lastName = lastName;
}

string Account::getUserName() const
{
    return userName;
}

void Account::setUserName(string userName)
{
    this->userName=userName;
}

string Account::getEmail() const
{
    return email;
}

void Account::setEmail(string email)
{
    this->email=email;
}

string Account::getPassword() const
{
    return password;
}

void Account::setPassword(string password)
{
    this->password=password;
}

Account *Account::getAccount()
{
 return this;
}

