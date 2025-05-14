/*

238. Product Of Array Except Self

Given an integer array nums, return an array output where output[i] is the product of all the elements of nums except nums[i].

Each product is guaranteed to fit in a 32-bit integer.

Follow-up: Could you solve it in O(n) time without using the division operation?


Example 1:
Input: nums = [1,2,4,6]
Output: [48,24,12,8]

Example 2:
Input: nums = [-1,0,1,2,3]
Output: [0,-6,0,0,0]


Constraints:
2 <= nums.length <= 1000
-20 <= nums[i] <= 20

*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // set all elements to 1, because 1 * n = n itself
        vector<int> res(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }

        int postfix = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            res[i] *= postfix;
            postfix *= nums[i];
        }

        return res;
    }
};

void runExample(vector<int>& nums, const string& label) {
    Solution solver;
    vector<int> result = solver.productExceptSelf(nums);

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
    for (int i : result) {
        cout << i << " ";
    }
    cout << "]\n\n";
}

int main() {
    vector<int> example1_nums = { 1, 2, 4, 6 };
    vector<int> example2_nums = { -1, 0, 1, 2, 3 };

    runExample(example1_nums, "Example 1");
    runExample(example2_nums, "Example 2");

    return 0;
}