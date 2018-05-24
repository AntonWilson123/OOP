#include <cstdlib>
#include <iostream>
#include <memory>

#include "Quadrate.h"
#include "Trapeze.h"
#include "Rectangle.h"

#include "QQueueItem.h"
#include "Queue.h"

int main(int argc, char** argv) {
	
	Queue<Quadrate> queue_quad;
	
	queue_quad.push(std::shared_ptr<Quadrate>(new Quadrate(1)));
	queue_quad.push(std::shared_ptr<Quadrate>(new Quadrate(2)));
	queue_quad.push(std::shared_ptr<Quadrate>(new Quadrate(999)));
	
	std::cout << queue_quad;
	queue_quad.pop();
	queue_quad.top();
	
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	
	Queue<Trapeze> queue_trap;
	
	queue_trap.push(std::shared_ptr<Trapeze>(new Trapeze(1,2,3)));
	queue_trap.push(std::shared_ptr<Trapeze>(new Trapeze(10,20,30)));
	queue_trap.push(std::shared_ptr<Trapeze>(new Trapeze(999,999,999)));
	
	std::cout << queue_trap;
	queue_trap.pop();
	queue_trap.top();
	
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	
	Queue<Rectangle> queue_rekt;
	
	queue_rekt.push(std::shared_ptr<Rectangle>(new Rectangle(11,22)));
	queue_rekt.push(std::shared_ptr<Rectangle>(new Rectangle(23,32)));
	queue_rekt.push(std::shared_ptr<Rectangle>(new Rectangle(666,999)));
	
	std::cout << queue_rekt;
	queue_rekt.pop();
	queue_rekt.top();
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	
	
	
	
	
	return 0;
}
