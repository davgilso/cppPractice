//
//  solution.cpp
//  missingInteger
//
//  Created by David Gilson on 17/11/2018.
//

#include <iostream>
#include <vector>

using namespace std;

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(std::vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int vecSize = static_cast<int>(A.size());
    std::vector<bool> counter(A.size());
    int check = 0;
    
    
    //Step through vector and flag small values as being seen or not.
    for (std::vector<int>::iterator it = A.begin(); it != A.end(); ++it)
    {
        if ((*it >0) && (*it <= vecSize))
        {
            counter[*it - 1] = true;
        }
    }
    
    //Check if small values have not been seen and return the first (this will be the smallest.
    for (std::vector<bool>::iterator it = counter.begin(); it != counter.end(); ++it)
    {
        ++check;
        
        if (!*it)
        {
            return (check);
        }
    }
    
    // Return the next largest number, as this will now be the only one that can be next smallest missing.
    return vecSize +1;
}

int main()
{
    std::vector<int> vInput;
    //[1, 3, 6, 4, 1, 2],
    vInput.push_back(230);
    vInput.push_back(3);
    vInput.push_back(999);
    vInput.push_back(1000);
    vInput.push_back(999999);
    vInput.push_back(999993);
    
    cout << solution(vInput) << endl;
    
    return 0;
}
