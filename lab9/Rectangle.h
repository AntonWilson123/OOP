#ifndef RECTANGLE_H
#define RECTANGLE_H

//#include "Figure.h"
#include <cstdlib>
#include <iostream>

class Rectangle
{
	private :
		size_t side_a,side_b;
		
	public :
		Rectangle();
		Rectangle(size_t i,size_t j);
		Rectangle(const Rectangle& orig);
	//	Quadrate(std::istream &is);
	//	virtual void Print() override;
		double Square();
		~Rectangle();
		
		bool operator==(const Rectangle& other);
		bool operator<(Rectangle& other);
		bool operator>(Rectangle& other);
		bool operator<=(Rectangle& other);
		bool operator>=(Rectangle& other);

		//operator double () const;

		//friend const Quadrate operator+(const Quadrate& left,const Quadrate& right);
	//	bool operator==(const Rectangle& left,const Rectangle& right);

		friend std::ostream& operator<<(std::ostream &os, const Rectangle& obj);
		friend std::istream& operator>>(std::istream& is, Rectangle& obj);
		
		Rectangle& operator=(const Rectangle& right);

};

#endif
