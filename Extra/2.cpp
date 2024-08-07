#include <iostream>

using namespace std;


	/*Scrivere un programma che chieda all’utente di inserire alcuni numeri interi, terminando
	la sequenza con il valore sentinella 0. Il programma dovrà contare i numeri multipli di 3
	e quelli dispari inseriti, visualizzare i due contatori e scrivere la frase “Hai inserito più
	numeri multipli di 3” oppure “Hai inserito più numeri dispari” o “I numeri multipli di 3 e
	dispari si equivalgono”. Seguire i seguenti passi per la creazione:
		
	1. definire le variabili necessarie
	2. scrivere l’algoritmo risolutivo in pseudocodice;
	3. tracciare il diagramma di flusso;
	4. scrivere il codice C++
	*/
	
int main(){
	
	int n;
    int mul = 0;
    int disp = 0;

    cout << "Inserisci dei numeri interi (termina con 0):" << std::endl;

    do {
        cin >> n;
        if (n == 0) {
            break;
        }

        if (n % 3 == 0) {
            mul++;
        }

        if (n % 2 != 0) {
            disp++;
        }
    } while (true);

    cout << "Numeri multipli di 3: " << mul << endl;
    cout << "Numeri dispari: " << disp << endl;

    if(mul > disp){
		cout << "Ci sono piu' multipli di 3 che dispari" <<endl;
		} else if( mul < disp){
			cout << "Ci sono piu' dispari che multipli di 3" <<endl;
			} else cout << "I multipli di 3 si equivalgono ai numeri dispari" <<endl;
		

	
	
	
	
	
	
	return 0;
}