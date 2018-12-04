class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
        int product = nums[0];
        int startIdx = 0;
        int endIdx = 0;
        int minProduct, maxProduct = 0;
        int p1, p2;
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        p1 = nums[0] * nums[1] * nums[n-1]; // For the case where we have large negative numbers.
        p2 = nums[n -3] * nums[n-2] * nums[n-1];
        
        return max(p1, p2);
    }
};
