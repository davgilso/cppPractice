#include <iostream>
#include <memory>

class logger
{
	private:
		virtual std::string print(std::string message) = 0;
		
	
};



int main(int argc, char* argv[])
{
	// This little prog will have two obj that implement logger,
	// then a function to print all logs will be called, that
	// takes a shared pointer as an arg. The pointer will be passed
	// by reference so to force a COPY and increase ref count. I will also
	// print out the ref count.
	return 0;
}