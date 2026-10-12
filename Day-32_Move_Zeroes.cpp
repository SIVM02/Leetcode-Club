/*
 * DATE: 12/10/2026
 *
 * PROBLEM LINK: https://leetcode.com/problems/move-zeroes/description/
 * PROBLEM STATEMENT:
 * 
 *      Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:
Input: nums = [0]
Output: [0]
 
Constraints:
1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1


 * __________________________________________________
 * Write statement notes here
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 *      1. Use two pointers: i (read), j (write).
 *      2. Move non-zero elements to the front, preserving order.
 *      3. Fill remaining positions with zeroes.
 *      4. Modify the original array (in-place).
 *
 * PATTERN: Two Pointers
 *      TIME: O(n)
 *      SPACE: O(1)
 *
 * KEY IDEA:
 *      Skip zeroes, copy non-zero elements forward,
 *      then fill the remaining positions with zeroes.
 * __________________________________________________
 * Write insights here
 * __________________________________________________
 *
 */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for(int i = 0 ; i< nums.size(); i++){
            if(nums[i] != 0){
                nums[j] = nums[i];
                j++;
            }
        }
        for(int i = j; i < nums.size() ; i++){
            nums[i] = 0;
        }
    }
};