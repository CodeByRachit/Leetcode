class Solution {
public:
    int Gcd(int a, int b) {
        while (b != 0) {
            int rem = a % b;
            a = b;
            b = rem;
        }
        return a;
    }
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd(n);
        prefixGcd[0] = nums[0];
        int mx = nums[0];
        for (int i = 1; i < n; i++) {
            mx = max(mx, nums[i]);
            prefixGcd[i] = Gcd(mx, nums[i]);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        long long sum = 0;
        int i = 0;
        int j = n - 1;
        while (i < j) {
            sum += Gcd(prefixGcd[i], prefixGcd[j]);
            i++;
            j--;
        }
        return sum;
    }
};