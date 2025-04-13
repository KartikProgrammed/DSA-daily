#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<stack>
#include <sstream>
#include <map>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
#include<climits>
using namespace std;

//1922. Count Good Numbers
// A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).
// For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
// Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.
// A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.

//APPROACH:-
//even positions have 5 choices and odd have 4 
//multiply and find exponentially 

//CODE:-
class Solution {
public:
    const int M=1e9+7;
    long long exppower(long long a,long long b){
        if(b==0){
            return 1;
        }
        long long half=exppower(a,b/2);
        long long result=(half*half) % M;

        if(b%2==1){
            result=(result*a)%M;
        }
        return result;
    }
    int countGoodNumbers(long long n) {
        long long odd=exppower(5,(n+1)/2);
        long long even=exppower(4,n/2);

        return ((long long)odd*even) %M;
    }
};


//1143. Longest Common Subsequence
//Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.
// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings.

//APPROACH:-
//DP

//CODE:-
class Solution {
public:
    int rec(string &text1, string &text2,int left,int right,vector<vector<int>> &memo){
        if(left>=text1.length() || right>=text2.length()){
            return 0;
        }
        if( memo[left][right]!=-1){
            return  memo[left][right];
        }
        int res=0;
        if(text1[left]==text2[right]){
            return memo[left][right]=1+rec(text1,text2,left+1,right+1,memo);
        }
        return memo[left][right]=max(rec(text1,text2,left+1,right,memo),rec(text1,text2,left,right+1,memo));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int l=text1.length();
        int r=text2.length();
        vector<vector<int>> memo(l,vector<int>(r,-1));
        return rec(text1,text2,0,0,memo);
    }
};


//516. Longest Palindromic Subsequence
// Given a string s, find the longest palindromic subsequence's length in s.
// A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

//APPROACH:-
//just reverse the string and find the LCS withthe original string

//CODE:-
class Solution {
public:
    int rec(string &s,string &s2,int left,int right,vector<vector<int>> &memo){
        if(left>=s.length()||right>=s2.length()){
            return 0;
        }
        if(memo[left][right]!=-1){
            return memo[left][right];
        }
        if(s[left]==s2[right]){
            return memo[left][right]=1+rec(s,s2,left+1,right+1,memo);
        }
        return memo[left][right]=max(rec(s,s2,left+1,right,memo),rec(s,s2,left,right+1,memo));
    }
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        string s2=s;
        reverse(s2.begin(),s2.end());
        vector<vector<int>> memo(n,vector<int>(n,-1));
        return rec(s,s2,0,0,memo);
    }
};


//1312. Minimum Insertion Steps to Make a String Palindrome
// Given a string s. In one step you can insert any character at any index of the string.
// Return the minimum number of steps to make s palindrome.
// A Palindrome String is one that reads the same backward as well as forward.

//APPROACH:-
//start w 2 pointers 1 from left and 1 from right
//when the ele at either indices are ==, skip both
//otherwise add an element at either side and compute min additions

//CODE:-
class Solution {
public:
    int rec(string &s,int left,int right,vector<vector<int>> &memo){
        if(left>right){
            return 0;
        }
        if(memo[left][right]!=-1){
            return memo[left][right];
        }
        if(s[left]==s[right]){
            return memo[left][right]=rec(s,left+1,right-1,memo);
        }
        return memo[left][right]=(1+min(rec(s,left+1,right,memo),rec(s,left,right-1,memo)));
    }
    int minInsertions(string s) {
        int n=s.length();
        vector<vector<int>> memo(n,vector<int>(n,-1));
        return rec(s,0,n-1,memo);
    }
};