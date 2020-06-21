#ifndef SELLER_INTERFACE_H_INCLUDED
#define SELLER_INTERFACE_H_INCLUDED

#include "../users/seller.h"

/**
 *     firstPageOfSeller() : This function returns three possibilities
 *         1- return -1 -> For back
 *         2- return -2 -> For add Product
 *         3- return value between 0 and (number of product * 3)
 *                3 -> -> For operations on products : show , edit , delete
 */
int firstPageOfSeller(const Seller &,Product *[]);

bool interfaceAddProduct(Product &);
bool interfaceEditProduct(Product *);

#endif // SELLER_INTERFACE_H_INCLUDED
