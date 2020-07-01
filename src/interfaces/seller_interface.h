#ifndef SELLER_INTERFACE_H_INCLUDED
#define SELLER_INTERFACE_H_INCLUDED

#include "../users/seller.h"

/**
 *     firstPageOfSeller() : This function displays the seller's homepage,
 *      and displays its main data and products.
 *      This function returns six possibilities
 *         1- return -1 -> For back
 *         3- return -2 -> For show shortcuts dialog
 *         4- return -3 -> For Profile
 *         5- return -4 -> For add Product
 *         6- return value between 0 and (number of product * 3)
 *                3 -> For operations on products : show , edit , delete
 */
int firstPageOfSeller(const Seller &,Product *[]);

/**
 *     interfaceAddProduct() : This is the input interface for the product data,
 *         and returns the data entered by the reference.
 */
bool interfaceAddProduct(const string &,Product &);

/**
 *     interfaceEditProduct() : This is the product data editing interface,
 *          and returns data modified by reference
 */
bool interfaceEditProduct(const string &,Product &);

/**
 *     These functions for dialogs
 */
void shortcutsSellerDialog(const string &);
void registerDoneDialog();

#endif // SELLER_INTERFACE_H_INCLUDED
