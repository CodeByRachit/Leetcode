class Solution {
    vector<int> suffix;
    vector<vector<int>> memo;
    int pileCount;
    int bestScore(int index, int currentM) {
        if (index + 2 * currentM >= pileCount) {
            return suffix[index];
        }
        int& answer = memo[index][currentM];
        if (answer != -1) {
            return answer;
        }
        answer = 0;
        for (int taken = 1; taken <= 2 * currentM; ++taken) {
            int nextM = max(currentM, taken);
            int opponentScore = bestScore(index + taken, nextM);
            answer = max(answer, suffix[index] - opponentScore);
        }
        return answer;
    }
public:
    int stoneGameII(vector<int>& piles) {
        pileCount = piles.size();
        suffix.assign(pileCount + 1, 0);
        for (int index = pileCount - 1; index >= 0; --index) {
            suffix[index] = piles[index] + suffix[index + 1];
        }
        memo.assign(pileCount, vector<int>(pileCount + 1, -1));
        return bestScore(0, 1);
    }
};