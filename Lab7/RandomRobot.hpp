#ifndef RANDOMROBOT_HPP
#define RANDOMROBOT_HPP
#include "Robot.hpp"
#include "MatrixPosition.hpp"
#include "vector"


class RandomRobot : public Robot { //Classe che eredita Robot (Eredità pubblica, protected e private sono poco usate)
     
 std::vector<int> v_{}; //vettore temporaneo per memorizzare gli spostamenti validi (serve dentro scan)
 MatrixPosition position_; // tiene conto dell'oggetto posizione del robot
 bool movment_; // variabile che verrà settata a true nel costruttore, finche no è falsa il robot può muoversi, vedi scan
 
public:
     RandomRobot(MatrixPosition p = MatrixPosition(0,0), bool a = true ): position_{p}, movment_{a} {} // da implementare come initializer list per settare il "magic number" 
//CAPIRE COME PASSARE START e da dove farlo partire, NOTA: VA BENE COME HO MESSO v_ nel costruttore?
     //Function member
     //NON Mod Function
     void move(Maze& m);
     void scan(Maze& m);
     
     //Mod function
     //void set_RandomRobot_position(int i, int j); // toglierla è più elegante settando direttamente con le function member di matrixPosition
     
     ~RandomRobot() = default;
};

#endif // RANDOMROBOT_HPP

