/*
 * DATE: 04/11/2026
 *
 * PROBLEM LINK: https://leetcode.com/problems/find-target-indices-after-sorting-array/description/
 * PROBLEM STATEMENT:
 *            You are given a 0-indexed integer array nums and a target element target.
A target index is an index i such that nums[i] == target.

Return a list of the target indices of nums after sorting nums in non-decreasing order. If there are no target indices, return an empty list. The returned list must be sorted in increasing order.

Example 1:
Input: nums = [1,2,5,2,3], target = 2
Output: [1,2]
Explanation: After sorting, nums is [1,2,2,3,5].
The indices where nums[i] == 2 are 1 and 2.

Example 2:
Input: nums = [1,2,5,2,3], target = 3
Output: [3]
Explanation: After sorting, nums is [1,2,2,3,5].
The index where nums[i] == 3 is 3.

Example 3:
Input: nums = [1,2,5,2,3], target = 5
Output: [4]
Explanation: After sorting, nums is [1,2,2,3,5].
The index where nums[i] == 5 is 4.
 
Constraints:
1 <= nums.length <= 100
1 <= nums[i], target <= 100

 * __________________________________________________
 * Write statement notes here
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 * 
 *          1} Sorting technique: Since the question asks for target indices after sorting the array, first sort the array using sort(nums.begin(), nums.end()).

            2} STL sort function: C++ provides an inbuilt sorting function:
                  sort(nums.begin(), nums.end());
                  It sorts the array in non-decreasing (ascending) order.

            3} Traverse after sorting: Once the array is sorted, traverse it using a loop and compare each element with the given target.

            4} Store matching indices: Whenever nums[i] == target, store the current index i in the answer vector using:
                    storage.push_back(i);

            5} Duplicate elements: A target can appear multiple times. We must store every matching index, not just the first occurrence.

            6} Automatically sorted indices: Since we traverse the sorted array from left to right, the indices are automatically stored in increasing order. No additional sorting of the answer vector is required.

            7} Empty vector handling: If the target doesn't exist in the array, no index gets inserted, and the function automatically returns an empty vector.

            8} Important observation: Sorting changes the original positions of elements. Therefore, we must find the target indices only after sorting.

 * __________________________________________________
 * Write insights here
 * __________________________________________________
 *
 */

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        vector<int> storage;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == target){
                storage.push_back(i);
            }
        }
        return storage;
    }
};