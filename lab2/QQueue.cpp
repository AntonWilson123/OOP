#include <iostream>

#include "Quadrate.h"
#include "QQueue.h"
// разобраться с конструктором 
QQueue::QQueue() : first(nullptr), last(nullptr) {
}

QQueue::QQueue(const QQueue& orig) {
	first = orig.first;
	last = orig.last;
}
std::ostream& operator<<(std::ostream& os, const QQueue& queue) {
	QQueueItem *item = queue.first;
	while(item!=nullptr){
		os << *item;
		item = item->GetNext();
	}
	return os;
}

void QQueue::push(Quadrate &&quadrate) {
	QQueueItem *other = new QQueueItem(quadrate);
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

bool QQueue::empty() {
	return first == last;
}

Quadrate QQueue::pop() {
	Quadrate result;
	if (first != nullptr) {
//		std::cout << "CHECK123123\n";
		QQueueItem *old_first = first;
		first = first->GetNext();
		result = old_first->GetQuadrate();
		//old_first->SetNext(nullptr);
		delete old_first;
	}
	return result;
}

QQueue::~QQueue(){
	if (first == last){/*std::cout << "CHECK DELETE1\n";*/ delete first;}
	else{
		//std::cout << "CHECK DELETE2\n";
		delete first;
	}
	
}
 
