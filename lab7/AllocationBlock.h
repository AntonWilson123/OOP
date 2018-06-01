#ifndef ALLOCATIONBLOCK_H
#define ALLOCATIONBLOCK_H
#include <cstdlib>	
	
class AllocationBlock {
	public:
		AllocationBlock(size_t size,size_t count);
		void *allocate();
		void deallocate(void *pointer);
		bool has_free_blocks();
		virtual ~AllocationBlock();
			private:
		size_t _size;
		size_t _count;
		char *_used_blocks;
		void **_free_blocks = nullptr;
		size_t _free_count;
		
};
#endif
