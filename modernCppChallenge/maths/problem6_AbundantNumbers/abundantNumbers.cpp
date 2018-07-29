#include <iostream>

using namespace std;

bool isAbundant(int input);

int main ()
{
    int input;
    cout << "Enter range to search to: ";
    cin >> input;

    for (int i =1; i <=input; i++)
    {
        if (isAbundant(i))
        {
            cout << i << " is an abundant number. \n";
        }
    }

    return 0;
}

bool isAbundant(int input)
{
    int total =0;

    for (int i = 1; i < input; i++)
    {
        if ( (input % i) == 0)
        {
            total +=i;
        }
    }

    if (total > input)
    {
        return true;
    }
    else
    {
        return false;
    }

}