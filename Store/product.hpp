#ifndef Product_HPP
#define Product_HPP

#include <string>

using namespace std;

class Product {
private:
    string id;
    string name;
    string description;
    float price;
    int quantity;
    
public:
    Product(string id, string name, string description, float price, int quantity)
        : id(id), name(name), description(description), price(price), quantity(quantity) {}

    string getId() const { return id; }
    string getName() const { return name; }
    string getDescription() const { return description; }
    float getPrice() const { return price; }
    int getQuantity() const { return quantity; }
    void setQuantity(int q) { quantity = q; }

    void display() const;
};


#endif