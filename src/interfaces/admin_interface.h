#ifndef ADMIN_INTERFACE_H_INCLUDED
#define ADMIN_INTERFACE_H_INCLUDED

#include"../users/admin.h"
#include"../users/seller.h"
#include"../data/products.h"

/**
 *     firstPageOfAdmin() : This function returns four possibilities
 *         1- return -1 -> For back
 *         2- return -2 -> For confirm request seller
 *         3- return -3 -> For reject request seller
 *         4- return value between 0 and (number of sellers)*2
 *                2 -> number of buttons in per seller
 */
int firstPageOfAdmin(const Admin &);

/**
 *     sellerPage() : This function three four possibilities
 *         1- return -1 -> For back
 *         2- return -2 -> For delete seller
 *         3- return value between 0 and (number of products)
 */
int sellerPage(const Seller &,const Products &);


#endif // ADMIN_INTERFACE_H_INCLUDED
