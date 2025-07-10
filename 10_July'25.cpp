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

//1021. Remove Outermost Parentheses
// A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.
// For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
// A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, with A and B nonempty valid parentheses strings.
// Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.
// Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.

// Approach:
//use 2 counters to keep track of the number of open and close parentheses

// CODE:
class Solution {
public:
    string removeOuterParentheses(string s) {
        int open=0;
        int close=0;
        string res="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                open++;
                if(open>1){
                    res+=s[i];
                }
            }
            else{
                close++;
                if(open==close){
                    open=0;
                    close=0;
                }
                else{
                    res+=s[i];
                }
            }
        }
        return res;
    }
};

//151. Reverse Words in a String
// Given an input string s, reverse the order of the words.
// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
// Return a string of the words in reverse order concatenated by a single space.
// Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

// Approach:
//put all the words in a vector and then reverse the vector and join the words with a single space

// CODE:
class Solution {
public:
    string reverseWords(string s) {
        vector<string> temp;
        string curr="";
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                if(!curr.empty()){
                    temp.push_back(curr);
                    curr="";
                }
            }
            else{
                curr+=s[i];
            }
        }
        string res="";
        if(!curr.empty()){
            temp.push_back(curr);
        }
        for(int i=temp.size()-1;i>=0;i--){
            if(i!=temp.size()-1){
                res+=" ";
            }
            res+=temp[i];
        }
        return res;
    }
}; 

// 1903. Largest Odd Number in String
// You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.
// A substring is a contiguous sequence of characters within a string.

// Approach:
// Iterate through the string from the end to the beginning and check if the character is odd. If it is, return the substring from the start to that character.

// CODE:
class Solution {
public:
    string largestOddNumber(string num) {
        int i=num.length()-1;
        while(i>=0 && num[i]%2==0){
            i--;
        }
        if(i<0){
            return "";
        }
        return num.substr(0,i+1);
    }
};

//205. Isomorphic Strings
// Given two strings s and t, determine if they are isomorphic.
// Two strings s and t are isomorphic if the characters in s can be replaced to get t.
// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

// Approach:
// Use two hash maps to keep track of the mapping between characters in both strings. If a character in s maps to a different character in t or vice versa, return false.
// If the mapping is consistent throughout both strings, return true.

// CODE:
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> map;
        unordered_map<char,char> map2;
        for(int i=0;i<s.length();i++){
            if(map.find(s[i])!=map.end()){
                if(map[s[i]]!=t[i]){
                    return false;
                }
            }
            else{
                map[s[i]]=t[i];
            }

            if(map2.find(t[i])!=map2.end()){
                if(map2[t[i]]!=s[i]){
                    return false;
                }
            }
            else{
                map2[t[i]]=s[i];
            }
        }
        return true;
    }
};