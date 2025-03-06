#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Structures
struct Drink {
    string name;
    int cost;
    int count;
};

// Function Prototypes
// Input array of soda, number of types of soda, and selected soda name
// Output index of selected soda
int WhichSoda (Drink soda[5], string selected, int types);
// Input array of soda, number of types of soda
// Display Menu listing sodas with cost and number left
void DisplayMenu (Drink soda[5], int types);

int main(){
    // Declare and Initialize Soda Array
    Drink soda[5] = {
        {
            "Cola",
            75,
            20
        },
        {
            "Root Beer",
            75,
            20
        },
        {
            "Lemon-Lime",
            75,
            20
        },
        {
            "Grape Soda",
            80,
            20
        },
        {
            "Cream Soda",
            80,
            20
        }
    };
    string selectedName;
    int selectedSoda = 0;
    int inputMoney = 0; // in cents; 95 = $0.95
    int totalCost = 0;
    
    // First Menu
    DisplayMenu(soda, 5);
    
    // Program loop
    getline(cin, selectedName, '\n');
    // cin >> selectedName;
    while (selectedName != "Quit") {
        // Find which soda was selected
        selectedSoda = WhichSoda(soda, selectedName, 5);
        cin >> inputMoney;
        // Dispense soda
        soda[selectedSoda].count--;
        // Dispense change
        totalCost += soda[selectedSoda].cost;
        cout << inputMoney - soda[selectedSoda].cost << endl;
        
        // Display Menu and get new soda
        DisplayMenu(soda, 5);
        cin.ignore();
        getline(cin, selectedName, '\n');
        // cin >> selectedName;
        // selectedName = "Quit";
    }
    cout << totalCost << endl;
    
	return 0;
}


// Input array of soda, number of types of soda, and selected soda name
// Output index of selected soda
int WhichSoda(Drink soda[5], string selected, int types) {
    for (int i = 0; i < types; i++) {
        if (selected == soda[i].name) {
            return i;
        }
    }
    return -1;
}

// Input array of soda, number of types of soda
// Display Menu listing sodas with cost and number left
void DisplayMenu (Drink soda[5], int types) {
    cout << left << fixed << setprecision(2);
    for (int i = 0; i < types; i++) {
        cout << setw(11) << soda[i].name << setw(4) << soda[i].cost << soda[i].count << endl; 
    }
    cout << "Quit" << endl;
}