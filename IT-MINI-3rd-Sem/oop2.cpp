/* |\     /|     @author: umgbhalla
   | )   ( |     date: 27 Aug 2021 
   | |   | |        
   | |   | |   
   | (___) |   
   (_______) 
   */
/* Create a Structure RationalNumber (fractions) with the following capabilities: 
 * a.Use integer variables to represent the data of the structure: numerator and denominator.  
 * b.Create a setdata member function that initializes the value of data members of structure variables if not passed then initialized defaultly.  
 * c.Create  a  member  function  that  adds  two  rational  number  (Structure  variables)  and  return  a resulting rational number(Structure variable). 
 * d.Create a member function that divides two rational number (Structure variables) and return a resulting rational number(Structure variable).. 
 * e.Printing Rational numbers in the form a/b, where a is the numerator and b is the denominator. */

#include<iostream>
#include<iomanip>
using namespace std;

struct RationalNumber {
  public :
    int numerator;
    int denominator;

    RationalNumber(int n = 0, int d  = 0) {
      numerator = n;
      denominator = d;
    }

    void setRationalNumber(int n, int d) {
      numerator = n;
      denominator = d;
    }

    RationalNumber addRationalNumber(RationalNumber a){
      RationalNumber t;

      t.numerator = a.numerator * denominator + a.denominator * numerator;
      t.denominator = a.denominator * denominator;
      t.reduction();
      return t;
    }
    RationalNumber subtractRationalNumber(RationalNumber s){
      RationalNumber t;

      t.numerator = s.denominator * numerator - denominator * s.numerator;
      t.denominator = s.denominator * denominator;
      t.reduction();

      return t;
    }

    RationalNumber multiplication( RationalNumber &m )
    {
      RationalNumber t;

      t.numerator = m.numerator * numerator;
      t.denominator = m.denominator * denominator;
      t.reduction();

      return t;
    }

    RationalNumber division( RationalNumber &v )
    {
      RationalNumber t;

      t.numerator = v.denominator * numerator;
      t.denominator = denominator * v.numerator;
      t.reduction();

      return t;
    }
    void reduction( void ) {
      int largest = numerator > denominator ? numerator : denominator;
      int gcd = 0; // greatest common divisor

      for ( int loop = 2; loop <= largest; ++loop )
        if ( numerator % loop == 0 && denominator % loop == 0 )
          gcd = loop;

      if (gcd != 0) {
        numerator /= gcd;
        denominator /= gcd;
      }
    };

    void print(){
      cout<<numerator<<"/"<<denominator<<"\n";
    }
};

int main() {
  RationalNumber t;
  t.print();
  RationalNumber v(88,7);
  v.print();
  v.addRationalNumber(t).print();
  t.division(v).print();
  return 0;
}
