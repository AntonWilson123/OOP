#include <iostream>
#include "Quadrate.h"

/*Quadrate::Quadrate(): side_a(0) {
}*/
Quadrate::Quadrate(){
//		is >> side_a;
		std::cout << "Фигура: квадрат\n";
		std::cout << "Введите сторону:" ;
		std::cin >> side_a; std::cout << "\n";
		if (side_a <= 0) { std::cout << "Неверные данные\n";
			std::cout << "Введите сторону:" ;
			std::cin >> side_a; std::cout << "\n";
	}
	
	std::cout << "Квадрат создан\n";
	
}

void Quadrate::Print(){
	std::cout << "Квадрат со стороной:" << side_a << "\n";
}	

double Quadrate::Square(){
	return (side_a * side_a);
}

Quadrate::~Quadrate() {
	std::cout << "Квадрат удален\n";
}
