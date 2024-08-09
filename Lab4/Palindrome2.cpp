#include <iostream>

bool is_palindrome(const char a[], int length);
//void print_array(const char a[]);

//riferisce ai caratteri validi ed esclude il terminatore ‘\0’);
int main(void){
     
     
 char a[] {'o','s','s','o'};
 //char a[] {'o','s','s','o','\0'}; se uso il carattere di fine stringa devo passare lenght-1 ovviamente
 int length = (sizeof(a))/(sizeof(char))-1; // il -1 è dovuto al carttere di fine stringa
 //std::cout<<"Verifichiamo che l'array di char '"<<print_array(a)<<"' sia palindroma\n";
 
 if(is_palindrome(a,length) == true) std::cout<<"e'palindroma\n";
 else std::cout<<"NON e' palindroma\n";
     
}


bool is_palindrome(const char a[], int length){
     char reverse[length];
     for(int i = length, j = 0;i>0;i--){
          reverse[j++] = a[i]; 
     } 
     for(int i = 0; i<length; i++){
          if(reverse[i] != a[i]){ return false;}
     }
     return true; 
}
/*
void print_array(const char a[]) { // occhio passando const char a[] sto passando un puntatore alla prima cella dell'array

     for(int i = 0;i<a.size();i++){
          
          
     }
     
}
 */

//NOTA importante non confondere std::array con array stile C tipo quello che sto usando ora char a[]