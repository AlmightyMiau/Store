#ifndef Admin_HPP
#define Admin_HPP

#include <string>

using namespace std;

#include "storeFront.hpp"
class StoreFront;

/// @brief Create, delete, and edit products
/// @details Deeply tied to StoreFront
/// @see StoreFront
/// @see Product
class Admin {
	private:
		StoreFront* store;
		bool isAdmin = false;
	public:
		/// @brief Constructor to load store into scope
		/// @param sf Storefront object from main
		Admin(StoreFront* sf) : store(sf) {}
        /// @brief Create a new product and add to Storefront's inventory
        void newProduct();
		/// @brief Edit a product's information
		void editProduct();
		/// @brief Delete a product from Storefront's inventory
		void deleteProduct();
};

#endif