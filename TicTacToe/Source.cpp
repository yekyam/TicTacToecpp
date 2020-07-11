#include <iostream>
#include <vector>
#include <string>

//Developed by Manuel E. Mateo
std::string XorO;
int point;
std::vector <std::string> inputs = { ".", ".", ".", ".", ".", ".", ".", ".", "." };
bool gameOn = true;
int filled_places = 0;
int turns = 0;
bool winner = false;

void drawEmptyBoard() {
	std::cout << "1|2|3\n4|5|6\n7|8|9\n";
}

void drawBoard() {
	std::cout << inputs.at(0) << "|" << inputs.at(1) << "|" << inputs.at(2) << "\n" << inputs.at(3) << "|" << inputs.at(4) << "|" << inputs.at(5) << "\n" << inputs.at(6) << "|" << inputs.at(7) << "|" << inputs.at(8) << "\n";
}

int userinput() {
	turns++;
	if (turns == 1 or turns == 3 or turns == 5 or turns == 7 or turns == 9 or turns == 11) {
		std::cout << "X's turn! Where would you like to place your letter?\n";
		XorO = "X";
		std::cin >> point;
		if (!point) {
			std::cerr << "Number not inputted! Quitting.";
			return -1;
		}
		return point;
	}
	else {
		std::cout << "O's turn! Where would you like to place your letter?\n";
		std::cin >> point; 
		if (!point) {
			std::cerr << "Number not inputted! Quitting.";
			return -1;
		}
		XorO = "O";
		return point;
	}
}

void game_mechanism(int point = 1) {
	if (inputs[point - 1] == ".") {
		inputs[point - 1] = XorO;
	}
	else if (inputs[point - 1] == "X" or inputs[point - 1] == "O") {
		std::cout << "Invalid placement, point is already filled.\n";
		turns--;
	}
}

void win_detection() {
	if (inputs[0] == inputs[1] && inputs[1] == inputs[2] && inputs[0] != ".")
	{
		std::cout << inputs.at(0) << " Wins! ";
		gameOn = false;
		winner = true;
	}
	else if (inputs[3] == inputs[4] && inputs[4] == inputs[5] && inputs[3] != ".")
	{
		std::cout << inputs.at(3) << " Wins! ";
		gameOn = false;
		winner = true;
	}
	else if (inputs[6] == inputs[7] && inputs[7] == inputs[8] && inputs[6] != ".")
	{
		std::cout << inputs.at(6) << " Wins! ";
		gameOn = false;
		winner = true;
	}
	else if (inputs[0] == inputs[3] && inputs[3] == inputs[6] && inputs[0] != ".")
	{
		std::cout << inputs.at(0) << " Wins! ";
		gameOn = false;
		winner = true;
	}
	else if (inputs[1] == inputs[4] && inputs[4] == inputs[7] && inputs[1] != ".")
	{
		std::cout << inputs.at(1) << " Wins! ";
		gameOn = false;
		winner = true;
	}
	else if (inputs[2] == inputs[5] && inputs[5] == inputs[8] && inputs[2] != ".")
	{
		std::cout << inputs.at(2) << " Wins! ";
		gameOn = false;
		winner = true;
	}
	else if (inputs[0] == inputs[4] && inputs[4] == inputs[8] && inputs[0] != ".")
	{
		std::cout << inputs.at(0) << " Wins! ";
		gameOn = false;
		winner = true;
	}
	else if (inputs[2] == inputs[4] && inputs[4] == inputs[6] && inputs[2] != ".")
	{
		std::cout << inputs.at(2) << " Wins! ";
		gameOn = false;
		winner = true;
	}
}

void gameOver() {
	for (int i = 0; i < inputs.size(); i++) {
		std::string letters = inputs[i];
		if (letters != ".") {
			filled_places++;
			if (filled_places == 9) {
				gameOn = false;
				if (winner == false) {
					std::cout << "It's a tie!";
				}
			}
		}
	}
}

void play_again() {
	std::cout << "Would you like to play again? Y or N.\n";
	std::string choice;
	std::cin >> choice;
	if (choice == "Y" or choice == "y"){
		std::cout << "Starting a new game.\n";
		inputs = { ".", ".", ".", ".", ".", ".", ".", ".", "." };
		filled_places = 0;
		turns = 0;
		drawEmptyBoard();
		gameOn = true;
	}else {
		std::cout << "Quitting. ";
	}
}


int main() {
	drawEmptyBoard();
		while (gameOn == true) {
			
			userinput();
			game_mechanism(point);
			drawBoard();
			win_detection();
			gameOver();
			filled_places = 0;
			if (gameOn == false) {
				play_again();
			}
		}
		std::cout << "Game over! ";
		win_detection;
		//play_again();
	}