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
#include <climits>
#include <cstring>
#include <cstdlib>
#include <iomanip>

using namespace std;


// 2537. Count the Number of Good Subarrays
// Given an integer array nums and an integer k, return the number of good subarrays of nums.
// A subarray arr is good if there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j].
// A subarray is a contiguous non-empty sequence of elements within an array.

//APPROACH:-
//Two pointer approach


//CODE:-
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int l=0;
        int n=nums.size();
        int r=0;
        int pairs=0;
        long long res=0;
        unordered_map<int,int> map;
        while(l<nums.size() && r<nums.size()){
            pairs+=map[nums[r]];
            map[nums[r]]++;
            while(pairs>=k){
                res+=(n-r);
                map[nums[l]]--;
                pairs-=map[nums[l]];
                l++;
            }
            r++;
        }
        return res;
    }
};


// 123. Best Time to Buy and Sell Stock III
// You are given an array prices where prices[i] is the price of a given stock on the ith day, and two integers k and m.
// Find the maximum profit you can achieve. You may complete at most k transactions, and you must sell the stock before you can buy again.
// Note that you cannot buy and sell the stock on the same day, and you must sell the stock before you can buy again.
// A transaction is defined as one buy and one sell.
// The final answer should be the maximum profit you can achieve after at most k transactions and m days.

//APPROACH:-
//Dynamic programming approach

//CODE:-
class Solution {
public:
    int dp(vector<int>& prices,int curr,int buy,bool holding,vector<vector<vector<int>>> &memo){
        if(curr>=prices.size() || buy==2){
            return 0;
        }
        if(memo[curr][buy][holding]!=-1){
            return memo[curr][buy][holding];
        }
        int res=0;
        if(holding){
            int op1=prices[curr]+dp(prices,curr+1,buy+1,false,memo);
            int op2=dp(prices,curr+1,buy,true,memo);
            res= max(op1,op2);
        }
        else{
            int op1=-prices[curr]+dp(prices,curr+1,buy,true,memo);
            int op2=dp(prices,curr+1,buy,false,memo);
            res=max(op1,op2);
        }
        return memo[curr][buy][holding]=res;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> memo(n,vector<vector<int>>(2,vector<int>(2,-1)));
        return dp(prices,0,0,false,memo);
    }
};


//188. Best Time to Buy and Sell Stock IV
// You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
// Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

//APPROACH:-
//Dynamic programming approach

//CODE:-
class Solution {
public:
    int dp(int k, vector<int>& prices,int curr,bool holding,int buy,vector<vector<vector<int>>> &memo){
        if(curr>=prices.size() || buy>=k){
            return 0;
        }
        if(memo[curr][holding][buy]!=-1){
            return memo[curr][holding][buy];
        }

        int res=0;
        if(holding){
            int op1=prices[curr]+dp(k,prices,curr+1,false,buy+1,memo);
            int op2=dp(k,prices,curr+1,true,buy,memo);
            res=max(op1,op2);
        }
        else{
            int op1=-prices[curr]+dp(k,prices,curr+1,true,buy,memo);
            int op2=dp(k,prices,curr+1,false,buy,memo);
            res=max(op1,op2);
        }
        return memo[curr][holding][buy]= res;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> memo(n,vector<vector<int>>(2,vector<int>(k,-1)));
        return dp(k,prices,0,false,0,memo);
    }
};