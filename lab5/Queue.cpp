#include <iostream>
#include "Queue.h"

template <class T> Queue<T>::Queue() : first(nullptr), last(nullptr) {
	}
	
template <class A> std::ostream& operator<<(std::ostream& os, const Queue<A>& queue) {
	std::shared_ptr<QQueueItem<A>> item = queue.first;
	if (item == nullptr) 
		std::cout << "ERROR: QUEUE IS EMPTY\n";
	while(item!=nullptr){
		os << *item; 
		item = item->GetNext();
	}
	return os;
}	

template <class T> void Queue<T>::push(std::shared_ptr<T> &&item){
	std::shared_ptr<QQueueItem<T>> other(new QQueueItem<T>(item));
	if (first == nullptr){
		first = other;
		last = other;
	}
	else{
			last->SetNext(other);
			last = other;
		}
	} 
	

template <class T> bool Queue<T>::empty() {
	return first == nullptr;
}

template <class T> void Queue<T>::pop() { 
	if (first != nullptr) {
		first = first->GetNext();
	}
	else 
		std::cout << " DELETE ERROR, QUEUE IS EMPTY\n ";
}

template <class T> void Queue<T>::top(){
	std::shared_ptr<QQueueItem<T>> figure = first; 
	std::cout << "Первый в очереди:" << *figure << "\n";
}

template <class T> Queue<T>::~Queue(){
}

template <class T> Iterator<QQueueItem<T>,T> Queue<T>::begin(){
	return Iterator<QQueueItem<T>,T>(first);
}
template <class T> Iterator<QQueueItem<T>,T> Queue<T>::end(){
		return Iterator<QQueueItem<T>,T>(nullptr);
}


#include "Quadrate.h"
template class Queue<Quadrate>;
template std::ostream& operator<<(std::ostream& os, const Queue<Quadrate>& queue);

#include "Trapeze.h"
template class Queue<Trapeze>;
template std::ostream& operator<<(std::ostream& os, const Queue<Trapeze>& queue);

#include "Rectangle.h"
template class Queue<Rectangle>;
template std::ostream& operator<<(std::ostream& os, const Queue<Rectangle>& queue);



 
