#include "QQueueItem.h"
#include <iostream>

QQueueItem::QQueueItem(const std::shared_ptr<Quadrate> &quadrate) {
	this->quadrate = quadrate;
	this->trapeze = nullptr;
	this->rectangle = nullptr;
	this->next = nullptr;
	std::cout << "Queue item created: quadrate\n";
}

QQueueItem::QQueueItem(const std::shared_ptr<Trapeze> &trapeze) {
	this->trapeze = trapeze;
	this->quadrate = nullptr;
	this->rectangle = nullptr;
	this->next = nullptr;
	std::cout << "Queue item created: trapeze\n";
}

QQueueItem::QQueueItem(const std::shared_ptr<Rectangle> &rectangle) {
	this->rectangle = rectangle;
	this->quadrate = nullptr;
	this->trapeze = nullptr;
	this->next = nullptr;
	std::cout << "Queue item created: rectangle\n";
}

/*
QQueueItem::QQueueItem(const QQueueItem& orig) {
	this->quadrate = orig.quadrate;
	this->next = orig.next;
	std::cout << "Queue item copied\n";
}*/


std::shared_ptr<QQueueItem> QQueueItem::SetNext(std::shared_ptr<QQueueItem> &next) {
	std::shared_ptr<QQueueItem> old = this->next;
	this->next = next;
	return old;
}

std::shared_ptr<Quadrate> QQueueItem::GetQuadrate() const {
	return this->quadrate;
}

std::shared_ptr<Trapeze> QQueueItem::GetTrapeze() const {
	return this->trapeze;
}

std::shared_ptr<Rectangle> QQueueItem::GetRectangle() const {
	return this->rectangle;
}

std::shared_ptr<QQueueItem> QQueueItem::GetNext() {
	return this->next;
}

QQueueItem::~QQueueItem() {
	std::cout << "Queue item deleted\n";
}

std::ostream& operator<<(std::ostream& os, const QQueueItem& obj) {
	if (obj.quadrate != nullptr){
		os << "-------" << *obj.quadrate << "\n";
		return os;
	}
	if (obj.trapeze != nullptr){
		os << "-------" << *obj.trapeze << "\n";
		return os;
	}
	if (obj.rectangle != nullptr){
		os << "-------" << *obj.rectangle << "\n";
		return os;
	}
}

