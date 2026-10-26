/*
 * DATE: 24/10/2026
 *
 * PROBLEM LINK: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/
 * PROBLEM STATEMENT:
 *        Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such that B[i] == A[(i+x) % A.length] for every valid index i.

Example 1:
Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 2 positions to begin on the element of value 3: [3,4,5,1,2].

Example 2:
Input: nums = [2,1,3,4]
Output: false
Explanation: There is no sorted array once rotated that can make nums.

Example 3:
Input: nums = [1,2,3]
Output: true
Explanation: [1,2,3] is the original sorted array.
You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.
 
Constraints:
1 <= nums.length <= 100
1 <= nums[i] <= 100

 * __________________________________________________
 * Write statement notes here
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 * 
 *    --> The One-Drop Rule: A sorted and rotated array can only have one place where a number is smaller than the one before it (nums[i] < nums[i-1]). If it happens twice or more, it's not a valid rotated sorted array.
 *    --> Checking the Main Body: Your for loop checks every adjacent pair from index 1 to n-1 to find any drops within the array.
 *    --> Handling the Wrap-Around: Your extra if (nums[0] < nums[n-1]) check handles the rotation boundary, making sure the connection between the very last element and the first element is also accounted for.
 *    --> Early Stop for Efficiency: By checking if (count == 2) and returning false right away, your code stops running the moment it fails, keeping the time complexity at $\mathcal{O}(n)$ with no extra memory used.
 *          --> Time Complexity: O(n)
 *          --> Space Complexity: O(1)
 * __________________________________________________
 * Write insights here
 * __________________________________________________
 *
 */

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i = 1 ; i < n ; i++){
            if(nums[i] < nums[i-1]){
                count++;
            }
            if(count == 2){
                return false;
            }
        }
        if(nums[0] < nums[n-1]){
            count++;
        }
        if(count == 2){
            return false;
        }
        return true;
    }
};