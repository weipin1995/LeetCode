/*

150. Evaluate Reverse Polish Notation

You are given an array of strings tokens that represents a valid arithmetic expression in Reverse Polish Notation.

Return the integer that represents the evaluation of the expression.

The operands may be integers or the results of other operations.
The operators include '+', '-', '*', and '/'.
Assume that division between integers always truncates toward zero.


Example 1:
Input: tokens = ["1","2","+","3","*","4","-"]
Output: 5
Explanation: ((1 + 2) * 3) - 4 = 5


Constraints:
1 <= tokens.length <= 1000.
tokens[i] is "+", "-", "*", or "/", or a string representing an integer in the range [-100, 100].

*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> rel;

        for (const string& s : tokens) {
            if (s == "+") {
                int a = rel.top(); rel.pop();
                int b = rel.top(); rel.pop();
                rel.push(b + a);
            } else if (s == "-") {
                int a = rel.top(); rel.pop();
                int b = rel.top(); rel.pop();
                rel.push(b - a);
            } else if (s == "*") {
                int a = rel.top(); rel.pop();
                int b = rel.top(); rel.pop();
                rel.push(b * a);
            } else if (s == "/") {
                int a = rel.top(); rel.pop();
                int b = rel.top(); rel.pop();
                rel.push(b / a);
            } else {
                rel.push(stoi(s));
            }
        }

        return rel.top();
    }

    //int evalRPN(vector<string>& tokens) {
    //    stack<int> rel;
    //    int temp = 0;
    //
    //    rel.push(stoi(tokens[0]));
    //
    //    for (int i = 1; i <= tokens.size()-1; i++) {
    //        if ((i % 2) == 1) {
    //            rel.push(stoi(tokens[i]));
    //        } else {
    //            temp = rel.top();
    //            rel.pop();
    //            
    //            if ((tokens[i]) == "+") {
    //                temp = rel.top() + temp;
    //            } else if ((tokens[i]) == "-") {
    //                temp = rel.top() - temp;
    //            } else if ((tokens[i]) == "*") {
    //                temp = rel.top() * temp;
    //            } else {
    //                temp = rel.top() / temp;
    //            }
    //            rel.pop();
    //            rel.push(temp);
    //        }
    //    }
    //
    //    return rel.top();
    //}
};

void runExample(vector<string>& tokens, const string& label) {
    Solution solver;
    int result = solver.evalRPN(tokens);

    // Print Label
    cout << "=== " << label << " ===\n";

    // Print Input Vector<String>
    cout << "Input: tokens = [ ";
    for (const string& s : tokens) {
        cout << "\"" << s << "\" ";
    }
    cout << "]\n";

    // Print Output
    cout << "Outputs: " << result << "\n\n";
}

int main() {
    vector<string> example1_strs = { "1","2","+","3","*","4","-" };

    runExample(example1_strs, "Example 1");

    return 0;
}