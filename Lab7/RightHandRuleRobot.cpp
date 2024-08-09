#include "RightHandRuleRobot.hpp"
#include "ctime"
#include "cstdlib"

void RightHandRuleRobot:: scan(Maze& m){ 
 int i = position_.get_row(); //inizizialmente ragiono con la posizione dove si trova il robot
 int j = position_.get_col();
 int c = 0; // se il ciclo della rotazione avviene più di 3 volte significa che il robot sarà in un vicolo cieco
 
 
 //std::cout<<"\n STO per passare il pop\n";
 int tmp = v_.size();
 if(tmp == 1) v_.pop_back(); // la logic size è 1 
 //std::cout<<"\n ho passato il pop\n";
  while(v_.size() == 0 && c <= 3 ){ // se ha trovato una mossa allora esce dal ciclo altrimenti riprova per un massimo di 3 cicli
    // Caso più semplice in cui se lo scan va bene il robot segue la direzione di appoggio, ossia appoggiandosi a destra segue il muro
    c++;
    switch(right_hand(direction_right_hand_)){ //NOTA AGGIUNGERE CONTROLLO CON IL MARK 'r'
      case up : 
      if(m.get_position_value(i,j-1) != '*' && m.get_position_value(i,j-1) != 'r' && m.get_position_value(i-1,j-1) =='*')  v_.push_back(middle_left); 
        if(m.get_position_value(i-1,j-1) != '*' && m.get_position_value(i-1,j-1) != 'r' && m.get_position_value(i-1,j) =='*') v_.push_back(up_left);    //Quando si muove facendo perno     
            break; //Se nella direzione della mano destra c'è un muro  nella casella sucessiva alla direzione e la casella dopo non è un muro allora sono mosse possibili da move
     
      case dx : 
      if(m.get_position_value(i-1,j) != '*' && m.get_position_value(i-1,j) != 'r' &&  m.get_position_value(i-1,j+1) =='*') v_.push_back(up_center);
       if(m.get_position_value(i-1,j+1) != '*' && m.get_position_value(i-1,j+1) != 'r' && m.get_position_value(i,j+1) =='*') v_.push_back(up_right);   //Quando si muove facendo perno
         break;
         
      case down : 
      if(m.get_position_value(i,j+1) != '*' && m.get_position_value(i,j+1) != 'r' && m.get_position_value(i+1,j+1) =='*') v_.push_back(middle_right); 
       if(m.get_position_value(i+1,j+1)!= '*' && m.get_position_value(i+1,j+1)!= 'r'  && m.get_position_value(i+1,j) == '*') v_.push_back(down_right);  //Quando si muove facendo perno
       break;
       
      case sx : 
      if(m.get_position_value(i+1,j) != '*' && m.get_position_value(i+1,j) != 'r' && m.get_position_value(i+1,j-1) =='*') v_.push_back(down_center);
       if(m.get_position_value(i+1,j-1)!= '*' && m.get_position_value(i+1,j-1)!= 'r' && m.get_position_value(i,j-1) == '*') v_.push_back(down_left); //Quando si muove facendo perno
       break;

     default: break;    //In questo switch si verificherà solo una mossa quindi posso breakkare alla fine di ogni case
     }
   //Se non ho trovato mosse che andavano bene fino a qua provo a far ruotare il robot su se stesso
   // se per ora nessuna mossa era disponibile significa che può essere che il robot si trovi in uno spigolo, quindi qua ci sarà il rotation
    if(v_.size() == 0) rotate();// cambia la direzione, ovvero la mano destra ruoterà di 90 gradi in maniera anti oraria
   
  }   

    // Piccola nota di sviluppo, su questo random movment, non c'è il ocntrollo delle posizioni 
    // di conseguenza significa che può ripassare su posizioni in cui è gia stato
    int flag = 0; int memory_flag = 0;//Setto due counter uno per gli spazi vuoti e uno per le r
    for(int r = i-1; r <= i+1 ; r++ ){ // Parto da la posizione in alto a sinistra della matrice delle pos   
       for(int c = j-1; c <= j+1; c++ ){//Scannerizzo
        if(!(r == i && c == j)){ //Controllo di non trovarmi al centro della mat, ossia dove c'è il robot
         if(m.get_position_value(r,c) == 'r') memory_flag++; //aggiorno i flag   
          if(m.get_position_value(r,c) == ' ') flag++;  
        }
       }
     }
     
     // dopo il doppio ciclo di controllo se il robot 
     // si trova in mezzo ad 8 celle vuote/ ad 8 celle cui la somma tra vuote e caratteri r sia 8
     // assegna a v_ una mossa random
    int random = rand()%8;
    if(flag + memory_flag == 8) v_.push_back(right_hand(random)); 
    
    if(v_.size() == 0) movment_ = false; // il robot si è bloccato perchè il labirinto non è risolvibile 
                                          //o semplicmente perchè non ha trovato l'uscita  tutte le mosse che fa sono impossibili in quanto è "murato"
}
    

void RightHandRuleRobot::rotate(){
  if(direction_right_hand_+ 1 == 4) direction_right_hand_ = 0; // le direzioni sono appunto 4 e vanno da un indice di 0 fino a 3
  else direction_right_hand_ += 1; 
   
}

void RightHandRuleRobot:: move(Maze& m){ 
 
 position_ = m.get_start(); // La posizione del robot viene settata nello start dello specifrico labirinto solo la prima volta
 
 while(position_ != m.get_exit()){ //Finchè la posizione del robot non è uguale a quella dell'uscita, di fatto finchè il robot non esce deve muoversi
  scan(m); //Scannerizzo l'unica mossa possibile, NOTA: a differenza del random, il righthand può avere solo una mossa disponibile alla volta, quindi la logic size di v_ sarà sempre 1
     if(!movment_ == true) {std::cout << "Il robot si e'bloccato o non ha trovato l'uscita" << std::endl; break;} // Se non ho mosse il robot si blocca
     
     int i = position_.get_row();
     int j = position_.get_col();
     
     m.maze_update_mark(position_); //Aggiorna la r nel labirinto, ossia il percorso del robot
     
          switch (v_[position(0)]){ //accedo alla posizione 0, in quanto v_ sarà sempre al massimo di lunghezza 1 
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
     
     m.maze_update_robot(position_); //Aggiorna la R nel labirinto
     m.print_maze(); std::cout << std:: endl; //Stampo il labirinto aggionrato ad ogni movimento del robot
 }
  if(movment_) std::cout<<"\nIl ROBOT HA TROVATO L'USCITA!!!!!!!!!\n\n"; //se non si è bloccato alora stampa questo
}