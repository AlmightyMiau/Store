#include "userManagement.hpp"

#include <fstream>
#include <iostream>

// Save users to users.dat file
void UserManagement::saveToFile() const{
    std::ofstream file(filename, std::ios::binary);
    int strLen;

    // Write number of users
    int size = users.size();
    file.write(reinterpret_cast<char*>(&size), sizeof(size)); // REMEMBER TO USE &SIZE AND NOT JUST SIZE :(

    for (int i = 0; i < size; i++) {
        strLen = users[i].getUsername().size();
        file.write(reinterpret_cast<const char*>(&strLen), sizeof(strLen));
        file.write(users[i].getUsername().c_str(),strLen);

        strLen = users[i].getPassword().size();
        file.write(reinterpret_cast<const char*>(&strLen), sizeof(strLen));
        file.write(users[i].getPassword().c_str(),strLen);

        bool admin = users[i].getAdmin();
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
        User tempUser;
        file.read(reinterpret_cast<char*>(&strLen),sizeof(strLen));
        temp = new char[strLen +1];
        file.read(temp,strLen);
        temp[strLen] = '\0';
        tempUser.setUsername(std::string(temp));
        delete [] temp;

        file.read(reinterpret_cast<char*>(&strLen),sizeof(strLen));
        temp = new char[strLen +1];
        file.read(temp,strLen);
        temp[strLen] = '\0';
        tempUser.setPassword(std::string(temp));
        delete [] temp;

        int admin;
        file.read(reinterpret_cast<char*>(&admin), sizeof(admin));
        tempUser.setAdmin(admin);

        users.push_back(tempUser);
}
    file.close();
}

// Create a new user
void UserManagement::addUser() {
    User newUser;
    string username;
    string password;
    bool taken = false;

    // Get new username
    do {
        cout << "Creating new account\nEnter Username: ";
        cin >> username;

        // Make sure it isn't already in use
        for (const auto& user : users) {
            if (username == user.getUsername()) {
                cout << "Username is already in use" << endl;
                taken = true;
                break;
            }
        }
        
    } while (taken);
    // Set username
    newUser.setUsername(username);

    // Get new password
    cout << "Enter Password: ";
    cin >> password;
    newUser.setPassword(password);

    // if user is admin, give it admin
    if (newUser.getUsername() == "admin") {
        newUser.setAdmin(true);
    }

    // Add new user to list of users
    cout << users.size();
    users.push_back(newUser);
    cout << users.size();
    saveToFile(); // Save after every change :3
}