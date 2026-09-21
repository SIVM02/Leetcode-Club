/*
 * DATE: 21/09/2026
 *
 * PROBLEM LINK: https://www.geeksforgeeks.org/problems/search-an-element-in-an-array-1587115621/1
 * PROBLEM STATEMENT:
 *    Given an array, arr[] of n integers, and an integer element x, find whether element x is present in the array. Return the index of the first occurrence of x in the array, or -1 if it doesn't exist.

Examples:

Input: arr[] = [1, 2, 3, 4], x = 3
Output: 2
Explanation: For array [1, 2, 3, 4], the element to be searched is 3. Since 3 is present at index 2, the output is 2.
Input: arr[] = [10, 8, 30, 4, 5], x = 5
Output: 4
Explanation: For array [10, 8, 30, 4, 5], the element to be searched is 5 and it is at index 4. So, the output is 4.
Input: arr[] = [10, 8, 30], x = 6
Output: -1
Explanation: The element to be searched is 6 and it is not present, so we return -1.
Constraints:

1 ≤ arr.size() ≤ 10^6
0 ≤ arr[i] ≤ 10^6
0 ≤ x ≤ 10^5
 * __________________________________________________
 * Write statement notes here
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 * __________________________________________________
 * Write insights here
 *      For loop practice.
 * __________________________________________________
 *
 */

int search(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) { // Changed arr.size() to n
            if (arr[i] == x) {
                return i; // First occurrence found
            }
        }
        return -1;
}