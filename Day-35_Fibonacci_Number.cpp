/*
 * DATE: 15/10/2026
 *
 * PROBLEM LINK: https://leetcode.com/problems/fibonacci-number/description/
 * PROBLEM STATEMENT:
 *        The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).

Example 1:
Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

Example 2:
Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.

Example 3:
Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.

Constraints:
0 <= n <= 30

 * __________________________________________________
 * Write statement notes here
      Given n, return the nth Fibonacci number.
 *    Base cases:
 *    F(0) = 0, F(1) = 1
 *    Recurrence:
 *        F(n) = F(n-1) + F(n-2), for n > 1
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
         1. Base cases are necessary to stop recursion.
 *    - If n <= 1, return n.
 *
 * 2. Recursive relationship:
 *    - F(n) depends on F(n-1) and F(n-2).
 *    - Solve smaller subproblems to calculate the answer.
 *
 * 3. Recursive tree:
 *    - The same subproblems are calculated multiple times.
 *    - For example, fib(4) calls fib(3) and fib(2),
 *      and fib(3) again calls fib(2).
 *
 * 4. Time Complexity: O(2^n)
 *    - Exponential time due to repeated calculations.
 *
 * 5. Space Complexity: O(n)
 *    - Maximum recursion stack depth is O(n).
 * __________________________________________________
 * Write insights here
 * __________________________________________________
 *
 */

class Solution {
public:
    int fib(int n) {
        if( n <= 1){
            return n;
        }
        int last = fib(n-1);
        int secondLast = fib(n - 2);
        return last + secondLast ;
    }
};
