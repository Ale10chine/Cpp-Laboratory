#include <iostream>
#include <cstdlib> // Per rand() e srand()
#include <ctime>   // Per time()

using namespace std;


/* Scrivere un programma simuli l'estrazione di due carte da un mazzo di 40, e calcoli
quante volte vengono estratte due carte di spade; effettuare prima N = 1.000.000
simulazioni con il reinserimento della prima carta, poi senza, utilizzando due
contatori distinti c_r, c_sr. Il programma contenga un commento in cui spiegate il
modello usato. Visualizzare i risultati alla fine della simulazione.
*/


// Nel mazzo di scopa ci sono 4 semi ognuno da 10 carte, dunque considerando questo mazzo
// ci saranno in tutto 10 carte di spade

//Considerando un array di lunghezza 40, i numeri compresi tra 1 e 10 saranno conteggiati
//come appartenenti al seme delle spade non potendo utilizzare stringhe o oggetti identificaivi

int main(){
	
	int mazzo[] {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	
	int c_r = 0; int c_sr = 0;
	int rnd = 0; int rnd2 = 0;
	
	srand(static_cast<unsigned>(time(nullptr))); 
	
	
	//Conteggio con reinserimento, NOTA: posso fare a meno di utilizzare l'array in quanto la prima carta pescata viene sempre reinserita prima della seconda pescata
	for(int i = 0; i < 1000; i++){
		
		rnd = 1 + (rand() % (40 - 1 + 1));
		rnd2 = 1 + (rand() % (40 - 1 + 1));
		//Stampa
		cout<<i+1<<") "<<rnd<<endl;
		cout<<i+1<<") "<<rnd2<<endl;
		
			if((rnd >= 1 and rnd <= 10) and (rnd2 >= 1 and rnd2 <= 10)) c_r++;
	}
	
	
	//Conteggio senza reinserimento
		for(int i = 0; i < 1000; i++){
		
		rnd = 1 + (rand() % (40 - 1 + 1));
		mazzo[rnd] = 0; // Setto uno 0 per capire che in questa posizione la carta è stata presa
		
		do {
			rnd2 = 1 + (rand() % (40 - 1 + 1));
		}while(mazzo[rnd2] == 0);
		
		//Stampa
		cout<<i+1<<") "<<rnd<<endl;
		cout<<i+1<<") "<<rnd2<<endl;
		
			if((rnd >= 1 and rnd <= 10) and (rnd2 >= 1 and rnd2 <= 10)) c_sr++;
		mazzo[rnd] = 1; // Metto di nuovo 1 per far si che il mazzo sia pronto di nuovo a una doppia pescata
	}
	
	cout<<"\nIn totale si sono verificate "<<c_r<<" pescata/e di due carte del seme di spade reinserendo man mano la prima carta che usciva"<<endl;
	cout<<"\nIn totale si sono verificate "<<c_sr<<" pescata/e di due carte del seme di spada senza reinserimenti"<<endl;
	
	return 0;
}