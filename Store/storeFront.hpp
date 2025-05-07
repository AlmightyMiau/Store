#ifndef StoreFront_HPP
#define StoreFront_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <sstream> ///< @include stringstream for getting info from txt file

using namespace std;

#include "cart.hpp"
#include "product.hpp"
#include "admin.hpp"

/// @brief Storefront holding the current cart and the store inventory
/// @see ShoppingCart
/// @see Product
/// @see Admin
class StoreFront {
    private:
        ShoppingCart currentCart;         /// @brief Cart of current user
        string filename = "products.txt"; /// @brief File of product data

        /// @brief Remove items in cart from inventory (by amounts)
        void updateInventory();

        friend class Admin; // This user is able to edit products
    
    protected:
        /// @brief List of products in inventory
        vector<Product> inventory;

        /// @brief Get list of products in inventory
        /// @return Vector of products
        vector<Product>& getInventory() { return inventory; };
    
    public:
        /// @brief Load products' data from file 
        void loadProductsFromFile();

        /// @brief Save products' data to file
        void saveProductsToFile();

        /// @brief Display all product properties
        void displayProductCatalog();

        /// @brief Get product object from id
        /// @param id int id of product
        /// @return Product
        Product* getProductById(const int& id);

        /// @brief Updates inventory, saves inventory, clears cart
        void processOrder();

        /// @brief Get cart data 
        /// @return ShoppingCart: 2 lists of products and quantities respectively
        ShoppingCart& getCart() { return currentCart; }
};

#endif