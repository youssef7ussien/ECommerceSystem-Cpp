#include <iostream>
#include "interfaces/interfaces.h"

using namespace std;


int main()
{
    initConsole();
//    editCursor(false);

    Products products;
    Sellers sellers;

    while(1)
    {
        int index=interfaceLoginAs();
        if(index==0 || index==1)
        {
            switch(index)
            {
                case 0: interfaceLogin(); break;
                case 1:
                {
                    int id;
                    if(!interfaceLoginSeller(sellers,id))
                        break;
                    interfaceSeller(sellers.getSeller(id),products);
                } break;
            }
        }
        else if (index==2)
        {
            interfaceCustomer(products);
        }
        else if (index==3)
            interfaceRegister();
        else if (index==4)
        {
            if(interfaceExitGame(44,8))
                return 0;
        }
    }
    setCursor(0,32);
    //system("pause");
    return 0;
}
