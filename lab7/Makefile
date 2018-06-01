lab7: Quadrate.o Trapeze.o Rectangle.o Queue.o QueueItem.o AllocationBlock.o List.o List_item.o main.o
	g++ -std=c++11 -g -Wall Quadrate.o Trapeze.o Rectangle.o Queue.o List.o List_item.o QueueItem.o AllocationBlock.o main.o -o lab7
main.o: main.cpp
	g++ -std=c++11 -g -c main.cpp
List.o: List.cpp
	g++ -std=c++11 -g -c List.cpp
List_item.o: List_item.cpp
	g++ -std=c++11 -g -c List_item.cpp
Quadrate.o: Quadrate.cpp
	g++ -std=c++11 -g -c Quadrate.cpp
Queue.o: Queue.cpp
	g++ -std=c++11 -g -c Queue.cpp
QueueItem.o: QueueItem.cpp
	g++ -std=c++11 -g -c QueueItem.cpp
Trapeze.o: Trapeze.cpp
	g++ -std=c++11 -g -c Trapeze.cpp
Rectangle.o: Rectangle.cpp
	g++ -std=c++11 -g -c Rectangle.cpp
AllocationBlock.o : AllocationBlock.cpp
	g++ -std=c++11 -g -c AllocationBlock.cpp

clean:
	rm *.o lab7
lab:
	./lab7
