/*
 * DATE: 23/10/2026
 *
 * PROBLEM LINK: https://leetcode.com/problems/rotate-array/description/
 * PROBLEM STATEMENT:
 *            Given an integer array nums, rotate the array to the right by k steps, where k is non-negative. 

Example 1:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 
Constraints:
1 <= nums.length <= 10^5
-2^31 <= nums[i] <= 2^31 - 1
0 <= k <= 10^5
 * __________________________________________________
 * Write statement notes here
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 *      - Step 1: Reverse the entire array (puts the last k elements at the front, but backward).
 *      - Step 2: Reverse the first k elements (fixes their internal order).
 *      - Step 3: Reverse the remaining n - k elements (fixes the rest of the array's order).
 * 
 *       Modulo Operator (k = k % n): Always handle cases where k is greater than the size of the array (n). 
 *       Rotating an array by its own length brings it back to the original state.
 * __________________________________________________
 * Write insights here
 * __________________________________________________
 *
 */

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // Find the number of elements in the array
        int n = nums.size();
        // If k is greater than the array size, reduce it using modulo.
        k = k % n;

        // Reverse the complete array
        int start = 0;
        int end = n - 1;
        while(start < end){
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }

        // Reverse the first k elements to fix their order
        start = 0;
        end = k - 1;
        while(start < end){
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
        // Reverse the remaining (n - k) elements to fix their order
        start = k;
        end = n - 1;
        while(start < end){
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }

    }
};