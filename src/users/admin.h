#pragma once
#include "sellers.h"
#include "../data/products.h"
#include "account.h"

class Admin : public Account
{
private:

	Sellers *sellers;
	Products *products;

public:

	Admin(string firstName,string lastName,string username,string email,
		  string password,Sellers &sellers, Products &products)
		: Account( firstName, lastName, username, email, password)
	{
		this->sellers=&sellers;
		this->products=&products;
	}

	int numberProducts() const
	{
		return products->productsLength();
	}

	int numberSellers() const
	{
		return sellers->getLength();
	}

	int numberRequests() const
	{
		return sellers->requestLength();
	}

	Products getProducts() const
	{
		return *products;
	}

	Queue<Seller> getRequests() const
	{
        return sellers->getRequests();
	}

	Product getProductAt(int index) const
	{
		return products->getCopyProductAt(index);
	}

	Product getProduct(int id) const
	{
		return products->getCopyProduct(id);
	}

	Seller getCopySellerAt(int index) const
	{
		return sellers->getCopySellerAt(index);
	}

	Seller* getSellerAt(int index)
	{
		return sellers->getSellerAt(index);
	}

	void confirmAddSeller()
	{
		sellers->addSeller();
	}

	void rejectAddSeller()
	{
        sellers->removeRequest();
	}

	void deleteSeller(int index)
	{
		Seller seller;
		sellers->deleteSellerAt(index,seller);
		while(seller.numberProducts())
			products->deleteProduct(seller.deleteProductIdAt(0));
	}

	void deleteProduct(int id)
	{
		products->deleteProduct(id);
	}
};
