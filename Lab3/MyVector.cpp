#include "MyVector.hpp"
     
     
    //Costructors 
    
    //Copy constructor
    MyVector:: MyVector(const MyVector& v)
     : size{v.size}, elem{new double[v.size]} {
     std::copy(v.elem, v.elem + v.size, this->elem);     

     }
    //Move constructor
    MyVector:: MyVector(MyVector&& v)
     :size{v.size}, elem{new double[v.size]} {
     this->elem = v.elem;
     v.elem = nullptr;
     v.size = 0; 
     
     }
    //Constructor con initializer list
    MyVector:: MyVector(std::initializer_list<double> lst) //Questa sintassi si chiama costruttore con lista di inizzializzazione
     : size{int(lst.size())}, elem{new double[size]} {     //Tra l'altro questo è anche n initializer list che viene chiamato con le graffe!
      std::copy(lst.begin(), lst.end(), elem);
     }
     
    //Modifying functions
    void MyVector::safe_set(int pos , double val){
     if (!(pos < this->size && pos > -1)) throw std::out_of_range("Out of range");
     elem[pos] = val;
     } 
     
    //NON Modifying functions
    double MyVector::safe_get(int pos) const{ 
     if (!(pos < this->size && pos > -1))  throw std::out_of_range("Out of range");
     return elem[pos];
     }
     
     void MyVector::print_vector() const{
      if (!this->elem) return;
      std::cout << "[";
      for (int i=0; i<size-1; i++)
           std::cout << elem[i] << ", ";
      std::cout << elem[size-1] << "]" << std::endl;
          
     }
        
    //Overloading come member function
    double MyVector::operator[](int pos) const{ return elem[pos];}
    double& MyVector::operator[](int pos) { return elem[pos];}
    
    //copy assignment
    MyVector& MyVector:: operator=(const MyVector v){    
    double* ptr = new double[v.size]; // alloco dinamicamente
    std::copy(v.elem, v.elem + v.size, ptr); // copio gli elementi di v

    delete[] this->elem; // dealloco elem
    this->elem = ptr; // elem punta alla cella puntata da ptr
    this->size = v.size; // fisso la dimensione
    return *this; // torno un auto riferimento
    }
    //move assignment
    MyVector& MyVector::operator=(MyVector&& v){        
    delete[] this->elem;
    this->elem = v.elem;
    this->size = v.size;

    v.elem = nullptr;
    v.size = 0;

    return *this; 
      
    }

    /*
    NOTE VARIE:
    La funzione copy va a scrivere in delle cella consecutuive in memoria, partendo dall'elemento puntato da v.elem
    fino a v.eleme+v.size ossia usando l'aritmetica dei puntatori glistiamo dando un range
    DOMANDA:stiamo passando un puntatore che funge da iteratore?
    
    
    
    */