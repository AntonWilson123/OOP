#include <iostream>

#include "Queue.h"
#include "Quadrate.h"
#include "Trapeze.h"
#include "Rectangle.h"




Queue::Queue() : first(nullptr), last(nullptr) {
	}
	
std::ostream& operator<<(std::ostream& os, const Queue& queue) {
	std::shared_ptr<QQueueItem> item = queue.first;
	if (item == nullptr) 
		std::cout << "ERROR: QUEUE IS EMPTY\n";
	while(item!=nullptr){
		os << *item; 
		item = item->GetNext();
	}
	return os;
}	

void Queue::push(std::shared_ptr<Quadrate> &&quadrate) {
		std::shared_ptr<QQueueItem> other(new QQueueItem(quadrate));
		if (first == nullptr) {
		//std::cout << "CHECK CREATE2\n";
		//other->SetNext(first);
			first = other;
			last = other;
		} 
		else {
	//	std::cout << "CHECK CREATE3\n";
			last->SetNext(other);
			last = other;
		}
	}

void Queue::push(std::shared_ptr<Trapeze> &&trapeze) {
	std::shared_ptr<QQueueItem> other(new QQueueItem(trapeze));
		if (first == nullptr) {
		//std::cout << "CHECK CREATE2\n";
		//other->SetNext(first);
			first = other;
			last = other;
		} 
		else {
	//	std::cout << "CHECK CREATE3\n";
			last->SetNext(other);
			last = other;
		}
	}

void Queue::push(std::shared_ptr<Rectangle> &&rectangle) {
	std::shared_ptr<QQueueItem> other(new QQueueItem(rectangle));
		if (first == nullptr) {
		//std::cout << "CHECK CREATE2\n";
		//other->SetNext(first);
			first = other;
			last = other;
		} 
		else {
	//	std::cout << "CHECK CREATE3\n";
			last->SetNext(other);
			last = other;
		}
	}

bool Queue::empty() {
	return first == nullptr;
}

void Queue::pop() { // проблема удаления
	if (first != nullptr) {
		first = first->GetNext();
	}
	else 
		std::cout << " DELETE ERROR, QUEUE IS EMPTY\n ";
}

Queue::~Queue(){
}


 
