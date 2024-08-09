#include "Submarine.hpp"
#include "Battlefield.hpp"

Submarine::Submarine() {
    hp_ = 1;
    size_ = 1;
    type_ = 'E';
}

void Submarine::action(Battlefield& b1, Battlefield& b2, const Coordinate& t) {
    if (!b2.is_inside(t)) return;

    // controllo se la destinzione è già occupata, se è lui stesso ad occuparla
    // eseguo comunque l'azione
    if (!b1.move(this, t) && cm_ != t) return;

    // trovo le coordinate della posizione (0,0) della matrice 5x5 che ha il
    // target come centro di massa
    char start_x = t.x() - 2;

    // controllo sulle righe J K
    if (start_x == 'J') start_x = 'H';
    if (start_x == 'K') start_x = 'I';

    char end_x =  t.x() + 2;

    // controllo sulle righe J K
    if (end_x == 'J') end_x = 'L';
    if (end_x == 'K') end_x = 'M';

    // inizio la scansione del sonar
    Coordinate start(start_x, t.y()-2); // posizione (0,0) matrice
    Coordinate end(end_x, t.y()-2); // posizione (0,4) matrice

    // creo il vettore della colonna (x, 0)
    std::vector<Coordinate> matrix_rows = generate_inline_position(start, end);

    // creo il vettore contenente le posizioni da marchiare
    std::vector<Coordinate> sonar;

    // calcolo le restanti posizioni partendo dalla colonna creata
    for (int i=0; i<matrix_rows.size(); i++) 
        for (int j=0; j<matrix_rows.size(); j++) {
            Coordinate tmp(matrix_rows[i].x(), matrix_rows[i].y()+j);
            if (b2.check_position(tmp))
                sonar.push_back(tmp);
        }

    // marchio la griglia di attacco
    for (const Coordinate& p : sonar) {
        // risalgo al proprietario dalla coordinata che devo segnare
        NavalUnit* owner = b2.get_coordinate_owner(p);

        // controllo se la coordintata è già stata colpita
        for (const Coordinate& c : owner->get_positions())
            if (c==p && c.is_marked()) b1.mark_attack(p, 'X');
            else if (c == p) b1.mark_attack(p, 'Y');
    }
}