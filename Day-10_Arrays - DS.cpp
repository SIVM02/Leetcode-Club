/*
 * DATE: 20/09/2026
 *
 * PROBLEM LINK: https://www.hackerrank.com/challenges/arrays-ds/problem
 * PROBLEM STATEMENT:
 *    An array is a data structure that stores elements of the same type in a contiguous block of memory. In an array, A, of size N, each memory location has some unique index, i (where 0 < i < N), that can be referenced as A[i] or A.

Your task is to reverse an array of integers.

Note: If you've already solved our C++ domain's Arrays Introduction challenge, you may want to skip this.

Example:-
A = [1,2,3]
Return [3, 2, 1].

Function Description:-
Complete the function reverse Array with the following parameter(s):
int A[n]: the array to reverse

Returns:-
int[n]: the reversed array

Input Format
The first line contains an integer, N. the number of integers in A.
The second line contains N space-separated integers that make up A.

Constraints

1 ≤ N ≤ 10^3

1 ≤ A[i] ≤ 10^4, where A[i] is the sth integer in A
 * __________________________________________________
 * Write statement notes here
 *    1. Backward Loop Approach:
   - Iterating from index (n - 1) down to 0 easily constructs a reversed vector.
   - Time Complexity: O(N) — Single pass over the array.
   - Space Complexity: O(N) — Requires extra memory for the result vector.
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 * __________________________________________________
 * Write insights here
 * __________________________________________________
 *
 */

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'reverseArray' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

vector<int> reverseArray(vector<int> a) {
    vector<int> result;
    
    // Read elements from the end to the beginning
    for (int i = a.size() - 1; i >= 0; i--) {
        result.push_back(a[i]);
    }
    
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> res = reverseArray(arr);

    for (size_t i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
