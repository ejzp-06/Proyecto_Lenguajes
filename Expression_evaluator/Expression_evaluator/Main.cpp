//
//
//#include <iostream>
//#include <string>
//#include <stdio.h>
//
//#include "Validator.h"
//#include "Stack.h"
//#include "postfixConverter.h"
//
//using namespace std;
//
//void main()
//{
//	int opcion;
//	string result;
//	postfixConverter converter;
//	cout << "*****************EVALUADOR DE EXPRESIONES*********************" << endl;
//	cout << "1. Ingresar una expresion." << endl;
//	cout << "2. Salir." << endl;
//	cout << "Ingrese la opcion: ";
//	cin >> opcion;
//
//	Validator *validator = new Validator;
//
//	while (opcion != 2) 
//	{
//		switch (opcion)
//		{
//		case 1:
//		{
//			system("cls");
//			string expression = "";
//			cout << "Ingrese la expresion: ";
//			cin >> expression;
//			if (validator->expression_isCorrect(expression))
//			{
//				result = converter.convertExpression(expression);
//				cout << "Resultado final: " << result << endl;
//			}
//			system("pause");
//		}
//		break;
//		case 2:
//			cout << "Hasta la proxima!" << endl;
//			system("pause");
//			break;
//		default:
//			cout << "Ese no es un valor valido!" << endl;;
//			system("pause");
//			break;
//		}
//
//	}
//
//	/*postfixConverter converter;
//	Stack result = converter.convertExpression("6+(5*5)");
//	result;*/
//}
//
