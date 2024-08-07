#include "BattleShip.hpp"
#include "Battlefield.hpp"

BattleShip::BattleShip(){ 
		hp_ = 5;
		size_ = 5;
		type_ ='C';
}

void BattleShip::action(Battlefield& b1, Battlefield& b2, const Coordinate& t){ 
	if (!b2.is_inside(t)) return; 

	//setto il carattere standard
	char c = 'O'; 

    // controllo se la posizione è occupata da un pezzo di una nave
	if (b2.check_position(t)) {
        c = 'X';

        // cerco il proprietario della coordinata e decremento la vita della nave
        NavalUnit* owner = b2.get_coordinate_owner(t);
		
		//Controlla la condizione che se un pezzo è già colpito non va a togliergli la vita
		for(Coordinate& p : owner->get_positions()) // la reference la uso nel ciclo perchè devo accedere a variabili del pointer
			if(p == t && p.is_marked()) return;
        owner->decrease_life(t);

        b2.refresh_defence();
    }
	
	//scrivo nella matrice d'attacco di b1 una X o una O in base a l fatto di aver colpito o meno un pezzo di una nave
	b1.mark_attack(t, c);
}

