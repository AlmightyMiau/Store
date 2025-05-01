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
        void addUser(User& newUser); // returns a newly created user object
        bool login(User& newUser); // returns an already existing user object
        int userExists(string username); // Checks if username is in users[], returns index or -1
        void printUsers(User& currentUser); // Prints all user data, if user is admin
        void saveToFile() const;
        void loadFromFile();

        // Destructor (save current list of users to file)
        ~UserManagement() {saveToFile();};
};

#endif