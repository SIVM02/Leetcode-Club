/*
 * DATE: 28/10/2026
 *
 * PROBLEM LINK: https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
 * PROBLEM STATEMENT:
 *          Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.

Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. After removing duplicates, return the number of unique elements k.

The first k elements of nums should contain the unique numbers in sorted order. The remaining elements beyond index k - 1 can be ignored.

Custom Judge:
The judge will test your solution with the following code:
int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length
int k = removeDuplicates(nums); // Calls your implementation
assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.

Example 1:
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

Example 2:
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
 
Constraints:
      1 <= nums.length <= 3 * 10^4
      -100 <= nums[i] <= 100
      nums is sorted in non-decreasing order.

 * __________________________________________________
 * Write statement notes here
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 *        1. Sorted Array Advantage: Duplicates are always adjacent, so compare neighboring unique and current elements.

          2. Two Pointer Technique:
              i (slow pointer): Tracks the last unique element.
              j (fast pointer): Traverses the array to find new unique elements.

          3. Main Logic:
              If nums[i] == nums[j] → Duplicate, ignore it.
              If nums[i] != nums[j] → Increment i and copy nums[j] to nums[i].

          4. Why i + 1? Because i represents an index, while i + 1 represents the total number of unique elements.

          5. In-place Modification: Modify the original array without using extra space.
              Important Revision Tricks
              Sorted array → Think about adjacent comparison.
              Two pointers → Useful for in-place array modification.
              Index starts at 0, but count starts at 1.
              No need for a set or extra array.

          Complexity
              Time: O(n)
              Space: O(1)
 * __________________________________________________
 * Write insights here
 * __________________________________________________
 *
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0){
            return 0 ; 
        }
        // i count the unique element but i add first element as a unique element in last time when the loop is completed because it help to arrarnge the unique element in a array.
        int i = 0;
        for(int j = 1 ; j < nums.size() ; j++){
            if(nums[i] != nums[j]){
                i++;
                //  nums[i] = nums[j] help to arrange the unique element  in a array {Array Modification} 
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};