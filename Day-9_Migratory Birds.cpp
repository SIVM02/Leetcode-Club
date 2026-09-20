/*
 * DATE: 19/09/2026
 *
 * PROBLEM LINK: https://www.hackerrank.com/challenges/migratory-birds/problem
 * PROBLEM STATEMENT:
 *      Given an array of bird sightings where every element represents a bird type id, determine the id of the most frequently sighted type. If more than 1 type has been spotted that maximum amount, return the smallest of their ids.

Example

arr = [1, 1, 2, 2, 3]

There are two each of types 1 and 2, and one sighting of type 3. Pick the lower of the two types seen twice: type 1.

Function Description :-
Complete the migratoryBirds function in the editor below.

migratoryBirds has the following parameter(s):
int arr[n]: the types of birds sighted

Returns:-
int: the lowest type id of the most frequently sighted birds

Input Format:-
The first line contains an integer, n, the size of arr.

The second line describes arr as a space-separated integers, each a type number of the bird sighted.

Constraints
5 ≤ n ≤ 2×10^5
It is guaranteed that each type is 1. 2. 3. 4. or 5.

Sample Input O
6
144453

Sample Output O
4

Explanation O
The different types of birds occur in the following frequencies:

Type 1: 1 birds
Type 2: 0 birds
Type 3: 1 birds
Type 4: 3 birds
Type 5: 1 birds

The type number that occurs at the highest frequency is type 4, so we print 4 as our answer.

Sample Input 1
11
12345432134

Sample Output 1
3

Explanetion 1
The different types of birds occur in the following frequencies:

Type 1: 2
Type 2: 2
Type 3: 3
Type 4: 3
Type 5:1

Two types have a frequency of 3, and the lower of those is type 3.


 * __________________________________________________
 * Write statement notes here
 *    Time Complexity is O(N),
 *    Space Complexity: O(1).
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 *        // Bird IDs are strictly limited to integers 1, 2, 3, 4, and 5.
 *        // If multiple bird IDs share the exact same maximum frequency, return the smallest ID.
 * __________________________________________________
 * Write insights here
 *    use swich case and for loop simplest way .
 * __________________________________________________
 *
 */

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'migratoryBirds' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int migratoryBirds(vector<int> arr) {
  int first = 0;
  int second = 0;
  int third = 0;
  int four = 0;
  int five = 0;

  for(int i = 0 ; i < arr.size() ; i++){
    switch (arr[i]){
    case 1:
        first++;
        break;
    case 2: 
        second++;
        break;
    case 3:
        third++;
        break;
    case 4:
        four++;
        break;
    case 5:
        five++;
        break;
    default:
      break;
    }
  }
  int max_freq = 0;
  int best_bird = 0;

  if(first > max_freq){
    max_freq = first;
    best_bird = 1;
  }
  if(second > max_freq){
    max_freq = second;
    best_bird = 2;
  }
  if(third > max_freq){
    max_freq = third;
    best_bird = 3;
  }
  if(four > max_freq){
    max_freq = four;
    best_bird = 4;
  }
  if(five > max_freq){
    max_freq = five;
    best_bird = 5;
  }
  return best_bird; 
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

    int result = migratoryBirds(arr);

    fout << result << "\n";

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
