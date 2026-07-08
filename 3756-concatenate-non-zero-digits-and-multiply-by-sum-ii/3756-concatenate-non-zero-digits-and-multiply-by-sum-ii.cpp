class Solution {
public:
    typedef long long ll;
    const int M = 1e9+7;
    class node {
        public:
        ll val;
        int len;
        ll sum;
        node(ll v = 0,int l = 0,ll s = 0) {
            val = v;
            len = l;
            sum = s;
        }
    };
    int n;
    vector<node>seg;
    vector<ll> pow10;
    node merge(node &left, node &right) {
        node res;
        res.val = (left.val * pow10[right.len] + right.val) % M;
        res.len = left.len + right.len;
        res.sum = left.sum + right.sum;
        return res;
    }
    void build(int l,int r,int i,string &s) {
        if(l == r) {
            int d = s[l] - '0';
            if (d == 0)
                seg[i] = node(0, 0, 0);
            else
                seg[i] = node(d, 1, d);
            return;
        }
        int mid = l + (r-l)/2;
        build(l,mid,2*i+1,s);
        build(mid+1,r,2*i+2,s);
        seg[i] = merge(seg[2*i + 1], seg[2*i + 2]);
    }
    node solve(int s,int e,int l,int r,int i) {
        if(r < s || l > e) 
            return node();
        if(s >= l && e <= r)
            return seg[i];
        int mid = s + (e-s)/2;
        node leftNo = solve(s,mid,l,r,2*i+1);
        node rightNo = solve(mid+1,e,l,r,2*i+2);
        return merge(leftNo,rightNo);
    }
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {   
        n = s.size();
        seg.resize(4*n);
        pow10.resize(n + 1);
        pow10[0] = 1;
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % M;
        build(0,n-1,0,s);
        vector<int>res;
        for(auto &query : queries) {
            int l = query[0];
            int r = query[1];
            node ans = solve(0,n-1,l,r,0);
            res.push_back(1LL*ans.val * ans.sum % M );
        }
        return res;
    }
};