lab3: main.o Quadrate.o Trapeze.o Rectangle.o Queue.o QQueueItem.o 
	g++ -std=c++11 -g -o lab3 main.o Quadrate.o Trapeze.o Rectangle.o Queue.o QQueueItem.o
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

clean:
	rm *.o lab3
lab:
	./lab3
