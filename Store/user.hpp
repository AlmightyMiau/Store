#ifndef User_HPP
#define User_HPP

#include <string>

#include "cart.hpp"

class User{
    private:
        std::string username;
        std::string password;
        bool admin;
    public:
        //setters
        void setUsername(const std::string &username){this->username = username;}
        void setPassword(const std::string &password){this->password = password;}
        void setAdmin(bool admin){this->admin = admin;}

        void saveCartToFile(ShoppingCart& cart) const;
        void loadCartFromFile(ShoppingCart& cart);

        //getters
        const std::string& getUsername() const{return username;}
        const std::string& getPassword() const{return password;}
        bool getAdmin() const{return admin;}
};

#endif