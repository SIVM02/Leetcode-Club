/*
 * DATE: 16/11/2026
 *
 * PROBLEM LINK: https://leetcode.com/problems/count-valid-substrings-i/description/
 * PROBLEM STATEMENT:
 *          You are given a string s consisting only of the characters 'a', 'b', and 'c'.
A string is called valid if it does not contain "abc" as a substring.
Return the number of valid substrings in s. Substrings with different starting or ending indices are counted separately.

Example 1:
Input: s = "abac"
Output: 10
Explanation:
The following substrings don't contain "abc"​​​​​​​ as a substring:
s[0..0] = "a"
s[0..1] = "ab"
s[0..2] = "aba"
s[0..3] = "abac"​​​​​​​
s[1..1] = "b"
s[1..2] = "ba"
s[1..3] = "bac"
s[2..2] = "a"
s[2..3] = "ac"
s[3..3] = "c"
Thus, the answer is 10.

Example 2:
Input: s = "abc"
Output: 5
Explanation:
The following substrings don't contain "abc"​​​​​​​ as a substring:
s[0..0] = "a"
s[0..1] = "ab"
s[1..1] = "b"
s[1..2] = "bc"
s[2..2] = "c"​​​​​​​
Thus, the answer is 5.

Example 3:
Input: s = "ac"
Output: 3
Explanation:
All substrings in s don't contain "abc" as a substring​​​​​​​. Thus, the answer is 3.

Constraints:
1 <= s.length <= 10^5​​​​​​​
s only consists of 'a', 'b', and 'c' characters.
 * __________________________________________________
 * Write statement notes here
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 * 
 *          Total number of substrings of a string of length n is n * (n + 1) / 2.
            Instead of counting valid substrings directly, calculate total substrings - invalid substrings.
            Use last_abc_start to track the most recent starting index of the "abc" pattern.
            Whenever "abc" is found, update last_abc_start = i - 2.
            last_abc_start + 1 gives the number of invalid substrings ending at the current index.
            Pattern: Pattern Matching + Counting + Contribution Technique.

            Complexity:
                Time: O(N) — Single traversal.
                Space: O(1) — Only a few variables.
 * __________________________________________________
 * Write insights here
 * __________________________________________________
 *
 */

class Solution {
public:
    long long countValidSubstrings(string s) {
        // total substring are:-
        long long n = s.length();
        long long totalSubstring = (n * (n + 1)) / 2; 

        long long count =0;
        long long last_abc_start = -1;
        for(long long i = 2; i < n ; i++){
            if(s[i-2] == 'a' && s[i-1] == 'b' && s[i] == 'c'){
                last_abc_start = i - 2;
            }
            if(last_abc_start != -1){
                count = count + (last_abc_start + 1);
            }
        }
        return totalSubstring - count;
    }
};