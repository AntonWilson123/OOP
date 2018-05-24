#ifndef QQUEUE_H
#define QQUEUE_H

#include "Quadrate.h"
#include "Rectangle.h"
#include "Trapeze.h"
#include <memory>
#include "QQueueItem.h"

class Queue {
	public:
		Queue();
	
		void push(std::shared_ptr<Quadrate> &&quadrate);
		void push(std::shared_ptr<Trapeze> &&trapeze);
		void push(std::shared_ptr<Rectangle> &&rectangle);
		
		bool empty();
		void pop();
	
		friend std::ostream& operator<<(std::ostream& os,const Queue& queue);	
		virtual ~Queue();
	private:
		std::shared_ptr<QQueueItem> first;
		std::shared_ptr<QQueueItem> last;
};
#endif 
