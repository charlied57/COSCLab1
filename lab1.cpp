// lab1.cpp : Defines the entry point for the console application.
//Charles Davis Lab 1
//This program takes an input file that is defined bu the user and outputs how many numbers are in the file, the first two numbers, and the last two numbers.
//It then had the user type in a character and hit return to terminate the program.  It does this so that the console doesn't close befor the user can view the results.


#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

//The included functions from the standard namespace
using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::ifstream;
using std::ios;

//Start main function
int main() {
	//Have uset input the file name
	string end;
	string filename;
	cout << "File name: ";
	cin >> filename;

	//Open the file
	ifstream file(filename);

	//Checks if the file is open
	if (file.is_open())
	{
		//intializes the intagers that will get used within the if statement
		int input;
		int first_value = 0;
		int second_value = 0;
		int second_to_last_value = 0;
		int last_value = 0;
		int count = 0;

		//Counts how many numbers are in the file
		while (!file.eof()) {
			file >> input;
			count++;
		}

		//Resets the file pointer back to the begining of the file
		file.clear();
		file.seekg(0, ios::beg);

		//If statement for 0 or one elements
		if (count == 1) {
			file >> input;

			//If the file doesnt have an element then input is defaulted to zero and then the program is terminated after a messege is printed and the user ends the program
			if (input == 0) {
				file.close();
				cout << "This file is empty." << endl;
				cout << "Hit any key followed by return to end the program" << endl;
				cin >> end;
				return 0;
			}

			//If the file has one element then it is printed and the program terminates
			first_value = input;
			file >> input;
			cout << "This file contains " << count << " integer.\n";
			cout << "The only value is " << first_value << ".\n";
			file.close();
			cout << "Hit any key followed by return to end the program" << endl;
			cin >> end;
			return 0;
		}

		//If the file has two numbers then they are printed in this function and the program terminates
		else if (count == 2) {
			file >> input;
			first_value = input;
			file >> input;
			last_value = input;
			cout << "This file contains " << count << " integers.\n";
			cout << "The first value is " << first_value << ".\n";
			cout << "The last value is " << last_value << ".\n";
			file.close();
			cout << "Hit any key followed by return to end the program" << endl;
			cin >> end;
			return 0;
		}

		//If the file has three numbers then they are printed in this function and the program terminates
		else if (count == 3) {
			file >> input;
			first_value = input;
			file >> input;
			second_value = input;
			file >> input;
			last_value = input;
			cout << "This file contains " << count << " integers.\n";
			cout << "The first value is " << first_value << ".\n";
			cout << "The middle value is " << second_value << ".\n";
			cout << "The last value is " << last_value << ".\n";
			file.close();
			cout << "Hit any key followed by return to end the program" << endl;
			cin >> end;
			return 0;
		}

		//This section runs when the file has four or more numbers in it
		else {
			//Set the first four numbers in the file as the four output values
			file >> input;
			first_value = input;
			file >> input;
			second_value = input;
			file >> input;
			second_to_last_value = input;
			file >> input;
			last_value = input;

			//This loops until the end of the file.  The loop runs x times based on the first time the program ran through the file and determined the number of numbers in the file
			for (int i = 5; i < count; i++) {
				//Sets the last number to be the second to last number
				second_to_last_value = last_value;
				//Pulls the next number from the file
				file >> input;
				//Sets the just pulled number to the last number
				last_value = input;
			}
		}

		//This block of outputs only runs if the file had four or more numbers
		file.close();
		cout << "This file contains " << count - 1 << " integers.\n";
		cout << "The first value is " << first_value << ".\n";
		cout << "The second value is " << second_value << ".\n";
		cout << "The second to last value is " << second_to_last_value << ".\n";
		cout << "The last value is " << last_value << ".\n";
	}

	//If the file name typed in is nor reconized then this else statement is ran
	else {
		cout << "Invalid file name\n";
	}

	//If the file has more than four numbers then this is the termination of the program.  This method is used so that the console window doesn't dissapear befor the user can read it
	cout << "Hit any key followed by return to end the program" << endl;
	cin >> end;
	return 0;
}