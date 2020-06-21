#pragma once
#include "../data/queue.h"
#include "seller.h"

class Sellers {
    List<Seller> sellers;
    Queue<Seller> waitingList;
public:
    Sellers()
    {}

    void initializingData()
    {
       Seller seller1("Youssef","Hussien","seller01","seller01","01");
        seller1.addProduct(0);
        seller1.addProduct(3);
        seller1.addProduct(4);
        seller1.addProduct(6);
        seller1.addProduct(9);
        seller1.addProduct(16);
        seller1.addProduct(18);
        seller1.addProduct(19);
        seller1.addProduct(20);
        addRequest(seller1);
        addSeller();

        Seller seller2("Hossam","Mahmoud","seller02","seller02","02");
        seller2.addProduct(1);
        seller2.addProduct(5);
        seller2.addProduct(10);
        seller2.addProduct(11);
        seller2.addProduct(14);
        seller2.addProduct(17);
        addRequest(seller2);
        addSeller();

        Seller seller3("Abdelrahman","Salem","seller03","seller03","03");
        seller3.addProduct(2);
        seller3.addProduct(7);
        seller3.addProduct(8);
        seller3.addProduct(12);
        seller3.addProduct(13);
        seller3.addProduct(15);
        addRequest(seller3);
        addSeller();

        Seller seller4("Ahmed","Nady","seller04","youssefhussien123456789@commerce.com","04");
        addRequest(seller4);
        Seller seller5("Mahmoud","Soliman","seller05","seller05@commerce.com","05");
        addRequest(seller5);
        Seller seller6("Ahmed","Nady","seller06","seller06@commerce.com","06");
        addRequest(seller6);
        Seller seller7("Mahmoud","Soliman","seller07","seller07@commerce.com","07");
        addRequest(seller7);
        addRequest(seller3);
        addRequest(seller4);
        addRequest(seller6);
        addRequest(seller1);
        addRequest(seller5);
    }

    int getLength() const
    {
       return sellers.getLength();
    }

    int requestLength() const
    {
       return waitingList.getLength();
    }

    Queue<Seller> getRequests() const
    {
        return waitingList;
    }

    Seller *getSeller(int id)
    {
        return sellers.getItem(id);
    }

    Seller *getSellerAt(int index)
    {
        return sellers[index];
    }

    Seller getSellerConst(int index) const
    {
       return sellers.getCopyItem(index);
    }

    Seller firstRequest() const
    {
       return waitingList.getFront();
    }

    void addSeller()
    {

       sellers.insertLast(waitingList.dequeue());
    }

    void addRequest(const Seller &seller)
    {
       waitingList.enqueue(seller);
    }

    void removeReqeust()
    {
       waitingList.dequeue();
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
