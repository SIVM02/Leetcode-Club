/*
On Day 2, I learned the inner workings of insertion sort, and the logic became much clearer to me. Using two for loops made it easier to understand this time, so I am also confident I can implement it using two while loops and the 4 different combinations of while and for loops.
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
  // Initialize the array to be sorted
  int array[] = {9, 4, 6, 3, 7, 1} ;
  // Calculate the number of elements in the array
  int n = sizeof(array)/sizeof(array[0]);
  // Insertion Sort using nested for-loops (Swap approach)
  for(int i = 1 ; i < n ; i++){
    // Inner loop: Bubble the current element back to its correct sorted position
    // Runs as long as the previous element is greater than the current element
    for(int j = i ; j > 0 && array[j-1] > array[j]; j-- ){
      // Swap out-of-order adjacent elements
      int temp = array[j];
      array[j] = array[j-1];
      array[j-1] = temp;
    }
  }
  // Output the sorted array to the console
  for (int i = 0 ; i < n; i++){
    cout << array[i] << ' ';
  }
  return 0;
}