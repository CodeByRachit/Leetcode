class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> s;
        vector<int> ans;
        int maxEl = *max_element(nums.begin(), nums.end());
        int minEl = *min_element(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++) {
            s.insert(nums[i]);
        }
        for(int i=minEl; i<=maxEl; i++) {
            if(s.find(i) == s.end()) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};