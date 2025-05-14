/*

42. Trapping Rain Water

You are given an array non-negative integers height which represent an elevation map. Each value height[i] represents the height of a bar, which has a width of 1.

Return the maximum area of water that can be trapped between the bars.


Example 1:
Input: height = [0,2,0,3,1,0,1,3,2,1]
Output: 9


Constraints:
1 <= height.length <= 1000
0 <= height[i] <= 1000

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) return 0;
        int l = 0;
        int r = height.size() - 1;
        int maxL = height[l];
        int maxR = height[r];
        int res = 0;

        while (l < r) {
            if (maxL < maxR) {
                l++;
                maxL = max(height[l], maxL);
                // Inpossible to be negative
                res += maxL - height[l];
            }
            else {
                r--;
                maxR = max(height[r], maxR);
                res += maxR - height[r];
            }
        }

        return res;
    }
};

void runExample(vector<int>& height, const string& label) {
    Solution solver;
    int result = solver.trap(height);

    // Print Label
    cout << "=== " << label << " ===\n";

    // Print Input
    cout << "Input: height = [ ";
    for (int i : height) {
        cout << i << " ";
    }
    cout << "]\n";

    // Print Output
    cout << "Outputs: [ " << result << " ]\n\n";
}

int main() {
    vector<int> example1_nums = { 0,2,0,3,1,0,1,3,2,1 };

    runExample(example1_nums, "Example 1");

    return 0;
}