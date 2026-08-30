class Solution {
public:
    int minimumDeletions(vector<int>& A) {
        int n = A.size();
        int mini = min_element(A.begin(), A.end()) - A.begin();
        int maxi = max_element(A.begin(), A.end()) - A.begin();
        int left = min(mini, maxi);
        int right = max(mini, maxi);
        int option1 = right + 1;
        int option2 = n - left;
        int option3 = (left + 1) + (n - right);
        return min({option1, option2, option3});
    }
};