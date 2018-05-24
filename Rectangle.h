#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Figure.h"

class Rectangle : public Figure
{
	private :
		int side_a, side_b;
	public :
		Rectangle();
		virtual void Print() override;
		virtual double Square() override;
		virtual ~Rectangle() override;
};

#endif
