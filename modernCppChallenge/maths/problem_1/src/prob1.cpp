#include <iostream>

using namespace std;


int main (int argc, char **argv)
{
    int maxNumber =0, totalSum =0;

    cout << "Please enter a number to use: ";
    cin >> maxNumber;

    for (int i =1; i <=maxNumber; i++)
    {
        if ( ((i % 3) == 0) || ( (i % 5) == 0 ) )
        {
            totalSum += i;
        }
    }

    cout << "Here: " << totalSum << "\n";
}