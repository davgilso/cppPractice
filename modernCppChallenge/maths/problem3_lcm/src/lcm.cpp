#include <iostream>
#include <numeric>
#include <vector>

using namespace std;


int findGcd(int a, int b);

int calcLcm(int a, int b);

int main(int argc, char** argv)
{
    int input_a =0, input_b=0, gcd =0, lcm = 0;
    std::vector<int> userInput;
    bool hasInput = true;

    cout << "Enter first number: ";
    cin >> input_a;
    cout << "Enter second number: ";
    cin >> input_b;

    cout << "LCM using std CPP 17 call = " << std::lcm(input_a, input_b) <<"\n";

    gcd = findGcd(input_a, input_b);

    lcm = ((input_a * input_b) / gcd);

    cout << "LCM calculated without using STD::LCM() = " << lcm << "\n";

    cout << "Enter >2 numbers to then calculate LCM" << "\n";

    while (hasInput)
    {
        int temp;
        cout << "Enter a number: ";
        cin >> temp;

        if (temp != 0)
        {
            userInput.push_back(temp);
        }
        else
        {
            hasInput = false;
        }

    }

    // Accum will start by passing in the init value first along with the first element in the vector.
    // this means the init value needs to be something that can kick off the calculation correctly.
    lcm = std::accumulate(userInput.begin(), userInput.end(), 1, calcLcm);

    cout << "Accum LCM = " << lcm <<"\n";
    

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

int calcLcm(int a, int b)
{
    int gcd =0;

    gcd = findGcd(a, b);
    cout << "GCD = " << gcd << "\n";
    if (gcd !=0)
    {
        return ((a * b) / gcd);
    }
    else
    {
        return 0;
    }
}