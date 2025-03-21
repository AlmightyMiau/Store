#ifndef CMovie_HPP
#define CMovie_HPP

#include "MovieInfo.hpp"

using namespace std;

class CMovie {
    private: 
        MovieInfo *movies;//Pointer to the dynamic Movie structure.
        int nMovies;//Number of movies in the structure.
    public: 
        CMovie();//Constructor
        CMovie(const CMovie &);//Copy Constructor
        CMovie operator=(const CMovie &);//Chain Equality Operator
        ~CMovie();//Destructor
        void display();//Display
        int getNMovies() const { return nMovies; }//Get the number of movies
        void setNMovies(int n) { nMovies = n; }//Set the number of movies
        void outputToFile (string filename); // Open [filename] in output binary mode, output this object's nMovies and movies[] (convergted into bytes)
        void readFromFile (string filename); // Read file "movies.dat" in input binary mode, input into this object's nMovies and movies[] (converted from bytes)
};


#endif /* CMovie_HPP */