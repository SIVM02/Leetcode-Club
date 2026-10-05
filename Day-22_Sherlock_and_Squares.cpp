/*
 * DATE: 05/10/2026
 *
 * PROBLEM LINK: https://www.hackerrank.com/challenges/sherlock-and-squares/problem
 * PROBLEM STATEMENT:
 *      Watson likes to challenge Sherlock's math ability. He will provide a starting and ending value that describe a range of integers, inclusive of the endpoints. Sherlock must determine the number of square integers within that range.

Note: A square integer is an integer which is the square of an integer, e.g. 1,4,9,16,25.

Example
a = 24
b = 49

There are three square integers in the range:25, 36  and 49. Return 3.

Function Description:-
Complete the squares function in the editor below. It should return an integer representing the number of square integers in the inclusive range from a to b.

squares has the following parameter(s):
int a: the lower range boundary
int b: the upper range boundary

Returns
int: the number of square integers in the range

Input Format
The first line contains q, the number of test cases.
Each of the next  lines contains two space-separated integers, a and b, the starting and ending integers in the ranges.

Constraints
1 ≤ q ≤ 100
1 ≤ a ≤ b ≤ 10^9

Sample Input
2
3 9
17 24

Sample Output
2
0

Explanation
Test Case #00: In range[3,9] , 4 and 9 are the two square integers.
Test Case #01: In range [17,24], there are no square integers.


 * __________________________________________________
 * Write statement notes here
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 * 
 *      - Don't check every number from a to b if the range is large.
 *      - Instead, find the possible integer roots.
 *
 *      - Smallest possible root:
 *              ceil(sqrt(a))
 *
 *      - Largest possible root:
 *             floor(sqrt(b))
 *
 *      - Number of perfect squares:
 *              floor(sqrt(b)) - ceil(sqrt(a)) + 1
 *        
 *       - Time Complexity:
 *             O(1)
 *
 *        - Space Complexity:
 *              O(1)
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
 * Complete the 'squares' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER a
 *  2. INTEGER b
 */

int squares(int a, int b) {
    // Method 1... Easiest approach
    int count = 0;
    for(int i = a; i <= b ; i++){
        int root = sqrt(i);
        if(root * root == i){
            count++;            
        }        
    }
    return count;

    // Method 2... 
    /*
      int first = ceil(sqrt(a));
      int last = floor(sqrt(b));

      return last - first + 1;
    */
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int a = stoi(first_multiple_input[0]);

        int b = stoi(first_multiple_input[1]);

        int result = squares(a, b);

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
