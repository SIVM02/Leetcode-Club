/*
 * DATE: 20/10/2026
 *
 * PROBLEM LINK: https://leetcode.com/problems/reverse-integer/description/
 * PROBLEM STATEMENT:
 *        Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Example 1:
Input: x = 123
Output: 321

Example 2:
Input: x = -123
Output: -321

Example 3:
Input: x = 120
Output: 21

Constraints:
-231 <= x <= 231 - 1

* __________________________________________________
 * Write statement notes here
 *      1. Extract the last digit using x % 10.
 *      2. Remove the last digit using x / 10.
 *      3. Reverse the number using:
 *            rev = rev * 10 + lastDigit.
 *
 *      4. Negative numbers are handled naturally in C++.
 *
 *      5. Check INT_MIN and INT_MAX to prevent 32-bit integer overflow.
 *
 *      6. IMPORTANT: Check for overflow BEFORE updating rev, because 64-bit integers are not allowed.
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 * __________________________________________________
 * Write insights here
 * __________________________________________________
 *
 */

class Solution {
public:
    int reverse(int x) {
        long rev = 0;
        while(x != 0){
            int lastDigit = x % 10;
            rev = rev * 10 + lastDigit;
            x = x / 10;
        }
        // We need to only return the number of int size that means 32 bits only so we use this condition 
        // if (rev > INT_MAX || rev < INT_MIN) then return 0;
        if (rev > INT_MAX || rev < INT_MIN){
            return 0;
        }
        // otherwise return the reverse number.
        return rev ;
    }
};