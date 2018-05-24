#ifndef QQUEUE_H
#define QQUEUE_H

#include "Quadrate.h"
#include "QQueueItem.h"

class QQueue {
	public:
		QQueue();
		QQueue(const QQueue& orig);
		void push(Quadrate &&quadrate);
		bool empty();
		Quadrate pop();
		
		friend std::ostream& operator<<(std::ostream& os,const QQueue& queue);
		
		virtual ~QQueue();
	private:
		QQueueItem *first; //указатель на очередь
		QQueueItem *last;
	//	int QueueElems;
};
#endif 
