/*
 * DATE: 15/09/2026
 *
 * PROBLEM LINK: https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem
 * PROBLEM STATEMENT:
        *  Lily likes to play games with integers. She has created a new game where she determines the difference between a number and its reverse. For instance, given the number 12, its reverse is 21. Their difference is 9. The number 120 reversed is 21, and their difference is 99.
        She decides to apply her game to decision making. She will look at a numbered range of days and will only go to a movie on a beautiful day.

        Given a range of numbered days. [i...j] and a number k, determine the number of days in the range that are beautiful. Beautiful numbers are defined as numbers where |i-reverse(i)| is evenly divisible by k. If a day's value is a beautiful number, it is a beautiful day. Return the number of beautiful days in the range.

        Function Description:

        Complete the beautifulDays function in the editor below.

        beautiful Days has the following parameter(s):
        int i: the starting day number
        int j: the ending day number
        int k: is the divisor

        Returns:
        int: the number of beautiful days in the range

        Input Format:
        A single line of three space-separated integers describing the respective values of i, j, and k.

        Constraints
        1 ≤ i ≤ j ≤ 2×10^ 6
        1 ≤ k ≤ 2×10^ 9

        Sample Input
        20 23 6

        Sample Output
        2

        Explanation
        Lily may go to the movies on days 20, 21, 22, and 23. We perform the following calculations to determine which days are beautiful:

        - Day 20 is beautiful because the following evaluates to a whole number: |20 - 02| / 6 = 18 / 6 = 3
        - Day 21 is not beautiful because the following doesn't evaluate to a whole number: |21 - 12| / 6 = 9 / 6 = 1.5
        - Day 22 is beautiful because the following evaluates to a whole number: |22 - 22| / 6 = 0 / 6 = 0
        - Day 23 is not beautiful because the following doesn't evaluate to a whole number: |23 - 32| / 6 = 9 / 6 = 1.5

        Only two days, 20 and 22, in this interval are beautiful. Thus, we print 2 as our answer.
 * __________________________________________________
 * Write statement notes here
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 *   reverseNo = (reverseNo * 10) + temp % 10 ;
 *  This is a formula that are build by a comman sense.
 *  The modulo operator (%) extracts the remainder.
 *  Integer division by 10 removes the last digit.
 *  Space complexity is O(1)
 * 
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
 * Complete the 'beautifulDays' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER i
 *  2. INTEGER j
 *  3. INTEGER k
 */

int beautifulDays(int i, int j, int k) {
    int count = 0;
    for(int index = i ; index <= j ; index++){
        // Reset reverseNo for each iteration since each number has a unique reverse value.
        int reverseNo = 0;
        //We use temp for donot disturb the index value so the for loop ruun properly  
        int temp = index;
        // We reverse the number using While loop
        while(temp > 0 ){
            // reverse number * 10 help to add places like once place, tens place, hundred place and so on.
            // % this is a modulus operator that help to get the remainder of a number, Here number is temp.
            reverseNo = (reverseNo * 10) + temp % 10 ;
            temp /= 10;
        }
        // Here we use abs() function
        // abs() functiona always return the prositive value because it calculate the ditance and distance new be negative.
        if(abs(index - reverseNo) % k == 0){
            count++;
        }
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int i = stoi(first_multiple_input[0]);

    int j = stoi(first_multiple_input[1]);

    int k = stoi(first_multiple_input[2]);

    int result = beautifulDays(i, j, k);

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
