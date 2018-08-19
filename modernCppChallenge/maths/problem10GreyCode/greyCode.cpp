#include <iostream>
#include <bitset>
#include <math.h>

using namespace std;

int grey_encode(int num);

int main()
{
    int bitNum = 31;

    for (int i = 0; i <= bitNum; i++)
    {
        int greyCode =0;

        cout << "Number = " << i << "\n";
        cout << "binary: " << std::bitset<5> (i)<< "\n";
        greyCode = grey_encode(i);
        cout << "grey code: " << std::bitset<5> (greyCode)<< "\n\n";

    }
}

int grey_encode(int num)
{
    return num ^ (num >>1);
}