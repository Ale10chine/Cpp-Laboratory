#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP
     
    //Costructors 
    
     //Constructor con initializer list         CONTROLLARE LOGICSIZE
    template <typename T>
    MyVector<T>:: MyVector(std::initializer_list<T> lst)               //Questa sintassi si chiama costruttore con lista di inizzializzazione
     : size{int(lst.size())},logic_size{size}, elem{new T[size]} {     //Tra l'altro questo è anche un initializer list che viene chiamato con le graffe!
      std::copy(lst.begin(), lst.end(), elem);
     }
     
    //Copy constructor
    template <typename T>
    MyVector<T>:: MyVector(const MyVector<T>& v)
     : size{v.size}, logic_size{v.logic_size}, elem{new T[v.size]} {
     std::copy(v.elem, v.elem + v.size, this->elem);                        // SIZE O LOGIC SIZE? SIZE in quanto copiamo tutta la dimensione fisica 
                                                                            //anche nella nuova rialocazione
     }
     
    //Move constructor
    template <typename T>
    MyVector<T>:: MyVector(MyVector<T>&& v)
     :size{v.size}, elem{new T[v.size]} {                                   // Punta il primo elemento NON all'ultimo, grazie al new
     this->elem = v.elem;
     v.elem = nullptr;
     v.size = 0; 
     v.logic_size = 0;
     
     }

     
    //Modifying functions
    
   //template <typename T>   //SOSTITUITE DALLA FUNCTION MEMEBR "at"
   //void MyVector<T>::safe_set(int pos , T val){
     //if (!(pos < this->size && pos > -1)) throw std::out_of_range("Out of range");
     //elem[pos] = val;
     //}
     
    //NON Modifying functions
    
    //template <typename T>   //SOSTITUITE DALLA FUNCTION MEMEBR "at"
    //T MyVector<T>::safe_get(int pos) const{ 
     //if (!(pos < this->size && pos > -1))  throw std::out_of_range("Out of range");
     //return elem[pos];
     //}
     
     template <typename T>
     void MyVector<T>::print_vector() const{                         //Ovviamente stampiamo fino a logic size perchè non in tutta la dim fisica
      if (!this->elem) return;                                       //Il nostro vector contiene qualcosa
      std::cout << "[";
      for (int i=0; i<logic_size-1; i++)
           std::cout << elem[i] << ", ";
      std::cout << elem[logic_size-1] << "]" << std::endl;
          
     }
        
    //Overloading come member function
    template <typename T>
    T MyVector<T>::operator[](int pos) const{ return elem[pos];}
    
    template <typename T>
    T& MyVector<T>::operator[](int pos) { return elem[pos];}
    
    //copy assignment
    template <typename T>
    MyVector<T>& MyVector<T>:: operator=(const MyVector<T>& v){    
    T* ptr = new T[v.size];                                    // alloco dinamicamente
    std::copy(v.elem, v.elem + v.size, ptr);                   // copio gli elementi di v

    delete[] this->elem;                                       // dealloco elem
    this->elem = ptr;                                          // elem punta alla cella puntata da ptr
    this->size = v.size;                                       // fisso la dimensione
    this->logic_size = v.logic_size;                           // torno un auto riferimento
    return *this;
    }
    
    //Move assignment
    template <typename T>
    MyVector<T>& MyVector<T>::operator=(MyVector<T>&& v){        
    delete[] this->elem;
    this->elem = v.elem;
    this->size = v.size;
    this->logic_size = v.logic_size;
    
    v.elem = nullptr;
    v.size = 0;
    v.logic_size = 0;
    
    return *this; 
      
    }
    
    template <typename T> //.............................SPIEGARE LA DIFFERENZA CON LA NON CONST e implementara qui e provarla nel tester
    T MyVector<T>::at (int n) const{
         
         
     return nullptr;    
     }
    
    
    
    template <typename T> // <T> obj = v.at(5) con move constructor e assignment   
    T& MyVector<T>::at (int n){   //accesso con boundary check
     if(n>this->logic_size) throw std::out_of_range("Out of range");
     return this->elem[n];  // è più corretto ritornare this->elem[n] o elem[n] ?
     }
    
    template <typename T> //......................
    void MyVector<T>::push_back(const T& val){ //v.push_back("ciao") per allocare in coda un generico T 
       if(this->size == 0) reserve(5);                             // Può essere una soluzione valida instanzialre un size pari a 10 se si inizizalizza un MyVector con il costruttore vuoto?
       if(this->logic_size == this->size) reserve((this->size)*2);  //ma reserve non avendo nessun parametro implicito a chi si riferisce? mi prende in automatico il parametro di push?
       elem[this->logic_size] = val;                                //Nota se il v ector è vuoto e facciamo delle push, essendo size 0 ogni volta la dimensione sarà nuovamente 0 
       this->logic_size++; 
     }
     
     template <typename T> // v.pop_back() per rimuovere l'ultimo elemento in coda    //.................
     T MyVector<T>::pop_back(){ 
      logic_size--;
      return elem[logic_size+1];
     }
                                                                                     
     template <typename T>  //v.reserve(5) per aumebntare di 5 slot il vector ricorda che il tipo avendo implementato il template è geenrico
     void MyVector<T>::reserve (int new_alloc){                    //Ogni volta se aumenti solo di una piccola parte potrebbe essere problematico perchè così questa funzione potrebbe essere chiamata molte volte, prova un rimedi tipo come java che facevamo il *2
      if(new_alloc <= this->size ) return;                         // non vogliamo che la nuova allocazione sia minore o uguale della dimensione fisica
       T* ptr = new T[new_alloc];                                   // alloco dinamicamente il nuovo spazio
       std::copy(this->elem, this->elem + this->logic_size, ptr);   // copio gli elementi di v , ptr è il da dove parto a copiare nel nuovo vettore (più correttamente nella nuova allocazione)  
       delete [] elem;                                              // dealloco il vecchio puntatore per evitare di creare garbage
       this->elem = ptr;
       this->size = new_alloc;   
       
     }
     
     
     
#endif

/*
NOTE IMPORTANTI:
 Come mai sulle funzioni non cost non serve mettere il MyVector<T>:: ?
 Con new e la riga di codice "elem{new T[v.size]}" il puntatore elem punta al pirmo dato della nuova allocazione con dimensione v.size
 Schematizza concetto di garbage che si crea ragionando su come avevi fatto inizzialmente te nella funciotn reserve, ossia
 vai a perdere il riferimento del vettore implicito creando appunto garbage perchè ricorda che la memoria è in posizione differente, randomica e non consecutiva
 
 Quando lavori con elem, o in generale i puntatori non ragionare in termini di posizione iesima, ossia dato quel puntatore accedo alla ceella x, ogni puntatore punta ad un vector
 una volta che lo si cancella si perde il riferimento in memoria a quella cella di memoria deallocandone anche lo spazio cumulativo di memoria
  
 NOTA, essendo ancora i primi programmi con i puntatori preferisco esplicitare l'uso di this per esplicitare il fatto che mi riferisco alla data member dell'oggetto passato
 come parametro implicito, anche se ovviamene si può a fare a meno lavorando all'interno del "namespace?"  MyVector<T>::





*/