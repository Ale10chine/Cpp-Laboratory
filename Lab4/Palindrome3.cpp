#include <iostream>

bool is_palindrome(const char* first, const char* last);

// (per convenzione la lunghezza si riferisce ai caratteri validi ed esclude il terminatore ‘\0’);

int main(void){
     
     //char a[] {'o','s','s','o','\0'};
     char b[] {'R','o','B','o','R','\0'};
     
     char* p1 = &b[0];
     char* p2 = &b[4];
     
      if(is_palindrome(p1,p2) == true) std::cout<<"e'palindroma\n"; // posso passare anche direttamente is_palindrome(a,a+length)
      else std::cout<<"NON e' palindroma\n"; 
     
}

bool is_palindrome(const char* first, const char* last){
     
     const char* t1 = first; // cos il puntatore che ho creato sta puntando a quello che punta first(cioè p1), NOTA il const
     const char* t2 = last;
     
     
      while(last != t1 and  first != t2){
          
           if(*first != *last)     //Così sto facendo una dereference dei puntatori, cioè accedo a quello che sta puntando il puntatore
               return false;
          first = first +1; //l'incremento deve essere unitario e non first + c con c che ad ogni ciclo incrementa altrimenti usciamo nel campo di interesse del puntatore nell' array char
          last = last -1;
     
      }
return true;     
}