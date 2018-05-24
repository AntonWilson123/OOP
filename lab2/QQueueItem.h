#ifndef QQUEUEITEM_H
#define	QQUEUEITEM_H

#include "Quadrate.h"
#include <iostream>

class QQueueItem {
	public:
		QQueueItem(const Quadrate& quadrate);
		QQueueItem(const QQueueItem& orig);
	
		friend std::ostream& operator<<(std::ostream& os, const QQueueItem& obj);
	
		QQueueItem* SetNext(QQueueItem* next);
		QQueueItem* GetNext();
		Quadrate GetQuadrate() const;
		virtual ~QQueueItem();
	private:
		Quadrate quadrate;
		QQueueItem *next;
};

#endif
/* TSTACKITEM_H */
