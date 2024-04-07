#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool checkValidString(string str) {
        stack<int> stack1;
        stack<int> stack2;
        for (int i = 0 ; i < str.size() ; i++) {
            if (str[i] == '(')
                stack1.push(i);
            else if (str[i] == '*')
                stack2.push(i);
            else if (str[i] == ')') {
                if (!stack1.empty())
                    stack1.pop();
                else if (!stack2.empty())
                    stack2.pop();
                else
                    return false;
            }
        }
        while (!stack1.empty() && !stack2.empty()) {
            if (stack1.top() > stack2.top())
                return false;
            stack1.pop();
            stack2.pop();
        }
        return stack1.empty();
    }
};