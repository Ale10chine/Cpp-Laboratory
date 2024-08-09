#include <iostream>
#include <vector>                 //libreria per vettori
using namespace std;

int g  = 1;                       // una variabile int globale (in quanto globale, è anche statica senza bisogno di esplicitarlo) inizializzata a un valore diverso da 0
int g2;                           // variabile int globale non inizizalizzata


void print(string s, vector<int> v);    //Definizione funzioni
void fibonacci(int x, int y, vector<int>& v, int n);
void call_counter(void);


int main(void){
    
	cout<<("Hello World\n");
    // Modified 
    int a;                         //variabile int locale automatica
    int static b = 1;              //variabile int locale statica inizizalizzata a un valore diverso da 0
    int static c;                  // variabile int locale statica non inizizlizzata
    
    vector<int> v1 {1,2,3,4,5};
    print("il mio vettore e'",v1);
    
    vector<int> fib;
    int x,y,n;
    
    cout<<"Inserisci i due numeri di partenza consecutivi della sequenza di fibonacci\n";
    cin>>x;
    cin>>y;
    cout<<"Quanti n primi valori della sequenza di fibonacci a partire dai due valori inseriti vuoi stampare?\n";
    cin>>n; cout<<"\n";
    
    fibonacci(x,y,fib,n);
    print("Vettore di fibonacci",fib);
    
    
    
    call_counter();
    call_counter();
    call_counter();
    call_counter();
    call_counter();
	return 0;
}

void print(string s, vector<int> v){
    cout<< s <<":\n\n";
    for(int i = 0; i<v.size(); i++){      
        cout<<"v["<<i<<"] ="<<v[i]<<"\n";
        } 
    cout<<"\n";
}

void fibonacci(int x, int y, vector<int>& v, int n){
    v.push_back(x);
    v.push_back(y);
     
     if (n == 0 or n == 1) return;
    
    int somma = 0;
    for(int i = 0; i < n; i++){
        somma = x + y;
        y = x;
        x = somma;
        v.push_back(somma);
        }
     return;
    }
    
void call_counter(void){
   static int c = 0;                                 //essendo n statico si aggiorna ogni volta ?
   cout<<"Numero di chiamate funzione call_counter : "<<++c<<"\n";    

    }

// a. in quale delle sezioni riportate da size compare la variabile locale automatica? Perché?
// Non compare in nessuna sezione perché è una variabile che si trova nell'RA del del main.
//
// b. perché la variabile locale automatica è “automatica”?
// Perché si trova dentro allo scope della funzione main.
//
// c. cosa succede togliendo l’inizializzazione alle variabili statiche? Perché?
// Finiscono del bss in quanto non sono inizializzate.
//
// d. qual è lo scope di ciascuna delle variabili create?
// Le variabili globali sono visibili in tutto il file; le altre sono visibili solo dentro lo scope main.