#include "interfaces/interfaces.h"
#include "interfaces/graphics.h"

int main()
{
    initConsole();

    Products products;
    products.initializingData();

    bool CreateSellers=false;
    Sellers sellers;

    while(true)
    {
        int index=interfaceLoginAs();
        if(index==0 || index==1)
        {
            if(!CreateSellers)
            {
                sellers.initializingData();
                CreateSellers=true;
            }
            if(index==0)
            {
                Admin admin("Admin","Admin","admin","admin@commerce.com","admin",sellers,products);
                if(interfaceLoginAdmin())
                    interfaceAdmin(admin);
            }
            else
            {
                int result=chooseMethodLogin();
                if (result==0)
                {
                    int id;
                    if (interfaceLoginSeller(sellers, id))
                        interfaceSeller(*sellers.getSeller(id), products);
                }
                else if (result==1)
                {
                    Account account;
                    if (interfaceRegister(account))
                    {
                        sellers.addRequest(Seller(account.getFirstName(), account.getLastName(),
                                                  account.getUserName(),account.getEmail(),
                                                  account.getPassword()));
                    }
                }
            }
        }
        else if(index==2)
        {
            interfaceCustomer(products);
        }
        else if(index==3)
            aboutDialog();
        else if(index==4)
        {
            if(interfaceExitGame(44,8))
            {
                products.saveData();
                if(CreateSellers)
                    sellers.saveData();
                return 0;
            }
        }
    }
    return 0;
}
