#ifndef FRACTION_H
#define FRACTION_H

#include<iostream>

class Fraction{
    public:
    // 构造函数 初始化用
    Fraction(int nume = 0,int denom = 1) : numerator(nume),denominator(denom) {}
    
    // 输入输出重载
    friend std::ostream& operator<<(std::ostream &out,const Fraction &fraction);
    friend std::istream& operator>>(std::istream &in, Fraction &fraction);
    // 加减乘除重载
    friend Fraction operator+(const Fraction &leftFraction ,const Fraction &rightFraction);
    friend Fraction operator-(const Fraction &leftFraction ,const Fraction &rightFraction);
    friend Fraction operator*(const Fraction &leftFraction ,const Fraction &rightFraction);
    friend Fraction operator/(const Fraction &leftFraction ,const Fraction &rightFraction);
    // 关系运算符重载
    friend bool operator>(const Fraction &leftFraction ,const Fraction &rightFraction);
    friend bool operator<(const Fraction &leftFraction ,const Fraction &rightFraction);
    friend bool operator>=(const Fraction &leftFraction ,const Fraction &rightFraction);
    friend bool operator<=(const Fraction &leftFraction ,const Fraction &rightFraction);
    friend bool operator==(const Fraction &leftFraction ,const Fraction &rightFraction);
    friend bool operator!=(const Fraction &leftFraction ,const Fraction &rightFraction);
    // 取+、-一目运算符
    Fraction operator+();
    Fraction operator-();
    
    void setNumerator(int nume);
    void setDenominator(int denom);
    int getNumerator()  const;
    int getDenominator() const;
    // 化简 使得输入输出没有公因子
    void simplify();

    private:
        int numerator;
        int denominator;

};
#endif