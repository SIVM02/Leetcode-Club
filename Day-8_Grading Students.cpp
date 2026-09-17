/*
 * DATE: 18/09/2026
 *
 * PROBLEM LINK: https://www.hackerrank.com/challenges/grading/problem
 * PROBLEM STATEMENT:
 *HackerLand University has the following grading policy:

      Every student receives a grade in the inclusive range from 0 to 100.
      Any grade less than 40 is a failing grade.

Sam is a professor at the university and likes to round each student's grade according to these rules:
    If the difference between the grade and the next multiple of 5 is less than 3, round grade up to the next multiple of 5.

    If the value of grade is less than 38, no rounding occurs as the result will still be a failing grade.

Examples
  grade = 84 round to 85 (85 - 84 is less than 3)
  grade = 29 do not round (result is less than 38)
  grade = 57 do not round (60 - 57 is 3 or higher)

Given the initial value of grade for each of Sam's n students, write code to automate the rounding process.

Function Description:-
  Complete the function grading Students with the following parameter(s):
  int grades [n]: the grades before rounding

Returns:-
  int [n]: the grades after rounding

Input Format:-
  The first line contains a single integer, n, the number of students.
  Each line i of the n subsequent lines contains a single integer, grades [i].

Constraints
  1 ≤ n ≤ 60

• 0 ≤ grades[i] ≤ 100

Sample Input O
4
73
67
38
33

Sample Output O
75
67
40
33

Explanation O

    ! IMAGE ARE NOT LONGER AVAILABLE IN A HACKERRANK

1. Student 1 received a 73, and the next multiple of 5 from 73 is 75. Since 75 - 73 < 3, the student's grade is rounded to 75.

2. Student 2 received a 67, and the next multiple of 5 from 67 is 70. Since 70 - 67 = 3, the grade will not be modified and the student's final grade is 67.

3. Student 3 received a 38, and the next multiple of 5 from 38 is 40. Since 40 - 38 < 3, the student's grade will be rounded to 40.

4. Student 4 received a grade below 33, so the grade will not be modified and the student's final grade is 33.


 * __________________________________________________
 * Write statement notes here
        APPROACH:
            For each grade:
                1. If the grade is less than 38, keep it unchanged because it is already a failing grade.
                2. If the grade is 38 or more, check its remainder when divided by 5.
                3. If the remainder is 3 or 4, the next multiple of 5 is less than 3 marks away, so round the grade up.
                4. Otherwise, keep the original grade.
 * ___________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 * __________________________________________________
 * Write insights here
 *      - Use modulo (%) to find how far a number is from a multiple of 5.
 *      - If grade % 5 >= 3, round to the next multiple of 5.
 *      - Always check grade >= 38 before rounding.
 *      - Next multiple of 5 can be calculated as:
                (grade / 5 + 1) * 5
 *      - Integer division in C++ automatically gives the required quotient.
 *      - Time Complexity: O(n)
 *      - Space Complexity: O(n) for the result vector.
 *                 ____________________________
 *
 */

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'gradingStudents' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY grades as parameter.
 */

vector<int> gradingStudents(vector<int> grades) {
    int n = grades.size();
    vector<int> updatedResult(n);
    int result ;
    for(int i = 0 ; i < n ; i++){
        // if grade = 20 , skip if condition then goes to else statement and return same grade {updatedResult[i] = grades[i]}
        // if grade >= 38 and we need to check the remainder is >= 3 then goes to if condition otherwise else condition.
        if(grades[i] >= 38 && grades[i] % 5 >= 3){
            int quotient = grades[i] /  5;
            result = (quotient + 1) * 5;
            updatedResult[i] = result ; 
        }else{
            updatedResult[i] = grades[i];
        }
    }
    return updatedResult;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string grades_count_temp;
    getline(cin, grades_count_temp);

    int grades_count = stoi(ltrim(rtrim(grades_count_temp)));

    vector<int> grades(grades_count);

    for (int i = 0; i < grades_count; i++) {
        string grades_item_temp;
        getline(cin, grades_item_temp);

        int grades_item = stoi(ltrim(rtrim(grades_item_temp)));

        grades[i] = grades_item;
    }

    vector<int> result = gradingStudents(grades);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
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
