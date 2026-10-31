/*
 * DATE: 30/10/2026
 *
 * PROBLEM LINK: https://leetcode.com/problems/first-missing-positive/description/
 * PROBLEM STATEMENT:
 *          Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.
You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

Example 1:
Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.

Example 2:
Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.

Example 3:
Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.
 
Constraints:
1 <= nums.length <= 10^5
-2^31 <= nums[i] <= 2^31 - 1
 * __________________________________________________
 * Write statement notes here
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 *      1. The smallest missing positive integer must be in the range
 *          [1, n + 1], where n is the size of the array.
 *
 *      2. Negative numbers and zero are not useful when searching for
 *         the smallest missing positive integer.
 *         Therefore, we can replace negative numbers with 0.
 *
 *      3. Sorting helps arrange numbers in increasing order, making it
 *         easier to identify the first missing positive integer.
 *
 *      4. Maintain an expected variable starting from 1.
 *         - If nums[i] == expected, increment expected.
 *         - Otherwise, ignore the current element.
 *
 *       5. Duplicate numbers do not affect the answer because expected
 *         increases only when the required number is found.
 *
 *      6. Sorting gives O(n log n) time complexity.
 *
 *      7. IMPORTANT:
 *         This approach does NOT satisfy the problem O(n) time requirement.
 *      
 *          Time Complexity: O(n)
 *          Auxiliary Space: O(1)
 *        
 * __________________________________________________
 * Write insights here
 * __________________________________________________
 *
 */

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // This is method 1 That take time complexity of O(n log n)
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] < 0){
                nums[i] = 0;
            }
        }
        int expected = 1;
        sort(nums.begin() , nums.end());
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == expected){
                expected++ ;
            }
        }
        return expected;
    }
};