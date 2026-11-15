/*
 * DATE: 13/11/2026
 *
 * PROBLEM LINK: https://leetcode.com/problems/add-two-integers/description/
 * PROBLEM STATEMENT:
 *          Given two integers num1 and num2, return the sum of the two integers.

Example 1:
Input: num1 = 12, num2 = 5
Output: 17
Explanation: num1 is 12, num2 is 5, and their sum is 12 + 5 = 17, so 17 is returned.

Example 2:
Input: num1 = -10, num2 = 4
Output: -6
Explanation: num1 + num2 = -6, so -6 is returned.

Constraints:
-100 <= num1, num2 <= 100

 * __________________________________________________
 * Write statement notes here
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 *         
 *          Use the + operator to directly add two integers.
            No loops or extra variables are required.
            The same approach works for both positive and negative integers.
            Pattern: Basic Arithmetic Operation.

            Complexity:
                Time:O(1)
                Space:O(1)
 * __________________________________________________
 * Write insights here
 * __________________________________________________
 *
 */

class Solution {
public:
    int sum(int num1, int num2) {
        return num1 + num2;
    }
};