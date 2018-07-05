#include <iostream>
#include <numeric>

using namespace std;


int findGcd(int a, int b);

int main(int argc, char** argv)
{
    int input_a =0, input_b=0, gcd =0, lcm = 0;


    cout << "Enter first number: ";
    cin >> input_a;
    cout << "Enter second number: ";
    cin >> input_b;

    cout << "LCM using std CPP 17 call = " << std::lcm(input_a, input_b) <<"\n";

    gcd = findGcd(input_a, input_b);

    lcm = ((input_a * input_b) / gcd);

    cout << "LCM calculated without using STD::LCM() = " << lcm << "\n";

    return 0;
}

int findGcd(int a, int b)
{
    if (b==0)
    {
        return a;
    }
    else
    {
        a = findGcd(b, (a %b));
        return a;
    }
}