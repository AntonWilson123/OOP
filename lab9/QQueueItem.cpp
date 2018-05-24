#include "QQueueItem.h"
#include <iostream>

template <class T> QQueueItem<T>::QQueueItem(const std::shared_ptr<T> &object,std::recursive_mutex *parent) {
	this->queue_mutex = parent;
	this->object = object;
	this->next = nullptr;
//	std::cout << "Queue item created!\n";
}

template <class T> QQueueItem<T>::QQueueItem(T *object,std::recursive_mutex *parent) {
	this->queue_mutex = parent;
	this->object = std::shared_ptr<T>(object);
	this->next = nullptr;
//	std::cout << "Queue item created!\n";
}


//template <class T> AllocationBlock QQueueItem<T>::stackitem_allocator(sizeof(QQueueItem<T>),100);


template <class T> std::shared_ptr<QQueueItem<T>> QQueueItem<T>::SetNext(std::shared_ptr<QQueueItem<T>> &next) {
	std::unique_lock<std::recursive_mutex> lock(*queue_mutex);
	std::shared_ptr<QQueueItem<T>> old = this->next;
	this->next = next;
	return old;
}


template <class T> std::shared_ptr<T> QQueueItem<T>::GetObject() const {
	std::unique_lock<std::recursive_mutex> lock(*queue_mutex);
	return this->object;
}

template <class T> std::shared_ptr<QQueueItem<T>> QQueueItem<T>::GetNext() {
	std::unique_lock<std::recursive_mutex> lock(*queue_mutex);
	return this->next;
}


template <class T> QQueueItem<T>::~QQueueItem() {
//	std::cout << "Queue item deleted\n";
}

template <class A> std::ostream& operator<<(std::ostream& os, const QQueueItem<A>& obj) {
		std::unique_lock<std::recursive_mutex> lock(*obj.queue_mutex);
		os << "-------" << *obj.object << "\n";
		return os;
}
/*
template <class T> void * QQueueItem<T>::operator new (size_t size) {
	return stackitem_allocator.allocate();
}

template <class T> void QQueueItem<T>::operator delete(void *p) {
	stackitem_allocator.deallocate(p);
}*/
#include <functional>
template class QQueueItem<std::function<void(void)>>;
#include "Quadrate.h"
template class QQueueItem<Quadrate>;
template std::ostream& operator<<(std::ostream& os, const QQueueItem<Quadrate>& obj);

#include "Trapeze.h"
template class QQueueItem<Trapeze>;
template std::ostream& operator<<(std::ostream& os, const QQueueItem<Trapeze>& obj);

#include "Rectangle.h"
template class QQueueItem<Rectangle>;
template std::ostream& operator<<(std::ostream& os, const QQueueItem<Rectangle>& obj);



