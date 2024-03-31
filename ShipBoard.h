#include "Ship.h"
#include "Board.h"
#include <vector>
using namespace std;

#ifndef SHIPBOARD_H
#define SHIPBOARD_H

class ShipBoard : public Board {
	public:
		ShipBoard(string playerType);	// Constructor for the ShipBoard
		bool QueryHit(string space);	// Function that tests if the space chosen hits a ship
		Ship* HitShip(string space);	// Function that returns which ship was hit when given a coordinate
		void PrintShipBoard();		// Prints the board
		int SpaceConverter(string space); // Same conversion function I've used in other files

	private:
		vector<Ship*> boats;		// A vector containing all the Ship objects present on the board
};

#endif
