#include <iostream>
using namespace std;

void print_reference(int &a, double &b);
void print_pointer(int* p1, double* p2);

int main(void){
     
     int a = 1;
     double b = 1.1;
     
     int* p1 = &a;
     double* p2 = &b;
     
     print_reference(a,b);
     print_pointer(p1,p2);
     
 return 0;     
}

void print_reference(int &a, double &b){
     
     cout<<"\nLe variabili passante per reference sono:\n";
     cout<<"a = "<<a<<"\n";
     cout<<"b = "<<b<<"\n";
}

void print_pointer(int* p1, double* p2){
     
     cout<<"\nLe variabili passante per reference sono:\n";
     cout<<"a = "<<p1[0]<<"\n";
     cout<<"b = "<<p2[0]<<"\n";     
}