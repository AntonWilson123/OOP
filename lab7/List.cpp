#include <iostream> 
#include "List.h"

template <class T> List<T>::List() : first(nullptr), last(nullptr),count(0){
	}

/*
template <class T> std::shared_ptr<ListItem<T>> List<T>::get_n_elem(int n){
		std::shared_ptr<ListItem<T>> buf;
		buf = first->object;
		buf = first->next;
		for (int i=0;i<count;i++){	
			if (i+1 == n)
				return buf;
			else
				buf = first->GetNext();
		}
}*/

template <class T> void List<T>::push(T *value){
	std::shared_ptr<ListItem<T>> value_item(new ListItem<T>(value));
	last->SetNext(value_item);
	last = value_item;

/*	if (count <= 5)
		{
			if (first == nullptr){
			first = other;
			last = other;
			count ++;
			return 1;
		}
		else {
			last->SetNext(other);
			last = other;
			count ++;
			if (count == 5)
				merge_list();
			return 1;
		}

	}
	else 
		return -1;*/
}

/*
template <class T> void List<T>::merge_list(){
	std::shared_ptr<ListItem<T>> buf;
	std::shared_ptr<ListItem<T>> newfirst = first;
	std::shared_ptr<T> object1;
	std::shared_ptr<T> object2;
	for (int i=0;i<5;i++){
		object1 = first->GetObject();
		object2 = first->next->GetObject();
		if (object1.Square() > object2.Square() ){
			buf = first->next->GetNext(); // 1-ый ccылается на 3-ий
			first->next = buf;
			first->next->next = *first;	// 2-oi ssilayetsya na 1-iy
			}
		first = first->next;
		}

	}*/

template <class T> size_t List<T>::size(){
	return count;
}

template <class T> std::shared_ptr<T> List<T>::pop_front() { 
	std::shared_ptr<T> firstback;
	if (first != nullptr){
		firstback = first->GetObject();
		first = first->GetNext();
		return firstback;
	}
	else
		std::cout << "Delete error,list is empty\n";
}

template <class T> std::ostream& operator<<(std::ostream& os,const List<T>& list){
	std::shared_ptr<ListItem<T>> item = list.first;
	if (item == nullptr)
		std::cout << "ERROR: list is empty\n";
	while(item != nullptr){
		os << *item;
		item = item->GetNext();
	}	
}

template <class T> bool List<T>::empty(){
	return first == nullptr;
}

#include "Quadrate.h"
template class List<Quadrate>;         
template std::ostream& operator<<(std::ostream&os, const List<Quadrate>& list);

#include "Trapeze.h"
template class List<Trapeze>;
template std::ostream& operator<<(std::ostream&os, const List<Trapeze>& list);

#include "Rectangle.h"
template class List<Rectangle>;
template std::ostream& operator<<(std::ostream&os, const List<Rectangle>& list);
