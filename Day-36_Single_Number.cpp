/*
 * DATE: 16/10/2026
 *
 * PROBLEM LINK: https://leetcode.com/problems/single-number/description/
 * PROBLEM STATEMENT:
 *        Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:
Input: nums = [2,2,1]
Output: 1

Example 2:
Input: nums = [4,1,2,1,2]
Output: 4

Example 3:
Input: nums = [1]
Output: 1

Constraints:
1 <= nums.length <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
Each element in the array appears twice except for one element which appears only once.

 * __________________________________________________
 * Write statement notes here
 *        --> Sorting places duplicate elements next to each other.
          --> Time complexity: O(n)
          --> Extra space: O(1)
          --> If all pairs match, the single element is nums.back().
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
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1 ; i+=2){
            if(nums[i] != nums[i + 1]){
                return nums[i];
            }
        }
        return nums.back();
    }
};
