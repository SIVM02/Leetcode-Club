/*
 * DATE: 02/10/2026
 *
 * PROBLEM LINK: https://leetcode.com/problems/missing-number/description/?envType=problem-list-v2&envId=math
 * PROBLEM STATEMENT: 
 * 
 *      Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

Example 1:
Input: nums = [3,0,1]
Output: 2

Explanation:
n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.

Example 2:
Input: nums = [0,1]
Output: 2

Explanation:
n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.

Example 3:
Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8

Explanation:
n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.

Constraints:
n == nums.length
1 <= n <= 10^4
0 <= nums[i] <= n
All the numbers of nums are unique.


 * __________________________________________________
 * Write statement notes here
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 * 
 *        Since nums.length = n, the expected numbers are 0 to n.
 *        Expected sum of 0 to n = n * (n + 1) / 2.
 *        Actual sum = sum of all elements in nums.
 *        Missing number = expectedSum - actualSum.
 *         
 *        Time complexity: O(n)
 *        Space complexity: O(1)
 * __________________________________________________
 * Write insights here
 *      We have n distinct numbers from the range [0, n].
 *      Exactly one number is missing.
 *      Need to find the missing number.
 * __________________________________________________
 *
 */

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int actualSum = 0;
        int n = nums.size();
        int expectedSum = n * (n + 1) / 2;
        for(int i = 0 ; i < n ; i++){
            actualSum = actualSum + nums[i];
        }
        int missingNum = expectedSum - actualSum;
        return missingNum ;
    }
};