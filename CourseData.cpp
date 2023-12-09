#include <iostream>
#include <iomanip>
#include <vector>
#include "CourseData.h"

using namespace std;

// function to set the course ID of the course member
void Course::setCourseID(string t_courseID) {
	this->m_courseID = t_courseID;
}

// function to set the course name of the course member
void Course::setCourseName(string t_courseName) {
	this->m_courseName = t_courseName;
}

// function to set the prerequisites required for the course member
void Course::setCoursePrerequisites(vector<string> t_prerequisites) {
	this->m_preReqList = t_prerequisites;
}

// function to return the courseID
string Course::getCourseID() {
	return this->m_courseID;
}

// function to return the course name
string Course::getCourseName() {
	return this->m_courseName;
}

// function to return the vector list of courses prerequisites
vector<string> Course::getCoursePrerequisites() {
	return this->m_preReqList;
}





