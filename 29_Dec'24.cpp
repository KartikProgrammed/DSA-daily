#include <bits/stdc++.h>
using namespace std;

//1639. Number of Ways to Form a Target String Given a Dictionary
// You are given a list of strings of the same length words and a string target.

// Your task is to form target using the given words under the following rules:

// target should be formed from left to right.
// To form the ith character (0-indexed) of target, you can choose the kth character of the jth string in words if target[i] = words[j][k].
// Once you use the kth character of the jth string of words, you can no longer use the xth character of any string in words where x <= k. In other words, all characters to the left of or at index k become unusuable for every string.
// Repeat the process until you form the string target.
// Notice that you can use multiple characters from the same string in words provided the conditions above are met.

// Return the number of ways to form target from words. Since the answer may be too large, return it modulo 109 + 7.

//APPROACH 1:- 
//vanilla recursion, we have 2 situations, if we have the matching character or Not.
//if matches, we either use it and increment to the next col or we dont use it and increment the row 
//if it doesnt, we either search it in the same col incr row or we search in next col with row=0
//THIS GIVES TLE so well memoise and try again

//CODE:- 
class Solution {
public:
    int recursion(vector<string>& words,string target,int tindex,int col,int row){
        if(tindex>=target.length()){
            return 1;
        }
        if(col>=words[0].size()){
            return 0;
        }
        int r1=0;
        if(target[tindex]==words[row][col]){
            r1+=recursion(words,target,tindex+1,col+1,0);
        }
        if(row+1<words.size()){
            r1+=recursion(words,target,tindex,col,row+1);
        }
        else{
            r1+=recursion(words,target,tindex,col+1,0);
        }
        return r1;
    }
    int numWays(vector<string>& words, string target) {
        return recursion(words,target,0,0,0);      
    }
};


//MEMOISED CODE(still wont work)

class Solution {
public:
    int recursion(vector<string>& words,string target,int tindex,int col,int row,vector<vector<vector<int>>> &dp){
        if(tindex>=target.length()){
            return 1;
        }
        if(col>=words[0].size()){
            return 0;
        }
        if(dp[tindex][col][row]!=-1){
            return dp[tindex][col][row];
        }
        int r1=0;
        int mod=1e9+7;
        if(target[tindex]==words[row][col]){
            r1+=recursion(words,target,tindex+1,col+1,0,dp)% mod;
        }
        if(row+1<words.size()){
            r1+=recursion(words,target,tindex,col,row+1,dp)% mod;
        }
        else{
            r1+=recursion(words,target,tindex,col+1,0,dp)% mod;
        }
        return dp[tindex][col][row]=r1;
    }
    int numWays(vector<string>& words, string target) {
        int m = target.size();
        int n = words[0].size();
        int k = words.size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, -1)));
        return recursion(words,target,0,0,0,dp);      
    }
};

//OPTIMAL APPROACH
class Solution {
public:
    int recursion(vector<string>& words,string target,int tindex,int col,vector<vector<int>> &dp,vector<vector<int>>& freq){
        if(tindex>=target.length()){
            return 1;
        }
        if(col>=words[0].size()){
            return 0;
        }
        if(dp[tindex][col]!=-1){
            return dp[tindex][col];
        }
        int mod=1e9+7;
        int r1 = recursion(words, target, tindex, col + 1,dp,freq);
        if (freq[target[tindex] - 'a'][col] > 0) {
            r1 += ((long long)freq[target[tindex] - 'a'][col] * 
                            recursion(words, target, tindex + 1, col + 1,dp, freq)) % mod;
        }
        return dp[tindex][col]=r1%mod;
    }
    int numWays(vector<string>& words, string target) {
        int m = target.size();
        int n = words[0].size();
        vector<vector<int>> freq(26, vector<int>(n, 0));
        for (const auto& word : words) {
            for (int j = 0; j < n; j++) {
                freq[word[j] - 'a'][j]++;
            }
        }
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return recursion(words,target,0,0,dp,freq);      
    }
};