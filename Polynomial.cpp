#include "Polynomial.h"
#include <iostream>
#include <sstream>

Polynomial::Polynomial(){
	head = NULL;
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

void Polynomial::setPolynomial(std::string expression, std::string variable){
	std::string term, coeff, var, exp;
	std::stringstream termParser, coeffParser, varParser, expParser;
	
	termParser.clear();
	termParser.str("");
	termParser.str(expression);
	
	getline(termParser, term, '+');	
	getline(termParser, term, '-');
	
	coeffParser.clear();
	coeffParser.str("");
	coeffParser.str(term);

	std::strcat(varible, "^");
	getline(coeffParser, coeff, variable);
		
	expParser.clear();
	expParser.str("");
	expParser.str(
}
Term* Polynomial::get(int k){
	Node* temp = head;
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
		prevNode = temp;
		temp = temp->getNext();
	}
	nextNode = temp->getNext();
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
        std::cout << "P(" << temp->getVariable() << ") = " << std::endl;
	for(int i = 0; i < terms(); i++){
                temp->printData();
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


