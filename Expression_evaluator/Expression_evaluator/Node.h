#pragma once

#include <string>

class Node
{
public:

	Node *next;
	Node *previous;
	std::string character;

	Node(std::string character) : character(character),next(nullptr),previous(nullptr){}  //TODO:delegating constructors c++ 11
	Node() : Node("s") {}
};