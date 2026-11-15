/*
 * DATE: 17/11/2026
 *
 * PROBLEM LINK: https://leetcode.com/problems/find-mismatched-segments-between-two-strings/description/
 * PROBLEM STATEMENT:
 *          You are given two strings s1 and s2 of the same length.
A mismatched segment is a maximal contiguous range of indices where the characters of s1 and s2 differ at every index.

Return a 2D array containing [sub1, sub2] for each mismatched segment, where sub1 and sub2 are the corresponding substrings from s1 and s2, respectively. Return the segments in increasing order of their starting indices. If there are no mismatched segments, return an empty array.

Example 1:
Input: s1 = "earth", s2 = "empty"
Output: [["ar","mp"],["h","y"]]
Explanation:
The characters at indices 1 and 2 differ, forming the mismatched segment ["ar","mp"].
The characters at index 4 differ, forming the mismatched segment ["h","y"].

Example 2:
Input: s1 = "action", s2 = "nation"
Output: [["ac","na"]]
Explanation:
The characters at indices 0 and 1 differ, forming the mismatched segment ["ac","na"]. All remaining characters are equal in both strings.

Example 3:
Input: s1 = "hot", s2 = "hot"
Output: []
Explanation:
The two strings are identical, so there are no mismatched segments.

Constraints:
1 <= s1.length == s2.length <= 100
s1 and s2 consist of lowercase English letters.

 * __________________________________________________
 * Write statement notes here
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 * 
 *          Traverse both strings simultaneously using a single loop.
            If characters differ, append them to their respective mismatch strings.
            If characters match, the current mismatched segment ends; store it in the answer and reset both strings.
            Handle the remaining mismatched segment after the loop because it may extend to the end of the strings.
            Pattern: Linear Traversal + Grouping Consecutive Elements.

            Complexity:
                Time: O(N)
                Space: O(N) — For storing the result and mismatch strings.
                
 * __________________________________________________
 * Write insights here
 * __________________________________________________
 *
 */

class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>> ans;
        string misMatch1 = "";
        string misMatch2 = "";
        int i = 0;
        for(i = 0 ; i < s1.length() ; i++){
            if(s1[i] != s2[i]){
                misMatch1 = misMatch1 + s1[i];
                misMatch2 = misMatch2 + s2[i];
            }
            else{
                if(misMatch1.length() != 0){
                    ans.push_back({misMatch1 , misMatch2});

                    misMatch1 = "";
                    misMatch2 = "";
                }
            }
        }
        if(misMatch1.length() != 0){
            ans.push_back({misMatch1 , misMatch2});
        }
        return ans;
    }
};