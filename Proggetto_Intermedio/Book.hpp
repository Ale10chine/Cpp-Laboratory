#include <iostream>
#include "Date.hpp"

#ifndef BOOK_HPP
#define BOOK_HPP //ricordati di mettere .h e nelle define guards _H


class Book{

  
public:
  //Exception
  class InvalidOperation{};
  //Costructors
  Book(const Book& b) = default;               //Costruttore di copia a default  (Copy constructor) --> Book a; Book b = a;
  Book& operator=(const Book& b) = default;    //overloading dell'operatore di assegnamento, (assegnamento di copia o Copy assigment)  --> Book a; Book b; a = b;
  
  Book(Book&& b) = default;                    //Costruttore di spostamento (Move constructor) vai a vedere bene slide
  Book& operator=(Book&& b) = default;         //Assegnamento di spostamento (Move assignment) vai a vedere bene slide
  
  Book(std::string an = "NO NAME", std::string as = "NO SURNAME",std::string tit = "NO TITLE", std::string isbn = "000-000-000-x", Date d = Date(), bool av= false);
  //Book(std::string an, std:: string as , std:: string tit, std:: string isbn ,Date d ,bool av);
  
  //Function member:
  
  //Modifying functions 
  //void set_title(std::string t){title_ = t;}
  //void set_author_name(std::string n){author_name_ = n;}
  //void set_author_surname(std::string s){author_surname_ = s;}
  void set_date(Date d){ copyrigth_ = d;}                           //nota nonostante abbiamo la classe Date occorre lo stesso avere un set perchè così settiamo la date del libro associato
  void set_isbn(std::string isbn);
  //void set_available(bool a){ available_ = a;}
  
  //NON Modifying functions
  std::string get_isbn() const{ return isbn_;}
  std::string get_title() const{return title_;}
  std::string get_author_name() const{return author_name_;}
  std::string get_author_surname() const {return author_surname_;}
  Date get_copyright() const{return copyrigth_;}
  bool get_available() const{ return available_;}
  
  //other function member (Book Operation)
  void LoanBook(){ if(!available_) throw InvalidOperation(); available_= false;}  
  void DeliveryBook(){if(available_) throw InvalidOperation(); available_= true;}
  
private:
  
  //Data Member
  std::string isbn_;
  std::string title_;
  std::string author_name_;
  std::string author_surname_;
  Date copyrigth_;
  bool available_;
  
  static constexpr int kIsbnFieldSize = 3; // lunghezza campo "n" dell'isbn
  static constexpr int kIsbnLenght = 13; // lunghezza isbn

  
};

//Helper function (solitamente gli overloading degli operatori vanno qui)
std::ostream& operator<<(std::ostream& os,const Book& b);
bool operator==(Book a , Book b);
bool operator!=(Book a, Book b);
  
bool IsIsbn(const std::string& isbn,int len, int field);


#endif // BOOK_HPP


/*NOTE VARIE:
Scelta concettuale/filosofica, i set non ci servono perchè abbiamo deciso
che l'utente non può cambiare nome titolo ecc una vlta che il libro è stato creato, teniamo solo i set che modificano data e isbn
 
Nota isDate la posso usare nel costruttore e non mi da problemi mentre IsIsbn se lo faccio mi crea problemi a meno che non definisca 
quest'ultima o come function member oppure sopra la classe
 
Book(std::string an = "NO NAME" , std:: string as = "NO SURNAME", std:: string tit = "NO TITLE", std:: string isbn = "NO ISBN",Date d = Date(),bool av = true)  //Costruttore di default ? perchè non va d() ? 
   : author_name_ {an}, author_surname_{as}, title_{tit}, isbn_{isbn}, copyrigth_{d}, available_{av} {if(!IsIsbn(isbn)) isbn_="INVALID ISBN";} // perchè non lo mettiamo explicit?
*/