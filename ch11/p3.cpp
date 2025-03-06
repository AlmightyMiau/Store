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
struct Sales {
    float firstQuarterSales,
          secondQuarterSales,
          thirdQuarterSales,
          fourthQuarterSales;
};

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    Sales divisions[4];
    
    cout << fixed << setprecision(2);
    
    for (int i = 0; i < 4; i++) {
        switch (i) {
            case 0: cout << "North" << endl; break;
            case 1: cout << endl << "West" << endl; break;
            case 2: cout << endl << "East" << endl; break;
            case 3: cout << endl << "South" << endl; break;
        }
        cout << "Enter first-quarter sales:" << endl;
        cin >> divisions[i].firstQuarterSales;
        cout << "Enter second-quarter sales:" << endl;
        cin >> divisions[i].secondQuarterSales;
        cout << "Enter third-quarter sales:" << endl;
        cin >> divisions[i].thirdQuarterSales;
        cout << "Enter fourth-quarter sales:" << endl;
        cin >> divisions[i].fourthQuarterSales;
        cout << "Total Annual sales:$";
        cout << divisions[i].firstQuarterSales + 
                divisions[i].secondQuarterSales + 
                divisions[i].thirdQuarterSales + 
                divisions[i].fourthQuarterSales
        << endl;
        cout << "Average Quarterly Sales:$";
        cout << (divisions[i].firstQuarterSales + 
                divisions[i].secondQuarterSales + 
                divisions[i].thirdQuarterSales + 
                divisions[i].fourthQuarterSales) /
                4;
    }
    
    
    //Initialize Variables
    
    //Process or map Inputs to Outputs
    
    //Display Outputs

    //Exit stage right!
    return 0;
}