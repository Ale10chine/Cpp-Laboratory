#ifndef MAZE_HPP
#define MAZE_HPP

#include <iostream>
#include <fstream>
#include "MatrixPosition.hpp"
enum position { up_left = 0, up_center, up_right, middle_left, middle_right, down_left, down_center, down_right};


class Maze{
     
  static constexpr int lato_ = 9;  // const non si può modificare, mentre connstexpr nota a tempo di compilazione, static singifica che in memoria esiste una copia sola per tutti gli oggetti a differenza delle data bember che ce ne sono in memoria tanti quanti oggetti vengono creati
  char maze_[lato_][lato_];        //Dichiaro una matrice di dimensione 9*9
  MatrixPosition exit_; // mi salva la posizione dell'uscita
  MatrixPosition start_; // mi salva la posizione dello start
  
public:
  
  class invalid_maze{};
  
  
  Maze(std:: ifstream& fin); //Costructor senza initializer list, la matrice di caratteri e l'uscita vengono salvati dentro il costruttore NOTA
  ~Maze() = default; //Destructor esplicito che lo setto a default (Nota che se non lo fai il compilatore te lo obbliga a fare)
  
  //Function Member:
  //Mod Function
  
  void maze_update_robot(MatrixPosition& p); // Per aggionrare il carattere 'R' nel labirinto, non cambia nulla se metto o meno la reference
  void maze_update_mark(MatrixPosition& p); //Setta un simbolo 'r' per specificare che di la è passato il robot
  
  //NON Mod Function
  
  //bool valid_move() const; //restituisce un valore booleano se il movimento è valido o meno
  char get_position_value(int i, int j) const{ return maze_[i][j];}
  MatrixPosition get_position(int i , int j) const { MatrixPosition a = MatrixPosition(i,j); return a ;}
  MatrixPosition get_exit() const { return exit_;}
  MatrixPosition get_start() const { return start_;}
  void print_maze() const;
};

#endif // MAZE_HPP
