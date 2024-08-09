#include "SupportVessel.hpp"


SupportVessel::SupportVessel() {
    hp_ = 3;
    size_ = 3;
    type_ = 'S';
}

void SupportVessel::action(Battlefield& b1, Battlefield& b2, const Coordinate& t) {
    if (!b1.move(this, t) && cm_ != t) return;
	//Se la barca non si muove o l'azione richiesta non è un movimento su sè stessa (Stato di immutabilità ricercato)

    // eseguo l'azione di cura delle navi circostanti
    // trovo le coordinate della posizione (0,0) della matrice 3x3 che ha il
    // target come centro di massa
    char start_x = t.x() - 1;
    if (start_x == 'K') start_x = 'I';

    char end_x = t.x() + 1;
    if (end_x == 'J') end_x = 'L';

    Coordinate start(start_x, t.y()-1);
    Coordinate end(end_x, t.y()-1);
    //std::cout << start << std::endl;
    //std::cout << end << std::endl;
    //std::cout << std::endl;
    std::vector<Coordinate> matrix_rows = generate_inline_position(start, end); // Poichè c'è già il controllo sulle J,K
    for (int i=0; i<matrix_rows.size(); i++) 
        for (int j=0; j<matrix_rows.size(); j++) {
            Coordinate tmp(matrix_rows[i].x(), matrix_rows[i].y()+j);
            // controllo che non si auto curi
            bool flag = 0;
            for (Coordinate p : positions_) //Se non è se stessa, quindi evitiamo l'auto cura,
                if (p == tmp) flag = 1;
            if (flag) continue;
            if (!b1.check_position(tmp)) continue; // se la coordinata non è piena, non fa nulla, se è piena andrà a cercare di chi è la posizione (la nave)
            // curo la nave
            NavalUnit* owner = b1.get_coordinate_owner(tmp); // trova la nave a cui corisponde il pezzo
            owner->restore();//cura la nave
        }
    b1.refresh_defence();
}
