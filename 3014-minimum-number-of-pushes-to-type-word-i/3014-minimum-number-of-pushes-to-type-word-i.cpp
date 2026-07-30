class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int count=1;
        int res=0;
        if(n<=8) return n;
        if(n>8 &&n<=16){
            return ((n-8)*2)+8;
        }
        if(n>16 && n<=24){
              return ((n-16)*3)+24;
        }
        return ((n-24)*4)+48;
    }
};