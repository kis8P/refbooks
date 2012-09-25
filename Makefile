refbooks: refbooks.o db.o
	g++ refbooks.o db.o -o refbooks

refbooks.o: refbooks.cpp db.hpp
	g++ -c refbooks.cpp

db.o: db.cpp db.hpp
	g++ -c db.cpp

clean:
	rm -rf *.o
