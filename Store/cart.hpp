#ifndef Cart_HPP
#define Cart_HPP

#include "product.hpp"
#include <vector>

class ShoppingCart {
    private:
        // Key-value pairs of Product and Quantity being bought (not always needed)
        vector<Product> products;
        vector<int> productCounts;
    
    public:
        void addItem(Product product, int quantity);
    
        void removeItem(Product* product, int quantity);
    
        float calculateTotal() const;
    
        void displayCart() const;
    
        void clearCart() { products.clear(); productCounts.clear(); }

        
        // Returns vector of products, quantity of products
        vector<Product>* getItems() { return &products; }
        vector<int>* getItemQuantities() { return &productCounts; }

        int findItem(Product* product);
};

#endif