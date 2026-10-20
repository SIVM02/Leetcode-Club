/*
 * DATE: 14/10/2026
 *
 * PROBLEM LINK: https://leetcode.com/problems/sort-colors/description/
 * PROBLEM STATEMENT:
 *        You are given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.

Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Explanation:
The array has two 0s, two 1s, and two 2s. Sorting them in-place places all 0s first, then all 1s, then all 2s.

Example 2:
Input: nums = [2,0,1]
Output: [0,1,2]
Explanation:
The array has one each of 0, 1, and 2, arranged in-place in the order 0, 1, 2.

Constraints:
n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.

 * __________________________________________________
 * Write statement notes here
 *        -->Given an array containing only 0, 1, and 2, sort it in ascending order.
          -->0 represents red, 1 represents white, and 2 represents blue.
          -->Sort the array in-place without using the built-in sorting function.

          --> Time Complexity: O(n) — one traversal to count the elements and another traversal to rewrite the array.
          --> Space Complexity: O(1) — only three counters and one index variable are used.
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 * 
 *      -->Three-Pass Technique:
        -->First pass: Count the frequency of 0, 1, and 2.
        -->Second pass: Fill the array with all 0s, then all 1s, then all 2s.
 * __________________________________________________
 * Write insights here
 * __________________________________________________
 *
 */

//Method 1:- use counting of red white blue then arraange it
// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int Red = 0;
//         int White = 0;
//         int Blue = 0;
//         for(int i = 0 ; i < nums.size() ; i++){
//             if(nums[i] == 0){
//                 Red++;
//             }
//             if(nums[i] == 1){
//                 White++;
//             }
//             if(nums[i] == 2){
//                 Blue++;
//             }
//         }
//         int index = 0;
        
//         for(int i = 0 ; i < Red ; i++ ){
//             nums[index] = 0 ;
//             index++ ;
//         }
//         for(int i = 0 ; i < White ; i++){
//             nums[index] = 1 ;
//             index++ ;
//         }
//         for(int i = 0 ; i < Blue ; i++){
//             nums[index] = 2;
//             index++ ; 
//         }
//     }
// };

// When i do revision then i think about this direction
// Method 2:- use the selection sort or other sorting algo
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int larger = nums[0];
        for(int i = 0 ; i < nums.size() ; i++){
            for(int j = i+1 ; j < nums.size() ; j++){
                if(nums[j] < nums[i]){
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }
            }
            
        }
    }
};
