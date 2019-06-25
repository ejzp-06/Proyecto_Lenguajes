#pragma warning(disable: 4996)

#include "Validator.h"
#include <iostream>

using namespace std;

Validator::Validator()
{

}

bool Validator::validate_digits(string expression)
{
	int expression_size = expression.size()-1;
	char *tmp_expression = new char [expression_size];
	strcpy(tmp_expression, expression.c_str());

	for (int i = 0; i < expression_size; i++)
	{
		if (!validate_characters(tmp_expression[i]))
			return false;
	}

	return true;
}

bool Validator::validate_characters(char character)
{
	if (character == '0' || character == '.' || character == '1' || character == '2' || character == '3' || character == '4' || character == '5' || character == '6' || character == '7' || character == '8' || character == '9' || character == '(' || character == ')' || character == '*' || character == '/' || character == '^' || character == '+' || character == '-' || character == '[' || character == ']' || character == '%')
	{
		return true;
	}
	cout << "Error en la escritura de la expresion: Parece que ha escrito un digito ilegal." << endl;
	system("pause");
	return false;
}

bool Validator::validate_parenthesis(string expression)
{

	int expression_size = expression.size();
	char *tmp_expression = new char[expression_size];
	strcpy(tmp_expression, expression.c_str());
	int open_parenthesis = 0;

	for (int i = 0; i < expression_size; i++)
	{
		if (tmp_expression[i] == '(')
		{   //que le valga verga que hace esta parte del codigo
			if (tmp_expression[i + 1] == '*' || tmp_expression[i + 1] == '/' || tmp_expression[i + 1] == '^' || tmp_expression[i+1] == '+' || tmp_expression[i+1]=='-' || tmp_expression[i+1] == '%')
			{
				cout << "Error en la escritura de la expresion: Es posible que haya utilizado mal un operador." << endl;
 				return false;
			}
			else if (tmp_expression[i + 1] == ')') {
				cout << "Error en la escritura de la expresion: Es posible que haya utilzado mal un parentesis.";
				return false;
			}
			open_parenthesis++;
		}
		else if (tmp_expression[i] == ')' && open_parenthesis == 0) {
			//si un caracter es un ) y open parentesis es igual a 0, significa que no hay un par que de este parentesis
			cout << "Error en la escritura de la expresion: Es posible que no haya cerrado un parentesis." << endl;
			return false;
		}
		else if (tmp_expression[i] == ')' && isANumber(tmp_expression[i + 1])) {
			cout << "Error en la escritura de la expresion: Parece que le haya hecho falta escribir un operador." << endl;
			system("pause");
			return false;
		}
		else if (tmp_expression[i] == ')' && open_parenthesis > 0) {
			if (tmp_expression[i - 1] == '*' || tmp_expression[i - 1] == '+' || tmp_expression[i - 1] == '-' || tmp_expression[i - 1] == '/' || tmp_expression[i - 1] == '^' || tmp_expression[i-1] == '%')
			{
				cout << "Error en la escritura de la expresion: Es posible que haya utilizado mal un operador." << endl;
				return false;
			}
			open_parenthesis--;
		}
		else if (tmp_expression[i] == ')' && open_parenthesis > 0) {
			if (tmp_expression[i + 1] == '*' || tmp_expression[i +1] == '+' || tmp_expression[i + 1] == '-' || tmp_expression[i + 1] == '/' || tmp_expression[i+1] == '%' || tmp_expression[i + 1] == '^' && tmp_expression[i+2]!='(' )
			{
				cout << "Error en la escritura de la expresion: Es posible que haya utilizado mal un operador." << endl;
				return false;
			}
			open_parenthesis--;
		}
		else if (isANumber(tmp_expression[i]) && tmp_expression[i + 1] == '(') {
			cout << "Error en la escritura de la expression: Es posible que le haya hecho falta escribir un operador." << endl;
			return false;
		}
		else if (isAnOperator(tmp_expression[i]) && isAnOperator(tmp_expression[i + 1]))
		{
			cout << "Error en la escritura de la expression: Es posible que haya mal escrito un operador." << endl;
			return false;
		}
	}

    if (open_parenthesis > 0) {
		cout << "Error en la escritura de la expresion: Es posible que no haya cerrado un parentesis." << endl;
		return false;
	}
	return true;
}

bool Validator::validate_incompleteExpression(string expression)
{

	int expression_size = expression.size()-1;
	char *tmp_expression = new char[expression_size];
	strcpy(tmp_expression, expression.c_str());
    if (tmp_expression[0] == '+' || tmp_expression[0] == '-' || tmp_expression[0] == '*' || tmp_expression[0] == '/' || tmp_expression[0] == '^' || tmp_expression[0]=='%')
	{
		cout << "Error en la escritura de la expresion: Es posible que haya utilizado mal un operador." << endl;
		return false;
	}
	else if (tmp_expression[expression_size] == '+' || tmp_expression[expression_size] == '-' || tmp_expression[expression_size] == '*' || tmp_expression[expression_size] == '/' || tmp_expression[expression_size] == '^' || tmp_expression[expression_size] == '%')
	{
		cout << "Error en la escritura de la expresion: Es posible que haya utilizado mal un operador." << endl;
		return false;
	}
	return true;
}

bool Validator::isANumber(char character)
{
	if (character >= '0' && character <= '9')
		return true;

	return false;
}

bool Validator::isAnOperator(char character)
{
	switch (character)
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

bool Validator::expression_isCorrect(string expression)
{
	return (validate_digits(expression) && validate_incompleteExpression(expression) && validate_parenthesis(expression));
}
