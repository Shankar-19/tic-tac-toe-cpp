#include <iostream>
#include <string>

#define SQUARES 9

using namespace std;

class Game {
private:
	string gameBoard;
	char displayChar = '*';
	void setDisplay(char ch) {
		displayChar = ch;
		cout << "Welcome to tic-tac-toe\n";
		for(int i = 0; i != SQUARES; ++i)
			gameBoard += ch;
	}
public:
	Game() {
		setDisplay(displayChar);
	}
	Game(char ch) {
		setDisplay(ch);	
	}
	void display();
	void choose();
	void gameLoop(char ch);
	void set(int pos, char ch);
	char gameState();
};

void Game::display() {
	cout << endl;
	for(int i = 0; i != SQUARES; ++i) {
		cout << gameBoard[i] << ' ';
		if(i % 3 == 2)
			cout << endl;
	}
}

void Game::choose() {
	display();
	char ch = '\0';
	while(true) {
		cout << "\nChoose x or o :: ";
		cin >> ch;
		if(ch == 'x' || ch == 'o')
			break;
	}
	gameLoop(ch);
}

void Game::gameLoop(char ch) {
	int pos = 0;
	char state = 'c';
	size_t found = 0;
	while(state == 'c') {
			found = gameBoard.find(displayChar); 
			if(found == string::npos) {
				break;
			}
		if(ch == 'x') {
			cout << "\nx enter the pos :: ";
			cin >> pos;
			set(pos, ch);
			state = gameState();
			display();
			ch = 'o';
		}
		else {
			cout << "\no enter the pos :: ";
			cin >> pos;
			set(pos, ch);
			state = gameState();
			display();
			ch = 'x';
		}
	}
	if(state == 'x')
		cout << "\nPlayer x wins the game\n";
	else if (state == 'o')
		cout << "\nPlayer o wins the game\n";
	else 
		cout << "\nMatch Draw\n";
}

void Game::set(int pos, char ch) {
	while(true) {
		if(pos <= gameBoard.size()) {
			if(gameBoard[pos - 1] == displayChar) {
				gameBoard[pos - 1] = ch;
				break;
			}
			else {
				cout << "\nChoose different spot\n";
				cout << '\n' << ch <<" enter the pos :: ";
				cin >> pos;
			}
		}
		else {
			cout << "\nEnter between 1 - 9 :: ";
			cin >> pos;
		}	
	}
} 

char Game::gameState() {
	string temp = gameBoard;
	if(temp[0] == 'x' && temp[1] == 'x' && temp[2] == 'x' || 
			temp[0] == 'o' && temp[1] == 'o' && temp[2] == 'o')
		return temp[0];
	else if(temp[3] == 'x' && temp[4] == 'x' && temp[5] == 'x' || 
			temp[3] == 'o' && temp[4] == 'o' && temp[5] == 'o')
		return temp[3];
	else if(temp[6] == 'x' && temp[7] == 'x' && temp[8] == 'x' || 
			temp[6] == 'o' && temp[7] == 'o' && temp[8] == 'o')
		return temp[6];
	else if(temp[0] == 'x' && temp[3] == 'x' && temp[6] == 'x' || 
			temp[0] == 'o' && temp[3] == 'o' && temp[6] == 'o')
		return temp[0];
	else if(temp[1] == 'x' && temp[4] == 'x' && temp[7] == 'x' || 
			temp[1] == 'o' && temp[4] == 'o' && temp[7] == 'o')
		return temp[1];
	else if(temp[2] == 'x' && temp[5] == 'x' && temp[8] == 'x' || 
			temp[2] == 'o' && temp[5] == 'o' && temp[8] == 'o')
		return temp[2];
	else if(temp[0] == 'x' && temp[4] == 'x' && temp[8] == 'x' || 
			temp[0] == 'o' && temp[8] == 'o' && temp[8] == 'o')
		return temp[0];
	else if(temp[2] == 'x' && temp[4] == 'x' && temp[6] == 'x' || 
			temp[2] == 'o' && temp[4] == 'o' && temp[6] == 'o')
		return temp[2];
	else
		return 'c';
}