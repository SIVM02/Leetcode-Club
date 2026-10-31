/*
 * DATE: 29/10/2026
 *
 * PROBLEM LINK: https://leetcode.com/problems/maximize-sum-after-at-most-k-digit-rearrangements/description/
 * PROBLEM STATEMENT: 
 *          You are given an integer array nums of length n and an integer k.
In one operation, you may choose any element of nums and rearrange its decimal digits in any order to form a new integer.
Return the maximum possible sum of the array after performing at most k operations.

Example 1:
Input: nums = [123,45], k = 1
Output: 366
Explanation:
We choose nums[0] = 123 and rearrange its digits to form 321.
The array becomes [321, 45]. Thus, the total sum is 321 + 45 = 366.

Example 2:
Input: nums = [102,90,14], k = 2
Output: 341
Explanation:
We choose nums[0] = 102 and rearrange its digits to form 210.
We choose nums[2] = 14 and rearrange its digits to form 41.
The array becomes [210, 90, 41]. Thus, the total sum is 210 + 90 + 41 = 341.
 
Constraints:
1 <= n == nums.length <= 10^5
1 <= nums[i] <= 10^9
1 <= k <= n

 * __________________________________________________
 * Write statement notes here
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 * 
 *       1. GREEDY + SORTING:
 *          Calculate the maximum possible number by sorting
 *          its digits in descending order.
 *
 *       2. CONTRIBUTION / GAIN:
 *          gain[i] = maximumNumber - nums[i]
 *
 *       3. INDEPENDENT OPERATIONS:
 *          Each operation affects only one element, so gains
 *          can be calculated independently.
 *
 *       4. MAXIMUM K BENEFITS:
 *          Sort gains in descending order and select the
 *          largest K gains.
 *
 *       5. FINAL ANSWER:
 *          Original Sum + Sum of K Largest Gains.
 *
 *       6. COMPLEXITY:
 *          Time: O(N log N)
 *          Space: O(N)
 *
 *       7. PATTERN TO REMEMBER:
 *          Whenever K independent operations provide different
 *          benefits, calculate each benefit and greedily choose
 *          the K largest.
 *
 *      
 * __________________________________________________
 * Write insights here
 * __________________________________________________
 *
 */

class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        // 525 WEEKLY CONTEST 2nd PROBLEM.
        // NOT ABLE TO SOLVED DURING CONTEST.
        // NOT UNDERSTAND QUESTION DURING CONTEST.
        // REATTEMPT AFTER CONTEST.
        // Question ye kah raha h ki terepe ek array {nums} h or ek K value h, or us array me se humlog k values ko arrange kar sakte h {Arrange means = digit position change} and array me se every element ko sum kare to maximum aaye. 
        int n = nums.size();
        long long sum = 0;
        for(long long i = 0 ; i < n ; i++){
            sum = sum + nums[i];
        }
        vector<int> digitStorage;
        vector<int> maxDiff;
        for(int i = 0 ; i < n ; i++){
            int temp = nums[i];
            while(temp > 0){
                int digit = temp % 10;
                digitStorage.push_back(digit);
                temp = temp / 10;
            }
            sort(digitStorage.begin() , digitStorage.end(), greater<long long>());
            long long maximumNumber = 0;
            for(int j = 0 ; j < digitStorage.size() ; j++){
                maximumNumber = digitStorage[j] + maximumNumber * 10;
            }
            maxDiff.push_back(maximumNumber - nums[i]);
            digitStorage.clear();
        }
        sort(maxDiff.begin(), maxDiff.end(), greater<long long>());
        for(long long i = 0 ; i < k ; i++){
            sum = sum + maxDiff[i];
        }
        return sum;
    }
};