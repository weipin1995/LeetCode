/*

20. Valid Parentheses

You are given a string s consisting of the following characters: '(', ')', '{', '}', '[' and ']'.

The input string s is valid if and only if:

Every open bracket is closed by the same type of close bracket.
Open brackets are closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
Return true if s is a valid string, and false otherwise.


Example 1:
Input: s = "[]"
Output: true

Example 2:
Input: s = "([{}])"
Output: true

Example 3:
Input: s = "[(])"
Output: false
Explanation: The brackets are not closed in the correct order.


Constraints:
1 <= s.length <= 1000

*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> closeToOpen = { {')', '('}, {']', '['}, {'}', '{'} };
        stack<char> res;

        for (char c : s) {
            if (closeToOpen.count(c)) {
                if (!res.empty() && res.top() == closeToOpen[c]) {
                    res.pop();
                } else {
                    return false;
                }
            } else {
                res.push(c);
            }
        }

        // return res.empty()
        if (res.empty()) {
            return true;
        } else {
            return false;
        }
    }
};

void runExample(string s, const string& label) {
    Solution solver;
    bool result = solver.isValid(s);

    // Print Label
    cout << "=== " << label << " ===\n";

    // Print Input
    cout << "Input: s = " << "\"" << s << "\"\n";

    // Print Output
    if (result) cout << "Output: true";
    else cout << "Output: false";
    cout << "\n\n";
}

int main() {
    string example1_s = "[]";
    string example2_s = "([{}])";
    string example3_s = "[(])";

    runExample(example1_s, "Example 1");
    runExample(example2_s, "Example 2");
    runExample(example3_s, "Example 3");

    return 0;
}