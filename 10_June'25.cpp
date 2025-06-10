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

//3442. Maximum Difference Between Even and Odd Frequency I
// You are given a string s consisting of lowercase English letters.
// Your task is to find the maximum difference diff = freq(a1) - freq(a2) between the frequency of characters a1 and a2 in the string such that:
// a1 has an odd frequency in the string.
// a2 has an even frequency in the string.
// Return this maximum difference.

//Approach:
// Count the frequency of each character and then find the maximum difference between odd and even frequencies.

// CODE:
class Solution {
public:
    int maxDifference(string s) {
        vector<int> map(26,0);
        for(int i=0;i<s.length();i++){
            map[s[i]-'a']++;
        }
        int maxOdd=INT_MIN;
        int minEven=INT_MAX;
        for(int i=0;i<26;i++){
            if(map[i]%2==0 && map[i]!=0){
                minEven=min(minEven,map[i]);
            }
            else{
                maxOdd=max(maxOdd,map[i]);
            }
        }
        return maxOdd-minEven;
    }
};

//921. Minimum Add to Make Parentheses Valid
// A parentheses string is valid if and only if:
// It is the empty string,
// It can be written as AB (A concatenated with B), where A and B are valid strings, or
// It can be written as (A), where A is a valid string.
// You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.
// For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
// Return the minimum number of moves required to make s valid.

//Approach:
// Use a stack to keep track of unmatched parentheses and count the number of moves needed to balance them.

// CODE:
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stk;
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                stk.push('(');
            }
            if(s[i]==')'){
                if(!stk.empty()){
                    stk.pop();
                }
                else{
                    count++;
                }
            }
        }
        while(!stk.empty()){
            count++;
            stk.pop();
        }
        return count;
    }
};

//38. Count and Say
// The count-and-say sequence is a sequence of digit strings defined by the recursive formula:
// countAndSay(1) = "1"
// countAndSay(n) is the run-length encoding of countAndSay(n - 1).
// Run-length encoding (RLE) is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "3322251" we replace "33" with "23", replace "222" with "32", replace "5" with "15" and replace "1" with "11". Thus the compressed string becomes "23321511".
// Given a positive integer n, return the nth element of the count-and-say sequence.

//Approach:
// Use a loop to generate the count-and-say sequence iteratively by counting consecutive characters in the previous string.

// CODE:
class Solution {
public:
    string rle(string n){
        char prev=n[0];
        int count=1;
        string res="";
        for(int i=1;i<n.length();i++){
            if(prev!=n[i]){
                res+=to_string(count)+prev;
                count=1;
                prev=n[i];
            }
            else{
                count++;
            }
        }
        res+=to_string(count)+prev;
        return res;
    }

    string countAndSay(int n) {
        string res="1";
        int count=1;
        while(count<n){
            res=rle(res);
            count++;
        }
        return res;
    }
};