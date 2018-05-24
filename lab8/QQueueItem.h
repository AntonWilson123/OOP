#ifndef QQUEUEITEM_H
#define	QQUEUEITEM_H

#include <iostream>
#include <memory>
//#include "AllocationBlock.h"

template <class T> class QQueueItem {
	public:
		QQueueItem(T *item);
		QQueueItem(const std::shared_ptr<T>& item);
		template <class A> friend std::ostream& operator<<(std::ostream& os,
		 const QQueueItem<A>& obj);


	
		std::shared_ptr<QQueueItem<T>> SetNext(std::shared_ptr<QQueueItem> &next);
		std::shared_ptr<QQueueItem<T>> GetNext();
		std::shared_ptr<T> GetObject() const;
		
		virtual ~QQueueItem();
	private:
		std::shared_ptr<T> object;
		std::shared_ptr<QQueueItem<T>> next;

		//static AllocationBlock stackitem_allocator;

};

#endif
/* TSTACKITEM_H */
