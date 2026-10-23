/*
 * DATE: 24/10/2026
 *
 * PROBLEM LINK: https://leetcode.com/problems/longest-consecutive-sequence/description/
 * PROBLEM STATEMENT:
 *        Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.
// I solve it in a o(nlogn).

Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Example 3:
Input: nums = [1,0,1,2]
Output: 3

Constraints:
0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9

 * __________________________________________________
 * Write statement notes here
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 *        POINTS:-
 *            1} Sorting Strategy: Sorting makes consecutive numbers sit next to each other, changing a complex search into an easy linear scan.
              2} Handle Duplicates: Skip identical numbers using continue so they don't break your counting logic.
              3} Reset Streak Properly: When a sequence breaks (else), reset count to 1 (because the current element starts a new potential sequence).
              4} Track the Best: Keep a separate maximum variable to update and store the longest streak found so far.
              5} Guard Edge Cases: Always check if nums.size() == 0 at the very start to avoid runtime errors.
 * __________________________________________________
 * Write insights here
 * __________________________________________________
 *
 */

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // check the nums is empty or not.
        // if empty then return 0.
        if(nums.size() == 0){
            return 0;
        }
        // we sort the array by the help of inbuild sort function.
        sort(nums.begin() , nums.end());
        // count the size of array
        int n = nums.size();
        // let suppose the maximum and count is 1.
        int maximum = 1;
        int count = 1 ;
        for(int i = 1 ; i < n ; i++){
            // Edge case:- we check if the element is same continue then i skip it. 
            if(nums[i-1] == nums[i]){
                continue;
            }
            // if compare the continuous element and increase the count.
            if(nums[i] == nums[i-1] + 1  ){
                count++;
            }
            // if element is not same then count become 1.
            else {
                count = 1;
            }
            // if count is increase then maximum change each time.
            if(count > maximum){
                maximum = count;
            }
        }
        // at the end return the maximum count.
        return maximum;
    }
};