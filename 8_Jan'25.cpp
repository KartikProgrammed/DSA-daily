#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_map>
#include<stack>
#include<unordered_set>
using namespace std;

// 3042. Count Prefix and Suffix Pairs I
// You are given a 0-indexed string array words.
// Let's define a boolean function isPrefixAndSuffix that takes two strings, str1 and str2:
// isPrefixAndSuffix(str1, str2) returns true if str1 is both a 
// prefix
//  and a 
// suffix
//  of str2, and false otherwise.
// For example, isPrefixAndSuffix("aba", "ababa") is true because "aba" is a prefix of "ababa" and also a suffix, but isPrefixAndSuffix("abc", "abcd") is false.

// Return an integer denoting the number of index pairs (i, j) such that i < j, and isPrefixAndSuffix(words[i], words[j]) is true.

//APPROACH:-
//create the function as said in the description and basic brute force is then applied

//CODE:-
class Solution {
public:
    
    bool isPrefixAndSuffix(string a,string b){
        int na=a.length();
        int nb=b.length();
        if(na>nb){
            return false;
        }
        for(int i=0;i<na;i++){
            if(a[i]!=b[nb-na+i] || a[i]!=b[i]){
                return false;
            }
        }
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int result=0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if( isPrefixAndSuffix(words[i],words[j])==true){
                    result++;
                }
            }
        }
        return result;
    }
};

//424. Longest Repeating Character Replacement
// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

// Return the length of the longest substring containing the same letter you can get after performing the above operations.

//APPROACH:-
//take a maxwindow int and maxfreq vector and then calc according to the concepts of sliding window

//CODE:-
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> freq;
        int res=0;
        int l=0; //left
        int r=0; //right
        int maxfreq=0;
        while(r<s.length()){
            freq[s[r]]+=1;
            maxfreq=max(maxfreq,freq[s[r]]);
            while((r-l+1)-maxfreq>k){
                freq[s[l]]--;
                l++;
            }
            res=max(res,r-l+1);
            r++;
        }
        return res;
    }
};