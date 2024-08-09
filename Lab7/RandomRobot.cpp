#include "RandomRobot.hpp"
#include "ctime"
#include "cstdlib"


void RandomRobot:: scan(Maze& m){ // da costruttore il robot avrà come data member una posizione iniziale, lo passo come reference così si modificherà e aggiornerà man mano
     //Ci sono problemi con il copy assigment? prova a verificare
 int i = position_.get_row();
 int j = position_.get_col();
     
 int tmp = v_.size();
  for(int i = 0; i < tmp; i++) v_.pop_back();  //std::cout<<"POP\n";
  //for(int i = 0; i < tmp; i++) std::cout<<v_[i]<<"\n";
/*   
     std::cout<<"Ho finito di pobackkare\n";
     std::cout<<"Il vettore dovrebbe essere nullo: "; 
     for(int i = 0; i < tmp; i++) std::cout<<v_[i]<<"\n";
*/
    // pusho in un vector temporaneo indici da 0 a 7 mosse disponibili
   /* 
    int index_position = 0; //RIGUARDARE CONDIZIONE
    for(int r = i-1; r <= i+1 ; r++ ){ // Parto da la posizione in alto a sinistra della matrice delle pos   
       for(int c = j-1; c <= j+1; c++ ){ //Scannerizzo
        index_position++;
        if(!(r == i && c == j)){ //Controllo di non trovarmi al centro della mat, ossia dove c'è il robot
         if(m.get_position_value(r,c) != '*' && m.get_position_value(r,c) != 'r'){ std::cout<<index_position<<"\n"; v_.push_back(position(index_position));}
        }
       }
     }
   */

   if(m.get_position_value(i-1,j-1) != '*' && m.get_position_value(i-1,j-1) != 'r')  v_.push_back(up_left);  // se nella posizione i-esima non trovo un muro o lo start allora posso muovermici 
   if(m.get_position_value(i-1,j) != '*'  && m.get_position_value(i-1,j) != 'r')      v_.push_back(up_center); 
   if(m.get_position_value(i-1,j+1) != '*'  && m.get_position_value(i-1,j+1) != 'r')  v_.push_back(up_right); 
   if(m.get_position_value(i,j-1) != '*'  && m.get_position_value(i,j-1) != 'r')      v_.push_back(middle_left); 
   if(m.get_position_value(i,j+1) != '*'   && m.get_position_value(i,j+1) != 'r')      v_.push_back(middle_right); 
   if(m.get_position_value(i+1,j-1) != '*'  && m.get_position_value(i+1,j-1) != 'r')  v_.push_back(down_left);  
   if(m.get_position_value(i+1,j) != '*'  && m.get_position_value(i+1,j) != 'r')      v_.push_back(down_center); 
   if(m.get_position_value(i+1,j+1) != '*' && m.get_position_value(i+1,j+1) != 'r')  v_.push_back(down_right);

/*   
     std::cout<<"\nvediamo che carattere c'e' nella pos 0: "<<m.get_position_value(i-1,j-1)<<"\n";
     std::cout<<"vediamo che carattere c'e' nella pos 1: "<<m.get_position_value(i-1,j)<<"\n";
     std::cout<<"vediamo che carattere c'e' nella pos 2: "<<m.get_position_value(i-1,j+1)<<"\n";
     std::cout<<"vediamo che carattere c'e' nella pos 3: "<<m.get_position_value(i,j-1)<<"\n";
     std::cout<<"vediamo che carattere c'e' nella pos 4: "<<m.get_position_value(i,j+1)<<"\n";
     std::cout<<"vediamo che carattere c'e' nella pos 5: "<<m.get_position_value(i+1,j-1)<<"\n";
     std::cout<<"vediamo che carattere c'e' nella pos 6: "<<m.get_position_value(i+1,j)<<"\n";
     std::cout<<"vediamo che carattere c'e' nella pos 7: "<<m.get_position_value(i+1,j+1)<<"\n";
     
     std::cout<<"Il vettore dice che le mosse possibili sono:\n"; 
      tmp = v_.size();
     for(int i = 0; i < tmp; i++) std::cout<<v_[i]<<"\n";
*/
    if(v_.size() == 0) movment_ = false; // il robot si è bloccato perchè il labirinto non è risolvibile 
                                          //o semplicmente perchè non ha trovato l'uscita  tutte le mosse che fa sono impossibili in quanto è "murato"
}                                             

//NOTA: l'algoritmo è progettato in modo che se solo una direzione è possibile anche se random, sceglie quella direzione
void RandomRobot:: move(Maze& m){ 
 position_ = m.get_start(); // La posizione del robot viene settata nello start dello specifrico labirinto solo la prima volta
 
 while(position_ != m.get_exit()){ //Finchè la posizione del robot non è uguale a quella dell'uscita, di fatto finchè il robot non esce deve muoversi
  scan(m); //Scannerizzo le mie mosse possibili 
  if(!movment_ == true) {std::cout << "Il robot si e'bloccato o non ha trovato l'uscita" << std::endl; break;} // Se non ho mosse il robot si blocca
     
  srand(time(NULL)); // devo scegliere randomicamente un indice tra 0 e capacity() ossia la dim logica del nostro vector che può essere al massimo "lungo" 7
  int random = rand()% v_.size(); //Prende un indice casuale da 0 alla dim logica del vector
/*
     std::cout<<"Numero randomico scelto :"<<random<<std::endl;
*/
  int i = position_.get_row();
  int j = position_.get_col();
     
  m.maze_update_mark(position_); //Aggiorna la r nel labirinto, ossia il percorso del robot
     
  switch (v_[position(random)]){ //accedo alla posizione i-esima del vector dove ci sarà la mossa "estratta" casualmente tra le possibili, uso l'enum
   case up_left:  position_.set_row(i-1); position_.set_col(j-1); break;   //Vado ad aggiornare position_ di robot, di fatto lo sto muovendo
   case up_center:  position_.set_row(i-1); position_.set_col(j); break;
   case up_right:  position_.set_row(i-1); position_.set_col(j+1); break;
   case middle_left:  position_.set_row(i); position_.set_col(j-1); break;
   case middle_right:  position_.set_row(i); position_.set_col(j+1); break;
   case down_left:  position_.set_row(i+1); position_.set_col(j-1); break;
   case down_center :  position_.set_row(i+1); position_.set_col(j); break;
   case down_right:  position_.set_row(i+1); position_.set_col(j+1); break;
          //NOTA QUA HA SENSO USARE L'ENUMERAZIONE al posto di 0,1,2...
   default: break;     
     }
/*    
     std::cout<<"setto la nuove posizione di R\n";
*/
  m.maze_update_robot(position_); //Aggiorna la R nel labirinto
  m.print_maze(); std::cout << std:: endl; //Stampo il labirinto aggionrato ad ogni movimento del robot
 }
 if(movment_) std::cout<<"\nIl ROBOT HA TROVATO L'USCITA!!!!!!!!!\n\n"; //se non si è bloccato alora stampa questo
}


/*void RandomRobot::set_RandomRobot_position(int i, int j){ //Funzione che aggiorna la posizione in MatrixPosition di RandomRobot
     position_.set_row(i);                                //non molto utile altrimenti faccio una matriosca
     position_.set_col(j);
}*/

