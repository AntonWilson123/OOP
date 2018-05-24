#include <iostream>
#include "Quadrate.h"
#include "Rectangle.h"
#include "Trapeze.h"

	using namespace std;
	int main(int argc, char** argv){
		Figure *figure1 = new Quadrate();
		figure1->Print();
		std::cout << "Площадь квадрата:" << figure1->Square() << "\n";
		delete figure1;
		std::cout << "______________________________\n\n";
		Figure *figure2 = new Rectangle();
		figure2->Print();
		std::cout << "Площадь прямоугольника:" << figure2->Square() << "\n";
		delete figure2;
		std::cout << "______________________________\n\n";
		Figure *figure3 = new Trapeze();
		figure3->Print();
		std::cout << "Площадь трапеции:" << figure3->Square() << "\n";
		delete figure3;
		std::cout << "______________________________\n\n";
		return 0; 
	
	}
