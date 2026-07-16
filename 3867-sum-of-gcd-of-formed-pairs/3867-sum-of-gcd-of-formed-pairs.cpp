class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n =nums.size();
        vector<int> prevGcd(n);
        prevGcd[0]=nums[0];
        int  mx=nums[0];
        for(int i =1;i<n ;i++){
            mx=max(mx,nums[i]);
            long long gcd =__gcd(mx,nums[i]);
            prevGcd[i]=gcd ;
        }
        sort(prevGcd.begin(),prevGcd.end());
        int i =0;
        int j =n-1 ;
        long long sum =0;
        while(i<j){
           
           sum+=__gcd(prevGcd[i++],prevGcd[j--]);
        }
        return sum ;
        return 0;    
    }
};