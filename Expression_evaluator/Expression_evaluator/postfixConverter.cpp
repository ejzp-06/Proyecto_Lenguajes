#include <iostream>
#include <string>
#include <any>
#include "postfixConverter.h"
#include "Stack.h"

using namespace std;

postfixConverter::postfixConverter()
{

}

postfixConverter::postfixConverter(string infixExpression)
{
	this->expression = infixExpression;
}

auto isANumber = [](char digit) { return (digit >= '0' && digit <= '9' || digit == '.');}; //TODO:generic lamda expression c++ 14 
																						   //TODO: automatic return type deduction c++ 14
																						   //TODO: auto automatic type deduction c++ 11
							
auto performOperation = [](double num1, double num2, string operation) 
{ 

	if (operation == "*")
		return (num1 * num2);
	else if(operation =="+")
		return num1 + num2;
	else if (operation == "-")
		return num1 - num2;
	else if (operation == "/")
		return num1 / num2;
	else if (operation == "^")
		return pow(num1,num2);
	else 
		return double((int)num1 % (int)num2);
};

bool postfixConverter::isAnOperator(char digit) 
{
	switch (digit)
	{
	case '+':
	case '-':
	case '*':
	case '/':
	case '^': 
	case '%': return 1;
	default: return 0;
	}
}

string postfixConverter::evaluate(Stack postfixExpression)
{
	Stack expression = postfixExpression;
	Stack resultant_Stack;
	
	int operations = numberOfOperations(expression);
	for (int i = 0; i < operations; i++)
	{
		//expression.print();
		//cout << endl;
		double num1 = 0;
		decltype (num1) num2 = 0; //TODO: decltype c++ 11
		Node* tmp = expression.first;
		while (tmp != nullptr)
		{
			if (tmp->character == "+" || tmp->character == "-" || tmp->character == "*" || tmp->character == "/" || tmp->character == "^" || tmp->character == "%") {
				if (isFloat(tmp->previous->previous->character))
					num1 = (float)atof(tmp->previous->previous->character.c_str());
				else
					num1 = (int)atof(tmp->previous->previous->character.c_str());

				if (isFloat(tmp->previous->character))
					num2 = (float)atof(tmp->previous->character.c_str());
				else
					num2 = (int)atof(tmp->previous->character.c_str());

				auto result = performOperation(num1, num2, tmp->character);
				Node *new_node = new Node(to_string(result));

				if (tmp->previous->previous== expression.first) {
					if (tmp->next==nullptr) {
						expression.first = new_node;
						expression.last = new_node;
						break;
					}

					expression.first = new_node;
					new_node->next = tmp->next;
					tmp->next->previous = new_node;
					break;
				}
				else {
					tmp->previous->previous->previous->next = new_node;
					new_node->previous = tmp->previous->previous->previous;
					new_node->next = tmp->next;
					tmp->next->previous= new_node;
				}
			}
			tmp = tmp->next;
		}
	}
	resultant_Stack = expression;
	return resultant_Stack.first->character;
}

string postfixConverter::convertExpression(string expression)
{
	Stack infixNotation;
	Stack operators;
	
	decltype(auto) expression_size = expression.size(); //TODO: decltype(auto) also deduces return types c++ 14
	string number = ""; 
  	for (int i = 0; i < expression_size; i++)
	{
		if(isANumber(expression[i]))
		{
			number += expression[i];
			if (isAnOperator(expression[i + 1]) || expression[i+1]==')' || expression[i+1] ==']'|| i == expression_size-1) {
				infixNotation.push(number);
				number = "";
			}
		}
		else if (isAnOperator(expression[i]))
		{

			string operator_ = "";
			operator_ += expression[i];
			while (!operators.isEmpty() &&hasHigherPrecedence(operators.last->character,operator_))
			{
				string top = operators.top()->character;
				infixNotation.push(operators.last->character);
				operators.pop();
			}

			operators.push(operator_);
			operator_ = "";
		}
		else if (expression[i] == '(') {
			string operator_ = "";
			operator_ += expression[i];
			operators.push(operator_);
			operator_ = ""; 

		}
		else if (expression[i] == ')') {
			while (operators.last->character != "(") {
				infixNotation.push(operators.last->character);
				operators.pop();
			}
			operators.pop();
		}

	}

	while (!operators.isEmpty()) {
		infixNotation.push(operators.last->character);
		operators.pop();
	}

	return evaluate(infixNotation);
}

bool postfixConverter::isCloseParenthesis(char character)
{
	return character == ')';
}

bool postfixConverter::isFloat(string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '.')
			return true;
	}

	return false;
}

int postfixConverter::getOperatorWeight(string character)
{
	if (character == "^")
		return 3;
	else if (character == "*" || character == "/" || character == "%")
		return 2;
	else if (character == "+" || character == "-")
		return 1;
	else return 0;
}
int postfixConverter::numberOfOperations(Stack postFixExpression)
{
	int contador = 0;
	string expression = convertToString(postFixExpression);
	for (int i = 0; i < expression.size(); i++)
	{
		if(isAnOperator(expression[i]))
			contador++;
	}

	return contador;

}
bool postfixConverter::hasHigherPrecedence(string character_0, string character_1)
{ 
	auto w1 =  getOperatorWeight(character_0);
	if (auto w2 = getOperatorWeight(character_1); w1 >= w2) //TODO: init- statements for if and switch  c++ 17
		return true;

	return false;

}

string postfixConverter::convertToString(Stack postfixExpression)
{
	Node* tmp = postfixExpression.first;
	string expression = "";

	while (tmp != nullptr)
	{
		expression += tmp->character+" ";
		tmp = tmp->next;
	}

	return expression;
}

