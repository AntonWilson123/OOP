#ifndef QUADRATE_H
#define QUADRATE_H

#include "Figure.h"
class Quadrate : public Figure
{
	private :
		int side_a;
	public :
		Quadrate();
	//	Quadrate(std::istream &is);
		virtual void Print() override;
		virtual double Square() override;
		virtual ~Quadrate() override;
};

#endif
