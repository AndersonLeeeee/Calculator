#ifndef COMPLEX_H
#define COMPLEX_H


class Complex{
    public:
    Complex(){
        realPart = 0;
        imaginaryPart = 0;
    }
    Complex(double real, double imaginary){
        realPart = real;
        imaginaryPart = imaginary;
    }
    // 输入输出重载
    friend std::ostream& operator<<(std::ostream &out, const Complex &complex);
    friend std::istream& operator>>(std::istream &out, Complex &complex);
    // 四则运算函数声明
    friend Complex operator+(Complex &complex1, Complex &complex2);
    friend Complex operator+(double &number1, Complex &complex2);
    friend Complex operator+(Complex &complex1, double &number2);

    friend Complex operator-(Complex &complex1, Complex &complex2);
    friend Complex operator-(double &number1, Complex &complex2);
    friend Complex operator-(Complex &complex1, double &number2);

    friend Complex operator*(Complex &complex1, Complex &complex2);
    friend Complex operator*(double &number1, Complex &complex2);
    friend Complex operator*(Complex &complex1, double &number2);

    friend Complex operator/(Complex &complex1, Complex &complex2);
    friend Complex operator/(double &number1, Complex &complex2);
    friend Complex operator/(Complex &complex1, double &number2);

    void display();
    double getImaginary() const;
    double getRealPart() const;
    void setImaginaryPart(double imaginary);
    void setRealPart(double real);
    
    private:
        double realPart;
        double imaginaryPart;
};

#endif