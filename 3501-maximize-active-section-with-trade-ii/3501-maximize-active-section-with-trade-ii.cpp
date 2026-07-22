class SegmentTree{
    public:
    vector<int>seg;
    SegmentTree(int n){
        seg.resize(4*n);
    }
    void build(int i,int l,int r,vector<int>&nums){
        if(l==r){
           seg[i]=nums[l];
           return;
        }
        int mid=l+(r-l)/2;
        build(2*i+1,l,mid,nums);
        build(2*i+2,mid+1,r,nums);
        seg[i]=max(seg[2*i+1],seg[2*i+2]);
        return;
    }
    int query(int i,int left,int right,int l,int r){
        if(left>right) return 0;
        if(right<l || r<left) return 0;
        else if(left<=l && r<=right) return seg[i];
        int mid=l+(r-l)/2;
        int leftMax=query(2*i+1,left,right,l,mid);
        int rightMax=query(2*i+2,left,right,mid+1,r);
        return max(leftMax,rightMax);
    }
};
class Solution {
public:
    int n;
    int findLowerBound(int target,vector<int>&nums){
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>=target){
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
    int findUpperBound(int target,vector<int>&nums){
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>target){
                high=mid-1;
            }else low=mid+1;
        }
        return low;
    }
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        this->n=s.size();
        int totalOnes=0;
        for(auto it:s) totalOnes+=it-'0';
        vector<int>zerosLeft,zerosRight,zerosLen;
        int st=0;
        while(st<n){
            int e=st;
            while(e<n && s[e]==s[st]) e++;
            if(s[st]=='0'){
                zerosLeft.emplace_back(st);
                zerosRight.emplace_back(e-1);
                zerosLen.emplace_back(e-st);
            }
            st=e;
        }
        int m=zerosLen.size();
        if(m<=1){
            int q=queries.size();
            vector<int>ans(q,totalOnes);
            return ans;
        }
        vector<int>nums;
        for(int i=1;i<zerosLen.size();i++) nums.emplace_back(zerosLen[i-1]+zerosLen[i]);
        SegmentTree ST=SegmentTree(nums.size());
        ST.build(0,0,nums.size()-1,nums);
        vector<int>ans;
        for(auto it:queries){
            int l=it[0],r=it[1];
            int maxi=totalOnes;
            int leftIdx=findLowerBound(l,zerosRight);
            int rightIdx=findUpperBound(r,zerosLeft)-1;
            if(leftIdx>=m || rightIdx<0 || leftIdx>=rightIdx){
                ans.emplace_back(maxi);
                continue;
            }
            int leftLen=zerosRight[leftIdx]-max(l,zerosLeft[leftIdx])+1;
            int rightLen=min(zerosRight[rightIdx],r)-zerosLeft[rightIdx]+1;
            if(leftIdx+1==rightIdx){
                ans.emplace_back(totalOnes+leftLen+rightLen);
                continue;
            }
            int leftCont=leftLen+zerosLen[leftIdx+1];
            int rightCont=zerosLen[rightIdx-1]+rightLen;
            int middleCont=ST.query(0,leftIdx+1,rightIdx-2,0,nums.size()-1);
            maxi=totalOnes+max({leftCont,rightCont,middleCont});
            ans.emplace_back(maxi);
        }
        return ans;
    }
};