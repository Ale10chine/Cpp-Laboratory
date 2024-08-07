#include <iostream>
#include "Rational.hpp"
using namespace std;

//la classe è stata implementata con lo scopo di returnare un nuovo 
//oggetto dato dalla somma tra oggetto "parametro implicito" e oggetto "parametro esplicito"

int main (void){
    
    Rational a {330 , 20};
    Rational b {450 , 62};
    
    cout<<"i due numeri razionali inizizali sono:\n";
    cout<<"\n a = "<<a<<"\n";
    cout<<"\n b = "<<b<<"\n";
    
    cout<<"\nSenza overload degli operatori:\n";
    
    Rational sum = a.Add(b);                                
    cout<<"\nLa somma tra a e b e': "<<sum<<"\n";           
    Rational sub = a.Subs(b);
    cout<<"La differenza tra a e b e': "<<sub<<"\n";
    Rational mul = a.Mul(b);
    cout<<"La moltiplicazione tra a e b e': "<<mul<<"\n";
    Rational div = a.Div(b);
    cout<<"La divisione tra a e b e': "<<div<<"\n";
    
    cout<<"\nCheck con overload degli operatori come Member function:\n";
    
    sum = a+b;
    cout<<"\nLa somma tra a e b e': "<<sum<<"\n";
    sub = a-b;
    cout<<"La differenza tra a e b e': "<<sub<<"\n"; 
    mul = a*b;
    cout<<"La moltiplicazione tra a e b e': "<<mul<<"\n"; 
    div = a/b;
    cout<<"La divisione tra a e b e': "<<div<<"\n"; 
    
    Rational c {6 , 5};
    int i = 12;
    
    cout<<"\nIl numero razionale e l'intero iniziale sono:\n";
    cout<<"\n c = "<<c<<"\n";
    cout<<"\n i = "<<i<<"\n";
   
    
    sum = c+i;
    cout<<"\nCheck: La somma tra un oggetto Rational e un intero e': "<<sum<<"\n";
    //sum = i+c;                                                              Non mi fa soomare i+c perchè ovviamente non esiste un overload di questo tipo
    //cout<<"\nLa somma tra intero e oggetto Rational e': "<<sum<<"\n";
    
    
    /*
    cout<<"\nCheck con overload degli operatori come Helper function:\n";
    sum = a+b;                                                                        //Come mai non funziona cout<<a+b; ??
    cout<<"\nLa somma tra a e b e': "<<sum<<"\n";
    sub = a-b;
    cout<<"La differenza tra a e b e': "<<sub<<"\n"; 
    mul = a*b;
    cout<<"La moltiplicazione tra a e b e': "<<mul<<"\n"; 
    div = a/b;
    cout<<"La divisione tra a e b e': "<<div<<"\n"; 
     */
    
    return 0;
    }
  
  
  /*
1. What are the two parts of a class?
 La parte public e la parte private
 
2. What is the difference between the interface and the implementation in a class?
 L'interfaccia è sostanzialmente la dichiarazione di tutte le funzioni 
 (dentro la classe sono sufficienti dichiarare quelle membro) e di tutte le variabili che riguardano
 una classe, mentre l'implementazione è la vera e propria definizione di tali funzioni

3. Why is a constructor used for the Date type instead of an init_day() function?
 Usando un costruttore le data member vengono inizializzate direttemente, se uso init_day() le variabili 
 vengono inizializzate due volte: prima qunado creo un oggetto Date, poi quando invoco init_date().

4. What is an invariant? Give examples.
 Un'invariante è una condizione all'interno di una classe che deve rimanere sempre vera. 
 Per esempio nella classe Rational, si ha che denominatore >= 1. Oppure nella classe Date, 0 <= month <= 12.

5. When should functions be put in the class definition, and when should they be defined
outside the class? Why?
 Le function member vengono definite al di fuori della classe se il corpo delle funzioni è lungo. 
 Le helper function vengono sempre dichiarate al di fuori della classe, in quanto non sono funcition member.
  */