#ifndef BATTLEFIELD_HPP
#define BATTLEFIELD_HPP

#include <list>
#include <vector>
#include "Coordinate.hpp"

class NavalUnit; // forward declaration

class Battlefield {
public:
    Battlefield();
	
	//Disabilitiamo il costruttore di copia e il copy assignment, non avrebbe senso ma specialmente per evitare Shallow Copy
	Battlefield (const Battlefield&) = delete;
	Battlefield operator=(const Battlefield&) = delete; 

    // Pulisce la griglia d'attacco
    void clean_attack(char c);

    // Permette di scrivere un carattere nella griglia d'attacco
    void mark_attack(const Coordinate& p, char c);

    // Refresh difesa
    void refresh_defence();

    // Sposta la nave graficamente e aggiorna le posizioni della nave
    bool move(NavalUnit* u, const Coordinate& p); // la mettiamo booleana in modo tale da avere un feedback se una unave si sposta o meno, utile nel MoveRepair

    // Inserisce nella lista units_ la nave e la disegna nella matrice
    void insert(NavalUnit* u);

    // Torna true se units_ è vuota
    bool is_empty() { return units_.empty(); }

    // Torna true se nella cella corrispondente alla coordinata è 
    // presente un pezzo di una nave
    bool check_position(const Coordinate& p);
	
	//Torna true se nella celle corrispondenti alla coordinate sono 
    // presenti dei pezzi di una nave
    bool check_position(const std::vector<Coordinate>& v);

    // Torna true se la coordinata è interna alla griglia
    bool is_inside(const Coordinate& p);

    // Torna true se tutte le posizioni contenute nel vettore sono
    // interne alla griglia
    bool is_inside(const std::vector<Coordinate>& v);
    
    // Ritorna l'unità navale che ha il cm alla coordinata p
    NavalUnit* choose_unit(const Coordinate& p);

    // Permette di risalire al'unità che occupa una data coordinata
    NavalUnit* get_coordinate_owner(const Coordinate& p);

    // Converte la righe da char a int
    int row(char c); 

    friend std::ostream& operator<<(std::ostream& os, const Battlefield& b);

private:
    // la la colonna (x,0) e la riga (0,y) delle griglie vengono ignorate
    char defence_[13][13]; // Griglia di difesa
    char attack_[13][13]; // Griglia d'attacco
    std::list<NavalUnit*> units_; // Unità navali presenti
};

#endif
