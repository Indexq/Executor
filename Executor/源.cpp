#include<iostream>
#include"Executor.h"
#include<string>


int main() {
	Exceutor* ptr = new Exceutor();
	std::string cmd;
	ptr->CommendCarry("S");
	while (1) {
		std::cin >> cmd;
		ptr->CommendCarry(cmd);
		
		ptr->CommendCarry("S");
		std::cout << std::endl;
	}


	


}
