#include <cstdlib>
#include <iostream>
#include <memory>

#include "Quadrate.h"
#include "Trapeze.h"
#include "Rectangle.h"

#include "Queue.h"
#include "List.h"


#include "IremoveCriteriaALL.h"
#include "IremoveCriteriaBYVALUE.h"

int main(int argc, char ** argv){
	Queue<List<Quadrate>,Quadrate> queue;
	queue.InsertSubitem(new Quadrate(5));
	queue.InsertSubitem(new Quadrate(7));
	queue.InsertSubitem(new Quadrate(2));
	queue.InsertSubitem(new Quadrate(1));
	queue.InsertSubitem(new Quadrate(11));
	queue.InsertSubitem(new Quadrate(100));
	queue.InsertSubitem(new Quadrate(142));

	std::cout << queue << std::endl;

	return 0;
}