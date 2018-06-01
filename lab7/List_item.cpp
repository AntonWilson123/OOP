#include "List_item.h"

#include <iostream>

template <class T> ListItem<T>::ListItem(T *_object) {
	this->object = std::shared_ptr<T>(_object);
	this->next = nullptr;
	std::cout << "List item: created!\n";
}


template <class T> AllocationBlock ListItem<T>::stackitem_allocator(sizeof(ListItem<T>),100);


template <class T> std::shared_ptr<ListItem<T>> 
ListItem<T>::SetNext(std::shared_ptr<ListItem<T>> &next) {
	std::shared_ptr<ListItem<T>> old = this->next;
	this->next = next;
	return old;
}


template <class T> std::shared_ptr<T> ListItem<T>::GetObject() const {
	return this->object;
}

template <class T> std::shared_ptr<ListItem<T>> ListItem<T>::GetNext() {
	return this->next;
}


template <class T> ListItem<T>::~ListItem() {
	std::cout << "List item deleted\n";
}

template <class A> std::ostream& operator<<(std::ostream& os, const ListItem<A>& obj) {
		os << "-------" << *obj.object << "\n";
		return os;
}

template <class T> void * ListItem<T>::operator new (size_t size) {
	return stackitem_allocator.allocate();
}

template <class T> void ListItem<T>::operator delete(void *p) {
	stackitem_allocator.deallocate(p);
}


#include "Quadrate.h"
template class ListItem<Quadrate>;
template std::ostream& operator<<(std::ostream&os, const ListItem<Quadrate>& list);

#include "Trapeze.h"
template class ListItem<Trapeze>;
template std::ostream& operator<<(std::ostream&os, const ListItem<Trapeze>& list);

#include "Rectangle.h"
template class ListItem<Rectangle>;
template std::ostream& operator<<(std::ostream&os, const ListItem<Rectangle>& list);
