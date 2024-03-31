#include <vector>
#include <string>
using namespace std;

#ifndef SHIP_H
#define SHIP_H

class Ship{
	public:
		Ship() { name = "none"; start = 0; spaces.push_back(0); }  // Ship default constructor
		Ship(string shipType, string startPos, string direction);  // Ship normal constructor
		int SpaceConverter(string space);			   // Conversion function
		void PrintSpaces();					   // Prints the spaces that the ship lies on
		int GetSpace(int position);				   // Gets one of the spaces that the ship lies on
		int GetSize();						   // Gets the size of the ship
		string GetName();					   // Gets the ship type
		int GetStart();						   // Gets the starting position
		string GetDirection();					   // Gets the direction its facing
		string GetStartString();				   // Gets the starting position as a string coord

	private:
		vector<int> spaces;					   // The vector holding the values of the coords the ship lies on
		string name;						   // The ship type
		int start;						   // The ship starting coord as a meaningful number
		string startString;					   // The strating position as a string coord
		string direction;					   // The starting direction

};

#endif
