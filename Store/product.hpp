#ifndef Product_HPP
#define Product_HPP

#include <string>

using namespace std;

class Product {
private:
    int id;
    string name;
    string description;
    float price;
    int quantity;
    
public:
    Product(int id, string name, string description, float price, int quantity)
        : id(id), name(name), description(description), price(price), quantity(quantity) {}
    Product(string id, string name, string description, float price, int quantity)
    : id(stoi(id)), name(name), description(description), price(price), quantity(quantity) {}

    int getId() const { return id; }
    string getName() const { return name; }
    void setName(string n) {this->name = n;}
    string getDescription() const { return description; }
    void setDescription(string d) {this->description = d;}
    float getPrice() const { return price; }
    void setPrice(float p) {this->price = p;}
    int getQuantity() const { return quantity; }
    void setQuantity(int q) { quantity = q; }

    void display() const;
};


#endif