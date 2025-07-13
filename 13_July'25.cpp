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
