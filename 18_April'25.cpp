#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <cstring>
#include <cstdlib>

using namespace std;

// 38. Count and Say
// The count-and-say sequence is a sequence of digit strings defined by the recursive formula:
// countAndSay(1) = "1"
// countAndSay(n) is the run-length encoding of countAndSay(n - 1).
// Run-length encoding (RLE) is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "3322251" we replace "33" with "23", replace "222" with "32", replace "5" with "15" and replace "1" with "11". Thus the compressed string becomes "23321511".
// Given a positive integer n, return the nth element of the count-and-say sequence.

//APPROACH:-
//Recursion approach
//recurse and get the count of each digit and then append it to the result string

//CODE:-
class Solution {
public:
    string rec(int n,string curr){
        if(n==1){
            return curr;
        }
        string res="";
        int i=0;
        while(i<curr.length()){
            char prev=curr[i];
            int count=0;
            while(prev==curr[i]){
                count++;
                i++;
            }
            res+=to_string(count)+prev;
        }
        return rec(n-1,res);
    }
    string countAndSay(int n) {
        return rec(n,"1");
    }
};


//300. Longest Increasing Subsequence
// Given an integer array nums, return the length of the longest strictly increasing subsequence.


//APPROACH:-
//Dynamic programming approach

//CODE:-
class Solution {
public:
    int rec(vector<int>& nums,int ind,int prev,vector<vector<int>> &dp){
        if(ind>=nums.size()){
            return 0;
        }
        if(dp[ind][prev+1]!=-1){
            return dp[ind][prev+1];
        }
        int res=0;
        int op1=0;
        if(prev==-1 || nums[ind]>nums[prev]){
            op1=1+rec(nums,ind+1,ind,dp);
        }
        int op2=rec(nums,ind+1,prev,dp);
        res=max(op1,op2);
        return dp[ind][prev+1]=res;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return rec(nums,0,-1,dp);
    }
};