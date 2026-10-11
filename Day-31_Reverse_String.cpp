/*
 * DATE: 11/10/2026
 *
 * PROBLEM LINK: https://leetcode.com/problems/reverse-string/
 * PROBLEM STATEMENT:
 *        Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

Example 1:
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

Example 2:
Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
 

Constraints:
1 <= s.length <= 105
s[i] is a printable ascii character.

 * __________________________________________________
 * Write statement notes here
 * 
 *      1. Use two pointers: left = 0, right = n - 1.
        2. Swap characters and move both pointers inward.
        3. Stop when left >= right.
        4. Pattern: Two Pointers + Swapping.
        5. Time Complexity: O(n).
        6. Recursive Space: O(n); Iterative Space: O(1).
        
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 * __________________________________________________
 * Write insights here
 * __________________________________________________
 *
 */

class Solution {
public:
    void helperFunction (vector<char>& s ,int left ,int right){
        if(left >= right){
            return;
        }
        swap(s[left] , s[right]);
        helperFunction(s , left + 1 , right - 1);
    }
    
    void reverseString(vector<char>& s) {
        int Length = s.size() - 1; 
        helperFunction(s , 0 , Length);
    }
};