/*
 * DATE: 10/11/2026
 *
 * PROBLEM LINK: https://leetcode.com/problems/defanging-an-ip-address/description/ 
 * PROBLEM STATEMENT:
 *        Given a valid (IPv4) IP address, return a defanged version of that IP address.

A defanged IP address replaces every period "." with "[.]".
 
Example 1:
Input: address = "1.1.1.1"
Output: "1[.]1[.]1[.]1"

Example 2:
Input: address = "255.100.50.0"
Output: "255[.]100[.]50[.]0"
 
Constraints:
The given address is a valid IPv4 address.

 * __________________________________________________
 * Write statement notes here
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 * 
 *          1} String traversal: Traverse the input string character by character using a for loop.
            2} Character comparison: Check whether the current character is a dot ('.').
            3} String replacement: If '.' is found, append "[.]" to the result.
            4} push_back() function: Use ans.push_back(address[i]) to append a single character.
            5} Preserve other characters: If the character is not a dot, append it unchanged.
            6} Build a new string: Store the modified string in ans without changing the original string.
            7} Complexity Analysis
                  Time:O(n) — Traverse the string once.
                  Space:O(n) — Store the resulting string.
 * __________________________________________________
 * Write insights here
 * __________________________________________________
 *
 */

class Solution {
public:
    string defangIPaddr(string address) {
        string ans = "";
        for(int i = 0 ; i < address.length() ; i++){
            if(address[i] == '.'){
                ans = ans + "[.]";
            }else {
                ans.push_back(address[i]);
            }
        }
        return ans;
    }
};