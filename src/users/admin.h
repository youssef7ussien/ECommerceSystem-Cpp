#pragma once
#include "sellers.h"
#include "../data/products.h"
#include "account.h"

class Admin : public Account
{
private:

	Sellers *sellers;
	Products products;

public:

	Admin(std::string firstName,std::string lastName,std::string username,std::string email,
		std::string password,Sellers *sellers, Products *products)
		: Account( firstName, lastName, username, email, password)
	{
		this->sellers=sellers;
		this->products=*products;
	}

	int numberProducts() const
	{
		return products.productsLength();
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
		return products;
	}

	Queue<Seller> getRequests() const
	{
        return sellers->getRequests();
	}

	Product getProductAt(int index) const
	{
		return products.getProductConst(index);
	}

	Product getProduct(int id) const
	{
		return products.getProductConstId(id);
	}

	Seller getSellerConst(int index) const
	{
		return sellers->getSellerConst(index);
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
		sellers->removeReqeust();
	}

	void removeSeller(std::string name)
	{
		sellers->deleteSeller(name);
	}

	void removeSeller(int index)
	{
		sellers->deleteSellerAt(index);
	}

	void deleteProduct(int id)
	{
		products.deleteProduct(id);
	}

	void deleteProductAt(int index)
	{
		products.deleteProductAt(index);
	}
};
