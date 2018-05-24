#include <cstdlib>
#include "Quadrate.h"
#include "Rectangle.h"
#include "Trapeze.h"
#include "Queue.h"
#include <future>
#include <functional>
#include <random>
#include <thread>


int main(int argc, char **argv){
	Queue<Quadrate> queue_quad;
	typedef std::function<void(void)> command;
	Queue<command> queue_cmd;

	command cmd_insert = [&](){
		std::cout << "Command: create quadrates\n";
		std::default_random_engine generator;
		std::uniform_int_distribution<int> distribution(1,100);

		for (int i=0;i< 10; i++){
			int side = distribution(generator);
			queue_quad.push(new Quadrate(side));
		}
	};

	command cmd_print = [&](){
		std::cout << "Command: print queue\n";
		std::cout << queue_quad;
	};

	queue_cmd.push(std::shared_ptr<command> (&cmd_print, [](command*){
	}));
	queue_cmd.push(std::shared_ptr<command> (&cmd_insert, [](command*){
	}));
	queue_cmd.push(std::shared_ptr<command> (&cmd_print, [](command*){
	}));

	while (!queue_cmd.empty()){
		std::shared_ptr<command> cmd = queue_cmd.pop();
		std::future<void> ft = std::async(*cmd);
		ft.get();
	}
	return 0;
}