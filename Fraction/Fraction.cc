#include "Fraction.hh"

Fraction::Fraction(int n, int d) : num(n), den(d){ // TODO: finish initializer list :

}

//friend
Fraction operator +(Fraction a, Fraction b) {
    return Fraction(a.num*b.den+b.num*a.den, a.den*b.den);
}

// member operator
Fraction Fraction::operator -(Fraction f) {
    return Fraction(num*f.den-f.num*den, den*f.den);
}

std::ostream& operator <<(std::ostream& s, Fraction b) {
    return s << b.num <<"/"<< b.den;
}

//just here for illustration, you do not have to do anything
void Fraction::simplify() {
}

