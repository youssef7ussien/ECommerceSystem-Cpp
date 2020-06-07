#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include <vector>
#include "Graphics.h"
#include"../users/customer.h"
#include"../users/seller.h"

enum User {ADMIN,SELLER,CUSTOMER};

// Login and Register
int interfaceLoginAs();
bool interfaceLogin();
bool interfaceRegister();
// Admin
void interfaceAdmin();
// Seller
void interfaceSeller(Seller &);
// Customer
void interfaceCustomer(const Customer &);

//void interfaceCart();
//void interfaceSearch();
bool interfaceExitGame(int x,int y);

#endif // INTERFACES_H_INCLUDED
