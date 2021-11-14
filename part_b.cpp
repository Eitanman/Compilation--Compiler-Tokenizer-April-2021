#include <iostream>
#include <stack>
#include "tokens.hpp"



int main()
{
	std::stack<int> s; // stack for the left parenthesis (and braces).
	unsigned int parenCount = 0; // counter for the number of open parenthesis.
	int token;
	while(token = yylex()) {
		if ( ( token == LPAREN ) || ( token == LBRACE ) ) {
			s.push(token);
			// printing:
			for ( unsigned int i = 0; i < parenCount; i++) {
				std::cout << "\t";
			}
			std::cout << yytext;
			parenCount++;
		}
		else if ( ( token == RPAREN ) || ( token == RBRACE ) ) {
			if ( s.empty() || ( (token == RPAREN) && (s.top() == LBRACE) ) 
				|| ( (token == RBRACE) && (s.top == LPAREN) ) ) {
				std::cout << "Error: Bad Expression\n";
				exit(0);
			}
			// else:
			parenCount--;
			s.pop();
			for ( unsigned int i = 0; i < parenCount; i++) {
				std::cout << "\t";
			}
			std::cout << yytext;
		}
		else if ( token == illegal_char ) {
			std::cout << "Error " << yytext << std::endl;
		}
		else {
			std::cout << "Error: " << TokenTypes[token] << std::endl;
		}
	}
	return 0;
}