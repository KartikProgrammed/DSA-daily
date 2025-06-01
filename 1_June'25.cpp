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


// 2929. Distribute Candies Among Children II
// You are given two positive integers n and limit.
// Return the total number of ways to distribute n candies among 3 children such that no child gets more than limit candies.

//Approach 1:- Recursion
//TLE

//CODE:-
class Solution {
public:
    long long recursion(int curr,int left,int limit){
        if(left<0){
            return 0;
        }
        if(curr>2){
            if(left==0){
                return 1;
            }
            return 0;
        }
        long long res=0;
        for(int i=0;i<=limit;i++){
            res+=recursion(curr+1,left-i,limit);
        }
        return res;
    }
    long long distributeCandies(int n, int limit) {
        return recursion(0,n,limit);
    }
};

//APPROACH 2:- Math

// CODE:-
class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long res=0;
        int minCh1=max(0,n-limit*2);
        int maxCh1=min(n,limit);
    
        for(int i=minCh1;i<=maxCh1;i++){
            int N=n-i;
            int minCh2=max(0,N-limit);
            int maxCh2=min(N,limit);

            res+=maxCh2-minCh2+1;
        }
        return res;
    }
};


//673. Number of Longest Increasing Subsequence
// Given an integer array nums, return the number of longest increasing subsequences.
// Notice that the sequence has to be strictly increasing.


// Approach: Dynamic Programming

// CODE:-
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> count(n,1);
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && dp[j]+1>dp[i]){
                    dp[i]=1+dp[j];
                    count[i]=count[j];
                }
                else if(nums[i]>nums[j] && 1+dp[j]==dp[i]){
                    count[i]+=count[j];
                }
            }
            maxi=max(maxi,dp[i]);
        }
        int res=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi){
                res+=count[i];
            }
        }
        return res;

    }
};

//1547. Minimum Cost to Cut a Stick
// Given a wooden stick of length n units. The stick is labelled from 0 to n. For example, a stick of length 6 is labelled as follows:
// Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.
// You should perform the cuts in order, you can change the order of the cuts as you wish.
// The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). Please refer to the first example for a better explanation.
// Return the minimum total cost of the cuts.

// Approach: Dynamic Programming with Memoization
//important line:- int cost=cuts[end+1]-cuts[st-1]+recursion(cuts,st,i-1,dp)+recursion(cuts,i+1,end,dp); dry run this line to understand how the cost is calculated.

// CODE:-
class Solution {
public:
    int recursion(vector<int> &cuts,int st,int end,vector<vector<int>> &dp){
        if(st>end){
            return 0;
        }
        if(dp[st][end]!=-1){
            return dp[st][end];
        }
        int res=INT_MAX;
        for(int i=st;i<=end;i++){
            int cost=cuts[end+1]-cuts[st-1]+recursion(cuts,st,i-1,dp)+recursion(cuts,i+1,end,dp);
            res=min(cost,res);
        }
        return dp[st][end]=res;
    }
    int minCost(int n, vector<int>& cuts) {
        int N=cuts.size();
        sort(cuts.begin(),cuts.end());
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        vector<vector<int>> dp(N+1,vector<int>(N+1,-1));
        return recursion(cuts,1,N,dp);
    }
};

// 312. Burst Balloons
// You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.
// If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.
// Return the maximum coins you can collect by bursting the balloons wisely.

// Approach: Dynamic Programming with Memoization

// CODE:-
class Solution {
public:
    int recursion(vector<int> &nums,int st,int end,vector<vector<int>> &dp){
        if(st>end){
            return 0;
        }
        if(dp[st][end]!=-1){
            return dp[st][end];
        }
        int res=INT_MIN;
        for(int i=st;i<=end;i++){
            int cost=nums[i]*nums[st-1]*nums[end+1]+recursion(nums,st,i-1,dp)+recursion(nums,i+1,end,dp);
            res=max(res,cost);
        }
        return dp[st][end]=res;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
        return recursion(nums,1,n,dp);
    }
};