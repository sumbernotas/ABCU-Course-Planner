#include <iostream>
#include <regex>
#include <cstring>
#include "CourseBST.h"

//initializes the root of the tree
CourseBST::CourseBST() {
	root = nullptr;
}

//initializes the function to recursively remove all nodes from a binary tree
CourseBST::~CourseBST() {
	destroyRecursive(root);
}

// initializes the inOrder() function for BST by passing the root
void CourseBST::InOrder() {
	inOrder(root);
}

// initializes the postOrder() function for BST by passingthe root
void CourseBST::PostOrder() {
	postOrder(root);
}

// initializes the preOrder() function for BST by passing the root
void CourseBST::PreOrder() {
	preOrder(root);
}

// defines a function to insert a node to the tree, the node being inserted is what is passed as a parameter
void CourseBST::Insert(Course t_course) {
	if (root == nullptr) { // if root node is null, assign the root to the new node
		root = new Node(t_course);
	}
	else { // if root node is not null, call the function to add the node to the tree
		this->addNode(root, t_course);
	}
}

// initializes a function to remove a node from the tree, the node being removed is what is passed as a parameter
void CourseBST::Remove(string t_courseID) {
	this->removeNode(root, t_courseID);
}

// defines a function to search the binary tree for a specific node, which is the one being passed
Course CourseBST::Search(string t_courseID) {
	// converts all characters on t_courseID to upper case to improve search
	transform(t_courseID.begin(), t_courseID.end(), t_courseID.begin(), ::toupper);

	Node *currentNode = root; // assigns the current node as root to begin

	// while current node is not null, checks if node matches the node being searched for
	while (currentNode != nullptr) {
		if (currentNode->course.getCourseID().compare(t_courseID) == 0) { // if node matches the nodes that searched for, it returns the node
			return currentNode->course;
		}
		else if (t_courseID.compare(currentNode->course.getCourseID()) < 0) { // if current node does not match node being searched for, it checks the left tree
			currentNode = currentNode->left;
		}
		else { // if left tree does not match, it checks the right tree
			currentNode = currentNode->right;
		}
	}

	Course course; // initializes a member of the class Course
	return course; // returns matched course member
}

// defines a function to add a node to a tree
void CourseBST::addNode(Node *node, Course course) {
	if (node != nullptr) { // if node is not null, begin to add node
		if (node->course.getCourseID().compare(course.getCourseID()) > 0) { // if course ID node is greater than root
			if (node->left == nullptr) { // if left node is null, add node to left
				node->left = new Node(course);
				return;
			}
			else { // if node is not null, repeat process
				this->addNode(node->left, course);
			}
		}
		else if (node->course.getCourseID().compare(course.getCourseID()) < 0) { // if course ID node is less than root
			if (node->right == nullptr) { // if right node is null, add node to right
				node->right = new Node(course);
				return;
			}
			else { // if right node is not null, repeat process
				this->addNode(node->right, course);
			}
		}
	}
}

// defines function to recursively delete all nodes of tree
void CourseBST::destroyRecursive(Node *node) {
	if (node != nullptr) { // if node is not null, delete node
		destroyRecursive(node->left);
		destroyRecursive(node->right);

		delete node;
		node = nullptr;
	}
}

// defines functions to output tree in order from left to right
void CourseBST::inOrder(Node *node) {
	if (node != nullptr) { // if node is not null
		inOrder(node->left); // go to left 

		cout << node->course.getCourseID() << ", " << node->course.getCourseName() << endl; // output nodes information to console

		inOrder(node->right); // go to right 
	}
}

// defines function to output tree in post order form
void CourseBST::postOrder(Node *node) {
	if (node != nullptr) { // if node is not null
		postOrder(node->left); // go to left
		postOrder(node->right); // go to right

		cout << node->course.getCourseID() << ", " << node->course.getCourseName() << endl; // output nodes information to console
	}
}

// defines function to output tree in pre-order form
void CourseBST::preOrder(Node* node) {
	if (node != nullptr) { // if node is not empty
		cout << node->course.getCourseID() << ", " << node->course.getCourseName() << endl; // output nodes information to console

		postOrder(node->left); // go to left node
		postOrder(node->right); // go to right node
	}
}

// defines a function to remove a single node from a tree
Node* CourseBST::removeNode(Node *node, string courseID) {
	if (node == nullptr) { // if node is null
		return node; // return node
	}
	else if (courseID.compare(node->course.getCourseID()) < 0) { // if wanted course does not match current left
		node->left = removeNode(node->left, courseID); // repeat process
	}
	else if (courseID.compare(node->course.getCourseID()) > 0) { // if wanted course does not match current right
		node->right = removeNode(node->right, courseID); // repeat process
	}
	else { 
		if (node->left == nullptr && node->right == nullptr) { // if nodes left and right pointers are null, delete the node
			delete node;
			node = nullptr;
		}
		else if (node->left != nullptr && node->right == nullptr) { // if nodes right pointer is null but left is not, delete right node
			Node* temp = node;
			node = node->left;
			delete temp;
			temp = nullptr;
		}
		else if (node->left == nullptr && node->right != nullptr) { // if nodes left pointer is null but right is not, delete left node
			Node* temp = node;
			node = node->right;
			delete temp;
			temp = nullptr;
		}
		else { 
			Node* temp = node;
			while (temp->left != nullptr) {
				temp = temp->left;
			}
			node->course = temp->course;
			node->right = removeNode(node->right, temp->course.getCourseID());
		}
	}
}