class Solution {
public:
    bool sumGame(string num) {
        int n = num.length() - 1;
        int s = 0;
        int e = n - 1;
        int mid = s + (e - s)/2;
        int lques = 0;
        int lsum = 0;
        int rques = 0; 
        int rsum = 0;
        for(int i = 0; i < num.length(); i++){
            if (i <= mid){
                num[i] == '?' ? lques += 1 : lsum += (num[i] - '0'); 
            }
            else{
                num[i] == '?' ? rques += 1 : rsum += (num[i] - '0');
            }
        }
        int totalques = lques + rques;
        if (totalques == 0){
            return lsum == rsum ? false : true;
        }
        if (lques == rques){
            return lsum == rsum ? false : true; 
        }
        if (totalques % 2 != 0){
            return true;
        }
        if (abs(lsum - rsum) == (abs(lques - rques) / 2)* 9){
            if ((lsum > rsum && lques > rques) || (rsum > lsum && rques > lques) ) return true;
            return false;
        }
        return true;
    }
};