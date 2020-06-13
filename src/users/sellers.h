#pragma once
#include "../data/linked_list.h"
#include "../data/queue.h"
#include "seller.h"

class Sellers
{
    List<Seller> sellers;
    Queue<Seller> waitingList;
public:
       Sellers()
       {
            Seller seller1("seller 1","seller","seller01","seller01","01");
            seller1.addProduct(0);
            seller1.addProduct(3);
            seller1.addProduct(4);
            seller1.addProduct(6);
            seller1.addProduct(9);
            addRequest(seller1);

            Seller seller2("seller 2","seller","seller02","seller02","02");
            seller2.addProduct(1);
            seller2.addProduct(5);
            seller2.addProduct(8);
            seller2.addProduct(10);
            seller2.addProduct(11);
            addRequest(seller2);

            Seller seller3("seller 3","seller","seller03","seller03","03");
            seller3.addProduct(2);
            seller3.addProduct(8);
            seller3.addProduct(12);
            seller3.addProduct(13);
            addRequest(seller3);

            addSeller();
            addSeller();
            addSeller();
       }

       int getLength() const
       {
           return sellers.getLength();
       }

       int requestLength() const
       {
           return waitingList.getLength();
       }

       Seller* getSeller(int id)
       {
           return sellers.getItem(id);
       }

       Seller firstRequest() const
       {
           return waitingList.getFront();
       }

       void addSeller()
       {

           sellers.insertLast(waitingList.dequeue());
       }

       void addRequest(Seller seller)
       {
           waitingList.enqueue(seller);
       }

       void deleteSeller(string username)
       {
           sellers.remove<string>(username);
       }

       void deleteSellerAt(int index)
       {
           sellers.removeAt(index);
       }

       bool checkSeller(string email,string password,int &id) const
       {
           for(int i=0;i<sellers.getLength() ; i++)
           {
               Seller seller=sellers.getCopyItem(i);
               if(seller.getEmail()==email && seller.getPassword()==password)
                    {
                        id=seller.getId();
                        return true;
                    }
           }
           return false;
       }
};
