// you can use includes, for example:
// #include <algorithm>
#include <algorithm>    // std::sort
#include <vector>       // std::vector

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int i = 1;
    
    //1. Order the vector.
    std::sort(A.begin(), A.end());
    
    for (std::vector<int>::iterator it = A.begin(); it != A.end(); ++it)
    {
        if ((i < *it) && (i != *it))
        {
            //cout << "i =" << i << endl;
            //cout << "IT = " << *it << endl;
            return i;
        }
        else if(*it < 0)
        {
            i = 1;
        }
        else
        {
            //cout << *it << endl;
            i = (*it +1);
        }
    }
    
    return i;
}
