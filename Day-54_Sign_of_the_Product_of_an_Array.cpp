/*
 * DATE: 04/11/2026
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
 *      1. We don't need to calculate the actual product: The question only asks for the sign of the product, not its actual value. Therefore, we can avoid multiplication completely.

        2. Negative number counting technique: The product of an array is:
              Positive if the number of negative elements is even.
              Negative if the number of negative elements is odd.
              Zero if at least one element is zero.

        3. Sign flipping technique: Instead of counting negative numbers separately, we can maintain a product variable initialized to 1.
Whenever we encounter a negative number, flip the sign using product = -product.
              Positive numbers don't change the sign.

        4. Early return optimization: If we encounter 0, immediately return 0 because the product of the entire array will be zero.

        5. Avoid integer overflow: Multiplying all array elements could cause integer overflow. Tracking only the sign avoids this problem entirely.

        6. Helper function concept: We created a separate signFunc() function to determine whether the final result is positive, negative, or zero. This improves code organization and reusability.

        7. Important observation: We only care about whether the product is positive, negative, or zero. The magnitude of the product is irrelevant.
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