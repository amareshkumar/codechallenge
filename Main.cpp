//C++ program

#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

using namespace std;

bool game_result(vector<char> boxes) {
	if (boxes.size() == 0) {
		return true;
	}
	else {
		return false;
	}
}

//get a random letter from the provided set of letters.
char random_letter(char letter_box[], int len) {
	int randno = rand() % len + 1;

	return letter_box[randno];
}

int main() {
	char letters[20] = { 'a', 'a', 'b', 'b','c','c','d','d','e','e','f','f','g','g','h','h','i','i','j','j'};
	vector <char> boxes(20);

	//put letter in the boxes
	for (int i = 0; i < 20; i++) {
		boxes[i] = random_letter(letters, 20); //boxes at index i is box number i+1 i.e. box at index 5 is box no 6
	}

	static int i = 0;
	do {
		//user input
		int user_input1, user_input2 = 0;
		char previous_char, next_char_found; 
		cout << "\nSize of boxes now is: " << boxes.size() << endl; 
		cout << "\nenter box number to choose: ";
		cin >> user_input1;
		if (user_input1 < 0 || user_input1 > 19) { 
			cout << "please choose a box in range of 1 to 20" << endl; 
			continue;
		}
		previous_char = boxes[user_input1 % 20 + 1];
		cout << "Letter in box numbered " << user_input1 << " is: "<< previous_char << endl; 
		getchar();
		//system("cls");//clear the screen

		cout << endl << "enter next box number to choose: ";
		cin >> user_input2;
		if (user_input1 < 0 || user_input1 > 19) {
			cout << "please choose a box in range of 1 to 20" << endl;
			continue;
		}
		if (user_input1 == user_input2) {
			cout << "please enter a different number what you entered in first turn!" << endl;
			continue;
		}
		next_char_found = boxes[user_input2 % 20 + 1];
		cout << "Letter in box numbered " << user_input2 << " is: " << next_char_found << endl;
		getchar();
		//system("cls");//clear the screen

		if (previous_char == next_char_found) {
			boxes.erase(boxes.begin() + user_input1 + 1);
			cout << "Size of boxes now is: " << boxes.size() << endl;
			boxes.erase(boxes.begin() + user_input2 + 1);
			cout << "Size of boxes now is: " << boxes.size() << endl;
		}
		else {
			i++;
			continue;
		}

		i++;
	} while ((i < 40) || (boxes.size() != 0));

	if (game_result(boxes)) {
		cout << "user won!" << endl;
		return 0;
	}
	else {
		cout << "user lost!" << endl;
	}
	return 0;
}