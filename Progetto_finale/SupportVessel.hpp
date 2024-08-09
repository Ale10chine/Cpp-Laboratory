#ifndef SUPPORT_VESSEL_HPP
#define SUPPORT_VESSEL_HPP

#include "NavalUnit.hpp"
#include "Battlefield.hpp"

class SupportVessel : public NavalUnit{
public:
    SupportVessel();
	//Disabilitiamo il costruttore di copia e il copy assignment, non avrebbe senso ma specialmente per evitare Shallow Copy
	SupportVessel (const SupportVessel&) = delete;
	SupportVessel operator=(const SupportVessel&) = delete; 
    void action(Battlefield& b1, Battlefield& b2, const Coordinate& t);
};

#endif
