#include <iostream>

class Rational{                                                  // Nota: Rational:: equivale a std::, puoi bypassarlo con using namespace Rational;
    
public:
     //Contructors
     Rational();                                                 // a default constructor initializing the Rational number to 0,
     Rational(int n);                                            // a constructor accepting an int argument     // quindi qua posso fare siccome non è explicit Rational r = 5 oppure Rational r(5) oppure Rational r = Rational(5)  
     Rational(int n, int d);                                     // Costruttore standard (non richiesto dalla consegna)
     Rational(int n1 , int n2,  int d1, int d2);                 // a constructor accepting two ints for numerator and denominator
     
     //NON modifying functions 
     int getNumerator() const;                                    
     int getDenominator() const;
     double object_doubleconv() const; 

     
     //modifying functions                       
     void  SetRational(int n, int d);                            // assignment    
     
     //Member function
     Rational  Add(const Rational& r);                           // addition
     Rational  Subs(const Rational& r);                          // subtraction
     Rational  Mul(const Rational& r);                           // multiplication
     Rational  Div(const Rational& r); //occhio al const         // division
     
     // Overloading degli operatori come Member function         // equality (==), greater than (>) and less than (<)  and output to stream (<<)                      
     bool operator==(const Rational& r);                         // operators. Also, provide a conversion to double via a to_double function.
     bool operator>(const Rational& r);
     bool operator<(const Rational& r);
     //bool operator<<(const Rational& r); ??
     Rational operator+(const Rational& r);                      // Overload operatore + tra due oggetti Rational
     Rational operator+(int c);                                  // Overload operatore + tra un oggetto Rational e un intero
     Rational operator-(const Rational& r);                      // Overload operatore- (non richiesto)
     Rational operator*(const Rational& r);                      // Overload operatore* (non richiesto)
     Rational operator/(const Rational& r);                      // Overload operatore/ (non richiesto)
     
private:

     int num;
     int den;

    };   // ricorda il punto e virgola dopo la classe 
  
  //Both overloads shall be implemented in two ways: using a member function and a helper function
  //(they should not be implemented at the same time!).
  
  //Helper function
  std::ostream& operator<<(std::ostream& os, Rational& r);
  /*
  bool operator==(const Rational& a, const Rational& b);
  bool operator>(const Rational& a, const Rational& b);
  bool operator<(const Rational& a, const Rational& b);
  Rational operator+(const Rational& a, const Rational& b);
  Rational operator+(const Rational& r, int c);
  Rational operator-(const Rational& a, const Rational& b);
  Rational operator*(const Rational& a, const Rational& b);
  Rational operator/(const Rational& a, const Rational& b); 
  */ 
  int mcm_calculator(int a , int b);          
  Rational semplify_function(int n, int d);   
   
   
   
   
   
   
   
   
   /* Metodo alternativo per implementare la classe, in questo modo andavo a modificare direttamente l'oggetto "parametro implicito"
      
      Rational();                                                
      Rational(int n);                                    //a constructor accepting an int argument
      Rational(int n1 , int n2,  int d1, int d2);         //a constructor accepting two ints for numerator and denominator
    
     void  SetRational(int n, int d);                      // assignment
     void  Add(Rational& r);                               //addition
     void  Subs(Rational& r);                              //subtraction
     void  Mul(Rational& r);                               //multiplication
     void  Div( const Rational& r); //occhio al const      //division
    
     bool operator==(const Rational& r);
     bool operator>(const Rational& r);
     bool operator<(const Rational& r);
     bool operator<<(const Rational& r);
    */