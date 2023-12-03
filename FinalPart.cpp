#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

struct Product
{
    string productName;
    string productBrand;
    string productCategory;
    double productPrice;
    int productID;
};

const int maxProduct = 50;
int productCount = 0;
Product productList[maxProduct];
Product productChosen;
bool productIsChosen = false;

void predefinedProduct()
{
    productList[productCount++] = {"ASUS TUF F15 FX506HC", "ASUS", "Laptop", 1199.99, 115};
    productList[productCount++] = {"Lenovo LOQ 15 IRH-8", "LENOVO", "Laptop", 1399.90, 105};
    productList[productCount++] = {"Nokia 106 Dual Sim", "NOKIA", "Handphone", 399.90, 201};
    productList[productCount++] = {"HUAWEI Band 8", "HUAWEI", "Smartwatch", 599.90, 345};
    productList[productCount++] = {"Kingston SSD A400 480GB", "KINGSTON", "SSD", 499.90, 401};
    productList[productCount++] = {"Resistor 1k", "RESISTOR", "Komponen", 500.00, 115};
    productList[productCount++] = {"MSI Katana GF66", "MSI", "Laptop", 13000000, 116};
    productList[productCount++] = {"Acer Aspire 5", "ACER", "Laptop", 10000000, 125};
    productList[productCount++] = {"GoPro Hero 6", "GOPRO", "ActionCam", 299, 501};
    productList[productCount++] = {"DJI Osmo 3", "DJI", "Gymbal", 199, 502};
    productList[productCount++] = {"Acer Aspire 7", "ACER", "Laptop", 500, 127};
    //...
}

void displayProducts()
{
    cout << "Available products : " << endl;
    for (int i = 0; i < productCount; i++)
    {
        cout << "Name : " << productList[i].productName;
        cout << ", Brand : " << productList[i].productBrand;
        cout << ", category : " << productList[i].productCategory;
        cout << ", price : $" << productList[i].productPrice;
        cout << ", ID : " << productList[i].productID << endl;
    }
    cout << endl;
}

void displayByCategory(int typeCategory)
{
    if (typeCategory > 0 && typeCategory <= 7)
    {
        cout << "Products in the selected category : " << endl;
        for (int i = 0; i < productCount; i++)
        {
            if (typeCategory == 1 && productList[i].productCategory == "Laptop")
            {
                cout << "Name : " << productList[i].productName;
                cout << ", Brand : " << productList[i].productBrand;
                cout << ", Category : " << productList[i].productCategory;
                cout << ", Price : $" << productList[i].productPrice;
                cout << ", ID : " << productList[i].productID << endl;
            }
            else if (typeCategory == 2 && productList[i].productCategory == "Handphone")
            {
                cout << "Name : " << productList[i].productName;
                cout << ", Brand : " << productList[i].productBrand;
                cout << ", Category : " << productList[i].productCategory;
                cout << ", Price : $" << productList[i].productPrice;
                cout << ", ID : " << productList[i].productID << endl;
            }
            else if (typeCategory == 3 && productList[i].productCategory == "Smartwatch")
            {
                cout << "Name : " << productList[i].productName;
                cout << ", Brand : " << productList[i].productBrand;
                cout << ", Category : " << productList[i].productCategory;
                cout << ", Price : $" << productList[i].productPrice;
                cout << ", ID : " << productList[i].productID << endl;
            }
            else if (typeCategory == 4 && productList[i].productCategory == "SSD")
            {
                cout << "Name : " << productList[i].productName;
                cout << ", Brand : " << productList[i].productBrand;
                cout << ", Category : " << productList[i].productCategory;
                cout << ", Price : $" << productList[i].productPrice;
                cout << ", ID : " << productList[i].productID << endl;
            }
            else if (typeCategory == 5 && productList[i].productCategory == "Komponen")
            {
                cout << "Name : " << productList[i].productName;
                cout << ", Brand : " << productList[i].productBrand;
                cout << ", Category : " << productList[i].productCategory;
                cout << ", Price : $" << productList[i].productPrice;
                cout << ", ID : " << productList[i].productID << endl;
            }
            else if (typeCategory == 6 && productList[i].productCategory == "ActionCam")
            {
                cout << "Name : " << productList[i].productName;
                cout << ", Brand : " << productList[i].productBrand;
                cout << ", Category : " << productList[i].productCategory;
                cout << ", Price : $" << productList[i].productPrice;
                cout << ", ID : " << productList[i].productID << endl;
            }
            else if (typeCategory == 7 && productList[i].productCategory == "Gymbal")
            {
                cout << "Name : " << productList[i].productName;
                cout << ", Brand : " << productList[i].productBrand;
                cout << ", Category : " << productList[i].productCategory;
                cout << ", Price : $" << productList[i].productPrice;
                cout << ", ID : " << productList[i].productID << endl;
            }
        }
    }
    else
    {
        cout << "ENTER THE AVAILABLE CATEGORIES!!!!!!!!!";
    }
    cout << endl;
}

void displayByBrand(string brand)
{
    cout << "Products by the selected brand : " << endl;
    for (int i = 0; i < productCount; i++)
    {
        if (productList[i].productBrand == brand)
        {
            cout << "Name : " << productList[i].productName;
            cout << ", Brand : " << productList[i].productBrand;
            cout << ", Category : " << productList[i].productCategory;
            cout << ", Price : $" << productList[i].productPrice;
            cout << ", ID : " << productList[i].productID << endl;
        }
    }
    cout << endl;
}

void displayByPrice()
{
    // Copying productList to tempProductList to not tampering with displayProduct index
    Product tempProductList[productCount];
    Product tempKey;
    for (int i = 0; i < productCount; i++)
    {
        tempProductList[i] = productList[i];
    }

    int key, j = productCount;
    for (int i = 1; i < productCount; i++)
    {
        key = tempProductList[i].productPrice;
        tempKey = tempProductList[i];
        j = i - 1;

        while (j >= 0 && tempProductList[j].productPrice > key)
        {
            tempProductList[j + 1] = tempProductList[j];
            j = j - 1;
        }
        tempProductList[j + 1] = tempKey;
    }

    cout << "Available products : " << endl;
    for (int i = 0; i < productCount; i++)
    {
        cout << "Name : " << tempProductList[i].productName;
        cout << ", Brand : " << tempProductList[i].productBrand;
        cout << ", category : " << tempProductList[i].productCategory;
        cout << ", price : $" << tempProductList[i].productPrice;
        cout << ", ID : " << tempProductList[i].productID << endl;
    }
    cout << endl;
}

const int maxCartSize = 10;
Product cart[maxCartSize];
int cartSize = 0;

void addToCart(const Product &product)
{
    if (cartSize < maxCartSize)
    {
        cart[cartSize++] = product;
        cout << "Product '" << product.productName << "' added to the cart!" << endl;
    }
    else
    {
        cout << "The cart is full. Cannot add more products." << endl;
    }
}

void displayCart()
{
    cout << "Products in the cart:" << endl;
    if (cartSize == 0)
    {
        cout << "cart is empty, do mind to add your favoured products into the cart\n";
    }
    else
    {
        for (int i = 0; i < cartSize; i++)
        {
            cout << "Name: " << cart[i].productName;
            cout << ", Brand: " << cart[i].productBrand;
            cout << ", Category: " << cart[i].productCategory;
            cout << ", Price: $" << cart[i].productPrice;
            cout << ", ID: " << cart[i].productID << endl;
        }
    }
    cout << endl;
}

struct User
{
    string userName, userPass;
};

User singleUser = {"user1", "awikwok1"};

bool userAuthentication(string userName, string userPass)
{
    if (singleUser.userName == userName && singleUser.userPass == userPass)
    {
        return true;
    }
    else
    {
        return false;
    }
    return false;
}

void searchProduct()
{
    string search;
    cout << "Enter Product name : ";
    cin.ignore();
    getline(cin, search);
    bool found = false;
    for (auto &x : search)
    {
        x = tolower(x);
    }
    string temp;
    for (int i = 0; i < productCount; i++)
    {
        temp = productList[i].productName;
        for (auto &x : temp)
        {
            x = tolower(x);
        }
        if (temp.find(search) != string::npos)
        {
            cout << productList[i].productName << endl;
            cout << "Brand\t\t: " << productList[i].productBrand << endl;
            cout << "Category\t: " << productList[i].productCategory << endl;
            cout << "Price\t\t: " << productList[i].productPrice << endl;
            cout << "Product ID\t: " << productList[i].productID << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Product out of stock\n";
    }
}

void Qris()
{
    cout << " ▌│█║▌║▌║ \n";
    cout << " ▌║▌│█║▌║ \n";
    cout << " ▌║║▌║▌║║ \n";
    cout << endl;
}

void Transfer()
{
    cout << "please perform transfer to this number below \n";
    cout << "98253894\n";
}

bool transaction()
{
    int payOption;
    do
    {
        cout << "Select payment Method\n";
        cout << "1. Qris\n";
        cout << "2. transfer\n";
        cout << "3. Back\n";
        cout << "Enter your option = ";
        cin >> payOption;

        switch (payOption)
        {
        case 1:
            Qris();
            return true;
            break;

        case 2:
            Transfer();
            return true;
            break;
        case 3:
            cout << "proceed to homepage \n";
            return false;
            break;
        default:
            cout << "Invalid option, please select again \n";
            return false;
            break;
        }
    } while (payOption != 3);
}

void buyProduct()
{

    if (cartSize > 0)
    {
        cout << "Purchased products : " << endl;
        for (int i = 0; i < cartSize; i++)
        {
            cout << "Name : " << cart[i].productName << endl;
            cout << "Brand : " << cart[i].productBrand << endl;
            cout << "Category : " << cart[i].productCategory << endl;
            cout << endl;
        }
        bool transacSuccess = transaction();

        if (transacSuccess)
        {
            cout << "Transaction complete! Thank you for using our service\n\n";
            cartSize = 0;
        }
        else
        {
            cout << "Transaction canceled\n\n";
        }
    }
    else
    {
        cout << "The cart is empty, please add products before performing a purchase" << endl;
    }
}

int main()
{
    predefinedProduct();
    string username, password;

    cout << "=== Welcome to TronHUB ===" << endl;
    do
    {
        cout << "Enter your username : ";
        cin >> username;
        cout << "Enter your password : ";
        cin >> password;

        if (!userAuthentication(username, password))
        {
            cout << "Invalid username or password" << endl;
        }
    } while (!userAuthentication(username, password));
    cout << "login successful!" << endl;
    int option;
    do
    {
        cout << "Home Page" << endl;
        cout << "1. Display all available Products" << endl;
        cout << "2. Display Products by category" << endl;
        cout << "3. Display Products by brand" << endl;
        cout << "4. Display Product by Price" << endl;
        cout << "5. Add products to cart" << endl;
        cout << "6. Display products from the cart" << endl;
        cout << "7. Search products" << endl;
        cout << "8. Buy Products" << endl;
        cout << "9. Exit" << endl;
        cout << "please select your choice = ";
        cin >> option;

        switch (option)
        {
        case 1:
            displayProducts();
            break;
        case 2:
        {
            int categoryOption;
            cout << "Enter category option: " << endl;
            cout << "1. Laptop\n2. Handphone\n3. Smartwatch\n4. SSD\n5. Komponen\n6. ActionCam\n7. Gymbal" << endl;
            cin >> categoryOption;
            displayByCategory(categoryOption);
            break;
        }

        case 3:
        {
            string brand;
            cout << "Enter brand: ";
            cin >> brand;
            displayByBrand(brand);
            break;
        }
        case 4:
            displayByPrice();
            break;
        case 5:
            int productID;
            cout << "Enter the product ID to add to the cart: ";
            cin >> productID;

            for (int i = 0; i < productCount; i++)
            {
                if (productList[i].productID == productID)
                {
                    addToCart(productList[i]);
                    break;
                }
            }
            break;
        case 6:
            displayCart();
            break;
        case 7:
            searchProduct();
            break;
        case 8:
            buyProduct();
            break;
        case 9:
            cout << "exiting the program, goodbye";
            break;
        default:
            cout << "Invalid Option, please select the available option\n";
            break;
        }
    } while (option != 9);
} // program is finally finished

/* I appreciate for all of my teammate who kindly works on this project and patiently resolves
 all of the error and missed-details on this program.
 i sincerely apologize whether there were any miscommunication, inefficient perfomance, or any other issues
 while working on this project. I would like to specially thank albatani for making the ppt only in one night
 for the next day presentation simultaneously with the reports as well

 with the end of production of the project, i hereby declare that this project has finally come to an end

 thank you for all of your contributions while making this project,
 thank you for all of the enthusiasts during the production
 see you guys in the next semester on our hopefully next brighter year  */
