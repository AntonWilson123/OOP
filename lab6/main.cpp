#include <cstdlib>
#include <iostream>
#include <memory>

#include "Quadrate.h"
#include "Trapeze.h"
#include "Rectangle.h"

#include "QQueueItem.h"
#include "Queue.h"

#include "AllocationBlock.h"


void TestQueue()
{
	Queue<Quadrate> queue_quad;
	queue_quad.push(std::shared_ptr<Quadrate>(new Quadrate(1)));
	queue_quad.push(std::shared_ptr<Quadrate>(new Quadrate(2)));
	queue_quad.push(std::shared_ptr<Quadrate>(new Quadrate(3)));
	queue_quad.push(std::shared_ptr<Quadrate>(new Quadrate(4)));
	for(auto i : queue_quad)
		std::cout << *i << "\n";
	while(!queue_quad.empty()) {
		queue_quad.top();
		queue_quad.pop();
	}
}

void TestAllocationBlock(){ 
	AllocationBlock allocator(sizeof(int),10);
	int *a1=nullptr;
	int *a2=nullptr;
	int *a3=nullptr;
	int *a4=nullptr;
	int *a5=nullptr;
	a1 = (int*)allocator.allocate();
	*a1 =1; 
	std::cout << "a1 pointer value:" << *a1 << "\n";
	a2 = (int*)allocator.allocate();
	*a2 =2;
	std::cout << "a2 pointer value:" << *a2 << "\n";
	a3 = (int*)allocator.allocate();
	*a3 =3; 
	std::cout << "a3 pointer value:" << *a3 << "\n";

	allocator.deallocate(a1);
	allocator.deallocate(a3);

	a4 = (int*)allocator.allocate();
	*a4 = 4;
	std::cout << "a4 pointer value: " << *a4 << "\n";
	a5 = (int*)allocator.allocate();
	*a5 = 5;
	std::cout << "a5 pointer value: " << *a5 << "\n";
	
	std::cout << "a1 pointer value:" << *a1 << "\n";
	std::cout << "a2 pointer value:" << *a2 << "\n";
	std::cout << "a3 pointer value:" << *a3 << "\n";

	allocator.deallocate(a2);
	allocator.deallocate(a4);
	allocator.deallocate(a5);
}


int main(int argc, char** argv) {
	
	TestAllocationBlock();
	TestQueue();

	return 0;
}
