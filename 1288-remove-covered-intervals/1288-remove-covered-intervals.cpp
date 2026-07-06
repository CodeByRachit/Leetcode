class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 1) return intervals.size();
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        });
        int i = 0, j = 1, nbInt = intervals.size();
        while (i < intervals.size() && j < intervals.size()) {
            if (intervals[i][1] >= intervals[j][1]) {
                nbInt--;
                j++;
            } else {
                i = j;
                j++;
            }
        }
        return nbInt;
    }
};