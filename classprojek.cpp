#include <iostream>
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
    productList[productCount++] = {"Resistor 1k", "Resistor", "Komponen", 500.00, 115};
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

void displayByCategory(int Typecategory)
{
    // ---
}

const int maxCartSize = 10;
Product cart[maxCartSize];
int cartSize = 0;

void addToCart(const Product& product)
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
    for (int i = 0; i < cartSize; i++)
    {
        cout << "Name: " << cart[i].productName;
        cout << ", Brand: " << cart[i].productBrand;
        cout << ", Category: " << cart[i].productCategory;
        cout << ", Price: $" << cart[i].productPrice;
        cout << ", ID: " << cart[i].productID << endl;
    }
    cout << endl;
}


void displayByPrice() {
    // Copying productList to tempProductList to not tampering with displayProduct index
    Product tempProductList[productCount];
    Product tempKey;
    for (int i = 0; i < productCount; i++) {
        tempProductList[i] = productList[i];
    }

    int key, j = productCount;
    for (int i = 1; i < productCount; i++) {
        key = tempProductList[i].productPrice;
        tempKey = tempProductList[i];
        j = i - 1;

        while (j >= 0 && tempProductList[j].productPrice > key) {
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
        cout << "6. Buy products from the cart" << endl;
        cout << "7. Exit" << endl;
        cout << "please select your choice = ";
        cin >> option;

        switch (option)
        {
        case 1:
            displayProducts();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            displayByPrice();
            break;
        case 5:
        {
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
        }
        case 6:
        displayCart();
        break;
        case 7:
            cout << "exiting the program, goodbye";
            break;
        }
    } while (option != 7);
} //program is still yet to finish
