#include<iostream>
#include<vector>

using namespace std;

class Rational 
{
    public:
    
    Rational(int x, int y);
    Rational(int x);
    Rational(double number);
    Rational(const Rational &number);
    Rational();
    Rational operator +(Rational &number);
    Rational operator +(const double &number);
    Rational operator -(const Rational &number);
    Rational operator -();
    Rational operator *(const Rational &number);
    Rational operator *(const double &number);
    Rational operator /(const Rational &number);
    bool operator ==(const Rational &number) const;
    bool operator ==(const double &number);
    bool operator <(Rational &number);
    bool operator >(const Rational &number);
    int operator[](int index);
    friend ostream& operator <<(ostream &output, const Rational &number);
    double floating()const;

    private:
    int denominator, numerator; 
    long long gcd(long long a, long long b);
    vector<int> decimalToFraction(double number);

}; 