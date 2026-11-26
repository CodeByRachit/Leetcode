class Solution {
public:
    bool canAliceWin(int n) {
        int i = 10;
        while(n >=0){
            n = n-i;
            i--;
        }
        if(i%2 == 0){
            return true;
        }
        return false;
    }
};