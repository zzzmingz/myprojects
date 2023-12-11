#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

#define productlines 50
#define userlines 1000
#define cartmax 25

using namespace std;

int main();
int MainMenu();
void RegisterUser();
void LoginMenu();
void CashierMenu();
void AdminMenu();
void ProductMenu();
void AddProduct();
void EditProduct();
void DeleteProduct();
void EditUserMenu();
void EditUser();
void DeleteUser();
void CheckAvailability();
void SalesMenu();
void CheckCart();
void AddItemsToCart();
void DeleteItemsFromCart();
void Payment();
string AskUserString(string question);
int AskUserInt(string question);
float AskUserFloat(string question);
char AskUserChar(string question);
ofstream efile;
ifstream sfile;
bool System = true;
bool LogIn;
bool AdminAcc;
string PriceArray[cartmax];
int CartPos = 1;
string Cart[cartmax];

int MainMenu()
{
    char MainMenuRespo;

    cout << "\t ----------------------------------------------" << endl;
    cout << "\t      WELCOME TO THE POINT OF SALES SYSTEM    " << endl;
    cout << "\t ----------------------------------------------\n" << endl;
    cout << "\t   A. Register" << endl;
    cout << "\t   B. Login" << endl;
    cout << "\t   C. Exit \n" << endl;
    cout << "\t   Please choose:";
    cin >> MainMenuRespo;

    switch(MainMenuRespo)
    {
    case 'A':
        RegisterUser();
        break;
    case 'B':
        LoginMenu();
        break;
    case 'C':
        system("cls");
        cout << "Exiting...";
        System = false;
        break;
    default:
        system("cls");
        cout << "\n\t INVALID OPTION! Please try again. \n\n";
        break;
    }
}

enum UserType{Cashier, Admin};

struct UserData{string firstName, lastName, userName, Pword, UserID;
    UserType type;
};

void RegisterUser()
{
    UserData uData;
    char uTypeResponse;
    char RegisterResponse;
    bool Register = true;
    bool uTypeRespo = true;
    bool useridCheck = true;
    bool RegisterOut = true;

    do{
    system("cls");
    do{

    cout << "\t ------------------------" << endl;
    cout << "\t         REGISTER        " << endl;
    cout << "\t ------------------------" << endl;
    cout << "\t Please enter a user ID: ";
    cin >> uData.UserID;


    sfile.open("User" + uData.UserID + ".txt");
    if (sfile.is_open()){
        system("cls");
        cout << "\n\t USER ID IS ALREADY REGISTERED. Please enter a different user ID.\n";
        sfile.close();
    }else{
        useridCheck = false;
    }
    }while(useridCheck);

    system("cls");
    cout << "\t ------------------------" << endl;
    cout << "\t         REGISTER        " << endl;
    cout << "\t ------------------------" << endl;
    uData.firstName = AskUserString("\t First Name: ");
    uData.lastName = AskUserString("\t Last Name: ");
    uData.userName = AskUserString("\t Username: ");
    uData.Pword = AskUserString("\t Password: ");

    do{
    cout << "\n\t User type:" << endl;
    cout << "\t (1) Cashier" << endl;
    cout << "\t (2) Admin" << endl;
    cout << "\n\t Please choose a user type:";
    cin >> uTypeResponse;

    if(uTypeResponse == '1'){
        uData.type = Cashier;
        uTypeRespo = false;
    }else if(uTypeResponse == '2'){
        uData.type = Admin;
        uTypeRespo = false;
    }else{
        cout << "\n\t INVALID OPTION! Please try again. \n\n";
    }
    }while(uTypeRespo);

    efile.open("User" + uData.UserID + ".txt");
    if(efile.is_open()){
        efile << uData.firstName << " " << uData.lastName << "\n";
        efile << uData.userName << "\n";
        efile << uData.Pword << "\n";
        efile << uData.type << "\n";
        efile.close();
    }

    do{
    system("cls");
    cout << "\t ------------------------" << endl;
    cout << "\t     ACCOUNT CREATED!    " << endl;
    cout << "\t ------------------------" << endl;
    cout << "\t What would you like to do now? \n" << endl;
    cout << "\t (1) Create another account" << endl;
    cout << "\t (2) Return \n" << endl;
    cout << "\t Please choose:";
    cin >> RegisterResponse;

    if(RegisterResponse == '1'){
        system("cls");
        RegisterOut = false;
        continue;
    }else if(RegisterResponse == '2'){
        system("cls");
        RegisterOut = false;
        Register = false;
    }else{

    }
    }while(RegisterOut);


    }while(Register);

}

int main()
{

    do{
    while(!LogIn){
        MainMenu();
        if(!System){
            return 0;
        }
    }
    if(LogIn){
        if(AdminAcc){
            AdminMenu();
        }else{
            CashierMenu();
        }
    }

    }while(System);
}

void LoginMenu()
{
    UserData u;
    bool useridCheck = true;
    string userNameCheck;
    string passwordCheck;
    string uname;
    string passw;
    string uType;

    system("cls");
    do{
    cout << "\t ----------------------------------" << endl;
    cout << "\t ENTER YOUR USER ID HERE TO VERIFY" << endl;
    cout << "\t ----------------------------------" << endl;
    u.UserID = AskUserString("\t Enter User ID: ");

    sfile.open("User" + u.UserID + ".txt");
    if (!sfile.is_open()){
        system("cls");
        cout << "\n\t ERROR! User not registered! " + u.UserID + " does not exist in the database! \n";
    }else{
        useridCheck = false;
        sfile.close();
    }
    }while(useridCheck);
    system("cls");

    do{
    cout << "\t ----------------------------------" << endl;
    cout << "\t             LOGIN HERE            " << endl;
    cout << "\t ----------------------------------" << endl;
    userNameCheck = AskUserString("\n\t Username: ");
    passwordCheck = AskUserString("\t Password: ");

    sfile.open("User" + u.UserID + ".txt");
    if(sfile.is_open()){
        for(int i=0; i<=1; i++){
            getline(sfile, uname);
        }
        getline(sfile, passw);
        if(uname != userNameCheck || passw != passwordCheck){
            system("cls");
            cout << "\n\t INCORRECT USERNAME OR PASSWORD! Please try again. \n";
        }
    }
    sfile.close();
    }while(uname != userNameCheck || passw != passwordCheck);

    sfile.open("User" + u.UserID + ".txt");
    if(sfile.is_open()){
        for(int i=0; i<=3; i++){
            getline(sfile, uType);
        }
        if(uType == "1"){
            AdminAcc = true;
        }else{
            AdminAcc = false;
        }
    sfile.close();
    }

    LogIn = true;
    system("cls");
}

struct ProductData{
    string productName, productID;
    int productCount;
    float productPrice;
};

void CashierMenu()
{
    system("cls");
    bool Cashier;
    char CashierRespo;

    do {
    cout << "\t ----------------------------------" << endl;
    cout << "\t               CASHIER             " << endl;
    cout << "\t ----------------------------------" << endl;
    cout << "\n\t What would you like to do? \n" << endl;
    cout << "\t (1) Check Item Availablity" << endl;
    cout << "\t (2) Start Sales" << endl;
    cout << "\t (3) Logout" << endl;
    cout << "\n\t Please choose: ";
    cin >> CashierRespo;

    switch(CashierRespo){
    case '1':
        CheckAvailability();
        break;
    case '2':
        SalesMenu();
        break;
    case '3':
        system("cls");
        Cashier = false;
        LogIn = false;
        break;
    default:
        system("cls");
        cout << "\n\t INVALID OPTION! Please try again. \n\n";
        break;
    }
    }while(Cashier);
}

void AdminMenu()
{
    system("cls");
    bool Admin;
    char AdminRespo;

    do{
    cout << "\t ----------------------------------" << endl;
    cout << "\t                ADMIN              " << endl;
    cout << "\t ----------------------------------" << endl;
    cout << "\n\t (1) Products" << endl;
    cout << "\t (2) Users" << endl;
    cout << "\t (3) Logout" << endl;
    cout << "\n\t Please choose: ";
    cin >> AdminRespo;

    switch(AdminRespo){
    case '1':
        ProductMenu();
        break;
    case '2':
        EditUserMenu();
        break;
    case '3':
        system("cls");
        Admin = false;
        LogIn = false;
        break;
    default:
        system("cls");
        cout << "\n\t INVALID OPTION! Please try again. \n\n";
        break;
    }
    }while(Admin);
}

void ProductMenu()
{
    system("cls");
    char ProductRespo;
    bool Product = true;

    do{
    cout << "\t ----------------------------------" << endl;
    cout << "\t             PRODUCTS              " << endl;
    cout << "\t ----------------------------------" << endl;
    cout << "\n\t What would you like to do? \n" << endl;
    cout << "\t (1) Add Product" << endl;
    cout << "\t (2) Edit Product" << endl;
    cout << "\t (3) Delete Product" << endl;
    cout << "\t (4) Back" << endl;
    cout << "\n\t Please choose: ";
    cin >> ProductRespo;

    switch(ProductRespo){
    case '1':
        AddProduct();
        break;
    case '2':
        EditProduct();
        break;
    case '3':
        DeleteProduct();
        break;
    case '4':
        system("cls");
        Product = false;
        break;
    default:
        system("cls");
        cout << "\n\t INVALID OPTION! Please try again. \n\n";
    }
    }while(Product);
}

void AddProduct()
{
    system("cls");

    ProductData pData;
    bool prodidCheck = true;

    system("cls");
    do{
    cout << "\t ----------------------------------" << endl;
    cout << "\t           ADD A PRODUCT           " << endl;
    cout << "\t ----------------------------------" << endl;
    cout << "\n\t Please enter a product ID: ";
    cin >> pData.productID;

    sfile.open("Product" + pData.productID + ".txt");
    if (sfile.is_open()){
        system("cls");
        cout << "\n\t ERROR! Product ID is already registered. Please enter a different product ID.\n";
        sfile.close();
    }else{
        prodidCheck = false;
    }
    }while(prodidCheck);

    system("cls");
    cout << "\t ----------------------------------" << endl;
    cout << "\t          ADDING PRODUCTS          " << endl;
    cout << "\t ----------------------------------" << endl;
    cout << "\n\t Please fill the following form \n" << endl;
    pData.productName = AskUserString("\t Product Name: ");
    pData.productCount = AskUserInt("\t Product Count: ");
    pData.productPrice = AskUserFloat("\t Product Price: ");

    efile.open("Product" + pData.productID + ".txt");
    cout << "\n\t ADDED A PRODUCT SUCCESSFULLY!" << endl;

    if(efile.is_open()){
        efile << pData.productName << "\n";
        efile << pData.productCount << "\n";
        efile << pData.productPrice << "\n";
        efile.close();
    }
}

void EditProduct()
{
    system("cls");

    ProductData p;
    bool prodidCheck = true;
    bool EditProduct = true;
    char EditRespo;
    int EditLine;
    int LineNum = 0;
    string LineArray[productlines];

    system("cls");

    do{
    cout << "\t ----------------------------------" << endl;
    cout << "\t            EDIT PRODUCT          " << endl;
    cout << "\t ----------------------------------" << endl;
    p.productID = AskUserString("\n\t Please enter the Product ID: ");

    sfile.open("Product" + p.productID + ".txt");
    if (!sfile.is_open()){
        system("cls");
        cout << "\n\t ERROR! Product " + p.productID + " is not registered! Please enter a different product ID. \n";
    }else{
        prodidCheck = false;
        sfile.close();
    }
    }while(prodidCheck);

    system("cls");
    do{
    cout << "\t ----------------------------------" << endl;
    cout << "\t            EDIT PRODUCT          " << endl;
    cout << "\t ----------------------------------" << endl;
    cout << "\n\t What do you wish to edit? \n" << endl;
    cout << "\t (1) Name" << endl;
    cout << "\t (2) Inventory" << endl;
    cout << "\t (3) Price" << endl;
    cout << "\t (4) Back" << endl;
    cout << "\n\t Please choose: ";
    cin >> EditRespo;

    switch(EditRespo){
    case '1':
        {
        sfile.open("Product" + p.productID + ".txt");
        if(sfile.is_open()){
            while(!sfile.eof()){
                getline(sfile, LineArray[LineNum]);
                LineNum++;
                if(LineNum == productlines){
                    break;
                }
            }
        }
        sfile.close();

        EditLine = 0;
        LineArray[EditLine] = AskUserString("\t Change product name: ");

        efile.open("Product" + p.productID + ".txt");
        if(efile.is_open()){
            for(int i = 0; i < LineNum; i++){
                efile << LineArray[i] + "\n";
            }
        }
        efile.close();
        break;
        }
    case '2':
        {
        sfile.open("Product" + p.productID + ".txt");
        if(sfile.is_open()){
            while(!sfile.eof()){
                getline(sfile, LineArray[LineNum]);
                LineNum++;
                if(LineNum == productlines){
                    break;
                }
            }
        }
        sfile.close();

        EditLine = 1;
        LineArray[EditLine] = AskUserString("\t Change product count: ");

        efile.open("Product" + p.productID + ".txt");
        if(efile.is_open()){
            for(int i = 0; i < LineNum; i++){
                efile << LineArray[i] + "\n";
            }
        }
        efile.close();
        break;
        }
    case '3':
        {
        sfile.open("Product" + p.productID + ".txt");
        if(sfile.is_open()){
            while(!sfile.eof()){
                getline(sfile, LineArray[LineNum]);
                LineNum++;
                if(LineNum == productlines){
                    break;
                }
            }
        }
        sfile.close();

        EditLine = 2;
        LineArray[EditLine] = AskUserString("\t Change product price: ");

        efile.open("Product" + p.productID + ".txt");
        if(efile.is_open()){
            for(int i = 0; i < LineNum; i++){
                efile << LineArray[i] + "\n";
            }
        }
        efile.close();
        break;
        }
    case '4':
        system("cls");
        EditProduct = false;
        break;
    default:
        system("cls");
        cout << "\n\t INVALID OPTION! Please try again. \n\n";
    }
}while(EditProduct);
}

void DeleteProduct()
{
    system("cls");

    int status;
    string prodid;
    string prod;
    char ProdName[1000];
    char DeleteMenu;
    char DeleteConfirm;
    bool Delete = true;

    do{
    cout << "\t ----------------------------------" << endl;
    cout << "\t           DELETE PRODUCT          " << endl;
    cout << "\t ----------------------------------" << endl;
    cout << "\n\t (1) Delete Product" << endl;
    cout << "\t (2) Back" << endl;
    cout << "\n\t Please choose: ";
    cin >> DeleteMenu;

    switch(DeleteMenu){
    case '1':
        prodid = AskUserString("\t Please input the Product ID of the product to delete:");
        prod = "Product" + prodid + ".txt";
        DeleteConfirm = AskUserChar("\t Press [Y] to confirm deletion. Enter any key to return.\n\t ");
        if(DeleteConfirm == 'Y'){
            for(int i = 0; i < sizeof(prodid); i++){
                ProdName[i] = prod[i];
            }
            status = remove(ProdName);
            if(status == 0){
                system("cls");
                cout << "\n\t PRODUCT DELETED SUCCESSFULLY! \n\n ";
            }else{
            cout << "\t Error in Deleting File!";
            }
            break;
        }else{
            break;
        }
    case '2':
        system("cls");
        Delete = false;
        break;
    default:
        system("cls");
        cout << "\n\t INVALID OPTION! Please try again. \n\n";
        break;
    }
    }while(Delete);
}

void EditUserMenu()
{
    system("cls");
    char UserResponse;
    bool User = true;

    do{
    cout << "\t ----------------------------------" << endl;
    cout << "\t                USER               " << endl;
    cout << "\t ----------------------------------" << endl;
    cout << "\n\t What do you wish to edit? \n" << endl;
    cout << "\t (1) Add User" << endl;
    cout << "\t (2) Edit User" << endl;
    cout << "\t (3) Delete User" << endl;
    cout << "\t (4) Back" << endl;
    cout << "\n\t Please choose: ";
    cin >> UserResponse;

    switch(UserResponse){
    case '1':
        RegisterUser();
        break;
    case '2':
        EditUser();
        break;
    case '3':
        DeleteUser();
        break;
    case '4':
        system("cls");
        User = false;
        break;
    default:
        system("cls");
        cout << "\n\t INVALID OPTION! Please try again. \n\n";
    }
    }while(User);
}

void EditUser()
{
    system("cls");

    UserData u;
    bool useridCheck = true;
    bool EditUserb = true;
    char EditResponse;
    int eLine;
    int LineNum = 0;
    string LineArray[userlines];

    system("cls");

    do{
    cout << "\t ----------------------------------" << endl;
    cout << "\t              EDIT USER            " << endl;
    cout << "\t ----------------------------------" << endl;
    u.UserID = AskUserString("\n\t Please enter the User ID: ");

    sfile.open("User" + u.UserID + ".txt");
    if (!sfile.is_open()){
        system("cls");
        cout << "\n\t ERROR! User not registered! " + u.UserID + " does not exist in the database! \n";
    }else{
        useridCheck = false;
        sfile.close();
    }
    }while(useridCheck);

    system("cls");
    cout << "\t ----------------------------------" << endl;
    cout << "\t              EDIT USER            " << endl;
    cout << "\t ----------------------------------" << endl;
    cout << "\n\t What do you wish to edit? \n" << endl;
    cout << "\t (1) Name" << endl;
    cout << "\t (2) Username" << endl;
    cout << "\t (3) Password" << endl;
    cout << "\t (4) Access" << endl;
    cout << "\t (5) Back" << endl;
    cout << "\n\t Please choose: ";
    cin >> EditResponse;

    switch(EditResponse){
    case '1':
        {
        sfile.open("User" + u.UserID + ".txt");
        if(sfile.is_open()){
            while(!sfile.eof()){
                getline(sfile, LineArray[LineNum]);
                LineNum++;
                if(LineNum == userlines){
                    break;
                }
            }
        }
        sfile.close();

        eLine = 0;
        cout << "\n\t Please enter your new desired first and last name." << endl;
        LineArray[eLine] = AskUserString("\t New first and last Name: ");

        efile.open("User" + u.UserID + ".txt");
        if(efile.is_open()){
            for(int i = 0; i < LineNum; i++){
                efile << LineArray[i];
            }
        }
        efile.close();
        system("cls");
        break;
        }
    case '2':
        {
        sfile.open("User" + u.UserID + ".txt");
        if(sfile.is_open()){
            while(!sfile.eof()){
                getline(sfile, LineArray[LineNum]);
                LineNum++;
                if(LineNum == userlines){
                    break;
                }
            }
        }
        sfile.close();

        eLine = 1;
        LineArray[eLine] = AskUserString("\t Change username: ");

        efile.open("User" + u.UserID + ".txt");
        if(efile.is_open()){
            for(int i = 0; i < LineNum; i++){
                efile << LineArray[i];
            }
        }
        efile.close();
        system("cls");
        break;
        }
    case '3':
        {
        sfile.open("User" + u.UserID + ".txt");
        if(sfile.is_open()){
            while(!sfile.eof()){
                getline(sfile, LineArray[LineNum]);
                LineNum++;
                if(LineNum == userlines){
                    break;
                }
            }
        }
        sfile.close();

        eLine = 2;
        cout << "\n\t Please enter your new desired password." << endl;
        LineArray[eLine] = AskUserString("\t New Password:  ");

        efile.open("User" + u.UserID + ".txt");
        if(efile.is_open()){
            for(int i = 0; i < LineNum; i++){
                efile << LineArray[i];
            }
        }
        efile.close();
        system("cls");
        break;
        }
    case '4':
        {
        sfile.open("User" + u.UserID + ".txt");
        if(sfile.is_open()){
            while(!sfile.eof()){
                getline(sfile, LineArray[LineNum]);
                LineNum++;
                if(LineNum == userlines){
                    break;
                }
            }
        }
        sfile.close();

        eLine = 3;
        bool Cashier = true;
        char CashierAcc;
        string num1;

        cout << "\n\t Please select the account's new type: " << endl;
        CashierAcc = AskUserChar("\n\t (1) Cashier\n \t (2) Admin \n\n \t What access will you give to the account?");

        if(CashierAcc = '1'){
            num1 = "0";
        }else if(CashierAcc = '2'){
            num1 = "1";
        }
        LineArray[eLine] = num1;

        efile.open("User" + u.UserID + ".txt");
        if(efile.is_open()){
            for(int i = 0; i < LineNum; i++){
                efile << LineArray[i];
            }
        }
        efile.close();
        system("cls");
        break;
        }
    case '5':
            system("cls");
            EditUserb = false;
            break;
    default:
            system("cls");
            cout << "\n\t INVALID OPTION! Please try again. \n\n";
            break;
    }
}

void DeleteUser()
{
    system("cls");

    int status;
    string deluserid;
    string deluser;
    char UserName[1000];
    char DeleteUserRespo;
    char DeleteConfirm;
    bool Delete = true;

    do{
    cout << "\t ----------------------------------" << endl;
    cout << "\t              EDIT USER            " << endl;
    cout << "\t ----------------------------------" << endl;
    cout << "\n\t (1) Delete User" << endl;
    cout << "\t (2) Back" << endl;
    cout << "\n\t Please choose: ";
    cin >> DeleteUserRespo;

    switch(DeleteUserRespo){
    case '1':
        deluserid = AskUserString("\n\t Please input the User ID of the user to delete:");
        deluser = "User" + deluserid + ".txt";
        DeleteConfirm = AskUserChar("\t Press [Y] to confirm deletion. Enter any key to return. \n\t ");
        if(DeleteConfirm == 'Y'){
            for(int i = 0; i < sizeof(deluserid); i++){
                UserName[i] = deluser[i];
            }
            status = remove(UserName);
            if(status == 0){
                system("cls");
                cout << "\t USER DELETED SUCCESSFULLY!";
            }else{
            cout << "\t Error in deleting user!\n";
            }
            break;
        }else{
            break;
        }

    case '2':
        system("cls");
        Delete = false;
        break;
    default:
        system("cls");
        cout << "\n\t INVALID OPTION! Please try again. \n\n";
        break;
    }
    }while(Delete);
}

void CheckAvailability()
{
    system("cls");
    ProductData p;
    string AmountCheck;
    char AvailCheckRespo;
    bool AvailCheck = true;

    do{
    cout << "\t ----------------------------------" << endl;
    cout << "\t      CHECK ITEM AVAILABILITY      " << endl;
    cout << "\t ----------------------------------" << endl;
    cout << "\n\t (1) Check Availability" << endl;
    cout << "\t (2) Back" << endl;
    cout << "\n\t Please choose:";
    cin >> AvailCheckRespo;

    switch(AvailCheckRespo){
    case '1':
        p.productID = AskUserString("\t Please enter the product ID: ");

        sfile.open("Product" + p.productID + ".txt");
        if(sfile.is_open()){
            for(int i=0; i<=1; i++){
                getline(sfile, AmountCheck);
            }
            system("cls");
            cout << "\t " << AmountCheck << " pcs" ;
            if(AmountCheck == "0"){
                cout << "\t PRODUCT UNAVAILABLE! \n";
            }else{
                cout << " - PRODUCT AVAILABLE! \n";
            }
            cin.ignore();
            system("cls");
        }
        CashierMenu(); // enter again to go back to Cashier Main Menu
        sfile.close();
        break;
    case '2':
        system("cls");
        AvailCheck = false;
        break;
    default:
        system("cls");
        cout << "\n\t INVALID OPTION! Please try again. \n\n";
        break;
    }
    }while(AvailCheck);
}

void SalesMenu()
{
    system("cls");
    bool SalesMenu = true;
    char StartSalesRespo;

    do{
        cout << "\t ----------------------------------" << endl;
        cout << "\t             START SALES           " << endl;
        cout << "\t ----------------------------------" << endl;
        cout << "\n\t What would you like to do?" << endl;
        cout << "\t (1) Add to Cart" << endl;
        cout << "\t (2) Check Cart" << endl;
        cout << "\t (3) Remove from Cart" << endl;
        cout << "\t (4) Payment" << endl;
        cout << "\t (5) Back" << endl;
        cout << "\n\t Please choose: ";
        cin >> StartSalesRespo;

        switch(StartSalesRespo){
        case '1':
            AddItemsToCart();
            break;
        case '2':
            CheckCart();
            break;
        case '3':
            DeleteItemsFromCart();
            break;
        case '4':
            Payment();
            break;
        case '5':
            system("cls");
            SalesMenu = false;
            break;
        default:
            system("cls");
            cout << "\n\t INVALID OPTION! Please try again. \n\n";
            break;
        }
    }while(SalesMenu);
}

void AddItemsToCart()
{
    ProductData p;
    string name, inventcount, price;
    char AddItemsRespo;
    bool AddtoCart;

    system("cls");

    do{
    cout << "\t ----------------------------------" << endl;
    cout << "\t          ADDING A PRODUCT          " << endl;
    cout << "\t ----------------------------------" << endl;
    cout << "\n\t (1) Add items to cart" << endl;
    cout << "\t (2) Back" << endl;
    cout << "\n\t Please choose:";
    cin >> AddItemsRespo;

    if(AddItemsRespo == '1'){
    p.productID = AskUserString("\t Enter Product ID: ");

    sfile.open("Product" + p.productID + ".txt");
    if(sfile.is_open()){
        getline(sfile, name);
        getline(sfile, inventcount);
        getline(sfile, price);

        system("cls");
        cout << "\n\t SUCCESSFULLY ADDED TO CART! \n";

    }else{
        system("cls");
        cout << "\t PRODUCT NOT FOUND! \n";
    }
    sfile.close();

    }else if(AddItemsRespo == '2'){
        system("cls");
        AddtoCart = false;
    }else{
        system("cls");
        cout << "\n\t INVALID OPTION! Please try again. \n\n" << endl;
    }


    }while(AddtoCart);

}

void CheckCart()
{
    system("cls");
    cout << "\t ----------------------------------" << endl;
    cout << "\t             YOUR CART             " << endl;
    cout << "\t ----------------------------------\n\n" << endl;

}

void DeleteItemsFromCart()
{
    char DeleteCartRespo;
    bool DeleteCart = true;
    int toDelete;

    system("cls");

    do{
    cout << "\t ----------------------------------" << endl;
    cout << "\t        DELETE FROM YOUR CART      " << endl;
    cout << "\t ----------------------------------\n" << endl;
    cout << "\t (1) Remove item from the cart" << endl;
    cout << "\t (2) Back" << endl;
    cout << "\t Please choose: ";
    cin >> DeleteCartRespo;

    if(DeleteCartRespo == '1'){
        for(int i=0; i<cartmax; i++){
            cout << to_string(i) + Cart[i] << "\n";
            if(Cart[i] == " "){
                break;
            }
        }
        toDelete = AskUserInt("\t Please enter the product ID you wish to delete: ");
        for(int i=toDelete; i<cartmax; i++){
            Cart[i]=Cart[i+1];
            PriceArray[i]=PriceArray[i+1];
            if(Cart[i] == " "){
                break;
            }
        }
        for(int i=0; i<cartmax; i++){
            cout << to_string(i) + Cart[i] << "\n";
            if(Cart[i] == " "){
                break;
            }
        }
    }else if(DeleteCartRespo == '2'){
        system("cls");
        DeleteCart = false;
    }else{
        system("cls");
        cout << "\n\t INVALID OPTION! Please try again. \n\n";
    }
    }while(DeleteCart);

}

void Payment()
{
    system("cls");
    bool Payment = true;
    char PaymentRespo;

    do{
    cout << "\t ----------------------------------" << endl;
    cout << "\t               PAYMENT             " << endl;
    cout << "\t ----------------------------------\n" << endl;
    cout << "\t (1) Continue to Payment" << endl;
    cout << "\t (2) Back" << endl;
    cout << "\n\t Please choose: ";
    cin >> PaymentRespo;

    switch(PaymentRespo){
    case '1':
        cout << "\n\t PAYMENT SUCCESSFUL!" << endl;
        break;
    case '2':
        system("cls");
        Payment = false;
        break;
    default:
        system("cls");
        cout << "\n\t INVALID OPTION! Please try again. \n\n";
        }
    }while(Payment);
}

string AskUserString(string question)
{
    string respo;
    cout << question;
    getline(cin >> ws, respo);
    return respo;
}

int AskUserInt(string question)
{
    int respo;
    cout << question;
    cin >> respo;
    return respo;
}

float AskUserFloat(string question)
{
    float respo;
    cout << question;
    cin >> respo;
    return respo;
}

char AskUserChar(string question)
{
    char respo;
    cout << question;
    cin >> respo;
    return respo;
}
