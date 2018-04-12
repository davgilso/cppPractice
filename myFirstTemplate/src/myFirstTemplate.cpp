/*
 * Very simple example of how to template a class.
 * 
 * Scenario: Create a logger class that has a single
 * print function for any input type.
 * 
 * Also, I used unique pointer to avoid the use of NEW
 * keyword.
 * 
 * The class template just specifies a type that is will
 * be specified when a new logger obj is created. So,
 * a user must create a new logger object for each type
 * of item they would like to log.
 * 
 * 
 */ 


#include <iostream>
#include <memory>
#include <string>

using namespace std;


template <typename T>
class logger
{
public:
	void print(T message)
	{
		cout << message << endl;
	}
};


int main()
{
	
	auto myLogString = make_unique<logger<std::string>>();
	auto myLogInt    = make_unique<logger<int>>();
	
	myLogString->print("Hello string");
	myLogInt->print(69);
	cin.get();
	
	return 0;
}