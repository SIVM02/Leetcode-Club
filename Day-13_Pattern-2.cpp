/*
 * DATE: 28/09/2026
 *
 * PROBLEM LINK: https://takeuforward.org/practice/dsa/pattern-2
 * PROBLEM STATEMENT:
 *      Given an integer n. You need to recreate the pattern given below for any value of N. Let's say for N = 5, the pattern should look like as below:

*
**
***
****
*****

Print the pattern in the function given to you.

Example 1:
Input: n = 4
Output:
    *
    **
    ***
    ****
Example 2:
Input: n = 2

Output:
    *
    **

Constraints
1 <= n <= 100

 * __________________________________________________
 * Write statement notes here
 *      1} For outer loop, count the no of lines
 *      2} For the inner loop,Focus on thr column & connect them somehow to the rows.
 *      3} Print them '*' inside the inner for loop.
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
    void pattern2(int n) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                cout << "*";
            }
        cout << "\n";
        }
    }
};