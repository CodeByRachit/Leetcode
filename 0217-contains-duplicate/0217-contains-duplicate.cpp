class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> d; 
        for (int num : nums){
            d[num]++;
            if (d[num] > 1){
                return true;
            }
        }
    return false;
    }
};