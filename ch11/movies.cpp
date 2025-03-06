#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct MovieData {
    string title;
    string director;
    int year;
    int length;
};

int main(){
    MovieData* movies;
	int count;
	cin >> count;
	
	movies = new MovieData[count];
	for (int i = 0; i < count; i++) {
	    cin.ignore();
	    getline(cin, movies[i].title);
	    getline(cin, movies[i].director);
	    cin >> movies[i].year
	        >> movies[i].length;
	}
	
	// Display movies
	cout << left;
	cout << "This program reviews structures\nInput how many movies, the Title of the Movie, Director, Year Released, and the Running Time in (minutes).\n";
	for (int i = 0; i < count; i++) {
	    cout << endl;
	    cout << setw(11) << "Title: " << movies[i].title << endl;
	    cout << setw(11) << "Director: " << movies[i].director << endl;
	    cout << setw(11) << "Year: " << movies[i].year << endl;
	    cout << setw(11) << "Length: " << movies[i].length << endl;
	}
	
	
	return 0;
}