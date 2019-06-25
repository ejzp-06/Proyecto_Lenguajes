#include "Stack.h"
#include <iostream>


Stack::Stack()
{
	this->first = nullptr;
	this->last = nullptr;
}

void Stack::push(std::string character)
{
	Node *tmp = new Node(character);

	if (isEmpty())
	{
		this->first = tmp;
		this->last = tmp;
		return;
	}

	this->last->next = tmp;
	tmp->previous = this->last;
	this->last = tmp;
}

void Stack::pop()
{
	if (isEmpty())
	{
		return;
	}

	Node *tmp = new Node;
	tmp = top();

	if (tmp == this->last)
	{
		this->last = 0;
		this->first = 0;
		return;
	}

	while (tmp->next != 0) {
		tmp = tmp->next;
	}

	this->last = tmp->previous;
	this->last->next = 0;
}

void Stack::print()
{

	Node *tmp = top();

	while (tmp != nullptr) {
		std::cout << tmp->character<<", ";
		tmp = tmp->next;
	}
}

Node* Stack::top()
{
	if (isEmpty())
		return 0;

	Node *tmp = new Node;
	tmp = this->first;
	return tmp;
}

Node* Stack::bottom()
{
	if (isEmpty())
		return 0;

	Node *tmp = new Node;
	tmp = this->last;
	return tmp;
}

int Stack::searchParenthesis(Stack operators)
{
	int counter = 0b0; //TODO: binary literals c++ 14

	auto* tmp{operators.first}; //TODO: direct list initialization c++ 17

	while (tmp->next != operators.last)
	{
		if (tmp->character == "(")
			return counter;

		counter++;
	}

	return counter;
}

int Stack::getSize()
{
	int contador = 0;
	Node* tmp = this->first;

	while (tmp != nullptr) {
		tmp = tmp->next;
		contador++;
	}

	return contador;
}

bool Stack::isEmpty()
{
	return (this->first == nullptr); //TODO:nullptr c++ 11

}
