#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "Player.hpp"
#include "NavalUnit.hpp"
#include <string>
#include <fstream>
#include <Windows.h>

class Human : public Player{
public:
	//costruttore di default
	Human(): initialized_units_{1} {}; //istanzia a 1 il contatore che tiene conto delle barche secondo la l'ordine di default
	//Disabilitiamo il costruttore di copia e il copy assignment, non avrebbe senso ma specialmente per evitare Shallow Copy
	Human (const Human&) = delete;
	Human operator=(const Human&) = delete; 
	//Initialization
	void init_unit(Battlefield& b1, NavalUnit* unit, std::ofstream& log);
	
	//Turn
	int turn(Battlefield& b1, Battlefield& b2, std::ofstream& log);
	
	//distruttore di defualt
	~Human() = default;

private:
	// contatore che tiene conto del numero di barca a cui ci si riferisce secondo l'ordine di default della lista
	int initialized_units_;
	
	//Function private
	std::string get_unit_name();
	
	//Funzione per i comandi speciali, passo il battlefield per fare la clean
	bool special_commands(Battlefield& b1, std::string input1, std::string input2);
};

#endif // HUMAN_HPP
