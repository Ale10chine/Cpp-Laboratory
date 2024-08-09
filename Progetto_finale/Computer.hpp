#ifndef COMPUTER_HPP
#define COMPUTER_HPP

#include <vector>
#include "Player.hpp"
#include "NavalUnit.hpp"
#include "Battlefield.hpp"



class Computer : public Player {
public:
    Computer() { };
	//Disabilitiamo il costruttore di copia e il copy assignment, non avrebbe senso ma specialmente per evitare Shallow Copy
	Computer (const Computer&) = delete;
	Computer operator=(const Computer&) = delete; 
	
	void init_unit(Battlefield& b1, NavalUnit* u, std::ofstream& log); 
	int turn(Battlefield& b1, Battlefield& b2, std::ofstream& log);
private:
    static constexpr char kRows[] = { '0', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'L', 'M', 'N', '\0' };

    std::vector<NavalUnit*> alive_units_;
    Coordinate get_random_coordinate();
};


#endif
