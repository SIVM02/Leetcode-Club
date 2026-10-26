/*
 * DATE: 25/10/2026
 *
 * PROBLEM LINK: https://leetcode.com/problems/power-of-two/description/
 * PROBLEM STATEMENT:
 *        Given an integer n, return true if it is a power of two. Otherwise, return false.
An integer n is a power of two, if there exists an integer x such that n == 2x.

Example 1:
Input: n = 1
Output: true
Explanation: 20 = 1

Example 2:
Input: n = 16
Output: true
Explanation: 24 = 16

Example 3:
Input: n = 3
Output: false
 
Constraints:
-231 <= n <= 231 - 1

 * __________________________________________________
 * Write statement notes here
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 *          1. The Core Idea: "Strip the 2s"
                A power of two (2,4,8,16,…) is made up of only the number 2 multiplied repeatedly.
                If you keep dividing it by 2, you are peeling away those factors one by one.

            2. The Success Rule (n == 1)
                If a number is a true power of two, dividing it repeatedly by 2 will eventually leave you with exactly 1.
                  Example: 
                    16→8→4→2→1 (Success!)

            3. The Failure Rule (n > 1 odd number)
                If the number contains any other factor (like 3 in the case of 6, since 6=2×3), dividing by 2 will strip away the 2, but leave behind an odd number.
            Example: 
            6→3 (Stuck at an odd number, not 1 → Failure!)

            4. Safety Net (n <= 0)
               Always check for zero or negative numbers first. Powers of two are strictly positive, and handling n <= 0 upfront prevents infinite loops during division.
 * __________________________________________________
 * Write insights here
 * __________________________________________________
 *
 */

class Solution {
public:
    bool isPowerOfTwo(int n) {
        // Check the number is less than 0 or equal to 0 then return false.
        if(n <= 0){
            return false;
        }
        while(n % 2 == 0){
            n = n / 2;
        }
        if(n == 1){
            return true;
        }else {
            return false;
        }
    }
};