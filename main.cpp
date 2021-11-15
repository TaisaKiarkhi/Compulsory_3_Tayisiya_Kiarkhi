#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <cstdlib>
using namespace std;

char board[6][7]{ {'*','*','*','*','*','*','*'},
	              {'*','*','*','*','*','*','*'},
	              {'*','*','*','*','*','*','*'},
               	  {'*','*','*','*','*','*','*'},
	              {'*','*','*','*','*','*','*'},
	              {'*','*','*','*','*','*','*'} };

void play();
void AI();
void number_board();
char Players_char = 'X';
void switch_players_char();
char winner();
void play_AI();
void play_Player();
int score_player_1{};
int score_player_2{};
void score_file();
void select();




//allows to input the nicknames
class Nicknames {   //declare classes before int, or the main will write "indefinite"
public:
     string name;
	void print_name() {

		cout << "Please, enter your nickname in the game" << endl;
		getline(cin, name);

		cout << "Your name in the game is: " << name << endl;

	}
};
//creating a board and an empty board
class Board {

public:
	void board_array() {

		 
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 7; j++) {

					cout << "| " << "_" << board[i][j] << "_";
				}
				cout << " |" << endl;
			}

		} 
	
	void empty_board() {

		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 7; j++) {

				board[i][j] = '*';
			}
		
		}

	}
	
};



int main() {
	cout << "Welcome to 4 in a row! You can play alone or with your frined!" << endl;
	cout << "Player 1 " << endl;
	Nicknames Player_1;
	Player_1.print_name();

	cout << "Player 2" << endl;
	Nicknames Player_2;
	Player_2.print_name();
	if (Player_2.name == "AI") {

		AI();
	}
	
	for (int i = 0; i < 200; i++) {  ///I used for loop to loop the game max 200 times
		
		number_board();
		Board* new_board = new Board(); //creates new board
		new_board->board_array();
		switch_players_char();
		play();
		winner();
		
		if (winner() == 'X') {
			cout << "Player 2 won the game!" << endl;
		}
		else if (winner() == 'O') {
			cout << "Player 1 won the game!" << endl;
		}
		else if (winner() == ' ' ) {
			cout << "It is draw!" << endl;
		}
		
		
	}
	
	
     return 0;
}
//writes the score down into the file
void score_file() {
	std::string buff;
	std::streampos begin;
	std::streampos end;
	std::fstream score("C:\\Users\\Taisa\\source\\repos\\Compulsory_3_Tayisiya_Kiarkhi\\New_score.txt", std::ios::in | std::ios::app | std::ios::out);
	int score_text_1{};
	int score_text_2{};
	string player_1{};
	string player_2{};
	score_text_1 = score_player_1;
	score_text_2 = score_player_2;

	player_1 = "Score Player 1 : ";
	player_2 = " Score Player 2 : ";

	score << player_1 << score_text_1;
	score << player_2 << score_text_2;

	score.clear();
	score.seekg(0);
	score.sync();
	while (getline(score, buff)) {
		cout<<endl << buff << endl;
	}
	score.clear();
	score.close();
}




//the players select if they want to play again
void select() {
	char selection{};
	cout << "Do you want to play again? (Y/N)";
	cin >> selection;
	if (selection == 'Y') {
		Board* new_empty = new Board(); //creates a new empty board for new game
		new_empty->empty_board();
	}
	if (selection == 'N') {
		cout << "Bye!";
	}

}





//the players select a position on the board
void play()
{
	int index{};
		int position{};
		cin >> position;
		if(position==1){
			index = 5;
			if (board[index][0] == Players_char) {
				--index;
			}
			if (board[index][0] == Players_char) {
				--index;
			}
			if (board[index][0] == Players_char) {
				--index;
			}
			if (board[index][0] == Players_char) {
				--index;
			}
			if (board[index][0] == Players_char) {
				--index;
			}
			board[index][0] = Players_char;                           
		}  
		
		

		 if (position == 2) {
			 index = 5;
			 if (board[index][1] == Players_char) {
				 --index;
			 }
			 if (board[index][1] == Players_char) {
				 --index;
			 }
			 if (board[index][1] == Players_char) {
				 --index;
			 }
			 if (board[index][1] == Players_char) {
				 --index;
			 }
			 if (board[index][1] == Players_char) {
				 --index;
			 }
			 board[index][1] = Players_char;
		}

		else if (position == 3) {
			 index = 5;
			 if (board[index][2] == Players_char) {
				 --index;
			 }
			 if (board[index][2] == Players_char) {
				 --index;
			 }
			 if (board[index][2] == Players_char) {
				 --index;
			 }
			 if (board[index][2] == Players_char) {
				 --index;
			 }
			 if (board[index][2] == Players_char) {
				 --index;
			 }
			 board[index][2] = Players_char;
		}
		else if (position == 4) {
			 index = 5;
			 if (board[index][3] == Players_char) {
				 --index;
			 }
			 if (board[index][3] == Players_char) {
				 --index;
			 }
			 if (board[index][3] == Players_char) {
				 --index;
			 }
			 if (board[index][3] == Players_char) {
				 --index;
			 }
			 if (board[index][3] == Players_char) {
				 --index;
			 }
			 board[index][3] = Players_char;
		}
		else if (position == 5) {
			 index = 5;
			 if (board[index][4] == Players_char) {
				 --index;
			 }
			 if (board[index][4] == Players_char) {
				 --index;
			 }
			 if (board[index][4] == Players_char) {
				 --index;
			 }
			 if (board[index][4] == Players_char) {
				 --index;
			 }
			 if (board[index][4] == Players_char) {
				 --index;
			 }
			 board[index][4] = Players_char;
		}
		else if (position == 6) {
			 index = 5;
			 if (board[index][5] == Players_char) {
				 --index;
			 }
			 if (board[index][5] == Players_char) {
				 --index;
			 }
			 if (board[index][5] == Players_char) {
				 --index;
			 }
			 if (board[index][5] == Players_char) {
				 --index;
			 }
			 if (board[index][5] == Players_char) {
				 --index;
			 }
			 board[index][5] = Players_char;
		}
		else if (position == 7) {
			 index = 5;
			 if (board[index][6] == Players_char) {
				 --index;
			 }
			 if (board[index][6] == Players_char) {
				 --index;
			 }
			 if (board[index][6] == Players_char) {
				 --index;
			 }
			 if (board[index][6] == Players_char) {
				 --index;
			 }
			 if (board[index][6] == Players_char) {
				 --index;
			 }
			 board[index][6] = Players_char;
		}

	}

	
void AI()
{
	for (int i = 0; i < 200; i++) {
		number_board();
		Board* new_board = new Board();
		new_board->board_array();
		switch_players_char();
		play_AI();
		play_Player();
		winner();
		delete new_board;
		if (winner() == 'X') {
			cout << "Player 2 won the game!" << endl;
		}
		else if (winner() == 'O') {
			cout << "Player 1 won the game!" << endl;
		}
		else if (winner() == ' ') {
			cout << "It is draw!" << endl;
		}
	}


}



//shows the position on the board
void number_board()
{
	const int number[7]{ 1,2,3,4,5,6,7, };
	for (int a = 0; a < 7; a++) {
		cout << "  " << " " << number[a] << " ";
	}
	cout << endl;
}



void switch_players_char()
{
	if (Players_char == 'X')
		Players_char = 'O';
	else if  (Players_char == 'O')
		Players_char = 'X';
}





//checks the winner
char winner()

{   
	
	
	//for X vertical
			

		if (board[5][0] == 'X' && board[4][0] == 'X' && board[3][0] == 'X' && board[2][0] == 'X' ||
			board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X' && board[3][0] == 'X' ||
			board[5][1] == 'X' && board[4][1] == 'X' && board[3][1] == 'X' && board[2][1] == 'X' ||
			board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X' && board[3][1] == 'X' ||
			board[5][2] == 'X' && board[4][2] == 'X' && board[3][2] == 'X' && board[2][2] == 'X' ||
			board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X' && board[3][2] == 'X' ||
			board[5][3] == 'X' && board[4][3] == 'X' && board[3][3] == 'X' && board[2][3] == 'X' ||
			board[5][4] == 'X' && board[4][4] == 'X' && board[3][4] == 'X' && board[2][4] == 'X' ||
			board[5][5] == 'X' && board[4][5] == 'X' && board[3][5] == 'X' && board[2][5] == 'X' ||
			board[5][6] == 'X' && board[4][6] == 'X' && board[3][6] == 'X' && board[2][6] == 'X' ||
			board[0][3] == 'X' && board[1][3] == 'X' && board[2][3] == 'X' && board[3][3] == 'X' ||
			board[0][4] == 'X' && board[1][4] == 'X' && board[2][4] == 'X' && board[3][4] == 'X' ||
			board[0][5] == 'X' && board[1][5] == 'X' && board[2][5] == 'X' && board[3][5] == 'X' ||
			board[0][6] == 'X' && board[1][6] == 'X' && board[2][6] == 'X' && board[3][6] == 'X'
			) {
			
			score_player_1+=1; //writes the score
			score_file();
			select(); 
			return 'X';

		}

		//horizontal
		else if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X' && board[0][3] == 'X' ||
			board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X' && board[1][3] == 'X' ||
			board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X' && board[2][3] == 'X' ||
			board[3][0] == 'X' && board[3][1] == 'X' && board[3][2] == 'X' && board[3][3] == 'X' ||
			board[4][0] == 'X' && board[4][1] == 'X' && board[4][2] == 'X' && board[4][3] == 'X' ||
			board[5][0] == 'X' && board[5][1] == 'X' && board[5][2] == 'X' && board[5][3] == 'X' ||
			board[0][3] == 'X' && board[0][4] == 'X' && board[0][5] == 'X' && board[0][6] == 'X' ||
			board[1][3] == 'X' && board[1][4] == 'X' && board[1][5] == 'X' && board[1][6] == 'X' ||
			board[2][3] == 'X' && board[2][4] == 'X' && board[2][5] == 'X' && board[2][6] == 'X' ||
			board[3][3] == 'X' && board[3][4] == 'X' && board[3][5] == 'X' && board[3][6] == 'X' ||
			board[4][3] == 'X' && board[4][4] == 'X' && board[4][5] == 'X' && board[4][6] == 'X' ||
			board[5][3] == 'X' && board[5][4] == 'X' && board[5][5] == 'X' && board[5][6] == 'X'
			) {
			
		
			score_player_1+=1;
			score_file();
			select();
			return 'X';
		
		}
		//crossing  up
		else if (board[3][0] == 'X' && board[2][1] == 'X' && board[1][2] == 'X' && board[0][3] == 'X' ||
			board[4][0] == 'X' && board[3][1] == 'X' && board[2][2] == 'X' && board[1][3] == 'X' ||
			board[3][1] == 'X' && board[2][2] == 'X' && board[1][3] == 'X' && board[0][4] == 'X' ||
			board[5][0] == 'X' && board[4][1] == 'X' && board[3][2] == 'X' && board[2][3] == 'X' ||
			board[3][2] == 'X' && board[2][3] == 'X' && board[1][4] == 'X' && board[0][5] == 'X' ||
			board[5][1] == 'X' && board[4][2] == 'X' && board[3][3] == 'X' && board[2][4] == 'X' ||
			board[3][3] == 'X' && board[2][4] == 'X' && board[1][5] == 'X' && board[0][6] == 'X' ||
			board[5][2] == 'X' && board[4][3] == 'X' && board[3][4] == 'X' && board[2][5] == 'X' ||
			board[4][3] == 'X' && board[3][4] == 'X' && board[2][5] == 'X' && board[1][6] == 'X' ||
			board[5][3] == 'X' && board[4][4] == 'X' && board[3][5] == 'X' && board[2][6] == 'X'
			) {
			
		
			score_player_1+=1;
			score_file();
			select();
			return 'X';
		
		}
		//crossing down
		else if (board[0][3] == 'X' && board[1][4] == 'X' && board[2][5] == 'X' && board[3][6] == 'X' ||
			board[0][2] == 'X' && board[1][3] == 'X' && board[2][4] == 'X' && board[3][5] == 'X' ||
			board[1][3] == 'X' && board[2][4] == 'X' && board[3][5] == 'X' && board[4][6] == 'X' ||
			board[0][1] == 'X' && board[1][2] == 'X' && board[2][3] == 'X' && board[3][4] == 'X' ||
			board[2][3] == 'X' && board[3][4] == 'X' && board[4][5] == 'X' && board[5][6] == 'X' ||
			board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X' && board[3][3] == 'X' ||
			board[2][2] == 'X' && board[3][3] == 'X' && board[4][4] == 'X' && board[5][5] == 'X' ||
			board[1][0] == 'X' && board[2][1] == 'X' && board[3][2] == 'X' && board[4][3] == 'X' ||
			board[2][1] == 'X' && board[3][2] == 'X' && board[4][3] == 'X' && board[5][4] == 'X' ||
			board[2][0] == 'X' && board[3][1] == 'X' && board[4][2] == 'X' && board[5][3] == 'X'
			) {
			
			score_player_1+=1;
			score_file();
			select();
			return 'X';
			
		}

		//Winner O

		 //for X vertical
		else if (board[5][0] == 'O' && board[4][0] == 'O' && board[3][0] == 'O' && board[2][0] == 'O' ||
			board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O' && board[3][0] == 'O' ||
			board[5][1] == 'O' && board[4][1] == 'O' && board[3][1] == 'O' && board[2][1] == 'O' ||
			board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O' && board[3][1] == 'O' ||
			board[5][2] == 'O' && board[4][2] == 'O' && board[3][2] == 'O' && board[2][2] == 'O' ||
			board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O' && board[3][2] == 'O' ||
			board[5][3] == 'O' && board[4][3] == 'O' && board[3][3] == 'O' && board[2][3] == 'O' ||
			board[5][4] == 'O' && board[4][4] == 'O' && board[3][4] == 'O' && board[2][4] == 'O' ||
			board[5][5] == 'O' && board[4][5] == 'O' && board[3][5] == 'O' && board[2][5] == 'O' ||
			board[5][6] == 'O' && board[4][6] == 'O' && board[3][6] == 'O' && board[2][6] == 'O' ||
			board[0][3] == 'O' && board[1][3] == 'O' && board[2][3] == 'O' && board[3][3] == 'O' ||
			board[0][4] == 'O' && board[1][4] == 'O' && board[2][4] == 'O' && board[3][4] == 'O' ||
			board[0][5] == 'O' && board[1][5] == 'O' && board[2][5] == 'O' && board[3][5] == 'O' ||
			board[0][6] == 'O' && board[1][6] == 'O' && board[2][6] == 'O' && board[3][6] == 'O'
			) {
		
			score_player_2+=1;
			score_file();
			select();
			return 'O';
		
		}

		//horizontal
		else if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O' && board[0][3] == 'O' ||
			board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O' && board[1][3] == 'O' ||
			board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O' && board[2][3] == 'O' ||
			board[3][0] == 'O' && board[3][1] == 'O' && board[3][2] == 'O' && board[3][3] == 'O' ||
			board[4][0] == 'O' && board[4][1] == 'O' && board[4][2] == 'O' && board[4][3] == 'O' ||
			board[5][0] == 'O' && board[5][1] == 'O' && board[5][2] == 'O' && board[5][3] == 'O' ||
			board[0][3] == 'O' && board[0][4] == 'O' && board[0][5] == 'O' && board[0][6] == 'O' ||
			board[1][3] == 'O' && board[1][4] == 'O' && board[1][5] == 'O' && board[1][6] == 'O' ||
			board[2][3] == 'O' && board[2][4] == 'O' && board[2][5] == 'O' && board[2][6] == 'O' ||
			board[3][3] == 'O' && board[3][4] == 'O' && board[3][5] == 'O' && board[3][6] == 'O' ||
			board[4][3] == 'O' && board[4][4] == 'O' && board[4][5] == 'O' && board[4][6] == 'O' ||
			board[5][3] == 'O' && board[5][4] == 'O' && board[5][5] == 'O' && board[5][6] == 'O'
			) {
			
			score_player_2+=1;
			score_file();
			select();
			return 'O';
			
		}
		//crossing  up
		else if (board[3][0] == 'O' && board[2][1] == 'O' && board[1][2] == 'O' && board[0][3] == 'O' ||
			board[4][0] == 'O' && board[3][1] == 'O' && board[2][2] == 'O' && board[1][3] == 'O' ||
			board[3][1] == 'O' && board[2][2] == 'O' && board[1][3] == 'O' && board[0][4] == 'O' ||
			board[5][0] == 'O' && board[4][1] == 'O' && board[3][2] == 'O' && board[2][3] == 'O' ||
			board[3][2] == 'O' && board[2][3] == 'O' && board[1][4] == 'O' && board[0][5] == 'O' ||
			board[5][1] == 'O' && board[4][2] == 'O' && board[3][3] == 'O' && board[2][4] == 'O' ||
			board[3][3] == 'O' && board[2][4] == 'O' && board[1][5] == 'O' && board[0][6] == 'O' ||
			board[5][2] == 'O' && board[4][3] == 'O' && board[3][4] == 'O' && board[2][5] == 'O' ||
			board[4][3] == 'O' && board[3][4] == 'O' && board[2][5] == 'O' && board[1][6] == 'O' ||
			board[5][3] == 'O' && board[4][4] == 'O' && board[3][5] == 'O' && board[2][6] == 'O'
			) {
			
			score_player_2+=1;
			score_file();
			select();
			return 'O';
		
		}
		//crossing down
		else if (board[0][3] == 'O' && board[1][4] == 'O' && board[2][5] == 'O' && board[3][6] == 'O' ||
			board[0][2] == 'O' && board[1][3] == 'O' && board[2][4] == 'O' && board[3][5] == 'O' ||
			board[1][3] == 'O' && board[2][4] == 'O' && board[3][5] == 'O' && board[4][6] == 'O' ||
			board[0][1] == 'O' && board[1][2] == 'O' && board[2][3] == 'O' && board[3][4] == 'O' ||
			board[2][3] == 'O' && board[3][4] == 'O' && board[4][5] == 'O' && board[5][6] == 'O' ||
			board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O' && board[3][3] == 'O' ||
			board[2][2] == 'O' && board[3][3] == 'O' && board[4][4] == 'O' && board[5][5] == 'O' ||
			board[1][0] == 'O' && board[2][1] == 'O' && board[3][2] == 'O' && board[4][3] == 'O' ||
			board[2][1] == 'O' && board[3][2] == 'O' && board[4][3] == 'O' && board[5][4] == 'O' ||
			board[2][0] == 'O' && board[3][1] == 'O' && board[4][2] == 'O' && board[5][3] == 'O'
			) {
			
			score_player_2+=1;
			score_file();
			select();
			return 'O';

		}
		return ' ';
		


}

void play_AI()
{
	srand(time(NULL));
	int index{};
	int position=rand()%7+1;

	if (position == 1) {
		index = 5;
		if (board[index][0] == 'X') {
			--index;
		}
		if (board[index][0] == 'X') {
			--index;
		}
		if (board[index][0] == 'X') {
			--index;
		}
		if (board[index][0] == 'X') {
			--index;
		}
		if (board[index][0] == 'X') {
			--index;
		}
		board[index][0] = 'X';
	}



	if (position == 2) {
		index = 5;
		if (board[index][1] == 'X') {
			--index;
		}
		if (board[index][1] == 'X') {
			--index;
		}
		if (board[index][1] == 'X') {
			--index;
		}
		if (board[index][1] == 'X') {
			--index;
		}
		if (board[index][1] == 'X') {
			--index;
		}
		board[index][1] = 'X';
	}

	else if (position == 3) {
		index = 5;
		if (board[index][2] == 'X') {
			--index;
		}
		if (board[index][2] == 'X') {
			--index;
		}
		if (board[index][2] == 'X') {
			--index;
		}
		if (board[index][2] == 'X') {
			--index;
		}
		if (board[index][2] == 'X') {
			--index;
		}
		board[index][2] = 'X';
	}
	else if (position == 4) {
		index = 5;
		if (board[index][3] == 'X') {
			--index;
		}
		if (board[index][3] == 'X') {
			--index;
		}
		if (board[index][3] == 'X') {
			--index;
		}
		if (board[index][3] == 'X') {
			--index;
		}
		if (board[index][3] == 'X') {
			--index;
		}
		board[index][3] = 'X';
	}
	else if (position == 5) {
		index = 5;
		if (board[index][4] == 'X') {
			--index;
		}
		if (board[index][4] == 'X') {
			--index;
		}
		if (board[index][4] == 'X') {
			--index;
		}
		if (board[index][4] == 'X') {
			--index;
		}
		if (board[index][4] == 'X') {
			--index;
		}
		board[index][4] = 'X';
	}
	else if (position == 6) {
		index = 5;
		if (board[index][5] == 'X') {
			--index;
		}
		if (board[index][5] == 'X') {
			--index;
		}
		if (board[index][5] == 'X') {
			--index;
		}
		if (board[index][5] == 'X') {
			--index;
		}
		if (board[index][5] == 'X') {
			--index;
		}
		board[index][5] = 'X';
	}
	else if (position == 7) {
		index = 5;
		if (board[index][6] == 'X') {
			--index;
		}
		if (board[index][6] == 'X') {
			--index;
		}
		if (board[index][6] == 'X') {
			--index;
		}
		if (board[index][6] == 'X') {
			--index;
		}
		if (board[index][6] == 'X') {
			--index;
		}
		board[index][6] = 'X';
	}

}

void play_Player()
{
	
	int index{};
	int position{};
	cin >> position;

	if (position == 1) {
		index = 5;
		if (board[index][0] == 'O') {
			--index;
		}
		if (board[index][0] == 'O') {
			--index;
		}
		if (board[index][0] == 'O') {
			--index;
		}
		if (board[index][0] == 'O') {
			--index;
		}
		if (board[index][0] == 'O') {
			--index;
		}
		board[index][0] = 'O';
	}



	if (position == 2) {
		index = 5;
		if (board[index][1] == 'O') {
			--index;
		}
		if (board[index][1] == 'O') {
			--index;
		}
		if (board[index][1] == 'O') {
			--index;
		}
		if (board[index][1] == 'O') {
			--index;
		}
		if (board[index][1] == 'O') {
			--index;
		}
		board[index][1] = 'O';
	}

	else if (position == 3) {
		index = 5;
		if (board[index][2] == 'O') {
			--index;
		}
		if (board[index][2] == 'O') {
			--index;
		}
		if (board[index][2] == 'O') {
			--index;
		}
		if (board[index][2] == 'O') {
			--index;
		}
		if (board[index][2] == 'O') {
			--index;
		}
		board[index][2] = 'O';
	}
	else if (position == 4) {
		index = 5;
		if (board[index][3] == 'O') {
			--index;
		}
		if (board[index][3] == 'O') {
			--index;
		}
		if (board[index][3] == 'O') {
			--index;
		}
		if (board[index][3] == 'O') {
			--index;
		}
		if (board[index][3] == 'O') {
			--index;
		}
		board[index][3] = 'O';
	}
	else if (position == 5) {
		index = 5;
		if (board[index][4] == 'O') {
			--index;
		}
		if (board[index][4] == 'O') {
			--index;
		}
		if (board[index][4] == 'O') {
			--index;
		}
		if (board[index][4] == 'O') {
			--index;
		}
		if (board[index][4] == 'O') {
			--index;
		}
		board[index][4] = 'O';
	}
	else if (position == 6) {
		index = 5;
		if (board[index][5] == 'O') {
			--index;
		}
		if (board[index][5] == 'O') {
			--index;
		}
		if (board[index][5] == 'O') {
			--index;
		}
		if (board[index][5] == 'O') {
			--index;
		}
		if (board[index][5] == 'O') {
			--index;
		}
		board[index][5] = 'O';
	}
	else if (position == 7) {
		index = 5;
		if (board[index][6] == 'O') {
			--index;
		}
		if (board[index][6] == 'O') {
			--index;
		}
		if (board[index][6] == 'O') {
			--index;
		}
		if (board[index][6] == 'O') {
			--index;
		}
		if (board[index][6] == 'O') {
			--index;
		}
		board[index][6] = 'O';
	}

}
