/*

84. Largest Rectangle In Histogram

You are given an array of integers heights where heights[i] represents the height of a bar. The width of each bar is 1.

Return the area of the largest rectangle that can be formed among the bars.

Note: This chart is known as a histogram.


Example 1:
Input: heights = [7,1,7,2,2,4]
Output: 8

Example 2:
Input: heights = [1,3,7]
Output: 7


Constraints:
1 <= heights.length <= 1000.
0 <= heights[i] <= 1000

*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<int> stack;

        for (int i = 0; i <= n; i++) {
            while (!stack.empty() && (i == n || heights[stack.top()] >= heights[i])) {
                int height = heights[stack.top()];
                stack.pop();
                int width = stack.empty() ? i : i - stack.top() - 1;
                maxArea = max(maxArea, height * width);
            }

            stack.push(i);
        }

        return maxArea;
    }
};

void runExample(vector<int>& heights, const string& label) {
    Solution solver;
    int result = solver.largestRectangleArea(heights);

    // Print Label
    cout << "=== " << label << " ===\n";

    // Print Input
    cout << "Input: heights = [ ";
    for (int i : heights) {
        cout << i << " ";
    }
    cout << "]\n";

    // Print Output Vector
    cout << "Outputs: " << result << "\n\n";
}

int main() {
    vector<int> example1_nums = { 7,1,7,2,2,4 };
    vector<int> example2_nums = { 1,3,7 };

    runExample(example1_nums, "Example 1");
    runExample(example2_nums, "Example 2");

    return 0;
}