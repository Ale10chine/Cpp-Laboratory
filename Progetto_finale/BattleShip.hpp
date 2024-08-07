#ifndef BATTLESHIP_HPP
#define BATTLESHIP_HPP

#include "NavalUnit.hpp"

class BattleShip : public NavalUnit{
public:
	BattleShip();
	//Disabilitiamo il costruttore di copia e il copy assignment, non avrebbe senso ma specialmente per evitare Shallow Copy
	BattleShip (const BattleShip&) = delete;
	BattleShip operator=(const BattleShip&) = delete; 
	void action(Battlefield& b1, Battlefield& b2, const Coordinate& t);
};

#endif

