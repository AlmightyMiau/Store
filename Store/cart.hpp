#ifndef Cart_HPP
#define Cart_HPP

#include "product.hpp"
#include <map>

class ShoppingCart {
    private:
        map<Product*, int> items;
    
    public:
        void addItem(Product* product, int quantity);
    
        void removeItem(Product* product, int quantity);
    
        float calculateTotal() const;
    
        void displayCart() const;
    
        void clearCart() { items.clear(); }

        const map<Product*, int>& getItems() const;
};

#endif