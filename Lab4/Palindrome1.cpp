#include <iostream>

bool is_palindrome(const std:: string& s);

int main(void){
     
     
 std::string s {"osso"};
 std::cout<<"Verifichiamo che la stringa '"<<s<<"' sia palindroma\n";
 
 if(is_palindrome(s) == true) std::cout<<"e'palindroma\n";
 else std::cout<<"NON e' palindroma\n";
     
}


bool is_palindrome(const std:: string& s){
     std::string reverse;
     for(int i = s.size()-1;i>=0;i--){
          reverse = reverse + s[i]; 
     } std::cout<<"reverse e':"<<reverse<<"\n";
     if(reverse == s) return true;
     else return false; 
}