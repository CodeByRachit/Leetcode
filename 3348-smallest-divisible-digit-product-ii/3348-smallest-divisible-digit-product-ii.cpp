class Solution {
public:
    int c[10][4]={
        {0,0,0,0},{0,0,0,0},{1,0,0,0},{0,1,0,0},{2,0,0,0},
        {0,0,1,0},{1,1,0,0},{0,0,0,1},{3,0,0,0},{0,2,0,0}
    };
    vector<vector<vector<vector<int>>>> dp;
    int A,B,C,D;
    void build(int a,int b,int c5,int d7){
        A=a; B=b; C=c5; D=d7;
        dp.assign(A+1, vector<vector<vector<int>>>(
            B+1, vector<vector<int>>(
                C+1, vector<int>(D+1,1e9))));
        dp[0][0][0][0]=0;
        for(int x=0;x<=A;x++)
        for(int y=0;y<=B;y++)
        for(int z=0;z<=C;z++)
        for(int w=0;w<=D;w++){
            if(!x&&!y&&!z&&!w) continue;
            for(int d=2;d<=9;d++){
                int nx=max(0,x-c[d][0]);
                int ny=max(0,y-c[d][1]);
                int nz=max(0,z-c[d][2]);
                int nw=max(0,w-c[d][3]);
                dp[x][y][z][w]=min(dp[x][y][z][w],
                    1+dp[nx][ny][nz][nw]);
            }
        }
    }
    int get(vector<int>& f){
        return dp[min(f[2],A)][min(f[3],B)]
                 [min(f[5],C)][min(f[7],D)];
    }
    void rem(vector<int>& f,int d){
        f[2]=max(0,f[2]-c[d][0]);
        f[3]=max(0,f[3]-c[d][1]);
        f[5]=max(0,f[5]-c[d][2]);
        f[7]=max(0,f[7]-c[d][3]);
    }
    string fill(vector<int> f,int n){
        string s;
        for(int i=0;i<n;i++){
            for(int d=1;d<=9;d++){
                auto g=f;
                rem(g,d);
                if(get(g)<=n-i-1){
                    s+=char('0'+d);
                    f=g;
                    break;
                }
            }
        }
        return s;
    }
    string smallestNumber(string num,long long t){
        int p[]={2,3,5,7};
        vector<int> f(10);
        for(int x:p)
            while(t%x==0)
                f[x]++,t/=x;
        if(t>1) return "-1";
        build(f[2],f[3],f[5],f[7]);
        int n=num.size();
        // num itself
        if(num.find('0')==string::npos){
            auto g=f;
            for(char x:num)
                rem(g,x-'0');
            if(!g[2]&&!g[3]&&!g[5]&&!g[7])
                return num;
        }
        vector<vector<int>> pre(n+1,f);
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i];
            if(num[i]!='0')
                rem(pre[i+1],num[i]-'0');
        }
        int z=num.find('0');
        for(int i=n-1;i>=0;i--){
            if(z!=-1 && i>z) continue;
            for(int d=num[i]-'0'+1;d<=9;d++){
                auto g=pre[i];
                rem(g,d);
                if(get(g)<=n-i-1)
                    return num.substr(0,i)+
                           char('0'+d)+
                           fill(g,n-i-1);
            }
        }
        return fill(f,max(n+1,get(f)));
    }
};