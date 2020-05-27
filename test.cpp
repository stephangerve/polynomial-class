#include <iostream>
#include <sstream>
#include "string.h"

int main(){
	std::string line = "5x^4+3x^2+x+-2x+100+50x^2+10x", term, coeffVar, coeff, exp;
	char variableChar = 'x';
	std::string variableStr(1,variableChar);
	std::stringstream tokenizer, parser, coeffParser;
	tokenizer.clear();
	tokenizer.str(line);
	int i = 0;
	std::cout << line << std::endl;
	while(getline(tokenizer, term, '+')){
		i++;
		std::cout << std::endl;
		std::cout << i << ") ";	
		std::cout << "term: " << term << std::endl;
		
		//Coefficient and Variable w/o exponent
		parser.clear();
		parser.str(term);
		getline(parser, coeffVar, '^');
		std::cout << "Coefficient-variable: " << coeffVar << std::endl;
		
		//Coefficient
		coeffParser.clear();
		coeffParser.str(coeffVar);
		getline(coeffParser, coeff, variableChar);
		if(coeff == ""){
			coeff = "1";
		}
		std::cout << "Coefficient: " << coeff << std::endl;
		
		//Exponent
		if(term == coeff + variableStr || term == variableStr){
			std::cout << "Exponent: 1" << std::endl;
		}
		else if(term == coeff){
			std::cout << "Exponent: 0" << std::endl;
			
		}
		else{	
			getline(parser, exp, '\0');
			std::cout << "Exponent: " << exp << std::endl;
		}
			
	}
	//std::cout << "End" << std::endl;
	/*parser.str(term);
	getline(parser, coeffVar, '^');
	std::cout << coeffVar << std::endl;
	getline(parser, exp, '\0');
	std::cout << exp << std::endl;
	parser.clear();
	parser.str(coeffVar);
	getline(parser, coeff, 'x');
	std::cout << coeff << std::endl;*/

}
