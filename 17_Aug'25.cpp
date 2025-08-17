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

// 837. New 21 Game

// Alice plays the following game, loosely based on the card game "21".
// Alice starts with 0 points and draws numbers while she has less than k points. During each draw, she gains an integer number of points randomly from the range [1, maxPts], where maxPts is an integer. Each draw is independent and the outcomes have equal probabilities.
// Alice stops drawing numbers when she gets k or more points.
// Return the probability that Alice has n or fewer points.
// Answers within 10-5 of the actual answer are considered accepted.

// Approach:
// 1. Use dynamic programming to calculate the probability of reaching each score from 0 to
// n.


// Code: (TLE)
class Solution {
public:
    double recursion(int curr,int n,int k,int maxPts,vector<double> &memo){
        if(curr>=k){
            if(curr<=n){
                return 1.0;
            }
            return 0.0;
        }
        if(memo[curr]>=0){
            return memo[curr];
        }
        double op1=0;
        for(int i=1;i<=maxPts;i++){
            op1+=recursion(curr+i,n,k,maxPts,memo);
        }
        return memo[curr]=op1/maxPts;
    }
    double new21Game(int n, int k, int maxPts) {
        int tot=0;
        vector<double> memo(n + maxPts + 1, -1.0);
        return recursion(0,n,k,maxPts,memo);
    }
};


//Approach2:
// 1. Use dynamic programming to calculate the probability of reaching each score from 0 to n.
// 2. Use a sliding window to keep track of the sum of probabilities for the last
// maxPts scores.

// Code:
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || n >= k + maxPts) return 1.0;

        vector<double> dp(n + 1, 0.0);
        dp[0] = 1.0;

        double windowSum = 1.0, result = 0.0;

        for (int i = 1; i <= n; i++) {
            dp[i] = windowSum / maxPts;

            if (i < k) {
                windowSum += dp[i];  // contribute to future
            } else {
                result += dp[i];     // final probability if stopped
            }

            if (i - maxPts >= 0) {
                windowSum -= dp[i - maxPts];
            }
        }

        return result;
    }
};


//3. Longest Substring Without Repeating Characters

// Given a string s, find the length of the longest substring without duplicate characters.

// Approach:
// 1. Use a sliding window technique with two pointers to track the current substring.
// 2. Use a hash set to keep track of characters in the current substring.
// 3. If a character is repeated, move the left pointer until the substring is valid again.
// 4. Update the maximum length whenever a valid substring is found.
// 5. Return the maximum length found.

// Code:
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> map;
        int i=0;
        int j=0;
        int res=0;
        while(i<=j && j<s.length()){
            if(map[s[j]] == 1){
                while(i<j && s[i]!=s[j]){
                    map[s[i]]--;
                    i++;
                }
                map[s[i]]--;
                i++;
            }
            map[s[j]]++;
            
            int curr=j-i+1;
            res=max(res,curr);
            j++;
        }
        return res;
    }
};


//1004. Max Consecutive Ones III

// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

// Approach:
// 1. Use a sliding window technique with two pointers to track the current window of
// consecutive 1's and the number of 0's that can be flipped.

// Code:
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int res=0;
        int i=0,j=0;
        int zeros=0;
        while(i<=j && j<nums.size()){
            if(nums[j]==0){
                zeros++;
            }
            while(zeros>k){
                if(nums[i]==0){
                    zeros--;
                }
                i++;
            }

            int curr=j-i+1;
            res=max(res,curr);
            j++;
        }
        return res;
    }
};