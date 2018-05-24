#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Figure.h"
#include <cstdlib>
#include <iostream>

class Rectangle : public Figure
{
	private :
		size_t side_a, side_b;
	public :
		Rectangle();
		Rectangle(size_t i,size_t j);
		Rectangle(const Rectangle& orig);
		virtual void Print() override;
		virtual double Square() override;
		friend std::ostream& operator<<(std::ostream& os, const Rectangle& obj);
		Rectangle& operator=(const Rectangle& right);		
		virtual ~Rectangle() override;
};

#endif
