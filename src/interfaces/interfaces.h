#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include"../users/customer.h"
#include"../users/admin.h"

enum User {ADMIN,SELLER,CUSTOMER};

void aboutDialog();

/**
 * interfaceLoginAs() : This function is the system interface through which users enter,
 *   and it returns four possibilities :
 *         1- return 0 -> For Admin login
 *         2- return 1 -> For Seller login
 *         3- return 2 -> For Customer login
 *         4- return 3 -> For Exit
 */
int interfaceLoginAs();

/**
 * chooseMethodLogin() : This function offers the user to choose if he wants
 *   to log in with the account or create a new account.
 */
int chooseMethodLogin();

/**
 * interfaceLoginAdmin() : This function checks the admin's account,
 *   and return true or false.
 */
bool interfaceLoginAdmin();

/**
 * interfaceLoginSeller() : This function checks the seller's account,
 *   and returns the id number via the reference &,
 *   and it is correct if it is present and wrong if not.
 */
bool interfaceLoginSeller(const Sellers &,int &);

/**
 * interfaceRegister() : This is the function that creates an account for the seller,
 *   and returns the new account data by reference & ,
 *   and returns true if it was created and false if not.
 */
bool interfaceRegister(Account &);

/**
 * interfaceAdmin() : This function in which the operations of the administrator occur,
 *   from offering sellers and deleting them,
 *   as well as displaying products with the ability to delete them
 *   and also displays new registration requests.
 */
void interfaceAdmin(Admin &);

/**
 * interfaceSeller() : This function in which seller operations occur,
 *   from displaying his data with the ability to modify it,
 *   in addition to displaying his products with the ability to delete or modify them.
 */
void interfaceSeller(Seller &,Products &);

/**
 * interfaceCustomer() : This function in which the customer’s operations occur,
 *   from displaying the products available in the program with the ability to purchase them,
 *   in addition to the ability to search and print the purchase invoice.
 */
void interfaceCustomer(Products &);


bool interfaceExitGame(int x,int y);

#endif // INTERFACES_H_INCLUDED
