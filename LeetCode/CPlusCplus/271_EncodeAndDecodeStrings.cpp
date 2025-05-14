/*

271. Encode and Decode Strings

Design an algorithm to encode a list of strings to a single string. The encoded string is then decoded back to the original list of strings.

Please implement encode and decode


Example 1:
Input: ["neet","code","love","you"]
Output:["neet","code","love","you"]

Example 2:
Input: ["we","say",":","yes"]
Output: ["we","say",":","yes"]


Constraints:
0 <= strs.length < 100
0 <= strs[i].length < 200
strs[i] contains only UTF-8 characters.

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {
        if (strs.empty()) return "";

        vector<int> sizes;
        for (string s : strs) {
            sizes.push_back(s.size());
        }

        string res = "";
        for (int sz : sizes) {
            res += to_string(sz) + ',';
        }
        res += '#';

        for (string s : strs) {
            res += s;
        }

        return res;
    }

    vector<string> decode(string s) {
        if (s.empty()) return {};

        vector<int> sizes;
        vector<string> res;
        int i = 0;

        while (s[i] != '#') {
            string cur = "";
            while (s[i] != ',') {
                cur += s[i];
                i++;
            }
            sizes.push_back(stoi(cur));
            i++;
        }
        i++;

        for (int sz : sizes) {
            res.push_back(s.substr(i, sz));
            i += sz;
        }

        return res;
    }
};

void runExample(vector<string>& strs, const string& label) {
    Solution solver;
    string enc = solver.encode(strs);
    vector<string> result = solver.decode(enc);

    // Print Label
    cout << "=== " << label << " ===\n";

    // Print Input
    cout << "Input: [ ";
    for (string s : strs) cout << "\"" << s << "\" ";
    cout << "]\n";

    // Print Encode
    cout << "Encode: [ \"" << enc << "\" ]\n";

    // Print Output
    cout << "Output: [ ";
    for (string s : result) cout << "\"" << s << "\" ";
    cout << "]\n\n";
}

int main() {
    vector<string> example1_strs = { "neet","code","love","you" };
    vector<string> example2_strs = { "we","say",":","yes" };

    runExample(example1_strs, "Example 1");
    runExample(example2_strs, "Example 2");

    return 0;
}