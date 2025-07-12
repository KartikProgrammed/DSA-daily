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

//796. Rotate String
// Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
// A shift on s consists of moving the leftmost character of s to the rightmost position.
// For example, if s = "abcde", then it will be "bcdea" after one shift.
 

// Approach:
// Concatenate s with itself and check if goal is a substring of the concatenated string. This works because all possible rotations of s will appear in the concatenated string.

// CODE:
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()){
            return false;
        }
        string curr=s+s;
        for(int i=0;i<curr.length();i++){
            if(curr[i]==goal[0]){
                bool flag=true;
                for(int j=0;j<goal.length();j++){
                    if(curr[i+j]!=goal[j]){
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    return true;
                }
            }
        }
        return false;
    }
};

//242. Valid Anagram
// Given two strings s and t, return true if t is an anagram of s, and false otherwise.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

// Approach:
// Use a hash map to count the frequency of each character in both strings. If the frequency maps are equal, return true; otherwise, return false.

// CODE:
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        unordered_map<char,int> map;
        for(char it:s){
            map[it]++;
        }
        for(int i=0;i<t.length();i++){
            if(map[t[i]]<=0){
                return false;
            }
            else{
                map[t[i]]--;
            }
        }
        return true;
    }
};


//451. Sort Characters By Frequency
// Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.
// Return the sorted string. If there are multiple answers, return any of them.
 

// Approach:
// Use a hash map to count the frequency of each character. Then, sort the characters based on their frequency and build the result string accordingly.

// CODE:
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> map;
        for(char it:s){
            map[it]++;
        }
        vector<pair<char,int>> curr(map.begin(),map.end());
        sort(curr.begin(),curr.end(),[](const pair<char,int> &a,const pair<char,int> &b){
            return a.second>b.second;
        });
        string res="";
        for(auto it:curr){
            res+=string(it.second, it.first);
        }
        return res;
    }
};

//1614. Maximum Nesting Depth of the Parentheses
// Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.


// Approach:
// Use a counter to keep track of the current depth while iterating through the string. Update the maximum depth whenever you encounter an opening parenthesis.

// CODE:
class Solution {
public:
    int maxDepth(string s) {
        int res=0;
        int curr=0;
        for(char it:s){
            if(it=='('){
                curr++;
            }
            else if(it==')'){
                curr--;
            }
            res=max(res,curr);
        }
        return res;
    }
};