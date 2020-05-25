#ifndef POLYNOMIAL_H_EXISTS
#define POLYNOMIAL_H_EXISTS

#include "Polynomial.h"

class Polynomial{
	private:
		Term* head;
		int count;
	public:
		Polynomial();
		~Polynomial();
		void setPolynomial(std::string, std::string);
		Term *get(int);
		void remove(int);
		void insert(Term*);
		bool exists(int);
		bool isEmpty();
		void printPolynomial();
		int terms();
		int degree();
		double evaluate(int);

}




#endif
