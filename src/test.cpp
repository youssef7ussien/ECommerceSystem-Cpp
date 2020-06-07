#include <iostream>
//#include"products.h"
#include"users/seller.h"
#include"users/customer.h"
//#include"categories.h"
#include "data/hash_table.cpp"

using namespace std;

int main()
{
    Products products;
    Seller seller;
    //Customer customer;
    int x=1;
    while(x!=0)
    {
        cin>>x;
        switch (x)
        {
            case 1:
            {
                seller.addProduct(Product("id 1","hgjhgj",100.5,"hgfghfg"));
                seller.addProduct(Product("ad 2","hgjhgj",5.5,"hgfghfg"));
                seller.addProduct(Product("ad 3","hgjhgj",5.5,"hgfghfg"));
                cout<<"seller.getLength : "<<seller.getProducts().getLength()<<endl;
                products=seller.getProducts();

            }break;
            case 2:
            {
                Customer customer("1-1","1-2","1-3","1-4","1-5",products);
                cout<<"customer.getLength : "<<customer.getProducts().getLength()<<"       ";
                cout<<"customer.getProduct(1)->getName(): "<<customer.getProduct(1)->getName()<<endl;
            }break;
        }
    }
    //system("pause");
    return 0;


}
