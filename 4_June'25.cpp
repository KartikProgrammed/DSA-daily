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