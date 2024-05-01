// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

class Solution {
    public int maxProfit(int[] prices) {
        int min_price=prices[0];
        int max_profit=0;
        for(int price:prices) {
            min_price = price<min_price ? price : min_price;
            max_profit = price-min_price>max_profit ? price-min_price : max_profit;
        }
        return max_profit;
    }
}