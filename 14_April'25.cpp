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

// 1534. Count Good Triplets
// Given an array of integers arr, and three integers a, b and c. You need to find the number of good triplets.
// A triplet (arr[i], arr[j], arr[k]) is good if the following conditions are true:
// 0 <= i < j < k < arr.length
// |arr[i] - arr[j]| <= a
// |arr[j] - arr[k]| <= b
// |arr[i] - arr[k]| <= c
// Where |x| denotes the absolute value of x.
// Return the number of good triplets.

//APROACH:-
//run 3 loops and increase res if conditions satisfy

//CODE:-
class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int res=0;
        for(int i=0;i<arr.size()-2;i++){
            for(int j=i+1;j<arr.size()-1;j++){
                for(int k=j+1;k<arr.size();k++){
                    if(abs(arr[i]-arr[j]) <=a && abs(arr[j]-arr[k]) <=b && abs(arr[i]-arr[k]) <=c ){
                        res++;
                    }
                }
            }
        }
        return res;
    }
};


//115. Distinct Subsequences
// Given two strings s and t, return the number of distinct subsequences of s which equals t.
// The test cases are generated so that the answer fits on a 32-bit signed integer.

//APPROACH:-
//DP ON STRINGS BASIC

//CODE:-
class Solution {
public:
    int rec(string &s,string &t,int left,int right,vector<vector<int>> &memo){
        if(right>=t.length()){
            return 1;
        }
        if(left>=s.length()){
            return 0;
        }
        if(memo[left][right]!=-1){
            return memo[left][right];
        }
        int res=0;
        if(s[left]==t[right]){
            res+=rec(s,t,left+1,right+1,memo);
        }
        res+=rec(s,t,left+1,right,memo);
        return memo[left][right]=res;
    }
    int numDistinct(string s, string t) {
        int m=s.length();
        int n=t.length();
        vector<vector<int>> memo(m,vector<int>(n,-1));
        return rec(s,t,0,0,memo);
    }
};


//72. Edit Distance
// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
// You have the following three operations permitted on a word:
// Insert a character
// Delete a character
// Replace a character

//APPROACH:-
//If the char matches, no peration required
//if it doesnt, u can either ins,del,replace try all find min

//CODE:-
class Solution {
public:
    int rec(string &word1,string &word2,int left,int right,vector<vector<int>> &memo){
        if(right>=word2.length()){
            return word1.length()-left;
        }
        if(left>=word1.length()){
            return word2.length()-right;
        }
        if(memo[left][right]!=-1){
            return memo[left][right];
        }
        if(word1[left]==word2[right]){
            return memo[left][right]=rec(word1,word2,left+1,right+1,memo); //skip
            
        }
        int subb=rec(word1,word2,left,right+1,memo); //ins
        int subb2=rec(word1,word2,left+1,right,memo); //del
        int subb3=rec(word1,word2,left+1,right+1,memo); //replace
        
        return memo[left][right]=1+min({subb,subb2,subb3});        
    }
    int minDistance(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();
        vector<vector<int>> memo(m,vector<int>(n,-1));
        return rec(word1,word2,0,0,memo);
    }
};

// 44. Wildcard Matching
// Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).

//APPROACH:-
//* should be taken care of carefully else all easy

//CODE:-
class Solution {
public:
    bool rec(string &s,string &p,int left,int right,vector<vector<int>> &memo){
        if(right>=p.length()){
            return left==s.length();
        }
        if(left>=s.length()){
            for (int k = right; k < p.length(); ++k)
                if (p[k] != '*') return false;
            return true;
        }
        if(memo[left][right]!=-1){
            return memo[left][right];
        }
        
        if(p[right]=='?' || s[left]==p[right]){
            return memo[left][right]= rec(s,p,left+1,right+1,memo);
        }
        if(p[right]=='*'){
            return memo[left][right]= rec(s,p,left+1,right,memo) || rec(s,p,left,right+1,memo);
        }
        return memo[left][right]= false;
    }
    bool isMatch(string s, string p) {
        int m=s.length();
        int n=p.length();
        vector<vector<int>> memo(m,vector<int>(n,-1));
        return rec(s,p,0,0,memo);
    }
};