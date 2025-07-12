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