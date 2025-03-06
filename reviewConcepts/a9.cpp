/* 
 * File:   main.cpp
 * Author: YOUR NAME HERE
 * Created on DATE AND TIME HERE
 * Purpose:  Input something, output it reversed with some modifications
 * Note:Range should be 5 digits, 321 = 00321 reverse = 12300 before subtraction
 *      12300 - 999 = 11301 after subtraction
 *      12300 = 00321 = 321 after reversal and no subtraction
 */

//System Libraries Here
#include <iostream>//cin,cout,endl
#include <cstring> //strlen()
using namespace std;
//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
bool  inRange(const char [],unsigned short &);//Output true,unsigned or false
bool  reverse(unsigned short,signed short &);//Output true,short or false
short subtrct(signed short,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;     //More than enough
    char  digits[SIZE];    //Character digits or not
    unsigned short unShort;//Unsigned short
    short snShort;         //Signed short
    
    //Input or initialize values Here
    cout<<"Reverse a number and subtract if possible."<<endl;
    cout<<"Input a number in the range of an unsigned short"<<endl;
    cin>>digits;
    
    //Test if it is in the Range of an unsigned short
    if(!inRange(digits,unShort)){
        cout<<"No Conversion Possible"<<endl;
        return 0;
    }
    
    //Reverse and see if it falls in the range of an signed short
    if(!reverse(unShort,snShort)){
        cout<<"No Conversion Possible"<<endl;
        return 0;
    }
    
    //Now subtract if the result is not negative else don't subtract
    snShort=subtrct(snShort,999);
    
    //Output the result
    cout<<snShort<<endl;
    
    //Exit
    return 0;
}


// Catch incompatible inputs
// if (input > 65535) { cout << "No Conversion Possible" << endl; }
// try { unsigned short int output = <unsigned short int>input } catch { cout << "No Conversion Possible" << endl; }

//Output true,unsigned or false
bool  inRange(const char digits[], unsigned short &unShort) {
    unsigned short limit = -1; // Find upper limit of ushort
    unShort = 0;
    short tempDigit = 0;
    
    // convert digits to int
    for (int i = 0; digits[i] != '\u0000'; i++) {
        // convert char num to int num
        tempDigit = (digits[i] - 48);
        if (tempDigit > 9 || tempDigit < 0) { return false; }
        unShort = 10 * unShort + tempDigit;
    }
    if (unShort > limit) { return false; }
    return true;
}

//Output true,short or false
bool  reverse(unsigned short unShort, signed short &snShort) {
    // output each digit individually in reverse order
    for (int i = 1; i < 65535; i*=10) {
        if (snShort * 10 + unShort / i % 10 > 32767) { return false; }
        snShort = snShort * 10 + unShort / i % 10;
    }
    return true;
}

short subtrct(signed short snShort, int limit) {
    signed short output;
    snShort - limit > 0 ? output = snShort - limit : output = snShort;
    return output;
}