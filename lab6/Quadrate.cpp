#include <iostream>
#include "Quadrate.h"
//#include <cstdlib>

Quadrate::Quadrate() : side_a(0){
}


Quadrate::Quadrate(size_t i) : side_a(i) {
	std::cout << "Квадрат со стороной " << side_a << " создан\n" ;
}

Quadrate::Quadrate(const Quadrate& orig) {
	std::cout << "Quadrate copy created" << std::endl;
	side_a = orig.side_a;
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

Quadrate& Quadrate::operator=(const Quadrate& right){
		if (this == &right) return *this;
		std::cout << "Квадрат скопирован\n";
		side_a = right.side_a;
		return *this;
}

const Quadrate operator+(const Quadrate& left,const Quadrate& right){
	return Quadrate(left.side_a + right.side_a);
}

bool operator==(const Quadrate& left,const Quadrate& right){
	return (left.side_a == right.side_a);
}

std::ostream& operator<<(std::ostream &os,const Quadrate& obj) {
	os << "Квадрат со стороной:" << obj.side_a << "\n";
	return os; 
}
	
std::istream& operator>>(std::istream& is, Quadrate& obj) {
	is >> obj.side_a;
	return is; 
}
