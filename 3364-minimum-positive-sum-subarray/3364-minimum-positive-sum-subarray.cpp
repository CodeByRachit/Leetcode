class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int start = 0 , end = 0;
        int Min = INT_MAX;
        int sum = 0;
        while(end < nums.size())
        {
            sum += nums[end];
            int len = end - start + 1;
            if(len >= l && len <= r)
            {
                if(sum > 0 && sum < Min)
                        Min = sum;
            }
            if(len == r || end == nums.size() - 1)
            {
                start++;
                end = start;
                sum = 0;
            }
            else
                end++;
        }
        if(Min == INT_MAX)
            return -1;
        return Min;
    }
};