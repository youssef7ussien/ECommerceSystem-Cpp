#ifndef CUSTOMER_INTERFACE_H_INCLUDED
#define CUSTOMER_INTERFACE_H_INCLUDED

#include"../users/customer.h"
#include"../data/products.h"
#include"../data/linked_list.h"
#include"../data/queue.h"

/*
 *     firstPageOfSeller() : This function returns seven possibilities
 *         1- return -1 -> For back
 *         2- return -2 -> For search
 *         3- return -3 -> For Shopping Cart
 *         4- return -4 -> For show all Categories
 *         5- return -5 -> For show all Products
 *         6- return value between 0 and (number of categories)
 *         7- return value between (number of categories) and (number of products)
 */
int firstPageOfCustomer(const Customer&,const Products &products);

/*
 *     showProducts() : This function returns two possibilities
 *     1- return -1 -> For back
 *     2- return value between 0 and (number of products)
 *
 */
int showProducts(std::string,const List<Product> &,std::string categoryName="");

/*
 *     showCategories() : This function returns two possibilities
 *     1- return -1 -> For back
 *     2- return value between 0 and (number of categories)
 *
 */
int showCategories(std::string,const List<Category> &);

void searchPage(const List<Product> &);

int showCart(Customer &,Queue<Product> *);

// return name
string nameDialog();

void buyDialog(const Customer &,std::string);



#endif // CUSTOMER_INTERFACE_H_INCLUDED
