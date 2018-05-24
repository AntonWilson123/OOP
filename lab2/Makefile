
lab2: main.o Quadrate.o QQueue.o QQueueItem.o 
	g++ -std=c++11 -g -o lab2 main.o Quadrate.o QQueue.o QQueueItem.o
main.o: main.cpp
	g++ -std=c++11 -g -c main.cpp
Quadrate.o: Quadrate.cpp
	g++ -std=c++11 -g -c Quadrate.cpp
QQueue.o: QQueue.cpp
	g++ -std=c++11 -g -c QQueue.cpp
QQueueItem.o: QQueueItem.cpp
	g++ -std=c++11 -g -c QQueueItem.cpp
clean:
	rm *.o lab2
lab:
	./lab2
