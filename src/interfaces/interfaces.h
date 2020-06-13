#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include <vector>
#include "graphics.h"
#include"../users/customer.h"
#include"../users/seller.h"
#include"../users/sellers.h"
#include "../data/products.h"

enum User {ADMIN,SELLER,CUSTOMER};

// Login and Register
int interfaceLoginAs();
bool interfaceLogin();
bool interfaceLoginSeller(const Sellers ,int &);
bool interfaceRegister();
// Admin
void interfaceAdmin();
// Seller
void interfaceSeller(Seller *,Products &);
// Customer
void interfaceCustomer(const Products &);

//void interfaceCart();
//void interfaceSearch();
bool interfaceExitGame(int x,int y);

#endif // INTERFACES_H_INCLUDED
