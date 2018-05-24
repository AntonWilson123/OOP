#include "QQueueItem.h"
#include "Queue.h"
#include <iostream>

template <class T> QQueueItem<T>::QQueueItem(const std::shared_ptr<T> &object) {
	this->object = object;
	this->next = nullptr;
	std::cout << "Queue item created!\n";
}


template <class T> std::shared_ptr<QQueueItem<T>> 
QQueueItem<T>::SetNext(std::shared_ptr<QQueueItem<T>> &next) {
	std::shared_ptr<QQueueItem<T>> old = this->next;
	this->next = next;
	return old;
}

template <class T> std::shared_ptr<T> QQueueItem<T>::GetObject() const {
	return this->object;
}

template <class T> std::shared_ptr<QQueueItem<T>> QQueueItem<T>::GetNext() {
	return this->next;
}


template <class T> QQueueItem<T>::~QQueueItem() {
	std::cout << "Queue item deleted\n";
}

template <class A> std::ostream& operator<<(std::ostream& os, const QQueueItem<A>& obj) {
		os << "-------" << *obj.object << "\n";
		return os;
}

template <class T> void * QQueueItem<T>::operator new (size_t size) {
	std::cout << "Allocated : " << size << " bytes\n";
	return malloc(size); 
}

template <class T> void QQueueItem<T>::operator delete(void *p){
		std::cout << "Deleted\n";
		free(p);
}

#include "Quadrate.h"
template class QQueueItem<Quadrate>;
template std::ostream& operator<<(std::ostream& os, const QQueueItem<Quadrate>& obj);

#include "Trapeze.h"
template class QQueueItem<Trapeze>;
template std::ostream& operator<<(std::ostream& os, const QQueueItem<Trapeze>& obj);

#include "Rectangle.h"
template class QQueueItem<Rectangle>;
template std::ostream& operator<<(std::ostream& os, const QQueueItem<Rectangle>& obj);



