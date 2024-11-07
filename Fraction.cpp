#include<iostream>
#include<iomanip>
#include"Fraction.h"

void Fraction::setNumerator(int nume){
    numerator = (nume == 0) ? 0 : nume;
}
void Fraction::setDenominator(int denom){
    if(denom == 0){
        std::cerr<<"分母不能为零！"<<std::endl;
    }
    denominator = (denominator != 0) ? denominator : NULL;
}
int Fraction::getNumerator()  const{
    return numerator;
}
int Fraction::getDenominator() const{
    return denominator;
}
void Fraction::simplify(){
    int a = numerator;
    int b = denominator;
    // 求 gcd
    while(b){
        int temp = b;
        b = a % b;
        a = temp;
    }
    // 靠gcd化简分子分母
    numerator /= a;
    denominator /= a;
    // 负号放分子上
    if(denominator < 0){
        denominator = -denominator;
        numerator = -numerator;
    }
}

// 输入输出重载
std::ostream& operator<<(std::ostream &out, const Fraction &fraction){
    out << fraction.numerator << '/' << fraction.denominator;
    return out;
}

std::istream& operator>>(std::istream &in, Fraction &fraction){
    char ch;
    char tempChar;
    in >> fraction.numerator >> ch >> fraction.denominator;
    while(1){
        while((tempChar = getchar()) != '\n'){
            continue;
        }
        if(fraction.denominator == 0){
            std::cerr<<"分母为零！请重新输入:"<<std::endl;
            in.clear();
            in >> fraction.numerator >> ch >> fraction.denominator;
        }else if(ch != '/'){
            std::cout<<"格式输入错误！(形如m/n) 请重新输入: " << std::endl;
            in.clear();
            in >> fraction.numerator >> ch >> fraction.denominator;
        }else{
            break;
        }
    }
    return in;
}

// 四则运算重载
// 加法
Fraction operator+(const Fraction &leftFraction, const Fraction &rightFraction){
    Fraction fraction;
    fraction.numerator = leftFraction.numerator * rightFraction.denominator + 
                            rightFraction.numerator * leftFraction.denominator;
    fraction.denominator = leftFraction.denominator * rightFraction.denominator;
    fraction.simplify();
    return fraction;
}
// 减法
Fraction operator-(const Fraction &leftFraction, const Fraction &rightFraction){
    Fraction fraction;
    fraction.numerator = leftFraction.numerator * rightFraction.denominator
                         - rightFraction.numerator * leftFraction.denominator;
    fraction.denominator = leftFraction.denominator * rightFraction.denominator;
    fraction.simplify();
    return fraction;
}
// 乘法
Fraction operator*(const Fraction &leftFraction, const Fraction &rightFraction){
    Fraction fraction;
    fraction.numerator = leftFraction.numerator * rightFraction.numerator;
    fraction.denominator = leftFraction.denominator * rightFraction.denominator;
    fraction.simplify();
    return fraction;
}
// 除法
Fraction operator/(const Fraction &leftFraction, const Fraction &rightFraction){
    Fraction fraction;
    fraction.numerator = leftFraction.numerator * rightFraction.denominator;
    fraction.denominator = leftFraction.denominator * rightFraction.numerator;
    fraction.simplify();
    return fraction;
}


// 取正重载
Fraction Fraction::operator+(){
    simplify();
    if(numerator < 0){
        numerator = -numerator;
    }
    return *this;
}

// 取负重载
Fraction Fraction::operator-(){
    simplify();
    numerator = -numerator;
    return *this;
}

// 大于号重载
bool operator>(const Fraction &leftFraction, const Fraction &rightFraction){
    int leftNumerator = leftFraction.numerator * rightFraction.denominator;
    int rightNumerator = rightFraction.numerator * leftFraction.denominator;
    int commonDenominator = leftFraction.denominator * rightFraction.denominator;
    if((leftNumerator - rightNumerator) * commonDenominator > 0){
        return true;
    }else{
        return false;
    }
}

// 小于号重载
bool operator<(const Fraction &leftFraction, const Fraction &rightFraction){
    int leftNumerator = leftFraction.numerator * rightFraction.denominator;
    int rightNumerator = rightFraction.numerator * leftFraction.denominator;
    int commonDenominator = leftFraction.denominator * rightFraction.denominator;
    if((leftNumerator - rightNumerator) * commonDenominator < 0){
        return true;
    }else{
        return false;
    }
}

// 等于号重载
bool operator==(const Fraction &leftFraction, const Fraction &rightFraction){
    return (leftFraction.numerator == rightFraction.numerator 
    && leftFraction.denominator == rightFraction.denominator);
}

// 不等于号重载
bool operator!=(const Fraction &leftFraction, const Fraction &rightFraction){
    return !(leftFraction == rightFraction);
}

// 大于等于重载
bool operator>=(const Fraction &leftFraction, const Fraction &rightFraction){
    if(leftFraction < rightFraction){
        return false;
    }else{
        return true;
    }
}

// 小于等于号重载
bool operator<=(const Fraction &leftFraction, const Fraction &rightFraction){
    if(leftFraction > rightFraction){
        return false;
    }else{
        return true;
    }
}














