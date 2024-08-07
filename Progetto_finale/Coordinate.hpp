#ifndef COORDINATE_HPP
#define COORDINATE_HPP

#include <iostream>
#include <vector>
#include <cctype>

class Coordinate{
public:
	//Costructor
	Coordinate() : x_{'0'}, y_{0}, mark_{0} { } //Default
	Coordinate(std::string s); //con controllo e conversione di maiuscole
	Coordinate(char c, int n)
        : x_{c}, y_{n}, mark_{0} {
        if (!isupper(c)) x_ = toupper(c);
    }

	// non mod function
	char x() const { return x_ ; }                                                                             
	int y() const { return y_ ; }
    bool is_marked() const { return mark_; }

    // mod
    void mark() { mark_ = 1; }
    void unmark() { mark_ = 0; }

private:
	char x_; // indice di riga
	int y_; // indice di colonna
    bool mark_; // coordinata colpita
};

std::ostream& operator<<(std::ostream& os, const Coordinate& c);
bool operator==(const Coordinate& a,const Coordinate& b);
bool operator!=(const Coordinate& a,const Coordinate& b);
std::vector<Coordinate> generate_inline_position(const Coordinate& from,const Coordinate& to); 

#endif // COORDINATE_H
