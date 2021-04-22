#include<iostream>
#include<cmath>
#include<vector>
#include "Rational.h"

using namespace std;

Rational::Rational(int x, int y)
{
    numerator = x;
    denominator = y;
}

Rational::Rational(): numerator(1), denominator(1) {}

Rational::Rational(int x)
{
    numerator = x;
    denominator = 1;
}
Rational::Rational(double floatingNumber)
{
    vector<int> result = decimalToFraction(floatingNumber);
    numerator = result[0];
    denominator = result[1];
}

Rational::Rational(const Rational &number)
{
    numerator = number.numerator;
    denominator = number.denominator; 
}

double Rational::floating() const
{
    return static_cast<double>(numerator) / denominator;
}

Rational Rational::operator +(Rational &number)
{
    Rational temp;
    int deno = denominator * number.denominator;
    int num = numerator * number.denominator + number.numerator * denominator;
    int gcdVal = (int)gcd(deno, num);
    temp.denominator = deno / gcdVal;
    temp.numerator = num / gcdVal; 
    return temp;
}

Rational Rational::operator +(const double &number)
{
    vector<int> result = decimalToFraction(number); 
    Rational temp;
    int deno = denominator * result[1];
    int num = numerator * result[1] + result[0] * denominator;
    int gcdVal = (int)gcd(deno, num);
    temp.denominator = deno / gcdVal;
    temp.numerator = num / gcdVal;  
    return temp;
}

Rational Rational::operator -(const Rational &number)
{
    Rational temp;
    int deno = denominator * number.denominator;
    int num = numerator * number.denominator - number.numerator * denominator;
    int gcdVal = (int)gcd(deno, num);
    temp.denominator = deno / gcdVal;
    temp.numerator = num / gcdVal; 
    return temp;  
}
Rational Rational::operator *(const Rational &number) 
{
    Rational temp;
    int deno = denominator * number.denominator;
    int num = numerator * number.numerator;
    int gcdVal = gcd(deno, num);
    temp.numerator = num / gcdVal;
    temp.denominator = deno / gcdVal;
    return temp;
}

Rational Rational::operator *(const double &number)
{
    vector<int> result = decimalToFraction(number);
    Rational temp;
    int deno = denominator * result[1];
    int num = numerator * result[0];
    int gcdVal = gcd(deno, num);
    temp.numerator = num / gcdVal;
    temp.denominator = deno / gcdVal;
    return temp;

}

Rational Rational::operator /(const Rational &number)
{
    Rational temp;
    int num = numerator * number.denominator;
    int deno  = denominator * number.numerator;
    int gcdVal = gcd(deno, num);
    temp.numerator = num / gcdVal;
    temp.denominator = deno / gcdVal;
    return temp;
}

bool Rational::operator <(Rational &number)
{
     return ((static_cast<double>(numerator) / denominator) 
     - (static_cast<double>(number.numerator)  / number.denominator)) < 0;
}

bool Rational::operator >(const Rational &number)
{
  return ((static_cast<double>(numerator) / denominator) 
     - (static_cast<double>(number.numerator)  / number.denominator)) > 0;  
}

ostream& operator << (ostream &output, const Rational &number)
{
    if (number.denominator == 1) output << number.numerator;
    else output << number.numerator  << "/" << number.denominator;
    return output;
}

int Rational::operator[](int index)
{
    return index == 0 ? numerator : denominator;
}

bool Rational::operator ==(const Rational &number) const
{
    return numerator == number.numerator && denominator == number.denominator;
}

bool Rational::operator ==(const double &number)
{
    vector<int>result = decimalToFraction(number);
    return numerator == result[0] && denominator == result[1];
}

Rational Rational::operator-()
{
    return Rational( - 1 * numerator, denominator);
}

long long Rational::gcd(long long a, long long b)
{
    if (a == 0) return b;
    else if (b == 0) return a;
    return (a < b) ?  gcd(a, b % a) :  gcd(b, a % b);
}

vector<int> Rational::decimalToFraction(double number)
{
    double intVal = floor(number); ßß
    vector<int> result;

    double fVal = number - intVal;
    const long pVal = 1000000000;
 
    long long gcdVal = gcd(round(fVal * pVal), pVal);
 
    long long num = round(fVal * pVal) / gcdVal;
    long long deno = pVal / gcdVal;

    result.push_back((intVal * deno) + num);
    result.push_back(deno);
    return result;
}

