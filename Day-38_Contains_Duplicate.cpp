/*
 * DATE: 18/10/2026
 *
 * PROBLEM LINK: 
 * PROBLEM STATEMENT:
 *          Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1:
Input: nums = [1,2,3,1]
Output: true
Explanation:
The element 1 occurs at the indices 0 and 3.

Example 2:
Input: nums = [1,2,3,4]
Output: false
Explanation
All elements are distinct.

Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true 

Constraints:
1 <= nums.length <= 105
-10^9 <= nums[i] <= 10^9

 * __________________________________________________
 * Write statement notes here
 *      1} Sorting helps identify duplicate elements easily because equal elements become adjacent after sorting.
 *      2. After sorting, compare each element with its previous element. If nums[i] == nums[i-1], a duplicate exists.
 *      3. We start the loop from i = 1 because nums[0] has no previous element to compare with.
 *      4. Early return: As soon as a duplicate is found, return true. If the loop finishes without finding one, return false.
 *      5. Time Complexity:
 *            - Brute Force: O(n^2)
 *            - Sorting Approach: O(n log n)
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
    bool containsDuplicate(vector<int>& nums) {
        /* Brute force approach
        for(int i = 0 ; i < nums.size() ; i++){
            for(int j = i + 1 ; j < nums.size() ; j++){
                if(nums[i] == nums[j]){
                    return true;
                }
            }
        }
        return false;
        */
       // I sort the element then easy to compare.
        sort(nums.begin(), nums.end());

        for(int i = 1 ; i < nums.size() ; i++){
          // we compare to the first element to previous one.
            if(nums[i] == nums[i-1] ){
                return true ;
            }
        }
        return false;
    }
};