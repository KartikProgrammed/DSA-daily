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