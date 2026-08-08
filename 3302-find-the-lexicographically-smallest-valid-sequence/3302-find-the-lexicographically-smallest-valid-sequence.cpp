class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<int> sequenceSize(m, -1);
        for(int i = m - 1, j = n - 1;i >= 0;i--){
            sequenceSize[i] = n - j - 1;
            if(j >= 0 and word1[i] == word2[j])
                j--;
        }
        vector<int> res;
        bool mugetsu = false;
        int j = 0;
        for(int i = 0;i < m and j < n;i++){
            if(j == n) break;
            if(word1[i] == word2[j]){
                res.push_back(i);
                j++;
            }
            else if(!mugetsu and sequenceSize[i] >= n - j - 1){
                mugetsu = true;
                res.push_back(i);
                j++;
            }
        }
        if(j < n) return {};
        return res;
    }
};