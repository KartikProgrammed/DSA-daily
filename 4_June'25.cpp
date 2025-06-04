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

//3403. Find the Lexicographically Largest String From the Box I
// You are given a string word, and an integer numFriends.
// Alice is organizing a game for her numFriends friends. There are multiple rounds in the game, where in each round:
// word is split into numFriends non-empty strings, such that no previous round has had the exact same split.
// All the split words are put into a box.
// Find the lexicographically largest string from the box after all the rounds are finished.

//Approach:
//start from the end of the string and compare lexicographically with the current largest string.
//return the largest string found.

// CODE:
class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends==1){
            return word;
        }
        int n=word.size();
        int reqLen=n-numFriends+1;
        string res="";
        for(int i=0;i<n;i++){
            res=max(res,word.substr(i,reqLen));
        }
        return res;
    }
};


//132. Palindrome Partitioning II
// Given a string s, partition s such that every substring of the partition is a palindrome.
// Return the minimum cuts needed for a palindrome partitioning of s.

//Approach:
//Use dynamic programming to find the minimum cuts needed for a palindrome partitioning of s.
//at every index i, you can either cut at the index or not
//if u do, then change the left pointer to i+1 and check if the string to the left was a palindrome or not
//if it was, then you can add 1 to the cuts needed for the right side of the string

// CODE:
class Solution {
public:
    bool check(int left,int curr,string &s){
        for(int i=left,j=curr;i<j;i++,j--){
            if(s[i]!=s[j]){
                return false;
            }
        }
        return true;
    }
    int recursion(int left,int curr,string &s,vector<vector<int>> &dp){
        if(curr==s.length()){
            if(check(left,curr-1,s)){
                return 0;
            }
            else{
                return INT_MAX;
            }
        }
        if(dp[left][curr]!=-1){
            return dp[left][curr];
        }
        int res=INT_MAX;
        int op1=INT_MAX,op2=INT_MIN;
        if(check(left,curr,s)){
            int next=recursion(curr+1,curr+1,s,dp);
            if(next!=INT_MAX){
                op1=1+next;
            }
        }
        op2=recursion(left,curr+1,s,dp);
        res=min(op1,op2);
        return dp[left][curr]=res;
    }
    int minCut(string s) {
        int n=s.length();
        vector<vector<int>> dp(n+1,vector(n+1,-1));
        return recursion(0,0,s,dp);
    }
};

//1043. Partition Array for Maximum Sum
// Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.
// Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.


//Approach:
//Use dynamic programming to find the maximum sum of the array after partitioning.
//at every index i, you can either partition at the index or not
//if you do, then change the left pointer to i+1 and check if the maximum value of the subarray is greater than the current maximum value
//if it is, then you can add the maximum value to the sum of the right side of the array

// CODE:
class Solution {
public:
    int recursion(vector<int> &arr,int k,int left,int curr,vector<vector<int>> &dp){
        if(curr==arr.size()){
            if (curr - left > k) return INT_MIN;
            if (left >= arr.size()) return 0;
            return *max_element(arr.begin()+left,arr.begin()+curr)*(curr-left);
        }
        if(dp[left][curr]!=-1){
            return dp[left][curr];
        }
        int op1=INT_MIN;
        if(curr - left + 1 <= k){
            int next=recursion(arr,k,curr+1,curr+1,dp);
            int partmax=*max_element(arr.begin()+left,arr.begin()+curr+1);
            if(next!=INT_MIN){
                op1=partmax*(curr-left+1)+next;
            }
        }
        int op2=recursion(arr,k,left,curr+1,dp);
        return dp[left][curr]=max(op1,op2);
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(n,-1));
        return recursion(arr,k,0,0,dp);
    }
};