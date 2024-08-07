#include <ostream>
#include "Book.hpp"


//Constructor
/*Book::Book(std::string an, std:: string as , std:: string tit, std:: string isbn ,Date d ,bool av){
     if(!IsIsbn(isbn)) isbn_= "INVALID ISBN";
     isbn_ = isbn; 
     author_name_ = an;
     author_surname_ = as; 
     title_ = tit;
     copyrigth_ = d;
     available_ = av;
}*/

 Book::Book( std::string an, std::string as, std::string tit, std::string isbn, Date d , bool av)
 : isbn_{isbn}, title_{tit}, author_name_{an}, author_surname_{as}, copyrigth_{d}, available_{av} { 
      if(!IsIsbn(isbn, kIsbnLenght, kIsbnFieldSize)) throw InvalidOperation(); 
 }
//Function memeber

 void Book::set_isbn(std::string isbn){
     if(!IsIsbn(isbn, kIsbnLenght, kIsbnFieldSize)) throw InvalidOperation();
     isbn_ = isbn;
 }
//Helper function
 std::ostream& operator<<(std::ostream& os,const Book& b){
     return os<<"Title:"<<b.get_title()<<"\n"
              <<"Author: "<<b.get_author_name()<<","<<b.get_author_surname()<<"\n"
              <<"ISBN: "<<b.get_isbn()<<"\n"
              <<"Copyright Date: "<<b.get_copyright()<<"\n";
 }

 bool operator==(Book a , Book b){
     if(a.get_isbn()==b.get_isbn()) return true;
     else return false;
 }
 bool operator!=(Book a, Book b){
     if(a.get_isbn()!=b.get_isbn()) return true;
     else return false;
 }

 // Ritorna true se la stringa passata rappresenta un isbn.
 // Per il controllo dei caratteri si faccia riferimento alla tabella ascii:
 //      se 96<c<126 allora c è una lettera dell'alfabeto;
 //      se 47<c<58 allora c è un numero.
 bool IsIsbn(const std::string& isbn, int len, int field) {
     if (isbn.size() != len) return false;
     if ((isbn.back()<96 && isbn.back()>123) || (isbn.back()<47 && isbn.back()>58)) return false; // controllo che l'ultimo carattere sia un numero o una lettera

     int f = 0; // contatore lunghezza field
     for (int i=0; i<len-1; i++) {
         if(isbn[i]>47 && isbn[i]<58) ++f; // se il carattere i-esimo è un numero
         else { // se non è un numero stoppo il contatore f
             if (isbn[i] != '-' || f != field) return false; // se il carattere non è un '-' oppure se il contatore
                                                         // non è stato incrementato abbastanza => non è un isbn
             f = 0; // ricominio il conteggio
         }
     }

    if (f != 0) return false;
    return true;
 }


/*NOTE VARIE
 il std:: o Book:: si mette solo se le funzioni sono funzioni membro
 Le funzioni membero vano sempre usate con parametri impliciti
  */
 
 
 
 /*
 bool IsIsbn(std::string isbn){   //Funziona, ma da abellire o migliorare
   bool flag = true;
   int t = 0; //contatore trattini
   int c = 0; //contatore cifre
   int s = 0; //contatore di caratteri (n-n-n-x) la x in sostanza
  
   if(!((isbn[isbn.size()-1]>64 and isbn[isbn.size()-1]<91)||(isbn[isbn.size()-1]>96 and isbn[isbn.size()-1]<123)|| isbn[isbn.size()-1]>47 and isbn[isbn.size()-1]<58)) flag = false;
   if(isbn[3]!='-' || isbn[7]!='-' || isbn[11]!='-') flag = false;
  
   for(int i = 0; i< isbn.size()-2; i++){ // controllo sulla consecutività dei trattini  123-456-789-x  il trattino è nella posizione 3/7/11 | 12
        if(isbn[i]>47 and isbn[i]<58) ++c; // per i numeri basta consultare tabella ASCII, il++c è una chicca di Sturturp
  }   
    if(c != 9) flag = false;
   
      if(flag) return true;
      else  return false; 
} 
*/
 