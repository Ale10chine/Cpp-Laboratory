#include <iostream>
#include "Maze.hpp"
#include "RandomRobot.hpp"
#include "RightHandRuleRobot.hpp"
//#include <windows.h> da errore per porblema con il linker?


int main(void){

     std::ifstream fin("C:\\Users\\alex1\\Codlite_workspace\\Codlite_workspace\\Lab7\\Maze1.txt");
     
     Maze m1(fin); // Creo il labirinto e inizizalmente lo stampo per visualizzarlo
     m1.print_maze();
     
     RandomRobot r; // Creo il mio robot anche a default, tanto poi abbiamo visto che in base a dove è 'S' verrà settata la data member position_ di robot
     MatrixPosition tmp = m1.get_start();
     m1.maze_update_robot(tmp);
     std::cout<<"\n\n Il nostro robot partita' dunque da S:\n";
     m1.print_maze();
     std::cout<<"\n\n Il Robot ora cerchera' di uscire partendo dalla cella di posizione :\n";
     std::cout<<"["<< tmp.get_row()<<"]["<< tmp.get_col()<<"]"<<"\n";
     
     r.move(m1); //Il robot cercherà ora l'uscita
     fin.close();
     
      
      //Sleep(10);
     
     std::ifstream fin2("C:\\Users\\alex1\\Codlite_workspace\\Codlite_workspace\\Lab7\\Maze2.txt");
     
     Maze m2(fin2); // Creo il labirinto e inizizalmente lo stampo per visualizzarlo
     m2.print_maze();
     
     RandomRobot r2; // Creo il mio robot anche a default, tanto poi abbiamo visto che in base a dove è 'S' verrà settata la data member position_ di robot
     tmp = m2.get_start();
     m2.maze_update_robot(tmp);
     std::cout<<"\n\n Il nostro robot partita' dunque da S:\n";
     m2.print_maze();
     std::cout<<"\n\n Il Robot ora cerchera' di uscire partendo dalla cella di posizione :\n";
     std::cout<<"["<< tmp.get_row()<<"]["<< tmp.get_col()<<"]"<<"\n";
     
     r2.move(m2); //Il robot cercherà ora l'uscita
     fin.close();
 /*    
     std::ifstream fin3 ("C:\\Users\\alex1\\Codlite_workspace\\Codlite_workspace\\Lab7\\Maze3.txt");
     
     Maze m3(fin3); // Creo il labirinto e inizizalmente lo stampo per visualizzarlo
     m3.print_maze();
     
     RightHandRuleRobot r3; // Creo il mio robot anche a default, tanto poi abbiamo visto che in base a dove è 'S' verrà settata la data member position_ di robot
     MatrixPosition tmp = m3.get_start();
     m3.maze_update_robot(tmp);
     std::cout<<"\n\n Il nostro robot partita' dunque da S:\n";
     m3.print_maze();
     std::cout<<"\n\n Il Robot ora cerchera' di uscire partendo dalla cella di posizione :\n";
     std::cout<<"["<< tmp.get_row()<<"]["<< tmp.get_col()<<"]"<<"\n";
     
     r3.move(m3); //Il robot cercherà ora l'uscita
     fin3.close();
*/     
     
return 0;
}
