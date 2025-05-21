/*

704. Binary Search

You are given an array of distinct integers nums, sorted in ascending order, and an integer target.

Implement a function to search for target within nums. If it exists, then return its index, otherwise, return -1.

Your solution must run in O(logn) time.


Example 1:
Input: nums = [-1,0,2,4,6,8], target = 4
Output: 3

Example 2:
Input: nums = [-1,0,2,4,6,8], target = 3
Output: -1


Constraints:
1 <= nums.length <= 10000.
-10000 < nums[i], target < 10000

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while ((l <= r)) {
            int n = l + (r - l) / 2;
            cout << "l = " << l << ", r = " << r << ", n = " << n << "\n";
            if (nums[n] > target) {
                r = n - 1;
            } else if (nums[n] < target) {
                l = n + 1;
            } else {
                return n;
            }
        }

        return -1;
    }
};

void runExample(vector<int>& nums, int target, const string& label) {
    Solution solver;
    int result = solver.search(nums, target);

    // Print Label
    cout << "=== " << label << " ===\n";

    // Print Input
    cout << "Input: nums = [ ";
    for (int num : nums) cout << num << " ";
    cout << "], target = " << target << "\n";

    // Print Output
    cout << "Output: " << result << "\n\n";
}

int main() {
    vector<int> example1_nums = { -1,0,2,4,6,8 };
    int example1_target = 4;
    vector<int> example2_nums = { -1,0,2,4,6,8 };
    int example2_target = 3;

    runExample(example1_nums, example1_target, "Example 1");
    runExample(example2_nums, example2_target, "Example 2");

    return 0;
}