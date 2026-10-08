/*
 * DATE: 08/10/2026
 *
 * PROBLEM LINK: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 * PROBLEM STATEMENT:
 *    You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
 
Constraints:
1 <= prices.length <= 10^5
0 <= prices[i] <= 10^4


 * __________________________________________________
 * Write statement notes here
 * --> Single Transaction: You can only buy once and sell once.
 * --> Time Direction: You must buy before you sell (buyday < sellday).
 * --> Return 0 if prices continuously decrease (no profitable trade possible).
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 *    Space & Time Complexity:
*         -->Time Complexity: O(N) — single traversal through the vector.
*         -->Auxiliary Space Complexity: O(1) — constant extra space using variables.
 * __________________________________________________
 * Write insights here
 * __________________________________________________
 *
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int buyPrice = prices[0];

        for(int i = 1 ; i < prices.size() ; i++){
            if(prices[i] < buyPrice){
                buyPrice = prices[i];
            }
            if(prices[i] - buyPrice > profit){
                profit = prices[i] - buyPrice ;
            }
        }
        return profit;
    }
};