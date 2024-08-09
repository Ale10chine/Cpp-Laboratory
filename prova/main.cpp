#include <iostream>
using namespace std;
void HelpMe(int *p, int *num, int *q);
void WhereAmI(int *p, int *q, int a);
void HelpMe(int *p, int *num, int *q) {
 int a;
 a = 2;
 q = &a;
 *p = *q + *num;
 num = p;
}
void WhereAmI(int *p, int *q, int a) {
 a = 6;
 *p = a + *p;
 *q = a + 3;
 HelpMe(q, &a, p);
}
int main() {
	

 int *p;
 int q;
 int *num;
 int a;
 a = 3;
 q = 5;
 p = &a;
 num = &q;
 HelpMe(&a, p, num);
 //WhereAmI(&q, p, *num);
 cout << "*p = " << *p << " q = " << q << " *num = " << *num << endl;
 
 /*
 int *p = new int[10];
	for (int i = 0; i < 10; ++i)
		p[i] = i;
 int *q = &p[3];
 cout << q[-2] << endl;

*/

 return 0;
}


/*
Per libreria in C++ si intende uno strumento che permette di raggruppare codice già scritto ed eseguito in ulteriori
progetti all'interno di uno nuovo. E' banale intuire la sua convenienza in termini di comodità, passare e includere 
algoritmi già implementati in progetti esterni da quello corrente è una pratica che semplifica di gran lunga il lavoro del programmatore.

Le librerie sono di due tipologie:

Librerie statiche: Anche dette self-contained generano eseguibili che non possono essere spezzati in seguito.
Il loro vantaggio principale è che sono più adatte alla distribuzione di software monolitico
ossia autonomo ma al contempo può presentarsi come uno stesso limite.

Librerie dinamiche: In queste librerie più file fanno riferimento alla stessa libreria precompilata, 
così facendo possono essere ricompilate senza toccare gli eseguibili.
Hanno il vantaggio di occupare molto meno spazio sul disco. Lo svantaggio è che non sono autonomi ossia self contained.

Il concetto di template può essere assocciato a quello di strumento fornito dal linguaggio c++ 
finalizzato alla programmazione generica. In particolar modo tramite template è possibile la 
parametrizzazione e conseguentemente la specializzazione per qualsiasi tipo di funzione o classe.
Per esempio attraverso questo meccanismo è possibile rendere utilizzabile una funzione da qualsiasi tipo di oggetto,
ciò implica la possibilità di utilizzare la stessa funzione (con i suoi specifici obbiettivi) per più ambiti diversi tra di loro.

template <typename T>
void f(){


}*/









     /*
     std::vector <int> v_ = std::vector <int> (7);
     
     for(int i = 0; i < v_.size(); i++) v_[i] = i+1;
     
          std::cout<<"Le mosse possibili sono:\n";
     for(int i = 0; i < v_.size(); i++) std::cout<<v_[i]<<"\n";
    
     std::cout<<"la size di v e :"<< v_.size()<<"\n"; int tmp = v_.size();
     for(int i = 0; i < tmp; i++) v_.pop_back(); //se metto 7 funziona
     
      std::cout<<"la size di v dopo i pop e :"<< v_.size()<<"\n";
     std::cout<<"Dopo aver svuotato il vettore lo stampo dovrebbe essere nullo\n";
     for(int i = 0; i < v_.size(); i++) std::cout<<v_[i]<<"\n";
     std::cout<<"\n\n\n";
	  */
	  /*
    std::cout << "Hello World" << std::endl;
	Sleep(5000);
    system("cls");
    std::cout << "Ciao amico mio" << std::endl;*/