#include <iostream>
#include "Queue.h"
#include <exception>

template <class T> Queue<T>::Queue() : first(nullptr), last(nullptr) {
	}
	
template <class T> std::shared_ptr<T> Queue<T>::operator[](size_t i){
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

template <class T> void Queue<T>::sort(){
	if (size() > 1){
		std::shared_ptr<T> middle = pop();
		Queue<T> left,right;
		
		while (!empty()){
			std::shared_ptr<T> item = pop();			
		
			if (*item < *middle){
				left.push(item);
			}
				else {
					right.push(item);
					
				}
			
		}

		left.sort();
		right.sort();

		while (!left.empty())
			push(left.pop());
		push(middle);
		while (!right.empty())
			push(right.pop());
	}
}

template<class T> std::future<void> Queue<T>::sort_in_background(){
	std::packaged_task<void(void)> task(std::bind(std::mem_fn(&Queue<T>::sort_parallel), this));
	std::future<void> res(task.get_future());
	std::thread th(std::move(task));
	th.detach();
	return res;
}

template <class T> void Queue<T>::sort_parallel(){
	if (size() > 1){ 	
		std::shared_ptr<T> middle = pop();
		Queue<T> left,right;

		while (!empty()) {
			std::shared_ptr<T> item = pop();
			if (*item < *middle){
				left.push(item);
			}
			else {
				right.push(item);
			}
		}

		std::future<void> left_res = left.sort_in_background();
		std::future<void> right_res = right.sort_in_background();

		left_res.get();

		while (!left.empty())
			push(left.pop());
		push(middle);

		right_res.get();

		while (!right.empty())
			push(right.pop());
		}
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

template <class T> void Queue<T>::push(std::shared_ptr<T> item){
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

template <class T> std::shared_ptr<T> Queue<T>::pop() { 
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


#include "Quadrate.h"
template class Queue<Quadrate>;
template std::ostream& operator<<(std::ostream& os, const Queue<Quadrate>& queue);

#include "Trapeze.h"
template class Queue<Trapeze>;
template std::ostream& operator<<(std::ostream& os, const Queue<Trapeze>& queue);

#include "Rectangle.h"
template class Queue<Rectangle>;
template std::ostream& operator<<(std::ostream& os, const Queue<Rectangle>& queue);



 
