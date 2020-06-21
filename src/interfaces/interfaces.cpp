#include <iostream>
#include <conio.h>
#include <regex>
#include "interfaces.h"
#include "seller_interface.h"
#include "admin_interface.h"
#include "customer_interface.h"

using namespace std;

void notCompleted() // For Test
{
    system("cls");
    color(RED); drawRectangle(55,10,21,3); color();
    setCursor(57,12); cout<<" not completed yet ";
    _getch();
}

int interfaceLoginAs()
{
    system("cls");
    char key=80;  int index=0;

    drawRectangle(50,1,30,1,2); // login as box
    setCursor(62,2); cout<<"Login as";
    drawRectangle(55,4,20,1); // Admin box
    drawRectangle(55,7,20,1); // Seller box
    drawRectangle(55,10,20,1); // Customer box
    drawRectangle(55,13,20,1); // Register box
    drawLine(50,16,82,16);
    drawRectangle(67,17,14,1); // Exit box

    while(key!=13)
    {
        if(index==0)  color(BLACK,RED);
        setCursor(57,5); cout<<"      Admin       "; color();

        if(index==1)  color(BLACK,RED);
        setCursor(57,8); cout<<"      Seller      "; color();

        if(index==2)  color(BLACK,RED);
        setCursor(57,11); cout<<"     Customer     "; color();

        if(index==3)  color(BLACK,RED);
        setCursor(57,14); cout<<"     Register     "; color();

        setCursor(69,18);
        if(index==4)  color(BLACK,RED);
        cout<<"    EXIT    "; color();
        setCursor(0,28);
        while(1)
        {
            key=_getch();
            if(key==KEY_DOWN)
                { index=(index+1)%5; break; }
            else if(key==KEY_UP)
                { index=(index+4)%5; break; }
            else if(key==KEY_ENTER)
                return index;
            else if(key==KEY_ESC)
                    return 4;
        }
    }
    return index;
}

inline string inputText()
{
    editCursor(true);
    string text="";
    char character=getchar();
    while(1)
    {
        if(character=='\n')
        {
            editCursor(false);
            return text;
        }
        text+=character;
        character=getchar();
    }
}

inline void initialBox(int x,int y,int width,int lengthLine)
{
    setCursor(x+2,y+1);
    clearLine(lengthLine);
    color(RED); drawRectangle(x,y,width,1); color();
    setCursor(x+2,y+1);
}

bool interfaceLogin()
{
    system("cls");
    char key='0';  int index=2;
    string username="",password="";
    drawRectangle(50,1,30,1,2); // login box
    setCursor(62,2); cout<<"Login";
    drawRectangle(45,6,40,1); // email box
    setCursor(46,5); cout<<"Enter email";
    drawRectangle(45,10,40,1); // password box
    setCursor(46,9); cout<<"Enter password";
    drawRectangle(50,14,14,1); // Again box
    drawRectangle(66,14,14,1); // Exit box

    while(key!=KEY_ENTER)
    {
        setCursor(52,15);
        if(index==0)  color(BLACK,RED);
        cout<<"   AGAIN    "; color();

        setCursor(68,15);
        if(index==1)  color(BLACK,RED);
        cout<<"    BACK    "; color();

        if(index==2)
        {
            initialBox(45,6,40,username.size());
            username="";
            username=inputText();
            drawRectangle(45,6,40,1);

            initialBox(45,10,40,password.size());
            password="";
            password=inputText();

            if(username=="admin" && password=="admin")
                return true;
            setCursor(44,13); color(DARK_RED);
            cout<<"Incorrect email or password please try again";
            color();
            drawRectangle(45,10,40,1);
            index=0;
            continue;
        }

        while(1)
        {
            key=_getch();
            if(key==KEY_RIGHT)
                { index=(index+1)%2; break; }
            else if(key==KEY_LEFT)
                { index=(index+3)%2; break; }
            else if(key==KEY_ENTER)
                break;
        }
        if(key==KEY_ENTER && index==0)
        {
            key='0'; index=2;
            setCursor(44,13); cout<<"                                            ";
        }
    }
    return false;
}

bool interfaceLoginSeller(const Sellers sellers,int &seller)
{
    system("cls");
    char key='0';  int index=2;
    string email="",password="";
    drawRectangle(50,1,30,1,2); // login box
    setCursor(62,2); cout<<"Login";
    drawRectangle(45,6,40,1); // email box
    setCursor(46,5); cout<<"Enter email";
    drawRectangle(45,10,40,1); // password box
    setCursor(46,9); cout<<"Enter password";
    drawRectangle(50,14,14,1); // Again box
    drawRectangle(66,14,14,1); // Exit box

    while(key!=KEY_ENTER)
    {
        setCursor(52,15);
        if(index==0)  color(BLACK,RED);
        cout<<"   AGAIN    "; color();

        setCursor(68,15);
        if(index==1)  color(BLACK,RED);
        cout<<"    BACK    "; color();

        if(index==2)
        {
            initialBox(45,6,40,email.size());
            email=inputText();
            drawRectangle(45,6,40,1);

            initialBox(45,10,40,password.size());
            password=inputText();

            if(sellers.checkSeller(email,password,seller))
                return true;
            setCursor(44,13); color(DARK_RED);
            cout<<"Incorrect email or password please try again";
            color();
            drawRectangle(45,10,40,1);
            index=0;
            continue;
        }

        while(1)
        {
            key=_getch();
            if(key==KEY_RIGHT)
                { index=(index+1)%2; break; }
            else if(key==KEY_LEFT)
                { index=(index+3)%2; break; }
            else if(key==KEY_ENTER)
                break;
        }
        if(key==KEY_ENTER && index==0)
        {
            key='0'; index=2;
            setCursor(44,13); cout<<"                                            ";
        }
    }
    return false;
}

bool interfaceRegister(Account &account)
{
    system("cls");
    char key='0';  int index=2;
    drawRectangle(50,1,30,1,2); // login box
    setCursor(64,2); cout<<"Register";
    drawRectangle(44,6,20,1); // firstName box
    setCursor(45,5); cout<<"First name";
    drawRectangle(66,6,20,1); // lastName box
    setCursor(67,5); cout<<"Last name";
    drawRectangle(44,10,42,1); // userName box
    setCursor(45,9); cout<<"username";
    drawRectangle(44,14,42,1); // email box
    setCursor(45,13); cout<<"Email";
    drawRectangle(44,18,42,1); // password box
    setCursor(45,17); cout<<"Password";
    drawRectangle(44,22,42,1); // confirm password box
    setCursor(45,21); cout<<"Confirm Password";
    drawRectangle(50,25,14,1); // Again box
    drawRectangle(66,25,14,1); // Exit box
    string confirmPassword="";
    while(key!=KEY_ENTER)
    {
        setCursor(52,26);
        if(index==0)  color(BLACK,RED);
        cout<<"   AGAIN    "; color();

        setCursor(68,26);
        if(index==1)  color(BLACK,RED);
        cout<<"    BACK    "; color();

        if(index==2)
        {
            initialBox(44,6,20,account.getFirstName().size());
            account.setFirstName(inputText());
            drawRectangle(44,6,20,1);

            initialBox(66,6,20,account.getLastName().size());
            account.setLastName(inputText());
            drawRectangle(66,6,20,1);

            initialBox(44,10,42,account.getUserName().size());
            account.setUserName(inputText());
            drawRectangle(44,10,42,1);

            initialBox(44,14,42,account.getEmail().size());
            account.setEmail(inputText());
            drawRectangle(44,14,42,1);

            initialBox(44,18,42,account.getPassword().size());
            account.setPassword(inputText());
            drawRectangle(44,18,42,1);

            initialBox(44,22,42,confirmPassword.size());
            confirmPassword=inputText();

            bool validation=true;
            if(!account.validationUsername())
            {
                validation=false;
                setCursor(89,11); color(DARK_RED);
                cout<<"Incorrect username";
            }
            if(!account.validationEmail())
            {
                validation=false;
                setCursor(89,15); color(DARK_RED);
                cout<<"Incorrect email";
            }
            if(!account.validationPassword())
            {
                validation=false;
                setCursor(89,19); color(DARK_RED);
                cout<<"Incorrect password";
            }
            if(!account.confirmPassword(confirmPassword))
            {
                validation=false;
                setCursor(89,23); color(DARK_RED);
                cout<<"Password does not match";
            }
            color();
            if(validation)
                return true;
            drawRectangle(44,22,42,1);
            index=0;
            continue;
        }
        while(1)
        {
            key=_getch();
            if(key==KEY_RIGHT)
                { index=(index+1)%2; break; }
            else if(key==KEY_LEFT)
                { index=(index+3)%2; break; }
            else if(key==KEY_ENTER)
                break;
        }
        if(key==KEY_ENTER && index==0)
        {
            key='0';
            index=2;
            setCursor(89,11); cout<<"                       ";
            setCursor(89,15); cout<<"                       ";
            setCursor(89,19); cout<<"                       ";
            setCursor(89,23); cout<<"                       ";
        }
    }
    return false;
}

bool interfaceExitGame(int x,int y)
{
    char key='0';  int index=0;
    drawRectangle(x,y,43,5); //35 11
    setCursor(x+1,y+1); color();
    cout<<"               Are You Sure ?              ";
    setCursor(x+1,y+2); clearLine(43);
    setCursor(x+1,y+3); clearLine(43);
    setCursor(x+1,y+4); clearLine(43);
    setCursor(x+1,y+5); clearLine(43);
    drawRectangle(x+2,y+3,11,1);
    drawRectangle(x+33,y+3,8,1);

    while(key!=KEY_ENTER)
    {
        setCursor(x+4,y+4); color();
        if(index==1)  color(BLACK,RED);
        cout<<"   YES   "; color();

        setCursor(x+35,y+4);
        if(index==0)  color(BLACK,RED);
        cout<<"  NO  "; color();
        setCursor(0,26);
        while(1)
        {
            key=_getch();
            if(key==KEY_RIGHT)
                { index=(index+1)%2; break; }
            else if(key==KEY_LEFT)
                { index=(index+3)%2; break; }
            else if(key==KEY_ENTER)
                break;
        }
    }
    return index==1 ? true : false;
}

void productDetails(int x,int y,const Product product,User user=CUSTOMER)
{
    system("cls");
    drawRectangle(x,y,83,14); // Border Box
    drawRectangle(x+2,y+1,60,1); // Name Box
    setCursor(x+4,y+2); cout<<product.getName();
    drawRectangle(x+66,y+1,15,1); // Price Box
    setCursor(x+68,y+2); cout<<product.getPrice()<<" $";
    setCursor(x+3,y+4); cout<<product.getDescription(); // Description
    switch(user)
    {
        case CUSTOMER:
        {
            drawRectangle(x+21,y+11,39,1); // BUY Box
            setCursor(x+39,y+12); cout<<"BUY";
        } break;
        case SELLER:
        {
            drawRectangle(x+21,y+11,16,1);
            setCursor(x+28,y+12); cout<<"Edit";
            drawRectangle(x+50,y+11,16,1);
            setCursor(x+56,y+12); cout<<"Delete";
        } break;
        case ADMIN:
        {
            drawRectangle(x+21,y+11,39,1);
            setCursor(x+38,y+12); cout<<"Delete";
        } break;
    }
}

void interfaceAdmin(Admin &admin)
{
    while(1)
    {
        int result=firstPageOfAdmin(admin);
        if(result==-1)
            return;
        else if(result==-2)
        {
            admin.confirmAddSeller();
        }
        else if(result==-3)
        {
            admin.rejectAddSeller();
        }
        else if(!(result%2))
        {
            int id=sellerPage(*admin.getSellerAt(result/2),admin.getProducts());
            if(id==-2)
                continue;
            else if(id==-1)
                continue;
            else
            {
                productDetails(15,1,admin.getProduct(id));
                setCursor(0,31); system("pause");
            }
        }
        else if(result%2)
        {

        }
    }
}

void interfaceSeller(Seller *seller,Products &products)
{
    while(1)
    {
        Product *sellerProducts[seller->numberProducts()];
        seller->getProducts(sellerProducts,products.getProducts());
        int result=firstPageOfSeller(*seller,sellerProducts);

        if(result==-2)
            return ;
        else if(result==-1) // For add Product
        {
            Product product;
            if(interfaceAddProduct(product))
            {
                product.generateId();
                products.addProduct(product);
                seller->addProduct(product.getId());
            }

        }
        else if(!(result%3)) // For show Product
        {
            productDetails(15,1,*sellerProducts[result/3],SELLER);  // 3 -> number of buttons in per row
            setCursor(0,31); system("pause");
        }
        else if(result%3==1) // For edit Product
        {
            if(interfaceEditProduct(sellerProducts[(result-1)/3]))
            {
                productDetails(15,1,*sellerProducts[(result-1)/3],SELLER);
                setCursor(0,31); system("pause");
            }
        }
        else if(result%3==2) // For delete Product
        {
            products.deleteProduct(seller->deleteProductAt((result-2)/3));
        }
    }
}

void showAllProducts(Customer &customer,const List<Product> &products)
{
    while(1)
    {
        int result=showProducts(customer.getName(),products);
        if(result==-1)
            break;
        else if(!(result%2)) // For More
        {
            productDetails(15,1,products.getCopyItem(result/2));  // 2 -> number of buttons in per box
            setCursor(0,31); system("pause");
        }
        else if(result%2) // For Buy
        {
            customer.addToCart(products.getCopyItem(result/2));
//                productDetails(15,1,products.getProductConst(re/2));
            buyDialog(customer,products.getCopyItem(result/2).getName());
        }
    }
}

void showProductsOfCategory(Customer &customer,const Products &products,Category category)
{
    while(1)
    {
        int result=showProducts(
            customer.getName(),
            products.getProductsOfCategory(category.getProductsId()),
            category.getName()
        );
        if(result==-1)
            break;
        else if(!(result%2)) // For More
        {
            productDetails(15,1,products.getProductConstId(category[result/2]));  // 2 -> number of buttons in per box
            setCursor(0,31); system("pause");
        }
        else if(result%2) // For Buy
        {
            customer.addToCart(products.getProductConstId(category[result/2]));
            buyDialog(customer,products.getProductConst((category[result/2])).getName());
        }
    }
}

void interfaceCustomer(const Products &products)
{
    Customer customer(nameDialog());
    system("cls");
    int numCategories=products.categoriesLength();
    if(numCategories>10) numCategories=10;
    while(1)
    {
        int result=firstPageOfCustomer(customer,products);
        if(result==-1)
            return ;
        else if(result==-2)
        {
            int id=-1;
            int button=searchPage(customer.getName(),products.getProducts(),id);
            if(button==-1)
                continue;
            if(button==0)
            {
                productDetails(15,1,products.getProductConstId(id));
                setCursor(0,31); system("pause");
            }
            else if(button==1)
            {
                customer.addToCart(products.getProductConstId(id));
                buyDialog(customer,products.getProductConstId(id).getName());
            }

        }
        else if(result==-3)
            showCart(customer,customer.getCart());
        else if(result==-4)
        {
            while(1)
            {
                int index=showCategories(customer.getName(),products.getCategories());
                if(index==-1)
                    break;
                showProductsOfCategory(customer,products,products.getCategories().getCopyItem(index));
            }
        }
        else if(result==-5)
            showAllProducts(customer,products.getProducts());
        else if(result<numCategories)
             showProductsOfCategory(customer,products,products.getCategories().getCopyItem(result));
        else if(!((result-numCategories)%2))
        {
            productDetails(15,1,products.getProductConst((result-numCategories)/2));  // 2 -> number of buttons in per box
            setCursor(0,31); system("pause");
        }
        else if(((result-numCategories)%2))
        {
            customer.addToCart(products.getProductConst((result-numCategories)/2));
            buyDialog(customer,products.getProductConst((result-numCategories)/2).getName());
        }
    }

}

