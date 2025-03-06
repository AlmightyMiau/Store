/* 
 * File:   main.cpp
 * Author: YOUR NAME HERE
 * Created on DATE AND TIME HERE
 * Purpose:  Even, Odd Vectors and Array Columns Even, Odd
 * Note:  Check out content of Sample conditions in Hacker Rank
 * Input size of integer array, then array, output columns of Even, Odd
 * Vectors then Even, Odd 2-D Array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <vector>  //vectors<>
#include <iomanip> //Format setw(),right
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=2;//Only 2 columns needed, even and odd

//Function Prototypes Here
void read(vector<int> &, vector<int> &);
void copy(vector<int>, vector<int>,int [][COLMAX]);
void prntVec(vector<int>, vector<int>,int n);//int n is the format setw(n)
void prntAry(const int [][COLMAX],int,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //No more than 80 rows
    int array[ROW][COLMAX];     //Really, just an 80x2 array, even vs. odd
    vector<int> even(0),odd(0); //Declare even,odd vectors
    
    //Input data and place even in one vector odd in the other
    read(even,odd);
    
    //Now output the content of the vectors
    //          setw(10)
    prntVec(even,odd,10);//Input even, odd vectors with setw(10);
    
    //Copy the vectors into the 2 dimensional array
    copy(even,odd,array);
    
    //Now output the content of the array
    //                              setw(10)
    prntAry(array,even.size(),odd.size(),10);//Same format as even/odd vectors
    
    //Exit
    return 0;
}


void read(vector<int> &even, vector<int> &odd) {
    // Get size
    int size = 0;
    cout << "Input the number of integers to input." << endl;
    cin >> size;
    
    cout << "Input each number." << endl;
    int num = 0;
    while (cin >> num) {
        if (num % 2) { // == 1 is odd
            odd.push_back(num);
        } else {
            even.push_back(num);
        }
    }
}
void prntVec(vector<int> even, vector<int> odd, int n) {//int n is the format setw(n)
    // Print message header
    cout << right << setw(n) << "Vector" << setw(n) << "Even" << setw(n) << "Odd" << endl;
    
    // Find max vector length
    int size = 0;
    even.size() > odd.size() ? size = even.size() : size = odd.size();
    
    // Print each row
    // setw(2n), even[i], odd[i]
    // if no even[i] skip it, if no odd[i] skip it, if neither end loop
    for (int i = 0; i < size; i++) {
        cout << setw(2 * n);
        
        // If even[i] exists 
        try { cout << even.at(i); } 
        catch (const out_of_range& e) { cout << ' '; }
        cout << setw(n);
        
        // If odd[i] exists
        try { cout << odd.at(i); } 
        catch (const out_of_range& e) { cout << ' '; }
        cout << endl;
    }
}
void copy(vector<int> even, vector<int> odd, int array[][COLMAX]) {
    int size = 0;
    even.size() > odd.size() ? size = even.size() : size = odd.size();
    
    // Copy each row from parallel vectors to 2d array
    // if no even[i] skip it, if no odd[i] skip it
    for (int i = 0; i < size; i++) {
        // If even[i] exists 
        try { array[i][0] = even.at(i); } 
        catch (const out_of_range& e) { }
        
        // If odd[i] exists
        try {array[i][1] = odd.at(i); } 
        catch (const out_of_range& e) { }
    }
}
void prntAry(const int array[][COLMAX], int evenSize, int oddSize, int n) {
    // Print message header
    cout << right << setw(n) << "Array" << setw(n) << "Even" << setw(n) << "Odd" << endl;
    
    int size = 0;
    evenSize > oddSize ? size = evenSize : size = oddSize;
    // Print array
    for (int i = 0; i < size; i++) {
        cout << setw(2 * n);
        
        // If even[i] exists 
        if (i < evenSize) { cout << array[i][0]; }
        else { cout << ' '; }
        cout << setw(n);
        
        // If odd[i] exists
        if (i < oddSize) { cout << array[i][1]; }
        else { cout << ' '; }
        cout << endl;
    }
}