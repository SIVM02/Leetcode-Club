/*
 * DATE: 06/10/2026
 *
 * PROBLEM LINK: https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem
 * PROBLEM STATEMENT: 
 *         There is a new mobile game that starts with consecutively numbered clouds. Some of the clouds are thunderheads and others are cumulus. The player can jump on any cumulus cloud having a number that is equal to the number of the current cloud plus 1 or 2. The player must avoid the thunderheads. Determine the minimum number of jumps it will take to jump from the starting postion to the last cloud. It is always possible to win the game.

For each game, you will get an array of clouds numbered 0 if they are safe or 1 if they must be avoided.

Example:-
c = [0, 1, 0, 0, 0, 1, 0]

Index the array from 0...6. The number on each cloud is its Index in the list so the player must avoid the clouds at indices 1 and 5. They could follow these two paths: 0-2-4-6 or 0-2-3-4-6. The first path takes 3 jumps while the second takes 4. Return 3.

Function Description:-
Complete the jumpingOnClouds function in the editor below.

JumpingOnClouds has the following parameter(s):
      int c[n]: an array of binary integers

Returns
int: the minimum number of jumps required

Input Format:-
The first line contains an integer n, the total number of clouds. The second line contains n space-separated binary integers describing clouds c[1] where 0 <= i < n.

Constraints:-
2 <= n <= 100
c[i] belong to {0, 1}
c[0] = c[n - 1] = 0

Output Format
Print the minimum number of jumps needed to win the game.

Sample Input 0
7
0 0 1 0 0 1 0

Sample Output 0
4

Explanation 0:
The player must avoid c[2] and c[5]. The game can be won with a minimum of 4 jumps.

 * __________________________________________________
 * Write statement notes here
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 *
 *      - This is a GREEDY problem.
 *      - At every cloud, try to jump 2 positions first.
 *        - If the cloud at i + 2 is safe, take the +2 jump.
 *        - Otherwise, take the +1 jump.
 * 
 * - Important condition:
 *      i + 2 < c.size()
 *          -> Make sure i + 2 is inside the array.
 *
 *      c[i + 2] == 0
 *          -> Make sure the destination is safe.
 * 
 * COMPLEXITY:
 * - Time Complexity: O(n)
 * - Space Complexity: O(1)
 * __________________________________________________
 * Write insights here
 *      - If +2 is not possible, +1 must be taken because the problem guarantees that the game can always be won.
 * __________________________________________________
 *
 */

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'jumpingOnClouds' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY c as parameter.
 */

int jumpingOnClouds(vector<int> c) {
    int count = 0;
    for (int i = 0; i < c.size() - 1; i++){
            if(i + 2 < c.size() && c[i+2] == 0){
                count++;
                i++;
            }else{
                count++;
            }
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split(rtrim(c_temp_temp));

    vector<int> c(n);

    for (int i = 0; i < n; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = jumpingOnClouds(c);

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
