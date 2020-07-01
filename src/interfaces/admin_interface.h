#ifndef ADMIN_INTERFACE_H_INCLUDED
#define ADMIN_INTERFACE_H_INCLUDED

#include"../users/admin.h"

/**
 *     firstPageOfAdmin() : This function is the home page of the admin,
 *      in which the sellers and new registration requests are presented.
 *      This function returns four possibilities :
 *         1- return -1 -> For back
 *         2- return -2 -> For show shortcuts dialog
 *         3- return -3 -> For show profile
 *         3- return -4 -> For confirm request seller
 *         3- return -5 -> For reject request seller
 *         4- return value between 0 and (number of sellers)*2
 *                2 -> number of buttons in per seller(show, delete)
 */
int firstPageOfAdmin(const Admin &);

/**
 *     sellerPage() : This job is the seller's page and it shows his products
 *      and some of his main data. This function three four possibilities
 *         1- return -1 -> For back
 *         2- return value between 0 and (The number of his products) , this value is the ID of the product
 */
int sellerPage(const Seller &,const Products &);

void shortcutsAdminDialog(const string &);


#endif // ADMIN_INTERFACE_H_INCLUDED
