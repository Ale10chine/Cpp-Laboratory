#include "Maze.hpp"


  //Costructors
Maze::Maze(std::ifstream& fin) {
   for(int i = 0; i < lato_; i++){
        std:: string s = "";    //implementabile anche con l'ausilio di char e dell'operatore >>
        std:std::getline(fin,s);
        if(s.size() == 0) throw invalid_maze();
       for(int j = 0; j < lato_; j++){
            if(s.at(j) == 'E') exit_ = MatrixPosition(i,j);    // setto l'uscita
            if(s.at(j) == 'S') start_ = MatrixPosition(i,j);  // setto lo start
            maze_[i][j] = s.at(j);
        } 
     }
     
}
  //Function Member:
  //Mod Function:
  
void Maze:: maze_update_robot(MatrixPosition& p){ //Sposta il robot graficamente, infatti serve per muovere ed aggiornare la R

 int i = p.get_row();
 int j = p.get_col();
 //std::cout<<"riga e colonna nuove settate del robot sono : "<<i<<" "<<j<<"\n";
 //if(maze_[i][j] != '*') 
       maze_[i][j] = 'R';
}

void Maze:: maze_update_mark(MatrixPosition& p){ //Sposta il robot graficamente, infatti serve per muovere ed aggiornare la R

 int i = p.get_row();
 int j = p.get_col();
// std::cout<<"riga e colonna del marchio di dove e'passato il robot : "<<i<<" "<<j<<"\n";
 //if(maze_[i][j] != '*') 
       maze_[i][j] = 'r';
}
          
 //NON Mod Function
   
void Maze::print_maze() const{
  std::cout << std::endl;
     for(int i = 0; i < lato_; i++){ std::cout << std::endl;
       for(int j = 0; j < lato_; j++) std::cout << maze_[i][j];
  }
}    