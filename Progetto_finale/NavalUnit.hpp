#ifndef NAVALUNIT_HPP
#define NAVALUNIT_HPP

#include "Coordinate.hpp"

class Battlefield; // forward declaration

/*
 * Rappresenta un'unità navale.
*/
class NavalUnit { // costruttori copy assigment ecc disabilitati in default (classe astratta)
public:
    // Azione specifica di ogni nave
    virtual void action(Battlefield& b1, Battlefield& b2, const Coordinate& t) = 0;

    // Ripristina la vita della nave
    void restore() {
        for (Coordinate& p : positions_)
            p.unmark();
        hp_ = size_;
    }

    // Decrementa di uno la vita della nave e setta a hit la coordinata colpita
    void decrease_life(const Coordinate& p) {
        for (Coordinate& c : positions_) {
            if (c == p) {
                c.mark();
                --hp_;
                break;
            }
        }
    }

    // Setta le nuove posizioni utile per istanziare barche nel battlefield
    void set_positions(std::vector<Coordinate> v) {
        if((int) v.size()  != size_) return;
        for (int i=0; i<size_; i++) {
            if (positions_.size() == 0)
                break;
            if (positions_[i].is_marked())
                v[i].mark();
        }
        positions_ = v;
        cm_ = v[v.size()/2]; // aggiorno il cm_
    }

    // Ritorna il carattere associato alla nave
    char type() const { return type_; }

    // Ritorna un vettore contenente le coordinate occupate dalla nave
    std::vector<Coordinate> get_positions() const { return positions_; }

    // Ritorna la coordinata del centro di massa della nave
    Coordinate get_cm() const { return cm_; }

    // Ritorna la prua della nave
    Coordinate get_bow() const { return positions_.front(); }

    // Ritorna la poppa della nave
    Coordinate get_stern() const { return positions_.back(); }

    // Torna true se la nave è ancora viva
    bool is_alive() const { return hp_ != 0; }

    // Torna il numero di punti vita della nave
    int get_hp() const { return hp_; }

    // Torna la dimensione della nave
    int size() const { return size_; }

    // Eliminio il costruttore di copia e l'assegnamento di copia
    NavalUnit(const NavalUnit& n) = delete;
    NavalUnit& operator=(const NavalUnit&) = delete;

    virtual ~NavalUnit() { }

protected:
    NavalUnit() { }

    int hp_; // punti vita
    int size_; // dimensione
    char type_; // carattere identificativo 
    Coordinate cm_; // centro di massa
    std::vector<Coordinate> positions_; // posizioni occupate
};

#endif
