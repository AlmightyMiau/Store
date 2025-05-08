#ifndef UserManagement_HPP
#define Usermanagement_HPP

#include <vector>

using namespace std;

#include "user.hpp"

/// @brief Manages any users in program
/// @see User
class UserManagement{
    private:
        string filename = "users.dat"; // File to save list of users to
        vector<User> users;            // List of users
    public:
        /// @brief Create a new user, and add to the list
        /// @param newUser - User object to hold data in (empty)
        void addUser(User& newUser); // returns a newly created user object
        /// @brief Delete a user from the list
        /// @param index - Location of user in this objects vector
        /// @see userExists() for index of user
        void deleteUser(int index); // removes a user from users
        /// @brief Login as a user, and return user data in newUser
        /// @param newUser - User object to hold user data in (empty)
        /// @return Successfully logged in?
        bool login(User& newUser); // returns an already existing user object
        /// @brief Searches through list of users for one with same username
        /// @param username of user to find index of 
        /// @return (int) Location of user in list, or -1 if not found
        int userExists(string username); // Checks if username is in users[], returns index or -1
        /// @brief Displays all users' info, if currentUser is admin
        /// @param currentUser - user calling this function (to check if is admin)
        void printUsers(User& currentUser); // Prints all user data, if user is admin
        /// @brief Save list of users to file "users.dat"
        /// @details User data stored as username length, username, password length, password, true/false is admin?, consecutively for each user, with number of users at start of file
        void saveToFile() const;
        /// @brief Load list of users from file "users.dat"
        void loadFromFile();

        /// Destructor (save current list of users to file)
        ~UserManagement() {saveToFile();};
};

#endif