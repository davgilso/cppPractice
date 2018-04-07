#include <iostream>
#include <memory>

class logger
{
	private:
		virtual void print(std::string message) = 0;
		
	
};

class apple : public logger {
	
	std::string name;
	
public:
	
	apple(void):name("apple"){
	}
	
	void print(std::string message)
	{
		std::cout << "Apple:" << message << std::endl;
	}
	
};

class orange : public logger {
	
	std::string name;

public:
	
	orange (): name("orange"){
	}
	
	void print(std::string message)
	{
		std::cout << "orange: " << message << std::endl;
	}
	
	void notAnOrange(std::shared_ptr<apple> a)
	{
		a->print("Coming from orange");
		std::cout << "Use count:" << a.use_count() << std::endl;
	}
	
};

int main(int argc, char* argv[])
{
	// This little prog will have two obj that implement logger,
	// then a function to print all logs will be called, that
	// takes a shared pointer as an arg. The pointer will be passed
	// by reference so to force an increase of ref count. I will also
	// print out the ref count.
	
	std::shared_ptr<apple> a1 = std::make_shared<apple>();
	std::shared_ptr<orange> o1 = std::make_shared<orange>();
	
	/* This will increase the reference count.*/
	o1->notAnOrange(a1);
	
	/* This will not increase the count, but a1 will now be invalid.*/
	o1->notAnOrange(std::move(a1));
	
	std::cin.get();
	return 0;
}

