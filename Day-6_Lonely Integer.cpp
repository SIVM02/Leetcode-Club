/*
 * DATE: 16/09/2026
 *
 * PROBLEM LINK: https://www.hackerrank.com/challenges/lonely-integer/problem 
 * PROBLEM STATEMENT: 
      *Given an array of integers, where all elements but one occur twice, find the unique element.

      Example

      a = [1,2,3,4,3,2,1]
      The unique element is 4.

      Function Description:-
      Complete the lonelyinteger function in the editor below.

      lonelyinteger has the following parameter(s):
      int a[n]: an array of integers

      Returns
      int: the element that occurs only once

      Input Format
      The first line contains a single integer, n, the number of integers in the array.

      The second line contains n space-seperated integers that describe the values in a.

      Constraints

      1 ≤ n < 100
      It is guaranteed that n is an odd number and that there is one unique element.

      0 ≤ a[i] ≤ 100. where 0 ≤ i < n.

      Sample Input O
      1
      1

      Sample Output 0
      1

      Explanation 0
      There is only one element in the array, thus it is unique.

      Sample Input 1
      3
      1 1 2
      Sample Output 1
      2
      Explanation 1
      We have two 1's, and 2 is unique.

      Sample Input 2
      5
      0 0 1 2 1
      Sample Output 2
      2
      Explanation 2
      We have two 0's, two 1's, and one 2. 2 is unique.
 * __________________________________________________
 * Write statement notes here
 *      This question is solved by two method 
 *          1} first is solved by the help of sorting and 
 *          2} XOR i donot know how to do it so i learn and implement it.
 * 
 *  CONCEPT:- for Method 2:- I understand XOR but not able to write a code for it.
 *      XOR = one or the other, but NOT both.
 *          0 XOR 0 = 0 (Same -> OFF)
 *          1 XOR 1 = 0 (Same -> OFF)
 *          1 XOR 0 = 1 (Different -> ON)
 *          0 XOR 1 = 1 (Different -> ON)
 * 
 *           If the inputs are the same, the answer is 0. 
 *           If they are different, the answer is 1
 * 
 *  Computers use binary: They see 5 as 1 0 1.
 * XOR (^) compares column by column 
 *   1 0 1  (5) {Binary of 5 is 101 }
   ^ 1 0 1  (5)
    --------
    0 0 0  (= 0) {% 101 cancleout 101}

 *  RULES:-
 *      (Any number mixed with 0 stays exactly the same). ex:- X ^ 0 = X
 *      (Any number mixed with itself turns into 0). ex:- X ^ X = 0
 *      (The order does not matter. The matching numbers will find each other and cancel out, no matter where they are standing). 
 *      ex:- A ^ B ^ A is the exact same as A ^ A ^ B
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 * __________________________________________________
 * Write insights here
 *          Time Complexity  = O(n²) because 2 for loop
            Space Complexity = O(n) because n element are stored in a array
 * __________________________________________________
 *
 */

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'lonelyinteger' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

int lonelyinteger(vector<int> a) {
    int n = a.size();
    // Use insertion sort for sort the array.
    for(int i = 1; i < n ; i++){
        for(int j = i ; j > 0 && a[j-1] > a[j]; j--){
            int temp = a[j];
            a[j] = a[j-1];
            a[j-1] = temp;
        }
    }
    //Use for loop to check which number is lonely 
    // number < n - 1 Here we use this condition because we want to skip the last element  
    // Why we skip last element ? REASON = because if the last element is lonely then we return the previous element a[number] according to code.
    // We update the number by 2 [number += 2] because all the number are  twice only one is lonely.
    for(int number = 0; number < n - 1 ; number += 2){
        if(a[number] != a[number + 1]){
            return a[number];
        }
    }
    // if the last element is lonely then we return it a[n-1] and if the lonly element is not the last element then it is got by the previous code.
    return a[n-1];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    int result = lonelyinteger(a);

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
