#include "Rectangle.h"
#include <iostream>


Rectangle::Rectangle() : side_a(0),side_b(0){
}


Rectangle::Rectangle(size_t i,size_t j) : side_a(i),side_b(j) {
	std::cout << "Прямоугольник со сторонами " << side_a << " и " << side_b << " создан\n" ;
}

Rectangle::Rectangle(const Rectangle& orig) {
	std::cout << "Rectangle copy created" << std::endl;
	side_a = orig.side_a;
	side_b = orig.side_b;
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

Rectangle& Rectangle::operator=(const Rectangle& right){
		if (this == &right) return *this;
		std::cout << "Прямоугольник скопирован\n";
		side_a = right.side_a;
		side_b = right.side_b;
		return *this;
}

std::ostream& operator<<(std::ostream &os,const Rectangle& obj) {
	os << "Прямоугольник со сторонами:" << obj.side_a << ", " << obj.side_b << "\n";
	return os; 
}
