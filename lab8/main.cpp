#include <cstdlib>
#include <iostream>
#include <memory>
#include <random>
#include "Quadrate.h"
#include "Trapeze.h"
#include "Rectangle.h"
#include "Quadrate.h"
#include "QQueueItem.h"
#include "Queue.h"

//#include "AllocationBlock.h"

int main(int argc, char** argv) {

	Queue<Quadrate> queue_quad;
	Queue<Rectangle> queue_rect;
	Queue<Trapeze> queue_trap;

	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(1,1000);

/*
	for (int i=0; i<10; i++){
		int side = distribution(generator);
		queue_quad.push(new Quadrate(side));
	}*/


	for (int i=0; i<10; i++){
		int side_a = distribution(generator);
		int side_b = distribution(generator);
		queue_rect.push(new Rectangle(side_a,side_b));
	}

/*
	for (int i=0; i<10; i++){
		int side = distribution(generator);
		queue_quad.push(new Quadrate(side));
	}
*/
	//std::cout << queue_quad;
	std::cout << queue_rect;
	//std::cout << queue_trap;
	std::cout << "Sort starting....\n";

	//queue_quad.sort();
//	queue_quad.sort_parallel();
	queue_rect.sort_parallel();
//	queue_trap.sort_parallel();
//	std::cout << queue_quad;
	std::cout << queue_rect;
//	std::cout << queue_trap;
	return 0;
}
