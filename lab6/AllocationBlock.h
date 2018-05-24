#ifndef ALLOCATIONBLOCK_H
#define ALLOCATIONBLOCK_H
#include <cstdlib>
	
typedef struct block_list{
	void *val;
	struct block_list *next;
}Node;
	
class AllocationBlock {
	public:
		AllocationBlock(size_t size,size_t count);
		void *allocate();
		void deallocate(void *pointer);
		bool has_free_blocks();
		virtual ~AllocationBlock();
		void push(Node **head, void *free_block);
		void *pop(Node **head);
	private:
		size_t _size;
		size_t _count;
		char *_used_blocks;
		Node *_free_blocks = nullptr;
		size_t _free_count;
		
};
#endif
