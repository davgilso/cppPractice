// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bitset>
#include <vector>
#include <iostream>

using namespace std;

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    
    std::vector<int> vec;
    
    for(int i=0; i<32; i++)
    {
        int mask =  1 << i;
        int masked_n = N & mask;
        int thebit = masked_n >> i;
        vec.push_back(thebit);
    }
    
    bool hasOne = false;
    int zeroCount =0;
    int zCount = 0;
    
    for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (*it == 1)
        {
            hasOne = true;
                    
  
            if (zCount >= zeroCount)
            {
                zeroCount = zCount;
                    
            }
            zCount = 0;
        }
        else
        {
            if (hasOne == true)
            {
                ++zCount;
            }
        }
        
    }
    
    return zeroCount;
}

int main(int argc, char **argv)
{
    int input = 0;
    
    cout << "Please enter a number" << endl;
    cin >> input;
    
    cout << solution(input) << endl;
}
