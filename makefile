target: main.o Polynomial.o Term.o 
	g++ -o main main.o Polynomial.o Term.o

main.o: main.cpp Polynomial.cpp Polynomial.h
	g++ -c main.cpp Polynomial.cpp

Polynomial.o: Term.cpp Term.h Polynomial.cpp Polynomial.h
	g++ -c Term.cpp Term.h Polynomial.cpp Polynomial.h

run:
	./main

clean:
	rm *.o
	rm *.gch
	rm main

 
