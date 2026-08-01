class Solution {
public:
    int solve(int i, int j, vector<int>& nums) {
        if (i == j)
            return nums[i];
        int left = nums[i] - solve(i + 1, j, nums);
        int right = nums[j] - solve(i, j - 1, nums);
        return max(left, right);
    }
    bool predictTheWinner(vector<int>& nums) {
        int ans = solve(0, nums.size() - 1, nums);
        return ans >= 0;
    }
};