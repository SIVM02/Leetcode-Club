/*
 * DATE: 02/11/2026
 *
 * PROBLEM LINK: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-iii/description/
 * PROBLEM STATEMENT:
 *          You are given an integer array nums.
In one move, you may increase the value of any single element nums[i] by 1.
Return the minimum total number of moves required so that all elements in nums become equal.

Example 1:
Input: nums = [2,1,3]
Output: 3
Explanation:
To make all elements equal:
Increase nums[0] = 2 by 1 to make it 3.
Increase nums[1] = 1 by 1 to make it 2.
Increase nums[1] = 2 by 1 to make it 3.
Now, all elements of nums are equal to 3. The minimum total moves is 3.

Example 2:
Input: nums = [4,4,5]
Output: 2
Explanation:
To make all elements equal:
Increase nums[0] = 4 by 1 to make it 5.
Increase nums[1] = 4 by 1 to make it 5.
Now, all elements of nums are equal to 5. The minimum total moves is 2.

Constraints:
1 <= nums.length <= 100
1 <= nums[i] <= 100

 * __________________________________________________
 * Write statement notes here
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 *              1} Target should be the maximum element: Since we are only allowed to increase elements (never decrease them), the optimal final value must be the maximum element in the array.

              2}Greedy Approach: Make every element equal to the largest element. This guarantees the minimum number of moves.

              3} Two-pass approach:
                  First traversal: Find the maximum element.
                  Second traversal: Calculate the difference between the maximum and every element and add it to the total moves.

              4} No sorting required: We only need the maximum element, so sorting the array would be unnecessary and less efficient.

              5} Avoid unnecessary variables: Instead of using an additional count variable, directly add the difference to sum:
                    sum += largest - nums[i];
              
              6} Edge case: If all elements are already equal, the answer is 0. If the array contains only one element, the answer is also 0.

              7} Complexity Analysis
                    Time Complexity: O(n) — Two traversals of the array.
                    Space Complexity: O(1) — Only a few variables are used; no extra data structure is required.
 * __________________________________________________
 * Write insights here
 * __________________________________________________
 *
 */

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int largest = nums[0] ;
        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] > largest){
                largest = nums[i];
            }
        }
        int sum = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            int count = 0 ;
            if(nums[i] < largest){
                count = largest - nums[i];
                sum = sum + count;
            }
        }
        return sum ;
    }
};