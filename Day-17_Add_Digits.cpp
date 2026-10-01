/*
 * DATE: 01/10/2026
 *
 * PROBLEM LINK: https://leetcode.com/problems/add-digits/description/?envType=problem-list-v2&envId=math
 * PROBLEM STATEMENT:
 *      Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

 

Example 1:
Input: num = 38
Output: 2
Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2 
Since 2 has only one digit, return it.

Example 2:
Input: num = 0
Output: 0

Constraints:
0 <= num <= 2^31 - 1

 * __________________________________________________
 * Write statement notes here
 *      1}Repeatedly calculate the sum of all digits until only one digit remains.

        2}Use % 10 to extract the last digit.

        3}Use / 10 to remove the last digit.

        4}Use an inner loop to calculate the sum of digits.

        5}Use an outer loop to repeat the process until num becomes a single digit.
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 *      1}sum must be reset to 0 in every outer-loop iteration.
 *      2}Nested loops are useful when an operation on digits must be repeated.
 *      3}Edge case: num = 0 directly returns 0.       __________________________________________________
 * Write insights here
 * __________________________________________________
 *
 */
class Solution {
public:
    int addDigits(int num) {
        int digit;
        while(num > 9){
            int sum = 0;
            while(num > 0){
                digit = num % 10 ;
                num = num / 10;
                sum = sum + digit;
            }
            num = sum;
        }
        return num; 
    }
};