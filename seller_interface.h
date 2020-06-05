#ifndef SELLER_INTERFACE_H_INCLUDED
#define SELLER_INTERFACE_H_INCLUDED

#include "seller.h"

int firstPageOfSeller(const Seller &);
bool interfaceAddProduct();
bool interfaceEditProduct(Product *);

#endif // SELLER_INTERFACE_H_INCLUDED
