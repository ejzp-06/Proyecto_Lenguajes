
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "postfixConverter.h"
#include "Validator.h"

postfixConverter converter;
Validator validator;

TEST_CASE("Check Outputs") {
	REQUIRE(converter.convertExpression("3*3")== ("9.000000"));
	REQUIRE(converter.convertExpression("3-3") == ("0.000000"));
	REQUIRE(converter.convertExpression("3+3") == ("6.000000"));
	REQUIRE(converter.convertExpression("3/3") == ("1.000000"));
	REQUIRE(converter.convertExpression("3%3") == ("0.000000"));
	REQUIRE(converter.convertExpression("(1+3)+9*9") == ("85.000000"));
	REQUIRE(converter.convertExpression("(1+3)+9*2") == ("22.000000"));
	REQUIRE(converter.convertExpression("(1+3)+2*9") == ("22.000000"));
	REQUIRE(converter.convertExpression("2.5+0.5") == ("3.000000"));
	
}
TEST_CASE("Check expression") {
	REQUIRE(validator.expression_isCorrect("5+694+5")== true);
	REQUIRE(validator.expression_isCorrect("5+694/+5") == false);
	REQUIRE(validator.expression_isCorrect("((((5+5))))") == true);
	REQUIRE(validator.expression_isCorrect("5+") == false);
	REQUIRE(validator.expression_isCorrect("5++5") == false);

}

