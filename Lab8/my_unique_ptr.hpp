#ifndef MY_UNIQUE_PTR_HPP
#define MY_UNIQUE_PTR_HPP


template <typename T>
class my_unique_ptr{ //Puntatore intelligente mascherato sottoforma di oggetto
     
 T* ptr_;
 
public:

  //Costruttore che accetta un puntatore
  explicit my_unique_ptr(T* ptr = nullptr) : ptr_(ptr) {}   

  //Distruttore che dealloca il puntatore
  ~my_unique_ptr() { delete ptr_; }         

  //Lo unique_ptr non consente l'uso del copy constructor e del copy assigment
  my_unique_ptr(const my_unique_ptr&) = delete;
  my_unique_ptr& operator=(const my_unique_ptr&) = delete;
  
  //Operatore di dereferenziamento e accesso a membro  
  T& operator*() const { return *ptr_; } //NOTA: come ritorniamo T quindi il tipo e non un oggetto di tipo T (<T>my_unique_ptr)
  T* operator->() const { return ptr_; } //Infatti noi vogliamo ritornare una dereference, ossia il valore dell oggetto, quindi se intero, voglio che mi dia 5
                                         //Oppure vogliamo che ci ritorni un puntatore di tipo T esempio intero ad uno specifico oggetto
  //Rilascia il possesso del puntatore
  T* Release() {      //Novità dell'essere puntatore intelligente, risolve problemi di memory leak e dangling pointer
    T* ptr = ptr_;    //aiuta il compilatore dunque in quanto gestisce automaticamente la deallocazione della memoria quando escono dallo scope
    ptr_ = nullptr;
    return ptr;
  }

  
};

#endif // MY_UNIQUE_PTR_H


/*
NOTE IMPORTANTI: 
 Fai presente la nota del fatto che se creavi una classe unique_ptr non mi lasciava compilare per un problema di linker
 con il seguente errore : C:/mingw64/bin/../lib/gcc/x86_64-w64-mingw32/8.1.0/../../../../x86_64-w64-mingw32/lib/../lib/libmingw32.a(lib64_libmingw32_a-crt0_c.o):crt0_c.c:(.text.startup+0x2e): undefined reference to `WinMain'
 Prova a capire come mai, hp dovuto rinominare il file in  my_unique_ptr
  * 
  * // Spiega a cosa serve explicit (In teoria obbliga ad invocare il costruttore in questo modo)
  * 
  * // Ripassa cosa fa delete
*/