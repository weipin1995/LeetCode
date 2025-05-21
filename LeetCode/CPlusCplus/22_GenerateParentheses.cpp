/*

22. Generate Parentheses

You are given an integer n. Return all well-formed parentheses strings that you can generate with n pairs of parentheses.


Example 1:
Input: n = 1
Output: ["()"]

Example 2:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
You may return the answer in any order.


Constraints:
1 <= n <= 7

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void backtrack(int openN, int closedN, int n, vector<string>& res, string& stack) {
        // Print Output
        cout << stack << "\n";

        if (openN == closedN && openN == n) {
            res.push_back(stack);
            cout << "Outputs: [ ";
            for (const string& str : res) {
                cout << "\"" << str << "\" ";
            }
            cout << "]\n\n";
            return;
        }

        if (openN < n) {
            stack += '(';
            backtrack(openN + 1, closedN, n, res, stack);
            stack.pop_back();
        }
        if (closedN < openN) {
            stack += ')';
            backtrack(openN, closedN + 1, n, res, stack);
            stack.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string stack;
        backtrack(0, 0, n, res, stack);
        return res;
    }
};

void runExample(int n, const string& label) {
    Solution solver;
    vector<string> result = solver.generateParenthesis(n);

    // Print Label
    cout << "=== " << label << " ===\n";

    // Print Input
    cout << "Input: n = "<< n << "\n";

    // Print Output
    cout << "Outputs: [ ";
    for (const string& str : result) {
        cout << "\"" << str << "\" ";
    }
    cout << "]\n\n";
}

int main() {
    int example1_num = 1;
    int example2_num = 3;

    runExample(example1_num, "Example 1");
    runExample(example2_num, "Example 2");

    return 0;
}