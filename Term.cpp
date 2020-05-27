#include "Term.h"
#include <iostream>
#include <cmath>

Term::Term(){
	next = NULL;
	
}

Term::Term(double coefficient, char variable, int exponent){
	this->coefficient = coefficient;
	this->variable = variable;
	this->exponent = exponent;	
	next = NULL;

}

double Term::getCoefficient(){
	return coefficient;

}

void Term::setCoefficient(double coefficient){
	this->coefficient = coefficient;

}

char Term::getVariable(){
	return variable;
}

void Term::setVariable(char variable){
	this->variable = variable;
}

int Term::getExponent(){
	return exponent;
	
}

void Term::setExponent(int exponent){
	this->exponent = exponent;
}

Term* Term::getNext(){
	return next;
}

void Term::setNext(Term* next){
	this->next = next;
}

void Term::printData(){
	if(coefficient != 1 && coefficient != -1 && coefficient != 0){
		std::cout << coefficient;
	}
	if(exponent != 1 && exponent != 0){
		std::cout << variable << "^" << exponent; 
	}
	else if(exponent == 1){
		std::cout << variable;
	}
}

double Term::evaluate(int x){
	return coefficient * std::pow(x, exponent);
}
