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
        seller1.addProductId(0);
        seller1.addProductId(3);
        seller1.addProductId(4);
        seller1.addProductId(6);
        seller1.addProductId(9);
        seller1.addProductId(16);
        seller1.addProductId(18);
        seller1.addProductId(19);
        seller1.addProductId(20);
        addRequest(seller1);
        addSeller();

        Seller seller2("Hossam","Mahmoud","seller02","seller02","02");
        seller2.addProductId(1);
        seller2.addProductId(5);
        seller2.addProductId(10);
        seller2.addProductId(11);
        seller2.addProductId(14);
        seller2.addProductId(17);
        addRequest(seller2);
        addSeller();

        Seller seller3("Abdelrahman","Salem","seller03","seller03","03");
        seller3.addProductId(2);
        seller3.addProductId(7);
        seller3.addProductId(8);
        seller3.addProductId(12);
        seller3.addProductId(13);
        seller3.addProductId(15);
        addRequest(seller3);
        addSeller();

        Seller seller4("Ahmed","Nady","seller04","seller04@commerce.com","04");
        addRequest(seller4);
        addSeller();
        Seller seller5("Mahmoud","Soliman","seller05","seller05@commerce.com","05");
        addRequest(seller5);
//        Seller seller7("Mahmoud","Soliman","seller07","seller07@commerce.com","07");
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

    Seller* getSeller(int id)
    {
        return sellers.getItem(id);
    }

    Seller* getSellerAt(int index)
    {
        return sellers[index];
    }

    Seller getSellerConst(int index) const
    {
       return sellers.getCopyItemAt(index);
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

//    void deleteSeller(string username)
//    {
//       sellers.remove<string>(username);
//    }

    void deleteSellerAt(int index)
    {
       sellers.removeAt(index);
    }

    bool checkSeller(string email,string password,int &id) const
    {
        Seller seller;
        if(sellers.contain<string>(email,seller))
        {
            if(seller.getEmail()==email && seller.getPassword()==password)
            {
                id=seller.getId();
                return true;
            }
        }
        return false;
    }
};
