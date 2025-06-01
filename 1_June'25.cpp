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