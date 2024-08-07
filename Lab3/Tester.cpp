#include <iostream>
#include <stdexcept>
#include "MyVector.cpp"

using std::cout;
using std::cerr;
using std::endl;

void func_test(const MyVector& v);

int main(void) {
    cout << "Costruttore default: v1" << endl;
    MyVector v1;
    v1.print_vector();

    cout << "Costruttore con initializer_list: v2" << endl;
    MyVector v2 = {0, 1.1, 3.45, 23.333};
    v2.print_vector();

    cout << "Costruttore di copia: MyVector v3 = v2" << endl;
    MyVector v3 = v2;
    v3.print_vector(); 

    cout << "Operatore [] in lettura:" << endl;
    cout << "v3[2] = " << v3[3] << endl;

    cout << "Operatore [] in scrittura:" << endl;
    v3[0] = 324.77;
    cout << "v3[0] = " << v3[0] << endl;

    cout << "Operatore [] da oggetto const:" << endl;
    func_test(v3);

    cout << "Operatore = : v1 = v3" << endl;
    v1 = v3;
    v1.print_vector();

    cout << "safe_set()" << endl;
    v2.safe_set(3, 4.545);
    cout << "v2[3] = " << v2[3] << endl;

    cout << "safe_set() fuori vettore" << endl;
    try { v2.safe_set(23123, 34); }
    catch (std::out_of_range e) { cerr << e.what() << endl; }

    cout << "safe_get()" << endl;
    int  val = v2.safe_get(0);
    cout << "v2[0] = " << val << endl;

    cout << "safe_get() fuori vettore" << endl;
    try { v2.safe_get(23123); }
    catch (std::out_of_range e) { cerr << e.what() << endl; }

    return 0;
}

void func_test(const MyVector& v) {
    cout << v[2] << endl;
}