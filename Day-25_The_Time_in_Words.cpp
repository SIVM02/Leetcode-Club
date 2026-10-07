/*
 * DATE: 07/10/2026
 *
 * PROBLEM LINK: https://www.hackerrank.com/challenges/the-time-in-words/problem
 * PROBLEM STATEMENT:
 *          Given the time in numerals we may convert it into words, as shown below:

5:00 --> five o' clock
5:01 --> one minute past five
5:10 --> ten minutes past five
5:15 --> quarter past five
5:30 --> half past five
5:40 --> twenty minutes to six
5:45 --> quarter to six
5:47 --> thirteen minutes to six
5:28 --> twenty eight minutes past five

At minutes = 0, use o'clock. For 1 ≤ minutes ≤ 30, use past, and for 30 < minutes use to. Note the space between the apostrophe and clock in o' clock. Write a program which prints the time in words for the input given in the format described.

Function Description:-
Complete the timeinWords function in the editor below.

timelnWords has the following parameter(s):

int h: the hour of the day
int m: the minutes after the hour

Returns:-
string: a time string as described

Input Format:-
The first line contains h, the hours portion The second line contains m, the minutes portion

Constraints
1 ≤ h ≤ 12
0 ≤ m < 60

 * __________________________________________________
 * Write statement notes here
 * 
 *  --> Store number words from 0 to 19 in an array because these numbers have unique English names.
 * 
 *  --> Store the tens words separately:
        20 -> twenty
        30 -> thirty
        40 -> forty
        50 -> fifty
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 * 
 *      --> Break the problem into small cases instead of trying to convert every time using one complicated formula.
 *      --> Always check boundary values such as:
                0, 1, 15, 20, 29, 30, 31, 40, 45, 59
        
        --> Special cases are important:
            0  -> o' clock
            1  -> one minute
            15 -> quarter
            30 -> half
            45 -> quarter
            59 -> one minute to next hour

        --> Pay attention to singular/plural words:
            1 minute
            2 minutes
        
        --> The modulo operator (%) is useful for extracting the last digit.
            Example:
                28 % 10 = 8

 * __________________________________________________
 * Write insights here
 * __________________________________________________
 *
 */

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'timeInWords' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER h
 *  2. INTEGER m
 */

string timeInWords(int h, int m) {
    string Numbers[] = {
        "zero" , "one" , "two" , "three" , "four" , "five" , "six" , "seven" , "eight" , "nine" , "ten" , "eleven" , "twelve" , "thirteen" , "fourteen" , "fifteen" , "sixteen" , "seventeen" , "eighteen" , "nineteen"
    };
    string Tens[] = {
        "twenty" , "thirty" , "forty" , "fifty"
    };

    if(m == 0){
        return Numbers[h] + " o' clock"; 
    }
    if(m == 1){
        return Numbers[1] + " minute past " + Numbers[h];
    }
    if(m == 59){
        return "one minute to " + Numbers[(h % 12) + 1];
    }
    if(m > 1 && m <= 30){
        if(m == 15){
            return "quarter past " + Numbers[h];  
        }
        if(m == 30){
            return "half past " + Numbers[h];
        }
        if(m == 20){
            return Tens[0] + " minutes past " + Numbers[h];
        }
        if(m < 20){
            return Numbers[m] + " minutes past " + Numbers[h];
        }
        if(m > 20 && m < 30){
            return Tens[0] + " " + Numbers[m % 10] + " minutes past " + Numbers[h];
        }
    }
    if(m > 30 && m < 59){
        if(m == 45){
            return "quarter to " + Numbers[(h % 12) + 1];
        }
        if(m > 30 && m < 40){
            return Tens[0] + " " + Numbers[(60- m) % 10] + " minutes to " + Numbers[(h % 12) + 1];
        }
        if(m == 40){
            return Tens[0] + " minutes to " + Numbers[(h % 12) + 1];
        }
        if(m > 40){
            return Numbers[60-m] + " minutes to " + Numbers[(h % 12) + 1];
        }
    }
    return "";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string h_temp;
    getline(cin, h_temp);

    int h = stoi(ltrim(rtrim(h_temp)));

    string m_temp;
    getline(cin, m_temp);

    int m = stoi(ltrim(rtrim(m_temp)));

    string result = timeInWords(h, m);

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
