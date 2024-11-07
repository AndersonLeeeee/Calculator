#ifndef CALCULATOR_H
#define CALCULATOR_H

#include<iostream>
#include<string>
#include<iomanip>
#include"Complex.h"
#include"Fraction.h"

class CalculatorAssistant{
    public:
    void showMenu();
    void fractionCompute();
    void complexCompute();
    void run();
    private:
        Complex complex;
        Fraction fraction;
};
#endif