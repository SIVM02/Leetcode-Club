/*
 * DATE: 03/10/2026
 *
 * PROBLEM LINK: https://www.geeksforgeeks.org/problems/all-divisors-of-a-number/1
 * 
 * PROBLEM STATEMENT:
 * __________________________________________________
 * Write statement notes here
 *        Given an integer n, return all the divisors of n in the ascending order.
 
Examples:
Input : n = 20
Output: 1 2 4 5 10 20
Explanation: 20 is completely divisible by 1, 2, 4, 5, 10 and 20.

Input: n = 21191
Output: 1 21191
Explanation: As 21191 is a prime number, it has only 2 factors(1 and the number itself).

Constraints:
1 ≤ n ≤ 10^9

 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 * __________________________________________________
 * Write insights here
 *      1} The brute-force approach checks every number from 1 to n and takes O(n) time.
 *      2} Complexity
              Time: O(n)
              Space: O(k) where k is the number of divisors.
        3} Since n can be as large as 10^9, checking all numbers can cause a Time Limit Exceeded (TLE).

 * __________________________________________________
 *
 */

class Solution {
  public:
    vector<int> getDivisors(int n) {
        // This is a easier and a simpler approach of a question but it not work for this because of time complexity. 
        vector<int> divisors;
        for(int i = 1 ; i <= n; i++){
            if(n % i == 0){
                divisors.push_back(i);
            }
        }
        return divisors;
    }
};