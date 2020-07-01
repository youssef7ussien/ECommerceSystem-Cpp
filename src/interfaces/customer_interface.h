#ifndef CUSTOMER_INTERFACE_H_INCLUDED
#define CUSTOMER_INTERFACE_H_INCLUDED

#include"../users/customer.h"
#include"../data/products.h"

/**
 *     firstPageOfCustomer() : This function returns seven possibilities
 *         1- return -1 -> For back
 *         2- return -2 -> For search
 *         3- return -3 -> For Shopping Cart
 *         4- return -4 -> For show all Categories
 *         5- return -5 -> For show all Products
 *         5- return -6 -> For show shortcuts
 *         6- return value between 0 and (number of categories)
 *         7- return value between (number of categories) and ((number of categories) + 8)
 *                      8 ->  the first four products * 2
 *                              2 -> (more , buy)
 */
int firstPageOfCustomer(const Customer&,const Products &products);

/**
 *     showProducts() : This function returns two possibilities
 *     1- return -1 -> For back
 *     2- return value between 0 and (number of products)*2
 *                              2 -> (more , buy)
 *
 */
int showProducts(const string&,const List<Product> &,const string& titlePage="");

/**
 *     showCategories() : This function returns two possibilities
 *     1- return -1 -> For back
 *     2- return value between 0 and (number of categories)
 *
 */
int showCategories(const string&,const List<Category> &);

/**
 *     searchPage() : This function searches for products by returning
 *     a list of products that were found by reference
 *     and returns the name that was searched for.
 */
string searchPage(const string&,const List<Product> &,List<Product> &);


int showCart(const string&,Queue<Product>,PurchaseData &);

/**
 *     These functions for dialogs
 */
void noProductDialog();
string nameDialog();
void shortcutsCustomerDialog(const string&);
void buyDialog(const Customer &,const string&);
void cartFullDialog(const string&);
void outOfStockDialog(const string&);

#endif // CUSTOMER_INTERFACE_H_INCLUDED
