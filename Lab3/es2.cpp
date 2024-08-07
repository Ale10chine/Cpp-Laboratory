#include <iostream>
using namespace std;

void print_array_length(int a[]);

int main(void){
     
     constexpr int dim = 15;
     double a[dim];
     
     cout<<"La dimensione dell'array e': "<<sizeof(a)/8; //sizeof ritorna in byte
     
     cout<<"using print_array_length...\n";
   //  print_array_length(a);
     
return 0;     
}

/*void print_array_length(int a[]){ //Sizeof of ana array function parameter wil return sizeof 'int*' instead of 'int'     
    cout<<"La dimensione dell'array e': "<<sizeof(a)/8; //sizeof ritorna in byte
     
}*/