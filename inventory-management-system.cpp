#include<iostream>
#include<vector>
#include<string>
using namespace std;

class InventoryItem {                                                                                                 //class
private:
    int id;
    string name;

public:
    InventoryItem(int id, string name) : id(id), name(name) {}                                                 // constructors

    int getId() const {                                                                                       //get() manipulators
        return id;
    }

    void setId(int id) {                                                                                 //set() manipulators
        this->id = id;
    }

    string getName() const {
        return name;
    }

    void setName(string name) {
        this->name = name;
    }
};

class Product : public InventoryItem {                                                                  // concept of Inheritance 
private:
    string category;
    double price;
    int quantity;

public:
    Product(int id, string name, string category, double price, int quantity)
        : InventoryItem(id, name), category(category), price(price), quantity(quantity) {}

    string getCategory() const {
        return category;
    }

    void setCategory(string category) {
        this->category = category;
    }

    double getPrice() const {
        return price;
    }

    void setPrice(double price) {
        this->price = price;
    }

    int getQuantity() const {
        return quantity;
    }

    void setQuantity(int quantity) {
        this->quantity = quantity;
    }
};

class Inventory {
private:
    vector<Product> products;

public:
    void addProduct(Product product) {
        bool found = false;
        for (auto& p : products) {
            if (p.getId() == product.getId()) {
                cout << "Id already Exist." << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            products.push_back(product);
            cout << "Product added successfully." << endl;
            cout << "-----------------------------------------------------------" << endl;
        }
    }

    void removeProduct(int id) {
        bool found = false;
        for (auto i = products.begin(); i != products.end(); i++) {
            if (i->getId() == id) {
                products.erase(i);
                found = true;
                cout << "Product removed successfully." << endl;
                cout << "-----------------------------------------------------------" << endl;
                break;
            }
        }
        if (!found) {
            cout << "Id does not exist" << endl;
        }
    }

    Product* findProduct(int id) {
        for (auto i = products.begin(); i != products.end(); i++) {
            if (i->getId() == id) {
                return &(*i);
            }
        }
        return nullptr;
    }
    void updateProduct(int id, const std::string& name) {                                                                     //function overloading
    bool found = false;
    for (auto& product : products) {
        if (product.getId() == id) {
            product.setName(name);
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "ID does not exist." << endl;
    }
}
       void updateProduct(int id, int quantity) {                                                                           //function overloading
         bool found = false;
          for (auto& product : products) {
              if (product.getId() == id) {
                product.setQuantity(quantity);
                found = true;
                break;
           }
         }
        if (!found) {
            cout << "ID does not exist." << endl;
         }
    }


        void updateProduct(int id, const std::string& name, const std::string& category,     double price, int quantity) {               //function overloading
          bool found = false;
          for (auto& product : products) {
             if (product.getId() == id) {
                    product.setName(name);
                   product.setCategory(category);
                   product.setPrice(price);
                    product.setQuantity(quantity);
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "ID does not exist." << endl;
            }
        }

    void printProduct() const {
        for (auto i = products.begin(); i != products.end(); i++) {
            cout << "ID : " << i->getId() << endl;
            cout << "Name : " << i->getName() << endl;
            cout << "Category : " << i->getCategory() << endl;
            cout << "Price : $ " << i->getPrice() << endl;
            cout << "Quantity : " << i->getQuantity() << endl;
        }
    }
};

int main() {
    Inventory inventory;
    cout << "-----------------------------------------------------------" << endl;
    cout << "---------------Inventory Management System ----------------" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "------------------------- Welcome! ------------------------" << endl;
    cout << "-----------------------------------------------------------" << endl;
    char choice;
    do {
        cout << "Please choose an option:" << endl;
        cout << "1. Add a product" << endl;
        cout << "2. Remove a product" << endl;
        cout << "3. Find a product" << endl;
        cout << "4. Update a product" << endl;
        cout << "5. View all products" << endl;
        cout << "Q. Quit" << endl;
        cin >> choice;

        switch (choice) {
        case '1': {
            int id;
            string name, category;
            double price;
            int quantity;
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter product name: ";
            cin >> name;
            cout << "Enter product category: ";
            cin >> category;
            cout << "Enter product price: $ ";
            cin >> price;
            cout << "Enter product quantity: ";
            cin >> quantity;
            Product product(id, name, category, price, quantity);
            inventory.addProduct(product);
            break;
        }

        case '2': {
            int id;
            cout << "Enter product id: ";
            cin >> id;
            inventory.removeProduct(id);
            break;
        }

        case '3': {
            int id;
            cout << "Enter product id: ";
            cin >> id;
            Product* product = inventory.findProduct(id);
            if (product) {
                cout << "Name: " << product->getName() << endl;
                cout << "Category: " << product->getCategory() << endl;
                cout << "Price: $ " << product->getPrice() << endl;
                cout << "Quantity: " << product->getQuantity() << endl;
                cout << "-----------------------------------------------------------" << endl;
            } else {
                cout << "Product not found." << endl;
                cout << "-----------------------------------------------------------" << endl;
            }
            break;
        }

        case '4': {
            cout << "1. Update only Name" << endl << "2. Update all details" << endl << "3.Update Quantity only"<<endl;
            int l;
            cin >> l;
            if (l == 2) {
                int id;
                string name, category;
                double price;
                int quantity;
                cout << "Enter the product id: ";
                cin >> id;
                cout << "Enter new product name: ";
                cin >> name;
                cout << "Enter new product category: ";
                cin >> category;
                cout << "Enter new product price: $ ";
                cin >> price;
                cout << "Enter new product quantity: ";
                cin >> quantity;
                inventory.updateProduct(id, name, category, price, quantity);
                cout << "Product updated successfully." << endl;
                cout << "-----------------------------------------------------------" << endl;
            } else if (l == 1) {
                int id;
                string name;
                cout << "Enter the product id: ";
                cin >> id;
                cout << "Enter new product name: ";
                cin >> name;
                inventory.updateProduct(id, name);
                cout << "Product updated successfully." << endl;
                cout << "-----------------------------------------------------------" << endl;
            }
            else if(l==3)
            {
               int id; 
               string name;
               int quantity;
               cout << "Enter the product id: ";
                cin >> id;
                 cout << "Enter new product quantity: ";
                cin >> quantity;
                inventory.updateProduct(id,quantity);
                cout << "Product updated successfully." << endl;
                cout << "-----------------------------------------------------------" << endl;
            }
            break;
        }

        case '5': {
            inventory.printProduct();
            break;
        }
        case 'q':
        case 'Q':
            cout << "Goodbye!" << endl;
            cout << "-----------------------------------------------------------" << endl;
            return 0;

        default:
            cout << "Invalid Choice. Please Try again" << endl;
            cout << "-----------------------------------------------------------" << endl;
            break;
        }
    } while (true);

    return 0;
}

