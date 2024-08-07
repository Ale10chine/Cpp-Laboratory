#ifndef RIGHTHANDRULEROBOT_HPP
#define RIGHTHANDRULEROBOT_HPP

#include "Robot.hpp"
#include "MatrixPosition.hpp"
#include "vector"


enum right_hand{ up, dx, down, sx };// up = 0, dx = 1, down = 2, sx = 3

class RightHandRuleRobot : public Robot{

 std::vector<int> v_{}; //vettore temporaneo per memorizzare gli spostamenti validi (serve dentro scan)
 MatrixPosition position_; // tiene conto dell'oggetto posizione del robot
 int direction_right_hand_;
 bool movment_; // variabile che verrà settata a true nel costruttore, finche no è falsa il robot può muoversi, vedi scan

public:
     
//Costructor     
     RightHandRuleRobot(MatrixPosition p = MatrixPosition(0,0), bool a = true, int hand = 0 ): position_{p}, movment_{a}, direction_right_hand_{hand}{} // da implementare come initializer list per settare il "magic number" ; 
//Function member
//NON Mod Function
     void move(Maze& m);
     void scan(Maze& m);
     
     void rotate();   // fa ruotare in senso antiorario, usando l'overload dell'operatore + della classe RobotDirection
     
     
     ~RightHandRuleRobot() = default;

};

#endif // RIGHTHANDRULEROBOT_HPP
