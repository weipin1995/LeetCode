/*

11. Container With Most Water

You are given an integer array heights where heights[i] represents the height of the ith bar.

You may choose any two bars to form a container. Return the maximum amount of water a container can store.


Example 1:
Input: height = [1,7,2,5,4,7,3,6]
Output: 36

Example 2:
Input: height = [2,2,2]
Output: 4


Constraints:
2 <= height.length <= 1000
0 <= height[i] <= 1000

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int maxValue = 0;

        while (r > l) {
            int temp = (r - l) * min(heights[r], heights[l]);
            if (temp > maxValue) maxValue = temp;
            if (r < l) {
                r--;
            }
            else
            {
                l++;
            }
        }

        return maxValue;
    }
};

void runExample(vector<int> heights, const string& label) {
    Solution solver;
    int result = solver.maxArea(heights);

    // Print Label
    cout << "=== " << label << " ===\n";

    // Print Input
    cout << "Input: height = [ ";
    for (int i : heights) {
        cout << i << " ";
    }
    cout << "]\n";

    // Print Output
    cout << "Outputs: [ " << result << " ]\n\n";
}

int main() {
    vector<int> example1_nums = { 1,7,2,5,4,7,3,6 };
    vector<int> example2_nums = { 2,2,2 };

    runExample(example1_nums, "Example 1");
    runExample(example2_nums, "Example 2");

    return 0;
}