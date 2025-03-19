#include <iostream>
using namespace std;


void f();
void f_illegal();
//void print_array(int a[]);

int main(void){
     
    //f(); 
    f_illegal();   //da problemi anche poco fuori dall'array
     
     
 return 0;
}

void f(){
    
    int arrayC[10];
    int* p = &arrayC[1];
    
    for(int i = 0; i < 10; i++){
         p[i] = i+1;
         }
    cout<<"f() : \n";     
    cout<<p[3];
    cout<<"\n"<<p[33];   
    cout<<"\n"<<p[34];
    //cout<<"\n"<<p[35];
    //cout<<"\n"<<p[500];
    //cout<<"\n"<<p[5000];
    //cout<<"\n"<<p[50000];  in questo range da problemi in esecuzione, si passa da memoria allocata a memoria non allocata
    //Non c'è il controllo sulla memoria che vai a leggere (su java lancia un eccezione, mentre qua non hai il controllo sul tipo) 
    // p[x>=10] è memoria sporca ossia garbage collector
}

void f_illegal(){
     
    int arrayC[10];
    int* p = &arrayC[1];
    
    for(int i = 0; i < 10; i++){
         p[i+10] = i+1;
         }
    cout<<"f()_illegal : \n";       
    cout<<p[3];
    cout<<"\n"<<p[12];   
    cout<<"\n"<<p[13];
    cout<<"\n"<<p[14];
    //Non puoi scrivere la dentro perchè non è presente alcua cella inizializzata dell'array
     
}






/*

1. What is a dereference operator and why do we need one?
2. What is an address? How are memory addresses manipulated in C++?
3. What information about a pointed-to object does a pointer have? What useful information
does it lack?
4. What can a pointer point to?
5. When do we need a pointer (instead of a reference or a named object)?

*/