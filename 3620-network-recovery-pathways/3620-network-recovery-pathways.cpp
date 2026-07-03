class Solution {
public:
int n;
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        n=online.size();
        vector<vector<pair<int,int>>>adj(n);
        int low=0,high=0;
        for(auto e : edges)
        {
            int u=e[0];
            int v=e[1];
            int w=e[2];
            adj[u].push_back({v,w});
            high=max(high,w);
        }

        int ans=-1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(check(adj,online,k,mid))
            {
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
    return ans;
    }

    bool check(vector<vector<pair<int,int>>>&adj, vector<bool>& online, long long k,int mid)
    {
        vector<long long>dist(n,LLONG_MAX);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});
        dist[0]=0;

        int ans=-1;
        while(!pq.empty())
        {
            auto [cost,u] = pq.top();
            pq.pop();
            if(cost>dist[u])continue;

            for(auto [v,w] : adj[u])
            {
                if(!online[v])continue;
                if(w<mid)continue;
                if(cost+w < dist[v])
                {
                    dist[v]=cost+w;
                    pq.push({dist[v],v});
                }
            }   
        }
    return dist[n-1]<=k;
    }
};