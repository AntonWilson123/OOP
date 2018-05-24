#ifndef QQUEUEITEM_H
#define	QQUEUEITEM_H

#include "Quadrate.h"
#include "Trapeze.h"
#include "Rectangle.h"
#include <iostream>
#include <memory>



class QQueueItem {
	public:
		QQueueItem(const std::shared_ptr<Quadrate>& quadrate);
		QQueueItem(const std::shared_ptr<Trapeze>& trapeze);
		QQueueItem(const std::shared_ptr<Rectangle>& rectangle);
		
//		QQueueItem(const QQueueItem& orig);
		
		friend std::ostream& operator<<(std::ostream& os, const QQueueItem& obj);
	
		std::shared_ptr<QQueueItem> SetNext(std::shared_ptr<QQueueItem> &next);
		std::shared_ptr<QQueueItem> GetNext();
		std::shared_ptr<Quadrate> GetQuadrate() const;
		std::shared_ptr<Trapeze> GetTrapeze() const;
		std::shared_ptr<Rectangle> GetRectangle() const;
		
		virtual ~QQueueItem();
	private:
		std::shared_ptr<Quadrate> quadrate;
		std::shared_ptr<Trapeze> trapeze;
		std::shared_ptr<Rectangle> rectangle;
		
		std::shared_ptr<QQueueItem> next;
};

#endif
/* TSTACKITEM_H */
