#ifndef QUADRATE_H
#define QUADRATE_H

#include "Figure.h"
#include <cstdlib>
#include <iostream>

class Quadrate : public Figure
{
	private :
		size_t side_a;	
	public :
		Quadrate();
		Quadrate(size_t i);
		Quadrate(const Quadrate& orig);
	//	Quadrate(std::istream &is);
		virtual void Print() override;
		virtual double Square() override;
		virtual ~Quadrate() override;
		
		friend const Quadrate operator+(const Quadrate& left,const Quadrate& right);
		friend bool operator==(const Quadrate& left,const Quadrate& right);

		friend std::ostream& operator<<(std::ostream &os, const Quadrate& obj);
		friend std::istream& operator>>(std::istream& is, Quadrate& obj);

		Quadrate& operator=(const Quadrate& right);

};

#endif
