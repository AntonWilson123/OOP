#include <cstdlib>
#include <iostream>
#include <memory>

#include "Quadrate.h"
#include "Trapeze.h"
#include "Rectangle.h"

#include "QQueueItem.h"
#include "Queue.h"

int main(int argc, char** argv) {
	
	Queue queue;
	
	queue.push(std::shared_ptr<Quadrate>(new Quadrate(1)));
	queue.push(std::shared_ptr<Trapeze>(new Trapeze(2,3,4)));
	queue.push(std::shared_ptr<Rectangle>(new Rectangle(5,6)));
	
	std::cout << queue;
	
	queue.pop();
	queue.pop();
	
	std::cout << queue;
	queue.push(std::shared_ptr<Rectangle>(new Rectangle(99,99)));
	
	std::cout << queue;

	queue.pop();
	queue.pop();
	
	std::cout <<queue;

/*

	queue.push(std::shared_ptr<Trapeze>(new Trapeze(2,3,4)));
	queue.push(std::shared_ptr<Rectangle>(new Rectangle(5,6)));
	
	std::cout << queue;

	
	std::cout << queue.pop();
	std::cout << queue;	
	std::cout << queue.pop();		
	std::cout << queue;
	std::cout << queue;
	std::cout << queue.pop();
*/
	return 0;
}
