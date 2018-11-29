class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {    
        int count =0;
        int maxCount = 0;
        
        for (int i =0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                count +=1;    
                maxCount = max(maxCount, count);
            }
            else
            {
                cout << "count" << count << endl;
                maxCount = max(maxCount, count);
                count = 0;
            }
        }
        
        return maxCount;
        
    }
};
