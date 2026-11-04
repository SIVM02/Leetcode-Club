/*
 * DATE: 07/11/2026
 *
 * PROBLEM LINK: https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/description/
 * PROBLEM STATEMENT:
 *        Given an integer number n, return the difference between the product of its digits and the sum of its digits.
Example 1:
Input: n = 234
Output: 15 
Explanation: 
Product of digits = 2 * 3 * 4 = 24 
Sum of digits = 2 + 3 + 4 = 9 
Result = 24 - 9 = 15

Example 2:
Input: n = 4421
Output: 21
Explanation: 
Product of digits = 4 * 4 * 2 * 1 = 32 
Sum of digits = 4 + 4 + 2 + 1 = 11 
Result = 32 - 11 = 21
 
Constraints:
1 <= n <= 10^5

 *      
 * __________________________________________________
 * Write statement notes here
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 * 
 *            1} Digit extraction using modulo (%): We can extract the last digit of a number using:
 *                    int digit = n % 10;
 * 
 *                For example, if n = 234, then 234 % 10 = 4.

              2} Removing the last digit using division (/): We can remove the last digit using:
                    n = n / 10;

              For example, 234 / 10 = 23.

              3} While loop for digit traversal: We use while(n > 0) to process every digit until the number becomes zero.

              4} Product initialization: Always initialize product = 1 because multiplication starts with 1 (multiplicative identity).
                    If we initialize it with 0, the product will always remain zero.

              5} Sum initialization: Initialize sum = 0 because addition starts with 0 (additive identity).

              6} Calculate product and sum simultaneously: We don't need separate loops. We can calculate both values while extracting digits in a single traversal.
                    product = product * digit;
                    sum = sum + digit;
              
              7} Return the difference: Once all digits are processed, simply return:
                    return product - sum;
              
              8} Important observation: We don't need to convert the integer into a string or use arrays to access individual digits. Mathematical operations are sufficient.
 * __________________________________________________
 * Write insights here
 * __________________________________________________
 *
 */

class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1;
        int sum = 0;
        while(n > 0){
            int digit = n % 10;
            n = n / 10;
            product = product * digit ;
            sum = sum + digit;
        }
        return product-sum;
    }
};