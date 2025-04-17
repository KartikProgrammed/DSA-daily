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

using namespace std;

//2176. Count Equal and Divisible Pairs in an Array
// Given a 0-indexed integer array nums of length n and an integer k, return the number of pairs (i, j) where 0 <= i < j < n, such that nums[i] == nums[j] and (i * j) is divisible by k.

//APPROACH:-
//Two pointer approach

//CODE:-
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int res=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]==nums[j]){
                    int curr=i*j;
                    if(curr%k==0){
                        res++;
                    }
                }
            }
        }
        return res;
    }
};


//309. Best Time to Buy and Sell Stock with Cooldown
//You are given an array prices where prices[i] is the price of a given stock on the ith day.

// Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

// After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

//APPROACH:-
//Dynamic programming approach


//CODE:-
class Solution {
public:
    int dp(vector<int>& prices,int curr,bool holding,vector<vector<int>> &memo){
        if(curr>=prices.size()){
            return 0;
        }
        if(memo[curr][holding]!=-1){
            return memo[curr][holding];
        }
        int res=0;
        if(holding){
            int op1=prices[curr]+dp(prices,curr+2,false,memo);
            int op2=dp(prices,curr+1,true,memo);
            res=max(op1,op2);
        }
        else{
            int op1=-prices[curr]+dp(prices,curr+1,true,memo);
            int op2=dp(prices,curr+1,false,memo);
            res=max(op1,op2);
        }
        return memo[curr][holding]=res;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> memo(n,vector<int>(2,-1));
        return dp(prices,0,false,memo);
    }
};


//714. Best Time to Buy and Sell Stock with Transaction Fee
// You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.
// Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.
// Note:
// You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
// The transaction fee is only charged once for each stock purchase and sale.

//APPROACH:-
//Dynamic programming approach

//CODE:-
class Solution {
public:
    int dp(vector<int>& prices, int fee,int curr,bool holding,vector<vector<int>> &memo){
        if(curr>=prices.size()){
            return 0;
        }
        if(memo[curr][holding]!=-1){
            return memo[curr][holding];
        }
        int res=0;
        if(holding){
            int op1=prices[curr]-fee+dp(prices,fee,curr+1,false,memo);
            int op2=dp(prices,fee,curr+1,true,memo);
            res=max(op1,op2);
        }
        else{
            int op1=-prices[curr]+dp(prices,fee,curr+1,true,memo);
            int op2=dp(prices,fee,curr+1,false,memo);
            res=max(op1,op2);
        }
        return memo[curr][holding]= res;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> memo(n,vector<int>(2,-1));
        return dp(prices,fee,0,false,memo);
    }
};