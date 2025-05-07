#include "userManagement.hpp"

#include <fstream>
#include <iostream>
#include <filesystem> // remove() a file as part of deleting users

// Save users to users.dat file
void UserManagement::saveToFile() const{
    std::ofstream file(filename, std::ios::binary);
    int strLen;

    // Write number of users
    int size = users.size();
    file.write(reinterpret_cast<char*>(&size), sizeof(size)); // REMEMBER TO USE &SIZE AND NOT JUST SIZE :(

    for (int i = 0; i < size; i++) {
        // Username
        strLen = users[i].getUsername().size();
        file.write(reinterpret_cast<const char*>(&strLen), sizeof(strLen));
        file.write(users[i].getUsername().c_str(),strLen);

        // Password
        strLen = users[i].getPassword().size();
        file.write(reinterpret_cast<const char*>(&strLen), sizeof(strLen));
        file.write(users[i].getPassword().c_str(),strLen);

        // Is bool
        bool admin = users[i].isAdmin();
        file.write(reinterpret_cast<const char*>(&admin),sizeof(admin));
    }
    file.close();
}

// Load users from users.dat file
void UserManagement::loadFromFile() {
    std::ifstream file((filename), std::ios::binary);
    if (!file.good()) {
        // It should create an admin account
        cout << "file " << filename << ".dat is empty or does not exist" << endl;
        return;
    }
    int strLen;
    char *temp;

    // Read number of users
    int size;
    file.read(reinterpret_cast<char*>(&size), sizeof(size));

    for (int i = 0; i < size; i++) {
        // Username
        User tempUser;
        file.read(reinterpret_cast<char*>(&strLen),sizeof(strLen));
        temp = new char[strLen +1];
        file.read(temp,strLen);
        temp[strLen] = '\0';
        tempUser.setUsername(std::string(temp));
        delete [] temp;

        // Password
        file.read(reinterpret_cast<char*>(&strLen),sizeof(strLen));
        temp = new char[strLen +1];
        file.read(temp,strLen);
        temp[strLen] = '\0';
        tempUser.setPassword(std::string(temp));
        delete [] temp;

        // Is admin
        bool admin;
        file.read(reinterpret_cast<char*>(&admin), sizeof(admin));
        tempUser.setAdmin(admin);

        users.push_back(tempUser);
    }
    file.close();

    // If users is empty, create an admin user, and a guest user
    if (users.size() == 0) {
        User admin("admin","admin",true);
        User guest("guest","guest");
        users.push_back(admin);
        users.push_back(guest);
        saveToFile();
    }
}

// Create a new user
void UserManagement::addUser(User& newUser) {
    string username;
    string password;
    int index = -1;

    // Get new username
    cout << "Creating new account" << endl;
    do {
        cout << "Enter Username: ";
        cin >> username;

        if (username == "0") {return;} // Exit function

        index = userExists(username);
        if (index != -1) {cout << "Username is already in use" << endl;}
        
    } while (index != -1);
    // Set username
    newUser.setUsername(username);

    // Get new password
    cout << "Enter Password: ";
    cin >> password;

    if (username == "0") {return;} // Exit function

    newUser.setPassword(password);

    // if user is admin, give it admin
    if (newUser.getUsername() == "admin") {
        newUser.setAdmin(true);
    }

    // Add new user to list of users
    cout << "Success! New user \"" << newUser.getUsername() << "\" created" << endl;
    users.push_back(newUser);
    saveToFile(); // Save after every change :3
    return;
}

// Delete a user specified by index of user
void UserManagement::deleteUser(int index) {
    // Find that given user exists
    if (index != userExists(users[index].getUsername())) { // If not found, display error message and end function
        cout << "User "
             << users[index].getUsername()
             << " not found in list"
             << endl;
        return;
    }

    string username = users[index].getUsername();

    // Ask for confirmation to delete user
    char verify;
    cout << "Are you sure you want to delete "
         << username
         << "'s account? (y/n) ";
    cin >> verify;

    if (verify == 'y') {
        cout << "\nDeleting user '"
             << username
             << "'"
             << endl;
        // Delete user file
        string filename = username + ".dat";
        cout << "Deleting file " << filename << endl;
        // Won't work if the file is currently open by something !!!!
        cout << 
            ((remove(reinterpret_cast<char*>(&filename)) == 0) 
            ? "Successfully deleted file" 
            : "\nERROR: Failed to delete file\n")
        << endl;
        // Erases given user from users vector
        users.erase(users.begin() + index);
        saveToFile();
    } else {
        cout << "Canceling action" << endl;
    }

}

bool UserManagement::login(User& newUser) {
    string username;
    string password;
    int index;
    
    // Keep trying until success
    do {
        // Get username
        do {
            cout << "Username: ";
            cin >> username;

            if (username == "0") {return false;} // Exit function

            // Get index of user in array
            index = userExists(username);
            if (index == -1) {cout << "Invalid username" << endl;}
        } while (index == -1);

        // Get password
        cout << "Password: ";
        cin >> password;

        if (password == "0") {return false;} // Exit function

        if (password == users[index].getPassword()) {
            cout << "Succesfully logged in as " << users[index].getUsername() << endl;
            newUser = users[index];
            newUser.setLogged(true);
            return true;
        } else {
            cout << "Incorrect Password" << endl;
        }
        // What do if no log in? Keep trying
    } while (password != users[index].getPassword());
    return false;
}

// Returns index of given user in users vector
// Returns -1 if not found
int UserManagement::userExists(string username) {
    int index = -1;
    // Search array for username
    for (int i = 0; i < users.size(); i++) {
        if (username == users[i].getUsername()) {
            index = i;
            break;
        }
    }
    return index;
}

void UserManagement::printUsers(User& currentUser) {
    for (int i = 0; i < users.size(); i++) {
        cout << "User #" << i << '\n'
             << "Username:     " << users[i].getUsername() << '\n'
             << "Password:     " << users[i].getPassword() << '\n'
             << "Admin:        " << (users[i].isAdmin() ? "true" : "false" ) << '\n'
             << "Is Logged in: "  << ((currentUser.getUsername() == users[i].getUsername()) 
                                      ? (currentUser.isLogged() ? "true" : "false" ) 
                                      : "false") << '\n'
             << endl;
    }
}