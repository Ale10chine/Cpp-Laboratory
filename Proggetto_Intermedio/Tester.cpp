#include <iostream>
#include "Book.hpp"
#include <vector>


int main(void){
     
     //utilizzo del costuttore di default e stampa
     std::cout<<"Uso il costruttore di default e lo stampo\n";
     Book b;         
     std::cout<<b<<std::endl;
     
     //Oltre ai test necessari per lo sviluppo, devono essere compilabili le seguenti istruzioni:
     std::cout<<"Provo le due righe che devono compilare necessariamente e stampo\n";
     Book b1("David", "Foster Wallace", "Una cosa divertente che non faro' mai piu'", "887-521-837-4"); 
     std::cout<<b1<<std::endl;
     
     std::vector<Book> shelf(10);
     
     //Caso classico in cui va tutto bene
     std::cout<<"Creo un libro con tutto valido e stampo\n";
     Date d2(21,Month::mar,2001);
     Book b2("Giacomo","Leopardi","Le ultime lettere di Jacopo Ortis","123-456-781-3", d2 , 1 );  //Non puoi passare direttamente un oggetto date come parametro, come mai?
     std::cout<<b2<<std::endl;
     
     //Caso in cui la data non esiste
     //std::cout<<"Creo un libro con data di copirygth inesistente\n";
     //Date d3(30, Month::feb,2002);
     //Book b3("Giovanni","Strustourp","Topolino","123-456-789-X",d3,1);
     //std::cout<<b3<<std::endl;
     
     //Caso 1 in cui l'isbn non va bene
     //std::cout<<"Creo un libro con Isbn non valido\n";
     //Date d4(30, Month::jun,2002);
     //Book b4("Giovanni","Mucciaccia","Art-Attack","123-456-78X-X",d4,1);
     //std::cout<<b4<<std::endl;
     
     //Caso 2 in cui l'isbn non va bene 
     //std::cout<<"Creo un libro con Isbn non valido\n";
     //Date d4(30, Month::jun,2002);
     //Book b4("Giovanni","Mucciaccia","Art-Attack","123!456!78X-X",d4,1);
     //std::cout<<b4<<std::endl;
     
     //Caso 3 in cui l'isbn non va bene 
     //std::cout<<"Creo un libro con Isbn non valido\n";
     //Date d4(30, Month::jun,2002);
     //Book b4("Giovanni","Mucciaccia","Art-Attack","---123456789c",d4,1);
     //std::cout<<b4<<std::endl;
     
     //Creo un libro che è già in prestito
     std::cout<<"Creo un libro che e' in prestito\n";
     Date d5(1, Month(3),2002); //funziona anche cast di intero a intero ossia  (..., Month(Month::feb,...)
     Book b5("Giovanni","Strustourp","Topolino","123-456-789-X",d5,0);
     std::cout<<b5<<std::endl;
     
     std::cout<<"Chiedo se posso prendere il libro in prestito o se non e' disponibile\n";
     try{b5.LoanBook(); std::cout<<"Il Libro e' dispondibile\n";} catch (Book::InvalidOperation e){ std::cout<<"il libro NON e' disponibile\n";}
     
     std::cout<<"\n........Nel frattempo L'utente restituisce il libro........\n";
     b5.DeliveryBook();
     
     std::cout<<"\nRIchiedo se posso prendere il libro in prestito o se non e' disponibile\n";
     try{b5.LoanBook(); std::cout<<"Il Libro e' dispondibile\n"; } catch (Book::InvalidOperation e){ std::cout<<"il libro NON e' disponibile\n";}
     
     
     std::cout<< "\n\nConfronto due libri:\n" << std::endl;
     std::cout<< "Utilizzo il costruttore di copia per eguagliare b1 con b2 ossia\n" << b1.get_title() <<" con " <<b2.get_title()<<"\n";
     b1 = b2;  //Costruttore Copy assigment
     std::cout<< "Confronto ora b1 e b2:" << std::endl;
     if (b1 == b2) std::cout << "I libri sono uguali\n" << std::endl;
     std::cout<< "Confronto ora b1 e b5 ossia\n" << b1.get_title() <<" con " <<b5.get_title()<<"\n";
     if (b1 != b5) std::cout << "I libri non sono uguali" << std::endl;
    
    
     Date d6(29, Month::feb, 1992);
     //Date d7(29, Month::feb, 1900); questa data essendo bisestile lancerà l'eccezione InvalidDate
   
    
 return 0;     
};

