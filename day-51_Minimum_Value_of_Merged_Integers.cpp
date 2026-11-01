/*
 * DATE: 01/11/2026
 *
 * PROBLEM LINK: https://leetcode.com/problems/minimum-value-of-merged-integers/description/
 * PROBLEM STATEMENT:
 *          You are given an integer array nums of even length n.

You have to merge the elements of nums in pairs by merging nums[0] with nums[1], nums[2] with nums[3], and so on, until nums[n - 2] with nums[n - 1].
Return the minimum value among all the resulting merged integers.
To merge two integers, concatenate all the decimal digits of the first integer followed by all the decimal digits of the second integer.

Example 1:
Input: nums = [23,55,42,21]
Output: 2355
Explanation:
Merging nums[0] = 23 and nums[1] = 55 gives 2355.
Merging nums[2] = 42 and nums[3] = 21 gives 4221.
The minimum value among the merged numbers is min(2355, 4221) = 2355.

Example 2:
Input: nums = [34,7,11,11]
Output: 347
Explanation:
Merging nums[0] = 34 and nums[1] = 7 gives 347.
Merging nums[2] = 11 and nums[3] = 11 gives 1111.
The minimum value among the merged numbers is min(347, 1111) = 347.

Example 3:
Input: nums = [9,20]
Output: 920
Explanation:
Merging nums[0] = 9 and nums[1] = 20 gives 920.
There is only one merged number, so the minimum value is 920.
 
Constraints:
2 <= n == nums.length <= 100
n is even
1 <= nums[i] <= 1000

 * __________________________________________________
 * Write statement notes here
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 *
 * 1. Concatenation of two integers can be performed mathematically
 *    without converting them into strings.
 *
 * 2. To concatenate two numbers:
 *    result = a * (10 ^ number_of_digits_in_b) + b
 *
 *    Examples:
 *    23 and 5   -> 23 * 10 + 5    = 235
 *    23 and 55  -> 23 * 100 + 55  = 2355
 *    23 and 421 -> 23 * 1000 + 421 = 23421
 *
 * 3. Important trick:
 *    The number of digits in the SECOND integer determines
 *    the multiplication factor applied to the FIRST integer.
 *
 * 4. Digit-based concatenation can be implemented using:
 *    - Conditional checks (< 10, < 100, < 1000).
 *
 * 5. Since we only need the minimum merged integer, we don't
 *    necessarily need to store all merged values in a vector.
 *    We can maintain a running minimum.
 *
 * 6. STL functions learned:
 *    min_element() returns an iterator pointing to the
 *    smallest element in a range.
 *
 * 7. Constraints analysis:
 *    nums[i] <= 1000, so the merged integer has at most
 *    7 digits (1000 followed by 1000 = 10001000, actually
 *    8 digits). Therefore, int is sufficient here.
 *
 * 8. Complexity:
 *    Time Complexity: O(n)
 *    Space Complexity: O(n) for the storage vector.
 *
 * __________________________________________________
 * Write insights here
 * __________________________________________________
 *
 */

class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        vector<int> storage;
        for(int i = 0 ; i < nums.size() ; i += 2){
            int result = 0;
            int a = nums[i];
            int b = nums[i+1];
            if(nums[i+1] < 10){
                result = nums[i] * 10 + nums[i+1];
            }
            else if(nums[i+1] < 100){
                result = nums[i] * 100 + nums[i+1];
            }
            else if(nums[i+1] < 1000){
                result = nums[i] * 1000 + nums[i+1];
            }else {
                result = a * 10000 + b;
            }
            storage.push_back(result);
        }
        return *min_element(storage.begin() , storage.end());
     
    }
};