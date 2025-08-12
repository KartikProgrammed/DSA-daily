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


// 42. Trapping Rain Water

// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

// Approach:
// 1. Use two pointers to traverse the array from both ends.
// 2. Maintain the maximum heights from both ends and calculate the trapped water at each step.

// Code:
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> leftMax(height.size(),0);
        vector<int> rightMax(height.size(),0);
        int currL;
        int currR;
        for(int i=0,j=height.size()-1;i<height.size() && j>=0;i++,j--){
            if(i==0){
                leftMax[i]=-1;
                currL=height[i];
            }
            else{
                leftMax[i]=currL;
                currL=max(currL,height[i]);
            }
            if(j==height.size()-1){
                rightMax[j]=-1;
                currR=height[j];
            }
            else{
                rightMax[j]=currR;
                currR=max(currR,height[j]);
            }
        }
        int count=0;
        for(int i=1;i<height.size()-1;i++){
            int nextmax=min(leftMax[i],rightMax[i]);
            int res=nextmax-height[i];
            if(res>0){
                count+=res;
            }
        }
        return count;
    }
};


//907. Sum of Subarray Minimums

// Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

// Approach:
// 1. Use a stack to find the next smaller element for each element in the array
// 2. Calculate the contribution of each element as the minimum in all subarrays where it is the minimum.

// Code:
#define MOD 1000000007
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> leftSmaller(arr.size(),-1);
        vector<int> rightSmaller(arr.size(),arr.size());
        stack<int> stk;
        for(int i=0;i<arr.size();i++){
            while(!stk.empty() && arr[stk.top()]>arr[i]){
                stk.pop();
            }
            if(!stk.empty()){
                leftSmaller[i]=stk.top();
            }
            stk.push(i);
        }

        while(!stk.empty()){
            stk.pop();
        }

        for(int i=arr.size()-1;i>=0;i--){
            while(!stk.empty() && arr[stk.top()]>=arr[i]){
                stk.pop();
            }
            if(!stk.empty()){
                rightSmaller[i]=stk.top();
            }
            stk.push(i);
        }
        long long total=0;
        for(int i=0;i<arr.size();i++){
            long long left=i-leftSmaller[i];
            long long right=rightSmaller[i]-i;
            total=(total+(left*right %MOD) *arr[i]) % MOD;
        }
        return (int)total;
    }
};