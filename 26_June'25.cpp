#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <iomanip>
#include <sstream>
#include <fstream>

using namespace std;

//2311. Longest Binary Subsequence Less Than or Equal to K
// You are given a binary string s and a positive integer k.
// Return the length of the longest subsequence of s that makes up a binary number less than or equal to k.
// Note:
// The subsequence can contain leading zeroes.
// The empty string is considered to be equal to 0.
// A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

//Approach: Dynamic Programming

//CODE:-(TLE)
class Solution {
    string s;
    int n;
    vector<unordered_map<long long,int>> memo;   //  i → { k : answer }

    int dfs(int i, long long k) {
        if (i < 0) return 0;

        if (auto it = memo[i].find(k); it != memo[i].end())
            return it->second;

        int bit = s[i] - '0';
        long long val = bit ? (1LL << (n - i - 1)) : 0LL;

        int take = 0;
        if (val <= k) take = 1 + dfs(i - 1, k - val);

        int skip = dfs(i - 1, k);

        return memo[i][k] = max(take, skip);
    }

public:
    int longestSubsequence(string &str, int k) {
        s = str;
        n = s.size();
        memo.assign(n, {});
        return dfs(n - 1, k);
    }
};

//Approach: Greedy

//CODE:-(Accepted)
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int length = 0;
        long long powerValue = 1;
        
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '0') {
                length++;
            } else if(powerValue <= k) {
                length++;
                k -= powerValue;
            }

            if (powerValue <= k)
                powerValue <<= 1; //powerValue *= 2;
        }
        
        return length;
    }
};
