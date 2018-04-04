#include <iostream>
#include <string>
#include <vector>

struct phoneBookEntry
{
	std::string name, number, address;
	
	//For some reason I had to create a constructor for my copy method to work!.
	phoneBookEntry(std::string a, std::string b, std::string c )
		: name(a), number(b), address(c)
	{
			
	}
	
	//Copy method, that will tell us when a element is copied.
	phoneBookEntry(const phoneBookEntry& value) 
		: name(value.name), number(value.number), address(value.address)
	{
		std::cout << "Copied" << std::endl;
	}
};

//Override output operator to print values of phoneBookEntry struct.
std::ostream& operator<<(std::ostream& stream, const phoneBookEntry& pbEntry)
{
	stream << pbEntry.address << "," << pbEntry.name << "," << pbEntry.number;
	return stream;
}

int main (int argc, char* argv[])
{
	std::vector<phoneBookEntry> PbVector;
	
	/* Reserver 2 items in memory to help reduce the numver of copies made.
	 * You still cannot prevent a copy per insert though, since the data will
	 * always be copied into the memory allocated for the vecotr.
	 */
	PbVector.reserve(2);
	
	PbVector.push_back(phoneBookEntry("Mr Tom", "01383 7782372", "2 silly road"));
	PbVector.push_back(phoneBookEntry("Mr Dick", "01562 897982","201 mob street"));
	
	for (int i =0; i < (int)PbVector.size(); i++)
	{
		std::cout << PbVector[i] << std::endl;
	}

	//Remove item 2 in the vector and then print all items again.
	PbVector.erase(PbVector.begin()+1);
	
	for (phoneBookEntry& pb : PbVector)
	{
		std::cout << pb << std::endl;
	}

	std::cin.get();
}