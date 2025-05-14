/*

128. Longest Consecutive Sequence

Given an array of integers nums, return the length of the longest consecutive sequence of elements that can be formed.

A consecutive sequence is a sequence of elements in which each element is exactly 1 greater than the previous element. The elements do not have to be consecutive in the original array.

You must write an algorithm that runs in O(n) time.


Example 1:
Input: nums = [2,20,4,10,3,4,5]
Output: 4
Explanation: The longest consecutive sequence is [2, 3, 4, 5].

Example 2:
Input: nums = [0,3,2,5,4,6,1,1]
Output: 7


Constraints:
0 <= nums.length <= 1000
-10^9 <= nums[i] <= 10^9

*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset;

        for (int n : nums) {
            uset.insert(n);
        }

        int longest = 0;
        for (int n : nums) {
            if (uset.count(n - 1) == false) {
                int length = 0;
                while (uset.count(n + length)) {
                    length++;
                }
                if (length > longest) longest = length;
            }
        }

        return longest;
    }
};

void runExample(vector<int>& nums, const string& label) {
    Solution solver;
    int result = solver.longestConsecutive(nums);

    // Print Label
    cout << "=== " << label << " ===\n";

    // Print Input
    cout << "Input: nums = [ ";
    for (int n : nums) {
        cout << n << " ";
    }
    cout << "]\n";

    // Print Output
    cout << "Output: " << result << "\n\n";
}

int main() {
    vector<int> example1_nums = { 2, 20, 4, 10, 3, 4, 5 };
    //vector<int> example2_nums = { 0, 3, 2, 5, 4, 6, 1, 1 };
    vector<int> example2_nums = { 1 };

    runExample(example1_nums, "Example 1");
    runExample(example2_nums, "Example 2");

    return 0;
}