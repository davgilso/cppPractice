#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getSmallestPrime(int num);
bool isPrime(int num);

int main()
{
    int input = 0, tmp =0, sp =0;
    std::vector<int>factors;

    cout << "Enter number: ";
    cin >> input;

    tmp = input;


    while (tmp > 0)
    {
        sp = getSmallestPrime(tmp);

        if (sp != 0)
        {
            // !!! I NEED TO FIRST FIND THE SMALLEST PRIME NOT JUST OUTPUT 2!!!!!!
            if ( ((tmp / sp) > 0) && ((tmp % sp) ==0) )
            {
                tmp = (tmp / sp);
                factors.push_back(tmp);
                factors.push_back(sp);
            }
            else
            {
                tmp =0;
                break;
            }
        }
        else
        {
            break;
        }
    }

    std::sort( factors.begin(), factors.end());

    for (std::vector<int>::iterator it = factors.begin(); it != factors.end(); ++it)
    {
        // !!! I NEED TO FIRST FIND THE SMALLEST PRIME NOT JUST OUTPUT 2!!!!!!

        if (isPrime(*it))
        {
            cout << *it << "* ";
        }
    }

    cout << "\n";
}

int getSmallestPrime(int num)
{
    int rtn = 0;

    if (num < 1)
    {
        return rtn;
    }
    else
    {
        for (int i=2; i < (num/2); i++)
        {
            if (num%i ==0)
            {
                rtn = i;
                break;
            }
        }
    }

    return rtn;
}

bool isPrime(int num)
{
    if (num < 1)
    {
        return false;
    }
    else
    {
        for (int i=2; i < (num/2); i++)
        {
            if (num%i ==0)
            {
                return false;
            }
        }
    }

    return true;
}

