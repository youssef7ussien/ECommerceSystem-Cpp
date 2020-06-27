#ifndef UNTITLED1_ACCOUNT_H
#define UNTITLED1_ACCOUNT_H

#include <iostream>
using namespace std;

class Account {
protected:
    string firstName,lastName,userName,email,password;
public:
    Account();
    Account(const string &firstName, const string &lastName, const string &userName, const string &email,
            const string &password);
//    Account(const Account &);
    string getName() const;
    string getFirstName() const;
    void setFirstName(string);
    string getLastName() const;
    void setLastName(string);
    string getUserName() const;
    void setUserName(string);
    string getEmail() const;
    void setEmail(string);
    string getPassword() const;
    void setPassword(string);
    Account *getAccount();
//    bool validationEmail() const;
//    bool validationName() const;
//    bool validationUsername() const;
//    bool validationPassword() const;
//    bool confirmPassword(string) const;

};

#endif //UNTITLED1_ACCOUNT_H
