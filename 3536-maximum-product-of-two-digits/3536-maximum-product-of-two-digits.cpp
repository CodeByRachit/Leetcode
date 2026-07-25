class Solution {
public:
    int maxProduct(int n) {
        int num1 = 0, num2 = 0;
        while(n != 0) {
            int digit = n % 10;
            if(num1 < digit) {
                if(num1 > num2) num2 = num1;
                num1 = digit;
            }
            else if(num2 < digit)
                num2 = digit;

            n /= 10;
        }
        return num1 * num2;
    }
};