/*

49. Group Anagrams

Given an array of strings strs, group all anagrams together into sublists. You may return the output in any order.

An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.


Example 1:
Input: strs = ["act","pots","tops","cat","stop","hat"]
Output: [["hat"],["act", "cat"],["stop", "pots", "tops"]]

Example 2:
Input: strs = ["x"]
Output: [["x"]]

Example 3:
Input: strs = [""]
Output: [[""]]


Constraints:
1 <= strs.length <= 1000.
0 <= strs[i].length <= 100
strs[i] is made up of lowercase English letters.

*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;

        for (const string& s : strs) {
            unordered_map<char, int> count;

            for (char c : s) {
                count[c]++;
            }

            string key;
            for (int i = 0; i < 256; i++) {
                key += ',' + to_string(count[i]);
            }

            res[key].push_back(s);
        }

        vector<vector<string>> result;
        for (auto& pair : res) {
            result.push_back(pair.second);
        }

        return result;
    }
};

void runExample(vector<string> strs, const string& label) {
    Solution solver;
    vector<vector<string>> result = solver.groupAnagrams(strs);

    // Print Label
    cout << "=== " << label << " ===\n";

    // Print Input
    cout << "Input: strs = [ ";
    for (const string& str : strs) {
        cout << str << " ";
    }
    cout << "]\n";

    // Print Output
    cout << "Output: [";
    for (const auto& group : result) {
        cout << " [ ";
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << "]";
    }
    cout << " ]\n\n";
}

int main() {
    vector<string> example1_strs = { "act", "pots", "tops", "cat", "stop", "hat" };
    vector<string> example2_strs = { "x" };
    vector<string> example3_strs = { "" };

    runExample(example1_strs, "Example 1");
    runExample(example2_strs, "Example 2");
    runExample(example3_strs, "Example 3");

    return 0;
}