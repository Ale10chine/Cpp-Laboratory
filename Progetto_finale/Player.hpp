#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Coordinate.hpp"
#include "Battlefield.hpp"
#include <vector>

class Player { // interfaccia, classe astratta pura

public:
	//Gestisce l'inizzializzazione per Computer e per Human
	virtual void init_unit(Battlefield& b1, NavalUnit* unit, std::ofstream& log) = 0; //Ovveride richiesto esplicitamente (func virtuale)
	//Gestisce il turno per Computer e Human
	virtual int turn(Battlefield& b1, Battlefield& b2, std::ofstream& log) = 0;


};

#endif // PLAYER_HPP
