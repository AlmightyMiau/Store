#ifndef MovieInfo_HPP
#define MovieInfo_HPP

#include <iostream>

using namespace std;

struct MovieInfo {
    string title; //title of the movie
    char *director; //director of the movie as a char*
    unsigned short year; //year released
    unsigned short runtime; //duration in minutes
};

#endif /* MovieInfo_HPP */