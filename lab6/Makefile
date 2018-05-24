lab6: Quadrate.o Trapeze.o Rectangle.o Queue.o QQueueItem.o AllocationBlock.o main.o
	g++ -std=c++11 -g -Wall Quadrate.o Trapeze.o Rectangle.o Queue.o QQueueItem.o AllocationBlock.o main.o -o lab6
main.o: main.cpp
	g++ -std=c++11 -g -c main.cpp
Quadrate.o: Quadrate.cpp
	g++ -std=c++11 -g -c Quadrate.cpp
Queue.o: Queue.cpp
	g++ -std=c++11 -g -c Queue.cpp
QQueueItem.o: QQueueItem.cpp
	g++ -std=c++11 -g -c QQueueItem.cpp
Trapeze.o: Trapeze.cpp
	g++ -std=c++11 -g -c Trapeze.cpp
Rectangle.o: Rectangle.cpp
	g++ -std=c++11 -g -c Rectangle.cpp
AllocationBlock.o : AllocationBlock.cpp
	g++ -std=c++11 -g -c AllocationBlock.cpp

clean:
	rm *.o lab6
lab:
	./lab6
