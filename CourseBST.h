#pragma once
#ifndef ABCUADVISING_COURSEBST_H
#define ABCUADVISING_COURSEBST_H
#endif

#include <vector>
#include <string>
#include "CourseData.h"

using namespace std;

// declares a struct for the trees nodes
struct Node {
	Course course; // declares a member of the class course
	Node *left;  // declares a pointer to the left node
	Node *right; // declares a pointer to the right node

	Node() { // initializes each node to start as null
		left = nullptr;
		right = nullptr;
	}

	Node(Course t_course) : Node() {
		course = t_course;
	}
};

// a class to hold the binary tree
class CourseBST {
	public:
		// initializes public variables and functions of the CourseBST class
		CourseBST();
		virtual ~CourseBST();
		
		void InOrder();
		void PostOrder();
		void PreOrder();
		void Insert(Course t_course);
		void Remove(string t_courseID);

		Course Search(string t_courseID);

	private:
		// initializes private variables and functions of the CourseBST class
		Node* root;
		Node* removeNode(Node* node, string courseID);

		void destroyRecursive(Node *node);
		void addNode(Node *node, Course course);
		void inOrder(Node *node);
		void postOrder(Node *node);
		void preOrder(Node *node);
};
