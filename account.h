#ifndef E_COMMERCE_SYSTEM_ACCOUNT_H
#define E_COMMERCE_SYSTEM_ACCOUNT_H

#include <string>
using namespace std;

class account {
    string firstName, lastName, userName, email, password;
public:
    account(string , string , string , string , string);
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
};


#endif //E_COMMERCE_SYSTEM_ACCOUNT_H
