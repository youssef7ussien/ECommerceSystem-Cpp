#include <iostream>
#include "interfaces/interfaces.h"
#include "graphics.h"

using namespace std;


int main()
{
    initConsole();
    editCursor(false);

    Products products;
    products.initializingData();
    bool CreateSellers=true;
    Sellers sellers;

    while(1)
    {
        int index=interfaceLoginAs();
        if(index==0 || index==1)
        {
            if(CreateSellers)
            {
                sellers.initializingData();
                CreateSellers=false;
            }
            if(index==0)
            {
                Admin admin("Admin","Admin","admin","admin@commerce.com","admin",sellers,&products);
                if(interfaceLoginAdmin())
                    interfaceAdmin(admin);
            }
            else if(index==1)
            {
                int result=chooseMethod();
                if(result==0)
                {
                    int id;
                    if(interfaceLoginSeller(sellers,id))
                        interfaceSeller(*sellers.getSeller(id),products);
                }
                else if(result==1)
                {
                    Account account;
                    if(interfaceRegister(account))
                    {
                        sellers.addRequest(Seller(account.getFirstName(),account.getLastName()
                                                ,account.getUserName(),account.getEmail(),
                                                account.getPassword()));
                    }
                }
                else
                    continue;
            }
        }
        else if(index==2)
        {
            interfaceCustomer(products);
        }
        else if(index==3)
        {
            system("pause");
        }
        else if(index==4)
        {
            if(interfaceExitGame(44,8))
                return 0;
        }
    }
    return 0;
}
