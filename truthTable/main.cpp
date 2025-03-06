/* 
 * File:   main.cpp
 * Author:
 * Created on:
 * Purpose:  To tell the Truth
 */
 
 // This took 10 minutes

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    bool x,y;
    int size = 0;
    
    //Display the Heading
    cout<<"X Y !X !Y X&&Y X||Y X^Y X^Y^X X^Y^Y !(X&&Y) !X||!Y "<<
          " !(X||Y) !X&&!Y"<<endl;
    
    cin >> size;
    for (int i = 0; i < size; i++) {
        cin >> x >> y;
        cout<<(x?'T':'F')<<" "
            <<(y?'T':'F')<<"  "
            << (!x?'T':'F') << "  "
            << (!y?'T':'F') << "   "
            << (x&&y?'T':'F') << "    "
            << (x||y?'T':'F') << "   "
            << (x&&!y||!x&&y?'T':'F') << "    "
            << (x&&y||y?'T':'F') << "     "
            << (x&&y||x?'T':'F') << "       "
            << (!(x&&y)?'T':'F') << "      "
            << (!x||!y?'T':'F') << "        "
            << (!(x||y)?'T':'F') << "      "
            << (!x&&!y?'T':'F')
            <<endl;
    }
    //First Row
    
    //Second Row
    //etc

    //Exit
    return 0;
}