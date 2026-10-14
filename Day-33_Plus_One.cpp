/*
 * DATE: 13/10/2026
 *
 * PROBLEM LINK: https://leetcode.com/problems/plus-one/description/
 * PROBLEM STATEMENT:
 *          You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

Example 1:
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].

Example 2:
Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].

Example 3:
Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].
 

Constraints:
1 <= digits.length <= 100
0 <= digits[i] <= 9
digits does not contain any leading 0's.


 * __________________________________________________
 * Write statement notes here
 *          --> Given an array of digits representing a large positive integer, increment the number by one.
            -->The array stores digits from most significant to least significant.
            -->Start from the last digit because addition begins at the least significant digit.
            -->If a digit is less than 9, increment it and stop.
            -->If a digit is 9, change it to 0 and propagate the carry to the previous digit.
            -->If every digit is 9, insert 1 at the beginning.
            -->Do not convert the array into an integer because the number can contain up to 100 digits and exceed standard integer limits.
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 * 
 *          -->Process from right to left: Addition starts from the least significant digit, which is at the last index of the array.
            -->Carry propagation: When a digit is 9, adding 1 produces 10. Store 0 at that position and carry 1 to the previous digit.
            -->Early termination: If a digit is less than 9, increment it and return immediately because no carry remains to be processed.
            -->Handle the all-9s edge case: If every digit is 9, all digits become 0. A new leading 1 must be inserted.
 * __________________________________________________
 * Write insights here
 *          -->Time complexity:O(n) in the worst case, when all digits are 9.
            -->Auxiliary space: O(1) for the carry-processing logic, since the array is modified in place.
 * __________________________________________________
 *
 */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits[digits.size() - 1] < 9){
            digits[digits.size() - 1] += 1;
            return digits;
        }
        for(int i = digits.size() - 1 ; i >= 0 ; i--){
            if(digits[i] < 9){
                digits[i]++;
                return digits;
            }

            if(digits[i] == 9){
                digits[i] = 0;
            }
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
