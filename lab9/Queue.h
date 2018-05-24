#ifndef QQUEUE_H
#define QQUEUE_H

#include <memory>
#include <future>
#include <mutex>
#include <thread>
#include "QQueueItem.h"
#include "Iterator.h"

template <class T> class Queue {
	public:
		Queue();
		void push(T *item);
		void push(std::shared_ptr<T> item);
		size_t size();
/*
		void sort();
		void sort_parallel();
*/
		std::shared_ptr<T> operator[] (size_t i);
		bool empty();
		std::shared_ptr<T> pop();
		template <class A> friend std::ostream& operator<<(std::ostream& os,const Queue<A>& queue);	
		
		Iterator<QQueueItem<T>,T> begin();
		Iterator<QQueueItem<T>,T> end();
		
		
		virtual ~Queue();
	private:
		std::recursive_mutex queue_mutex;
		std::shared_ptr<QQueueItem<T>> first;
		std::shared_ptr<QQueueItem<T>> last;
};
#endif 
