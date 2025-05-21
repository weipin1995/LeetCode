/*

739. Daily Temperatures

You are given an array of integers temperatures where temperatures[i] represents the daily temperatures on the ith day.

Return an array result where result[i] is the number of days after the ith day before a warmer temperature appears on a future day. If there is no day in the future where a warmer temperature will appear for the ith day, set result[i] to 0 instead.


Example 1:
Input: temperatures = [30,38,30,36,35,40,28]
Output: [1,4,1,2,1,0,0]

Example 2:
Input: temperatures = [22,21,20]
Output: [0,0,0]

Constraints:
1 <= temperatures.length <= 1000.
1 <= temperatures[i] <= 100

*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> stack;

        for (int i = 0; i < temperatures.size(); i++) {
            int t = temperatures[i];

            while (!stack.empty() && t > stack.top().first) {
                auto pair = stack.top();
                stack.pop();
                res[pair.second] = i - pair.second;
                
                cout << "Result: [ ";
                for (int i : res) {
                    cout << i << " ";
                }
                cout << "]\n";
            }

            stack.push({t, i});
        }

        return res;
    }
};


void runExample(vector<int>& temperatures, const string& label) {
    Solution solver;
    vector<int> result = solver.dailyTemperatures(temperatures);

    // Print Label
    cout << "=== " << label << " ===\n";

    // Print Input
    cout << "Input: nums = [ ";
    for (int i : temperatures) {
        cout << i << " ";
    }
    cout << "]\n";

    // Print Output Vector<int>
    cout << "Outputs: [ ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << "]\n\n";
}

int main() {
    vector<int> example1_nums = { 30,38,30,36,35,40,28 };
    vector<int> example2_nums = { 22,21,20 };

    runExample(example1_nums, "Example 1");
    runExample(example2_nums, "Example 2");

    return 0;
}