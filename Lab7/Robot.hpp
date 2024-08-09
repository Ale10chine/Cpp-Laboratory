#ifndef ROBOT_HPP
#define ROBOT_HPP

#include "Maze.hpp"


class Robot{ 
     
public:
 //Funzione virtuale pura SOLO SE sceglo di implementarla scrivendo solo move come funzione ponendola  = 0 : è richiesto l'overriding
 //Per scelta implementativa al momento ho deciso di usare una classe astratta (Virtuale pura)
 //Nota essendo virtuale pura è obbligatorio l'override (NON serve quindi esplicitarlo con  la sintassi "override")
 
 //NON mod function member sono const o no?
 virtual void move(Maze& m) = 0; 
 virtual void scan(Maze& m) = 0; 
 
 
};

#endif // ROBOT_HPP


/*
NOTE IMPORTANTI : 
 Le interfaccie in java venivano specificate con " public interface Container" ad esempio
 qua continuano a mantenere il nome di "class"
 Le classi astratte sono un mezzo per implementare le interfacce, le si possono vedere come classi virtuali pure
 ossia come in java diciamo "ok sicuramente dichiariamo i metodi ma poi saremmo obbligati a definirli nelle classi derivate"
 Se una classe è astratta o virutale pura significa che NON possiamo instanziare oggetti di quella classe

 * Queste righe non servono perchè non è come shape, Robot è una classe virutale pura (Astratta)
 Robot (const Robot&) = delete; //setto a delete il copy constructor 
 Robot& operator=(const Robot&) = delete; // setto a delete il copy assigment per evitare lo slicing
 
  * Il Inizialmente il Robot si muove con un ciclo while fintanto chè non si blocca, ad ogni suo movimento il maze viene aggiornato
 con un mark, ovviamente i movimenti sono garantiti dalla funzione maze.valid_move() che ritorna un booleano
  * Creo un enumerazioni di posizioni (alto a destra a sinistra destra sinistra in basso ecc) dpodichè creo una funzione 
  
  NOTA: quando overraidi di fatto stai sovrascrivendo il codice, ossia se su "draw di shape" messa come virtual fai determinate cose
  e la overraidi in circle allora in circle la riandrai a definire da 0 
  
  NOTA BENE: Quando si usa std::vector stai attento ad usare v.size() nei cicli per ricalcola il valore ogni volta e di conseguenza sfasa il ciclo  
*/