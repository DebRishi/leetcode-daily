#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    
    stack<int> stack1;
    stack<int> stack2;
    
    MyQueue() {
        stack1 = std::stack<int>();
        stack2 = std::stack<int>();
    }
    
    void push(int x) {
        stack1.push(x);
    }
    
    int pop() {
        if (empty())
            return -1;
        int top = stack2.top();
        stack2.pop();
        return top;
    }
    
    int peek() {
        if (empty())
            return -1;
        else
            return stack2.top();
    }
    
    bool empty() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        return stack2.empty();
    }
};