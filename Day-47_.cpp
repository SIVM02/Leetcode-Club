/*
 * DATE: 26/10/2026
 *
 * PROBLEM LINK: https://leetcode.com/problems/binary-digit-score/
 * PROBLEM STATEMENT:
                You are given two integers a and b. Let s1 and s2 be the number of set bits in the binary representations of a and b, respectively.
The score of these integers is defined as follows:

If s1 >= s2, the score is s1 * s2.
Otherwise, the score is s2 / s1 using integer division.
Return an integer representing the score of a and b.
A set bit refers to a bit in the binary representation of a number that has a value of 1.

Example 1:
Input: a = 14, b = 6
Output: 6
Explanation:
The binary representation of a = 14 is "1110", so s1 = 3.
The binary representation of b = 6 is "110", so s2 = 2.
Since s1 > s2, the score of a and b is s1 * s2 = 3 * 2 = 6.

Example 2:
Input: a = 5, b = 15
Output: 2
Explanation:
The binary representation of a = 5 is "101", so s1 = 2.
The binary representation of b = 15 is "1111", so s2 = 4.
Since s1 < s2, the score of a and b is s2 / s1 = 4 / 2 = 2.

Example 3:
Input: a = 10, b = 12
Output: 4
Explanation:
The binary representation of a = 10 is "1010", so s1 = 2.
The binary representation of b = 12 is "1100", so s2 = 2.
Since s1 == s2, the score of a and b is s1 * s2 = 2 * 2 = 4.
 
Constraints:
1 <= a, b <= 100
 * __________________________________________________
 * Write statement notes here
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 * 
 *           1. Every decimal number has a binary representation consisting of 0s and 1s.
 *
 *          2. To convert a decimal number into binary:
 *              - Divide the number by 2.
 *              - Store the remainder (0 or 1).
 *              - Update the number using n = n / 2.
 *              - Repeat until n becomes 0.
 *           3. Important mathematical observation:
 *                If s1 >= s2, score = s1 * s2.
 *                Otherwise, score = s2 / s1 (integer division).
 *           8. Since a and b are positive (1 <= a, b <= 100),
 *                 both set-bit counts are guaranteed to be greater than 0.
 * 
 * __________________________________________________
 * Write insights here
 * __________________________________________________
 *
 */

class Solution {
public:
    int calculateScore(int a, int b) {
        // 525 WEEKLY CONTEST 1st PROBLEM.
        // SOLVED DURING CONTEST IN 23 MINUTES. 
        vector<int> binary1;
        vector<int> binary2;
        while (a > 0){
            binary1.push_back(a % 2);
            a = a/2;
        }
        while(b>0){
            binary2.push_back(b % 2);
            b = b/2;
        }
        int count = 0;
        int count1 = 0;
        for(int i = 0 ; i < binary1.size() ; i++){
            if(binary1[i] == 1){
                count++;
            }
        }
        for(int i = 0 ; i < binary2.size() ; i++){
            if(binary2[i] == 1){
                count1++;
            }
        }
        if(count >= count1){
            return  count*count1;
        }else{
            return count1/count;
        }
    }
};