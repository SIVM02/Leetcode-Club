/*
 * DATE: 06/11/2026
 *
 * PROBLEM LINK: https://leetcode.com/problems/sum-of-squares-of-special-elements/description/
 * PROBLEM STATEMENT:
 *            You are given a 1-indexed integer array nums of length n.
An element nums[i] of nums is called special if i divides n, i.e. n % i == 0.
Return the sum of the squares of all special elements of nums.

Example 1:
Input: nums = [1,2,3,4]
Output: 21
Explanation: There are exactly 3 special elements in nums: nums[1] since 1 divides 4, nums[2] since 2 divides 4, and nums[4] since 4 divides 4. 
Hence, the sum of the squares of all special elements of nums is nums[1] * nums[1] + nums[2] * nums[2] + nums[4] * nums[4] = 1 * 1 + 2 * 2 + 4 * 4 = 21.  

Example 2:
Input: nums = [2,7,1,19,18,3]
Output: 63
Explanation: There are exactly 4 special elements in nums: nums[1] since 1 divides 6, nums[2] since 2 divides 6, nums[3] since 3 divides 6, and nums[6] since 6 divides 6. 
Hence, the sum of the squares of all special elements of nums is nums[1] * nums[1] + nums[2] * nums[2] + nums[3] * nums[3] + nums[6] * nums[6] = 2 * 2 + 7 * 7 + 1 * 1 + 3 * 3 = 63. 
 
Constraints:

1 <= nums.length == n <= 50
1 <= nums[i] <= 50
 * __________________________________________________
 * Write statement notes here
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 *            1} 1-based vs 0-based indexing: The problem uses 1-based indexing, whereas C++ vectors use 0-based indexing. Therefore, we use:
 *                  int actual_index = i + 1;
 *                This converts the vector index into the actual position mentioned in the problem.
               
              2} Divisibility concept: An element is special if its 1-based index divides the array length n.
                    if(n % actual_index == 0)
              If the remainder is 0, the index is a divisor of n.

              3} Square of an element: Whenever we find a special element, calculate its square:
                    product = nums[i] * nums[i];
              
              4} Accumulate the answer: Add the square of every special element to soln.
                    soln = soln + product;
              
              5} Single traversal: We don't need sorting, nested loops, or any extra data structure. We can check every index in one traversal.

              6} Important observation: We are checking whether the index divides the array length, not whether the array length divides the index.
                    n % actual_index == 0
              
              7} Variable initialization: Always initialize the answer variable with 0 because we are calculating a sum.

              8} Avoid unnecessary variables: We can directly write:
                      soln += nums[i] * nums[i];
                  This eliminates the need for the additional product variable.

 * __________________________________________________
 * Write insights here
 * __________________________________________________
 *
 */

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int product ;
        int soln = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            int actual_index = i+1;
            if(n % actual_index == 0){
                product = nums[i] * nums[i];
                soln = soln + product;
            }
        }
        return soln ;
    }
};