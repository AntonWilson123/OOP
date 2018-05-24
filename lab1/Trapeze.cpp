#include "Trapeze.h"
#include <iostream>

Trapeze::Trapeze() {
	std::cout << "Фигура: трапеция\n";
	std::cout << "Введите стороны основания и высоту\n";
	std::cin >> side_a >> side_b >> side_c; std::cout << "\n";
	if ( (side_a <= 0) || (side_b <= 0) || (side_c <= 0) ){
		std::cout << "Неверные данные\n" ;
		std::cout << "Фигура: трапеция\n";
		std::cout << "Введите стороны основания и высоту\n";
		std::cin >> side_a >> side_b >> side_c; std::cout << "\n";
}
	std::cout << "Трапеция создана\n";
}

void Trapeze::Print(){
	std::cout << "a=" << side_a << ", b=" << side_b << ", h=" << side_c << "\n";
}

double Trapeze::Square(){
	return (((side_a+side_b)/2)*side_c);
}

Trapeze::~Trapeze(){
	std::cout << "Трацеция удалена\n";
}
