#pragma once

#include <string>
#include "Stack.h"

using namespace std;

class postfixConverter
{
public:

	string expression;

	postfixConverter();
	postfixConverter(string infixExpression);

	bool isAnOperator(char digit);
	bool isCloseParenthesis(char character);
	bool isFloat(string str);

	int getOperatorWeight(string character);
	int numberOfOperations(Stack postFixExpression);
	

	bool hasHigherPrecedence(string character_0, string character_1);
	string evaluate(Stack);


	string convertToString(Stack postfixExpression);
	string convertExpression(string expression);
};