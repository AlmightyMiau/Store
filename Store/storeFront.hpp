#ifndef StoreFront_HPP
#define StoreFront_HPP

#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

#include "cart.hpp"
#include "product.hpp"
#include "admin.hpp"

class StoreFront {
    private:
        ShoppingCart currentCart;
        string filename = "products.txt";
        void updateInventory();

        friend class Admin;
    
    protected:
        vector<Product> inventory;

        vector<Product>& getInventory() { return inventory; };
    
    public:

        void loadProductsFromFile();
    
        void saveProductsToFile();
    
        void displayProductCatalog();
    
        Product* getProductById(const int& id);
    
        void processOrder();
    
        void processPayment(float amount);
    
        ShoppingCart& getCart() { return currentCart; }

};

#endif