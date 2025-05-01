#ifndef User_HPP
#define User_HPP

#include <string>

#include "cart.hpp"

class User{
    private:
        std::string username;
        std::string password;
        bool admin;
        bool logged;
    public:
        // Constructors
        User(){};
        User(string u, string p) {username = u; password = p; admin = false;}
        User(string u, string p, bool a) {username = u; password = p; admin = a;}
        //setters
        void setUsername(const std::string &username){this->username = username;}
        void setPassword(const std::string &password){this->password = password;}
        void setAdmin(bool admin){this->admin = admin;}
        void setLogged(bool logged) {this->logged = logged;}

        void logout();

        void saveCartToFile(ShoppingCart& cart) const;
        void loadCartFromFile(ShoppingCart& cart);

        //getters
        const std::string& getUsername() const{return username;}
        const std::string& getPassword() const{return password;}
        bool isAdmin() const{return admin;}
        bool isLogged() {return logged;}
};

#endif