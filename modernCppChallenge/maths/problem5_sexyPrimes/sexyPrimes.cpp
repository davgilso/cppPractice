#include <iostream>
#include <optional>
#include <vector>
#include <algorithm>

using namespace std;

std::vector<int> getPrimesList(int a);
void printSexyPairs(std::vector<int> primes);
void findSexyPairs(std::vector<int>primes, std::vector<int>*pairs);

int main()
{
    std::vector<int>sexyPairs;
    std::vector<int>primes;

    int input;

    // 1. Get prime list.
    cout << "Please enter max range:";
    cin >> input;

    primes = getPrimesList(input);
    findSexyPairs(primes, &sexyPairs);
    printSexyPairs(sexyPairs);  

    return 0;
}

std::vector<int> getPrimesList(int a)
{
    std::vector<int> primeList;

    if (a <= 1)
    {
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
    }

    return primeList;
}

void findSexyPairs(std::vector<int>primes, std::vector<int> *pairs)
{
    // Step through list and check for sexy prime pairs.
    for(std::vector<int>::iterator it = primes.begin(); it != primes.end(); ++it)
    {
        if (std::find(primes.begin(), primes.end(), (*it +6))!= primes.end() )
        {
            pairs->push_back(*it);
            pairs->push_back(*it +6);
        }

    }
}

void printSexyPairs(std::vector<int> primes)
{
    for (std::vector<int> ::iterator it = primes.begin(); it != primes.end(); it++)
    {
        cout << "(" << *it << "," << *++it <<")" << "\n";
    }
}