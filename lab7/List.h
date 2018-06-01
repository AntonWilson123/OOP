#ifndef LIST_H
#define LIST_H

#include "List_item.h"
#include "Iterator.h"
#include <memory>


template <class T> class List {
	public:
		List();
		void push(T *item);
		std::shared_ptr<T> pop_front();		
		bool empty();
		size_t size();
		template <class A> friend std::ostream& operator<<(std::ostream& os,const List<A>& list);	

		Iterator<ListItem<T>,T> begin();
		Iterator<ListItem<T>,T> end();			

		virtual ~List();
	private:
		//void merge_list();
	//	std::shared_ptr<ListItem<T>> get_n_elem(int n);
		std::shared_ptr<ListItem<T>> first;
		std::shared_ptr<ListItem<T>> last;
		int count;
};
#endif
	
