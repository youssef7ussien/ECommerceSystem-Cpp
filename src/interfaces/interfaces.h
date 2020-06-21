#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "graphics.h"
#include"../users/customer.h"
#include"../users/sellers.h"
#include"../users/admin.h"
#include "../data/products.h"
#include "../users/account.h"

enum User {ADMIN,SELLER,CUSTOMER};

/**
 * interfaceLoginAs() : This function is the system interface through which users enter,
 *   and it returns four possibilities :
 *         1- return 0 -> For Admin login
 *         2- return 1 -> For Seller login
 *         3- return 2 -> For Customer login
 *         4- return 3 -> For Exit
 */
int interfaceLoginAs();


bool interfaceLogin();

/**
 * interfaceLoginSeller() : This function checks the seller's account,
 *   and returns the identification number via the reference &,
 *   and it is correct if it is present and wrong if not.
 */
bool interfaceLoginSeller(const Sellers ,int &);

/**
 * interfaceRegister() :
 *
 *
 */
bool interfaceRegister(Account &);

/**
 * interfaceRegister() :
 *
 *
 */
void interfaceAdmin(Admin &);

// Seller
void interfaceSeller(Seller *,Products &);

// Customer
void interfaceCustomer(const Products &);


bool interfaceExitGame(int x,int y);


void notCompleted();  // For Test


#endif // INTERFACES_H_INCLUDED
