#include "Player.h"
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;

bool endGame = false;

void StartPrompt() {

	cout << "Welcome to battleship! Soon will appear your\n"
	     << "two boards and a random player will be chosen\n"
	     << "to go first!\n";


}

int main() {

	// We first set up the game with two players, the human and the computer.

	Player human("human");
	Player computer("computer");
	string chosenSpace;
	int randNum = 0;
	bool validInput = false;

	srand(time(0));
	randNum = rand() % 100;

	// Cout the start prompt located above
	StartPrompt();
	cout << endl;

	// Randomly chose who starts. If the random number is between 0 and 49, the human goes first. If it's between 50 and 99, the computer goes first.
	switch(randNum) {

		case 0 ... 49:

			cout << "You go first!" << endl;
			cout << endl;

			do {
				// Prints out the two boards, one with ships and the other to keep track of the enemy
				human.PrintBoards();

				// Gets iput and tests whether it's valid
				validInput = false;
				while (!validInput) {
					cout << "What space do you wish to fire upon? (type STOP to stop)" << endl;
					cin >> chosenSpace;
					validInput = human.CheckInput(chosenSpace);

					if (!validInput) {
						cout << "Please enter a valid space or one you haven't chosen before." << endl;
					}
				}

				// Stops the program if STOP is typed
				if (chosenSpace == "STOP") {
					return 0;
				}

				// The human makes an attack with the chosen space and then there is a check to see if the human has sunk all battleships
				human.MakeAttack(chosenSpace, computer.shipBoard);
				endGame = human.CheckGame();

				// The game ends if the check is successful
				if (endGame) {
					cout << "You win!!!" << endl;
					human.PrintBoards();
					break;
				}

				// Since the game didn't end, we let the computer take a turn
				validInput = false;
				while (!validInput) {
					chosenSpace = computer.GenerateMove();
					validInput = computer.CheckInput(chosenSpace);
				}
				cout << "Computer chooses " << chosenSpace << endl;

				// Computer makes an attack and the game is checked again to see if the computer has sunk all the battleships
				computer.MakeAttack(chosenSpace, human.shipBoard);
				endGame = computer.CheckGame();

				// If successful the game ends with the computer winning
				if (endGame) {
					cout << "The Computer wins!!!" << endl;
					human.PrintBoards();
				}

			} while (!endGame);

			break;

		case 50 ... 99:

			// This section is very similar to the previous one, just the computer goes first

			cout << "The computer goes first!" << endl;
			cout << endl;

			do {
				human.PrintBoards();

				validInput = false;
				while (!validInput) {
					chosenSpace = computer.GenerateMove();
					validInput = computer.CheckInput(chosenSpace);
				}
				cout << "Computer chooses " << chosenSpace << endl;

				computer.MakeAttack(chosenSpace, human.shipBoard);
				endGame = computer.CheckGame();

				if (endGame) {
					cout << "The Computer wins!!!" << endl;
					human.PrintBoards();
					break;
				}

				human.PrintBoards();

				validInput = false;
				while (!validInput) {
					cout << "What space do you wish to fire upon? (type STOP to stop)" << endl;
					cin >> chosenSpace;
					validInput = human.CheckInput(chosenSpace);

					if (!validInput) {
						cout << "Please enter a valid space or one you haven't chosen before." << endl;
					}
				}

        // Stops the program if STOP is typed
				if (chosenSpace == "STOP") {
					return 0;
				}

				human.MakeAttack(chosenSpace, computer.shipBoard);
				endGame = human.CheckGame();

				if (endGame) {
					cout << "You win!!!" << endl;
					human.PrintBoards();
				}

			} while (!endGame);

			break;

	}

	return 0;

}
