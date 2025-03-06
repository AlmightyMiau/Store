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
struct Weather {
    float rain;
    int high;
    int low;
};
enum Months {
    JANUARY,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
};

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    Weather weather[6]; // Weather for a given month
    float totalRain, avgRain, sumHigh, sumLow, avgTemp;
    int high, low;
    int numMonths = 0;
    
    //Initialize Variables
    
    //Process or map Inputs to Outputs
    // Input all weather data
    while (cin >> weather[numMonths].rain) {
        cout << "Enter the total rainfall for the month:" << endl;
        cout << "Enter the high temp:" << endl;
        cin >> weather[numMonths].high;
        cout << "Enter the low temp:" << endl;
        cin >> weather[numMonths].low;
        numMonths++;
    }
    
    // Get average rain, highest temp, lowest temp, average temp
    high = weather[JANUARY].high;
    low = weather[JANUARY].low;
    for (int i = JANUARY; i < numMonths; i++) {
        totalRain += weather[i].rain;
        sumHigh += weather[i].high;
        sumLow += weather[i].low;
        low > weather[i].low ? low = weather[i].low : low;
        high < weather[i].high ? high = weather[i].high : high;
    }
    avgRain = totalRain / numMonths;
    avgTemp = (sumHigh + sumLow) / 2 / numMonths;
    
    //Display Outputs
    cout << fixed << setprecision(2);
    cout << "Average monthly rainfall:" << avgRain << endl;
    cout << "High Temp:" << high << endl;
    cout << "Low Temp:" << low << endl;
    cout << setprecision(1);
    cout << "Average Temp:" << avgTemp;

    //Exit stage right!
    return 0;
}