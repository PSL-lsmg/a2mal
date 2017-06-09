all: wicps

wicps: WICPS.o List.o Patient.o
	g++ -std=c++98 -pedantic -Wall -o wicps WICPS.o List.o Patient.o

WICPS.o: WICPS.cpp List.h Patient.h
	g++ -std=c++98 -pedantic -Wall -c WICPS.cpp

List.o: List.h List.cpp
	g++ -std=c++98 -pedantic -Wall -c List.cpp

Patient.o: Patient.h Patient.cpp
	g++ -std=c++98 -pedantic -Wall -c Patient.cpp

clean:
	rm -f wicps *.o