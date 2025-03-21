#include <iostream>   //I/O Library
#include <cstdlib>    //Random Number Generator, Setting seed, etc....
#include <iomanip>    //Formatting Library
#include <fstream>    // Reading and writing to files
#include <cstring>    // Get length of director name
using namespace std;  //Libraries compiled under std


#include "CMovie.hpp"

CMovie::CMovie(){
    
    //I copied the output from Code-E so I wouldn't make any typing mistakes
    //Then I just formatted.
    cout <<"This program reviews structures" << endl;
    cout <<"Input how many movies, the Title of the Movie, Director, Year "<<
          "Released, and the Running Time in (minutes)." << endl;
    cin >> nMovies;                //Integer Read
    // nMovies = rand() % 100;
    //Declare the Structure array
    movies = new MovieInfo[nMovies];   //dynamic Array

    //Now you can loop on the data as many times as it takes!
    for(int i = 0; i < nMovies; i++){
        cin.ignore();              //Oh Yea, Gotta do this for the buffer
        cout << "Title: ";
        getline( cin, movies[i].title );//Movie Name In an Array Structure
        cout << movies[i].title << endl;
        int size=81;//Make it Dynamic
        movies[i].director = new char[size];
        cout << "Director: ";
        cin.getline( movies[i].director, size - 1 );//Array Structure element
        cout << movies[i].director << endl;
        cout << "Year: ";
        cin >> movies[i].year; //Look ma, no ignore after gets!!!!
        cout << movies[i].year << endl;
        cout << "Length: ";
        cin >> movies[i].runtime;//Look again,no ignore after gets,only before
        cout << movies[i].runtime << endl;
    }
}

CMovie::CMovie(const CMovie &){ //copy constructor
    //TODO you can fill this up
}

CMovie CMovie::operator=(const CMovie &obj){
    //todo you can fill this up
    return obj;
}

CMovie::~CMovie(){
    //Clean Up the Dynamic Stuff
    delete [] movies;
}

void CMovie::display(){
    int n = 0;
    cout << "Select record 0 to " << nMovies - 1 << ": ";
    cin >> n;
    cout << n << endl;
    // n = rand() % nMovies;

    if (n != -1) {
        // Display specified record
        cout << left << endl;
        cout << setw(11) << "Title:" << movies[n].title << endl;
        cout << setw(11) << "Director:" << movies[n].director << endl;
        cout << setw(11) << "Year:" << movies[n].year << endl;
        cout << setw(11) << "Length:" << movies[n].runtime << endl;
    } else {
        for (int i = 0; i < nMovies; i++) {
            cout << left << endl;
            cout << setw(11) << "Title:" << movies[i].title << endl;
            cout << setw(11) << "Director:" << movies[i].director << endl;
            cout << setw(11) << "Year:" << movies[i].year << endl;
            cout << setw(11) << "Length:" << movies[i].runtime << endl;
        }
    }
}

void CMovie::outputToFile (string filename) {

    ofstream outfile(filename, ios::binary);

    outfile.write(reinterpret_cast<char*>(&(nMovies)), sizeof(nMovies));

    for (int i = 0; i < nMovies; i++) {
        // Get title length
        int titleLen = this->movies[i].title.size();
        // Write title length
        outfile.write(reinterpret_cast<char*>(&titleLen), sizeof(titleLen));
        // Write title
        outfile.write(this->movies[i].title.c_str(), titleLen); // Use titleLen NOT sizeof(titleLen) -_-

        // Get director name
        int dirLen = strlen(this->movies[i].director);
        // Write director length
        outfile.write(reinterpret_cast<char*>(&dirLen), sizeof(dirLen));
        // Write director
        outfile.write(this->movies[i].director, dirLen);

        // Write year
        outfile.write(reinterpret_cast<char*>(&this->movies[i].year), sizeof(this->movies[i].year));
        // Write runtime 
        outfile.write(reinterpret_cast<char*>(&this->movies[i].runtime), sizeof(this->movies[i].runtime));
    }
}

void CMovie::readFromFile (string filename) {
    ifstream infile(filename, ios::binary);

    infile.read(reinterpret_cast<char*>(&(nMovies)), sizeof(nMovies));

    for (int i = 0; i < nMovies; i++) {
        delete [] this->movies[i].director;
    }
    delete [] movies;
    movies = new MovieInfo[nMovies];

    for (int i = 0; i < nMovies; i++) {
        // Title
        // Read length of title
        int titleLen = 7; // temp number to hold length of title 
        infile.read(reinterpret_cast<char*>(&titleLen), sizeof(titleLen));
        // Read title into temp cstring
        char* tempTitle = new char[titleLen + 1];  // temp char* with space for string terminator
        infile.read(tempTitle, titleLen);          // Read title into tempTitle with length of titleLen
        tempTitle[titleLen] = '\0';                // Append a null terminator (to turn it into a string)
        this->movies[i].title = string(tempTitle);       // convert to string and put in movies
        delete [] tempTitle;                       // delete temp title name

        // Director
        // Read length of director name
        int dirLen; // temp number to hold length of title 
        infile.read(reinterpret_cast<char*>(&dirLen), sizeof(dirLen)); 
        // Make director name a new cstring
        // delete [] movies[i].director;            // Delete old director string
        this->movies[i].director = new char [dirLen];  // Create new director string with space for '\0'
        infile.read(this->movies[i].director, dirLen); // Read title into tempTitle with length of titleLen
        this->movies[i].director[dirLen] = '\0';
        // Year
        infile.read(reinterpret_cast<char*>(&this->movies[i].year), sizeof(this->movies[i].year)); 
        // Runtime
        infile.read(reinterpret_cast<char*>(&this->movies[i].runtime), sizeof(this->movies[i].runtime)); 
    }
}