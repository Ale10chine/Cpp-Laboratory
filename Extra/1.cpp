#include <iostream>

using namespace std;


	/*
	Scrivere un programma che chieda all’utente di inserire N = 20 valori reali, calcoli
	(usando un ciclo for) e visualizzi la somma e la media dei numeri inseriti. Seguire i
	seguenti passi per la creazione:

	1. definire le variabili necessarie
	2. scrivere l’algoritmo risolutivo in pseudocodice;
	3. tracciare il diagramma di flusso;
	4. scrivere il codice C++
	*/
	
int sum(int a[], int dim);
int average(int a[], int dim);

int main(){
	int dim = 20;
	int a[dim];
	
	for(int i = 0; i < 20; i++){
		cout<<"Inserisci il "<<i+1<<" numero"<<endl;
		cin >> a[i]; 
	}
	
	cout<<"La somma sara': "<<sum(a,dim)<<endl;
	cout<<"La media sara': "<<average(a, dim)<<endl;
	
	return 0;
}

int sum(int a[], int dim){
	int s;
		for(int i = 0; i < dim; i++){
			s += a[i];
		}
	return s;
}
int average(int a[], int dim){
	int av;
		for(int i = 0; i < dim; i++){
			av += a[i];
		}
	av = av/dim;
	
	return av;
}