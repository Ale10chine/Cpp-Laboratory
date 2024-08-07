#include "Battlefield.hpp"
#include "NavalUnit.hpp"

// Constructors
Battlefield::Battlefield() {
    // inizializzo le matrici con caratteri vuoti
    for (int i=0; i<13; i++)
        for (int j=0; j<13; j++) {
            attack_[i][j] = ' ';
            defence_[i][j] = ' ';
        }
}

// Function members
void Battlefield::refresh_defence() {
    if (units_.empty()) return;

    // pulisco la griglia di difesa
    for (int i=0; i<13; i++)
        for (int j=0; j<13; j++)
            defence_[i][j] = ' ';

    // riscrivo tutte le posizioni
    for (auto it=units_.begin(); it!=units_.end(); ) {
        // se è affondata la rimuovo
        if (!(*it)->is_alive())
            it = units_.erase(it);
        else {
            for (Coordinate p : (*it)->get_positions())
                if (p.is_marked())
                    defence_[row(p.x())][p.y()] = std::tolower((*it)->type());
                else
                    defence_[row(p.x())][p.y()] = (*it)->type();
            ++it;
        }
    }
}

void Battlefield::clean_attack(char c) {
    for (int i=0; i<13; i++)
        for (int j=0; j<13; j++) 
			if(attack_[i][j] == c)
				attack_[i][j] = ' ';
}

void Battlefield::mark_attack(const Coordinate& p, char c) {
    if (!is_inside(p)) return;
    attack_[row(p.x())][p.y()] = c;
}

bool Battlefield::move(NavalUnit* u, const Coordinate& p) {
    if (check_position(p)) return false; // ci dice se la posizione è già occupata, la nostra barca non si sposterà e rimarrà ferma
    if (!u) return false; // puntatore a nullptr

    // calcolo la distanza della prua e della poppa dal cm corrente
    // necessario in quanto non sappiamo se la nave è orizzontale o verticale
    int bow_x = row(u->get_bow().x()) - row(u->get_cm().x());
    int bow_y = u->get_bow().y() - u->get_cm().y();
    int stern_x = row(u->get_stern().x()) - row(u->get_cm().x());
    int stern_y = u->get_stern().y() - u->get_cm().y();

    // controllo le lettere J K delle righe
    if (bow_x+p.x() == 'K') bow_x -= 2;
    if (stern_y+p.y() == 'J') bow_x += 2;

    // coordinate della nuova prua e poppa
    Coordinate bow(bow_x+p.x(), bow_y+p.y());
    Coordinate stern(stern_x+p.x(), stern_y+p.y());

    // controllo che le posizioni della nave siano tutte intene alla griglia
    std::vector<Coordinate> pos = generate_inline_position(bow, stern);
    for (Coordinate c : pos)
        if (!is_inside(pos)) return false;

    // controllo che tutte le posizioni non siano occupate da altre navi
    for (Coordinate c : pos) {
        NavalUnit* owner = get_coordinate_owner(c);
        if (check_position(c) && owner != u) return false;
    }

    // pulisco le vecchie posizioni occupate nella griglia e le ridisegno
    u->set_positions(pos); // cambio le coordinate
    refresh_defence();
	return true;
}

void Battlefield::insert(NavalUnit* u) {
    //inserisco nella lista
    units_.push_back(u);

    // disegno la nave nella griglia
    char t = u->type();
    for (Coordinate p : u->get_positions())
        defence_[row(p.x())][p.y()] = t;
}

bool Battlefield::check_position(const Coordinate& p) {
    if (!is_inside(p)) return false;
    int x = row(p.x());
    int y = p.y();
    return defence_[x][y] != ' ';
}

bool Battlefield::check_position(const std::vector<Coordinate>& v) {
    for (Coordinate p : v)
        if (check_position(p)) return true;
    return false;
}

bool Battlefield::is_inside(const Coordinate& p) {
    char x = p.x();
    int y = p.y();
    if (x<'A' || x>'N' || x=='J' || x=='K') return false;
    if (y<1 || y>12) return false;
    return true;
}

bool Battlefield::is_inside(const std::vector<Coordinate>& v) {
    for (Coordinate c : v)
        if (!is_inside(c)) return false;
    return true;
}

NavalUnit* Battlefield::choose_unit(const Coordinate& p) {
    for (NavalUnit* u : units_)
        if (u->get_cm() == p) return u;
    return nullptr;
}

int Battlefield::row(char c) {
    switch (c) {
    case 'A': return 1; break;
    case 'B': return 2; break;
    case 'C': return 3; break;
    case 'D': return 4; break;
    case 'E': return 5; break;
    case 'F': return 6; break;
    case 'G': return 7; break;
    case 'H': return 8; break;
    case 'I': return 9; break;
    case 'L': return 10; break;
    case 'M': return 11; break;
    case 'N': return 12; break;
    default: return -1;
    }
}

NavalUnit* Battlefield::get_coordinate_owner(const Coordinate& p) {
    NavalUnit* owner = nullptr;

    // controllo tutte le posizioni di tutte le unità
    for (NavalUnit* u : units_)
        for (Coordinate c : u->get_positions())
            if (c == p) {
                owner = u;
                break;
            }
    return owner;
}

// Operators
std::ostream& operator<<(std::ostream& os, const Battlefield& b) {

	//La matrice del battlefield è all'interno della L di numeri ecaratteri che idividuano le coordinate nella griglia
    char row  = 'A';
	os << "\tDefence \t\t\t Attack\n";
    for (int i = 1; i < 13; i++) { //Stampa le lettere nella prima colonna
        if (row == 'J') row = 'L'; // salto la J e K
        os << char(row)<<"  ";
		
        // stampo la i-esima riga della prima matrice (difesa)
        for (int j = 1; j < 13; j++) 
            os << b.defence_[i][j] << " ";
        
        // aggiungo spazi
        os << "\t";

        // stampo la i-esima riga della seconda matrice (attacco)
        os << char(row++)<<"  ";
        for (int j = 1; j < 13; j++) 
            os << b.attack_[i][j] << " ";

        // vado a capo alla fine della riga
        os << std::endl; 
    }

    // stampa dei numeri sotto alle griglie
    // 10 11 12 occupano due caratteri
    os << std::endl<<" ";
    for (int i=1; i<10; i++)
        os << i << ' ';
    os << "d u d" << "\t "; 
    for (int i=1; i<10; i++)
        os << i << ' ';
    os << "d u d";
    

    // stampa della griglia di difesa
    //os << "------------------------------------------" << std::endl;
    //char c = 'A';
    //os << "Griglia di difesa:" << std::endl;
    //for (int i=1; i<13; i++) {
    //    if (c == 'J') c = 'L'; // salto le lettere J e K
    //    os << char(c++) << ' ';
    //    for (int j=1; j<13; j++)
    //        os << b.defence_[i][j] << ' ';
    //    os << std::endl;
    //}
    //os << "  ";
    //for (int i=1; i<13; i++)
    //    os << i << ' ';

    //// stampa della griglia d'attacco
    //os << std::endl;
    //os << "------------------------------------------" << std::endl;
    //c = 'A';
    //os << "Griglia di attacco:" << std::endl;
    //for (int i=1; i<13; i++) {
    //    if (c == 'J') c = 'L'; // salto le lettere J e K
    //    os << char(c++) << ' ';
    //    for (int j=1; j<13; j++)
    //        os << b.attack_[i][j] << ' ';
    //    os << std::endl;
    //}
    //os << "  ";
    //for (int i=1; i<13; i++)
    //    os << i << ' ';
    //os << std::endl;
    //os << "-----------------------------------------" << std::endl;
    return os;
}

