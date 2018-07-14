/**
 * Give a number (n), return the highest prime number
 * that is lower than the n.
 * 
 * This implementation uses std::optional to catch
 * the case where the user enter an invalid value
 * and no prime number can be returned by getLowestprime().
 * 
 * This example also shows how you can iterate over a vector.
 * 
 * 
 * 
 **/

#include <iostream>
#include <optional>
#include <vector>

using namespace std;

std::optional<int>getLowestPrime(int a);

int main()
{
    int userInput;
    std::optional<int>lowestPrime;

    cout << "Please enter a positive int: ";
    cin >> userInput;

    lowestPrime = getLowestPrime(userInput);

    if(lowestPrime.has_value())
    {
        cout << "Lowest prime number is: " << lowestPrime.value() << "\n";
    }
    else
    {
        cout << "Nothing";
    }

    return 0;
}

std::optional<int>getLowestPrime(int a)
{
    std::vector<int> primeList;

    if (a <= 1)
    {
        return {};
    }
    else
    {
        for (int i = 2; i <=a; i++)
        {
            int tmp=2;

            while((i % tmp) != 0 )
            {
                tmp++;
            }

            if(tmp == i)
            {
                primeList.push_back(i);
            }
        }

        for (std::vector<int>::iterator it = primeList.end(); it != primeList.begin(); --it)
        {
            if ((*it !=0) && (*it < a))
            {
                return *it;
            }
        }
    }

    return {};

}