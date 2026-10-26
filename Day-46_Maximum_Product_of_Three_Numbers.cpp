/*
 * DATE: 26/10/2026
 *
 * PROBLEM LINK: https://leetcode.com/problems/maximum-product-of-three-numbers/description/
 * PROBLEM STATEMENT:
 *              You are given an integer array nums. Find three numbers whose product is maximum and return the maximum product.

Example 1:
Input: nums = [1,2,-3]
Output: -6
Explanation:
The only three numbers are 1, 2, and -3, so the maximum product is 1 * 2 * -3 = -6.

Example 2:
Input: nums = [1,2,3,4]
Output: 24
Explanation:
The largest product comes from the three greatest numbers: 2 * 3 * 4 = 24.

Example 3:
Input: nums = [-1,-2,-3]
Output: -6
Explanation:
The only three numbers are -1, -2, and -3, so the maximum product is (-1) * (-2) * (-3) = -6.

Constraints:
3 <= nums.length <= 104
-1000 <= nums[i] <= 1000

 * __________________________________________________
 * Write statement notes here
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 *          - Don't forget negative numbers! Two big negative numbers multiplied together become a big positive number.
 *          - The maximum answer is always one of two choices:
 *              1. First 2 numbers * Last number (handles two big negatives)
 *              2. Last 3 numbers (handles all positives or all negatives)
 *          - Sorting makes it super easy to grab the smallest and largest numbers without searching manually.
 * __________________________________________________
 * Write insights here
 * __________________________________________________
 * // When I free i think different approaches, Other than sorting.
 */

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // I sort the array by help of inbuild function
        sort(nums.begin() , nums.end());
        // Count the number of digit in a array 
        int n = nums.size(); 
        // if Negative number is present so we calculate the product of starting two then product with last.
        //EXAMPLE:- [-100 , -99 , 1, 2, 3]
        int product1 = nums[0] * nums[1] * nums[n-1];
        // If negative is not present then product of last 3 element is the largest. 
        int product = nums[n-3] * nums[n-2] * nums[n-1]; 
        // we compare both the largest then return largest.
        if(product1 > product){
            return product1;
        }
        return product;
    }
};