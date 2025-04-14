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