/*
 * DATE: 09/11/2026
 *
 * PROBLEM LINK: https://leetcode.com/problems/convert-the-temperature/description/
 * PROBLEM STATEMENT:
 *        You are given a non-negative floating point number rounded to two decimal places celsius, that denotes the temperature in Celsius.
You should convert Celsius into Kelvin and Fahrenheit and return it as an array ans = [kelvin, fahrenheit].
Return the array ans. Answers within 10-5 of the actual answer will be accepted.

Note that:
Kelvin = Celsius + 273.15
Fahrenheit = Celsius * 1.80 + 32.00
 
Example 1:
Input: celsius = 36.50
Output: [309.65000,97.70000]
Explanation: Temperature at 36.50 Celsius converted in Kelvin is 309.65 and converted in Fahrenheit is 97.70.

Example 2:
Input: celsius = 122.11
Output: [395.26000,251.79800]
Explanation: Temperature at 122.11 Celsius converted in Kelvin is 395.26 and converted in Fahrenheit is 251.798.
 
Constraints:
0 <= celsius <= 1000

 * __________________________________________________
 * Write statement notes here
 * __________________________________________________
 *
 * INSIGHTS GAIN FROM THIS QUESTION: ( ANY NOTES, IDEAS, NEW TRICKS / THIS WILL HELP IN QUICK REVISION )
 * 
 *        1} Direct mathematical formulas: Temperature conversion can be solved directly using the given formulas.
          2} Kelvin conversion: celsius + 273.15
          3} Fahrenheit conversion: celsius * 1.80 + 32.00
          4} Use of double: Use double instead of int to preserve decimal values and precision.
          5} Vector initialization: Return both answers directly using {k, f}.
          6} No loops required: Simple mathematical calculations solve the problem.
          7} Complexity Analysis
                Time:O(1)
                Space: O(1) auxiliary space.
 * __________________________________________________
 * Write insights here
 * __________________________________________________
 *
 */

class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        double k = celsius + 273.15;
        double f = celsius * 1.80 + 32.00;
        return {k,f};
    }
};