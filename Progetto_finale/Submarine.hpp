#ifndef SUBMARINE_HPP
#define SUBMARINE_HPP

#include "NavalUnit.hpp"

class Submarine : public NavalUnit {
public:
    Submarine();
	//Disabilitiamo il costruttore di copia e il copy assignment, non avrebbe senso ma specialmente per evitare Shallow Copy
	Submarine (const Submarine&) = delete;
	Submarine operator=(const Submarine&) = delete; 
    void action(Battlefield& b1, Battlefield& b2, const Coordinate& t);
};


#endif
