#ifndef User_HPP
#define User_HPP

#include <string>

using namespace std;

#include "cart.hpp"

/// @brief A single user entity
class User{
    private:
        string username; /// @brief Username of user
        string password; /// @brief Password of user
        bool admin;      /// @brief If user is admin 
        bool logged;     /// @brief If user is currently logged in
    public:
        // Constructors
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

        /// @brief 
        /// @param username 
        void setUsername(const string &username){this->username = username;}
        void setPassword(const string &password){this->password = password;}
        void setAdmin(bool admin){this->admin = admin;}
        void setLogged(bool logged) {this->logged = logged;}

        void logout();

        void saveCartToFile(ShoppingCart& cart) const;
        void loadCartFromFile(ShoppingCart& cart);

        //getters
        const string& getUsername() const{return username;}
        const string& getPassword() const{return password;}
        bool isAdmin() const{return admin;}
        bool isLogged() {return logged;}
};

#endif