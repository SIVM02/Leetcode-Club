/*
 * DATE: 03/11/2026
 *
 * PROBLEM LINK: https://leetcode.com/problems/three-consecutive-odds/description/
 * PROBLEM STATEMENT:
 *             Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.

Example 1:
Input: arr = [2,6,4,1]
Output: false
Explanation: There are no three consecutive odds.

Example 2:
Input: arr = [1,2,34,3,4,5,7,23,12]
Output: true
Explanation: [5,7,23] are three consecutive odds.
 
Constraints:
1 <= arr.length <= 1000
1 <= arr[i] <= 1000

 * __________________________________________________
 * Write statement notes here
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 * __________________________________________________
 * Write insights here
 *          1. Consecutive elements: When a problem asks for consecutive elements satisfying a condition, we can use a counter to track how many consecutive elements satisfy that condition.

            2. Counter reset technique: If an even number is encountered, reset count = 0 because the sequence of consecutive odd numbers is broken.

            3. Increment counter: Whenever an odd number is encountered, increment count++.

            4. Early return: As soon as count == 3, return true. There is no need to traverse the remaining array.

            5. Single traversal: We don't need nested loops or extra data structures. We can solve the problem in one pass.

            6. Order matters: Three odd numbers must be adjacent. Finding three odd numbers anywhere in the array is not sufficient.
 * __________________________________________________
 *
 */

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0;
        for(int i = 0 ; i < arr.size() ; i++){
            if(arr[i] % 2 == 0 ){
                count = 0;
            }
            if(arr[i] % 2 != 0){
                count++;
            }
            if(count == 3){
                return true;
            }
        }
        return false;
    }
};