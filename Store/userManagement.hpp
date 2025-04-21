#ifndef UserManagement_HPP
#define Usermanagement_HPP

#include <vector>

using namespace std;

#include "user.hpp"

class UserManagement{
    private:
        string filename = "users.dat";
        vector<User> users;
    public:
        void addUser();
        void saveToFile() const;
        void loadFromFile();

        // Destructor (save current list of users to file)
        ~UserManagement() {saveToFile();};
};

#endif