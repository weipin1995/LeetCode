/*

1. Two Sum

Given an array of integers nums and an integer target, return the indices i and j such that nums[i] + nums[j] == target and i != j.

You may assume that every input has exactly one pair of indices i and j that satisfy the condition.

Return the answer with the smaller index first.


Example 1:
Input: nums = [3,4,5,6], target = 7
Output: [0,1]
Explanation: nums[0] + nums[1] == 7, so we return [0, 1].

Example 2:
Input: nums = [4,5,6], target = 10
Output: [0,2]

Example 3:
Input: nums = [5,5], target = 10
Output: [0,1]


Constraints:
2 <= nums.length <= 1000
-10,000,000 <= nums[i] <= 10,000,000
-10,000,000 <= target <= 10,000,000

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> num_map;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (num_map.count(complement)) {
                return { num_map[complement], i };
            }

            num_map[nums[i]] = i;
        }

        return{};
    }
};

void runTwoSumExample(vector<int>& nums, int target, const string& label) {
    Solution solver;
    vector<int> result = solver.twoSum(nums, target);

    // Print Label
    cout << "=== " << label << " ===\n";
    
    // Print Input
    cout << "Input: nums = [ ";
    for (int num : nums) cout << num << " ";
    cout << "], target = " << target << "\n";

    // Print Output
    if (!result.empty()) {
        cout << "Output: [ " << result[0] << ", " << result[1] << " ]\n\n";
    }
    else {
        cout << "Output: No valid pair found.\n\n";
    }
}

int main() {
    vector<int> example1_nums = { 3, 4, 5, 6 };
    int example1_target = 7;

    vector<int> example2_nums = { 4, 5, 6 };
    int example2_target = 10;

    vector<int> example3_nums = { 5, 5 };
    int example3_target = 10;

    runTwoSumExample(example1_nums, example1_target, "Example 1");
    runTwoSumExample(example2_nums, example2_target, "Example 2");
    runTwoSumExample(example3_nums, example3_target, "Example 3");

    return 0;
}