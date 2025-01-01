#include <bits/stdc++.h>
using namespace std;

//2466. Count Ways To Build Good Strings
// Given the integers zero, one, low, and high, we can construct a string by starting with an empty string, and then at each step perform either of the following:

// Append the character '0' zero times.
// Append the character '1' one times.
// This can be performed any number of times.

// A good string is a string constructed by the above process having a length between low and high (inclusive).

// Return the number of different good strings that can be constructed satisfying these properties. Since the answer can be large, return it modulo 109 + 7.


//APPROACH 1:- gives TLE and MLE
//send a string curr to every recursive call where every call either adds 0 or adds 1 
//check for base case increment resultant variable after every call

//CODE:- 
class Solution {
public:
    int recursion(string curr,int low,int high,int num_zero,int num_one){
        if(curr.length()>high){
            return 0;
        }
        int result=0;
        if(curr.length()>=low && curr.length()<=high){
            result=1;
        }
        
        string one=curr;
        string zero=curr;
        for(int i=0;i<num_zero;i++)
            zero+='0';
        for(int i=0;i<num_one;i++)
            one+='1';
        result+=recursion(one,low,high,num_zero,num_one);
        result+=recursion(zero,low,high,num_zero,num_one);
        return result;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        string curr="";
        return recursion(curr,low,high,zero,one);
    }
};

//APPROACH 2:- 
//use a variable len which stores length of the string curr instead of passing string well pass the integer and do the same thing
//then memoise it to pass the cases

//CODE:- 
class Solution {
public:
    int recursion(int length,int low,int high,int num_zero,int num_one,unordered_map<int,int> &map){
        if(length>high){
            return 0;
        }
        if (map.find(length) != map.end()) {
            return map[length];
        }
        int result=0;
        int MOD=1e9+7;
        if(length>=low && length<=high){
            result=1;
        }
        
        result+=recursion(length+num_one,low,high,num_zero,num_one,map) % MOD;
        result+=recursion(length+num_zero,low,high,num_zero,num_one,map) % MOD;
        result%=MOD;
        return map[length]=result;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        unordered_map<int,int> map;
        return recursion(0,low,high,zero,one,map);
    }
};