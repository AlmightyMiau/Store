#ifndef Product_HPP
#define Product_HPP

#include <string>

using namespace std;

/// @brief Holds id, name, description, price, and quantity of a product in the store
class Product {
private:
    int id;             ///< unique ID       (# >= 0) ex: 0
    string name;        ///< name            ex: Apple
    string description; ///< description     ex: Cosmic Crisp
    float price;        ///< price per unit  (float > 0) ex: 0.99
    int quantity;       ///< amount in store (# > 0) ex: 20
    
public:
    // Constructors
    /// @brief Initialize product with all properties
    /// @param id int or string id
    /// @param name string
    /// @param description string
    /// @param price float
    /// @param quantity int
    Product(int id, string name, string description, float price, int quantity)
        : id(id), name(name), description(description), price(price), quantity(quantity) {}
    /// @brief Initialize product with all properties
    /// @param id int or string id
    /// @param name string
    /// @param description string
    /// @param price float
    /// @param quantity int
    Product(string id, string name, string description, float price, int quantity)
    : id(stoi(id)), name(name), description(description), price(price), quantity(quantity) {}

    /// @brief Get id of this product
    /// @return int >= 0
    int getId() const { return id; }
    /// @brief Get name of this product
    /// @return string
    string getName() const { return name; }
    /// @brief Set name of this product
    /// @param n name (string)
    void setName(string n) {this->name = n;}
    /// @brief Get description of this product
    /// @return string
    string getDescription() const { return description; }
    /// @brief Set description of this product
    /// @param d description (string)
    void setDescription(string d) {this->description = d;}
    /// @brief Get price of this product
    /// @return float >= 0
    float getPrice() const { return price; }
    /// @brief Set price of this product 
    /// @param p price (float)
    void setPrice(float p) {this->price = p;}
    /// @brief Get amount of products
    /// @return int > 0
    int getQuantity() const { return quantity; }
    /// @brief Set amount of products
    /// @param q quantity (int)
    void setQuantity(int q) { quantity = q; }

    /// @brief Display all product properties
    void display() const;
};


#endif