/*
 * DATE: 10/10/2026
 *
 * PROBLEM LINK: https://leetcode.com/problems/valid-palindrome/description/
 * PROBLEM STATEMENT:
 *        A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
 * 
Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 
Constraints:
1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.

 * __________________________________________________
 * Write statement notes here
 * 
 *        1. A string is a palindrome if it reads the same forward
and backward after converting uppercase letters to lowercase and removing all non-alphanumeric characters.

          2. Alphanumeric characters include:
          - Lowercase letters (a-z)
          - Uppercase letters (A-Z)
          - Digits (0-9)

          3. If the string becomes empty after removing unwanted characters, it is considered a palindrome.

 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 * 
 * Quick revision: The key trick
Remember these three things:
          isalnum(c) — checks whether a character is a letter or digit.
          tolower(c) — converts an uppercase letter to lowercase.
          n - firstIndex - 1 ———— finds the character at the opposite end of the string.
 * __________________________________________________
 * Write insights here
 *      1. PREPROCESSING:
              - Traverse the original string.
              - Use isalnum() to keep only alphanumeric characters.
              - Use tolower() to convert uppercase letters to lowercase.
              - Store the processed characters in a new string.
*

        2. RECURSIVE COMPARISON:
              - Start comparing from the first index (0).
              - Compare the character at firstIndex with the character
              at n - firstIndex - 1 (the corresponding character
              from the end).
              - If the characters differ, return false immediately.
              - Otherwise, recursively move to the next index.
*

        3. BASE CASE:
              - If firstIndex >= n / 2, return true.
              - Only half of the string needs to be checked because the other half is already covered by the comparisons.

        4. IMPORTANT OBSERVATIONS:
              - Preprocessing makes palindrome checking simpler by removing case and punctuation-related differences.
              - A mismatch at any position means the string is not a palindrome, so recursion can stop immediately.
              - Empty strings and single-character strings are palindromes.
              - The original string remains unchanged because we store the cleaned characters separately.
 * __________________________________________________
 *
 */

class Solution {
public:
    bool Helperfunction(string& cleared , int firstIndex , int n){
        if(firstIndex >= n/2){
            return true;
        }
        if(cleared[firstIndex] != cleared[n-firstIndex-1]){
            return false;
        }
        return Helperfunction(cleared , firstIndex + 1, n);
    }
    bool isPalindrome(string s) {
        string cleared = "";
        for(int i = 0 ; i < s.length() ; i++){
            if(isalnum(s[i])){
                cleared.push_back(tolower(s[i]));
            }
        }
        int length = cleared.length();
        return Helperfunction(cleared , 0 , length);
    }
};