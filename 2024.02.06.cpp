#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    
    string getSignature(string str) {
        vector<int> freq(26, 0);
        for (char c : str)
            freq[c - 'a']++;
        string sig = "";
        for (int i = 0 ; i < 26 ; i++) {
            sig += 'a' + i;
            sig += to_string(freq[i]);
        }
        return sig;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (auto str : strs)
            map[getSignature(str)].push_back(str);
        vector<vector<string>> ans;
        for (auto& [_, list] : map)
            ans.push_back(list);
        return ans;
    }
};