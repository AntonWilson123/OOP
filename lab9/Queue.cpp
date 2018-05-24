#include <iostream>
#include "Queue.h"
#include <exception>

template <class T> Queue<T>::Queue() : first(nullptr), last(nullptr) {
	}
	
template <class T> std::shared_ptr<T> Queue<T>::operator[](size_t i){
	std::lock_guard<std::recursive_mutex> lock(queue_mutex);
	if (i > size() - 1)
		throw
			std::invalid_argument("index greater then queue size");
	size_t j=0;

	for (std::shared_ptr<T>  a: *this){
		if (j==i) return a;
		j++;
	}

	return std::shared_ptr<T>(nullptr);

}


template <class T> std::ostream& operator<<(std::ostream& os, const Queue<T>& queue) {
	std::shared_ptr<QQueueItem<T>> item = queue.first;
	if (item == nullptr) 
		std::cout << "ERROR: QUEUE IS EMPTY\n";
	while(item!=nullptr){
		os << *item; 
		item = item->GetNext();
	}
	return os;
}	

template <class T> void Queue<T>::push(T *item){
	std::lock_guard<std::recursive_mutex> lock(queue_mutex);
	std::shared_ptr<QQueueItem<T>> other(new QQueueItem<T>(item,&queue_mutex));
	if (first == nullptr){
		first = other;
		last = other;
	}
	else{
			last->SetNext(other);
			last = other;
		}
	} 

template <class T> void Queue<T>::push(std::shared_ptr<T> item){
	std::lock_guard<std::recursive_mutex> lock(queue_mutex);
	std::shared_ptr<QQueueItem<T>> other(new QQueueItem<T>(item,&queue_mutex));
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
	std::lock_guard<std::recursive_mutex> lock(queue_mutex);
	return first == nullptr;
}

template <class T> std::shared_ptr<T> Queue<T>::pop() { 
	std::lock_guard<std::recursive_mutex> lock(queue_mutex);
	std::shared_ptr<T> result;
	if (first != nullptr) {
		result = first->GetObject();
		first = first->GetNext();
		return result;
	}
	else 
		std::cout << " DELETE ERROR, QUEUE IS EMPTY\n ";
}
template <class T> size_t Queue<T>::size(){
	std::lock_guard<std::recursive_mutex> lock(queue_mutex);
	int result = 0;
	for (auto i : *this)
		result ++;
	return result;
}



/*
template <class T> void Queue<T>::top(){
	std::shared_ptr<QQueueItem<T>> figure = first; 
	std::cout << "Первый в очереди:" << *figure << "\n";
}*/

template <class T> Queue<T>::~Queue(){
}

template <class T> Iterator<QQueueItem<T>,T> Queue<T>::begin(){
	return Iterator<QQueueItem<T>,T>(first);
}
template <class T> Iterator<QQueueItem<T>,T> Queue<T>::end(){
		return Iterator<QQueueItem<T>,T>(nullptr);
}

#include <functional>
template class Queue<std::function<void(void)>>;
#include "Quadrate.h"
template class Queue<Quadrate>;
template std::ostream& operator<<(std::ostream& os, const Queue<Quadrate>& queue);

#include "Trapeze.h"
template class Queue<Trapeze>;
template std::ostream& operator<<(std::ostream& os, const Queue<Trapeze>& queue);

#include "Rectangle.h"
template class Queue<Rectangle>;
template std::ostream& operator<<(std::ostream& os, const Queue<Rectangle>& queue);



 
