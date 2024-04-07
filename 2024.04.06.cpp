#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string str) {
        vector<pair<char, int>> stack;
        for (int i = 0 ; i < str.size() ; i++) {
            if (str[i] == '(')
                stack.push_back({'(', i});
            else if (str[i] == ')') {
                if (!stack.empty() && stack.back().first == '(')
                    stack.pop_back();
                else
                    stack.push_back({')', i});
            }
        }
        string ans = "";
        for (int i = 0, j = 0 ; i < str.size() ; i++) {
            if (j < stack.size() && stack[j].second == i)
                j++;
            else
                ans.push_back(str[i]);
        }
        return ans;
    }
};