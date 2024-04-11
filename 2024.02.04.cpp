#include <iostream>
#include <vector>
using namespace std;
#define MAX_SIZE 128

// MEMORY LEVEL EXCEEDED
class Solution {
public:
    string minWindow(string str, string pat) {
        vector<int> freq(MAX_SIZE);
        int i = 0;
        int j = 0;
        string ans = "";
        int len = INT_MAX;
        int cnt = pat.size();
        
        for (char c : pat)
            freq[c]++;
        
        while (j < str.size()) {
            if (freq[str[j]] > 0) 
                cnt--;
            freq[str[j]]--;
            j++;
            while (cnt == 0) {
                if (j - i < len) {
                    ans = str.substr(i, j-i);
                    len = j-i;
                }
                if (freq[str[i]] == 0)
                    cnt++;
                freq[str[i]]++;
                i++;
            }
        }
        return ans;
    }
};

// MEMORY LEVEL EXCEEDED
class Solution {
public:
    
    int freq[MAX_SIZE];
    
    string minWindow(string str, string pat) {
        memset(freq, 0, sizeof(freq));
        int i = 0;
        int j = 0;
        string ans = "";
        int len = INT_MAX;
        int cnt = pat.size();
        
        for (char c : pat)
            freq[c]++;
        
        while (j < str.size()) {
            if (freq[str[j]] > 0) 
                cnt--;
            freq[str[j]]--;
            j++;
            while (cnt == 0) {
                if (j - i < len) {
                    ans = str.substr(i, j-i);
                    len = j-i;
                }
                if (freq[str[i]] == 0)
                    cnt++;
                freq[str[i]]++;
                i++;
            }
        }
        return ans;
    }
};

// MEMORY LEVEL EXCEEDED
class Solution {
public:
    
    int strFreq[MAX_SIZE];
    int patFreq[MAX_SIZE];
    
    bool compare() {
        for (int i = 0; i <  MAX_SIZE; i++) {
            if (patFreq[i] != 0 && patFreq[i] > strFreq[i])
                return false;
        }
        return true;
    }
    
    string minWindow(string str, string pat) {
        memset(strFreq, 0, sizeof(strFreq));
        memset(patFreq, 0, sizeof(patFreq));
        for (char c : pat)
            patFreq[c]++;
        int i = 0;
        int j = 0;
        int len = INT_MAX;
        string ans = "";
        while (j < str.size()) {
            strFreq[str[j++]]++;
            while (i < j && compare()) {
                if (j - i < len) {
                    ans = str.substr(i, j - i);
                    len = j - i;
                }
                strFreq[str[i++]]--;
            }
        }
        while (i < j && compare()) {
            if (j - i < len) {
                ans = str.substr(i, j - i);
                len = j - i;
            }
            strFreq[str[i++]]--;
        }
        return ans;
    }
};