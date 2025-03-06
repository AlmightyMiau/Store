/* 
 * Note:  This time you create the strcmp() function that takes into
 * account the new sort order.
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
using namespace std;

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;//Only 20 required, and 1 for null terminator

//Function Prototypes Here
int  read(char [][COLMAX],int &);//Outputs row and columns detected from input
void sort(char [][COLMAX],int,int,const char[],const char[]);//Sort by row using strcmp();
void print(const char [][COLMAX],int,int);//Print the sorted 2-D array
//int strcmp(char a[],char b[],char replace[],char with[]){
int strcmp(char [],char [],const char [],const char []);//Replace sort order

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=30;             //Only 20 required
    char array[ROW][COLMAX];      //Bigger than necessary 
    int colIn,colDet,rowIn,rowDet;//Row, Col input and detected
    char replace[COLMAX],with[COLMAX];//New sort order
    
    //Input the new sort order then sort
    cout<<"Modify the sort order by swapping these characters."<<endl;
    cin>>replace;
    cout<<"With the following characters"<<endl;
    cin>>with;
    cout<<"Read in a 2 dimensional array of characters and sort by Row"<<endl;
    cout<<"Input the number of rows <= 20"<<endl;
    cin>>rowIn;
    cout<<"Input the maximum number of columns <=20"<<endl;
    cin>>colIn;
    
    //Now read in the array of characters and determine it's size
    rowDet=rowIn;
    cout<<"Now input the array."<<endl;
    colDet=read(array,rowDet);
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size
    //if(rowDet==rowIn&&colDet==colIn){
        sort(array,rowIn,colIn,replace,with);
        cout<<"The Sorted Array"<<endl;
        print(array,rowIn,colIn);
    
    //Exit
    return 0;
}

//Outputs row and columns detected from input
int  read(char array[][COLMAX],int &rowCount) {
    int colDet = 0;
    
    // While there are more lines
    int i = 0;
    while (cin >> array[i]) {
        strlen(array[i]) > colDet ? colDet = strlen(array[i]) : colDet = colDet;
        i++;
    }
    // If given row count is incorrect, fix it
    if (rowCount != i) {
        rowCount = i;
    }
    return colDet;
}

//Sort by row using strcmp()
void sort(char array[][COLMAX], int rows, int cols, const char replace[], const char with[]) {
    char lowstr[cols];
    // Selection sort
    for (int i = 0; i < rows; i++) {
        strcpy(lowstr, array[i]);
        int lowrow = i;
        for (int j = i; j < rows; j++) {
            if (strcmp(lowstr, array[j], replace, with) > 0) {
                strcpy(lowstr, array[j]);
                lowrow = j;
            }
        }
        strcpy(array[lowrow], array[i]);
        strcpy(array[i], lowstr);
    }
    
}

//Print the sorted 2-D array
void print(const char array[][COLMAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        cout << array[i] << endl;
    }
}

//Replace sort order
int strcmp(char a[], char b[], const char replace[], const char with[]) {
    char A[strlen(a)+1]; strcpy(A, a);
    char B[strlen(b)+1]; strcpy(B, b);
    int result = 0;
    
    // replace array chars with new ones
    for (int i = 0; A[i] != '\0'; i++) {
        for (int j = 0; replace[j] != '\0'; j++) {
            if (A[i] == replace[j]) {
                A[i] = with[j];
                break; // continue to next a[] letter
            }
        }
    }
    for (int i = 0; B[i] != '\0'; i++) {
        for (int j = 0; replace[j] != '\0'; j++) {
            if (B[i] == replace[j]) {
                B[i] = with[j];
                break; // continue to next b[] letter
            }
        }
    }
    
    // for the whole length of the longer array
    int i = 0;
    while (A[i] != '\0' && B[i] != '\0') {
        if (A[i] < B[i]) {
            return -1;
        } else if (A[i] > B[i]) {
            return 1;
        }
        i++;
    }
    
    // one is prefix of the other
    if (A[i] == '\0' && B[i] != '\0') {
        return -1;
    } else if (A[i] != '\0' && B[i] == '\0') {
        return 1;
    }
    
    return result;
}