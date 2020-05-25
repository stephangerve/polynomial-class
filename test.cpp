#include <iostream>
#include <sstream>
#include "string.h"

int main(){
	std::string line = "5x^4+3x^2+1", term, coeffVar, coeff, exp;
	char var = 'x';
	std::stringstream parser;
	line += "+";
	parser.clear();
	parser.str(line);
	int i = 0;
	while(term != ""){
		i++;
		std::cout << i << ") ";	
		getline(parser, term, '+');
		std::cout << term << std::endl;
	}
	std::cout << "End" << std::endl;
	/*parser.str(term);
	getline(parser, coeffVar, '^');
	std::cout << coeffVar << std::endl;
	getline(parser, exp, '\0');
	std::cout << exp << std::endl;
	parser.clear();
	parser.str(coeffVar);
	getline(parser, coeff, 'x');
	std::cout << coeff << std::endl;
*/
}
