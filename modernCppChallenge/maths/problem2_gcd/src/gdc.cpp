#include <iostream>
#include <numeric>

using namespace std;

int gcdStd(int a, int b);
int recursiveGCD(int a, int b);
int nonRecursiveGCD(int a, int b);

int main (int argc, char **argv)
{
    int numOne =0, numTwo=0;

    cout<<"Enter positive number one: ";
    cin >> numOne;

    cout << "Enter positive number two: ";
    cin >> numTwo;

    gcdStd(numOne, numTwo);

    cout << "Greatest common divisor using recursiveGCD is " << recursiveGCD(numOne, numTwo) << "\n";

    cout << "Greatest common divisor using nonRecursiveGCD is " << nonRecursiveGCD(numOne, numTwo) << "\n";
}

int gcdStd(int a, int b)
{
     cout << "Greatest common divisor using std::gcd is " << std::gcd(a, b) << "\n";

     return 0;
}

int recursiveGCD(int a, int b)
{
    if ((b ==0))
    {
        return a;
    }
    else
    {
        a = recursiveGCD(b, (a %b));
        return a;
    }
}

int nonRecursiveGCD(int a, int b)
{
    int r =0;

    while (b != 0)
    {
        r = b;
        b = (a % b);
        a = r;
    }

    return r;


}
