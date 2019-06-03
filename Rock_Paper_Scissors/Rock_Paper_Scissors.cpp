#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <limits>
#include <algorithm>
#include <ctime>
#include <cstdlib>



using namespace std;

// Rock paper scissor game with the computer ! 
int main()
{
	// variable declaration bool check is here to check if the input is indeed rock paper scissor. 
	vector <string> r_p_s = { "rock", "paper", "scissor" };
	string input; bool check = true; bool end = false;
	int ct_play = 0; int player_play = 0;
	int player_scr = 0; int computer_scr = 0;
	cout << "Let's play a game of rock, paper, scissor! First to five win!\n";
	// While loop till either player or computer win 5 time
	while ((player_scr < 5 || computer_scr < 5) && (end == false)) {
		cout << "3, 2, 1 Go!\n";
		cin >> input;
		// random seed generator 1 - 3.
		srand(time(0));
		ct_play = rand() % 3 + 1;
		cout << r_p_s[ct_play - 1] << "\n";
		// to stop the game early on.
		if (input == "stop")
			end = true;
		// for loop for both check the validity of the input via bool check and store the player input into an int.
		for (int i = 0; i < r_p_s.size(); i++) {
			if (input == r_p_s[i]) {
				check = false;
				player_play = i + 1;
			}
		}
		// Sassy error line.
		if (check == true)
			cout << "rock, paper, scissor only! Are you trying to cheat me?!\n";
		
		 if (ct_play == player_play)
			cout << "Equality ! Let's continue!\n";
		 // rock vs paper or scissor
		 else if (ct_play == 1 && player_play == 2) {
			cout << "You win this one!\n";
			++player_scr;
		}
		 else if (ct_play == 1 && player_play == 3) {
			cout << "I win this one!\n";
			++computer_scr;
		}
		 // paper vs rock or scissor
		 else if (ct_play == 2 && player_play == 1) {
			cout << "I win this one!\n"; 
			++computer_scr;
		}
		 else if (ct_play == 2 && player_play == 3) {
			cout << "You win this one!\n";
			++player_scr;
		}
		 // scissor vs paper or rock
		 else if (ct_play == 3 && player_play == 1){
			cout << "You win this one!\n";
			++player_scr;
		}
		 else if (ct_play == 3 && player_play == 2) {
			cout << "I win this one!\n";
			++computer_scr;
		}
		 cout << "Me: " << computer_scr << " You: " << player_scr << "\n";
		 // Some lines to make the computer more human (and kinda a bit of an asshole). 
		 if (player_scr == 4 && computer_scr <= 3)
			 cout << "One more and you win! I shall try my best!\n";
		 if (player_scr <= 3 && computer_scr == 4)
			 cout << "One more and I win! Are you even trying?\n";
		 if (player_scr == 4 && computer_scr == 4)
			 cout << "It's the final battle! Let's do our best!\n";
	}
	if (player_scr < computer_scr)
		cout << "Haha I win! I'm the best!\n";
	if (player_scr > computer_scr)
		cout << "Fine, you win! Wanna rematch?\n";
}