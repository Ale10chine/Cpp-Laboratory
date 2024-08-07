#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

#include "Battlefield.hpp"
#include "SupportVessel.hpp"
#include "Coordinate.hpp"
#include "BattleShip.hpp"
#include "Submarine.hpp"
#include "Human.hpp"

constexpr int NUM_MOSSE = 5;

void battle_test();
void random_test();
void HumanTest();

int main() {
    //battle_test();
    //random_test();
	HumanTest();
    return 0;
}
void HumanTest(){
	BattleShip bs1, bs2, bs3;
    SupportVessel sup1, sup2, sup3;
    Submarine s1, s2;
	
	Battlefield b1;
    Battlefield b2;
	
	Human player1;
	std::ofstream log("C://Users//alex1//Codlite_workspace//Codlite_workspace//Progetto_finale//log.txt");
	player1.init_unit(b1,&bs1,log);
	player1.init_unit(b1,&bs2,log);
	player1.init_unit(b1,&bs3,log);
	player1.init_unit(b1,&sup1,log);
	player1.init_unit(b1,&sup2,log);
	player1.init_unit(b1,&sup3,log);
	player1.init_unit(b1,&s1,log);
	player1.init_unit(b1,&s2,log);
	
	int count;
	
	cout << b1 <<std::endl;
	
	while(NUM_MOSSE != count){
		
		count += player1.turn(b1,b2,log);
	}
	cout << b1 <<std::endl;
	
	/*
	string s = "A5 A6";
	std::size_t space = s.find(" ");
	
	string bow = s.substr(0,space);//da inizio allo spazio vedi questo es : "A1 B2"
	string stern = s.substr(space+1);//da spazio a fine stringa
	
	cout<< bow <<" "<< stern <<endl;
	*/
	
	
}

void battle_test() {
    BattleShip bs1, bs2, bs3;
    SupportVessel sup1, sup2, sup3;
    Submarine s1, s2;

    BattleShip enemy_bs;

    Battlefield b1;
    Battlefield b2;

    bs1.set_positions(generate_inline_position(Coordinate("D5"), Coordinate("D9")));
    bs2.set_positions(generate_inline_position(Coordinate("F5"), Coordinate("F9")));
    bs3.set_positions(generate_inline_position(Coordinate("G7"), Coordinate("M7")));

    enemy_bs.set_positions(generate_inline_position(Coordinate("D7"), Coordinate("H7")));

    b1.insert(&bs1);
    b1.insert(&bs2);
    b1.insert(&bs3);

    b2.insert(&enemy_bs);

    sup1.set_positions(generate_inline_position(Coordinate("F4"), Coordinate("H4")));
    sup2.set_positions(generate_inline_position(Coordinate("M2"), Coordinate("M4")));
    sup3.set_positions(generate_inline_position(Coordinate("B10"), Coordinate("B12")));

    b1.insert(&sup1);
    b1.insert(&sup2);
    b1.insert(&sup3);

    s1.set_positions(generate_inline_position(Coordinate("C3"), Coordinate("C3")));
    s2.set_positions(generate_inline_position(Coordinate("M11"), Coordinate("M11")));

    b1.insert(&s1);
    b1.insert(&s2);

    cout << b1 << endl;
    cout << b2 << endl;

    // azioni da rivedere tutte
    s1.action(b1, b2, Coordinate("G6")); //DA RIVEDERE
    enemy_bs.action(b2, b1, Coordinate("I7"));
    sup1.action(b1, b2, Coordinate("I6"));

    cout << b1 << endl;
    cout << b2 << endl;
}

void random_test() {
    static constexpr char rows[] = { '0', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'L', 'M', 'N', '\0' };

    // scelta di una unità random tra le disponibili
    std::srand(std::time(nullptr));
    int rnd_u = std::rand() % 7 + 1;

    // scelta del target
    int rnd_x = std::rand() % 12 + 1;
    int rnd_y = std::rand() % 12 + 1;

    cout << "Posizione vector: " << rnd_u << endl
         << "Posizione rows = " << rnd_x << endl
         << "y = " << rnd_y << endl;
    cout << Coordinate(rows[rnd_x], rnd_y) << endl;
}
