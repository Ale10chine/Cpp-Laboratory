#include <iostream>
#include <initializer_list>

class MyVector{
     
public:
     //Constructors
     MyVector() {size = 0; elem = nullptr; }                    //Per i costruttori semplici fornisco anche la definizione
     
     explicit MyVector(int s) : size {s}, elem{new double[s]}   //size {s} invece è il controllo sul tipo
     {if(s == 0) elem = nullptr;}                               //corpo costruttore, va bene anche: MyVector(int s) {size = s; elem =new double[s]; {if(s == 0) elem = nullptr;}  }  
    
     MyVector(std::initializer_list<double> lst); // Costruttore con initializer list usando il template <double>, richiediamo solo quel tipo la all'interno della lista
     
     
     MyVector(const MyVector& v);    // copy costructor
     MyVector(MyVector&& v);         // move costructor
     
     MyVector& operator=(const MyVector v);  //copy assignment
     MyVector& operator=(MyVector&& v);      //move assignment
     
     //Modifying functions
     void safe_set(int position , double val); 
     
     //NON Modifying functions
     double safe_get(int position) const; 
     void print_vector() const;
        
     //Overloading come member function
     double operator[](int pos) const; //versione const
     double& operator[](int pos);      //versione senza const    PERCHE SI FA IN DUE MODI?

        
     //Destructor
     ~MyVector() { delete[] elem;};               //tilde si fa con alt+126  , anche questo essendo semplice come def lo faccio direttamente qua

private:

     int size;     //dimensione MyVector
     double* elem; //puntatore 
     
   
};

/*
 NOTE VARIE: 
  - Quando si va a creare una classe se le data member sono poche come questo caso si evita di scrivere private e le si dichiara all'inizio
    altrimenti è buon uso fare il private: alla fine della parte public 
  - Quando consideriamo in una member function la data member size ci riferiamo sempre al
    oggetto passato come parametro implicito ossia quello puntato dal puntatore this->
  - A cosa serve explicit? Serve a invocare esplicitamente il costruttore...
    explicit MyVector(int s) ad esempio in questo caso posso solo invocarlo così v(10) 
    cioè stiamo evitando la possibilità di fare questo v = 10 che di default secondo la sintassi C++ lo farebbe, ad esempio
    nella classe Rational.hpp (header) vedi riga 8 per capire meglio
     
  - Con l'overloading dell'operatore = andiamo a fare la deep copy, vedi slide (12 ppt 2 lez 8 ) ossia abbiamo overloddato l'operatore  = sia facendo un copy assignment
    che facendo un move assignment passando dalla Shallow copy alla Deep copy (dalla copia superficiale di soli puntatori o reference senza copiare dati, alla
    copia dei dati gestendo bene i vari casi) Questo processo è obbligatorio farlo ed è molto importnate per evitare deadling pointer o garbage e addiriturra
    sovrascittura di specifici spazi di memoria. RICORDA: tipi che implementano una shallow copy hanno "pointer smantics" (o "reference semantics"), tipi che
    implementano una deep copy hanno una "value semantics".
  - Se io ho un oggetto passato come parametro esplicito di "tipo" oggetto constante (const)
    posso invocare funzioni solo di tipo const.
  - Quando passo un oggetto tramite const reference ad esempio (const MyVector& v) gli sto passando
    con la & una reference ossia gli sto passando l'indirizzo e di conseguenza mi andrà a modificare 
    l'oggetto originale però essendoci il const, questo passaggio aviene solo in lettura, passandro 
    (const MyVector v) cosi facendo stiamo passando una copia const cosa succede??? ...
  - Riorda che una initializer list è un handle a elementi allocati "altrove"
   SPIEGARE UNA VOLTA PER TUTTE COME USARE CONST NELLE FUNZIONI
  */
