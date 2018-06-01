#ifndef QUEUEITEM_H
#define	QUEUEITEM_H

#include <iostream>
#include <memory>

template <class T> class QueueItem {
	public:
		QueueItem(T *item);
		void push(std::shared_ptr <QueueItem<T>> _next);
		void SetNext(std::shared_ptr<QueueItem> _next);
		std::shared_ptr<QueueItem<T>> GetNext();
		std::shared_ptr<T> GetObject() const;
		
		/*
		void *operator new (size_t size);
		void operator delete(void *p);*/
		
		virtual ~QueueItem();
	private:
		std::shared_ptr<T> value;
		std::shared_ptr<QueueItem<T>> next;

		//static AllocationBlock stackitem_allocator;

};

#endif