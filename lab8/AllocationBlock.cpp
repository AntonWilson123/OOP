#include "AllocationBlock.h"
#include <iostream>

void AllocationBlock::push(Node **head, void *free_block) {
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->val = free_block;
    tmp->next = (*head);
    (*head) = tmp;
}
void *AllocationBlock::pop(Node **head) {
    Node* prev = nullptr;
    void *value;
    if (head == nullptr) {
        exit(-1);
    }
    prev = (*head);
    value = prev->val;
    (*head) = (*head)->next;
    free(prev);
    return value;
}

AllocationBlock::AllocationBlock(size_t size,size_t count):	_size(size),_count(count) {
	_used_blocks = (char*)malloc(_size*_count);
	_free_blocks = (Node*)malloc(sizeof(Node*));
	for(size_t i=0;i<_count;i++) 
		push(&_free_blocks,_used_blocks+i*_size );
	_free_count = _count;
	std::cout << "AllocationBlock: Memory init\n";
}


void *AllocationBlock::allocate() {
	void *result = nullptr;
	if(_free_count>0){
		result = pop(&_free_blocks);
		_free_count--;
		std::cout << "AllocationBlock: Allocate " << (_count-_free_count) <<
		" of " << _count << "\n";
	} 
	else{
		std::cout << "AllocationBlock: No memory exception \n" ;
	}
	return result;
}

void AllocationBlock::deallocate(void *pointer) {
	std::cout << "AllocationBlock: Deallocate block \n";
	push(&_free_blocks,pointer);
	_free_count ++;
}

bool AllocationBlock::has_free_blocks() {
	return _free_count>0;
}

AllocationBlock::~AllocationBlock() {
	if(_free_count<_count) 
		std::cout << "AllocationBlock: Memory leak?\n" ;
	else 
		std::cout << "AllocationBlock: Memory freed\n" ;
	delete _free_blocks;
	delete _used_blocks;
}
