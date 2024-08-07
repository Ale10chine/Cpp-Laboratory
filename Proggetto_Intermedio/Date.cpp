#include <ostream>
#include "Date.hpp"

 //Costructors
 Date::Date(int d , Month m , int y)
 : day_{d} , month_{m} , year_{y} {
     if(!IsDate(d,m,y)) throw InvalidDate();
     } 

 //Modifying functions 
 void Date::set_day(int d){   // il const non serve dato che ci serve modificare
    if(!IsDate(d,month_,year_)) throw InvalidDate();
      day_= d;
 }     

 void Date::set_month(Month m){
      if(!IsDate(day_,m,year_)) throw InvalidDate();
      month_ = m;   
 }                 
 void Date::set_year(int y){
      if(y < 0) throw InvalidDate();
      year_ = y;
 }


 //Helper function 
 bool IsDate(int d, Month m, int y) {
     if (y < 0) return false;
     if(d<1 || d > 31) return false;
     switch(m) {
         case Month::feb:
             if (!LeapYear(y) &&  d > 28) return false;
             else if (d > 29) return false;
             break;
         case Month::nov: case Month::apr: case Month::jun: case Month::sep:
             if (d != 30) return false;
             break;
         default:; // Nothing ci va o no sta riga? per togliere l'errore alla riga 27
     }
     return true;
 }

 // Restituisce true se l'anno passato è bisestile
 bool LeapYear(int y) {
     if ((y % 400) == 0) return true;
     return (((y % 4 ) == 0) && (y % 100) != 0 );
 }

 std::ostream& operator<<(std::ostream& os,const Date& d){
      return os<<d.get_day()<<"/"<<int(d.get_month())<<"/"<<d.get_year();
 }

 //Contestualizza ragionamento dietro i controlli di date


/*  Funziona ma da abbellire graficamente
 
 bool IsDate(int d, Month m, int y){ // Dato che è una helper function non serve Date::
     if((d<1 && d>31)||y<0) return false; 
     if(m==Month::feb && d>28) return false; 
     if((m==Month::nov || m==Month::apr || m==Month::jun || m==Month::sep) && d==31) return false;
      
      return true;
       
} */