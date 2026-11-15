/*
 * DATE: 12/11/2026
 *
 * PROBLEM LINK: https://leetcode.com/problems/sign-of-the-product-of-an-array/description/
 * PROBLEM STATEMENT:
 *        Implement a function signFunc(x) that returns:
                  1 if x is positive.
                  -1 if x is negative.
                  0 if x is equal to 0.
You are given an integer array nums. Let product be the product of all values in the array nums.
Return signFunc(product).

Example 1:
Input: nums = [-1,-2,-3,-4,3,2,1]
Output: 1
Explanation: The product of all values in the array is 144, and signFunc(144) = 1

Example 2:
Input: nums = [1,5,0,2,-3]
Output: 0
Explanation: The product of all values in the array is 0, and signFunc(0) = 0

Example 3:
Input: nums = [-1,1,-1,1,-1]
Output: -1
Explanation: The product of all values in the array is -1, and signFunc(-1) = -1
 
Constraints:
1 <= nums.length <= 1000
-100 <= nums[i] <= 100

 * __________________________________________________
 * Write statement notes here
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 *          We don't need to calculate the actual product; we only need its sign.
            If any element is 0, immediately return 0 (early exit).
            Every negative number flips the product's sign.
            Track the sign by multiplying product by -1 for every negative element.
            Pattern: Sign Tracking + Linear Traversal.

            Complexity:
                Time:O(N)
                Space:O(1)
 * __________________________________________________
 * Write insights here
 * __________________________________________________
 *
 */

class Solution {
public:
    int signFunc(int product){
        if(product < 0){
            return -1;
        }
        if(product > 0){
            return 1;
        }
        return 0;
    }
    int arraySign(vector<int>& nums) {
        long long product = 1;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 0){
                return 0;
            }
            if(nums[i] < 0){
                product = - product;
            }
        }
        return signFunc(product);
    }
};