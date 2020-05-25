#ifndef TERM_H_EXISTS
#define TERM_H_EXISTS

class Term{
	private:
		double coefficient;
		std::string variable;
		int exponent;
		Term *next;



	public:
		Term();
		Term(double, std::string, int);
		~Term();
		double getCoefficient();
		void setCoefficient(double);
		std::string getVariable();
		void setVariable(std::string);
		int getExponent();
		void setExponent(int);
		Term getNext();
		void *setNext(Term*);
		void printData();
		double evaluate(int);	




};



#endif
