#include <iostream>
#include <cstdlib>
#include "Quadrate.h"
#include "QQueue.h"
#include "QQueueItem.h"


	int main(int argc, char** argv){
/*
		Quadrate figure1 = Quadrate();
		Quadrate figure2 = Quadrate();
		Quadrate figure3 = Quadrate(0);
		figure1.Print();
		figure2.Print();
		figure3.Print();
		if (figure1 == figure2)
			std::cout << "Квадраты равны\n";
		else std::cout << "Квадраты не равны\n";
		//Figure *sum = figure1 + figure2;
		//sum = figure1 + figure2;
*/
		
		Quadrate figure1 = Quadrate(5);
		Quadrate figure2 = Quadrate(10);
		Quadrate figure3;

		figure3 = figure2;


		std::cout << "CHECKkeep: "<< figure3 << std::endl;


/*

		QQueue queue;
		


		queue.push(Quadrate(1));
		queue.push(Quadrate(3));
		queue.push(Quadrate(4));
		
		std::cout << queue;	
		std::cout << queue.pop();		
		std::cout << queue;
		queue.push(Quadrate(10));
		std::cout << queue;
		std::cout << queue.pop();
		
*/		
		return 0 ;
		
	}
