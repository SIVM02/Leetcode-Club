// The problem link are https://www.hackerrank.com/challenges/find-digits/problem

/*The given Question is
An integer d is a divisor of an integer n if the remainder of n / d = 0

Given an integer, for each digit that makes up the integer determine whether it is a divisor. Count the number of divisors occurring within the integer.

Example
n = 124

Check whether 1, 2 and 4 are divisors of 124. All 3 numbers divide evenly into 124 so return 3.

n = 111
Check whether 1. 1, and 1 are divisors of 111. All 3 numbers divide evenly into 111 so return 3.

n = 10
Check whether 1 and 0 are divisors of 10. 1 is, but 0 is not. Return 1.

Function Description

Complete the findDigits function in the editor below.

findDigits has the following parameter(s):

int n: the value to analyze

Returns
int: the number of digits in n that are divisors of n

Input Format

The first line is an Integer, t, the number of test cases.

The i subsequent lines each contain an integer, n.

Constraints

1 <= t <= 15
0 < n < 10 ^ 9

Sample Input
2
12
1012

Sample Output
2
3

Explanation
The number 12 is broken into two digits, 1 and 2. When 12 is divided by either of those two digits, the remainder is 0 so they are both divisors.

The number 1012 is broken into four digits, 1, 0, 1, and 2. 1012 is evenly divisible by its digits 1, 1, and 2, but it is not divisible by 0 as division by zero is undefined.
*/ 

// We only need to Complete the findDigits function in the editor below. 
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'findDigits' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER n as parameter.
 */

int findDigits(int n) {
  // VERSION 1: My first approach
  // Extract all digits → store in vector → check using second loop.

  // Store each digit of n so we can check them one by one later.
  vector<int> digits;

  // Keep track of how many digits we extracted.
  int count = 0;
  // Save the original number because n will be changed while extracting digits.
  int originalNumber = n;
  // Count how many digits are exact divisors of the original number.
  int Divisors = 0;

  // Extract each digit from the number, starting from the last digit.
  while (n>0)
  {
    // Get the last digit of n.
    int digit = n % 10;
    // Store the digit in the vector.
    digits.push_back(digit);
    // Increase the number of extracted digits.
    count++;
    // Remove the last digit from n.
    n = n / 10;
  }

  // Check every extracted digit to see if it divides the original number.
  for(int i = 0 ; i < count; i++){

    // VERY IMPORTANT: 
    // A digit can be 0, but we cannot divide by 0. 
    // Therefore, check digits[i] != 0 FIRST. 
    // 
    // Do NOT write: 
    // originalNumber % digits[i] == 0 && digits[i] != 0 
    // 
    /* because C++ would try the modulo operation first. 
    If (digits[i] != 0 && originalNumber % digits[i] == 0) { 
      Divisors++;
    }*/

    // Ignore 0 because division by zero is not possible. 
    // Count the digit if it divides the original number exactly.
    if(digits[i] != 0 && originalNumber % digits[i] == 0){
      Divisors++;
    }
  }
  // Return the total number of digits that divide the original number.
  return Divisors;

// VERSION 2: Improved approach
// Extract each digit → check immediately.
// Uses less memory and only one loop.

  int originalNumber = n;
  int Divisors = 0;

  while(n > 0){
    int digit = n % 10;
    if(digit != 0 && originalNumber % digit == 0){
      Divisors++;
    }
    n = n / 10;
  }
  return Divisors;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        int result = findDigits(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
