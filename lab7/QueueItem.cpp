#include "QueueItem.h"
#include <iostream>

template <class T> QueueItem<T>::QueueItem(T *object) {
	value = std::shared_ptr<T>(object);
	next = nullptr;
	}

template <class T> void QueueItem<T>::SetNext(std::shared_ptr<QueueItem<T>> _next) {
	next = _next;
}

template <class T> void QueueItem<T>::push(std::shared_ptr<QueueItem> _next){
	if (next != nullptr ){
		next->push(_next);
	}
	else {
		next = _next;
	}

}


template <class T> std::shared_ptr<T> QueueItem<T>::GetObject() const {
	return value;
}

template <class T> std::shared_ptr<QueueItem<T>> QueueItem<T>::GetNext() {
	return next;
}


template <class T> QueueItem<T>::~QueueItem() {
}

#include "List.h"

#include "Quadrate.h"
template class QueueItem<List<Quadrate>>;
template class QueueItem<Quadrate>;
/*
#include "Trapeze.h"
template class QueueItem<List<Trapeze>>;
template class QueueItem<Trapeze>;
//template std::ostream& operator<<(std::ostream& os, const QQueueItem<Trapeze>& obj);

#include "Rectangle.h"
template class QueueItem<List<Rectangle>>;
template class QueueItem<Rectangle>;
//template std::ostream& operator<<(std::ostream& os, const QQueueItem<Rectangle>& obj);
*/


