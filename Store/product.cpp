#include <iostream>
#include <iomanip>

#include "product.hpp"

/// @brief Display all product properties
void Product::display() const {
    cout << "\nID: " << id << endl
         << "Name: " << name << endl
         << "Description: " << description << endl
         << "Price: $" << fixed << setprecision(2) << price << endl
         << "In Stock: " << quantity << "\n\n";
}