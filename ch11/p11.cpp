/* 
 * File:   
 * Author: 
 * Created on 
 * Purpose:  
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
struct Budget {
    float housing,
          utilities,
          householdExpenses,
          transportation,
          food,
          medical,
          insurance,
          entertainment,
          clothing,
          misc;
};

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    Budget setBudget;
    Budget realBudget;
    float setTotal = 0;
    float realTotal = 0;
    
    //Initialize Variables
    setBudget = {
        500, // housing
        150, // utilities
        65,  // householdExpenses
        50,  // transportation
        250, // food
        30,  // medical
        100, // insurance
        150, // entertainment
        75,  // clothing
        50
    };
    
    cout << "Enter housing cost for the month:$\n"
         << "Enter utilities cost for the month:$\n"
         << "Enter household expenses cost for the month:$\n"
         << "Enter transportation cost for the month:$\n"
         << "Enter food cost for the month:$\n"
         << "Enter medical cost for the month:$\n"
         << "Enter insurance cost for the month:$\n"
         << "Enter entertainment cost for the month:$\n"
         << "Enter clothing cost for the month:$\n"
         << "Enter miscellaneous cost for the month:$\n";
    cin >> realBudget.housing
        >> realBudget.utilities
        >> realBudget.householdExpenses
        >> realBudget.transportation
        >> realBudget.food
        >> realBudget.medical
        >> realBudget.insurance
        >> realBudget.entertainment
        >> realBudget.clothing
        >> realBudget.misc;
    
    //Process or map Inputs to Outputs
    // Find set total budget
    setTotal += setBudget.housing;
    setTotal += setBudget.utilities;
    setTotal += setBudget.householdExpenses;
    setTotal += setBudget.transportation;
    setTotal += setBudget.food;
    setTotal += setBudget.medical;
    setTotal += setBudget.insurance;
    setTotal += setBudget.entertainment;
    setTotal += setBudget.clothing;
    setTotal += setBudget.misc;
    
    // Find real total budget
    realTotal += realBudget.housing;
    realTotal += realBudget.utilities;
    realTotal += realBudget.householdExpenses;
    realTotal += realBudget.transportation;
    realTotal += realBudget.food;
    realTotal += realBudget.medical;
    realTotal += realBudget.insurance;
    realTotal += realBudget.entertainment;
    realTotal += realBudget.clothing;
    realTotal += realBudget.misc;
    
    //Display Outputs
    cout << fixed << setprecision(2);
    cout << "Housing " << (realBudget.housing > setBudget.housing ? "Over" : (realBudget.housing < setBudget.housing ? "Under" : "Even")) << endl;
    cout << "Utilities " << (realBudget.utilities > setBudget.utilities ? "Over" : (realBudget.utilities < setBudget.utilities ? "Under" : "Even")) << endl;
    cout << "Household Expenses " << (realBudget.householdExpenses > setBudget.householdExpenses ? "Over" : (realBudget.householdExpenses < setBudget.householdExpenses ? "Under" : "Even")) << endl;
    cout << "Transportation " << (realBudget.transportation > setBudget.transportation ? "Over" : (realBudget.transportation < setBudget.transportation ? "Under" : "Even")) << endl;
    cout << "Food " << (realBudget.food > setBudget.food ? "Over" : (realBudget.food < setBudget.food ? "Under" : "Even")) << endl;
    cout << "Medical " << (realBudget.medical > setBudget.medical ? "Over" : (realBudget.medical < setBudget.medical ? "Under" : "Even")) << endl;
    cout << "Insurance " << (realBudget.insurance > setBudget.insurance ? "Over" : (realBudget.insurance < setBudget.insurance ? "Under" : "Even")) << endl;
    cout << "Entertainment " << (realBudget.entertainment > setBudget.entertainment ? "Over" : (realBudget.entertainment < setBudget.entertainment ? "Under" : "Even")) << endl;
    cout << "Clothing " << (realBudget.clothing > setBudget.clothing ? "Over" : (realBudget.clothing < setBudget.clothing ? "Under" : "Even")) << endl;
    cout << "Miscellaneous " << (realBudget.misc > setBudget.misc ? "Over" : (realBudget.misc < setBudget.misc ? "Under" : "Even")) << endl;
    
    cout << "You were $" << (realTotal > setTotal ? realTotal - setTotal : (realTotal < setTotal ? setTotal - realTotal : 0))
                         << (realTotal > setTotal ? " over budget" : (realTotal < setTotal ? " under budget" : " even"));
    //Exit stage right!
    return 0;
}