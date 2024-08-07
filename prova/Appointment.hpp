#ifndef APPOINTMENT_HPP
#define APPOINTMENT_HPP

#include <iostream>
class Appointment
{
public:
	Appointment(int d = 1, int h = 0, std::string s = "Normal");//Costruttore principale
	Appointment(const Appointment &a);//Costruttore di copia
	bool operator ==(Appointment a);//Overloading operatore == come function member
	friend std::ostream& operator<<(std::ostream& os, const Appointment& a);//Overloading operatore <<


private:

int day_;
int hour_;
std::string description_;
};

#endif // APPOINTMENT_HPP
