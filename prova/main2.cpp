#include <iostream>
#include <vector>
#include <list>

template <typename T, typename C>
T f(T a , C b){
	std::cout<<a<<" "<<b<<std::endl;
	return a + b;//devo controllarlo io il cast?
}

void f_const_reference(const int &a){
	
	//a = 6; essendo per const reference non posso modificarlo ma solo i spezionarlo
	int c = a +3;
	
}
int main(){
	int a;
	double b = 5.5;
	
	std::vector<int> c {1,23};
	//std::cout<<c; perchè non fa stampare il vector?
	
	int somma = f(a,b);
	//std::cout<<somma<<std::endl;
	
	int array[3] = {0,1,2};
	int *p = &array[0];
	//int *p = &array[0];
	
	std::list<int> l = {1,2,3,4,5};
	
	for( auto i = l.begin(); i!=l.end() ; i++){
		
	}
	return 0;
}