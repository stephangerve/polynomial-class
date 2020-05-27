#ifndef TERM_H_EXISTS
#define TERM_H_EXISTS

#include <iostream>

class Term{
	private:
		double coefficient;
		char variable;
		int exponent;
		Term *next;



	public:
		Term();
		Term(double, char, int);
		double getCoefficient();
		void setCoefficient(double);
		char getVariable();
		void setVariable(char);
		int getExponent();
		void setExponent(int);
		Term* getNext();
		void setNext(Term*);
		void printData();
		double evaluate(int);	




};



#endif
