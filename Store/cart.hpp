#ifndef Cart_HPP
#define Cart_HPP

#include <vector>

#include "product.hpp"

/// @brief Cart holding products with amounts
/// @see Product
class ShoppingCart {
    private:
        // Key-value pairs of Product and Quantity being bought
        vector<Product> products;  ///< List of products in cart 
        vector<int> productCounts; ///< Amounts of respective products
    
    public:
        /// @brief Add a product to cart
        /// @param product object with id, name, description, price, total amount
        /// @see Product
        /// @param quantity amount of product to add
        void addItem(Product product, int quantity);

        /// @brief Remove an item from cart 
        /// @attention Currently unused
        /// @param product Product to remove from cart
        void removeItem(Product* product);

        /// @brief Calculate total cost of items in cart
        /// @return sum of all item's price * amount (ex: [0.99 * 5] + [1.49 * 3])
        float calculateTotal() const;

        /// @brief Display all items in cart (product propertes & quantities)
        void displayCart() const;

        /// @brief Clear cart of all items
        /// @details clears both vectors of all data
        void clearCart() { products.clear(); productCounts.clear(); }
        

        /// @brief Get list of products in cart
        /// @return Vector of products
        vector<Product>* getItems() { return &products; }
        /// @brief Get list of amounts of products in cart
        /// @return Vector of ints
        vector<int>* getItemQuantities() { return &productCounts; }

        /// @brief Find index of product in list 
        /// @param product Product to find location of
        /// @return (int) index of product, or -1 if not found
        int findItem(Product* product);
};

#endif