#include "QQueueItem.h"
#include <iostream>

QQueueItem::QQueueItem(const Quadrate& quadrate) {
	this->quadrate = quadrate;
	this->next = nullptr;
	std::cout << "Queue item created\n";
}

QQueueItem::QQueueItem(const QQueueItem& orig) {
	this->quadrate = orig.quadrate;
	this->next = orig.next;
	std::cout << "Queue item copied\n";
}


QQueueItem* QQueueItem::SetNext(QQueueItem* next) {
	QQueueItem* old = this->next;
	this->next = next;
	return old;
}

Quadrate QQueueItem::GetQuadrate() const {
	return this->quadrate;
}

QQueueItem* QQueueItem::GetNext() {
	return this->next;
}

QQueueItem::~QQueueItem() {
	std::cout << "Queue item deleted\n";
}

std::ostream& operator<<(std::ostream& os, const QQueueItem& obj) {
	os << "-------" << obj.quadrate << "\n";
	return os;
}

