/* 
 * Author: Michael Risher
 * Purpose: 
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <cstdlib>    //Random Number Generator, Setting seed, etc....
#include <iomanip>    //Formatting Library
#include <string>     //String Library
#include <fstream>    // Reading and writing files
using namespace std;

//User Libraries
#include "CMovie.hpp"
//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes

//Execution begins here at main
int main(int argc, char** argv) {
    srand(time(0));
    
    //Variable Declarations
    string filename = "movies.dat";
    CMovie cmovie;//Class

    cmovie.outputToFile(filename);
    cmovie.readFromFile(filename);
    
    //Now you can loop on the data as many times as it takes!
    cmovie.display();//Look and see
    
    //Exit the Program
    return 0;
}