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

class StoreFront {
    private:
        vector<Product> inventory;
        ShoppingCart currentCart;
    
        void updateInventory();
    
    public:
        void loadProductsFromFile(const string& filename);
    
        void saveProductsToFile(const string& filename);
    
        void displayProductCatalog() const;
    
        Product* getProductById(const string& id);
    
        void processOrder();
    
        void processPayment(float amount);
    
        ShoppingCart& getCart() { return currentCart; }
};

#endif