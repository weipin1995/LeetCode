/*

242. Valid Anagram

Given two strings s and t, return true if the two strings are anagrams of each other, otherwise return false.

An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.


Example 1:
Input: s = "racecar", t = "carrace"
Output: true

Example 2:
Input: s = "jar", t = "jam"
Output: false


Constraints:
s and t consist of lowercase English letters.

*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<int, int> countS;

        if (s.length() != t.length()) {
            return false;
        }

        for (char c : s) {
            countS[c]++;
        }

        for (char c : t) {
            if (countS[c] <= 0) {
                return false;
            }
            countS[c]--;
        }

        return true;
    }
};

void runValidAnagramExample(string s, string t, const string& label) {
    Solution solver;
    bool result = solver.isAnagram(s, t);

    // Print Label
    cout << "=== " << label << " ===\n";

    // Print Input
    cout << "Input: s = \"" << s << "\", t = \"" << t << "\"\n";

    // Print Output
    if (result) {
        cout << "Output: true\n\n";
    }
    else {
        cout << "Output: false\n\n";
    }
}

int main() {
    string example1_s = "racecar";
    string example1_t = "carrace";

    string example2_s = "jar";
    string example2_t = "jam";

    runValidAnagramExample(example1_s, example1_t, "Example 1");
    runValidAnagramExample(example2_s, example2_t, "Example 2");

    return 0;
}
