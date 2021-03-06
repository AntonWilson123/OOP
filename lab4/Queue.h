#ifndef QQUEUE_H
#define QQUEUE_H

#include "Quadrate.h"
#include "Rectangle.h"
#include "Trapeze.h"
#include <memory>
#include "QQueueItem.h"

template <class T> class Queue {
	public:
		Queue();
		void push(std::shared_ptr<T> &&item);
		void top();
		bool empty();
		void pop();
		template <class A> friend std::ostream& operator<<(std::ostream& os,const Queue<A>& queue);	
		virtual ~Queue();
	private:
		std::shared_ptr<QQueueItem<T>> first;
		std::shared_ptr<QQueueItem<T>> last;
};
#endif 
