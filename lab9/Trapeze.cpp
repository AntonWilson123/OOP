#include "Trapeze.h"
#include <iostream>


Trapeze::Trapeze() : side_a(0),side_b(0),side_h(0){
}


Trapeze::Trapeze(size_t i,size_t j,size_t k) : side_a(i),side_b(j),side_h(k) {
//	std::cout << "Трапеция со сторонами " << side_a << "," << side_b << 
//		" и высотой " << side_h <<" создана\n" ;
}

Trapeze::Trapeze(const Trapeze& orig) {
//	std::cout << "Trapeze copy created" << std::endl;
	side_a = orig.side_a;
	side_b = orig.side_b;
	side_h = orig.side_h;
}

/*
void Trapeze::Print(){
	std::cout << "a=" << side_a << ", b=" << side_b << ", h=" << side_h << "\n";
}*/

double Trapeze::Square(){
	return (((side_a+side_b)/2)*side_h);
}

Trapeze::~Trapeze(){
//	std::cout << "Трацеция удалена\n";
}


Trapeze& Trapeze::operator=(const Trapeze& right){
		if (this == &right) return *this;
//		std::cout << "Трапеция скопирована\n";
		side_a = right.side_a;
		side_b = right.side_b;
		side_h = right.side_h;
		return *this;
}

bool Trapeze::operator==(const Trapeze& left){
	return ( (side_a == left.side_a) && (side_b == left.side_b) && (side_h == left.side_h));
}

bool Trapeze::operator>(Trapeze& other){
	return this->Square() > other.Square();
}

bool Trapeze::operator<(Trapeze& other){
	return this->Square() < other.Square();
}


bool Trapeze::operator>=(Trapeze& other){
	return this->Square() >= other.Square();
}

bool Trapeze::operator<=(Trapeze& other){
	return this->Square() <= other.Square();
}


std::ostream& operator<<(std::ostream &os,const Trapeze& obj) {
	os << "Трапеция со сторонами " << obj.side_a << "," << obj.side_b << 
		" и высотой " << obj.side_h << "\n";
	return os; 
}

