#include<iostream>
#include<string>
#include "CalculatorAssistant.h"
void CalculatorAssistant::showMenu(){
    std::cout<<"                         "<<std::endl;
    std::cout<<"-------------------------"<<std::endl;
    std::cout<<"          MENU           "<<std::endl;
    std::cout<<"       [1] 分数计算       "<<std::endl;
    std::cout<<"       [2] 复数计算       "<<std::endl;
    std::cout<<"       [0] 退出系统       "<<std::endl;
    std::cout<<"-------------------------"<<std::endl;
    std::cout<<"                         "<<std::endl;
    std::cout<<"请输入您的选择[0-2]:      "<<std::endl;
}

void CalculatorAssistant::run(){
    int chooseItem;
    char ch;
    while(true){
        showMenu();
        std::cin>>chooseItem;
        switch(chooseItem){
            case 0:
                return;
            case 1:
                fractionCompute();
                continue;
            case 2:
                complexCompute();
                continue;
            default:
                while((ch = getchar()) != '\n'){
                    continue;
                }
                std::cout<<"您的输入有误!请重新输入您的选择:"<<std::endl;
                std::cin.clear();
                std::cin>>chooseItem;
        }
    }
}

void CalculatorAssistant::fractionCompute(){
    Fraction fraction1;
    Fraction fraction2;
    std::cout<<"                         "<<std::endl;
    std::cout<<"-------------------------"<<std::endl;
    std::cout<<"         分数计算         "<<std::endl;
    std::cout<<"                         "<<std::endl;
    std::cout<<"请输入两个分数[格式如 1/4]:"<<std::endl;
    std::cin>>fraction1>>fraction2;
    std::cout<<"分数1 : "<< fraction1 << std::endl << "分数2 : "<< fraction2 << std::endl;
    std::cout<<"分数1 + 分数2 = "<< fraction1 + fraction2 << std::endl;
    std::cout<<"分数1 - 分数2 = "<< fraction1 - fraction2 << std::endl;
    std::cout<<"分数1 * 分数2 = "<< fraction1 * fraction2 << std::endl;
    std::cout<<"分数1 / 分数2 = "<< fraction1 / fraction2 << std::endl;
    std::cout<<"正分数 1 = "<< +fraction1 << std::endl;
    std::cout<<"负分数 1 = "<< -fraction1 << std::endl;
    std::cout<<"正分数 2 = "<< +fraction2 << std::endl;
    std::cout<<"负分数 2 = "<< -fraction2 << std::endl;
    std::cout<<"分数1 > 分数2 吗？(1-是 0-否)"<< (fraction1 > fraction2) << std::endl;
    std::cout<<"分数1 < 分数2 吗？(1-是 0-否)"<< (fraction1 < fraction2) << std::endl;
    std::cout<<"分数1 >= 分数2 吗？(1-是 0-否)"<< (fraction1 >= fraction2) << std::endl;
    std::cout<<"分数1 <= 分数2 吗？(1-是 0-否)"<< (fraction1 <= fraction2) << std::endl;
    std::cout<<"分数1 == 分数2 吗？(1-是 0-否)"<< (fraction1 == fraction2) << std::endl;
    std::cout<<"分数1 != 分数2 吗？(1-是 0-否)"<< (fraction1 != fraction2) << std::endl;
}

void CalculatorAssistant::complexCompute(){
    Complex complex1;
    Complex complex2;
    std::cout<<"                         "<<std::endl;
    std::cout<<"-------------------------"<<std::endl;
    std::cout<<"         复数计算         "<<std::endl;
    std::cout<<"                         "<<std::endl;
    std::cout<<"请输入两个分数[格式如 (1,4)]:"<<std::endl;
    std::cin>>complex1>>complex2;
    std::cout<<"分数1 : "<< complex1 << std::endl << "分数2 : "<< complex2 << std::endl;
    std::cout<<"分数1 + 分数2 = "<< complex1 + complex2 << std::endl;
    std::cout<<"分数1 - 分数2 = "<< complex1 - complex2 << std::endl;
    std::cout<<"分数1 * 分数2 = "<< complex1 * complex2 << std::endl;
    std::cout<<"分数1 / 分数2 = "<< complex1 / complex2 << std::endl;
}



