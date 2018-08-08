#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

bool isAmicable(int input1, int input2, std::vector<int>*amicableList);
int getRealNumberTotal(int input);


int main()
{
    int range = 100000;
    std::vector<int>amicableList;

    for (int i =4; i < range; i++)
    {
        int tmp1, tmp2 = 0;

        tmp1 = getRealNumberTotal(i);
        tmp2 = getRealNumberTotal(tmp1);

        if ((isAmicable(i, tmp2, &amicableList)) && (tmp1 != i))
        {
            amicableList.push_back(tmp1);
            amicableList.push_back(tmp2);
            cout << tmp2 << "..." << tmp1 << "\n";
        } 
    }
}

int getRealNumberTotal(int input)
{
    int total = 0;


    for (int i =1; i < input; i++)
    {
        if ((input % i ) == 0)
        {
            total += i;
        }   
    }

    return total;
}

bool isAmicable(int input1, int input2, std::vector<int>*amicableList)
{
    if ((std::find(amicableList->begin(), amicableList->end(), (input1))!= amicableList->end()) ||
         (std::find(amicableList->begin(), amicableList->end(), (input2))!= amicableList->end()))
    {
        return false;
    }
    else if((input1 == input2))
    {
        return true;
    }
    else
    {
        return false;
    }
}