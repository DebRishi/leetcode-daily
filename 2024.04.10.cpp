#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int size = deck.size();
        vector<int> nums(size);
        sort(deck.begin(), deck.end());
        int idxNums = 0;
        int idxDeck = 0;
        bool skip = true;
        while (idxDeck < size) {
            if (nums[idxNums] == 0) {
                if (skip) {
                    nums[idxNums] = deck[idxDeck];
                    idxDeck++;
                }
                skip = !skip;
            }
            idxNums = (idxNums + 1) % size;
        }
        return nums;
    }
};