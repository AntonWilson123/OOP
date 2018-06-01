#include "Queue.h"

template <class T,class TT> Queue<T,TT>::Queue() : first(nullptr), last(nullptr){
}

template <class T,class TT> void Queue<T,TT>::RemoveSubitem(IRemoveCriteria<TT> *criteria){
	std::cout << "--------------------->" << std::endl;
	for (auto i : *this){
		T copy;
		while(!i->empty()){
			std::shared_ptr<TT> value = i->pop_front();

			if (criteria->isIt(&*value))
				std::cout << "Queue: delete element " << *value << std::endl;
			else {
				copy.push(new TT(*value));
			}
		}
		while (!copy.empty())
			i->push(new TT(*copy.pop_front()));
	}
	std::cout << "!!!!!!!!!!!!!!!!" << std::endl;
}

template <class T,class TT> void Queue<T,TT>::InsertSubitem(TT *value){
	bool inserted = false;
	if (first != nullptr){
		for (auto i : *this){
			if (i->size() < 5){
				i->push(value);
				std::cout << "Queue: Add element in queue:" << i->size() << std::endl;
				inserted = true;
			}
		}
	}

	if (!inserted){
		std::cout << "Queue: New queue element created" << std::endl;
		T* t_value = new T();
		t_value->push(value);
		push(t_value);
	}
}

template <class T, class TT> void Queue<T,TT>::push(T *value){
	std::shared_ptr<QueueItem<T>> value_item(new QueueItem<T>(value));
	std::cout << "Queue: Added to queue" << std::endl;
	if (first != nullptr){
		first->push(value_item);
	}
	else {
		first = value_item;
	}
}

template <class T,class TT> bool Queue<T,TT>::pop(){
	if (first != nullptr) {
		first = first->GetNext();
	}
	else 
		std::cout << " DELETE ERROR, QUEUE IS EMPTY\n ";
}

template <class T,class TT> size_t Queue<T,TT>::Size(){
	size_t size = 0;
	for (auto a: *this)
		size ++;
	return size;
}

template <class T,class TT> Iterator<QueueItem<T>,T> Queue<T,TT>::begin() const{
	return Iterator<QueueItem<T>,T>(first);
}
template <class T,class TT> Iterator<QueueItem<T>,T> Queue<T,TT>::end() const{
	return Iterator<QueueItem<T>,T>(nullptr);
}

template <class T,class TT> Queue<T,TT>::~Queue(){
	std::cout << "Queue: deleted" << std::endl;
}


template <class A,class AA> std::ostream& operator<< (std::ostream& os,const Queue<A,AA>& queue){
	std::cout << "Queue:" << std::endl;
	for (auto i:queue)
		std::cout << *i << std::endl;
	return os;
}

#include "List.h"
#include "Quadrate.h"

template class Queue<List<Quadrate>,Quadrate>;
template std::ostream& operator<<(std::ostream& os, const Queue<List<Quadrate>,Quadrate> &queue);


/*
#include "Trapeze.h"
template class Queue<List<Trapeze>,Trapeze>;
template std::ostream& operator<<(std::ostream& os, const Queue<List<Trapeze>,Trapeze> & obj);

#include 	"Rectangle.h"
template class Queue<List<Rectangle>,Rectangle>;
template std::ostream& operator<<(std::ostream& os, const Queue<List<Rectangle>,Rectangle> & obj);
*/

