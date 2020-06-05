#include "account.h"
#include <regex>

Account::Account(const string &firstName, const string &lastName, const string &userName, const string &email,
                 const string &password) : firstName(firstName), lastName(lastName), userName(userName), email(email),
                                           password(password) {}

Account::Account() : firstName(""), lastName(""), userName(""), email(""), password("")
{}

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

bool Account::validationName()
{
    regex pattern("^([A-Z ._a-z0-9]){4,20}$");

    return regex_match(getFirstName(), pattern) && regex_match(getLastName(), pattern);
}

bool Account::validationEmail()
{
    regex pattern("^[\\w\\._]+@[\\w\\._]+\\.\\w{2,4}$");

    return regex_match(getEmail(), pattern);
}

bool Account::validationUsername()
{
    regex pattern("^([A-Z._a-z0-9]){4,20}$");

    return regex_match(getUserName(), pattern);
}

bool Account::validationPassword()
{
    regex pattern("^([A-Z.@_a-z0-9]){8,20}$");

    return regex_match(getPassword(), pattern);
}

bool Account::confirmPassword(string password)
{
    return getPassword()==password;
}

