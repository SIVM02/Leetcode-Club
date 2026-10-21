/*
 * DATE: 21/10/2026
 *
 * PROBLEM LINK: https://leetcode.com/problems/search-insert-position/description/
 * PROBLEM STATEMENT:
 *          Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1

Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4

Constraints:
1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104

 * __________________________________________________
 * Write statement notes here
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 * __________________________________________________
 * Write insights here
 *      Sorted arrays allow Binary Search — O(log n) instead of linear search — O(n).
        Find the first element greater than or equal to the target.
        If the target is greater than all elements, return nums.size().
        When binary search ends without finding the target, return left as the insertion index.
        Complexity: Time O(log n), Space O(1).
 * __________________________________________________
 *
 */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i;
        for(i = 0 ; i < nums.size() ; i++){
            if(nums[i] == target){
                return i;
            }
            if(nums[i] > target){
                return i;
            }
        }
        return i ;
    }
};