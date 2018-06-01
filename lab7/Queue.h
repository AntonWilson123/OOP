#ifndef QUEUE_H
#define QUEUE_H

#include <memory>
#include "QueueItem.h"
#include "Iterator.h"
#include "IremoveCriteria.h"

template <class T,class TT> class Queue {
	public:
		Queue();

		void push(T *item);
		
		void InsertSubitem(TT* value);
		void RemoveSubitem(IRemoveCriteria<TT> * criteria);
		bool pop();
		size_t Size();

		Iterator<QueueItem<T>,T> begin() const;
		Iterator<QueueItem<T>,T> end() const;
	
		template <class A,class AA> friend std::ostream& operator<<(std::ostream& os,const Queue<A,AA>& queue);	
				
		virtual ~Queue();
	private:
		std::shared_ptr<QueueItem<T>> first;
		std::shared_ptr<QueueItem<T>> last;
};
#endif 
