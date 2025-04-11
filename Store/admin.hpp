#ifndef Admin_HPP
#define Admin_HPP

#include <string>

using namespace std;

#include "storeFront.hpp"
class StoreFront;

// This needs to be able to see all products, edit products, and create new products
class Admin {
	private:
		StoreFront* store;
		bool isAdmin = false;
	public:
		Admin(StoreFront* sf) : store(sf) {}
		bool login(const string user, const string password);
        void newProduct(); // Create new product
		void editProduct(); // Edit a product
		void deleteProduct(); // Delete a product
		bool islogged() {return isAdmin;}; 
};

#endif