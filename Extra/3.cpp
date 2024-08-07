#include <iostream>
#include <cstdlib> // Per rand() e srand()
#include <ctime>   // Per time()

using namespace std;

	/*
	Scrivere un programma che simuli N = 18.000.000 volte l'esito dell'estrazione di un
	numero del lotto (vanno da 1 a 90) e conti quante volte esce ciascun numero.
	Definire opportunamente la costante intera N (globale) e un array di contatori.
	Visualizzare il risultato in output mettendo in colonna righe come “Il numero 7 è
	uscito 200304 volte” per ognuno dei 90 numeri.
	*/

int main(){
	
	// Inizializza il generatore di numeri casuali con il seme di tempo corrente
    srand(static_cast<unsigned>(time(nullptr))); 
	
	// Inizializza l'array di contatori
	int a[90];
	for (int i = 0; i < 90; i++) a[i] = 0; 
	
	long int i = 0;
	
	for( i = 0; i < 18000000; i++){
		// Genera il numero casuale nell'intervallo [min, max]
		int ran = 1 + (rand() % (90 - 1 + 1));
		a[ran] = a[ran] + 1;
	}
	
	for( int i = 0; i < 90; i++) cout << "Il numero " << i+1 << " e' stato generato randomicamente " << a[i] << " volte" <<endl;
	
	
	return 0;
}

//Note sul codice: 

/*
 "nullptr" Indica che vogliamo semplicemente ottenere il tempo corrente
 e non ci interessa ottenere un puntatore ad un oggetto time_t. Quindi, time(nullptr) restituirà il valore del tempo corrente
 in secondi.
  
 static_cast, un operatore di C++ utilizzato 
 per effettuare conversioni esplicite tra tipi di dati. 
 In questo caso, viene effettuata una conversione esplicita del valore restituito da time(nullptr) in un tipo di dato unsigned.
 Ciò è fatto per assicurarci che il seme del generatore di numeri casuali sia un valore non negativo,
 poiché il generatore di numeri casuali richiede un seme positivo.
  
 srand(...): La funzione srand() è definita nella libreria <cstdlib> ed è utilizzata per impostare il seme 
 del generatore di numeri casuali (rand()) in modo che i numeri casuali generati siano diversi ad ogni esecuzione del programma.
 Passando il valore convertito di time(nullptr) come argomento a srand(), stiamo impostando il seme del generatore di numeri casuali in base al tempo corrente.

 //Come generare un numero randomico
	
	// Inizializza il generatore di numeri casuali con il seme di tempo corrente
    srand(static_cast<unsigned>(time(nullptr))); 

    // Definisci l'intervallo desiderato [min, max]
    int min = 1;
    int max = 90;

    // Genera il numero casuale nell'intervallo [min, max]
    int numeroCasuale = min + (rand() % (max - min + 1));

    // Stampa il numero casuale generato
    cout << "Numero casuale generato: " << numeroCasuale << endl;
*/