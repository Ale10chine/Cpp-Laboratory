#include <iostream>
#include "Appointment.hpp"
class A{
	int a;
	public:
	A(int i){
		a = i;
	}
};

int main(){
	//Costruttore 
	Appointment app1 = Appointment(12,15,"Non era molto piacevole");
	//A a;
	A a = A(5);
	Appointment app5;// esiste sempre il costruttore di default
	//Output
	std::cout<<app1<<std::endl;

	//Costruttore di copia
	Appointment app2 = app1;
	std::cout<<app2<<std::endl;
	
	Appointment app3(12,15,"Veramente bello");
	std::cout<<app3<<std::endl;
	
	//Operatore ==
	if(app2 == app3) std::cout<<"Era lo stesso appuntamento"<<std::endl;
	else             std::cout<<"Erano appuntamenti diversi"<<std::endl;
	
	
	if(app1 == app2) std::cout<<"Era lo stesso appuntamento"<<std::endl;
	else             std::cout<<"Erano appuntamenti diversi"<<std::endl;

	return 0;
}