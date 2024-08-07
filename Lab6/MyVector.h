#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <initializer_list>


template <typename T>//ricorda di usare la sintassi google
class MyVector{
     
     int size;       //dimensione MyVector
     int logic_size; //dimensione logica
     T* elem;        //puntatore generico
      
public:
     //Constructors
     MyVector() {size = 0; logic_size = 0; elem = nullptr; }                    //Per i costruttori semplici fornisco anche la definizione
     
     explicit MyVector(int s) : size {s}, logic_size {s},  elem{new T[s]}        //Allochiamo uno spazio di memorica generico T   logic size??
     {if(s == 0) elem = nullptr;}                               //corpo costruttore, va bene anche: MyVector(int s) {size = s; elem =new double[s]; {if(s == 0) elem = nullptr;}  }  
    
     MyVector(std::initializer_list<T> lst); // Costruttore con initializer list usando il template <T> generico
     
     MyVector(const MyVector<T>& v);     // copy costructor     
     MyVector(MyVector<T>&& v);          // move costructor
     
     MyVector<T>& operator=(const MyVector<T>& v);  //copy assignment
     MyVector<T>& operator=(MyVector<T>&& v);      //move assignment
     
     //Modifying functions
     //void safe_set(int position , T val); 
     
     //NON Modifying functions
     int get_size() const {return size;}                // NOTA : Fatta esclusivamente per testare il reserve nel tester
     int get_logic_size() const {return logic_size;}    // NOTA : Fatta esclusivamente per testare il reserve nel tester
     //T safe_get(int position) const; 
     void print_vector() const;
     T& at (int n);                     //versione at reference
     T at (int n) const;                //versione at const reference
     
     //Other member function
     void push_back(const T& val);      //...........
     T pop_back();                      //...........   
     void reserve (int new_alloc);      //...........
     //Overloading come member function
     T operator[](int pos) const;       //versione const
     T& operator[](int pos);            //versione senza const    PERCHE SI FA IN DUE MODI?
     
        
     //Destructor
     ~MyVector() { delete[] elem;};               //tilde si fa con alt+126  , anche questo essendo semplice come def lo faccio direttamente qua

};

#include "MyVector.hpp"
#endif
/*
 NOTE VARIE: 
  cosa cambia metterlo o non mettere <T> nei costruttori? anche nele funzioni?
  Nota nei costruttori non scrivi <T> dopo la dichiarazione bensì il template va messo nei parametri, quindi nelle funzioni
  NOTA IMPORTANTE: questione file .h e.hpp perchè bisogna usarli quando si usa template al posto di hpp e cpp vedi bene slide ppt2 lezione 10
  chiedi comunque info al prof : Risposta = I templete richiedono che le classi siano fatte in modo da essere scritte e definite in un unico file quindi usiamo l'h e l'hpp 
  estensione
  */

