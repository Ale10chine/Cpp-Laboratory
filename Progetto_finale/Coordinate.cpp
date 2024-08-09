#include "Coordinate.hpp"

Coordinate::Coordinate(std::string s) {
    if (s.empty()) return;
    x_ = toupper(s.at(0));
	try {
		y_ = std::stoi(s.substr(1, 2));
	} catch (const std::invalid_argument e){
		x_ = '0';
		y_ = 0;
	}
    mark_ = 0;
}

std::vector<Coordinate> generate_inline_position(const Coordinate& from, const Coordinate& to) { //Passiamo come reference

	std::vector<Coordinate> v; //inizizalizzo un vettore di cordinate nullo
	
    // se le coordinate solo uguali
	if (from == to) { v.push_back(from); return v; }

    // se le posizioni passate sono diagonali
	if (from.x() != to.x() && from.y() != to.y()) return v;

	// Caso in cui ho ad esempio A7 A5 oppure A5 A7
	if (from.x() == to.x()) {
		if(from.y() > to.y()) 
			for(int i = to.y(); i <= from.y(); i++)
                v.push_back(Coordinate(from.x(),i));
		else 
			for(int i = from.y(); i <= to.y(); i++)
                v.push_back(Coordinate(from.x(),i));
	}  

	//Caso in cui ho ad esempio C7 A7 oppure A7 C7
	if (from.y() == to.y()){
		if (from.x() > to.x()) 
			for (int i = to.x(); i <= from.x(); i++) {
                if(i == 74 || i == 75) i = 76; // salto le lettere J e K
                v.push_back(Coordinate(i,from.y()));
            }
		else 
			for (int i = from.x(); i <= to.x(); i++) {
                if(i == 74 || i == 75) i = 76; // salto le lettere J e K
                v.push_back(Coordinate(i,from.y()));
            }
	} 
	return v;
}

std::ostream& operator<<(std::ostream& os, const Coordinate& c) {
	return os << "(" << c.x() << ", " << c.y() << ")";
}

bool operator==(const Coordinate& a,const Coordinate& b) {
	return (a.x() == b.x() && a.y() == b.y());
}

bool operator!=(const Coordinate& a,const Coordinate& b) {
	return (a.x() != b.x() || a.y() != b.y());
}
