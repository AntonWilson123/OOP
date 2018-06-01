#ifndef TRAPEZE_H
#define TRAPEZE_H

#include "Figure.h"
#include <cstdlib>
#include <iostream>

class Trapeze : public Figure
{
	private :
		size_t side_a, side_b, side_h;
	public :
		Trapeze();
		Trapeze(size_t i,size_t j,size_t k);
		Trapeze(const Trapeze& orig);
		virtual void Print() override;
		virtual double Square() override;
		friend std::ostream& operator<<(std::ostream& os, const Trapeze& obj);
		Trapeze& operator=(const Trapeze& right);
		
		
		virtual ~Trapeze() override;
};

#endif
