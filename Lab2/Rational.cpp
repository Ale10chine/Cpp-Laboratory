#include "Rational.hpp"

// Constructors
Rational::Rational()
{
    num = 0;
    den = 1;
}

Rational::Rational(int n)
{
    num = n;
    den = 1;
}

Rational::Rational(int n, int d)
{
    num = n;
    den = d;
}

Rational::Rational(int n1, int n2, int d1, int d2)
{
    num = n1 * n2;
    den = d1 * d2;
}

// NON modifying functions
int Rational::getNumerator() const { return num; } // implementabile solitamente dentro la classe

int Rational::getDenominator() const { return den; } // NOTA BENE IL const

double Rational::object_doubleconv() const
{                                                          // mi restituisce l'oggetto Rational in un valore numerico double
    double result = (double)this->num / (double)this->den; // tale per cui è possibile effettuare un confronto
    return result;
}

// modifying functions
void Rational::SetRational(int n, int d)
{
    num = n;
    den = d;
}

// MEMBER FUNCTION
Rational Rational::Add(const Rational &r)
{ // o la faccio int e restituisco una somma, o la faccio con un generics e restituisco un oggetto
  // oppure faccio l'overloading dell'operatore +
    int d = mcm_calculator(this->den, r.den);
    int dx = this->num * (d / this->den);
    int sx = r.num * (d / r.den);
    // Rational result = Rational(dx+sx,d);  //senza semplificazioni
    Rational result = semplify_function(dx + sx, d);
    return result;
}

Rational Rational::Subs(const Rational &r)
{

    int d = mcm_calculator(this->den, r.den);
    int dx = this->num * (d / this->den);
    int sx = r.num * (d / r.den);
    // Rational result = Rational(dx-sx,d);   //senza semplificazioni
    Rational result = semplify_function(dx - sx, d);
    return result;
}

Rational Rational::Mul(const Rational &r)
{

    int n = this->num * r.num;
    int d = this->den * r.den;
    Rational result = semplify_function(n, d);
    return result;
}

Rational Rational::Div(const Rational &r)
{

    int n = this->num * r.den;
    int d = this->den * r.num;
    Rational result = semplify_function(n, d);
    return result;
}

// Overloading degli operatori come Member function
bool Rational::operator==(const Rational &r)
{
    if (this->num == r.getNumerator())
    {
        if (this->den == r.getDenominator())
        {
            return true;
        }
    }
    return false;
}
bool Rational::operator>(const Rational &r)
{
    if ((this->object_doubleconv()) > (r.object_doubleconv()))
        return true;
    else
        return false;
}
bool Rational::operator<(const Rational &r)
{
    if ((this->object_doubleconv()) < (r.object_doubleconv()))
        return true;
    else
        return false;
}
Rational Rational::operator+(const Rational &r)
{
    int d = mcm_calculator(this->den, r.den);
    int dx = this->num * (d / this->den);
    int sx = r.num * (d / r.den);
    // Rational result = Rational(dx+sx,d);  //senza semplificazioni
    Rational result = semplify_function(dx + sx, d);
    return result;
}

Rational Rational::operator+(int c)
{
    int dx = this->num;
    int sx = c * this->den;
    int d = this->den;
    Rational result = semplify_function(dx + sx, d);
    return result;
}

Rational Rational::operator-(const Rational &r)
{
    int d = mcm_calculator(this->den, r.den);
    int dx = this->num * (d / this->den);
    int sx = r.num * (d / r.den);
    // Rational result = Rational(dx-sx,d);   //senza semlificazioni
    Rational result = semplify_function(dx - sx, d);
    return result;
}

Rational Rational::operator*(const Rational &r)
{
    int n = this->num * r.num;
    int d = this->den * r.den;
    Rational result = semplify_function(n, d);
    return result;
}

Rational Rational::operator/(const Rational &r)
{
    int n = this->num * r.den;
    int d = this->den * r.num;
    Rational result = semplify_function(n, d);
    return result;
}

// HELPER FUNCTION
std::ostream &operator<<(std::ostream &os, Rational &r)
{
    return os << r.getNumerator() << "/" << r.getDenominator();
}
/*bool Rational::operator<<(const Rational& r){

         return true;
}*/
/*
bool operator==(const Rational& a , const Rational& b){
         if(a.getNumerator() == b.getNumerator()){
            if(a.getNumerator() == b.getDenominator()){
                 return true;
                 }
              }
          return false;
}
bool operator>(const Rational& a, const Rational& b){
         if((a.object_doubleconv())>(b.object_doubleconv()))
            return true;
         else return false;
}
bool operator<(const Rational& a, const Rational& b){
         if((a.object_doubleconv())<(b.object_doubleconv()))
            return true;
         else return false;
}
Rational operator+(const Rational& a, const Rational& b){
        int d = mcm_calculator(a.getDenominator(), b.getDenominator());
        int dx = a.getNumerator()*(d/a.getDenominator());
        int sx = b.getNumerator()*(d/b.getDenominator());
        //Rational result = Rational(dx+sx,d);  //senza semplificazioni
        Rational result = semplify_function(dx+sx,d);
        return result;
}

Rational operator+(const Rational& a, int c){
        int dx = a.getNumerator();
        int sx = c*a.getDenominator();
        int d = a.getDenominator();
        Rational result = semplify_function(dx + sx, d);
        return result;
}

Rational operator-(const Rational& a, const Rational& b){
        int d = mcm_calculator(a.getDenominator(), b.getDenominator());
        int dx = a.getNumerator()*(d/a.getDenominator());
        int sx = b.getNumerator()*(d/b.getDenominator());
        //Rational result = Rational(dx-sx,d);   //senza semlificazioni
        Rational result = semplify_function(dx-sx,d);
        return result;
}

Rational operator*(const Rational& a, const Rational& b){
        int n  = a.getNumerator()*b.getNumerator();
        int d  = a.getDenominator()*b.getDenominator();
        Rational result = semplify_function(n , d);
        return result;
}

Rational operator/(const Rational& a, const Rational& b){
        int n  = a.getNumerator()*b.getDenominator();
        int d  = a.getDenominator()*b.getNumerator();
        Rational result = semplify_function(n , d);
        return result;
}
*/

int mcm_calculator(int a, int b)
{ // Funzione che mi calcola l'mc tra due numeri
    int mcm = a * b;
    for (int i = mcm; i > 0; i--)
    {
        if (i % a == 0 and i % b == 0)
            mcm = i;
    }
    return mcm;
}
Rational semplify_function(int n, int d)
{ // Funzione che semplifica le frazioni

    if (n >= d)
    {
        for (int i = d; i > 1; i--)
        {
            if (n % i == 0)
            {
                if (d % i == 0)
                {
                    n = n / i;
                    d = d / i;
                }
            }
        }
    }
    else
    {
        for (int i = n; i > 1; i--)
        {
            if (d % i == 0)
            {
                if (n % i == 0)
                {
                    n = n / i;
                    d = d / i;
                }
            }
        }
    }
    Rational semplify = Rational(n, d);
    return semplify;
}