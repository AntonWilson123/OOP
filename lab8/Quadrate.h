#ifndef QUADRATE_H
#define QUADRATE_H

//#include "Figure.h"
#include <cstdlib>
#include <iostream>

class Quadrate 
{
	private :
		size_t side_a;
		
	public :
		Quadrate();
		Quadrate(size_t i);
		Quadrate(const Quadrate& orig);
	//	Quadrate(std::istream &is);
	//	virtual void Print() override;
		double Square();
		~Quadrate();
		
		bool operator==(const Quadrate& other);
		bool operator<(Quadrate& other);
		bool operator>(Quadrate& other);
		bool operator<=(Quadrate& other);
		bool operator>=(Quadrate& other);

		//operator double () const;

		//friend const Quadrate operator+(const Quadrate& left,const Quadrate& right);
		//bool operator==(const Quadrate& other);

		friend std::ostream& operator<<(std::ostream &os, const Quadrate& obj);
		friend std::istream& operator>>(std::istream& is, Quadrate& obj);

		Quadrate& operator=(const Quadrate& right);

};

#endif
