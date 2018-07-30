#include <iostream>

using namespace std;

bool isAbundant(int input, int *abundance);

int main ()
{
    int input;
    cout << "Enter range to search to: ";
    cin >> input;

    for (int i =1; i <=input; i++)
    {
        int j;
        if (isAbundant(i, &j))
        {
            cout << "Abundant number = " << i << " Abundance = " << j << "\n";
        }
    }

    return 0;
}

bool isAbundant(int input, int *abundance)
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
        *abundance = (total - input);
        return true;
    }
    else
    {
        *abundance = 0;
        return false;
    }
}