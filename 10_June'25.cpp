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