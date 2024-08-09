#include "Appointment.hpp"

Appointment::Appointment(int d , int h , std::string s) //Implementato come init list
	:  day_{d}, hour_{h}, description_{s} {}

Appointment:: Appointment(const Appointment& a){
	this->day_ =  a.day_;
	this->hour_ = a.hour_;
	this->description_ = a.description_;
	
}
bool Appointment::operator ==(Appointment a){
	return (this->day_ == a.day_ && this->hour_ == a.hour_ && this->description_ == a.description_);
}
std::ostream& operator<<(std::ostream& os, const Appointment& a){
	
	os<<"l'appuntamento e' cosi' strutturato:"<<std::endl;
	os<<"Data: "<<a.day_<<std::endl;
	os<<"Ora: "<<a.hour_<<std::endl;
	os<<"Descrizione appuntamento: "<<a.description_<<std::endl;
	
	return os;
}


