#ifndef POLYNOMIAL_H_EXISTS
#define POLYNOMIAL_H_EXISTS

#include "Polynomial.h"
#include "Term.h"

class Polynomial{
	private:
		Term* head;
		int count;
	public:
		Polynomial();
		Polynomial(std::string, char);
		~Polynomial();
		void setPolynomial(std::string, char);
		Term *get(int);
		void remove(int);
		void insert(Term*);
		bool exists(int);
		bool isEmpty();
		void printPolynomial();
		int terms();
		int degree();
		double evaluate(int);

};




#endif
