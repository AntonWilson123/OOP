#include "Rectangle.h"
#include <iostream>



Rectangle::Rectangle(){
	std::cout << "Фигура: прямоугольник\n";
	std::cout << "Введите стороны a и b\n";
	std::cin >> side_a;
	std::cin >> side_b; std::cout << "\n";
	if (side_a <=0 || side_b <=0){
		std::cout << "Неверные данные";
		std::cout << "Введите стороны a и b\n";
		std::cin >> side_a;
		std::cin >> side_b; std::cout << "\n";
	}
	std::cout << "Прямоугольник создан\n";
}

void Rectangle::Print() {
	std::cout << "a=" << side_a << ", b=" << side_b << "\n"; 
}

double Rectangle::Square(){
	return (side_a * side_b);
}

Rectangle::~Rectangle(){
	std::cout << "Прямоугольник удален\n";
}
