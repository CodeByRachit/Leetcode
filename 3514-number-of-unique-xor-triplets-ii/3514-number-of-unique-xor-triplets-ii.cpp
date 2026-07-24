class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> l1, l2;
        unordered_set<int> st;
        for(int i=0; i<n; i++){
            if(l1.contains(nums[i])) continue;
            l1.insert(nums[i]);
            for(int j=i; j<n; j++){
                int val=nums[i] xor nums[j];
                if(l2.contains(val)) continue;
                l2.insert(val);
                for(int k=j; k<n; k++){
                    st.insert(nums[i] xor nums[j] xor nums[k]);
                }
            }
        }
        return st.size();
    }
};