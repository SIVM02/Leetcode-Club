/*
 * DATE: 23/9/2026
 *
 * PROBLEM LINK: https://leetcode.com/problems/binary-search/description/
 * PROBLEM STATEMENT:
 *      Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Example 2:
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
 
Constraints:
1 <= nums.length <= 10^4
-10^4 < nums[i], target < 10^4
--> All the integers in nums are unique.
--> nums is sorted in ascending order.

 * __________________________________________________
 * Write statement notes here
 *      --> Focus mainly on 
 *                -->Divide the search space into two halves by finding the middle index "mid". 
                  -->Compare the middle of the search space with the key. 
                  -->If the key is found at middle, the process is terminated.
                  -->If the key is not found at middle, choose which half will be used as the next search space.
                      -> If the key is smaller than the middle, then the left side is used for next search.
                      -> If the key is larger than the middle, then the right side is used for next search.
                  -->This process is continued until the key is found or the total search space is exhausted.
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 * __________________________________________________
 * Write insights here
 * 
 *      int mid = (last - first) / 2 + first ;
 * __________________________________________________
 *
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int first = 0;
        int last = nums.size() - 1;
        while(first <= last){
            int mid = (last - first) / 2 + first ;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] > target){
                last = mid - 1;
            }
            if(nums[mid] < target){
                first = mid + 1;
            }
        }
        return -1;
    }
};