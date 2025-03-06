/* 
 * Purpose:  Searching for multiple occurrence of patterns
 * Note:  cout proceeds to null terminator, cin reads to end of line
 *        for character arrays
 * 
 */

//System Libraries Here
#include <iostream>//cin,cout,getline()
#include <cstring> //strlen()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//PI, e, Gravity, or conversions

//Function Prototypes Begins Here
//srch1 utility function Input->start position, Output->position found or not
//srch1 is a simple linear search function, repeat in srchAll till all found
//srch1 Input->sentence, pattern, start position Output-> position found
//Remember arrays start at index/position 0
//srchAll Input->sentence, pattern Output->position array
int  srch1(const char [],const char [],int);//Search for 1 occurrence
void srchAll(const char [],const char [],int []);//Search for all occurrences
void print(const char []);//Print the character arrays
void print(const int []); //Print the array of indexes where the pattern found

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int LINE=81;               //Size of sentence or pattern to find
    char sntnce[LINE],pattern[LINE]; //80 + null terminator
    int match[LINE];                 //Index array where pattern was found
    
    //Input a sentence and a pattern to match
    cout<<"Match a pattern in a sentence."<<endl;
    cout<<"Input a sentence"<<endl;
    cin.getline(sntnce,LINE);
    cout<<"Input a pattern."<<endl;
    cin.getline(pattern,LINE);
    
    //Search for the pattern
    //Input the sentence and pattern, Output the matching positions
    //Remember, indexing starts at 0 for arrays.
    srchAll(sntnce,pattern,match);
    
    //Display the inputs and the Outputs
    cout<<endl<<"The sentence and the pattern"<<endl;
    print(sntnce);
    print(pattern);
    cout<<"The positions where the pattern matched"<<endl;
    print(match);
    
    //Exit
    return 0;
}


//srch1 utility function Input->start position, Output->position found or not
//srch1 is a simple linear search function, repeat in srchAll till all found
//srch1 Input->sentence, pattern, start position Output-> position found
//Remember arrays start at index/position 0
//srchAll Input->sentence, pattern Output->position array

//Search for 1 occurrence
int srch1(const char sntnce[], const char pattern[], int start) {
    // Look through sentence for first letter
    // After finding first matching letter, directly compare the next letters,
    // until either pattern has a \0 or they don't match in a different way
    for (int i = start; sntnce[i] != '\0'; i++) {
        if (pattern[0] == sntnce[i]) {
            for (int j = 0; pattern[j] == sntnce[i + j]; j++) {
                if (pattern[j + 1] == '\0') {
                    return i;
                }
            }
        }
    }
    return -1;
}

//Search for all occurrences
void srchAll(const char sntnce[], const char pattern[], int match[]) {
    match[0] = -1;
    int i = 0;
    int index = srch1(sntnce, pattern, 0);
    match[i] = index;
    while (index != -1) {
        i++;
        index = srch1(sntnce, pattern, index + 1);
        match[i] = index;
    }
}

//Print the character arrays
// sntnce & pattern
void print(const char phrase[]) {
    cout << phrase << endl;
}

//Print the array of indexes where the pattern found
// match
void print(const int match[]) {
    if (match[0] != -1) {
       for (int i = 0; match[i] != -1; i++) {
           cout << match[i] << endl;
       } 
    } else {
        cout << "None" << endl;
    }
}