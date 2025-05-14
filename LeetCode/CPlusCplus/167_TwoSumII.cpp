/*

167. Two Sum II - Input Array Is Sorted

Given an array of integers numbers that is sorted in non-decreasing order.

Return the indices (1-indexed) of two numbers, [index1, index2], such that they add up to a given target number target and index1 < index2. Note that index1 and index2 cannot be equal, therefore you may not use the same element twice.

There will always be exactly one valid solution.

Your solution must use O(1) additional space.


Example 1:
Input: numbers = [1,2,3,4], target = 3
Output: [1,2]
Explanation:
The sum of 1 and 2 is 3. Since we are assuming a 1-indexed array, index1 = 1, index2 = 2. We return [1, 2].


Constraints:
2 <= numbers.length <= 1000
-1000 <= numbers[i] <= 1000
-1000 <= target <= 1000

*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> res;

        int index = 0;
        int complementary = 0;
        for (int n : numbers) {

            if (~res.count(n)) {
                res[n] = index;
                index++;
            }
        }

        for (auto& entry : res) {
            int complementary = target - entry.first;
            if (res.count(complementary)) {
                return { entry.second + 1, res[complementary] + 1 };
            }
        }

        return {};
    }
};

void runExample(vector<int>& numbers, int target, const string& label) {
    Solution solver;
    vector<int> result = solver.twoSum(numbers, target);

    // Print Label
    cout << "=== " << label << " ===\n";

    // Print Input
    cout << "Input: numbers = [ ";
    for (int i : numbers) {
        cout << i << " ";
    }
    cout << "], target = " << target << "\n";

    // Print Output
    cout << "Outputs: [ ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << "]\n\n";
}

int main() {
    vector<int> example1_nums = { 1, 2, 3, 4 };
    int example1_target = 3;

    runExample(example1_nums, example1_target, "Example 1");

    return 0;
}