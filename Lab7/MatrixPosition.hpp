#ifndef MATRIXPOSITION_HPP
#define MATRIXPOSITION_HPP

class MatrixPosition{
     
     int row_;
     int col_;
     
public:
     //Default constructor
     MatrixPosition( int i = 0 , int j = 0 ) : row_{i} , col_{j} {}
     //Mod function
     void set_row(int r){ row_ = r;}
     void set_col(int c){ col_ = c;}
     //NON mod function
     int get_row()const{ return row_;} //Mi restituisce la riga
     int get_col()const{ return col_;} // Mi restituisce la colonna 
     //Destructor
     ~MatrixPosition() =  default;

};
//Helper function
 bool operator==(MatrixPosition a, MatrixPosition b);
 bool operator!=(MatrixPosition a, MatrixPosition b);
#endif // MATRIXPOSITION_HPP


/*
NOTE IMPORTANTI:
 * Il senso di progettare questa MatrixPosition è di tenere in considerazione la posizione
 questo mi serve perchè le funzioni che ritornano la posizione non possono returnare due valori, quindi mi ritornano un oggetto
 che memorizza posizione bidimensionalmente, con questo oggetto io sono in grado di fare confronti se sono == o !=
 oppure accedere a i e j tramite i get

*/