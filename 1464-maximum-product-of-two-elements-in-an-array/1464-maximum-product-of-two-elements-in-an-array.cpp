class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int fm = INT_MIN, sm = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            int num = nums[i]-1;
            if(num > fm){
                sm = fm;
                fm = num;
            }
            else if(num > sm){
                sm = num;
            }
        }
        return fm*sm;
    }
};