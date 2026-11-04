/*
 * DATE: 08/11/2026
 *
 * PROBLEM LINK: https://leetcode.com/problems/smallest-even-multiple/description/
 * PROBLEM STATEMENT:
 *        Given a positive integer n, return the smallest positive integer that is a multiple of both 2 and n.
 * 
Example 1:
Input: n = 5
Output: 10
Explanation: The smallest multiple of both 5 and 2 is 10.

Example 2:
Input: n = 6
Output: 6
Explanation: The smallest multiple of both 6 and 2 is 6. Note that a number is a multiple of itself.
 
Constraints:
1 <= n <= 150

 * __________________________________________________
 * Write statement notes here
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 * 
 *        1} Even number: If n % 2 == 0, return n because it is already divisible by 2.
          2} Odd number: If n is odd, return n * 2 to make it divisible by both 2 and n.
          3} Modulo operator (%): Used to check whether a number is even or odd.
          4} Mathematical concept: This problem is based on LCM (Least Common Multiple).
          5} No loops required: Simple conditional logic solves the problem.
 * __________________________________________________
 * Write insights here
 * __________________________________________________
 *
 */

class Solution {
public:
    int smallestEvenMultiple(int n) {
        if(n % 2  == 0){
            return n;
        }
        return n*2;
    }
};