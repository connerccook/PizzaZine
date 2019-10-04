#pragma once

#include <fstream>
#include <sstream>
#include <string>

#include "Location.h"

using std::getline;
using std::ifstream;
using std::stringstream;
using std::string;


class PizzaZine {
private:
    Location* pizzaLocations; // member variables
    size_t size;

public:
    PizzaZine(); //default constructor
    PizzaZine(const size_t &size); //constructor with parameters
    ~PizzaZine(); // destructor

    Location& operator[](const size_t &i); //operator function

    // This function is implemented for you
    void readInFile(const string&);
};

     PizzaZine::PizzaZine(){ //default constructor sets size to equal 50
       pizzaLocations = new Location[size=50];
       this->size = 50;
     }
     PizzaZine::PizzaZine(const size_t &size){ //constructor with paramters sets size to the inputted size
       pizzaLocations = new Location[size];
       this -> size = size;
     }
     PizzaZine::~PizzaZine() { //destructor
       delete [] pizzaLocations;
     }
Location& PizzaZine::operator[](const size_t &i){ //returns the indicated index
       return pizzaLocations[i];
     }

void PizzaZine::readInFile(const string& filename) {
    ifstream inFile(filename);
    Location newLoc;

    string line;
    string cell;

    // Read each line
    for (int i = 0; i < size; ++i) {
        // Break each line up into 'cells'
        getline(inFile, line);
        stringstream lineStream(line);
        while(getline(lineStream, newLoc.name, ',')) {
            getline(lineStream, newLoc.address, ',');
            getline(lineStream, newLoc.city, ',');
            getline(lineStream, cell, ',');
            if (!cell.empty()) {
                newLoc.postalCode = stoul(cell);
            }

            getline(lineStream, newLoc.province, ',');
            getline(lineStream, cell, ',');
            newLoc.latitude = stod(cell);
            getline(lineStream, cell, ',');
            newLoc.longitude = stod(cell);

            newLoc.priceRangeMin = -1;
            getline(lineStream, cell, ',');
            if (!cell.empty()) {
                newLoc.priceRangeMin = stoul(cell);
            }

            newLoc.priceRangeMax = -1;
            getline(lineStream, cell, ',');
            if (!cell.empty() && cell != "\r") {
                newLoc.priceRangeMax = stoul(cell);
            }
            pizzaLocations[i] = newLoc;
        }
    }
}
