#pragma once
#ifndef ABCUADVISING_COURSEDATA_H
#define ABCUADVISING_COURSEDATA_H
#endif

#include <string>
#include <vector>

using namespace std;

// class to hold all course information
class Course {
	public:
		// initializes all public functions in the course class
		void setCourseID(string t_courseID);
		void setCourseName(string t_courseName);
		void setCoursePrerequisites(vector<string> t_prerequisites);

		string getCourseID();
		string getCourseName();
		vector<string> getCoursePrerequisites();

	private:
		// initializes all private variables in the course class
		string m_courseID;
		string m_courseName;
		string m_coursePrerequisites;
		vector<string> m_preReqList;
};

