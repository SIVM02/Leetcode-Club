/*
 * DATE: 03/10/2026
 *
 * PROBLEM LINK: https://www.geeksforgeeks.org/problems/gcd-of-two-numbers3459/1https://www.geeksforgeeks.org/problems/gcd-of-two-numbers3459/1
 * PROBLEM STATEMENT:
 *        Given two positive integers a and b, find GCD of a and b.

Note: Don't use the inbuilt gcd function

Examples:
Input: a = 20, b = 28
Output: 4
Explanation: GCD of 20 and 28 is 4

Input: a = 60, b = 36
Output: 12
Explanation: GCD of 60 and 36 is 12

Constraints:
1 ≤ a, b ≤ 10^9

 * __________________________________________________
 * Write statement notes here
 *      // Use the Euclidean Algorithm.
 *        Key idea:
 *          GCD(a, b) = GCD(b, a % b)
 *      Instead of finding all factors, repeatedly use the remainder to make the problem smaller.
 * 
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 * __________________________________________________
 * Write insights here 
 *       Loop stops when b == 0.
 *       The remaining value of a is the answer.
 * __________________________________________________
 *
 */

class Solution {
  public:
    int gcd(int a, int b) {
        // code here
        while (b != 0){
            int remainder = a % b;
            a = b;
            b = remainder;
        }
        return a;
    }
};
