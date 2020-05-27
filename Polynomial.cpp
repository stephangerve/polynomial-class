#include "Polynomial.h"
#include "Term.h"
#include <iostream>
#include <sstream>

Polynomial::Polynomial(){
	head = NULL;

	std::string expression;
	char variable;
	std::cout << "Enter the expression: " << std::endl;
        std::cin >> expression;
	std::cout << "Enter the variable: " << std::endl;
	std::cin >> variable;
	this->setPolynomial(expression, variable);
}

Polynomial::Polynomial(std::string expression, char variable){
	head = NULL;
	
	this->setPolynomial(expression, variable);
}
Polynomial::~Polynomial(){
	Term* temp = head;
	for(int i = 0; i < terms(); i++){
		temp = head->getNext();
		delete head;
		count--;
		head = temp;
	}
}

void Polynomial::setPolynomial(std::string expression, char variableChar){
        std::string term, coeffVar, coeffStr, variableStr(1,variableChar), expStr;
        double coefficient;
	int exponent;
        std::stringstream tokenizer, parser, coeffParser, converter;

        tokenizer.clear();
        tokenizer.str(expression);
        while(getline(tokenizer, term, '+')){
		
		//Coefficient and Variable w/o exponent
                parser.clear();
                parser.str(term);
                getline(parser, coeffVar, '^');
                
		//Coefficient
                coeffParser.clear();
                coeffParser.str(coeffVar);
                getline(coeffParser, coeffStr, variableChar);
                if(coeffStr == ""){
                        coefficient = 1;
                }
                else{
                       	converter.clear();
			converter.str("");	
			converter << coeffStr;
                        converter >> coefficient;
                }

                //Exponent
                if(term == coeffStr + variableStr || term == variableStr){
			exponent = 1;
                }
                else if(term == coeffStr){
			exponent = 0;
                }
                else{
                        getline(parser, expStr, '\0');
			converter.clear();
			converter.str("");	
			converter << expStr;
                        converter >> exponent;
                }
                this->insert(new Term(coefficient, variableChar, exponent));


        }



}
Term* Polynomial::get(int k){
	Term* temp = head;
	if(this->exists(k) == false){
		std::cout << "Invalid index." << std::endl;
	}
	else{
		for(int i = 0; i < k; i++){
			temp = temp->getNext();
		}	
	}
	return temp;
}

void Polynomial::remove(int k){
	Term* prevTerm;
	Term* nextTerm;
	Term* temp = head;
	for(int i = 0; i < k; i++){
		prevTerm = temp;
		temp = temp->getNext();
	}
	nextTerm = temp->getNext();
	temp->setNext(NULL);
	delete temp;
	if(k == 0){
		head = nextTerm;
	}
	else{
		prevTerm->setNext(nextTerm);
	}
	count--;
}

void Polynomial::insert(Term* T){
	T->setNext(head);
	head = T;
	count++;
}
bool Polynomial::exists(int k){
    if(k > this->terms() || k < 0 || count == 0){
	std::cout << "Invalid index." << std::endl;
        return false;
    }
    else{
 	return true;
    }

}
bool Polynomial::isEmpty(){
	if(count == 0){
        	return true;
        }
        else if(count > 0){
                return false;
        }

}
void Polynomial::printPolynomial(){
	Term* temp = head;
        std::cout << "P(" << temp->getVariable() << ")=";
	for(int i = 0; i < terms(); i++){
		temp->printData();
		if(i + 1 < terms()){
			std::cout << "+";
		}
                temp = temp->getNext();
        }
        std::cout << std::endl;

}
int Polynomial::terms(){
	return count;
}
int Polynomial::degree(){

}
double Polynomial::evaluate(int x){
	Term* temp = head;
	double answer = 0.0;
	for(int i = 0; i < terms(); i++){
		answer += temp->evaluate(x);
		temp = temp->getNext();
	}
	return answer;
}


