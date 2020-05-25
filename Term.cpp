#include "Term.h"
#include <iostream>
#include <cmath>

Term::Term(){
	next = NULL;
	
}

Term::Term(double coefficient, std::string variable, int exponent){
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

std::string Term::getVariable(){
	return variable;
}

void Term::setVariable(std::string variable){
	this->variable = variable;
}

int Term::getExponent(){
	return exponent;
	
}

void Term::setExponent(int exponent){
	this->exponent = exponent;
}

Term* Term::getNext(){
	rteurn next;
}

void Term::setNext(Term* next){
	this->next = next;
}

void Term::printData(){
	std::cout << coefficient << variable << "^" << exponent; 
}

double Term::evaluate(int x){
	return coefficient * std::pow(x, exponent);
}
