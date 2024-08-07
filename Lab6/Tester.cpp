#include <iostream>
#include <stdexcept>
#include "MyVector.h"


using namespace std;

int main (void){
          
     cout<<"\n\nVerifico il costruttore di default"<<endl;
     MyVector<int> v1;
     v1.print_vector(); 
     cout<<endl;
     
     cout<<"\n\nVerifico il costruttore di default con passaggio di parametro il size del vector"<<endl;
     MyVector<int> v2 (5); //??                                   //DA RIVEDERE QUESTO COSTRUTTORE, è giusto che instanziando 5 elementi poi facendo print del vector mi stampi
     v2.print_vector();                                           // celle ovviamente vuote o con riferimenti randomici?Non sarebbe più corretto aseggnare dei valori di default?
     cout<<endl;
     
     cout<<"\n\nVerifico il costruttore con initializer list"<<endl;
     MyVector<int> v3 = {1,2,3,4,5,6,7,8,9};
     v3.print_vector();
     cout<<endl;
     
     cout<<"\n\nVerifico il costruttore di copia"<<endl;
     MyVector<int> v4 = v3;
     v4.print_vector();
     cout<<endl;
     
    /* cout<<"Verifico il costruttore di copia"<<endl;
     MyVector<char> v4 = v3;                             
     v4.print_vector();
     cout<<endl;*/
     
      
     cout<<"Verifico il copy assignment"<<endl;                  
     MyVector<int> v5 = {10,20,30,40,50};
     v4 = v5;
     v4.print_vector();
     cout<<endl;
     
     //Da finire
     cout<<"Verifico il Move constructor-----da fare"<<endl;                  

     cout<<endl;
     
     //Da finire
     cout<<"Verifico il move assigment------da fare"<<endl;                  

     cout<<endl;
     
     
     cout<<"\n\nVerifico l'operatore [] in lettura"<<endl;
     cout<<"\nv4[3] = "<<v4[3]<<endl;
     
     cout<<"\n\n\nVerifico l'operatore [] in scrittura"<<endl;
     cout<<"\nPongo v4[3] uguale a 5 "<<endl;
     v4[3] = 5;
     cout<<"\nv4[3] = "<<v4[3]<<endl;
     
     
     
     cout<<"\n\nVerifico la function at sia in lettura che in scrittura "<<endl;
     int a = v4.at(1);                         //move constructor?
     cout<<"\nNella posizione 1 del vettore v4 si trova il valore: "<<a<<endl;
     cout<<"\nNella posizione 3 del vettore v4 si trova il valore: "<<v4.at(3)<<endl;
     
     
     cout<<"Aumento le dimensioni del vettore v4"<<endl;
     cout<<"La dimensione di v4  e':"<<v4.get_size()<<endl; 
     v4.reserve(20);
     cout<<"La dimensione di v4 ora e':"<<v4.get_size()<<endl; 
     
                                                   
     cout<<"\nRimuovo 2 elementi da v4"<<endl;
     v4.pop_back();
     v4.pop_back();
     v4.print_vector();
     
     
     
     
     cout<<"\n\nCreo un vettore vuoto e ci metto dentro un po' di oggetti (interi)"<<endl;
     
    /* v4.push_back(100);
     v4.print_vector();*/
     MyVector<int> Vec;
     cout<<"\ninserisco valore"<<endl;
     Vec.push_back(5);
     cout<<"inserisco valore"<<endl;
     Vec.push_back(51);
     cout<<"inserisco valore"<<endl;
     Vec.push_back(34);
     cout<<"inserisco valore"<<endl;
     Vec.push_back(67);
     cout<<"inserisco valore"<<endl;
     Vec.push_back(343);
     cout<<"inserisco valore"<<endl;
     Vec.push_back(23);
     cout<<"inserisco valore"<<endl;
     Vec.push_back(10);
     cout<<"inserisco valore"<<endl;
     Vec.push_back(523);
    
     cout<<"inserisco valore"<<endl;
     cout<<"\nStampa del vettore completo:"<<endl;
     Vec.print_vector();
     
     cout<<"\nPer curiosità stampo quanto vale ora size di Vec:"<<endl;
     cout<<"La dimensione Fisica di Vec e':"<<Vec.get_size()<<endl; 
     cout<<"La dimensione Logica di Vec e':"<<Vec.get_logic_size()<<endl; 
     
 return 0;     
}


/* NOTE VARIE E DUBBI
  Anche sulla classe MyVector del lab 3 potevo fare le operazioni con vettori di floating ecc direttamernti inizializzati nel costruttore con initializer list,
  il vantaggio di usare typename può essere il fatto che ora possiamo usare tipi non primitivi?










*/