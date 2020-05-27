#include <iostream>
#include "Polynomial.h"


int main(){
	Polynomial* poly1 = new Polynomial("x^2+10", 'x');
	poly1->printPolynomial();
	std::cout << "Terms: " << poly1->terms() << std::endl;
	std::cout << "Evaluating x = 4: " << poly1->evaluate(4) << std::endl;


	
	





}
