/*

347. Top K Frequent Elements

Given an integer array nums and an integer k, return the k most frequent elements within the array.

The test cases are generated such that the answer is always unique.

You may return the output in any order.


Example 1:
Input: nums = [1,2,2,3,3,3], k = 2
Output: [2,3]

Example 2:
Input: nums = [7,7], k = 1
Output: [7]


Constraints:
1 <= nums.length <= 10^4.
-1000 <= nums[i] <= 1000
1 <= k <= number of distinct elements in nums.

*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        vector<pair<int, int>> arr;
        for (const auto& p : count) {
            arr.push_back({ p.second, p.first });
        }
        sort(arr.rbegin(), arr.rend());

        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(arr[i].second);
        }
        return res;
    }
};

void runExample(vector<int>& nums, int k, const string& label) {
    Solution solver;
    vector<int> result = solver.topKFrequent(nums, k);

    // Print Label
    cout << "=== " << label << " ===\n";

    // Print Input
    cout << "Input: nums = [ ";
    for (int i : nums) {
        cout << i << " ";
    }
    cout << "], k = " << k << "\n";

    // Print Output
    cout << "Outputs: [ ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << "]\n\n";
}

int main() {
    vector<int> example1_nums = { 1, 2, 2, 3, 3, 3 };
    int example1_k = 2;

    vector<int> example2_nums = { 7, 7 };
    int example2_k = 1;

    runExample(example1_nums, example1_k, "Example 1");
    runExample(example2_nums, example2_k, "Example 2");

    return 0;
}