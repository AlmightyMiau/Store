/* 
 * File:   
 * Author: 
 * Created on 
 * Purpose:  
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//User Libraries
struct Weather {
    string month;
    float rain;
    int high;
    int low;
    int avgTemp;
};

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    Weather weather[12]; // Weather for a given month
    float totalRain, avgRain;
    int high, low, avgTemp;
    int numMonths = 0;
    
    //Initialize Variables
    
    //Process or map Inputs to Outputs
    // Input all weather data
    while (cin >> weather[numMonths].month) {
        cin >> weather[numMonths].rain;
        cin >> weather[numMonths].low;
        cin >> weather[numMonths].high;
        weather[numMonths].avgTemp = (weather[numMonths].high + weather[numMonths].low) / 2;
        numMonths++;
    }
    
    // Get average rain, highest temp, lowest temp, average temp
    high = 0;
    low = 0;
    for (int i = 0; i < numMonths; i++) {
        totalRain += weather[i].rain;
        weather[low].low > weather[i].low ? low = i : low;
        weather[high].high < weather[i].high ? high = i : high;
    }
    avgRain = totalRain / numMonths;
    avgTemp = (weather[high].high + weather[low].low) / 2 + 1;
    
    //Display Outputs
    cout << fixed << setprecision(1);
    cout << "Average Rainfall " << avgRain << " inches/month" << endl;
    cout << "Lowest  Temperature " << left << setw(7) << weather[low].month << right << setw(4) << weather[low].low << " Degrees Fahrenheit" << endl;
    cout << "Highest Temperature " << left << setw(7) << weather[high].month << right << setw(4) << weather[high].high << " Degrees Fahrenheit" << endl;
    cout << "Average Temperature for the year " << avgTemp << " Degrees Fahrenheit" << endl;

    //Exit stage right!
    return 0;
}