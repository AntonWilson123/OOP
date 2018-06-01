#ifndef LIST_ITEM
#define LIST_ITEM


#include <iostream>
#include <memory>
#include "AllocationBlock.h"

template <class T> class ListItem {
	public:
		ListItem(T *_object);
		
		template <class A> friend std::ostream& operator<<(std::ostream& os,
		 const ListItem<A>& obj);
	
		std::shared_ptr<ListItem<T>> SetNext(std::shared_ptr<ListItem> &next);
		std::shared_ptr<ListItem<T>> GetNext();
		std::shared_ptr<T> GetObject() const;
		
		
		void *operator new (size_t size);
		void operator delete(void *p);
		
		virtual ~ListItem();
	private:
		std::shared_ptr<T> object;
		std::shared_ptr<ListItem<T>> next;

		static AllocationBlock stackitem_allocator;

};



#endif
