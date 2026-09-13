/*
DATE: 14/09/2026.

PROBLEM LINK: https://www.hackerrank.com/challenges/birthday-cake-candles/problem

PROBLEM STATEMENT:
You are in charge of the cake for a child's birthday. It will have one candle for each year of their total age. They will only be able to blow out the tallest of the candles. Your task is to count how many candles are the tallest.

Example
candles = [4,4,1,3]

The tallest candles are 4 units high. There are 2 candles with this height, so the function should return 2.

Function Description:-
Complete the function birthday CakeCandles with the following parameter(s):
int candles[n]: the candle heights

Returns
int: the number of candles that are tallest

Input Format
The first line contains a single integer, n, the size of candles[].

The second line contains n space-separated integers, where each integer i describes the height of candles[i].

Constraints
1 ≤ n ≤ 10^ 5

15 ≤ candles[i] ≤ 10^ 7

Sample Input O
4
3213

Sample Output O
2

Explanation O
Candle heights are [3,2,1,3]. The tallest candles are 3 units, and there are 2 of them.

INSIGHTS GAIN FROM THIS QUESTION: 
    - Single-Pass Search: Find the tallest candle and count it at the exact same time in just one loop.
    - Reset on New Max: When you find a taller candle, update the max height and reset your count to 1.
    - Count Matches: If a candle matches the current max height, just add 1 to the count.
    - Time Complexity: O(N) — You check each candle only once.
    - Space Complexity: O(1) — Uses fixed memory (only two extra variables).
*/

// CODE:

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'birthdayCakeCandles' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY candles as parameter.
 */

int birthdayCakeCandles(vector<int> candles) {
    // Keep track of the tallest candle and how many times it occurs.
    int tallestCount = 1;
    int maxHeight = candles[0];
    int n =candles.size();
    for(int i  = 1;i < n; i++){
      // Found a new tallest candle, so reset the count.
        if(candles[i] > maxHeight){
            maxHeight = candles[i];
            tallestCount = 0 ;
        }

        // Count another candle with the current maximum height.
        if(maxHeight == candles[i]){
            tallestCount++;
        }
    }
    return tallestCount;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string candles_count_temp;
    getline(cin, candles_count_temp);

    int candles_count = stoi(ltrim(rtrim(candles_count_temp)));

    string candles_temp_temp;
    getline(cin, candles_temp_temp);

    vector<string> candles_temp = split(rtrim(candles_temp_temp));

    vector<int> candles(candles_count);

    for (int i = 0; i < candles_count; i++) {
        int candles_item = stoi(candles_temp[i]);

        candles[i] = candles_item;
    }

    int result = birthdayCakeCandles(candles);

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
