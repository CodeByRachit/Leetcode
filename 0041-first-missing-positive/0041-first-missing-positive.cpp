class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int index = 0; index < n; index++){
            while (nums[index] >= 1 && nums[index] <= n && nums[nums[index]-1] != nums[index]){
                int correctIndex = nums[index] - 1;
                swap(nums[index], nums[correctIndex]);
            }
        }
        for (int index = 0; index < n; index++){
            if (nums[index] != index +1){
                return index +1;
            }
        }
        return n + 1;
    }
};