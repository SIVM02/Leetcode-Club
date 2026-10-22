/*
 * DATE: 22/10/2026
 *
 * PROBLEM LINK: https://leetcode.com/problems/number-of-1-bits/description/
 * PROBLEM STATEMENT:
 *        Given a positive integer n, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).
 * 
Example 1:
Input: n = 11
Output: 3

Explanation:
The input binary string 1011 has a total of three set bits.

Example 2:
Input: n = 128
Output: 1

Explanation:
The input binary string 10000000 has a total of one set bit.

Example 3:
Input: n = 2147483645
Output: 30

Explanation:
The input binary string 1111111111111111111111111111101 has a total of thirty set bits.

Constraints:
1 <= n <= 231 - 1

 * __________________________________________________
 * Write statement notes here
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 * 
 * 1. n % 2 gives the last binary bit (0 or 1).
 *
 * 2. n / 2 removes the last binary bit using integer division.
 *    Repeat until n becomes 0 to convert a number into binary.
 *
 * 3. To count set bits, count how many times the binary digit is 1.
 *
 * 4. We can count set bits directly during conversion without
 *    storing binary digits in an array.
 * 
 * 6. TIME COMPLEXITY: O(log n), since we process binary digits.
 *
 * 7. SPACE COMPLEXITY:
 *    O(log n) for my array-based approach.
 *    O(1) if we count directly without an array.
 * __________________________________________________
 * Write insights here
 * __________________________________________________
 *
 */

class Solution {
public:
    int hammingWeight(int n) {

        int binaryArray[32];
        //we count the no is how much time divided by 2 by using i.
        int i = 0;

        while(n > 0){
            binaryArray[i] = n % 2;
            i++;
            n = n / 2; 
        }

        int count = 0 ;
        for(int j = 0 ; j < i ; j++){
            if(binaryArray[j] == 1){
                count++;
            }
        }
        return count ;
    }
};