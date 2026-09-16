/*
 * DATE: 17/09/2026
 *
 * PROBLEM LINK: https://www.hackerrank.com/challenges/drawing-book/problem
 * PROBLEM STATEMENT:
 * 
 *    A teacher asks the class to open their books to a page number. A student can either start turning pages from the front of the book or from the back of the book. They always turn pages one at a time. When they open the book, page 1 is always on the right side:
 * 
 *  ! IMAGE ARE NOT LONGER AVAILABLE IN A HACKERRANK
 * 
 *  When they flip page 1, they see pages 2 and 3. Each page except the last page will always be printed on both sides. The last page may only be printed on the front, given the length of the book. If the book n is  pages long, and a student wants to turn to page p, what is the minimum number of pages to turn? They can start at the beginning or the end of the book.

Given n and p, find and print the minimum number of pages that must be turned in order to arrive at page p.
Example
n = 5
p = 3

! IMAGE ARE NOT LONGER AVAILABLE IN A HACKERRANK
Using the diagram above, if the student wants to get to page 3, they open the book to page 1, flip 1 page and they are on the correct page. If they open the book to the last page, page 5, they turn 1 page and are at the correct page. Return 1.

Function Description:-
Complete the pageCount function in the editor below.
pageCount has the following parameter(s):-
    int n: the number of pages in the book
    int p: the page number to turn to
Returns
  int: the minimum number of pages to turn

Input Format:-
The first line contains an integer n, the number of pages in the book.
The second line contains an integer, p, the page to turn to.

Constraints
    1 ≤ n ≤ 10^5
    1 ≤ p ≤ n

Sample Input O
6
2

Sample Output O
1

Explanation O:-
If the student starts turning from page 1, they only need to turn 1 page:
    ! IMAGE ARE NOT LONGER AVAILABLE IN A HACKERRANK
If a student starts turning from page 6, they need to turn 2 pages:
    ! IMAGE ARE NOT LONGER AVAILABLE IN A HACKERRANK
Return the minimum value, 1.

Sample Input 1
5 
4

Sample Output 1
0

Explanation 1
If the student starts turning from page 1, they need to turn 2 pages:
    ! IMAGE ARE NOT LONGER AVAILABLE IN A HACKERRANK

If they start turning from page 5, they do not need to turn any pages:
    ! IMAGE ARE NOT LONGER AVAILABLE IN A HACKERRANK
Return the minimum value, 0.
 * __________________________________________________
 * Write statement notes here
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 * 
 *
 * METHOD 1: Parity Check on Total Pages (n)
 * - Front turns: p / 2 (each flip covers 2 pages).
 * - Back turns: Depends on whether total pages 'n' is even or odd:
 *     If n is odd : (n - p) / 2  -> Last page shares spread with (n - 1).
 *     If n is even: (n - p + 1) / 2 -> Page n is alone, extra turn needed.
 * Result: min(front, back)
 *
 * METHOD 2: Direct Math (Total Flips - Target Flips)
 * ---------------------------------------------------
 * - Front turns: p / 2
 * - Back turns : (n / 2) - (p / 2) -> Total book flips minus target flips.
 * - Result: min(front, back)
 * __________________________________________________
 * Write insights here
 *      Complexity:
 *           Time: O(1).
 *           Space : O(1).
 * __________________________________________________
 *
 */


 #include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'pageCount' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER p
 */

int pageCount(int n, int p) {
    //METHOD 1
    int back;
    if(n % 2 == 0){
        back = (n - p + 1) / 2;
    }else {
        back = (n-p)/2 ;
    }
    int front = p / 2;
    if(front < back){
        return front;
    }
    return back ;
    // METHOD 2
    // Total turns to reach page p from the front
    int front = p / 2;
    
    // Total turns to reach page p from the back
    int back = (n / 2) - (p / 2);
    
    // Return the minimum of the two directions
    return min(front, back);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string p_temp;
    getline(cin, p_temp);

    int p = stoi(ltrim(rtrim(p_temp)));

    int result = pageCount(n, p);

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
