#include <ostream>
#ifndef DATE_HPPclTabCtrl
#define DATE_HPP

enum class Month; //dichiarazione dell'enumerazione secondo lo stesso principio delle funciton memeber

class Date{
  int day_;   
  Month month_;
  int year_;
  
     
public:
  //Exception
  class InvalidDate{};
  //Constructors
  
  Date(const Date& d) = default;               //Costruttore di copia a default  (Copy constructor) --> Date a; Date b = a;
  Date& operator=(const Date& d) = default;    //overloading dell'operatore di assegnamento, (assegnamento di copia o Copy assigment)  --> Date a; Date b; a = b;
  
  Date(Date&& d) = default;                    //Costruttore di spostamento (Move constructor) vai a vedere bene slide
  Date& operator=(Date&& d) = default;         //Assegnamento di spostamento (Move assignment) vai a vedere bene slide
  
  
  //Default constructor
  Date(int d = 1 , Month m = Month(1) , int y = 1977); //Implementato con initializer list in modo che se mancano dati, li setta di default in questo modo si evitano troppi costruttori
   
   
  //Function member:
  
  //Modifying functions 
  void set_day(int d); // il const non serve dato che ci serve modificare
  void set_month(Month m); // cosa succede se passo 13?
  void set_year(int y);
  
  //NON Modifying functions
  int get_day() const{return day_;}
  Month get_month() const{return month_;}
  int get_year() const{return year_;}
  
  //----------function member ulteriori non di base....
};

enum class Month{
  jen = 1, feb, mar, apr, may, jun, jul, ago, sep, oct, nov, dec   
};

//Helper function
bool IsDate(int d, Month m, int y);
bool LeapYear(int y); // anno bisestile
std::ostream& operator<<(std::ostream& os,const Date& d);
#endif // DATE_HPP


/*
 Solitamente è una cosa più logica fare tanti set e get in base a quante sono le variabili data member

 riga 18: serve per dire a chi legge il codice che non mettiamo il costruttore di copia particolare ma 
 lasciamo a default perchè ci va bene che copi tutti i campi (vai a vedere cosa succede in MyVector)
  
 Nota, se non si fa l'enumerazioni con la dichiarazione simil funzione negli scope sovrastanti non verrà vista
 */