#pragma once

#include "Node.h"

class Stack
{
public:
	
	Node *first;
	Node *last;


	void push(std::string character); 
	void pop();
	void print();

	Stack();

	Node* top();
	Node* bottom();

	int searchParenthesis(Stack);
	int getSize();
	bool isEmpty();


};