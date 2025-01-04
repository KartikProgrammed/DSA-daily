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

//1930. Unique Length-3 Palindromic Subsequences
//Given a string s, return the number of unique palindromes of length three that are a subsequence of s.

// Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.

// A palindrome is a string that reads the same forwards and backwards.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".

//APPROACH:- brute force (TLE)
//CODE:-
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<string> res;
        for(int left=0;left<s.length();left++){
            for(int right=left+2;right<s.length();right++){
                if(s[left]==s[right]){
                    for(int midd=left+1;midd<right;midd++){
                        string palindrome=string(1,s[left])+s[midd]+s[right];
                        res.insert(palindrome);
                    }
                }
            }
        }
        return res.size();
    }
};

//APPROACH 2:-
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;
        int n = s.length();
        
        unordered_map<char, pair<int, int>> M;
        
        for (int i = 0; i < n; i++) {
            if (M.find(s[i]) == M.end()) {
                M[s[i]].first = i;
            }
            M[s[i]].second = i;
        }
        
        for (auto& [ch, positions] : M) {
            int left = positions.first;
            int right = positions.second;
            
            if (right - left <= 1) continue;  // No valid subsequences in this range
            
            unordered_set<char> uniqueChars;
            for (int i = left + 1; i < right; i++) {
                uniqueChars.insert(s[i]);
            }
            
            ans += uniqueChars.size();  // Count the unique characters between first and last occurrence
        }
        
        return ans;
    }
};