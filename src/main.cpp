#include <iostream>
#include <string>
#include <vector>

struct phoneBookEntry
{
	std::string name, number, address;
};

std::ostream& operator<<(std::ostream& stream, const phoneBookEntry& pbEntry)
{
	stream << pbEntry.address << "," << pbEntry.name << "," << pbEntry.number;
	return stream;
}

int main (int argc, char* argv[])
{
	std::vector<phoneBookEntry> PbVector;
	PbVector.push_back({"Mr Tom", "01383 7782372", "2 silly road"});
	PbVector.push_back({"Mr Dick", "01562 897982","201 mob street"});
	
	for (int i =0; i < (int)PbVector.size(); i++)
	{
		std::cout << PbVector[i] << std::endl;
	}
	
	PbVector.erase(PbVector.begin()+1);
	
	for (phoneBookEntry& pb : PbVector)
	{
		std::cout << pb << std::endl;
	}
	
	std::cin.get();
}