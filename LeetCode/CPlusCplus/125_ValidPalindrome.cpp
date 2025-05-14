/*

125. Valid Palindrome

Given a string s, return true if it is a palindrome, otherwise return false.

A palindrome is a string that reads the same forward and backward. It is also case-insensitive and ignores all non-alphanumeric characters.


Example 1:
Input: s = "Was it a car or a cat I saw?"
Output: true
Explanation: After considering only alphanumerical characters we have "wasitacaroracatisaw", which is a palindrome.

Example 2:
Input: s = "tab a cat"
Output: false
Explanation: "tabacat" is not a palindrome.


Constraints:
1 <= s.length <= 1000
s is made up of only printable ASCII characters.

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.length() <= 1) return true;

        string strs = {};
        for (char c : s) {
            // if (isalnum(c))
            if (((c >= '0') && (c <= '9')) || ((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z'))) {
                strs += tolower(c);
            }
        }

        //return newStr == string(newStr.rbegin(), newStr.rend());
        int strLength = strs.length();
        for (int i = 0; i < strLength / 2; i++) {
            if (strs[i] != strs[strLength - i - 1]) {
                return false;
            }
        }

        return true;
    }
};

void runExample(string s, const string& label) {
    Solution solver;
    bool result = solver.isPalindrome(s);

    // Print Label
    cout << "=== " << label << " ===\n";

    // Print Input
    cout << "Input: s = [ \"" << s << "\" ]\n";

    // Print Output
    if (result) cout << "Output: true";
    else cout << "Output: false";
    cout << "\n\n";
}

int main() {
    string example1_str = "Was it a car or a cat I saw?";
    string example2_str = "tab a cat";

    runExample(example1_str, "Example 1");
    runExample(example2_str, "Example 2");

    return 0;
}