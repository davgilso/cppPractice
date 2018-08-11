#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void print_each_digit(int x);
int getArmstrong(int num);

std::vector<int>digits;

int main()
{
    for (int i = 100; i < 1000; i++)
    {
       int armstrong = 0;

       armstrong = getArmstrong(i);

       if (armstrong > 0)
       {
           cout << i << "\n";
       }
    }
}

void print_each_digit(int x)
{
    if(x >= 10)
    {
       print_each_digit(x / 10);
    }

    int digit = x % 10;

    digits.push_back(digit);
}

int getArmstrong(int num)
{
    int total =0,tmp =0;

    print_each_digit(num);

    for (std::vector<int>::iterator it = digits.begin(); it != digits.end(); ++it)
    {
        total += ((*it) * (*it) * (*it));
        
        tmp += total;
        total =0;
    }

    digits.clear();

    if (tmp == num)
    {
        return tmp;
    }
    else
    {
        return 0;
    }
}
