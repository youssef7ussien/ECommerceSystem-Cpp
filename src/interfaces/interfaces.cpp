#include "interfaces.h"
#include "seller_interface.h"
#include "admin_interface.h"
#include "customer_interface.h"
#include "functions.h"
#include "graphics.h"
#include <iomanip>

#define NAME_PATTERN        "^[a-zA-z0-9 \\-]{3,15}$"
#define USERNAME_PATTERN    "^[a-zA-z0-9_.]{3,30}$"
#define EMAIL_PATTERN       "^[\\w\\._]{3,21}@[\\w\\._]{2,11}\\.\\w{2,4}$"
#define PASSWORD_PATTERN    "^[a-zA-z0-9_.]{8,30}$"

void aboutDialog()
{
    color(RED); drawRectangle(38,8,54,7); color();
    clearMultiLines(39,9,7,52);
    setCursor(50,10); cout<<"E-Commerce Management System";
    setCursor(57,12); color(DARK_GRAY);
    cout<<"version "; color(); cout<<"1.0";
    color(); drawRectangle(82,13,8,1);
    int index=0;
    while(true)
    {
        if(index==0) color(BLACK,RED);
        setCursor(84,14); cout<<"  OK  "; color();
        while(true)
        {
            char key=_getch();
            if(key==KEY_LEFT || key==KEY_DOWN || key==KEY_RIGHT || key==KEY_UP)
                { index=(index+1)%2; break; }
            else if(key==KEY_ESC || (key==KEY_ENTER && index==0))
                return ;
        }
    }
}

int interfaceLoginAs()
{
    system("cls");

    drawRectangle(50,1,30,1,2); // login as box
    setCursor(62,2); cout<<"Login as";
    drawRectangle(55,4,20,1); // Admin box
    drawRectangle(55,7,20,1); // Seller box
    drawRectangle(55,10,20,1); // Customer box
    drawRectangle(55,13,20,1); // Register box
    drawLine(50,16,82,16);
    drawRectangle(67,17,14,1); // Exit box

    int index=0;
    while(true)
    {
        if(index==0)  color(BLACK,RED);
        setCursor(57,5); cout<<"      Admin       "; color();

        if(index==1)  color(BLACK,RED);
        setCursor(57,8); cout<<"      Seller      "; color();

        if(index==2)  color(BLACK,RED);
        setCursor(57,11); cout<<"     Customer     "; color();

        if(index==3)  color(BLACK,RED);
        setCursor(57,14); cout<<"       About      "; color();

        setCursor(69,18);
        if(index==4)  color(BLACK,RED);
        cout<<"    EXIT    "; color();
        setCursor(0,28);
        while(true)
        {
            char key=_getch();
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
}

void loginDesign()
{
    drawRectangle(50,1,30,1,2); // login box
    setCursor(62,2); cout<<"Login";
    drawRectangle(45,6,40,1); // email box
    setCursor(46,5); cout<<"Enter email";
    drawRectangle(45,10,40,1); // password box
    setCursor(46,9); cout<<"Enter password";
    drawRectangle(50,14,14,1); // Again box
    drawRectangle(66,14,14,1); // Exit box
}

int chooseMethodLogin()
{
    color(RED); drawRectangle(38,8,54,3); color();
    setCursor(39,9); clearLine(52);
    setCursor(39,10); clearLine(52);
    setCursor(39,11); clearLine(52);
    drawRectangle(40,9,15,1);
    drawRectangle(75,9,15,1);

    int index=0;
    while(true)
    {
        if(index==0) color(BLACK,RED);
        setCursor(42,10); cout<<"    LOGIN    "; color();

        if(index==1) color(BLACK,RED);
        setCursor(77,10); cout<<"  REGISTER   "; color();
        while(true)
        {
            char key=_getch();
            if(key==KEY_LEFT || key==KEY_RIGHT)
                { index=(index+1)%2; break; }
            else if(key==KEY_ENTER)
                return index;
            else if(key==KEY_ESC)
                return -1;
        }
    }
}

bool interfaceLoginAdmin()
{
    system("cls");
    char key='0';  int index=2;
    string username,password;
    loginDesign();

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
            username=inputText();
            drawRectangle(45,6,40,1);

            initialBox(45,10,40,password.size());
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

        while(true)
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

bool interfaceLoginSeller(const Sellers &sellers,int &seller)
{
    system("cls");
    char key='0';  int index=2;
    string email,password;
    loginDesign();

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

        while(true)
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

bool validationInput(const Account &account,const string& confirmPassword) // Use in interfaceRegister()
{
    bool validation=true;
    if(!validationRegex(NAME_PATTERN,account.getFirstName()))
    {
        validation=false;
        setCursor(89,7); color(DARK_RED);
        cout<<"Incorrect first name";
    }
    if(!validationRegex(NAME_PATTERN,account.getLastName()))
    {
        validation=false;
        setCursor(89,11); color(DARK_RED);
        cout<<"Incorrect last name";
    }
    if(!validationRegex(USERNAME_PATTERN,account.getUserName()))
    {
        validation=false;
        setCursor(89,15); color(DARK_RED);
        cout<<"Incorrect username";
    }
    if(!validationRegex(EMAIL_PATTERN,account.getEmail()))
    {
        validation=false;
        setCursor(89,19); color(DARK_RED);
        cout<<"Incorrect email";
    }
    if(!validationRegex(PASSWORD_PATTERN,account.getPassword()))
    {
        validation=false;
        setCursor(89,23); color(DARK_RED);
        cout<<"Incorrect password";
    }
    if(account.getPassword()!=confirmPassword)
    {
        validation=false;
        setCursor(89,27); color(DARK_RED);
        cout<<"Password does not match";
    }
    color();
    return validation;
}

bool interfaceRegister(Account &account)
{
    system("cls");
    drawRectangle(50,1,30,1,2); // login box
    setCursor(62,2); cout<<"Register";
    drawRectangle(44,6,42,1); // firstName box
    setCursor(45,5); cout<<"First name";
    drawRectangle(44,10,42,1); // lastName box
    setCursor(45,9); cout<<"Last name";
    drawRectangle(44,14,42,1); // userName box
    setCursor(45,13); cout<<"username";
    drawRectangle(44,18,42,1); // email box
    setCursor(45,17); cout<<"Email";
    drawRectangle(44,22,42,1); // password box
    setCursor(45,21); cout<<"Password";
    drawRectangle(44,26,42,1); // confirm password box
    setCursor(45,25); cout<<"Confirm Password";
    drawRectangle(50,30,14,1); // Again box
    drawRectangle(66,30,14,1); // Exit box
    string confirmPassword;
    char key='0';  int index=2;
    while(key!=KEY_ENTER)
    {
        setCursor(52,31);
        if(index==0)  color(BLACK,RED);
        cout<<"   AGAIN    "; color();

        setCursor(68,31);
        if(index==1)  color(BLACK,RED);
        cout<<"    BACK    "; color();

        if(index==2)
        {
            initialBox(44,6,42,account.getFirstName().size());
            account.setFirstName(inputText());
            drawRectangle(44,6,42,1);

            initialBox(44,10,42,account.getLastName().size());
            account.setLastName(inputText());
            drawRectangle(44,10,42,1);

            initialBox(44,14,42,account.getUserName().size());
            account.setUserName(inputText());
            drawRectangle(44,14,42,1);

            initialBox(44,18,42,account.getEmail().size());
            account.setEmail(inputText());
            drawRectangle(44,18,42,1);

            initialBox(44,22,42,account.getPassword().size());
            account.setPassword(inputText());
            drawRectangle(44,22,42,1);

            initialBox(44,26,42,confirmPassword.size());
            confirmPassword=inputText();

            if(validationInput(account,confirmPassword))
            {
                registerDoneDialog();
                return true;
            }
            drawRectangle(44,26,42,1);
            index=0;
            continue;
        }
        while(true)
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
            setCursor(89,7);  cout<<"                       ";
            setCursor(89,11); cout<<"                       ";
            setCursor(89,15); cout<<"                       ";
            setCursor(89,19); cout<<"                       ";
            setCursor(89,23); cout<<"                       ";
            setCursor(89,27); cout<<"                       ";
        }
    }
    return false;
}

bool interfaceExitGame(int x,int y)
{
    drawRectangle(x,y,43,5);
    setCursor(x+1,y+1); color();
    cout<<"               Are You Sure ?              ";
    clearMultiLines(x+1,y+2,4,43);
    drawRectangle(x+2,y+3,11,1);
    drawRectangle(x+33,y+3,8,1);

    int index=0;
    while(true)
    {
        if(index==1)  color(BLACK,RED);
        setCursor(x+4,y+4); cout<<"   YES   "; color();

        if(index==0)  color(BLACK,RED);
        setCursor(x+35,y+4); cout<<"  NO  "; color();
        while(true)
        {
            char key=_getch();
            if(key==KEY_RIGHT || key==KEY_LEFT)
                { index=(index+1)%2; break; }
            else if(key==KEY_ENTER)
                return index==1;
            else if(key==KEY_ESC)
                return false;
        }
    }
}

string editField(int x,int y,string text,const string& patternRegex,int width)
{
    setCursor(89,y+1); cout<<"               ";
    initialBox(x,y,width,text.size());

    while(true)
    {
        text=inputText();
        if(text=="" || !validationRegex(patternRegex,text))
        {
            setCursor(89,y+1); cout<<"               "; wait(150);
            setCursor(89,y+1); color(DARK_RED);
            cout<<"Incorrect input";
            setCursor(x+2,y+1); clearLine(text.size());
            setCursor(x+2,y+1);
            color();
        }
        else
        {
            setCursor(89,y+1); cout<<"               ";
            color(GREEN); drawRectangle(x,y,width,1);
            setCursor(89,y+1); cout<<"Done";
            color();
            return text;
        }
    }
}

bool interfaceProfile(Account &account)
{
    system("cls");
    int index=0;
    statusBar(account.getFirstName(),"BACK");
    drawRectangle(44,7,42,1); // firstName box
    setCursor(45,6); cout<<"First name";
    setCursor(46,8); color(DARK_GRAY); cout<<account.getFirstName(); color();

    drawRectangle(44,11,42,1); // lastName box
    setCursor(45,10); cout<<"Last name";
    setCursor(46,12); color(DARK_GRAY); cout<<account.getLastName(); color();

    drawRectangle(44,15,42,1); // userName box
    setCursor(45,14); cout<<"username";
    setCursor(46,16); color(DARK_GRAY); cout<<account.getUserName(); color();

    drawRectangle(44,19,42,1); // email box
    setCursor(45,18); cout<<"Email";
    setCursor(46,20); color(DARK_GRAY); cout<<account.getEmail(); color();

    drawRectangle(44,23,42,1); // password box
    setCursor(45,22); cout<<"Password";
    setCursor(46,24); color(DARK_GRAY); cout<<account.getPassword(); color();
//    drawRectangle(44,22,42,1); // confirm password box
//    setCursor(45,21); cout<<"Confirm Password";
    for(int i=0 ; i<4 ; i++)
        drawRectangle(33,i==3 ? 23 : 4*i+7,8,1);
    drawRectangle(54,27,22,1); // DONE box

    while(true)
    {
        if(index==6) // Name
        {
            account.setFirstName(editField(44,7,account.getFirstName(),NAME_PATTERN,42));
            index=1;
        }
        else if(index==7) // Price
        {
            account.setLastName(editField(44,11,account.getLastName(),NAME_PATTERN,42));
            index=2;
        }
        else if(index==8) // Category
        {
            account.setUserName(editField(44,15,account.getUserName(),USERNAME_PATTERN,42));
            index=3;
        }
        else if(index==9) // Description
        {
            account.setPassword(editField(44,23,account.getPassword(),PASSWORD_PATTERN,42));
            index=4;
        }

        setCursor(35,8);
        if(index==0)  color(BLACK,RED);
        cout<<" Edit "; color();

        setCursor(35,12);
        if(index==1)  color(BLACK,RED);
        cout<<" Edit "; color();

        setCursor(35,16);
        if(index==2)  color(BLACK,RED);
        cout<<" Edit "; color();

        setCursor(35,24);
        if(index==3)  color(BLACK,RED);
        cout<<" Edit "; color();

        setCursor(56,28);
        if(index==4)  color(BLACK,RED);
        cout<<"        DONE        "; color();

        while(true)
        {
            char key=_getch();
            if(key==KEY_DOWN)
                { index=(index+1)%5; break; }
            else if(key==KEY_UP)
                { index=(index+4)%5; break; }
            else if(key==KEY_ENTER)
            {

                if(index>=0 && index<=3)
                {
                    index+=6;
                    break;
                }
                else if(index==4)
                    return true;
            }
            else if(key==KEY_ESC)
                return false;
        }
    }
}

int keyboardBuyButton(int x,int y,string buttonName)
{
    int index=0;
    while(true)
    {
        if(index==0) color(BLACK,RED);
        setCursor(x,y); cout<<buttonName; color();
        while(true)
        {
            char key=_getch();
            if(key==KEY_LEFT || key==KEY_DOWN || key==KEY_RIGHT || key==KEY_UP)
                { index=(index+1)%2; break; }
            else if(key==KEY_ENTER && index==0)
                return index;
            else if(key==KEY_ESC)
                return -1;
        }
    }
}

int keyboardBuyButton(int x,int y)
{
    int index=0;
    while(true)
    {
        if(index==0) color(BLACK,RED);
        setCursor(x,y); cout<<"       Edit       "; color();

        if(index==1) color(BLACK,RED);
        setCursor(x+23,y); cout<<"      Delete      "; color();
        while(true)
        {
            char key=_getch();
            if(key==KEY_LEFT || key==KEY_RIGHT)
                { index=(index+1)%2; break; }
            else if(key==KEY_ENTER)
                return index;
            else if(key==KEY_ESC)
                return -1;
            else if(key=='e')
                return 0;
            else if(key=='d')
                return 1;
        }
    }
}

int productDetails(const Product& product,const string &userName,User user=CUSTOMER)
{
    system("cls");
    statusBar(userName,"BACK");
    drawRectangle(55,5,19,1);
    setCursor(58,6); color(CYAN); cout<<"PRODUCT DETAILS"; color();
    drawRectangle(23,8,83,20); // Border Box
    color(DARK_GRAY); drawRectangle(25,9,60,1); color(); // Name Box
    setCursor(29,10); color(CYAN); cout<<product.getName(); color();

    color(DARK_GRAY); drawRectangle(88,9,16,1); color(); // Price Box
    setCursor(90,10); cout<<setw(12)<<setprecision(8)<<product.getPrice()<<" $";

    color(DARK_GRAY); drawRectangle(31,12,67,1); // Category Box
    setCursor(33,13); color(YELLOW); cout<<"Category : ";
    color(); cout<<product.getCategoryName(); // Category name
    drawLine(50,15,80,15);
    if(product.getDescription().size()<80)
        { setCursor(26,17); cout<<product.getDescription(); }
    else
    {
        setCursor(26,17); cout<<product.getDescription().substr(0,80);
        setCursor(26,18); cout<<product.getDescription().substr(80);
    }

    if(product.getQuantity()==0)
    {
        setCursor(58,31); color(WHITE,DARK_RED);
        cout<<"  Out of stock  "; color();
    }
    if(user!=CUSTOMER)
    {
        setCursor(26,25); color(YELLOW);
        cout<<"Quantity in stock : "; color();
        cout<<product.getQuantity();
    }

    switch(user)
    {
        case CUSTOMER:
        {
            drawRectangle(45,26,39,1);
            return keyboardBuyButton(47,27,"                 BUY                 ");
        } break;
        case SELLER:
        {
            drawRectangle(43,26,20,1);
            drawRectangle(66,26,20,1);
            return keyboardBuyButton(45,27);
        } break;
        case ADMIN:
        {
            drawRectangle(45,26,39,1);
            return keyboardBuyButton(47,27,"                DELETE               ");
        } break;
    }

    return -1;
}

void interfaceAdmin(Admin &admin)
{
    while(true)
    {
        int result=firstPageOfAdmin(admin);
        if(result==-1) // For back
        {
            if(logOutDialog(admin.getFirstName()))
                return;
        }
        else if(result==-2) // For profile
            shortcutsAdminDialog(admin.getFirstName());

        else if(result==-3) // For profile
            interfaceProfile(*admin.getAccount());

        else if(result==-4) // For confirm
            admin.confirmAddSeller();

        else if(result==-5) // For reject
            admin.rejectAddSeller();

        else if(!(result%2)) // For Show seller page
        {
            while(true)
            {
                int id=sellerPage(*admin.getSellerAt(result/2),admin.getProducts());
                if(id==-1)
                    break;
                else
                {
                    int index=productDetails(admin.getProduct(id),admin.getFirstName(),ADMIN);
                    if(index==0)
                    {
                        admin.deleteProduct(id);
                        admin.getSellerAt(result/2)->deleteProductId(id);
                    }
                }
            }
        }
        else if(result%2) // For delete seller
            admin.deleteSeller(result/2);
    }
}

void editProduct(const string& sellerName,Product &product,Products &products) // Use in interfaceSeller()
{
    string oldCategoryName=product.getCategoryName();
    if(interfaceEditProduct(sellerName,product))
    {
        productDetails(product,sellerName,SELLER);
        if(oldCategoryName!=product.getCategoryName())
            products.changeCategory(product.getId(),oldCategoryName,product.getCategoryName());
    }
}

void interfaceSeller(Seller &seller,Products &products)
{
    while(true)
    {
        /**
         *   The dual pointer is used to contain the addresses
         *    of the seller's products so that they can be accessed
         *    and modified to be modified on the original product.
         */
        Product **sellerProducts;
        sellerProducts=new Product*[seller.numberProducts()];
        seller.getProducts(sellerProducts,products.getProducts());
        int result=firstPageOfSeller(seller,sellerProducts);

        if(result==-1) // For back
        {
            if(!logOutDialog(seller.getFirstName()))
                continue;

            delete[] sellerProducts;
            delete sellerProducts;
            return;
        }
        else if(result==-2) // For shortcuts
            shortcutsSellerDialog(seller.getFirstName());

        else if(result==-3) // For Profile
            interfaceProfile(*seller.getAccount());

        else if(result==-4) // For add Product
        {
            Product product;
            if(interfaceAddProduct(seller.getFirstName(),product))
            {
                seller.addProductId(product.generateId());
                products.addProduct(product);
            }
        }
        else if(!(result%3)) // For show Product
        {
            // 3 -> number of buttons in per row
            int index=productDetails(*sellerProducts[result/3],seller.getFirstName(),SELLER);
            if(index==0)
                editProduct(seller.getFirstName(),*sellerProducts[result/3],products);
            else if(index==1)
                products.deleteProduct(seller.deleteProductIdAt(result/3));
        }
        else if(result%3==1) // For edit Product
            editProduct(seller.getFirstName(),*sellerProducts[(result-1)/3],products);

        else if(result%3==2) // For delete Product
            products.deleteProduct(seller.deleteProductIdAt((result-2)/3));

        delete[] sellerProducts;
        delete sellerProducts;
    }
}

void buyProduct(Customer &customer,Product &product)
{
    if(product.outOfStock())
    {
        outOfStockDialog(customer.getName());
        return;
    }

    if(customer.cartLength()<9)
    {
        customer.addToCart(product);
        product.decreaseStock();
        buyDialog(customer,product.getName());
    }
    else
        cartFullDialog(customer.getName());
}

void shoppingCart(Customer &customer,Products &products)
{
    PurchaseData PD;
    int index=showCart(customer.getName(),customer.getCart().copy(),PD);
    if(index==-1)
        return;
    else if(index==0)
    {
        customer.createPurchaseData(PD);
        customer.printPurchaseData(customer.getCart().copy());
        customer.clearCart();
    }
    else if(index==1)
    {
        int length=customer.cartLength();
        for(int i=0 ; i<length ; i++)
            products.getProduct(customer.removeFromCart().getId())->increaseStock();
    }
}

void showProductDetails(Customer &customer,Product &product)
{
    int index=productDetails(product,customer.getName());
    if(index==0)
        buyProduct(customer,product);
}

void showAllProducts(Customer &customer,Products &products)
{
    while(true)
    {
        int result=showProducts(customer.getName(),products.getProducts());
        if(result==-1)
            return;
        else if(!(result%2)) // For More
            showProductDetails(customer,*products.getProductAt(result/2));
        else if(result%2) // For Buy
            buyProduct(customer,*products.getProductAt(result/2));
    }
}

void showProductsOfCategory(Customer &customer,Products &products,Category category)
{
    while(true)
    {
        int result=showProducts(customer.getName(),
                                products.getProductsOfCategory(category.getProductsId()),
                                category.getName());
        if(result==-1)
            return;
        else if(!(result%2)) // For More
            showProductDetails(customer,*products.getProduct(category[result/2]));
        else if(result%2) // For Buy
            buyProduct(customer,*products.getProduct(category[result/2]));
    }
}

void searchForProducts(Customer &customer,Products &products)
{
    List<Product> productsFounded;
    string text=searchPage(customer.getName(),products.getProducts(),productsFounded);
    if(text.empty())
        return;
    while(true)
    {
        int result=showProducts(customer.getName(),productsFounded,"*"+text);
        if(result==-1)
            break;
        else if(!(result%2))
            showProductDetails(customer,*products.getProduct(productsFounded.getCopyItemAt(result/2).getId()));
        else if(result%2)
            buyProduct(customer,*products.getProduct(productsFounded.getCopyItemAt(result/2).getId()));
    }
}

void interfaceCustomer(Products &products)
{
    if(products.productsLength()==0)
    {
        noProductDialog();
        return;
    }

    Customer customer(nameDialog());
    system("cls");
    int numCategories=products.categoriesLength();
    if(numCategories>10) numCategories=10;
    while(true)
    {
        int result=firstPageOfCustomer(customer,products);
        if(result==-1) // For Logout
        {
            if(!logOutDialog(customer.getName()))
                continue;
            if(customer.cartLength()!=0)
            {
                int length=customer.cartLength();
                for(int i=0 ; i<length ; i++)
                    products.getProduct(customer.removeFromCart().getId())->increaseStock();
            }
            return;
        }

        else if(result==-2) // For search
            searchForProducts(customer,products);

        else if(result==-3) // For shopping cart
            shoppingCart(customer,products);

        else if(result==-4) // For show all categories
        {
            while(true)
            {
                int index=showCategories(customer.getName(),products.getCategories());
                if(index==-1)
                    break;
                showProductsOfCategory(customer,products,products.getCategories().getCopyItemAt(index));
            }
        }

        else if(result==-5) // For all products
            showAllProducts(customer,products);

        else if(result==-6) // For show shortcuts
            shortcutsCustomerDialog(customer.getName());

        else if(result<numCategories) // For products of category
             showProductsOfCategory(customer,products,products.getCategories().getCopyItemAt(result));

        else if(!((result-numCategories)%2)) // For more in first page
            showProductDetails(customer,*products.getProductAt((result-numCategories)/2));

        else if(((result-numCategories)%2)) // For buy in first page
            buyProduct(customer,*products.getProductAt((result-numCategories)/2));
    }
}
