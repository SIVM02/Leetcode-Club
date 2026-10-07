/*
 * DATE: 07/10/2026
 *
 * PROBLEM LINK: https://leetcode.com/problems/number-of-good-pairs/description/
 * PROBLEM STATEMENT:
 *        Given an array of integers nums, return the number of good pairs.

A pair (i, j) is called good if nums[i] == nums[j] and i < j.

Example 1:
Input: nums = [1,2,3,1,1,3]
Output: 4
Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.

Example 2:
Input: nums = [1,1,1,1]
Output: 6
Explanation: Each pair in the array are good.

Example 3:
Input: nums = [1,2,3]
Output: 0
 

Constraints:
1 <= nums.length <= 100
1 <= nums[i] <= 100


 * __________________________________________________
 * Write statement notes here
 *    1}Brute force approach is Use two loop.
 *    2} This avoids counting the same pair twice.
 *       Example: (0,3) is counted, so we don't need (3,0).
 *    3} Two nested loops give O(n²) time and O(1) extra space.
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 * __________________________________________________
 * Write insights here
 * __________________________________________________
 *
 */

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count = 0;
        for(int i = 0 ; i < nums.size() - 1; i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] == nums[j]){
                    count++;
                }
            }
        }
        return count;
    }
};
