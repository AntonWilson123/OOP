#ifndef TRAPEZE_H
#define TRAPEZE_H

//#include "Figure.h"
#include <cstdlib>
#include <iostream>

class Trapeze
{
	private :
		size_t side_a, side_b, side_h;
	public :
		Trapeze();
		Trapeze(size_t i,size_t j,size_t k);
		Trapeze(const Trapeze& orig);
		//virtual void Print() override;
		double Square();
		friend std::ostream& operator<<(std::ostream& os, const Trapeze& obj);
		Trapeze& operator=(const Trapeze& right);


		bool operator==(const Trapeze& other);
		bool operator<(Trapeze& other);
		bool operator>(Trapeze& other);
		bool operator<=(Trapeze& other);
		bool operator>=(Trapeze& other);

		//bool operator==(const Trapeeze& left,const Trapeeze& right);
		
		
		~Trapeze();
};

#endif
