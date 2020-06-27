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

//bool Account::validationName() const
//{
//    regex pattern("^[a-zA-z0-9 \\-]{3,15}$");
//
//    return regex_match(getFirstName(), pattern) && regex_match(getLastName(), pattern);
//}
//
//bool Account::validationEmail() const
//{
//    regex pattern("^[\\w\\._]{3,21}@[\\w\\._]{2,11}\\.\\w{2,4}$");
//
//    return regex_match(getEmail(), pattern);
//}
//
//bool Account::validationUsername() const
//{
//    regex pattern("^([A-Z._a-z0-9]){3,30}$");
//
//    return regex_match(getUserName(), pattern);
//}
//
//bool Account::validationPassword() const
//{
//    regex pattern("^([A-Z._a-z0-9]){8,30}$");
//
//    return regex_match(getPassword(), pattern);
//}
//
//bool Account::confirmPassword(string password) const
//{
//    return getPassword()==password;
//}

