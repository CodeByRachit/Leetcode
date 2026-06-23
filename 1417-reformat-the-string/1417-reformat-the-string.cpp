class Solution {
public:
    string reformat(string s) {
        string nums{}, alpha{};
        for(char ch : s)
            if(ch >= '0' && ch <='9')
                nums += ch;
            else
                alpha += ch;
        int nlen = nums.length(), alen = alpha.length();
        if(abs(nlen - alen) > 1)
            return "";
        string ans{};
        if(alen > nlen)
            for(int i = 0; i < alen; ++i)
            {
                if(i < alen)
                    ans += alpha[i];
                if(i < nlen)
                    ans += nums[i];
            }
        else
            for(int i = 0; i < nlen; ++i)
            {
                if(i < nlen)
                    ans += nums[i];
                if(i < alen)
                    ans += alpha[i];
            }
        return ans;
    }
};