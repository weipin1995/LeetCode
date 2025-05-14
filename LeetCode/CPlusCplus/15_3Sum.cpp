/*

15. 3Sum

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] where nums[i] + nums[j] + nums[k] == 0, and the indices i, j and k are all distinct.

The output should not contain any duplicate triplets. You may return the output and the triplets in any order.


Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].

Example 2:
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.


Constraints:
3 <= nums.length <= 1000
-10^5 <= nums[i] <= 10^5

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum > 0) {
                    r--;
                }
                else if (sum < 0) {
                    l++;
                }
                else {
                    res.push_back({ nums[i], nums[l], nums[r] });
                    l++;
                    r--;
                }
            }
        }
        return res;
    }
};

void runExample(vector<int>& nums, const string& label) {
    Solution solver;
    vector<vector<int>> result = solver.threeSum(nums);

    // Print Label
    cout << "=== " << label << " ===\n";

    // Print Input
    cout << "Input: nums = [ ";
    for (int i : nums) {
        cout << i << " ";
    }
    cout << "]\n";

    // Print Output
    cout << "Outputs: [ ";
    for (const auto& row : result) {
        cout << "[ ";
        for (int val : row) {
            cout << val << " ";
        }
        cout << "] ";
    }
    cout << "]\n\n";
}

int main() {
    vector<int> example1_nums = { -1,0,1,2,-1,-4 };
    vector<int> example2_nums = { 0, 1, 1 };
    vector<int> example3_nums = { 0, 0, 0 };

    runExample(example1_nums, "Example 1");
    runExample(example2_nums, "Example 2");
    runExample(example3_nums, "Example 3");

    return 0;
}