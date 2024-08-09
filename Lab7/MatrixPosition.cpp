#include "MatrixPosition.hpp"

bool operator==(MatrixPosition a, MatrixPosition b){
 if(a.get_row() == b.get_row() && a.get_col() == b.get_col()) 
     return true;
 else return false;
}

bool operator!=(MatrixPosition a, MatrixPosition b){
 if(a.get_row() != b.get_row() || a.get_col() != b.get_col()) 
     return true;
 else return false;
}