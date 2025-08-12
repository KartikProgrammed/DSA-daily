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

//2787. Ways to Express an Integer as Sum of Powers
// Given two positive integers n and x.
// Return the number of ways n can be expressed as the sum of the xth power of unique positive integers, in other words, the number of sets of unique integers [n1, n2, ..., nk] where n = n1x + n2x + ... + nkx.
// Since the result can be very large, return it modulo 109 + 7.
// For example, if n = 160 and x = 3, one way to express n is n = 23 + 33 + 53.

// Approach:
// 1. Use backtracking to explore all combinations of unique integers raised to the power x.

// Code:
#define MOD 1000000007
class Solution {
public:
    long long power(int base, int exp) {
        long long result = 1;
        for (int i = 0; i < exp; i++) {
            result *= base;
        }
        return result;
    }

    int recursion(int n,int x,int curr,int num,vector<vector<int>>& dp){
        if(curr>n){
            return 0;
        }
        if(curr==n){
            return 1;
        }
        if (num > n) return 0;
        if (dp[curr][num] != -1) return dp[curr][num];

        long long val = power(num, x);
        if (val > n) return dp[curr][num] = 0;

        int op1=recursion(n,x,curr+val,num+1,dp)%MOD;
        int op2=recursion(n,x,curr,num+1,dp)%MOD;
        return dp[curr][num]=(op1+op2)%MOD;

    }
    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        int res=recursion(n,x,0,1,dp);
        return res;
    }
};