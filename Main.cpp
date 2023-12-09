/////////////////////////////////////////
///// Name: Summer Bernotas ////////////
///// Professor Jamaliannasrabadi //////
///// CS-300 DSA: Analysis and Design //
///// December 2023 ////////////////////
////////////////////////////////////////

#include <iostream>
#include <string>
#include "MainData.h"
#include "CourseData.h"
#include "CourseBST.h"

using namespace std;

int main() {
	// declares a binary search tree member of CourseBST as courseBST
	CourseBST* courseBST; 
	courseBST = new CourseBST(); 

	Course course; // declares a member of the course class called course

	// initializes variables for program
	int userMenuInput;
	string userInput;
	bool running = true;

	cout << "Welcome to the course planner!" << endl << endl; // outputs welcome message to the console

	while (running == true) { // while loop to execute while program is running

		outputDisplay(); // calls function to output the program's menu
		cin >> userMenuInput; // takes user input for menu navigation

		switch (userMenuInput) { // switch statement to determine user's menu option
			case 1: // executes if user wants to load data structure to program, option #1
				system("cls"); // clears screen

				cout << "Please enter the name of the file. "; // outputs message for name of file onto console
				cin >> userInput; // takes user input for file name

				loadDataStructure(userInput, courseBST); // calls a function to load and create an object of the file

				cout << endl;
				break; 
			case 2: // executes if user wants to print the entire list from file, option #2
				system("cls"); // clears screen

				cout << "Here is a sample schedule" << endl << endl; 
				courseBST->InOrder(); // calls InOrder() function from the binary tree created from loading the data structure to print all objects onto the console
				
				cout << endl;
				break;
			case 3: // executes if user wants to print information from a specific course, option #3
				system("cls"); // clears screen
				
				cout << "Please enter course ID. ";
				cin >> userInput; // takes user input for wanted course ID

				cout << endl;
				course = courseBST->Search(userInput); // calls function to search the binary tree created from loading the data structure to print specific course information
				printCourse(course); // outputs the found courses information

				cout << endl;
				break;
			case 9: // executes if user decides to exit the program, option #9
				cout << "Thank you for using the course planner!" << endl; // prints exit message to console
				running = false; // assigns running variable as false
				break;
			default: // executes if user does input a valid menu option
				cout << "That is not a valid option." << endl << endl;
				break;
		}

	}
	

	return 0;
}