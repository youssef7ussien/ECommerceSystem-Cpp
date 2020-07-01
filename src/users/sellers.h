#pragma once
#include "../data/queue.h"
#include "seller.h"

class Sellers {

    List<Seller> sellers;
    Queue<Seller> waitingList;

    void addSeller(Seller);

public:

    Sellers();
    int getLength() const;
    int requestLength() const;
    Queue<Seller> getRequests() const;
    Seller* getSeller(int);
    Seller* getSellerAt(int);
    Seller getCopySellerAt(int) const;
    Seller firstRequest() const;
    void addSeller();
    void addRequest(const Seller &);
    void removeRequest();
    void deleteSellerAt(int);
    void deleteSellerAt(int,Seller&);
    bool checkSeller(const string&, const string&, int &) const;

    void defaultData();  // For Test
    bool initializingData();
    bool saveData();
};
