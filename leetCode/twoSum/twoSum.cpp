#include <algorithm>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
     
        //Need to store index before sorting.
        vector< pair<int, int> > numsIndex;
        int j = 0; 
        int k = 0;
        
        k = (nums.size() -1);
        
        for (int i =0; i < nums.size(); i++)
        {
            pair<int, int>temp(nums[i], i);
            numsIndex.push_back(temp);
        }
        sort(numsIndex.begin(), numsIndex.end());
          
        while (j < k)
        {
            if ((numsIndex[j].first + numsIndex[k].first) == target)
            {
                vector<int> temp;
                temp.push_back(numsIndex[j].second);
                temp.push_back(numsIndex[k].second);
                cout << "return" << endl;
                return temp;
            }
            else if ((numsIndex[j].first + numsIndex[k].first) < target)
            {
                j +=1;
            }
            else
            {
                k -=1;
            }
                
        }
     
        return vector<int>(0,0);
    }
    
};
