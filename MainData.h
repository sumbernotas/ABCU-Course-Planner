#pragma once
#ifndef ABCUADVISING_MAINDATA_H
#define ABCUADVISING_MAINDATA_H
#endif


#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <regex>
#include "CourseBST.h"
#include "CourseData.h"

using namespace std;

// defines a function to output the program's menu options
void outputDisplay() {
	cout << "   1. Load Data Structure" << endl;
	cout << "   2. Print Course List" << endl;
	cout << "   3. Print Course" << endl;
	cout << "   9. Exit" << endl << endl;
	cout << "What would you like to do? ";
}

// defines a function to load the data structure and sort it into an object
void loadDataStructure(string& fileName, CourseBST* courseBST) {
	ifstream inputFile(fileName); // initializes the file
	string currentLine; // declares a varaible to hold the current line of text being read in the file

	if (!inputFile.is_open()) { // if the file does not open, display an error message to the console
		cout << "File was unable to be opened." << endl << endl;
	}
	else { // if file was opened, create object and display success message
		while (getline(inputFile, currentLine)) { // while there is still information in the file
			stringstream ss(currentLine);  // initializes stringstream to convert data of strings into substrings
			string courseID;               
			string courseName;             //////////
			string line;                   // initializes variables for each aspect of the course
			vector<string> preReq;         ///////////

			int i = 0;
			while (!ss.eof()) { // while it is not the end of line
				getline(ss, line, ','); // seperate substring by comma
				line = regex_replace(line, regex(R"(\r\n|\r|\n)"), ""); // uses regex expression to replace line and checks escape sequence (line breaks)

				if (i == 0) { // if system is reading the first string, assign it as the courseID
					courseID = line;
				}
				else if (i == 1) { // if system is reading the second string, assign it as the courseName
					courseName = line;
				}
				else { // all lines after the second are appended to the prerequisite vector
					preReq.push_back(line);
				}

				i++;
			}

			Course course; // creates a new member of the Course class for the specific course being read by the compiler
			course.setCourseID(courseID); // sets the members courseID
			course.setCourseName(courseName); // sets the members courseName
			course.setCoursePrerequisites(preReq); // sets the members prerequisites

			courseBST->Insert(course); // inserts this course into the binary tree
		}

		cout << fileName << " has successfully opened." << endl << endl; // outputs success message
		inputFile.close(); // closes the file
	}
}

// defines a function to print a specific course
void printCourse(Course course) {
	vector<string> preReq = course.getCoursePrerequisites(); // calls the function to get the prerequisites for the selected class
	string coursePrerequisites; // declares a variable which will hold the classes prerequisites

	if (preReq.size() == 1) { // if there is only one prerequisite for the class
		coursePrerequisites = course.getCoursePrerequisites()[0]; // print the first element in the prerequisite vector
	}
	else if (preReq.size() > 1) { // if there are more than one prerequisite for the class
		for (int i = 0; i < preReq.size() - 1; i++) { // go through each element in the vector
			coursePrerequisites += preReq[i] + ", "; // puts the class from the vector into the string
		}

		coursePrerequisites += preReq.back(); // adds last element of the vector into the string
	}
	else { // if there are not prerequisites, it returns "N/A"
		coursePrerequisites = "N/A";
	}

	cout << course.getCourseID() << ", " << course.getCourseName() << endl; // outputs the courses ID and name to console
	cout << "Prerequisites: " << coursePrerequisites << endl; // outputs the courses prerequisites to the console using the created string
}