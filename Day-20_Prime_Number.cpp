/*
 * DATE: 03/10/2026
 *
 * PROBLEM LINK: https://www.geeksforgeeks.org/problems/prime-number2314/1
 * PROBLEM STATEMENT:
 *        Given a number n, determine whether it is a prime number or not.
Note: A prime number is a number greater than 1 that has no positive divisors other than 1 and itself.

Examples :
Input: n = 7
Output: true
Explanation: 7 has exactly two divisors: 1 and 7, making it a prime number.

Input: n = 25
Output: false
Explanation: 25 has more than two divisors: 1, 5, and 25, so it is not a prime number.

Input: n = 1
Output: false
Explanation: 1 has only one divisor (1 itself), which is not sufficient for it to be considered prime.
Constraints:
1 ≤ n ≤ 10^9


* __________________________________________________
 * Write statement notes here
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
    bool isPrime(int n) {
        // code here
        if (n < 2){
            return false;
        }
        int Divisor = 0 ;
        for(int i = 2; i <= n ; i++){
            if(n % i == 0){
                Divisor++;
            }
        }
        if(Divisor == 1){
                return true;
        }
        return false;
    }
};
