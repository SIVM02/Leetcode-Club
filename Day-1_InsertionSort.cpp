#include<bits/stdc++.h>
using namespace std;

int main(){
  int nums[] = {3, 6, 2};
  // THis help to find the size of array
  int n = sizeof(nums)/sizeof(nums[0]);

  // Insertion sort
  for(int i = 1; i < n; i++){
    int temp = nums[i];
    int j = i - 1;

    while(j >= 0 && nums[j] > temp){
      nums[j+1] = nums[j];
      j--;
    }
    nums[j+1] = temp;
  }
  // use for loop for print the array;
  for(int i = 0 ; i < n ; i++){
    cout << nums[i] << ' ';
  }
  return 0;
}