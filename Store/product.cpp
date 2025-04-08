#include <iostream>
#include <iomanip>

#include "product.hpp"

void Product::display() const {
    cout << "ID: " << id << endl
            << "Name: " << name << endl
            << "Description: " << description << endl
            << "Price: $" << fixed << setprecision(2) << price << endl
            << "In Stock: " << quantity << "\n\n";
}