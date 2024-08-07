#include <stdio.h>
#include "Coordinate.hpp"

int main(){
    //Creo due coppie di coordinate
    Coordinate a('A',7); 
    Coordinate b('A', 5);
    std::cout<<a<<" "<<b<<std::endl;
    
    std::vector<Coordinate> v;
    v = generate_inline_position(a,b);
    for(int i = 0; i < v.size(); i++) std::cout<<v[i]<<" ";
    std::cout<<std::endl;
    
    Coordinate c('C',7); 
    Coordinate d('A', 7);
    std::cout<<c<<" "<<d<<std::endl;
    
    std::vector<Coordinate> v1;
    v1 = generate_inline_position(c,d);
    for(int i = 0; i < v1.size(); i++) std::cout<<v1[i]<<" ";
    std::cout<<std::endl;
    
    Coordinate e('F',7); 
    Coordinate f('F', 7);
    std::cout<<e<<" "<<f<<std::endl;
    
    std::vector<Coordinate> v2;
    v2 = generate_inline_position(e,f);
    for(int i = 0; i < v2.size(); i++) std::cout<<v2[i]<<" ";
    std::cout<<std::endl;
    
    Coordinate g('F',7); 
    Coordinate h('c', 9);
    std::cout<<g<<" "<<h<<std::endl;
    
    std::vector<Coordinate> v3;
    v3 = generate_inline_position(g,h);
    for(int i = 0; i < v3.size(); i++) std::cout<<v3[i]<<" ";
    std::cout<<std::endl;
    std::cout<<v3.size()<<std::endl;
	
	
	Coordinate i('K',7); 
    Coordinate l('N',7);
    std::cout<<i<<" "<<l<<std::endl;
    
    std::vector<Coordinate> v4;
    v4 = generate_inline_position(i,l);
    for(int i = 0; i < v4.size(); i++) std::cout<<v4[i]<<" ";
    std::cout<<std::endl;
    
    
    if(a == b) std::cout<<"coordinata a e b sono uguali\n";
    else std::cout<<"coordinata a e b NON sono uguali\n";

    if(a != b) std::cout<<"coordinata a e b NON sono uguali\n";
    else std::cout<<"coordinata a e b sono uguali\n";
    

 return 0;
}
