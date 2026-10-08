/*
 * DATE: 09/10/2026
 *
 * PROBLEM LINK: https://www.hackerrank.com/challenges/encryption/problem
 * PROBLEM STATEMENT:
 *        An English text needs to be encrypted using the following encryption scheme.
First, the spaces are removed from the text. Let & be the length of this text.
Then, characters are written into a grid, whose rows and columns have the following constraints:

[√L] ≤ row ≤ column ≤ [√L], where [x] is floor function and [x] is ceil function

Example:-
s = if man was meant to stay on the ground god would have given us roots

After removing spaces, the string is 54 characters long. √54 is between 7 and 8, so it is written in the form of a grid with 7 rows and 8 columns.

ifmanwas
meanttos
tayonthe
groundgo
dwouldha
vegivenu
sroots


Ensure that rows x columns ≤ L

If multiple grids satisfy the above conditions, choose the one with the minimum area, ie, rows x columns.

The encoded message is obtained by displaying the characters of each column, with a space between column texts. The encoded message for the grid above is:

imtgdvs fearwer mayoogo αnouυiο ntnnlvt wttddes aohghn sseoau

Create a function to encode a message.
Function Description:-

Complete the encryption function in the editor below.

encryption has the following parameter(s):
string s: a string to encrypt

Returns:-
string: the encrypted string

Input Format:-
One line of text, the string s

Constraints:-
1 ≤ length of s ≤ 81
s contains characters in the range ascii[a-z] and space, ascii(32).


 * __________________________________________________
 * Write statement notes here
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 * __________________________________________________
 * Write insights here
 *      -->Grid Sizing: rows = floor(√L), cols = ceil(√L). 
 *      -->If (rows * cols < L), just do rows++.
 *      
 *      -->The condition j < Length automatically handles incomplete last rows without going out-of-bounds.
 * __________________________________________________
 *
 */

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'encryption' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string encryption(string s) {
    // First remove the all spaces from a string.
    string cleared = "";
    for(int i = 0 ; i < s.length() ; i++){
        if(s[i] != ' '){
            cleared = cleared + s[i]; 
        }
    }
    // storing the length of a cleared string, 
    // it is a length of a character in which no space between a words.
    int Length = cleared.length();
    
    // then i calculate the rows and column size 
    int rows = floor(sqrt(Length));
    int column = ceil(sqrt(Length));
    if(rows * column < Length){
        rows++ ;
    }
    string result = "";
    for(int i = 0 ; i < column ; i++){
        int j = i;
        while(j < Length){
            result = result + cleared[j];
            j = j + column ;
        }
        result = result + " ";
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
