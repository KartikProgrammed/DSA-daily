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


// 2410. Maximum Matching of Players With Trainers
// You are given a 0-indexed integer array players, where players[i] represents the ability of the ith player. You are also given a 0-indexed integer array trainers, where trainers[j] represents the training capacity of the jth trainer.
// The ith player can match with the jth trainer if the player's ability is less than or equal to the trainer's training capacity. Additionally, the ith player can be matched with at most one trainer, and the jth trainer can be matched with at most one player.
// Return the maximum number of matchings between players and trainers that satisfy these conditions.

//Approach:
// 1. Sort both players and trainers.
// 2. Use two pointers to find the maximum number of matchings.

//Code:
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int pl=0;
        int tr=0;
        int res=0;
        while(pl<players.size() && tr<trainers.size()){
            if(players[pl]<=trainers[tr]){
                res++;
                pl++;
                tr++;
            }
            else{
                tr++;
            }
        }
        return res;
    }
};


//13. Roman to Integer
// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.
// Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
// I can be placed before V (5) and X (10) to make 4 and 9. 
// X can be placed before L (50) and C (100) to make 40 and 90. 
// C can be placed before D (500) and M (1000) to make 400 and 900.
// Given a roman numeral, convert it to an integer.

//Approach:
// 1. Create a map to store the values of Roman numerals.
// 2. Iterate through the string and check if the current numeral is less than the next numeral.
// 3. If it is, subtract the current numeral's value from the result, otherwise add it.

//CODE:-
class Solution {
public:
    int romanToInt(string s) {
        int curr=0;
        int res=0;
        while(curr<s.length()){
            if(s[curr]=='M'){
                res+=1000;
            }
            else if(s[curr]=='D'){
                res+=500;
            }
            else if(s[curr]=='L'){
                res+=50;
            }
            else if(s[curr]=='V'){
                res+=5;
            }
            else if(s[curr]=='C'){
                if(s[curr+1]=='D'){
                    res+=400;
                    curr+=1;
                }
                else if(s[curr+1]=='M'){
                    res+=900;
                    curr+=1;
                }
                else{
                    res+=100;
                }
            }
            else if(s[curr]=='X'){
                if(s[curr+1]=='L'){
                    res+=40;
                    curr+=1;
                }
                else if(s[curr+1]=='C'){
                    res+=90;
                    curr+=1;
                }
                else{
                    res+=10;
                }
            }
            else if(s[curr]=='I'){
                if(s[curr+1]=='V'){
                    res+=4;
                    curr+=1;
                }
                else if(s[curr+1]=='X'){
                    res+=9;
                    curr+=1;
                }
                else{
                    res+=1;
                }
            }
            curr++;
        }
        return res;
    }
};


// 8. String to Integer (atoi)
// Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.
// The algorithm for myAtoi(string s) is as follows:
// Whitespace: Ignore any leading whitespace (" ").
// Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
// Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
// Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
// Return the integer as the final result.
 
// Approach:
//follow the steps mentioned in the problem statement to convert the string to an integer.

//CODE:-
class Solution {
public:
    int myAtoi(string s) {
        int it=0;
        while(s[it]==' '){
            it++;
        }
        bool pos=true;
        if(it<s.length() &&(s[it]=='-' || s[it]=='+')){
            pos=(s[it]=='+');
            it++;
        }
        bool st=false;
        long long res=0;
        while(it<s.length() && isdigit(s[it])){
            res = res * 10 + (s[it] - '0');
            if(pos && res > INT_MAX) return INT_MAX;
            if(!pos && -res < INT_MIN) return INT_MIN;
            it++;
        }
        if(!pos){
            return (int)(-res);
        }
        return (int)res;
    }
};


//5. Longest Palindromic Substring
// Given a string s, return the longest palindromic substring in s.

//Approach:
//use strings to check for palindromes and find the longest one.

//CODE:-
class Solution {
public:
    string longestPalindrome(string s) {
        string res="";
        int n=s.length();
        for(int i=0;i<s.length();i++){
            int l=i;
            int r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                l--;
                r++;
            }
            if(r-l-1>res.length()){
                res=s.substr(l+1,r-l-1);
            }

            l=i;
            r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                l--;
                r++;
            }
            if(r-l-1>res.length()){
                res=s.substr(l+1,r-l-1);
            }
        }
        return res;
    }
};

//1781. Sum of Beauty of All Substrings
// The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.
// For example, the beauty of "abaacc" is 3 - 1 = 2.
// Given a string s, return the sum of beauty of all of its substrings.

//Approach:
// 1. Use a sliding window to find all substrings.
// 2. For each substring, calculate the frequency of characters and find the maximum and minimum
//    frequencies to compute the beauty.
// 3. Sum the beauties of all substrings.

//CODE:-
class Solution {
public:
    int beautySum(string s) {
        int res = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            unordered_map<char, int> freq;
            for (int j = i; j < n; j++) {
                freq[s[j]]++;

                int maxi = INT_MIN;
                int mini = INT_MAX;
                for (auto it : freq) {
                    maxi = max(maxi, it.second);
                    mini = min(mini, it.second);
                }
                res += (maxi - mini);
            }
        }
        return res;
    }
};
