/*
 * DATE: 01/10/2026
 *
 * PROBLEM LINK: https://leetcode.com/problems/palindrome-number/description/?envType=problem-list-v2&envId=math
 * PROBLEM STATEMENT:
 *      Given an integer x, return true if x is a palindrome, and false otherwise.

 

Example 1:
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 

Constraints:
-2^31 <= x <= 2^31 - 1

 * __________________________________________________
 * Write statement notes here
 *        1} A number is a palindrome if it remains the same when reversed.

          2}Negative numbers are not considered palindromes.
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 *     1} Extracting digits using % 10 and removing digits using / 10.
 *      2}Handle negative numbers separately.
 *      3}Reverse a number using: reverse = reverse * 10 + digit.

 __________________________________________________
 * Write insights here
 * __________________________________________________
 *
 */

class Solution {
public:
    bool isPalindrome(int x) {
        long long originalNo = x;
        long long reverseNo = 0;
        long long remainder = 0 ;
        if(x < 0){
            return false;
        }
        while(x != 0){
            remainder = x % 10;
            reverseNo = reverseNo * 10 + remainder ;
            x = x / 10;
        }
        if (reverseNo == originalNo){
            return true;
        }else{
            return false;
        }
    }
};