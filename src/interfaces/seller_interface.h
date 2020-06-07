#ifndef SELLER_INTERFACE_H_INCLUDED
#define SELLER_INTERFACE_H_INCLUDED

#include "../users/seller.h"

int firstPageOfSeller(const Seller &);
bool interfaceAddProduct(Product &);
bool interfaceEditProduct(Product *);

#endif // SELLER_INTERFACE_H_INCLUDED
