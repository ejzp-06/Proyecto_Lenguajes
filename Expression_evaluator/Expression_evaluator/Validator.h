#pragma once

#include <string>

using namespace std;

class Validator {
public:

	Validator();


	//functions used to validate if expression is correct
	bool validate_digits(string expression);
	bool validate_characters(char character);
	bool validate_parenthesis(string expression);
	bool validate_incompleteExpression(string expression);
	bool isANumber(char character);
	bool isAnOperator(char character);
	bool expression_isCorrect(string expression);

};