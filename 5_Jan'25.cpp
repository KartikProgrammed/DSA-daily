#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_map>
#include<stack>
#include<unordered_set>
using namespace std;

//2381. Shifting Letters II
//You are given a string s of lowercase English letters and a 2D integer array shifts where shifts[i] = [starti, endi, directioni]. For every i, shift the characters in s from the index starti to the index endi (inclusive) forward if directioni = 1, or shift the characters backward if directioni = 0.
// Shifting a character forward means replacing it with the next letter in the alphabet (wrapping around so that 'z' becomes 'a'). Similarly, shifting a character backward means replacing it with the previous letter in the alphabet (wrapping around so that 'a' becomes 'z').
// Return the final string after all such shifts to s are applied.

//CODE:-
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> dp(n + 1, 0);

        for (int i=0;i<shifts.size();i++) {
            int start = shifts[i][0];
            int end = shifts[i][1];
            int direction = shifts[i][2];

            if (direction == 1) {
                dp[start]++;
                dp[end + 1]--;
            } else {
                dp[start]--;
                dp[end + 1]++;
            }
        }

        int prefixSum = 0;
        for (int i = 0; i < n; i++) {
            prefixSum += dp[i];
            int currentPos = s[i] - 'a';
            int newPos = (currentPos + prefixSum % 26 + 26) % 26;
            s[i] = 'a' + newPos;
        }

        return s;
    }
};