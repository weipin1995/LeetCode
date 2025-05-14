/*

217. Contains Duplicate

Given an integer array nums, return true if any value appears more than once in the array, otherwise return false.


Example 1:
Input: nums = [1, 2, 3, 3]
Output: true

Example 2:
Input: nums = [1, 2, 3, 4]
Output: false

*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> uset;
        for (int i = 0; i < nums.size(); ++i) {
            if (uset.count(nums[i])) {
                return true;
            }

            uset.insert(nums[i]);
        }

        return false;
    }
};

void runContainsDuplicateExample(vector<int>& nums, const string& label) {
    Solution solver;
    bool result = solver.containsDuplicate(nums);

    // Print Label
    cout << "=== " << label << " ===\n";

    // Print Input
    cout << "Input: nums = [ ";
    for (int num : nums) cout << num << " ";
    cout << "]\n";

    // Print Output
    cout << "Output: " << (result ? "true" : "false") << "\n\n";
}

int main() {
    vector<int> example1_nums = { 1, 2, 3, 3 };
    vector<int> example2_nums = { 1, 2, 3, 4 };

    runContainsDuplicateExample(example1_nums, "Example 1");
    runContainsDuplicateExample(example2_nums, "Example 2");

    return 0;
}