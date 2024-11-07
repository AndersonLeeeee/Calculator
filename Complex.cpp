#include<iostream>
#include<iomanip>
#include"Complex.h"

void Complex::setRealPart(double real){
    realPart = real;
}
void Complex::setImaginaryPart(double imaginary){
    imaginaryPart = imaginary;
}
double Complex::getRealPart() const{
    return realPart;
}
double Complex::getImaginary() const{
    return imaginaryPart;
}

// 输出重载
std::ostream& operator<<(std::ostream &out,const Complex &complex){
    out << '(' << complex.realPart << ',' << complex.imaginaryPart << ')';
    return out;
}

// 输出重载
std::istream& operator>>(std::istream &in, Complex &complex){
    char leftBrackets;
    char rightBrackets;
    char comma;
    char tempChar;
    
    in >> leftBrackets >> complex.realPart >> comma >> complex.imaginaryPart >> rightBrackets;
    while(1){
        while((tempChar = getchar()) != '\n'){
            continue;
        }
        if((leftBrackets != '(') || (comma != ',') || (rightBrackets != ')')){
            std::cerr << "格式错误! 形如(m,n),请重新输入：" << std::endl;
            in.clear();
            in >> leftBrackets >> complex.realPart >> comma >> complex.imaginaryPart >> rightBrackets;
        }else{
            break;
        }
    }
    return in;
}

// 复数相加 (a + bi) + (c + di) = (a + c) + (b + d)i
Complex operator+(Complex &complex1, Complex &complex2){
    Complex complex;
    complex.realPart = complex1.realPart + complex2.realPart;
    complex.imaginaryPart = complex1.imaginaryPart + complex2.imaginaryPart;
    return complex;
}

Complex operator+(double &number1, Complex &complex2){
    Complex complex(number1,0);
    return complex + complex2;
}

Complex operator+(Complex &complex1, double &number2){
    Complex complex(number2,0);
    return complex1 + complex;
}

// 复数相减 (a + bi) - (c + di) = (a - c) + (b - d)i
Complex operator-(Complex &complex1, Complex &complex2){
    Complex complex;
    complex.realPart = complex1.realPart - complex2.realPart;
    complex.imaginaryPart = complex1.imaginaryPart - complex2.imaginaryPart;
    return complex;
}
Complex operator-(double &number1, Complex &complex2){
    Complex complex(number1,0);
    return complex - complex2;
}

Complex operator-(Complex &complex1, double &number2){
    Complex complex(number2,0);
    return complex1 - complex;
}

// 复数相乘 (a + bi) * (c + di) = (ac - bd) + (ad +bc)i
Complex operator*(Complex &complex1, Complex &complex2){
    Complex complex;
    complex.realPart = complex1.realPart * complex2.realPart
                        -complex1.imaginaryPart * complex2.imaginaryPart;
    complex.imaginaryPart = complex1.realPart * complex2.imaginaryPart 
                            +complex2.realPart * complex1.imaginaryPart;
    return complex;
}
Complex operator*(double &number1, Complex &complex2){
    Complex complex(number1,0);
    return complex * complex2;
}
Complex operator*(Complex &complex1, double &number2){
    Complex complex(number2,0);
    return complex * complex1;
}       

// 复数相除 (a + bi) / (c + di) = (ac + bd) / (c^2 + d^2) + (bc - ad) / (c^2 + d^2) i
Complex operator/(Complex &complex1, Complex &complex2){
    Complex complex;
    complex.realPart = (complex1.realPart * complex2.realPart 
                        + complex1.imaginaryPart * complex2.imaginaryPart)
                        /(complex2.realPart * complex2.realPart 
                        + complex2.imaginaryPart * complex2.imaginaryPart);

    complex.imaginaryPart = (complex1.imaginaryPart * complex2.realPart 
                        - complex1.realPart * complex2.imaginaryPart)
                        /(complex2.realPart * complex2.realPart 
                        + complex2.imaginaryPart * complex2.imaginaryPart);
    return complex;
}
Complex operator/(double &number1, Complex &complex2){
    Complex complex(number1,0);
    return complex / complex2;
}
Complex operator/(Complex &complex1, double &number2)  {
    Complex complex(number2,0);
    return complex1 / complex;
}

// display 函数
void Complex::display(){
    std::cout << "(" << realPart << "," << imaginaryPart << "i)" << std::endl;
}