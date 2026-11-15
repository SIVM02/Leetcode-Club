/*
 * DATE: 11/11/2026
 *
 * PROBLEM LINK: https://leetcode.com/problems/three-consecutive-odds/description/
 * PROBLEM STATEMENT:
 *              Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.

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
 *        Use a counter to track consecutive odd numbers.
          Increment the counter when an odd number is found.
          Reset the counter to 0 whenever an even number breaks the sequence.
          If the counter reaches 3, return true immediately (early exit).
          Pattern: Linear Traversal + Counter.

          Complexity:
              Time: O(N)
              Space: O(1)
 * __________________________________________________
 * Write insights here
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