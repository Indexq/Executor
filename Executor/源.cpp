#include<iostream>
#include"Executor.h"
#include<string>


 int main() {
	Bus* ptr = new Bus();
	std::string cmd;
	ptr->CommendCarry("S");
	while (1) {
		std::cin >> cmd;
		ptr->CommendCarry(cmd);
		
		ptr->CommendCarry("S");
		std::cout << std::endl;
	}

	/*Point p1, p2;
	std::cout << (p1 == p2);*/
	 
	 
	


}
