#ifndef User_HPP
#define User_HPP

#include <string>

using namespace std;

#include "cart.hpp"

/// @brief Represents a user, with username password, and if they are admin
/// @see ShoppingCart
class User{
    private:
        string username; // Username of user
        string password; // Password of user
        bool admin;      // If user is admin 
        bool logged;     // If user is currently logged in
    public:
        /// @brief Default constructor
        User(){};
        /// @brief Constructor to set username and password
        /// @param u username
        /// @param p password
        User(string u, string p) {username = u; password = p; admin = false;}
        /// @brief Constructor to set username, password, and if user is admin
        /// @param u username
        /// @param p password
        /// @param a Is admin? (bool)
        User(string u, string p, bool a) {username = u; password = p; admin = a;}

        /// @brief Set username of this user
        /// @param username New username (string)
        void setUsername(const string &username){this->username = username;}
        /// @brief Set password of this user
        /// @param password New password (string)
        void setPassword(const string &password){this->password = password;}
        /// @brief Set if this user is admin or not
        /// @param admin Is admin? true/false
        void setAdmin(bool admin){this->admin = admin;}
        /// @brief Set if this user is logged in
        /// @param logged Is logged in? true/false
        void setLogged(bool logged) {this->logged = logged;}

        /// @brief Clear user data
        /// @details Used on currentUser in main
        void logout();

        /// @brief Save cart info to file
        /// @details file saved to is "[username].dat"
        /// @param cart ShoppingCart to save
        void saveCartToFile(ShoppingCart& cart) const;
        /// @brief Load cart info from file
        /// @details file loaded from is "[username].dat"
        /// @param cart ShoppingCart to load data into
        void loadCartFromFile(ShoppingCart& cart);

        /// @brief Get username of this user
        /// @return username - string
        const string& getUsername() const{return username;}
        /// @brief Get password of this user
        /// @return password - string
        const string& getPassword() const{return password;}
        /// @brief Get if this user is admin or not
        /// @return Is admin? true/false
        bool isAdmin() const{return admin;}
        /// @brief Get if this user is logged in or not
        /// @return Is logged in? true/false
        bool isLogged() {return logged;}
};

#endif