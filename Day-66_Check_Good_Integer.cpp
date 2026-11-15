/*
 * DATE: 15/11/2026
 *
 * PROBLEM LINK: https://leetcode.com/problems/check-good-integer/description/
 * PROBLEM STATEMENT:
 *          You are given a positive integer n.
Let digitSum be the sum of the digits of n, and let squareSum be the sum of the squares of the digits of n.
An integer is called good if squareSum - digitSum >= 50.
Return true if n is good. Otherwise, return false.

Example 1:
Input: n = 1000
Output: false
Explanation:
The digits of 1000 are 1, 0, 0, and 0.
The digitSum is 1 + 0 + 0 + 0 = 1.
The squareSum is 12 + 02 + 02 + 02 = 1.
The squareSum - digitSum is 1 - 1 = 0. As 0 is not greater than or equal to 50, the output is false.

Example 2:
Input: n = 19
Output: true
Explanation:
The digits of 19 are 1 and 9.
The digitSum is 1 + 9 = 10.
The squareSum is 12 + 92 = 1 + 81 = 82.
The squareSum - digitSum is 82 - 10 = 72. As 72 is greater than or equal to 50, the output is true.
 
Constraints:
1 <= n <= 10^9
 * __________________________________________________
 * Write statement notes here
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 *            Use % 10 to extract the last digit of a number.
              Use / 10 to remove the last digit.
              Calculate both digitSum and squareSum while traversing digits using a while loop.
              Check whether squareSum - digitSum >= 50 to determine if the number is good.
              Pattern: Digit Extraction + Mathematical Calculation.
              
              Complexity:
                  Time: O(logN) — Traverses each digit once.
                  Space: O(1) — Uses only a few variables.
 * __________________________________________________
 * Write insights here
 * __________________________________________________
 *
 */

class Solution {
public:
    bool checkGoodInteger(int n) {
        int digitSum = 0;
        int squareSum = 0;
        while(n > 0){
            int digit = n % 10;
            n = n / 10;
            digitSum = digitSum + digit;
            squareSum = squareSum + (digit * digit);
        }
        if(squareSum - digitSum >= 50){
            return true;
        }
        return false;
    }
};