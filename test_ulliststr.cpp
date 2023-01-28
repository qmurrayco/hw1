#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
	ULListStr dat;
	dat.push_back("7");
	dat.push_front("8");
	dat.push_back("9");

	std::cout << "------------------------TOP----------------------------------" << std::endl;

	std::cout << "Get call index 0:" << dat.get(0) << std::endl; //should return 8
	std::cout << "Get call index 1:" << dat.get(1) << std::endl; //should return 7
	std::cout << "Get call index 2:" << dat.get(2) << std::endl; //should return 9
	//std::cout << "Get call 5:" << dat.get(5) << std::endl; //should return NULL

	dat.push_back("10");

	std::cout << "Get call 3:" << dat.get(3) << std::endl; //should return 10

	dat.push_front("11");

	std::cout << "Get call index 0:" << dat.get(0) << std::endl; //should return 11

	dat.pop_back(); //list should be 11 8 7  -> 9 -> NULL

	std::cout << "Get call index 3:" << dat.get(3) << std::endl; //should return 9

	dat.pop_front(); //list should be 8 7 -> 9 -> NULL

	std::cout << "Get call index 0:" << dat.get(0) << std::endl; //should return 8

	//lets see if we can delete the whole thing

	std::cout << "-------------------------MID---------------------------------" << std::endl;

	dat.pop_front(); //list should now be 7 -> 9 -> NULL

	std::cout << "Get call index 0:" << dat.get(0) << std::endl; //should return 7
	std::cout << "Get call index 1:" << dat.get(1) << std::endl; //should return 9

	dat.pop_front(); //list should now be 9 -> NULL

	std::cout << "Get call index 0:" << dat.get(0) << std::endl; //should return 9

	dat.pop_front(); //list should be empty now

	if(dat.empty()){
		std::cout << "List is empty, deletion by pop_front was good" << std::endl;
	}


	//going to try the same with pop_back()
	std::cout << "Attempting to refill list and delete again" << std::endl;
	dat.push_back("7");
	dat.push_front("8");
	dat.push_back("9");

	dat.pop_back();
	dat.pop_back();
	dat.pop_back();

	if(dat.empty()){
		std::cout << "List is empty, deletion by pop_back was good" << std::endl;
	}
	
	dat.push_back("7");
	dat.push_front("8");
	dat.push_back("9");

	std::cout << "List refilled, trying back() and front()" << std::endl;

	std::string test;
	test = dat.back();

	std::cout << "Back() yields:" << test << std::endl; //should be 9

	std::string test2;
	test2 = dat.front();

	std::cout << "Front() yields:" << test2 << std::endl; //should be 8

	//50 elements from back

	ULListStr list;

	for(int i = 0; i < 50; i++){
		list.push_back("test");
	}


	//try to delete them
	
	for(int i = 0; i < 50; i++){
		list.pop_back();
	}
}
