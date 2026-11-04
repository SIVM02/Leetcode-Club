/*
 * DATE: 05/11/2026
 *
 * PROBLEM LINK: https://leetcode.com/problems/max-consecutive-ones/description/
 * PROBLEM STATEMENT:
 *        Given a binary array nums, return the maximum number of consecutive 1's in the array.

Example 1:
Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.

Example 2:
Input: nums = [1,0,1,1,0,1]
Output: 2
 
Constraints:
1 <= nums.length <= 10^5
nums[i] is either 0 or 1.

 * __________________________________________________
 * Write statement notes here
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 * 
 *          1} Consecutive counting technique: Whenever we encounter 1, increment the count variable to track the current sequence of consecutive ones.

            2} Counter reset technique: Whenever we encounter 0, reset count = 0 because the consecutive sequence of ones is broken.

            3} Maintain maximum count: Use a separate variable max to store the maximum number of consecutive ones found so far.

            4} Update maximum continuously: After processing each element, compare the current count with max.
                    if(max < count){
                        max = count;
                    }
              This ensures that we never lose track of the longest sequence.

            5} Two variables, two responsibilities:

                    count → Tracks the current consecutive sequence.
                    max → Tracks the longest consecutive sequence found so far.

            6} No need for nested loops: A single traversal is sufficient to solve this problem efficiently.

            7} Important observation: We must update max before resetting count when we encounter 0. Otherwise, we might lose the count of the previous sequence.

            8} Edge cases:
                All elements are 1 → Answer is the array size.
                All elements are 0 → Answer is 0.
                Only one 1 → Answer is 1.
                Consecutive ones at the end of the array → Still counted correctly.


 * __________________________________________________
 * Write insights here
 * __________________________________________________
 *
 */

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0 ;
        int max = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 1){
                count++;
            }
            if(max < count){
                max = count;
            }
            if(nums[i] == 0){
                count = 0 ;
            }
        }
        return max;
    }
};