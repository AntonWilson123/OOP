#ifndef TRAPEZE_H
#define TRAPEZE_H

#include "Figure.h"

class Trapeze : public Figure
{
	private :
		int side_a, side_b, side_c;
	public :
		Trapeze();
		virtual void Print() override;
		virtual double Square() override;
		virtual ~Trapeze() override;
};

#endif
