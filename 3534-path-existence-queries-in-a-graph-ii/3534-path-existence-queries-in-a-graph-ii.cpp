class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> comb;
        for(int i = 0 ; i < n ; i++){
            comb.push_back({nums[i],i});
        }
        sort(comb.begin(),comb.end());
        vector<int> pos(n);
        for(int i = 0 ; i < n ; i++){
            pos[comb[i].second] = i;
        }
        vector<int> next(n);
        int r = 0;
        for(int l = 0 ; l < n ; l++){
            if(l > r){
                r = l;
            }
            while((r+1 < n) && (comb[r+1].first - comb[l].first) <= maxDiff){
                r++;
            }
            next[l] = r;
        }
        int LOG = ceil(log2(n))+1;
        vector<vector<int>> up(n , vector<int>(LOG));
        for (int i = 0; i < n; i++) {
            up[i][0] = next[i];
        }
        for(int i = 1 ; i < LOG ; i++){
            for(int j = 0 ; j < n ; j++){
                up[j][i] = up[up[j][i-1]][i-1];
            }
        }
        vector<int> ans;
        for(int i = 0; i < queries.size(); i++){
            int src = queries[i][0];
            int dest = queries[i][1];
            src = pos[src];
            dest = pos[dest];
            if(src > dest) swap(src,dest);
            else if(src == dest){
                ans.push_back(0);
                continue;
            }
            int jumps = 0;
            int cur = src;
            for(int i = LOG-1 ; i >= 0 ; i--){
                if(up[cur][i] < dest){
                    cur = up[cur][i];
                    jumps += (1<<i);
                }
            }
            if(up[cur][0] >= dest){
                ans.push_back(jumps+1);
            }
            else ans.push_back(-1);
        }
        return ans;
    }
};