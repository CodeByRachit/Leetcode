class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int firstBuy = -prices[0];
        int firstSell = 0;
        int secondBuy = -prices[0];
        int secondSell = 0;
        for (int price : prices){
            firstBuy = max(firstBuy, -price);
            firstSell = max(firstSell, firstBuy + price);
            secondBuy = max(secondBuy, firstSell - price);
            secondSell = max(secondSell, secondBuy + price);
        }
        return secondSell;
    }
};