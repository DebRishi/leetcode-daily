#include <iostream>
using namespace std;

// LEETCODE 2108 - Find First Palindromic String in the Array

class Solution {
public:
    
    bool isPalindrome(string& str) {
        int i = 0;
        int j = str.size() - 1;
        while (i < j) {
            if (str[i] != str[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    string firstPalindrome(vector<string>& words) {
        for (auto& word : words) {
            if (isPalindrome(word))
                return word;
        }
        return "";
    }
};